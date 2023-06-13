#include <iostream>

int main(void) {

	std::string hi = "HI THIS IS BRAIN";
	std::string *stringPTR = &hi;
	std::string &stringREF = hi;
	
	std::cout << &hi << std::endl << stringPTR << std::endl << &stringREF << std::endl;
	std::cout << hi << std::endl << *stringPTR << std::endl << stringREF << std::endl;
}