#include "../include/EnergySystem.h"
#include <cmath>

void EnergySystem::printMenu() {
    std::cout << "-----------------------" << std::endl;
    std::cout << "Energy Conversion System" << std::endl;
    std::cout << "-----------------------" << std::endl;
    printOptions();
}

void EnergySystem::printOptions() {
    for (const auto option : available_Energy_options) {
        std::cout << option.first << ") " << option.second << std::endl;
    }
}


void EnergySystem::validateChoice(int user_choice, const std::vector<int> &acceptable_Energy_options) {
    for (auto option : acceptable_Energy_options) {
        if (user_choice == option) {
            return;
        }
    }
    throw std::runtime_error("Invalid input! \n");
}

void EnergySystem::getChoice() {
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
            validateChoice(user_choice, acceptable_Energy_options);
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            printOptions();
        }
    }
}

float EnergySystem::getEnergy(float energy){
    while(true){
        try
        {
            std::cin >> energy;
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
            std::cout << "Energy = ";
        }
    }
    return energy;
}

void EnergySystem::startSystem(){
    printMenu();
    while(true){
        getChoice();

        if (user_choice == 0){
            std::cout << "Exiting Energy System ..." << std::endl;
            break;
        }

        if (user_choice == 1)
        {
            std::cout << "You have chosen Joules (J)!" << std::endl;
            std::cout << "Please insert the value of the energy you want to convert: " << std::endl;
            std::cout << "Energy = ";
            energy = getEnergy(energy);
            joules_To(energy);
        }

        if (user_choice == 2)
        {
            std::cout << "You have chosen Kilojoules (kJ)!" << std::endl;
            std::cout << "Please insert the value of the energy you want to convert: " << std::endl;
            std::cout << "Energy = ";
            energy = getEnergy(energy);
            kilojoules_To(energy);
        }

        if (user_choice == 3)
        {
            std::cout << "You have chosen Calories (cal)!" << std::endl;
            std::cout << "Please insert the value of the energy you want to convert: " << std::endl;
            std::cout << "Energy = ";
            energy = getEnergy(energy);
            calories_To(energy);
        }

        if (user_choice == 4)
        {
            std::cout << "You have chosen Kilocalories (kcal)!" << std::endl;
            std::cout << "Please insert the value of the energy you want to convert: " << std::endl;
            std::cout << "Energy = ";
            energy = getEnergy(energy);
            kilocalories_To(energy);
        }
        
        if (user_choice == 5)
        {
            std::cout << "You have chosen Electon Volts (eV)!" << std::endl;
            std::cout << "Please insert the value of the energy you want to convert: " << std::endl;
            std::cout << "Energy = ";
            energy = getEnergy(energy);
            electrovolts_To(energy);
        }
        
        if (user_choice == 6)
        {
            std::cout << "You have chosen Watt-hours (Wh)!" << std::endl;
            std::cout << "Please insert the value of the energy you want to convert: " << std::endl;
            std::cout << "Energy = ";
            energy = getEnergy(energy);
            wattHours_To(energy);
        }
        
        std::cout << "\n";
        std::cout << "Would you like to continue ? \n";
        std::cout << "Please choose between the following! \n";
        printOptions();
    }
}

void EnergySystem::joules_To(float energy){
    std::cout << "Energy in Joules = " << energy << "(J) \n";

    std::cout << "To Kilojoules = ";
    float energy_kJ = energy / 1000 ;
    std::cout << energy_kJ << "(kJ) \n";

    std::cout << "To Calories = ";
    float energy_cal = energy * 0.2390057361;
    std::cout << energy_cal << "(cal) \n";

    std::cout << "To Kilocalories = ";
    float energy_kcal = energy_cal / 1000;
    std::cout << energy_kcal << "(kcal) \n";

    std::cout << "To Electron Volts = ";
    float energy_eV = energy * 6.231509 * pow(10, 18);
    std::cout << energy_eV << "(eV) \n";

    std::cout << "To Watt-hours = ";
    float energy_Wh = energy * 0.0002777778;
    std::cout << energy_Wh << "(Wh) \n";
}

void EnergySystem::kilojoules_To(float energy){
    std::cout << "Energy in Kilojoules = " << energy << "(kJ) \n";

    std::cout << "To Joules = ";
    float energy_j = energy * 1000;
    std::cout << energy_j << "(J) \n";

    std::cout << "To Calories = ";
    float energy_cal = energy_j * 0.2390057361;
    std::cout << energy_cal << "(cal) \n";

    std::cout << "To Kilocalories = ";
    float energy_kcal = energy_cal / 1000;
    std::cout << energy_kcal << "(kcal) \n";

    std::cout << "To Electron Volts = ";
    float energy_eV = energy_j * 6.231509 * pow(10, 18);
    std::cout << energy_eV << "(eV) \n";

    std::cout << "To Watt-hours = ";
    float energy_Wh = energy_j * 0.0002777778;
    std::cout << energy_Wh << "(Wh) \n";
}

void EnergySystem::calories_To(float energy){
    std::cout << "Energy in Calories = " << energy << "(cal) \n";
    
    std::cout << "To Joules = ";
    float energy_j = energy * 4.184;
    std::cout << energy_j << "(J) \n";

    std::cout << "To Kilojoules = ";
    float energy_kJ = energy_j / 1000 ;
    std::cout << energy_kJ << "(kJ) \n";

    std::cout << "To Kilocalories = ";
    float energy_kcal = energy / 1000;
    std::cout << energy_kcal << "(kcal) \n";

    std::cout << "To Electron Volts = ";
    float energy_eV = energy_j * 6.231509 * pow(10, 18);
    std::cout << energy_eV << "(eV) \n";

    std::cout << "To Watt-hours = ";
    float energy_Wh = energy_j * 0.0002777778;
    std::cout << energy_Wh << "(Wh) \n";
}

void EnergySystem::kilocalories_To(float energy){
    std::cout << "Energy in Kilocalories = " << energy << "(kcal) \n";

    std::cout << "To Calories = ";
    float energy_cal = energy * 1000;
    std::cout << energy_cal << "(cal) \n";

    std::cout << "To Joules = ";
    float energy_j = energy_cal * 4.184;
    std::cout << energy_j << "(J) \n";

    std::cout << "To Kilojoules = ";
    float energy_kj = energy_j / 1000;
    std::cout << energy_kj << "(kJ) \n";

    std::cout << "To Electron Volts = ";
    float energy_eV = energy_j * 6.231509 * pow(10, 18);
    std::cout << energy_eV << "(eV) \n";

    std::cout << "To Watt-hours = ";
    float energy_Wh = energy_j * 0.0002777778;
    std::cout << energy_Wh << "(Wh) \n";
}

void EnergySystem::electrovolts_To(float energy){
    std::cout << "Energy in Electron Volts = " << energy << "(eV) \n";

    std::cout << "To Joules = ";
    float energy_j = energy * 1.602177 * pow(10, -19);
    std::cout << energy_j << "(J) \n";

    std::cout << "To Kilojoules = ";
    float energy_kj = energy_j / 1000;
    std::cout << energy_kj << "(kJ) \n";

    std::cout << "To Calories = ";
    float energy_cal = energy_j * 0.2390057361;
    std::cout << energy_cal << "(cal) \n";

    std::cout << "To Kilocalories = ";
    float energy_kcal = energy_cal / 1000;
    std::cout << energy_kcal << "(kcal) \n";

    std::cout << "To Watt-hours = ";
    float energy_Wh = energy_j * 0.0002777778;
    std::cout << energy_Wh << "(Wh) \n";
}

void EnergySystem::wattHours_To(float energy){
    std::cout << "Energy in Watt-hours = " << energy << "(Wh) \n";

    std::cout << "To Joules = ";
    float energy_j = energy * 3600;
    std::cout << energy_j << "(J) \n";

    std::cout << "To Kilojoules = ";
    float energy_kj = energy_j / 1000;
    std::cout << energy_kj << "(kJ) \n";

    std::cout << "To Calories = ";
    float energy_cal = energy_j * 0.2390057361;
    std::cout << energy_cal << "(cal) \n";

    std::cout << "To Kilocalories = ";
    float energy_kcal = energy_cal / 1000;
    std::cout << energy_kcal << "(kcal) \n";

    std::cout << "To Electron Volts = ";
    float energy_eV = energy_j * 6.231509 * pow(10, 18);
    std::cout << energy_eV << "(eV) \n";
}