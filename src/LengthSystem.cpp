#include "../include/LengthSystem.h"

void LengthSystem::printMenu(){
    std::cout << "=====================" << std::endl;
    std::cout << "    Length System      " << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "\n";

    printOptions();
}

void LengthSystem::printOptions(){
    std::cout << "Here are the S.I. measurement units for Length ! \n";
    for (auto option:available_Length_options)
    {
        std::cout << option.first << ") " << option.second << std::endl; 
    }
}


void LengthSystem::validateChoice(unsigned int user_choice, const std::vector<unsigned int> &acceptable_Length_options){
    for (auto option : acceptable_Length_options)
    {
        if(user_choice == option){
            return ;
        }
    }
    throw std::runtime_error("Invalid input! Please choose between the following: \n");
}

void LengthSystem::getChoice(){
    while (true)
    {
        try
        {
            std::cout << "Choose : " ;
            std::cin >> user_choice;
            std::cout << '\n';

            //in case of missclick (bad state of cin)
            if(std::cin.fail() || std::cin.peek() != '\n'){
                std::cin.clear();       
                std::cin.ignore(1000, '\n');  
                throw std::runtime_error("Invalid input!");
            }

            std::cout << "You have chosen : " << user_choice << std::endl;
            validateChoice(user_choice, acceptable_Length_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }   
    }
}

float LengthSystem::getLength(){
    while (true)
    {
        try
        {
            std::cin >> length;
            std::cout << "\n";

            //In case of invalid inpute (example temperature = 1/2)
            if(std::cin.fail() || std::cin.peek() != '\n'){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw std::runtime_error("Invalid input! Please enter a number that is acceptable with the following options: \n");
            }
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }
    }

    return length;
}


void LengthSystem::startSystem(){
    printMenu(); 

    while(true){
        getChoice();
        
        if (user_choice == 0)
        {
            std::cout << "Returning to Main Menu !" << std::endl;
            break;
        }

        std::cout << "Please insert the value of the length you want to convert: " << std::endl;
        std::cout << "Length = ";
        length = getLength();
        
        if (user_choice == 1)
        {

        }

        if (user_choice == 2)
        {
            
        }
        
        if (user_choice == 3)
        {
            
        }

        if (user_choice == 4)
        {

        }
    }
}