#include <vector>
template <class T = double>
class Matrix
{
private:
	int _n, _m;
	std::vector<T> matrix;

public:

	void set






	Matrix(T n, T m)
	{
		_n = n;
		_m = m;
		while(n){
			std::vector<T> row(m);
			matrix.push_back(row);	
		}
	}
};
