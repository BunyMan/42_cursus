/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myAwesomePhonebook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buny <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:52:40 by buny              #+#    #+#             */
/*   Updated: 2023/06/09 13:52:42 by buny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhonebook.hpp"


int main(){
    int i = 0;
    phoneBook p;
    std::string prompt;

    while(1)
    {
        if (!std::cin)
            return (0);
        std::cout << "Available Commands: \"ADD\"  \"SEARCH\"  \"EXIT\" -> ";
        std::getline(std::cin, prompt);
        if (!std::cin)
            return (0);
        while (!prompt.length())
        {
            std::getline(std::cin, prompt);
        }
        if (prompt == "ADD")
        {
            p.c[i % 8].setContact();
            std::cout << "Contact added on slot " << (i % 8) + 1 << std::endl;
            i++;
        }
        else if (prompt == "SEARCH")
        {
            p.searchFunc();
            std::getline(std::cin, prompt);
            if (!std::cin)
                return (0);
        }
        else if (prompt == "EXIT")
            return (0);
        else
            main();
    }
}