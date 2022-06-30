#amenamec bajanarar tcl
puts "grel havasarman a-i gorcakicy: "
gets stdin a
puts "grel havasarman b-i gorcakicy: "
gets stdin b


proc gsd {n m} {
	if {$b == 0} {
	   return $a
	} 
        return gcd [$b [expr $b%$a]] 
}

puts [gsd $a $b]
