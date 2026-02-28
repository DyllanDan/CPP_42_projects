#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Deault Bureaucrat Constructor called" << std::endl;
    name = "";
    grade = 150;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Deault Bureaucrat Destructor called" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << "Deault Bureaucrat Copy Constructor called" << std::endl;
    this->name = other.name;
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->grade = other.grade;
    }
    return (*this);
}

Bureaucrat::Bureaucrat(int grade)
{
    std::cout << " Bureaucrat Grade Constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

const std::string Bureaucrat::getName()
{
    return(name);
}

int Bureaucrat::getGrade()
{
    return(grade);
}

void Bureaucrat::setName(std::string name)
{
    this->name = name;
}

void Bureaucrat::setGrade(int grade)
{
    this->grade = grade;
}

void Bureaucrat::gradeIncrement()
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::gradeDecrement()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau) {
    os << Bureaucrat.getName() << ", bureaucrat with grade  " << bureau.getGrade();
    return os;