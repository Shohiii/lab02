#include <iostream>
#include <string>

// Программа для демонстрации персонализированного "Hello World"
// Исправлено: удалено 'using namespace std' для большей ясности кода

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}



