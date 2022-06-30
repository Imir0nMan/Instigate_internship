#include <iostream>
#include <cmath>
#include <vector>

int d_qarrord(int a, int b, int c){
return ((b/2)*(b/2)-4*a*c);
}

int d_sovorakan(int a, int b, int c){
return (b*b-4*a*c);
}

int mekarmat(int a, int b){
return (-b/(2*a));
}

auto qarakusayin(int a, int b, int c){
	if (b%2==0){
	   int d = d_qarrord(a, b, c);
	   if (d>0){
	      	int x1,x2;
	      	x1 = -b/2 + sqrt(d)/a;
	      	x2 = -b/2 - sqrt(d)/a;
	   	return std::vector<int>({x1, x2});
	   } else if(d==0){
	     	int x1 = mekarmat(a ,b);
	      	return std::vector<int>({x1});
	   } else 
	        return std::vector<int>({0, 0, 0});

	} else if(b%2==1){
		int d = d_sovorakan(a, b, c);
                if (d>0){
			int x1, x2;
			x1 = (-b-sqrt(d))/(2*a);
			x2 = (-b+sqrt(d))/(2*a);
	   		return std::vector<int>({x1, x2});
		} else if(d==0){ 
                  	int x1 = mekarmat(a ,b);
                 	return std::vector<int>({x1});
                } else 
               	  	return std::vector<int>({0, 0, 0});

	} else 
		return std::vector<int>({0, 0, 0});

}

int main(){
	auto x = qarakusayin(7, 15, 2);
	for (auto&i: x){
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;;
return 0;
}
