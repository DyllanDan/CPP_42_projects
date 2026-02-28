#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade; //150 (lower) - 1 (higher)
    
    public:
        //Canonical
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        //Methods
        Bureaucrat(int grade);
        const std::string getName();
        int getGrade();
        void setName();
        void setGrade();
        void gradeIncrement();
        void gradeDecrement();
        Bureaucrat std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);

}

#endif