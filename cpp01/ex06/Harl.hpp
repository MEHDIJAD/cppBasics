#pragma once
#ifndef _HARL_HPP_
#define _HARL_HPP_

#include <string>
#include <iostream>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GRAY    "\033[90m" // Added GRAY color

class harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        void complain( std::string level );
};

typedef void (harl::*funcPtr)(void);

enum Level{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NONE,  
};

// typedef struct  s_complain
// {
//     std::string level;
//     funcPtr action;
// }   t_complain;

#endif