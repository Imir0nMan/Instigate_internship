#ifndef ROW
#define ROW

#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T> class Row
{
private:
	std::vector<T> vec;
public:
	Row() {
        vec.resize(0);
    }
	Row(std::initializer_list<T> nums)
		: vec(nums) {}

	Row(const Row<T>& row) {
		for(int i = 0; i < row.size(); ++i) {
			vec.push_back(row[i]);
		}
	}

	~Row() {}

	bool empty() const {
		return vec.empty();
	}

	int size() const {
		return vec.size();
	}

	void push_back(T i) {
		vec.push_back(i);
	}

	void print() const {
		if(!this->empty()) {
			for(int i = 0; i < this->size(); ++i) {
				std::cout << this->vec[i] << " ";
			}
			std::cout << std::endl;
		}
	}

	T& operator[](int n) {
		if (n < 0 || n >= this->size()) {
			std::cout << "Index is out of bounds.\n";
			return this->vec[0];
		}

		return this->vec[n];
	}

	T operator[](int n) const {
		if (n < 0 || n >= this->size()) {
			std::cout << "Index is out of bounds.\n";
			return this->vec[0];
		}

		return this->vec[n];
	}


	void swap(Row<T>& row) {
		for (int i = 0; i < this->size(); i++) {
			this->vec[i] += row[i];
			row[i] = this->vec[i] - row[i];
			this->vec[i] -= row[i];
		}
	}

	bool operator==(const Row<T>& row) const {
		if (this->size() != row.size()) {
			return false;
		}
		for (int i = 0; i < row.size(); ++i) {
			if (this[i] != row[i]) {
				return false;
			}
		}
		return true;
	}

	void operator+=(const Row<T>& row) {
		if (this->size() == row.size()) {
			for (int i = 0; i < this->size(); i++) {
				vec[i] += row[i];
			}
		}
		else {
			return;
		}
	}

	void operator-=(const Row<T>& row) {
		if (this->size() == row.size()) {
			for (int i = 0; i < this->size(); i++) {
				vec[i] -= row[i];
			}
		}
		else {
			return;
		}
	}

	void  operator=(const Row<T>& row) {
		this->vec.clear();
		for(int i = 0; i < row.size(); ++i) {
			this->vec.push_back(row[i]);
		}
	}
	void operator*=(const double m) {
		for (int i = 0; i < this->size(); i++) {
			vec[i] *= m;
		}
	}
	void operator/=(const double d)	{
		for (int i = 0; i < this->size(); i++) {
			vec[i] /= d;
		}
	}

	Row<T> operator*(const double d) {
		Row<T> temp (*this);
		temp *= d;
		return temp;
	}
};





#endif
