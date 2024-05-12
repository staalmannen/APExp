# This AWK program performs substantially the same function as the
# dedicated ctags program available under UNIX.

# NOTE: modified (see end of file) by stes 9/97 to do Objective C.
# Original of file freely available at http://www.tasoft.com.

# It looks through C source files for function and pre-processor
# declarations and outputs an index file to be used by the "vi"
# text editor to look up those functions.
# Invoke this program like this:
#		awk -f ctags.awk *.h *.c > tags


# This function adds a tag to the tag array.
# Name is the name of the tag.
# Line is the line on which the tag appears.
# Truncate line to 60 characters; that should be enough to be unique.

# stes 10/97 changed so that duplicate tags allowed
function addtag(name,line)
{
	# Change all occurences of "/" to "\/" and "\" to "\\"
	gsub(/\\/,"\\\\",line)
	gsub(/\//,"\\/",line)
	tag[tagcount++] = name "\t" FILENAME "\t/" substr(line,1,60) "/"
}

# stes 10/97 hint support for ELVIS
function addtagclass(name,line,hint)
{
	# Change all occurences of "/" to "\/" and "\" to "\\"
	gsub(/\\/,"\\\\",line)
	gsub(/\//,"\\/",line)
        # the ;" is so that regular vi can read ELVIS tags files
	# (see elvis man page for more details)
	if (NOHINT) {
	    tag[tagcount++] = name "\t" FILENAME "\t/" substr(line,1,60) "/"
	} else {
	    tag[tagcount++] = name "\t" FILENAME "\t/" substr(line,1,60) "/;\"\tclass:" hint
	}
}

BEGIN {
    tagcount = 0;
}

# Added 3-96: Ignore lines that start as a C++ comment
/^[ 	]*\/\// { next }

# Added 3-96: Attempt to skip multi line comments.  Simple minded.
/^[ 	]*\/\*/		{
	while ($0 !~ /\*\//) {
		getline
	}
}


# The following pattern skips over obvious procedure bodies,
# allowing this AWK program to run much faster.
# The curly braces must appear in column 1.
# If you use a different convention for procedure bodies you can remove this.
/^{/,/^}/	{ next }


# Skip any line that begins with a comment.
/^[ 	]*\/\*/		{ next }

{ curline = $0 }	# Save for later, because we are changing $0 below.


# I like to include pre-processor definitions with arguments in the tags file.
# I do not include pre-processor definitions without arguments in my
# tags file, but if you want to do so then simplify the pattern below to:
#			/^#[ \t]*define/
# Or you can remove this code if you don't want pre-processor definitions
# included in the tags file.
/^#[ \t]*define[ \t]+[^ \t\(\)]+\(/	{
	# This split statement breaks up the line so
	# that va[2] is "define" and va[3] is the name being defined.
	split($0,va,"[# \t()]+")
	addtag(va[3],$0)
	next
}


# Skip over other pre-processor lines.
/^#/		{ next }

# 9-93: Try to handle multi-line function defintions.
# If line ends with a comma or left paren or ..., append the next line
# Make sure we are not in a comment.  To check, just look for /,
# which can not occur in a function definition.
# 10-96: removed this
#{
#	local fnd
#	while ($0 ~ /^[^/#]*[,(.][ \t]*$/) {
#		getline nextline
#		$0 = $0 nextline
#		fnd = 1
#	}
#}


# A function definition begins in column one and is followed
# by a parenthesized list not followed by a semi-colon.
# 9-93: The parenthesized list may contain matching parentheses to handle
# decls with function pointers like this:  int foo(  int (int *x)() )
# If you use a different convention for function definitions
# you will have to change this.
# 10-96: improved to handle multi-line function definitions.
#/^[^ 	]/ && /^[^;\/]* *\(([^()]|\([^()]*\))*\)[^,;]*$/ {
/^[a-zA-Z_]/ {
	gsub(/\/\*.*\*\//s,"")  # Remove in-line comments
	# While the accumulated line contains only characters that may
	# appear in a function declaration:
	while ($0 ~ /^[a-zA-Z_0-9*.,() \t]*$/) {
		# If it is a complete function declaration, add it to our list:
		if ($0 ~ /^[a-zA-Z_][a-zA-Z0-9_()* \t]*\(([a-zA-Z0-9_*., \t]|\([a-zA-Z0-9_*., \t]*\))*\)[^,;]*$/) {
			decl = substr($0,1,index($0,"(") - 1)
			if (decl ~ /\"/) next		# Skip strings
			sub(/ *$/,"",decl)
			n = split(decl,va,"[ \t*]+")
			rtnname = va[n]
			if (rtnname == "if") next
			if (rtnname == "do") next
			if (rtnname == "while") next
			if (rtnname == "until") next
			if (rtnname == "switch") next
	
			addtag(rtnname,curline)
		}
		# Append next line, and try again.
		getline nextline
		gsub(/\/\*.*\*\//s,"",nextline)  # Remove in-line comments
		$0 = $0 nextline
	}
	next
}


# I also like to put structure definitions in the tags file.
/^[ \t]*struct[ \t]+[a-zA-Z_]+[ \t]*{/ {
	split($0,va)
	addtag(va[2],curline)
	next
}

# stes 9/97 put Object implementations in tags file.
/^[ \t]*@implementation[ \t]+[a-zA-Z_]+[ \t]*/ {
    split($0,va)
    curclass=va[2]; # stes 10/97 for ELVIS hints
    addtag(va[2],curline)
    next
}

# stes 10/97 emit leading keyword for ^] feature
function makeLkw(ka)
{
    split(ka[1],kw,":"); # get first keywrod
    return kw[1];
}

# stes 10/97 little function to drop arguments and
# fabricate a selector, so that we can emit a "full
# selector name" in addition to the first keyword.
function makeSel(sel,ka,n)
{
    for (i=1;i<=n;i++) {
	m=split(ka[i],kw,":");
	if (m==1) sel = sel kw[1];
	else sel = sel kw[1] ":";
    } 
    return sel;
}

# stes 9/97 instance or factory methods with possibly cast in front of them
# emit first keyword as tag (for cntrl-]) and also a complete selector.
/^[ \t]*[+\-]/ {
    f=sub(/+/,"");if (f) sel="+"; # remove leading +
    f=sub(/\-/,"");if (f) sel="-"; # remove leading -
    sub(/[ \t]/,""); # remove *leading* spaces
    gsub(/\([^)]*\)/,""); # remove all type casts
    gsub(/[ \t]*:[ \t]*/,":"); # remove spaces around ':'
    n=split($0,ka); # get key:arg pairs
    addtagclass(makeLkw(ka),curline,curclass);
    addtagclass(makeSel(sel,ka,n),curline,curclass);
    next;
}

# Ignore all other lines
{ next }

END {
	# Print out the tags in alphabetic order.
	for (i in tag) {
		print tag[i] | "sort"
	}
}
