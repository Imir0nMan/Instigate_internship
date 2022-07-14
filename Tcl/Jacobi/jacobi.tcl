proc arr lines {
	foreach line $lines {
		lappend a [split $line " "]
	}

	puts $a
}


set input [open "input.txt" r]
set all_data [read $input]
set data [split $all_data "\n"]
arr $data
