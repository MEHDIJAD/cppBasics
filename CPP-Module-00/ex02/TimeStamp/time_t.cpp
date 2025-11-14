#include <iostream>
#include <ctime>

int main(void)
{
    std::time_t res = std::time(NULL);
    std::cout << res << std::endl;
}
