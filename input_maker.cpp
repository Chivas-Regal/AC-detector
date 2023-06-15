#include <iostream>

int main () {
    srand(time(NULL));
    std::cout << rand() % 10 << " " << rand() % 10 << std::endl;
}