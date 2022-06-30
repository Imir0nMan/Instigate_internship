#include <iostream>
using namespace std;

float gcayin(float num1,float num2){
	if(num1==0)return false;
	else if(num1==0 && num2==0) return true;
	else return num2/num1;
}

int main(){
cout<<gcayin(134.22,3663.32)<<endl;
return 0;
}
