#include <iostream>
#include <fstream>

class Matrix
{
	private:
		int _n, _m;
		double** matrix;
	public:

		void print()
		{
			for(int i = 0; i < _n; ++i){
				for(int j = 0; j < _m; ++j){
					std::cout<<matrix[i][j]<<"\t";
				}
				std::cout<<std::endl;
			}
		}

		double operator()(int n, int m)
		{
			if(n < 0 || n >= _n || m < 0 || m >= _m){
				std::cout<<"out of range "<<std::endl;
				return NULL;
			}
			return matrix [n][m];
		}
		
		void operator>>

		void first_set_of_elem(int n, int m, double elem)
		{
			matrix[n][m] = elem;
		}

		Matrix(int  n, int  m)
		{
			_n = n;
			_m = m;
			matrix = new double* [_n];
			for (int i = 0; i < _n; i++){
				matrix[i] = new double[_m];
			}
			/*
			for (int i = 0; i < _n; i++){
				for (int j = 0; j < _m; j++){
					matrix[i][j] = j+i;
				}					
			}
			*/
		}
};




int main()
{
	std::ifstream input ("input.txt");
	int n, m;
	input >> n >> m;
	Matrix mat(n, m);
	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			input>>mat;
		}
	}
	mat.print();
	
	return 0;
}

