#include "../include/AngleSystem.h"
#include <cmath>

void AngleSystem::printMenu(){
    std::cout << "=====================" << std::endl;
    std::cout << "    Angle System      " << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "\n";

    printOptions();
}

void AngleSystem::printOptions(){
    std::cout << "Here are the S.I. measurement units for Angle ! \n";
    for (auto option:available_Angle_options)
    {
        std::cout << option.first << ") " << option.second << std::endl; 
    }
}

void AngleSystem::validateChoice(int user_choice, const std::vector<int> &acceptable_Angle_options){
    for (auto option : acceptable_Angle_options)
    {
        if(user_choice == option){
            return ;
        }
    }
    throw std::runtime_error("Invalid input! \n");
}

void AngleSystem::getChoice(){
    while (true)
    {
        try
        {
            std::cout << "Choose : " ;
            std::cin >> user_choice;
            std::cout << '\n';

            //in case of missclick (bad state of cin)
            if(std::cin.fail() || std::cin.peek() != '\n' || user_choice < 0){
                std::cin.clear();       
                std::cin.ignore(1000, '\n');  
                throw std::runtime_error("Invalid input! \n");
            }

            std::cout << "You have chosen : " << user_choice << std::endl;
            validateChoice(user_choice, acceptable_Angle_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }   
    }
}

float AngleSystem::getAngle(){
    while (true)
    {
        try
        {
            std::cin >> angle;
            std::cout << "\n";

            //In case of invalid input (example angle = 1/2)
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

    return angle;
}

void AngleSystem::startSystem(){
    printMenu();
    while (true)
    {
        getChoice();

        if (user_choice == 0)
        {
            std::cout << "Exiting the Angle System..." << std::endl;
            break;
        }

        if (user_choice == 1)
        {
            std::cout << "Please insert the value of the angle you want to convert: " << std::endl;
            std::cout << "Angle = ";
            angle = getAngle();
            degrees_To(angle);
        }

        if (user_choice == 2)
        {
            std::cout << "Please insert the value of the angle you want to convert: " << std::endl;
            std::cout << "Angle = ";
            angle = getAngle();
            radians_To(angle);
        }
        
        if (user_choice == 3)
        {
            std::cout << "Please insert the value of the angle you want to convert: " << std::endl;
            std::cout << "Angle = ";
            angle = getAngle();
            gradians_To(angle);
        }
    }
}

void AngleSystem::degrees_To(float angle){
    std::cout << "Angle in Degrees (°): " << angle << " °" << std::endl;

    std::cout << "In Radians (rad): ";
    float radians = angle * (M_PI / 180.0);
    std::cout << radians << " rad \n";

    std::cout << "In Gradians (gon): ";
    float gradians = angle * (10.0 / 9.0);
    std::cout << gradians << " gon \n";
}

void AngleSystem::radians_To(float angle){
    std::cout << "Angle in Radians (rad): " << angle << " rad" << std::endl;

    std::cout << "In Degrees (°): ";
    float degrees = angle * (180.0 / M_PI);
    std::cout << degrees << " ° \n";

    std::cout << "In Gradians (gon): ";
    float gradians = angle * (200.0 / M_PI);
    std::cout << gradians << " gon \n";
}

void AngleSystem::gradians_To(float angle){
    std::cout << "Angle in Gradians (gon): " << angle << " gon" << std::endl;

    std::cout << "In Degrees (°): ";
    float degrees = angle * (9.0 / 10.0);
    std::cout << degrees << " ° \n";

    std::cout << "In Radians (rad): ";
    float radians = angle * (M_PI / 200.0);
    std::cout << radians << " rad \n";
}