#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;

    public:
        /* Constructor */
        Zombie(std::string name);

        void announce( void ); // <name>: BraiiiiiiinnnzzzZ...

        /* Destructor */
        ~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif

