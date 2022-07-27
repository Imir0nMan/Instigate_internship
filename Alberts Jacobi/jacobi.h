#ifndef JACOBI
#define JACOBI

#include "matrix.h"
#include <iomanip>

template <class T = double>
std::vector<Matrix<T>> MultiMatrix(const std::string& fileName) {
    std::ifstream in (fileName);
    if(in.is_open()) {
        int t;
        in >> t;
        std::vector<Matrix<T>> vec(t);
        for(int l = 0; l < t; ++l) {
            int _n, _m;
            in >> _n >> _m;
            vec[l].resize(_n);
            for(int i = 0; i < _n; ++i) {
                for(int j = 0; j < _m; ++j) {
                    T temp;
                    in >> temp;
                    vec[l][i].push_back(temp);
                }
            }
            vec[l].set_lines(_n);
            vec[l].set_columns(_m);
        }
        in.close();
        return vec;
    }

    std::cout << "Couldn't open the file";
    exit(-1);
}

template <class T>
T abs(const T value) {
    if (value >= 0) {
        return value;
    }
    return -1 * value;
}

void solution_output(std::vector<double> solution) {
    std::ofstream out ("output.txt", std::ios_base::app);
    if(out.is_open()) {
        if(!solution.empty()) {
            out << std::setprecision(3) << solution.front();
            for (int i = 1; i < solution.size(); ++i) {
                out << " " << std::setprecision(3) << solution.at(i);
            }
            /*for(double i : solution) {
                out << std::setprecision(3) << i << " ";
            }*/
        } else {
            out << "Not applicable matrix";
        }
        out << std::endl;
        out.close();
    } else {
        out  << "Couldn't open output.txt" << std::endl;
        return;
    }
}

template <class T>
std::vector<double> Jacobi(Matrix<T> m) {
    if(m.allZeroes() || !m.isApplicable()) {
        std::vector<double> empty_vec;
        return empty_vec;
    }
    double e = 0.001; // epsilon value, can be changed
    std::vector<double> prev(m.lines(),0);
    std::vector<double> iter(m.lines(),0); // the current values
    bool check = true;
    while(check) {
        for (int i = 0; i < m.lines(); i++) {
            prev[i] = iter[i];
            iter[i] = m[i][m.lines()];
            for (int j = 0;j < m.lines(); j++) {
                if (j != i) {
                    iter[i] -= iter[j]*m[i][j];
                }
                else {
                    continue;
                }
            }
            iter[i] /= m[i][i];
        }
        for (int i = 0; i < m.lines(); i++) {
            if (abs(iter[i] - prev[i] > e)) {
                break;
            }
            if (abs(iter[m.lines() - 1] - prev[m.lines() - 1] < e)) {
                check = false;
            }
        }
    }
    return iter;
}

#endif
