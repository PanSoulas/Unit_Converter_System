#include "../include/FrequencySystem.h"
#include <cmath>

void FrequencySystem::printMenu(){
    std::cout << "----------------------------" << std::endl;
    std::cout << "Frequency Conversion System" << std::endl;
    std::cout << "----------------------------" << std::endl;
    printOptions();
}

void FrequencySystem::printOptions(){
    for (auto option : available_Frequency_options)
    {
        std::cout << option.first << ") " << option.second << std::endl;
    }
}


void FrequencySystem::validateChoice(int user_choice, const std::vector<int> &acceptable_Frequency_options){
    for (auto option : acceptable_Frequency_options) {
        if (user_choice == option) {
            return;
        }
    }
    throw std::runtime_error("Invalid input! \n");
}

void FrequencySystem::getChoice() {
    while(true){
        try
        {
            std::cout << "Choose : ";
            std::cin >> user_choice;
            std::cout << '\n';

            if (std::cin.fail() || std::cin.peek() != '\n' || user_choice < 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw std::runtime_error("Invalid input! \n");
            }

            std::cout << "You have chosen : " << user_choice << std::endl;
            validateChoice(user_choice, acceptable_Frequency_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }
    }
}

float FrequencySystem::getFrequency(float frequency){
    while(true){
        try
        {
            std::cin >> frequency;
            std::cout << "\n";

            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw std::runtime_error("Invalid input! Please enter a number : \n");
            }
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Please enter a valid number: \n";
            std::cout << "Frequency = ";
        }
    }
    return frequency;
}

void FrequencySystem::startSystem(){
    printMenu();
    while(true){
        getChoice();

        if (user_choice == 0){
            std::cout << "Exiting Frequency System ..." << std::endl;
            break;
        }

        if (user_choice == 1)
        {
            std::cout << "You have chosen Hertz (Hz)!" << std::endl;
            std::cout << "Please insert the value of the frequency you want to convert: " << std::endl;
            std::cout << "Frequency = ";
            frequency = getFrequency(frequency);
            hertz_To(frequency);
        }

        if (user_choice == 2)
        {
            std::cout << "You have chosen Kilohertz (kHz)!" << std::endl;
            std::cout << "Please insert the value of the frequency you want to convert: " << std::endl;
            std::cout << "Frequency = ";
            frequency = getFrequency(frequency);
            kilohertz_To(frequency);
        }

        if (user_choice == 3)
        {
            std::cout << "You have chosen Megahertz (MHz)!" << std::endl;
            std::cout << "Please insert the value of the frequency you want to convert: " << std::endl;
            std::cout << "Frequency = ";
            frequency = getFrequency(frequency);
            megahertz_To(frequency);
        }

        if (user_choice == 4)
        {
            std::cout << "You have chosen Gigahertz (GHz)!" << std::endl;
            std::cout << "Please insert the value of the frequency you want to convert: " << std::endl;
            std::cout << "Frequency = ";
            frequency = getFrequency(frequency);
            gigahertz_To(frequency);
        }

        if (user_choice == 5)
        {
            std::cout << "You have chosen Revolutions per Minute (RPM)!" << std::endl;
            std::cout << "Please insert the value of the frequency you want to convert: " << std::endl;
            std::cout << "Frequency = ";
            frequency = getFrequency(frequency);
            revolutions_per_minute_To(frequency);
        }
        std::cout << "\n";
        std::cout << "Would you like to continue ? \n";
        std::cout << "Please choose between the following! \n";
        printOptions();
    }
}



void FrequencySystem::hertz_To(float frequency){
    std::cout << "Frequency in Hertz = " << frequency << "(Hz) \n";

    std::cout << "To Kilohertz = ";
    float frequency_kHz = frequency / 1000;
    std::cout << frequency_kHz << "(kHz) \n";

    std::cout << "To Megahertz = ";
    float frequency_MHz = frequency / pow(10, 6);
    std::cout << frequency_MHz << "(MHz) \n";

    std::cout << "To Gigahertz = ";
    float frequency_GHz = frequency / pow(10, 9);
    std::cout << frequency_GHz << "(GHz) \n";

    std::cout << "To Revolutions per Minute = ";
    float frequency_RPM = frequency * 60;
    std::cout << frequency_RPM << "(RPM) \n";
}

void FrequencySystem::kilohertz_To(float frequency){
    std::cout << "Frequency in Kilohertz = " << frequency << "(kHz) \n";

    std::cout << "To Hertz = ";
    float frequency_Hz = frequency * 1000;
    std::cout << frequency_Hz << "(Hz) \n";

    std::cout << "To Megahertz = ";
    float frequency_MHz = frequency_Hz / pow(10, 6);
    std::cout << frequency_MHz << "(MHz) \n";

    std::cout << "To Gigahertz = ";
    float frequency_GHz = frequency_Hz / pow(10, 9);
    std::cout << frequency_GHz << "(GHz) \n";

    std::cout << "To Revolutions per Minute = ";
    float frequency_RPM = frequency_Hz * 60;
    std::cout << frequency_RPM << "(RPM) \n";
}
void FrequencySystem::megahertz_To(float frequency){
    std::cout << "Frequency in Megahertz = " << frequency << "(MHz) \n";

    std::cout << "To Hertz = ";
    float frequency_Hz = frequency * pow(10, 6);
    std::cout << frequency_Hz << "(Hz) \n";

    std::cout << "To Kilohertz = ";
    float frequency_kHz = frequency_Hz / pow(10, 3);
    std::cout << frequency_kHz << "(kHz) \n";

    std::cout << "To Gigahertz = ";
    float frequency_GHz = frequency_Hz / pow(10, 9);
    std::cout << frequency_GHz << "(GHz) \n";

    std::cout << "To Revolutions per Minute = ";
    float frequency_RPM = frequency_Hz * 60;
    std::cout << frequency_RPM << "(RPM) \n";
}
void FrequencySystem::gigahertz_To(float frequency){
    std::cout << "Frequency in Gigahertz = " << frequency << "(GHz) \n";

    std::cout << "To Hertz = ";
    float frequency_Hz = frequency * pow(10, 9);
    std::cout << frequency_Hz << "(Hz) \n";

    std::cout << "To Kilohertz = ";
    float frequency_kHz = frequency_Hz / pow(10, 3);
    std::cout << frequency_kHz << "(GHz) \n";

    std::cout << "To Megahertz = ";
    float frequency_MHz = frequency_Hz / pow(10, 6);
    std::cout << frequency_MHz << "(MHz) \n";

    std::cout << "To Revolutions per Minute = ";
    float frequency_RPM = frequency_Hz * 60;
    std::cout << frequency_RPM << "(RPM) \n";
}
void FrequencySystem::revolutions_per_minute_To(float frequency){
    std::cout << "Frequency in Revolutions per Minute = " << frequency << "(RPM) \n";

    std::cout << "To Hertz = ";
    float frequency_Hz = frequency / 60;
    std::cout << frequency_Hz << "(Hz) \n";

    std::cout << "To Kilohertz = ";
    float frequency_kHz = frequency_Hz / 1000;
    std::cout << frequency_kHz << "(RPM) \n";
    
    std::cout << "To Megahertz = ";
    float frequency_MHz = frequency_Hz / pow(10, 6);
    std::cout << frequency_MHz << "(MHz) \n";

    std::cout << "To Gigahertz = ";
    float frequency_GHz = frequency_Hz / pow(10, 9);
    std::cout << frequency_GHz << "(GHz) \n";
}