#include "../include/SpeedSystem.h"

void SpeedSystem::printMenu() {
    std::cout << "-----------------------" << std::endl;
    std::cout << "Speed Conversion System" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printOptions();
}

void SpeedSystem::printOptions() {
    for (const auto &option : available_Speed_options) {
        std::cout << option.first << ") " << option.second << std::endl;
    }
}


void SpeedSystem::validateChoice(unsigned int user_choice, const std::vector<unsigned int> &acceptable_Speed_options) {
    for (auto option : acceptable_Speed_options) {
        if (user_choice == option) {
            return;
        }
    }
    throw std::runtime_error("Invalid input! \n");
}

void SpeedSystem::getChoice() {
    while(true){
        try
        {
            std::cout << "Choose : ";
            std::cin >> user_choice;
            std::cout << '\n';

            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw std::runtime_error("Invalid input! \n");
            }

            std::cout << "You have chosen : " << user_choice << std::endl;
            validateChoice(user_choice, acceptable_Speed_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }
    }
}

float SpeedSystem::getSpeed(float speed) {
    while(true){
        try
        {
            std::cin >> speed;
            std::cout << "\n";

            if (std::cin.fail() || std::cin.peek() != '\n') {
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
    return speed;
}


void SpeedSystem::startSystem(){
    printMenu();
    while(true){
        getChoice();

        if(user_choice == 0){
            std::cout << "Exiting Speed System ..." << std::endl;
            break;
        }

        std::cout << "Please insert the value of the speed you want to convert: " << std::endl;
        std::cout << "Speed = ";
        speed = getSpeed(speed);

        if (user_choice == 1){
            std::cout << "You have chosen Meters per Second (m/s)!" << std::endl;
            std::cout << "Please insert the value of the speed you want to convert: " << std::endl;
            std::cout << "Speed = ";
            speed = getSpeed(speed);
            metersPerSecond_To(speed);
        }
        if (user_choice == 2){
            std::cout << "You have chosen Kilometers per Hour (km/h)!" << std::endl;
            std::cout << "Please insert the value of the speed you want to convert: " << std::endl;
            std::cout << "Speed = ";
            speed = getSpeed(speed);
            kilometersPerHour_To(speed);
        }
        if (user_choice == 3){
            std::cout << "You have chosen Miles per Hour (mph)!" << std::endl;
            std::cout << "Please insert the value of the speed you want to convert: " << std::endl;
            std::cout << "Speed = ";
            speed = getSpeed(speed);
            milesPerHour_To(speed);
        }
        if (user_choice == 4){
            std::cout << "You have chosen Knots (kn)!" << std::endl;
            std::cout << "Please insert the value of the speed you want to convert: " << std::endl;
            std::cout << "Speed = ";
            speed = getSpeed(speed);
            knots_To(speed);
        }
        if (user_choice == 5){
            std::cout << "You have chosen Feet per Second (m/s)!" << std::endl;
            std::cout << "Please insert the value of the speed you want to convert: " << std::endl;
            std::cout << "Speed = ";
            speed = getSpeed(speed);
            feetPerSecond_To(speed);
        }
    }
}



void SpeedSystem::metersPerSecond_To(float speed){
    std::cout << "Speed in Meters per Second = " << speed << " (m/s) ! \n";

    std::cout << "To Kilometers per Hour = ";
    float speed_kmh = speed * 3.6;
    std::cout << " (km/h) ! \n";

    std::cout << "To Miles per Hour = ";
    float speed_mph = speed * 2.23694;
    std::cout << " (mph) ! \n";

    std::cout << "To Knots = ";
    float speed_kn = speed * 1.943844;
    std::cout << " (kn) ! \n";
    
    std::cout << "To Feet per Second = ";
    float speed_ftps = speed * 3.28084;
    std::cout << " (ft/s) ! \n";
}

void SpeedSystem::kilometersPerHour_To(float speed){
    std::cout << "Speed in Kilometers per Hour = " << speed << " (km/h) ! \n";

    std::cout << "To Meters per Second = ";
    float speed_ms = speed / 3.6 ;
    std::cout << " (m/s) ! \n";

    std::cout << "To Miles per Hour = ";
    float speed_mph = speed_ms * 2.23694;
    std::cout << " (mph) ! \n";

    std::cout << "To Knots = ";
    float speed_kn = speed_ms * 1.943844;
    std::cout << " (kn) ! \n";
    
    std::cout << "To Feet per Second = ";
    float speed_ftps = speed_ms * 3.28084;
    std::cout << " (ft/s) ! \n";
}


void SpeedSystem::milesPerHour_To(float speed){
    std::cout << "Speed in Miles per Hour = " << speed << " (mph) ! \n";

    std::cout << "To Meters per Second = ";
    float speed_ms = speed * 0.44704;
    std::cout << " (km/h) ! \n";

    std::cout << "To Kilometers per Hour = ";
    float speed_kmh = speed_ms * 3.6;
    std::cout << " (mph) ! \n";

    std::cout << "To Knots = ";
    float speed_kn = speed_ms * 1.943844;
    std::cout << " (kn) ! \n";
    
    std::cout << "To Feet per Second = ";
    float speed_ftps = speed_ms * 3.28084;
    std::cout << " (ft/s) ! \n";
}

void SpeedSystem::knots_To(float speed){
    std::cout << " Speed in Knots = " << speed << " (kn) ! \n";

    std::cout << " To Meters per Second = ";
    float speed_ms = speed / 1.943844;
    std::cout << " (m/s) ! \n";

    std::cout << " To Kilometers per Hour = ";
    float speed_kmh = speed_ms * 3.6;
    std::cout << " (km/h) ! \n";

    std::cout << " To Miles per Hour = ";
    float speed_mph = speed_ms * 2.23694;
    std::cout << " (mph) ! \n";

    std::cout << "To Feet per Second = ";
    float speed_ftps = speed_ms * 3.28084;
    std::cout << " (ft/s) ! \n"; 
}

void SpeedSystem::feetPerSecond_To(float speed){
    std::cout << " Speed in Feet per Second = " << speed << "(ft/s) ! \n";

    std::cout << " To Meters per Second = ";
    float speed_ms = speed * 0.3048;
    std::cout << " (m/s) ! \n";

    std::cout << " To Kilometers per Hour = ";
    float speed_kmh = speed_ms * 3.6;
    std::cout << " (km/h) ! \n";

    std::cout << " To Miles per Hour = ";
    float speed_mph = speed_ms * 2.23694;
    std::cout << " (mph) ! \n";

    std::cout << "To Knots = ";
    float speed_kn = speed_ms * 1.943844;
    std::cout << " (kn) ! \n";
}