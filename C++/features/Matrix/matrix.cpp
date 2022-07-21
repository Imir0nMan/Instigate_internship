#include <vector>
#include <iostream>
template <class T = double>
class Matrix
{
private:
	int _n, _m;
	std::vector<std::vector<T> > matrix;

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
		




	Matrix(T n, T m)
	{
		_n = n;
		_m = m;
		matrix.resize(_n);
		for (int i = 0; i < _n; i++){
			std::vector<T> row (m, 0);
			matrix.push_back(row);
		}
	}
};




int main()
{
	Matrix<double> mat(3, 4);
	mat.print();
	
	return 0;
}

