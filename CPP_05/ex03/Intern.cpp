/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydaniel <dydaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 13:13:05 by dydaniel          #+#    #+#             */
/*   Updated: 2026/03/28 14:08:32 by dydaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { }
Intern::Intern(const Intern& other){
    (void)other;
}
Intern::~Intern() { }

Intern& Intern::operator=(Intern const& other) {
    (void)other;
    return *this;
}


static AForm* createShrubbery(std::string const& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string const& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(std::string const& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const& name, std::string const& target) const {
    typedef AForm* (*FormCreator)(std::string const&);
    
    const struct {
        std::string name;
        FormCreator creator;
    } forms[] = {
        {"Shrubbery Form", createShrubbery},
        {"Robotomy Request", createRobotomy},
        {"Presidential Pardon", createPardon},
        {"", 0} //Fim do array
    };

    for (int i = 0; forms[i].name != ""; ++i) {
        if (name == forms[i].name) {
            AForm* form = (forms[i].creator)(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    std::cout << "Intern cannot create form called \"" << name << "\"" << std::endl;
    return 0;
}

