#include <iostream>
#include <regex>
#include <string>

/*In your C++ folder, create a new file called 'email.cpp'. In this file, create a function called 'emailIsValid' that takes
a string called 'email' as input and returns true if the email is valid and false otherwise. 
An email is considered valid if and only if it satisfies the requirements specified under 
'Syntax requirements' on the webpage whose URL is given in the previous screenshot.*/ 

bool emailIsValid(const std::string& email) {

    const std::regex pattern(
        "((^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+)"     
        "(@)"                                    
        "((?:[a-zA-Z0-9-]+\.)+[a-zA-Z]{2,}$))"   
    );
    

    return std::regex_match(email, pattern);
}

int main() {
    std::string email;
    std::cout << "Enter an email address: ";
    std::cin >> email;

    if (emailIsValid(email)) {
        std::cout << "The email address is valid." << std::endl;
    } else {
        std::cout << "The email address is invalid." << std::endl;
    }

    return 0;
}
