#include <iostream>
#include <string>

// Program to demonstrate a personalized "Hello World"
// Fixed: removed 'using namespace std' for better code clarity

int main()
{
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}

