#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

const double epsilon = 1/(1000);
void jakobs(ifstream &input, ofstream &output)
{
	int n;
	// popoxakannery sranov em artahaytel
	//for epsilon exit
	//output.precision(4);
	//output.setf(ios::fixed);

// std::string str((std::istreambuf_iterator<char>(input)),
//                  std::istreambuf_iterator<char>());
  // fscanf(str.c_str(), "%d\n", &n);
  input >> n;
	std::vector< std::vector<int> > a(n + 1);
  int i = 0;
  // a[0].push_back(0);
  // auto l = fscanf(str.c_str(), "%d %d %d %d\n", &x, &y, &z, &m);
  while( true )
    {
        int x, y, z, m;
        if ( !(input >> x >> y >> m))
        {
           if (input.eof())
            break;
          
            throw "bad input";
        }
        a.at(i).push_back(x);
        a.at(i).push_back(y);
        a.at(i).push_back(m);
        ++i;
      // std::cout << "x: "<< x << std::endl;
      // std::cout << "y: "<< y << std::endl;
      // std::cout << "z: "<< z << std::endl;
        
    }
  // {
    // assert(l != 4);
  //     // a.at(i).push_back(x);
  //     // a.at(i).push_back(y);
  //     // a.at(i).push_back(z);
  //     ++i;
  // }
	std::vector<float> iter(n, 0);
	decltype(iter) prev(n, 0);

	// for (int i = 0;i < n; ++i)
	// {
	// 	for (int j = 0;j <= n; ++i)
	// 	{
	// 		int elem;

	// 		 input>>elem;
 //      std::cout << elem << std::endl;
	// 		 a.at(i).push_back(elem);
	// 		 output<<a.at(i).at(j)<<" ";
	// 	}
	// 	output<<endl;
	// }

	std::for_each(a.begin(), a.end(), 
	[&](std::vector<int>& v)
	{
		std::for_each(v.begin(), v.end(), 
		[&](int x)
		{
			std::cout << x << " ";
		});
		std::cout << std::endl;

	});
		
	float maxi = 0;
	int count = 0;
	bool for_out = true;
	while (for_out)
	{
		for (int i = 0; i < n; ++i)
		{
			iter.at(i) = (a.at(i).at(n));
			for (int j = 0; j < n; ++j)
			{
				if (j != i)
					iter.at(i) -= (prev.at(j))*(a.at(i).at(j)); 
				else
					continue;
			}
      std::for_each(iter.begin(), iter.end(), 
    	[&](int x)
    	{
    		
    		std::cout << x << " ";
    
    	});
    		std::cout << std::endl;
			assert(a.at(i).at(i) == 0);
			iter.at(i) /= a.at(i).at(i);

			// cout<<iter.at(i)<<" ";
			//for_out = false;
			count++;
		}

		for (int i=0;i<n;i++)
		{
			maxi = iter.at(i)-prev.at(i);	
			if (abs(maxi) <= epsilon)
				count++;
			if(count >= n)
				for_out = false;
			prev.at(i) = iter.at(i);
			output<<prev.at(i)<<"\n";
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


