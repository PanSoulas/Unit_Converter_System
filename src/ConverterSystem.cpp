#include "../include/ConverterSystem.h"

char ConverterSystem::getUserChoice(){
    return user_choice;
}

void ConverterSystem::printHeader(){
    std::cout << "=====================" << std::endl;
    std::cout << "    Convert System       " << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "\n";
}

void ConverterSystem::printOptions(){
    for (auto option : available_options)
    {
        std::cout << option.first << ") " << option.second << std::endl; 
    }
}

void ConverterSystem::getChoice(){
    while (true)
    {
        try
        {
            std::cout << "Your choice is : " ;
            std::cin >> user_choice;
            //in case of missclick (bad state of cin)
            if(std::cin.fail() || std::cin.peek() != '\n'){
                std::cin.clear();       
                std::cin.ignore(1000, '\n');  
                throw std::runtime_error("Invalid input!");
            }
            validate_User_Choice(user_choice, acceptable_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }
    }
}


void ConverterSystem::printMenu(){
    std::cout << "=================================" << std::endl;
    std::cout << "  Welcome to the Convert System       " << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "\n";
    std::cout << " - Thank you for using the Converter System <3 " << std::endl;
    std::cout << " - Please choose which physical unit you want to convert - " << std::endl;

    printOptions();
}


void ConverterSystem::validate_User_Choice(char user_choice, const std::vector<std::pair<char, char>> &acceptable_options){
    for (auto choice : acceptable_options)
    {
        if (user_choice == choice.first || user_choice == choice.second)
        {
            return ;
        }
    }
    throw std::runtime_error("Invalid input! Please choose between the following options ");
}


void ConverterSystem::startSystem(){
    printMenu();
    getChoice();
}