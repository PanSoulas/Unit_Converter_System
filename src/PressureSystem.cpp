#include "../include/PressureSystem.h"

void PressureSystem::printMenu() {
    std::cout << "=====================" << std::endl;
    std::cout << "    Pressure System   " << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "\n";

    printOptions();
}

void PressureSystem::printOptions() {
    std::cout << "Here are the S.I. measurement units for Pressure ! \n";
    for (auto option : available_Pressure_options) {
        std::cout << option.first << ") " << option.second << std::endl;
    }
}

void PressureSystem::validateChoice(unsigned int user_choice, const std::vector<unsigned int> &acceptable_Pressure_options) {
    for (auto option : acceptable_Pressure_options) {
        if (user_choice == option) {
            return;
        }
    }
    throw std::runtime_error("Invalid input! \n");
}

void PressureSystem::getChoice() {
    while (true) {
        try {
            std::cout << "Choose : ";
            std::cin >> user_choice;
            std::cout << '\n';

            //in case of missclick (bad state of cin)
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw std::runtime_error("Invalid input! \n");
            }

            std::cout << "You have chosen : " << user_choice << std::endl;
            validateChoice(user_choice, acceptable_Pressure_options);
            break;
        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
            printOptions();
        }
    }
}

float PressureSystem::getPressure() {
    while (true) {
        try {
            std::cin >> pressure;
            std::cout << "\n";

            //In case of invalid input (example pressure = 1/2)
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw std::runtime_error("Invalid input! Please enter a number that is acceptable with the following options: \n");
            }
            break;
        } catch (const std::exception &e) {
            std::cerr << e.what() << '\n';
            printOptions();
        }
    }

    return pressure;
}

void PressureSystem::startSystem() {
    printMenu();
    while (true) {
        getChoice();

        if (user_choice == 0) {
            std::cout << "Exiting the Pressure System..." << std::endl;
            break;
        }

        std::cout << "Please insert the value of the pressure you want to convert: " << std::endl;
        std::cout << "Pressure = ";
        pressure = getPressure();

        if (user_choice == 1) {
            pascals_To(pressure);
        }

        if (user_choice == 2) {
            kilopascals_To(pressure);
        }

        if (user_choice == 3) {
            bar_To(pressure);
        }

        if (user_choice == 4) {
            atmospheres_To(pressure);
        }

        if (user_choice == 5) {
            millimeters_of_mercury_To(pressure);
        }

        if (user_choice == 6) {
            pounds_per_square_inch_To(pressure);
        }
    }
}

void PressureSystem::pascals_To(float pressure) {
    std::cout << "You have chosen to convert from Pascals (Pa) to other units." << std::endl;
    std::cout << pressure << " Pa is equal to:" << std::endl;
    std::cout << pressure / 1000 << " kPa" << std::endl;
    std::cout << pressure / 100000 << " bar" << std::endl;
    std::cout << pressure / 101325 << " atm" << std::endl;
    std::cout << pressure * 0.00750062 << " mmHg" << std::endl;
    std::cout << pressure * 0.000145038 << " psi" << std::endl;
}

void PressureSystem::kilopascals_To(float pressure) {
    std::cout << "You have chosen to convert from Kilopascals (kPa) to other units." << std::endl;
    std::cout << pressure << " kPa is equal to:" << std::endl;
    std::cout << pressure * 1000 << " Pa" << std::endl;
    std::cout << pressure / 100 << " bar" << std::endl;
    std::cout << pressure / 101.325 << " atm" << std::endl;
    std::cout << pressure * 7.50062 << " mmHg" << std::endl;
    std::cout << pressure * 0.145038 << " psi" << std::endl;
}

void PressureSystem::bar_To(float pressure) {
    std::cout << "You have chosen to convert from Bar (bar) to other units." << std::endl;
    std::cout << pressure << " bar is equal to:" << std::endl;
    std::cout << pressure * 100000 << " Pa" << std::endl;
    std::cout << pressure * 100 << " kPa" << std::endl;
    std::cout << pressure / 1.01325 << " atm" << std::endl;
    std::cout << pressure * 750.062 << " mmHg" << std::endl;
    std::cout << pressure * 14.5038 << " psi" << std::endl;
}

void PressureSystem::atmospheres_To(float pressure) {
    std::cout << "You have chosen to convert from Atmospheres (atm) to other units." << std::endl;
    std::cout << pressure << " atm is equal to:" << std::endl;
    std::cout << pressure * 101325 << " Pa" << std::endl;
    std::cout << pressure * 101.325 << " kPa" << std::endl;
    std::cout << pressure * 1.01325 << " bar" << std::endl;
    std::cout << pressure * 760 << " mmHg" << std::endl;
    std::cout << pressure * 14.696 << " psi" << std::endl;
}

void PressureSystem::millimeters_of_mercury_To(float pressure) {
    std::cout << "You have chosen to convert from Millimeters of Mercury (mmHg) to other units." << std::endl;
    std::cout << pressure << " mmHg is equal to:" << std::endl;
    std::cout << pressure * 133.322 << " Pa" << std::endl;
    std::cout << pressure * 0.133322 << " kPa" << std::endl;
    std::cout << pressure * 0.00133322 << " bar" << std::endl;
    std::cout << pressure * 0.00131579 << " atm" << std::endl;
    std::cout << pressure * 0.0193368 << " psi" << std::endl;
}

void PressureSystem::pounds_per_square_inch_To(float pressure) {
    std::cout << "You have chosen to convert from Pounds per Square Inch (psi) to other units." << std::endl;
    std::cout << pressure << " psi is equal to:" << std::endl;
    std::cout << pressure * 6894.76 << " Pa" << std::endl;
    std::cout << pressure * 6.89476 << " kPa" << std::endl;
    std::cout << pressure * 0.0689476 << " bar" << std::endl;
    std::cout << pressure * 0.0680459 << " atm" << std::endl;
    std::cout << pressure * 51.7149 << " mmHg" << std::endl;
}