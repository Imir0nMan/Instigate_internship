#ifndef GAUSS
#define GAUSS

#include <iomanip>
#include "matrix.h"

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
        out << "Not applicable Matrix";
        }
        out << std::endl;
        out.close();
    } else {
        out  << "Couldn't open output.txt" << std::endl;
        return;
    }
}

    template<class T>
void RowSort(Matrix<T>& m)
{
    for (int i = 0; i < m.lines(); i++)
    {
        for (int j = i + 1; j < m.lines(); j++)
        {
            if (abs(m[i][i]) < abs(m[j][i]))
            {
                m[i].swap(m[j]);
            }
        }
    }
    return;
}

template <class T>
bool GaussSub(Matrix<T>& m) {
    bool divZero = false;
    for (int i = 0; i < m.lines() - 1; i++) {
        for (int j = i + 1; j < m.lines(); j++) {
            if (m[i][i] == 0) {
                divZero = true;
                break;
            }
            float f = m[j][i] / m[i][i];
            m[j] -=  m[i]*f;
        }
        if(divZero){
            break;
        }
    }
    return !divZero;
}

template <class T>
void GaussSol(Matrix<T>& m, std::vector<double>& res) {

    for (int i = m.lines() - 1; i >= 0; --i) {
        res[i] = m[i][m.lines()];

        for (int j = i + 1; j < m.lines(); j++) {
            if (i != j) {
                res[i] = res[i] - m[i][j] * res[j];
            }
        }
        res[i] = res[i] / m[i][i];
    }
    return;
}

template <class T>
std::vector<double> Gauss(Matrix<T> m){
        std::vector<double> res(m.lines());
        //Sorting rows in increasing order
        RowSort(m);
        //Performing Gauss elimination
        //checking if the matrix was linear dependant
        if(GaussSub(m) && m[m.lines() -1][m.lines() -1] != 0) {
                //Getting the solution
                GaussSol(m,res);
        } else {
            res.resize(0);
        }
        return res;
}

#endif
