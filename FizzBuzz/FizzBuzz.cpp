// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
// FizzBuzz, counts up from zero. Every time the counter reaches a multiple of 3 it should print the word "Fizz",
// for multiples of 5 it should print "Buzz". If it is a multiple of both, the program should print "FizzBuzz".

#include <iostream>

int main()
{
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


