#include "myAwesomePhonebook.hpp"

Contact::Contact(void) {
    contactStatus = 0;
    return ;
}

Contact::~Contact(void) {
    return ;
}

int Contact::status(void) {
    return (contactStatus);
}

std::string Contact::getParameter(int opt) {
    if (opt == 1)
        return (firstName);
    if (opt == 2)
        return (lastName);
    if (opt == 3)
        return (nickName);
    if (opt == 4)
        return (phoneNbr);
    if (opt == 5)
        return (darkSecret);
    return ("Invalid option");
}

void Contact::setParam(std::string const&str, std::string &parameter) {
    std::cout << str;
    std::getline(std::cin, parameter);
    if (!std::cin)
        return ;
    while (!parameter.length())
        std::getline(std::cin, parameter);
}

void Contact::setContact(void) {
    Contact::setParam("Type the first name of your contact -> ", firstName);
    Contact::setParam("Type the last name of your contact -> ", lastName);
    Contact::setParam("Type the nick name of your contact -> ", nickName);
    Contact::setParam("Type the phone number of your contact -> ", phoneNbr);
    Contact::setParam("Type the darkest secret of your contact -> ", darkSecret);
    contactStatus = 1;
}