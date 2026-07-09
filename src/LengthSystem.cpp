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


void LengthSystem::validateChoice(int user_choice, const std::vector<int> &acceptable_Length_options){
    for (auto option : acceptable_Length_options)
    {
        if(user_choice == option){
            return ;
        }
    }
    throw std::runtime_error("Invalid input! \n");
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
            if(std::cin.fail() || std::cin.peek() != '\n' || user_choice < 0){
                std::cin.clear();       
                std::cin.ignore(1000, '\n');  
                throw std::runtime_error("Invalid input! \n");
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

            //In case of invalid input (example length = 1/2)
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
        
        if (user_choice == 1)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            meters_To(length);
        }

        if (user_choice == 2)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            kilometers_To(length);
        }
        
        if (user_choice == 3)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            centimeters_To(length);
        }

        if (user_choice == 4)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            millimeters_To(length);
        }

        if (user_choice == 5)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            mile_To(length);
        }

        if (user_choice == 6)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            feet_To(length);
        }
        
        if (user_choice == 7)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            inches_To(length);
        }

        if (user_choice == 8)
        {
            std::cout << "Please insert the value of the length you want to convert: " << std::endl;
            std::cout << "Length = ";
            length = getLength();
            yards_To(length);
        }        
    }
}


void LengthSystem::meters_To(float length){
    std::cout << "Length in meters (m): " << length << " m" << std::endl;

    std::cout << "In Kilometers (km): ";
    float kilometers = length / 1000;
    std::cout << kilometers << " km \n";

    std::cout << "In Centimeters (cm): ";
    float centimeters = length * 100;
    std::cout << centimeters << " cm \n";

    std::cout << "In Millimeters (mm): ";
    float millimeters = length * 1000;
    std::cout << millimeters << " mm \n";

    std::cout << "In Miles: ";
    float miles = length * 0.00062137;
    std::cout << miles << " miles \n";

    std::cout << "In feet: ";
    float feet = length * 3.28084;
    std::cout << feet << " ft \n";

    std::cout << "In inches: ";
    float inches = length * 39.3701;
    std::cout << inches << " in \n";

    std::cout << "In yards: ";
    float yards = length * 1.09361;
    std::cout << yards << " yd \n";
}

void LengthSystem::kilometers_To(float length){
    std::cout << "Length in kilometers (km): " << length << " km" << std::endl;

    std::cout << "In Meters (m): ";
    float meters = length * 1000;
    std::cout << meters << " m \n";

    std::cout << "In Centimeters (cm): ";
    float centimeters = meters * 100;
    std::cout << centimeters << " cm \n";

    std::cout << "In Millimeters (mm): ";
    float millimeters = meters * 1000;
    std::cout << millimeters << " mm \n";

    std::cout << "In Miles (mi): ";
    float miles = meters * 0.00062137;
    std::cout << miles << " mi \n";

    std::cout << "In feet (ft): ";
    float feet = meters * 3.28084;
    std::cout << feet << " ft \n";

    std::cout << "In inches (in): ";
    float inches = meters * 39.3701;
    std::cout << inches << " in \n";

    std::cout << "In yards (yd): ";
    float yards = meters * 1.09361;
    std::cout << yards << " yd \n";
}


void LengthSystem::centimeters_To(float length){
    std::cout << "Length in centimeters (cm): " << length << " cm" << std::endl;

    std::cout << "In Meters (m): ";
    float meters = length / 100;
    std::cout << meters << " m \n";

    std::cout << "In Kilometers (km): ";
    float kilometers = meters / 1000;
    std::cout << kilometers << " km \n";

    std::cout << "In Millimeters (mm): ";
    float millimeters = meters * 1000;
    std::cout << millimeters << " mm \n";

    std::cout << "In Miles: ";
    float miles = meters * 0.00062137;
    std::cout << miles << " miles \n";

    std::cout << "In feet: ";
    float feet = meters * 3.28084;
    std::cout << feet << " ft \n";

    std::cout << "In inches: ";
    float inches = meters * 39.3701;
    std::cout << inches << " in \n";

    std::cout << "In yards: ";
    float yards = meters * 1.09361;
    std::cout << yards << " yd \n";
}

void LengthSystem::millimeters_To(float length){
    std::cout << "Length in millimeters (mm): " << length << " mm" << std::endl;

    std::cout << "In Meters (m): ";
    float meters = length / 1000;
    std::cout << meters << " m \n";

    std::cout << "In Kilometers (km): ";
    float kilometers = meters / 1000;
    std::cout << kilometers << " km \n";

    std::cout << "In Centimeters (cm): ";
    float centimeters = meters * 100;
    std::cout << centimeters << " cm \n";

    std::cout << "In Miles (mi): ";
    float miles = meters * 0.00062137;
    std::cout << miles << " miles \n";

    std::cout << "In feet (ft): ";
    float feet = meters * 3.28084;
    std::cout << feet << " ft \n";

    std::cout << "In inches (in): ";
    float inches = meters * 39.3701;
    std::cout << inches << " in \n";

    std::cout << "In yards (yd): ";
    float yards = meters * 1.09361;
    std::cout << yards << " yd \n";
}


void LengthSystem::mile_To(float length){
    std::cout << "Length in miles: " << length << " miles" << std::endl;

    std::cout << "In Meters (m): ";
    float meters = length / 0.00062137;
    std::cout << meters << " m \n";

    std::cout << "In Kilometers (km): ";
    float kilometers = meters / 1000;
    std::cout << kilometers << " km \n";

    std::cout << "In Centimeters (cm): ";
    float centimeters = meters * 100;
    std::cout << centimeters << " cm \n";

    std::cout << "In Millimeters (mm): ";
    float millimeters = meters * 1000;
    std::cout << millimeters << " mm \n";

    std::cout << "In feet: ";
    float feet = meters * 3.28084;
    std::cout << feet << " ft \n";
    
    std::cout << "In inches: ";
    float inches = meters * 39.3701;
    std::cout << inches << " in \n";
    
    std::cout << "In yards: ";
    float yards = meters * 1.09361;
    std::cout << yards << " yd \n";
    
}

void LengthSystem::feet_To(float length){
    std::cout << "Length in feet: " << length << " ft" << std::endl;
    
    std::cout << "In Meters (m): ";
    float meters = length / 3.28084;
    std::cout << meters << " m \n";

    std::cout << "In Kilometers (km): ";
    float kilometers = meters / 1000;
    std::cout << kilometers << " km \n";
    
    std::cout << "In Centimeters (cm): ";
    float centimeters = meters * 100;
    std::cout << centimeters << " cm \n";
    
    std::cout << "In Millimeters (mm): ";
    float millimeters = centimeters * 10;
    std::cout << millimeters << " mm \n";
    
    std::cout << "In Miles: ";
    float miles = meters / 1609.34;
    std::cout << miles << " miles \n";
    
    std::cout << "In inches: ";
    float inches = meters * 39.3701;
    std::cout << inches << " in \n";
    
    std::cout << "In yards: ";
    float yards = meters * 1.09361;
    std::cout << yards << " yd \n";
}
    
void LengthSystem::inches_To(float length){
    std::cout << "Length in inches: " << length << " in" << std::endl;
    
    std::cout << "In Meters (m): ";
    float meters = length / 39.3701;
    std::cout << meters << " m \n";
    
    std::cout << "In Kilometers (km): ";
    float kilometers = meters / 1000;
    std::cout << kilometers << " km \n";

    std::cout << "In Centimeters (cm): ";
    float centimeters = meters * 100;
    std::cout << centimeters << " cm \n";

    std::cout << "In Millimeters (mm): ";
    float millimeters = centimeters * 10;
    std::cout << millimeters << " mm \n";

    std::cout << "In Miles: ";
    float miles = meters / 1609.34;
    std::cout << miles << " miles \n";

    std::cout << "In feet: ";
    float feet = meters * 3.28084;
    std::cout << feet << " ft \n";

    std::cout << "In yards: ";
    float yards = meters * 1.09361;
    std::cout << yards << " yd \n";
}

void LengthSystem::yards_To(float length){
    std::cout << "Length in yards: " << length << " yd" << std::endl;
    
    std::cout << "In Meters (m): ";
    float meters = length / 1.09361;
    std::cout << meters << " m \n";
    
    std::cout << "In Kilometers (km): ";
    float kilometers = meters / 1000;
    std::cout << kilometers << " km \n";
    
    std::cout << "In Centimeters (cm): ";
    float centimeters = meters * 100;
    std::cout << centimeters << " cm \n";
    
    std::cout << "In Millimeters (mm): ";
    float millimeters = centimeters * 10;
    std::cout << millimeters << " mm \n";
    
    std::cout << "In Miles: ";
    float miles = meters / 1609.34;
    std::cout << miles << " miles \n";
    
    std::cout << "In feet: ";
    float feet = meters * 3.28084;
    std::cout << feet << " ft \n";
    
    std::cout << "In inches: ";
    float inches = feet * 12;
    std::cout << inches << " in \n";
}
