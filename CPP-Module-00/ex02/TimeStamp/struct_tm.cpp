#include <iostream>
#include <ctime>

int main(void)
{
    std::time_t time_raw = std::time(NULL);

    std::tm* time_info = std::localtime(&time_raw);

    std::cout << "Year " << 1900 + time_info->tm_year << std::endl;
    std::cout << "Month " << 1 + time_info->tm_mon << std::endl;
    std::cout << "Day " << time_info->tm_mday << std::endl;
    std::cout << "Hour " << time_info->tm_hour << std::endl;
}
