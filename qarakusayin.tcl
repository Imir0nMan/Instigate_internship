#tcl qarakusayin
set A [gets stdin]
set B [gets stdin]
set C [gets stdin]

proc qarakusayin {A B C} {
   #  if{$A==0} {
   #    puts "qarakusayin havasarum che";
    #   return
   # }

   set D [expr {$B*$B-4*$A*$C}]
   set r [expr {-0.5*$B/$A}]
   set i [expr {0.5*sqrt(abs($D))/$A}]
   if {$D==0} {
         puts "x = $r"
    } elseif {$D>0} {
         puts "x1 = [expr {$r+$i}]"
         puts "x2 = [expr {$r-$i}]"
   } else {
   	puts "lucum chuni"      
   }
}

qarakusayin ($A $B $C)
