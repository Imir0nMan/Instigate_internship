function Linear(a ,b){
	if (a == 0 && b ==0){
		return "anverj lutsumner";
	}
	else if (a == 0)
		return "chka lutsum";
	else 
		return b/a;
}


let x, y;
x = 0;
y = 0;
let z = Linear(x,y);
console.log(z);
