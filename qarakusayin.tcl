proc qarakusayin {a b c} {
        set b1 [expr $b%2]
        if {$b1==0} {
                set d [expr $b/2*$b/2-$a*$c]
                if {$d>0} {
                        set t1 [expr -$b/2 + sqrt($d)/$a]
                        set t2 [expr -$b/2 - sqrt($d)/$a]
                  #puts " Dicrimanant is $d . The values are $t1 and $t2"
                  return [list $t1 $t2]
                }
                if { $d==0} {
                        set t [expr -$b/2/$a]
                        #puts " Dicrimanant is $d . The value ia $t"
                  return $t
                }
                if { $d<0 } {
                        #puts "Not real solutions because $d is smaller than 0"
                  return 0
                }
        }
        if {$b1==1} {
                set d [expr $b*$b-4*$a*$c]
                if {$d>0} {
                        set sum [expr -$b + sqrt($d)]
                        set sum1 [expr -$b - sqrt($d)]
                        set t1 [expr $sum/2*$a]
                        set t2 [expr $sum1/2*$a]
                        #puts " Dicrimanant is $d . The values are $t1 and $t2"
                  return [list $t1 $t2] 
                }
                if {$d==0} {
                        set t [expr -$b/2*$a]
                        #puts " Dicrimanant is $d . The value ia $t"
                  return $t
                }
                if {$d<0} {
                        #puts "Not real solutions because $d is smaller than 0"
                  return 0
                }
        }

}

set fr [open "naxnakan.txt" r]
set fp [open "freefile.txt" w+]
while { [gets $fr data] >= 0 } {
	split $data , 
	#puts [expr double([index $data 0])]
	puts 
	#set k [expr int([index $data 0])]
	#set l [expr int([index $data 1])]
	#set m [expr int([index $data 2])]
	#puts "$k $l $m"
   	#puts $fp [qarakusayin $k $l $m]
}
close $fp
close $fr

#set a [gets stdin]
#set b [gets stdin]
#set c [gets stdin]
#puts [qarakusayin $a $b $c]
