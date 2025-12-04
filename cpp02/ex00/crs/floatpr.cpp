#include <iostream>
#include <iomanip>

int main() {
    double a = 0.1;
    double b = 0.2;
    
    if (a + b == 0.3) {
        std::cout << "Math works!" << std::endl;
    } else {
        std::cout << "Math is broken." << std::endl;
    }

    // Let's see what the computer actually sees
    std::cout << std::setprecision(17) << (a + b) << std::endl;
}
