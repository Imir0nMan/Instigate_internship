let fs = require('fs');
let gaus = require('./gaus.js')
let Matrix = require('./matrix.js')


function test() {
	fs.writeFile('exit.txt', '', ()=>{});
        fs.writeFile('result.txt','',()=>{});
        let count = 0;
        let golden = fs.readFileSync('golden.txt','utf-8').split('\n');
        while(true){
                let arr = new Matrix(5)
                arr.init('test_input.txt')
                if(arr.matrix !== undefined){
                        fs.appendFileSync('exit.txt', gaus(arr).join('   ')+'\n',()=>{})
                        if(golden[count] === gaus(arr).join('   ')){
                                count++
                                fs.appendFileSync('result.txt','Test '+count+' passed\n',()=>{})
                        } else {
                                count++
                                fs.appendFileSync('result.txt','Test '+count+' failed!\n',()=>{})
                        }
                } else{
                        break
                }
        }
}

test()
