function diskriminant(a, b, c){
	return (b**2-4*a*c);
}

function oneRoot(a, b){
	return (-b/(2*a));
}

function quadratic(a, b, c){
	if (a != 0){
	let d = diskriminant(a, b, c);
		if (d > 0){
			let x1, x2;
			let sqrtD = Math.sqrt(d);
			x1 = ((-b-sqrtD)/(2*a));
			x2 = ((-b+sqrtD)/(2*a));
			return x1, x2;
		}
		else if (d == 0)
			return (oneRoot(a, b));
		else
			return "chuni lutsum";
	}
	else {
		if (b == 0 && c == 0)
			return "uni anverj lutsumner";
		else if (b == 0)
			return "chuni lutsum";
		else
			return c/b;
	}
}


let x, y, z;
x = 2;
y = 4;
z = 2;
let answer = quadratic(x, y, z);
console.log(answer);
