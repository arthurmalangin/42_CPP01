#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "Default constructor of ShrubberyCreationForm call !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getName(), 145, 137){
    std::cout << "Copy constructor of ShrubberyCreationForm call !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    std::cout << "Affectation constructor of ShrubberyCreationForm call !" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (obj.isSigned())
        this->setSigned();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "Destructor of ShrubberryCreationForm Call !" << std::endl;
}

std::string generateAsciiTree(void) {
    std::string asciiTxt;

    asciiTxt = "               ,@@@@@@@,\n";
    asciiTxt += "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    asciiTxt += "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    asciiTxt += "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n";
    asciiTxt += "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\'\n";
    asciiTxt += "   %&&%/ %&%%&&@@\\ V /@@\' `88\\8 `/88\'\n";
    asciiTxt += "   `&%\\ ` /%&\'    |.|        \\ \'|8\'\n";
    asciiTxt += "       |o|        | |         | |\n";
    asciiTxt += "       |.|        | |         | |\n";
    asciiTxt += "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
    return (asciiTxt);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (this->isSigned()) {
        if (executor.getGrade() <= this->getGradeToExectue()) {
            std::string fileName = this->getName() + "_shrubbery";
            std::ofstream output(fileName.c_str());
            if (output.is_open()) { //Verif if file is created
                output << generateAsciiTree();
                output.close(); //No forget to close
            }
        }
        else {
            throw Bureaucrat::GradeTooLowException();
        }
    }
    else {
        throw AForm::FormNotSignedException();
    }
}