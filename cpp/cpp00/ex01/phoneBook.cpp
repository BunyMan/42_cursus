#include "myAwesomePhonebook.hpp"

phoneBook::phoneBook(void) {
    return;
}

phoneBook::~phoneBook(void) {
    return;
}

void phoneBook::printParams(void) {
    std::cout << std::string(45, '_') << std::endl;
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
}

int phoneBook::searchForIndex(void) {
    std::string index;

    std::getline(std::cin, index);
    if (!std::cin)
        return (1);
    for (int i = 0; index[i]; i++) {
        if (index.length() == 0 || index[i] <= '0' || index[i] >= '9') {
            std::cout << "Invalid index selected" << std::endl;
            return (0);
        }
    }
    if (index.length() != 1 || index[0] == '9' || !c[index[0] - 49].status()) {
        std::cout << "Index out of range" << std::endl;
        return (0);
    }
    std::cout << "FIRST NAME     :" << c[index[0] - 49].getParameter(1) << std::endl;
    std::cout << "LAST NAME      :" << c[index[0] - 49].getParameter(2) << std::endl;
    std::cout << "NICKNAME       :" << c[index[0] - 49].getParameter(3) << std::endl;
    std::cout << "PHONE NUMBER   :" << c[index[0] - 49].getParameter(4) << std::endl;
    std::cout << "DARKEST SECRET :" << c[index[0] - 49].getParameter(5) << std::endl;
    std::getline(std::cin, index);
    return (1);
}

void phoneBook::printContactInfo(int i, int j) {
    std::string print;

    if (c[i].getParameter(j).length() < 9) {
        std::cout << std::setw(10);
        std::cout << c[i].getParameter(j);
        return;
    }
    for (int k = 0; k < 9; k++)
        std::cout << c[i].getParameter(j)[k];
    if (c[i].getParameter(j).length() == 10)
        std::cout << c[i].getParameter(j)[9];
    else
        std::cout << ".";
}

void phoneBook::searchFunc(void) {
    if (!c[0].status()) {
        std::cout << "Haha you ain't got friends" << std::endl;
        return;
    }
    printParams();
    for (int i = 0; i < 8; i++) {
        if (c[i].status()) {
            std::cout << std::string(45, '_') << std::endl;
            std::cout << "|     " << i + 1 << "    ";
            for (int j = 1; j < 4; j++) {
                std::cout << "|";
                printContactInfo(i, j);
            }
            std::cout << "|" << std::endl;
            std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
        }
    }
    std::cout << "\n";
    std::cout << "Type the index of the contact you want to display -> ";
    while (!searchForIndex())
        ;

}