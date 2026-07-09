#ifndef TEMPERATURE_SYSTEM_H
#define TEMPERATURE_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "ConverterSystem.h"

class TemperatureSystem : public ConverterSystem{
    protected:
        unsigned int user_choice;
        const std::vector<std::pair<int, std::string>> temperature_options = {{1, "Celsius"},
                                                        {2, "Fahrenheit"},
                                                        {3, "Kelvin"},
                                                        {4, "Rankine"},
                                                        {0, "Exit Temperature System"}};
        const std::vector<int> acceptable_temperature_options = {1, 2, 3, 4, 0};
        float temperature;
    public:
        TemperatureSystem() = default;

        void printOptions();

        void getChoice();

        void printMenu();

        void validate_User_Choice(int user_choice, const std::vector<int> &acceptable_temperature_options );
        float getTemperature();
        
        void startSystem();
        
        void celsius_To(float temperature);

        void fahrenheit_To(float temperature);
        void kelvin_To(float temperature);

        void rankine_To(float temperature);
};

#endif