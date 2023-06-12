/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buny <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:51:01 by buny              #+#    #+#             */
/*   Updated: 2023/06/09 13:51:04 by buny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class phoneBook {
    private:
        void    printParams(void);
        int     searchForIndex(void);
        void    printContactInfo(int i, int j);
    
    public:
        Contact c[8];
        phoneBook(void);
        ~phoneBook(void);

        Contact getContact(int n);
        void    searchFunc(void);
};

#endif