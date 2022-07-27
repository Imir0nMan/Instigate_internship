#include<iostream>
#include "jacobi.h"

void run() {
    std::vector<Matrix<double>> vec = MultiMatrix("input.txt");
    for(int i = 0; i < vec.size(); ++i) {
        std::vector<double> temp = Jacobi(vec[i]);
        solution_output(temp);
    }
}


int main() {
    run();
}

