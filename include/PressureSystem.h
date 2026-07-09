#ifndef PRESSURE_SYSTEM_H
#define PRESSURE_SYSTEM_H

#include "ConverterSystem.h"

class PressureSystem : public ConverterSystem {
    protected:
        // User's choices
        const std::vector<std::pair<int, std::string>> available_Pressure_options = {
            {1, "Pascals (Pa)"},
            {2, "Kilopascals (kPa)"},
            {3, "Bar (bar)"},
            {4, "Atmospheres (atm)"},
            {5, "Millimeters of Mercury (mmHg)"},
            {6, "Pounds per Square Inch (psi)"},
            {0, "Exit"}
        };
        const std::vector<int> acceptable_Pressure_options = {1, 2, 3, 4, 5, 6, 0};
        int user_choice;
        float pressure;
    public:
        PressureSystem() = default;

        void printMenu();

        void printOptions();
        
        void getChoice();
        
        void validateChoice(int user_choice, const std::vector<int> &acceptable_Pressure_options);
        
        float getPressure();
        
        void startSystem();


        void pascals_To(float pressure);
        void kilopascals_To(float pressure);
        void bar_To(float pressure);
        void atmospheres_To(float pressure);
        void millimeters_of_mercury_To(float pressure);
        void pounds_per_square_inch_To(float pressure);
};

#endif