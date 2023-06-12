/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buny <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:50:37 by buny              #+#    #+#             */
/*   Updated: 2023/06/09 13:50:44 by buny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
    private:
        int         contactStatus;
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNbr;
        std::string darkSecret;

        void        setParam(std::string const&str, std::string &Parameter);

    public:
        Contact(void);
        ~Contact(void);

        int         status(void);
        void        setContact(void);
        std::string getParameter(int i);
};

#endif