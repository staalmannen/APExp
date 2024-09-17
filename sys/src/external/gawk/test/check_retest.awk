FNR == 1 { save = $0 }
FNR %2 == 0 { if ($0 != save) exit 1 }
