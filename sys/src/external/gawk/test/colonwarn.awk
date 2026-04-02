BEGIN { pattern = ARGV[1] + 0; delete ARGV }
pattern == 1	{ sub(/[][:space:]]/,""); print }	# no warning
pattern == 2	{ sub(/[\][:space:]]/,""); print }	# no warning
pattern == 3	{ sub(/[^[:space:]]/,""); print }	# no warning
pattern == 4	{ sub(/[^][:space:]]/,""); print }	# no warning
pattern == 5	{ sub(/[:space:]/, ""); print }		# warning
