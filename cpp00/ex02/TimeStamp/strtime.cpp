#include <iostream>
#include <ctime>

int main(void)
{
    std::time_t time_raw = std::time(NULL);

    std::tm* time_info = std::localtime(&time_raw);

    char buffer[20];

    std::strftime(buffer, sizeof(buffer), "[%Y%M%d_%H%M%S]", time_info);

    std::cout << "Format Time: " << buffer << std::endl;
}
