#ifndef MATRIX
#define MATRIX

#include "row.h"
#include <fstream>
#include <string>

template <typename T>
class Matrix {
private:
	std::vector<Row<T>> mat;
	int n;
	int m;
public:

    Matrix() {
        n = 0;
        m = 0;
        mat.resize(0);
    }

	Matrix(int _n) {
		mat.resize(n);
		n = _n;
	}

	Matrix(std::initializer_list<Row<T>> _lines) : mat(_lines) {
		n = mat.size();
		if(!this->mat.empty()){
			m = mat[0].size();
		}
	}

    Matrix(const std::string& fileName) {
		std::ifstream in (fileName);
		if(in.is_open()) {
			int _n, _m;
			in >> _n >> _m;
			mat.resize(_n);
			for(int i = 0; i < _n; ++i) {
				for(int j = 0; j < _m; ++j)
				{
					T temp;
					in >> temp;
					mat[i].push_back(temp);
				}
			}
			n = _n;
			m = _m;
            in.close();
		} else {
			std::cout << "Couldn't open the file";
			exit(-1);
		}
	}

	~Matrix() {}

    void set_lines(int _n) {
        n = _n;
    }

    void set_columns(int _m) {
        m = _m;
    }
    void resize(int n)
    {
        this->mat.resize(n);
    }
    bool isApplicable() const {
         if(m != n+1)
         {
             return false;
         }
         for (int i = 0; i < n; i++) {
             float sum = 0;
             for (int j = 0; j < m; j++) {
                 if (i != j) {
                     sum += abs(mat[i][j]);
                 }
                 if (sum >= abs(mat[i][i])) {
                     return false;
                 }
             }
         }
         return true;
     }


     bool allZeroes() const {
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < m; j++) {
                 if (this->mat[i][j] != 0) {
                     return false;
                 }
             }
         }
         return true;
     }


	bool square() const {
		return n == m;
	}

	bool rectangle() const {
		return n != m;
	}

	Row<T>& operator[] (int n) {
		if (n >= this->mat.size() || n < 0) {
			std::cout << "n is out of bounds, value is " << std::endl;
			exit(-1);
		}

		return this->mat[n];
	}

	int lines() const {
		return n;
	}

	int columns() const {
		return m;
	}

	void print() {
		for (int i = 0; i < this->lines(); ++i) {
			mat[i].print();
		}
	}
};

#endif
