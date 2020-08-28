// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
// FizzBuzz, counts up from zero. Every time the counter reaches a multiple of 3 it should print the word "Fizz",
// for multiples of 5 it should print "Buzz". If it is a multiple of both, the program should print "FizzBuzz".

#include <iostream>
#include <string>

int main()
{
	int UPPER = 100;
	

	for (int i = 1; i <= UPPER; ++i)
	{
		std::string out;
		
		out.append(std::to_string(i));
		out.append(". ");
		
		if (i % 3 == 0)
			out.append("Fizz");
		
		if (i % 5 == 0)
			out.append("Buzz");

		if (out.find("Buzz") != std::string::npos)
			out.append(" lightyear");

		std::cout << out << "\n";

	}
}

/*
int main()
{
	// v 1.0
	int i = 1;
	
	do
	{
		if (i % 5 == 0 && i % 3 == 0)
		{
			std::cout << i << ". FizzBuzz\n";
		}
		else if (i % 5 == 0)
		{
			std::cout << i << ". Buzz\n";
		}
		else if (i % 3 == 0)
		{
			std::cout << i << ". Fizz\n";
		}
		else
		{
			std::cout << i << ".\n";
		}
		
		i++;
	}while (i < 25);
    
}
*/

