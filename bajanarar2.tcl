
proc gsd2 {n m} {
	while {$m!=0} {
		set t $m
		set $m [expr "$n%$m"]
		set $n $t
		return $n
		puts $n
	}
	puts "$n"
}


puts "grel havasarman a-i gorcakicy: "
gets stdin a
puts "grel havasarman b-i gorcakicy: "
gets stdin b

gsd2 $a $b
