proc jacobi {}

set input [open "input.txt" r]
while {[eof $input] != 1} {
	lappend inputs [gets $input]
}

puts $inputs
