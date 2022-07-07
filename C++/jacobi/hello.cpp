#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

const double epsilon = 1/(10*10*10);
float maxi, x1, x2, x3 = 0;
bool for_out = true;
void gaus(ifstream &input, ofstream &output)
{
char var[] = {'x','y','z','k','l','m','n','o','p'};
    int n;
    // popoxakannery sranov em artahaytel
    float iter[n] = {0};
    //for epsylon exit
    float eps[n] = {0}; 
    //output.precision(4);
    //output.setf(ios::fixed);
    input>>n;
    int a[n][n+1];
    for (int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
                 input>>a[i][j];
   		 output<<a[i][j]<<" ";
	}
	output<<endl;
    }
    
    while (for_out){
    	for (int i=0;i<n;i++){
    	   	iter[i] = a[i][n];
		for (int j=0;j<n;j++){
			if (j != i){
				iter[i] -= iter[j]*a[i][j]; 
			}
			else
				continue;
		}
		iter[i] /= a[i][i];
        }
	for (int i=0;i<n;i++){
		int count = 0;
		maxi = abs(iter[i]-eps[i]);
		if (maxi <= epsilon){
			count++;
		}
		if(count >= n)
			for_out = false;
	}
	
    }	    


    
}
int main(){
	ifstream input;
        ofstream output;
        input.open("input.txt");
        output.open("exit.txt");
        gaus(input,output);
        input.close();
        output.close();
	return 0;
}
