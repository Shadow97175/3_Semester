#include <stdio.h>
#include <string>
#include <iostream>


std::string read()
{
	std::string in;
	std::cout << "Enter a fractional decimal number:" << std::endl;;
	std::cin >> in;
	return in;
}

int main(void)
{
	std::string input = read();
	int por = 0;
	int zn = 1;
	if (input[0] == '-')
	{
		zn = 1;
		input.erase(input.begin());
	}
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ',')
		{
			input[i] = '.';
		}
	}
	double a = std::stod(input.substr());
	while ((a < 1) || (a > 10))
	{
		if (a > 10)
		{
			por++;
			a = a * 0.1;
		}
		if (a < 1)
		{
			por--;
			a = a * 10;
		}
	}
	std::cout << "Sign: " << zn << std::endl;
	std::cout << "Exponent: " << por << std::endl;
	std::cout << "Mantissa (normalized): " << a << std::endl;
}
