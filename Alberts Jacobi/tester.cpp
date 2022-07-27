#include <iostream>
#include "jacobi.h"

void run() {
    std::vector<Matrix<double>> vec = MultiMatrix("input.txt");
    for(int i = 0; i < vec.size(); ++i) {
        std::vector<double> temp = Jacobi(vec[i]);
        solution_output(temp);
    }
}

void differ() {
    std::ifstream output;
    output.open("output.txt");
    std::ifstream golden;
    golden.open("golden.txt");
    std::ofstream diff;
    diff.open("diff.txt", std::ios::app);

    if(output.is_open() && golden.is_open()) {
        std::string o, g;
        while(std::getline(output, o) && std::getline(golden, g)) {
            if (o == g) {
                diff << "PASS " << o << std::endl;
            }
            else {
                diff << "FAILED: output " << o << ", golden " << g << "." << std::endl;
            }
        }
   }
   output.close();
   golden.close();
   diff.close();
}


int main() {
    run();
    differ();
}
