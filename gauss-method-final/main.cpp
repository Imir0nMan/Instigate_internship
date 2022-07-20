#include <iostream>
#include "gauss.h"

void run() {
    std::vector<Matrix<double>> vec = MultiMatrix("input.txt");
    for(int i = 0; i < vec.size(); ++i) {
        std::vector<double> temp = Gauss(vec[i]);
        solution_output(temp);
    }
}


int main() {
    run();
}

