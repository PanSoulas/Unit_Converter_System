#ifndef MASS_SYSTEM_H
#define MASS_SYSTEM_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "ConverterSystem.h"

class MassSystem : public ConverterSystem{
    protected:
        //User's options
        const std::vector<std::pair<unsigned int, std::string>> available_Mass_options = {{1, "Kilograms (kg)"},
                                                            {2, "Grams (g)"},
                                                            {3, "Milligrams (mg)"},
                                                            {4, "Pounds (lb)"},
                                                            {5, "Ounces (oz)"},
                                                            {0, "Exit"}
                                                            };
        const std::vector<unsigned int> acceptable_Mass_options = { 1, 2, 3, 4, 5, 0};
        unsigned int user_choice;
        float mass;
    public:
        MassSystem() = default;

        void printMenu();

        void printOptions();

        void getChoice();

        void validateChoice(unsigned int user_choice, const std::vector<unsigned int> &acceptable_Mass_options);

        float getMass();


        void startSystem();

        void kilograms_To(float mass);
        void grams_To(float mass);
        void milligrams_To(float mass);
        void pounds_To(float mass);
        void ounces_To(float mass);

};

#endif 