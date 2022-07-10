#include<iostream>
#include <fstream>
#include <string>
using namespace std;

const double epsilon = 1/(1000);
void jakobs(ifstream &input, ofstream &output)
{
        int n = 3;
	input >> n;
	int mat[n][n+1];
	float curr[n] = {0}; 
	float prev[n] = {0};
	for (int i = 0;i < n; ++i)
        {
                for (int j = 0;j <= n; ++j)
                {
                        input>>mat[i][j];
			output << mat[i][j] << ' ';
		}               
                output<<endl;
        }
	output<<endl;
	float maxi = 0;
	int iter = 0;
	bool for_exit = true;
	while (for_exit)
	{
		for (int i = 0; i < n; ++i)
                {
                        curr[i] = mat[i][n];
                        for (int j = 0; j < n; ++j)
                        {
                                if (j != i) {
                                        curr[i] -= prev[j]*mat[i][j];
                                }
                                else {
                                        continue;
                                }
                        }
                        curr[i] /= mat[i][i];
                }
		iter++;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
                        maxi = curr[i] - prev [i];
                        if (abs(maxi) <= epsilon)
			{
                                count++;
			}
                        if(count >= n)
			{
                                for_exit = false;
			}
			else if(iter > 30)
			{
				for_exit = false;
				output<<endl<<"Lucum chuni\n";	
			}
                        prev[i] = curr[i];
                        output<<prev[i]<<' ';
		}
		output<<endl;
	}
}	

int main() try
{
        ifstream input;
        ofstream output;
        input.open("input.txt");
        output.open("exit.txt");
        jakobs(input,output);
        input.close();
        output.close();
        return 0;
}
catch(const char* ex)
{
  std::cerr << ex << std::endl;
}
catch(...)
{
        std::cerr << "exception()" << std::endl;
}

