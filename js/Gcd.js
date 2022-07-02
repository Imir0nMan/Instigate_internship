//Gcd algorythm

function gcd(num1, num2){
	if (num2 == 0) 
		return num1;
	else 
		return gcd(num2, num1 % num2);
}

let x = 3, y = 9;
let answer = gcd (x , y);
console.log(answer);
