match(/fn [A-Za-z0-9_]+/, $0) {print substr($0, RSTART + 3, RLENGTH - 3)}
