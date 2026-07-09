#ifndef LENGTH_SYSTEM_H
#define LENGTH_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "ConverterSystem.h"

class LengthSystem : public ConverterSystem{
    protected:
        //User's options
        const std::vector<std::pair<int, std::string>> available_Length_options = {{1, "Meters (m)"},
                                                            {2, "Kilometers (km)"},
                                                            {3, "Centimeters (cm)"},
                                                            {4, "Millimeters (mm)"},
                                                            {5, "Mile"},
                                                            {6, "Feet (ft)"},
                                                            {7, "Inches (')"},
                                                            {8, "Yards "},
                                                            {0, "Exit"}
                                                            };
        const std::vector<int> acceptable_Length_options = { 1, 2, 3, 4, 5, 6, 7, 8, 0};
        int user_choice;
        float length;
    public:
        LengthSystem() = default;

        void printMenu();

        void printOptions();

        void getChoice();

        void validateChoice(int user_choice, const std::vector<int> &acceptable_Length_options);

        float getLength();

        void startSystem();

        void meters_To(float length);
        void kilometers_To(float length);
        void centimeters_To(float length);
        void millimeters_To(float length);
        void mile_To(float length);
        void feet_To(float length);
        void inches_To(float length);
        void yards_To(float length);

};

#endif