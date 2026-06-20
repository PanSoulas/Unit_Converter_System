#include "../include/MassSystem.h"

void MassSystem::printMenu(){
    std::cout << "=====================" << std::endl;
    std::cout << "      Mass System      " << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "\n";

    printOptions();
}

void MassSystem::printOptions(){
    std::cout << "Here are the S.I. measurement units for Mass ! \n";
    for (auto option:available_Mass_options)
    {
        std::cout << option.first << ") " << option.second << std::endl; 
    }
}

void MassSystem::validateChoice(unsigned int user_choice, const std::vector<unsigned int> &acceptable_Mass_options){
    for (auto option : acceptable_Mass_options)
    {
        if(user_choice == option){
            return ;
        }
    }
    throw std::runtime_error("Invalid input! \n");
}

void MassSystem::getChoice(){
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
                throw std::runtime_error("Invalid input! \n");
            }

            std::cout << "You have chosen : " << user_choice << std::endl;
            validateChoice(user_choice, acceptable_Mass_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }   
    }
}

void MassSystem::startSystem(){
    printMenu(); 

    while(true){
        getChoice();
        
        if (user_choice == 0)
        {
            std::cout << "Returning to Main Menu !" << std::endl;
            break;
        }

        std::cout << "Please insert the value of the mass you want to convert: " << std::endl;
        std::cout << "Mass = ";
        mass = getMass();

        if (user_choice == 1)
        {
            kilograms_To(mass);
        }

        if (user_choice == 2)
        {
            grams_To(mass);
        }

        if (user_choice == 3)
        {
            milligrams_To(mass);
        }

        if (user_choice == 4)
        {
            pounds_To(mass);
        }

        if (user_choice == 5)
        {
            ounces_To(mass);
        }
    }
}

float MassSystem::getMass(){
    float mass;
    while (true)
    {
        try
        {
            std::cin >> mass;
            std::cout << '\n';

            //in case of missclick (bad state of cin)
            if(std::cin.fail() || std::cin.peek() != '\n'){
                std::cin.clear();       
                std::cin.ignore(1000, '\n');  
                throw std::runtime_error("Invalid input! \n");
            }

            return mass;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Please insert a valid value for the mass: " << std::endl;
            std::cout << "Mass = ";
        }   
    }
}

void MassSystem::kilograms_To(float mass){
    std::cout << "Mass in kilograms (kg): " << mass << " kg" << std::endl;

    std::cout << "In Grams (g): ";
    float grams = mass * 1000;
    std::cout << grams << " g \n";

    std::cout << "In Milligrams (mg): ";
    float milligrams = mass * 1000000;
    std::cout << milligrams << " mg \n";

    std::cout << "In Pounds (lb): ";
    float pounds = mass * 2.20462;
    std::cout << pounds << " lb \n";

    std::cout << "In Ounces (oz): ";
    float ounces = mass * 35.274;
    std::cout << ounces << " oz \n";
}


void MassSystem::grams_To(float mass){
    std::cout << "Mass in grams (g): " << mass << " g" << std::endl;

    std::cout << "In Kilograms (kg): ";
    float kilograms = mass / 1000;
    std::cout << kilograms << " kg \n";

    std::cout << "In Milligrams (mg): ";
    float milligrams = mass * 1000;
    std::cout << milligrams << " mg \n";

    std::cout << "In Pounds (lb): ";
    float pounds = mass * 0.00220462;
    std::cout << pounds << " lb \n";

    std::cout << "In Ounces (oz): ";
    float ounces = mass * 0.035274;
    std::cout << ounces << " oz \n";
}

void MassSystem::milligrams_To(float mass){
    std::cout << "Mass in milligrams (mg): " << mass << " mg" << std::endl;

    std::cout << "In Kilograms (kg): ";
    float kilograms = mass / 1000000;
    std::cout << kilograms << " kg \n";

    std::cout << "In Grams (g): ";
    float grams = mass / 1000;
    std::cout << grams << " g \n";

    std::cout << "In Pounds (lb): ";
    float pounds = mass * 0.00000220462;
    std::cout << pounds << " lb \n";

    std::cout << "In Ounces (oz): ";
    float ounces = mass * 0.000035274;
    std::cout << ounces << " oz \n";
}


void MassSystem::pounds_To(float mass){
    std::cout << "Mass in pounds (lb): " << mass << " lb" << std::endl;

    std::cout << "In Kilograms (kg): ";
    float kilograms = mass / 2.20462;
    std::cout << kilograms << " kg \n";

    std::cout << "In Grams (g): ";
    float grams = mass / 0.00220462;
    std::cout << grams << " g \n";

    std::cout << "In Milligrams (mg): ";
    float milligrams = mass / 0.00000220462;
    std::cout << milligrams << " mg \n";

    std::cout << "In Ounces (oz): ";
    float ounces = mass * 16;
    std::cout << ounces << " oz \n";
}

void MassSystem::ounces_To(float mass){
    std::cout << "Mass in ounces (oz): " << mass << " oz" << std::endl;

    std::cout << "In Kilograms (kg): ";
    float kilograms = mass / 35.274;
    std::cout << kilograms << " kg \n";

    std::cout << "In Grams (g): ";
    float grams = mass / 0.035274;
    std::cout << grams << " g \n";

    std::cout << "In Milligrams (mg): ";
    float milligrams = mass / 0.000035274;
    std::cout << milligrams << " mg \n";

    std::cout << "In Pounds (lb): ";
    float pounds = mass / 16;
    std::cout << pounds << " lb \n";
}
