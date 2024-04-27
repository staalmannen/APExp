# The full test will only work in a Swedish localte
# Try things that should work across the board
# BEGIN {
# 	s = "s� �r det"
# 	print match(s,/\ys�\y/), s ~ /\ys�\y/, "�" ~ /\w/
# }
BEGIN {
	printf "\"�\" = %c\n", "�"
	printf "\"�\" = %c\n", "�"
	s = "s� �r det"
	printf "s = \"%s\"\n", s
	printf "match(s,/\\ys�/) = %d\n", match(s, /\ys�/)
# 	printf "match(s,/s�\\y/) = %d\n", match(s, /s�\y/)
# 	printf "match(s,/\\ys�\\y/) = %d\n", match(s, /\ys�\y/)
	printf "s ~ /�/ = %d\n", s ~ /�/
	printf "s ~ /s�/ = %d\n", s ~ /s�/
	printf "s ~ /\\ys�/ = %d\n", s ~ /\ys�/
# 	printf "s ~ /s�\\y/ = %d\n", s ~ /s�\y/
# 	printf "s ~ /\\ys�\\y/ = %d\n", s ~ /\ys�\y/
# 	printf "\"�\" ~ /\\w/ = %d\n", "�" ~ /\w/
# 	printf "\"�\" ~ /\\w/ = %d\n", "�" ~ /\w/
# 	printf "\"�\" ~ /\\y�\\y/ = %d\n", "�" ~ /\y�\y/
# 	printf "\"�\" ~ /\\y�\\y/ = %d\n", "�" ~ /\y�\y/
# 	printf "\"�\" ~ /[[:alpha:]]/ = %d\n", "�" ~ /[[:alpha:]]/
# 	printf "\"�\" ~ /[[:alpha:]]/ = %d\n", "�" ~ /[[:alpha:]]/
}
