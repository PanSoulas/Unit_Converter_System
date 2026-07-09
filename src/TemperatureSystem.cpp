#include "../include/TemperatureSystem.h"

void TemperatureSystem::printOptions(){
    for(auto option : temperature_options){
        std::cout << option.first << ") " << option.second << std::endl;
    }
}

void TemperatureSystem::printMenu(){
    std::cout << "-------------------- \n";
    std::cout << " Temperature System  \n";
    std::cout << "-------------------- \n";
    std::cout << "Here are the S.I. measurement units for Temperature ! " << std::endl;

    printOptions();
}



void TemperatureSystem::validate_User_Choice(int user_choice, const std::vector<int> &acceptable_temperature_options){
    for (auto option : acceptable_temperature_options)
    {
        if(user_choice == option){
            return ;
        }
    }
    throw std::runtime_error("Invalid input! Please choose between the following: \n");
}


void TemperatureSystem::getChoice(){
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
                throw std::runtime_error("Invalid input!");
            }

            std::cout << "You have chosen : " << user_choice << std::endl;
            validate_User_Choice(user_choice, acceptable_temperature_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }   
    }
}

float TemperatureSystem::getTemperature(){
    while (true)
    {
        try
        {
            std::cin >> temperature;
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

    return temperature;
}

void TemperatureSystem::startSystem(){
    printMenu();    
    while(true){
        getChoice();
        
        if (user_choice == 0)
        {
            std::cout << "Returning to Main Menu !" << std::endl;
            break;
        }

        
        if (user_choice == 1)
        {
            std::cout << "You have chosen Celsius for conversion ! " << std::endl;
            std::cout << "Please insert the value of the temperature you want to convert: " << std::endl;
            std::cout << "Temperature = ";
            temperature = getTemperature();
            celsius_To(temperature);
        }

        if (user_choice == 2)
        {
            std::cout << "You have chosen Fahrenheit for conversion ! " << std::endl;
            std::cout << "Please insert the value of the temperature you want to convert: " << std::endl;
            std::cout << "Temperature = ";
            temperature = getTemperature();
            fahrenheit_To(temperature);
        }
        
        if (user_choice == 3)
        {
            std::cout << "You have chosen Kelvin for conversion ! " << std::endl;
            std::cout << "Please insert the value of the temperature you want to convert: " << std::endl;
            std::cout << "Temperature = ";
            temperature = getTemperature();
            kelvin_To(temperature);
        }

        if (user_choice == 4)
        {
            std::cout << "You have chosen Rankine for conversion ! " << std::endl;
            std::cout << "Please insert the value of the temperature you want to convert: " << std::endl;
            std::cout << "Temperature = ";
            temperature = getTemperature();
            rankine_To(temperature);
        }
    }
}


void TemperatureSystem::celsius_To(float temperature){
    std::cout << "User's temperature for measurement is : " << temperature << " Celsius (\u00B0C)" << std::endl;

    std::cout << "In Fahrenheit (\u00B0F): ";
    float fahrenheit = (temperature * 1.8) + 32.0;
    std::cout << fahrenheit << " \u00B0F" << std::endl; 

    std::cout << "In Kelvin (K): " ;
    float kelvin = temperature + 273.15;
    std::cout << kelvin << " K" << std::endl;

    std::cout << "In Rankine (R) : ";
    float rankine = fahrenheit + 459.67;
    std::cout << rankine << " R " << std::endl;
}


void TemperatureSystem::fahrenheit_To(float temperature){
    std::cout << "User's temperature for measurement is : " << temperature << " Fahrenheit (\u00B0F)" << std::endl;;

    std::cout << "In Celsius (\u00B0C): ";
    float celsius = (temperature - 32.0) / 1.8;
    std::cout << celsius << " \u00B0C" << std::endl; 

    std::cout << "In Kelvin (K): " ;
    float kelvin = ((temperature - 32) / 1.8) + 273.15;
    std::cout << kelvin << " K" << std::endl;

    std::cout << "In Rankine (R) : ";
    float rankine = temperature + 459.67;
    std::cout << rankine << " R " << std::endl;
}


void TemperatureSystem::kelvin_To(float temperature){
    std::cout << "User's temperature for measurement is : " << temperature << " Kelvin (K)" << std::endl;

    std::cout << "In Celsius (\u00B0C): ";
    float celsius = temperature - 273.15;
    std::cout << celsius << " \u00B0C" << std::endl;

    std::cout << "In Fahrenheit (\u00B0F): ";
    float fahrenheit = ((temperature - 273.15) * 1.8) + 32.0;
    std::cout << fahrenheit << " \u00B0F" << std::endl;

    std::cout << "In Rankine (R): ";
    float rankine = 1.8 * temperature;
    std::cout << rankine << " R" << std::endl;
}

void TemperatureSystem::rankine_To(float temperature){
    std::cout << "User's temperature for measurement is : " << temperature << " Rankine (R)" << std::endl;

    std::cout << "In Celsius (\u00B0C): ";
    float celsius = (temperature - 491.67) / 1.8;
    std::cout << celsius << " \u00B0C" << std::endl;

    std::cout << "In Fahrenheit (\u00B0F): ";
    float fahrenheit = temperature - 459.67;
    std::cout << fahrenheit << " \u00B0F" << std::endl;

    std::cout << "In Kelvin (K): " ;
    float kelvin = temperature / 1.8;
    std::cout << kelvin << " K" << std::endl;
}