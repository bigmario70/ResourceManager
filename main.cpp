#include <iostream>
#include "LinesLoader.h"
#include "ProgressBar.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    LinesLoader myLoader("../prova.txt");
    ProgressBar myPB(&myLoader);
    myLoader.loadLines();
    myLoader.print();
    return 0;
}
