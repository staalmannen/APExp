# The PLAS Stack: Plan 9, Listen/Rc-httpd, Apache-less, SQLite, PHP
A Theoretical Architecture and Setup Guide for Statically Linked Web Environments on 9front.

---

## 1. Architectural Overview
The **PLAS Stack** represents a radical departure from conventional web infrastructure. By coupling the distributed, file-centric philosophy of **9front (Plan 9)** with a completely self-contained, statically compiled **PHP binary containing an embedded SQLite engine**, this stack eliminates the need for dynamic linker dependencies, complex package managers, heavy relational database servers, and multi-layered container runtimes.

```
                  +-----------------------------------------+
                  |         Incoming HTTP Request           |
                  +-----------------------------------------+
                                       |
                                       v
                  +-----------------------------------------+
                  |    Plan 9 Native Listener (rc-httpd)    |
                  +-----------------------------------------+
                                       | (Forks transient namespace)
                                       v
                  +-----------------------------------------+
                  |     Statically Linked PHP Binary        |
                  |     (Embedded SQLite Engine / PDO)       |
                  +-----------------------------------------+
                     /                 |                 \
                    v                  v                  v
         +--------------------+ +-------------+ +--------------------+
         | local .sqlite file | | /net/tcp    | | /dev/sensors       |
         | (Shared via 9P)    | | (Plan 9 IP) | | (Synthetic files)  |
         +--------------------+ +-------------+ +--------------------+
```

### Core Advantages:
1. **The Ultimate Edge "Un-Appliance":** Deployment is reduced to copying exactly two elements: a single executable file and a flat data file. There are no shared library conflicts (`glibc`/`musl` disparities), zero system drift, and a tiny overall storage footprint.
2. **Namespace Sandbox Isolation:** Plan 9 forks a localized namespace for incoming requests. If a PHP application is compromised, the attacker is isolated within a transient, severely restricted process space.
3. **9P-Native Integration:** PHP can interact directly with synthetic filesystems (like `/net`, `/proc`, and `/dev`), enabling the web interface to read hardware metrics or manage networking interfaces naturally via standard file I/O operations.
4. **Distributed 9P DB Locks:** SQLite is traditionally bound to local contexts due to POSIX network file-locking vulnerabilities (e.g., NFS). Plan 9's native **9P protocol** guarantees coherent file locking and atomic transactions, allowing multiple terminal nodes to safely write to a single centralized `.sqlite` file hosted on a file server (`cwfs` or `hjfs`).

---

## 2. Theoretical Configuration & Deployment Guide

This section outlines a theoretical methodology to hook your statically compiled PHP binary into Plan 9's native networking and web hosting layers.

### Phase A: Organizing the Web Directory structure
In Plan 9, the standard web root is traditionally served from `/usr/web`. We will configure a dedicated workspace for our PLAS applications.

```rc
# Create our application and data directories inside the web root
mkdir -p /usr/web/plas/bin
mkdir -p /usr/web/plas/db
mkdir -p /usr/web/plas/htdocs

# Move your static PHP binary into place and make it executable
cp /sys/src/cmd/php/php /usr/web/plas/bin/php
chmod +x /usr/web/plas/bin/php

# Pre-initialize an empty SQLite tracking database file
touch /usr/web/plas/db/app.sqlite
```

### Phase B: Hooking into `rc-httpd` via CGI
Plan 9’s `rc-httpd` maps specific directories or extensions to executable command scripts using a simple configuration style. To pass incoming scripts to your static binary, create a handling gateway wrapper script.

Create the wrapper script at `/usr/web/plas/bin/php-cgi`:

```rc
#!/bin/rc
# php-cgi - A simple bridge passing CGI parameters into our static PHP binary

# Read standard CGI environment variables passed down by rc-httpd
# Plan 9 populates execution environments under /env/

if(! test -f $PATH_TRANSLATED){
    echo 'Status: 404 Not Found'
    echo 'Content-Type: text/html'
    echo ''
    echo '<h1>404 File Not Found</h1>'
    exit
}

# Execute the static binary in CGI mode, parsing the target script
exec /usr/web/plas/bin/php -c /usr/web/plas/bin/php.ini -f $PATH_TRANSLATED
```
Ensure the script is given execution permissions:
```rc
chmod +x /usr/web/plas/bin/php-cgi
```

Next, append a routing rule to your `/sys/lib/httpd.conf` config file so files ending in `.php` are piped into your wrapper:
```
# /sys/lib/httpd.conf addition
# Direct requests targeting .php scripts to our compiled binary bridge
cgi .php /usr/web/plas/bin/php-cgi
```

### Phase C: Initializing the Web Daemon
To fire up the listening service on standard HTTP port 80, invoke the network listener application:
```rc
# Run the native Plan 9 HTTP daemon
ip/httpd -h /usr/web
```

Alternatively, if you want an isolated server instance bound specifically to your directory without messing with the global system configuration, use `aux/listen1`:
```rc
# Instantly stream incoming TCP traffic on port 8080 directly through the CGI wrapper
aux/listen1 -v tcp!*!8080 /usr/web/plas/bin/php-cgi
```

---

## 3. Practical Integration Scripts

### Script 1: Interacting with SQLite database
Save this script as `/usr/web/plas/htdocs/index.php`. It demonstrates how the statically compiled engine processes structural queries internally on a local file resource.

```php
<?php
header('Content-Type: text/html; charset=utf-8');

try {
    // Open connection to the flat file database managed over 9P namespaces
    $db = new PDO('sqlite:/usr/web/plas/db/app.sqlite');
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
    // Create a demo table structure if initialization is fresh
    $db->exec("CREATE TABLE IF NOT EXISTS system_logs (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
        event TEXT,
        details TEXT
    )");
    
    // Log the current hit event
    $stmt = $db->prepare("INSERT INTO system_logs (event, details) VALUES (:event, :details)");
    $stmt->execute([
        ':event' => 'HTTP_REQUEST',
        ':details' => 'Client accessed endpoint via user-agent: ' . ($_SERVER['HTTP_USER_AGENT'] ?? 'Unknown')
    ]);
    
    // Query historical entry points
    $results = $db->query("SELECT * FROM system_logs ORDER BY id DESC LIMIT 5");
    
    echo "<h1>PLAS Stack Deployment Status: Operational</h1>";
    echo "<h3>Recent Database Entries (SQLite Embedded Engine):</h3>";
    echo "<ul>";
    foreach ($results as $row) {
        echo "<li>[" . htmlspecialchars($row['timestamp']) . "] " . htmlspecialchars($row['event']) . " - " . htmlspecialchars($row['details']) . "</li>";
    }
    echo "</ul>";
    
} catch (PDOException $e) {
    echo "<h2>Database Error: " . htmlspecialchars($e->getMessage()) . "</h2>";
}
?>
```

### Script 2: Exposing Plan 9 System/Network States as JSON
Because Plan 9 presents kernel states as accessible flat text structures, your static PHP application can read core metrics directly without invoking external shell scripts. Save this example as `/usr/web/plas/htdocs/sysstat.php`.

```php
<?php
header('Content-Type: application/json');

$response = [
    'stack' => 'PLAS (Plan 9, Listen, SQLite, PHP)',
    'status' => 'healthy',
    'system_metrics' => []
];

// 1. Read System Uptime and CPU utilization metrics out of /dev/sysstat
if (file_exists('/dev/sysstat')) {
    $sysstat = file_get_contents('/dev/sysstat');
    $metrics = preg_split('/\s+/', trim($sysstat));
    $response['system_metrics']['raw_sysstat'] = $metrics;
}

// 2. Read Active TCP Network connections straight out of Plan 9 synthetic networking stack
if (file_exists('/net/tcp')) {
    $tcp_connections = [];
    $connections = glob('/net/tcp/*');
    foreach ($connections as $conn) {
        if (is_dir($conn) && file_exists($conn . '/status')) {
            $status = trim(file_get_contents($conn . '/status'));
            if (!empty($status)) {
                $tcp_connections[] = [
                    'connection_id' => basename($conn),
                    'status' => $status
                ];
            }
        }
    }
    $response['network_state'] = [
        'active_tcp_directories' => count($connections),
        'connections' => $tcp_connections
    ];
}

echo json_encode($response, JSON_PRETTY_PRINT);
?>
```
