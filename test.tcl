#open test2.txt r
#open exit.txt w
set fp [open "exit.txt" w+]
set fi [open "test2.txt" r]

while { [gets $fi data] >= 0 } {
   puts $data
   puts $fp "$data"

}
close $fi
close $fp
