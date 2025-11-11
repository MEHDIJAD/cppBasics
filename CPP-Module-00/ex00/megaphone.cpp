#include <iostream>
#include <cctype>

int main(int ac __attribute__((unused)), char *av[])
{
	int i = 0;

	if (!av[1]) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}

	else {
		while(av[++i])
		{
			int j = -1;
			while (av[i][++j])
			{
				char c = av[i][j];
				if (std::isalpha(c)){
					c = std::toupper(c);
				}
				std::cout << c;
			}
		}
	}
	std::cout << std::endl;

	return (0);
}
