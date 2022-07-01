#include <cmath>
#include <vector>
//quadrate file


float d_qarrord(float a, float b, float c){
return ((b/2)*(b/2)-4*a*c);
}

float d_sovorakan(float a, float b, float c){
return (b*b-4*a*c);
}

float mekarmat(float a, float b){
return (-b/(2*a));
}

auto qarakusayin(float a, float b, float c){
	float d = d_sovorakan(a, b, c);
        if (d>0){
		float x1, x2;
		x1 = (-b-sqrt(d))/(2*a);
		x2 = (-b+sqrt(d))/(2*a);
	   	return std::vector<float>({x1, x2});
	} else if(d==0){ 
                float x1 = mekarmat(a ,b);
                return std::vector<float>({x1});
        } else return std::vector<float>({0, 0, 0});
}
