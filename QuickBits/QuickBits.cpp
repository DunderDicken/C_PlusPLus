// QuickBits.cpp 

#include <iostream>


int main()
{
	//             a b c d e f g h i j k l m n o p q r s t u v w x y z
	// vowels:     a e i o u y
	// consonants: b c d f g h j k l m n p q r s t v w x z
	char vowels[7] = "aeiouy";
	char consonants[21] = "bcdfghjklmnpqrstvwxz";

	char word1[6];
	char word2[5];

	for (int i = 0; i < sizeof(word1); i++)
	{
		
		if (i == 1 || i == 2)
			word1[i] = vowels[rand() % sizeof(vowels)];
		else
			word1[i] = consonants[rand() % sizeof(consonants)];
	}
	
    std::cout << word1 <<" \n";
}


