#include <cstdlib>
#include "Harl.hpp"

int main(int ac, char **av)
{
    harl hl;

    if (ac != 2){
        return(std::cout << "Usage: <Level>" 
            << std::endl, EXIT_FAILURE);
    }
    std::string inputLevel = av[1];

    hl.complain(inputLevel);
    return (EXIT_SUCCESS);
}
