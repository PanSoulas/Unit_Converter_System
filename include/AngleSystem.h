#ifndef ANGLE_SYSTEM_H
#define ANGLE_SYSTEM_H

#include "ConverterSystem.h"

class AngleSystem : public ConverterSystem{
    protected:
        const std::vector<std::pair<int, std::string>> available_Angle_options = {{1, "Degrees (°)"},
                                                            {2, "Radians (rad)"},
                                                            {3, "Gradians (gon)"},
                                                            {0, "Exit"}};
        const std::vector<int> acceptable_Angle_options = { 1, 2, 3, 0};
        int user_choice;
        float angle;
    public:
        AngleSystem() = default;

        void printMenu();

        void printOptions();

        void getChoice();

        void validateChoice(int user_choice, const std::vector<int> &acceptable_Angle_options);

        float getAngle();

        void startSystem();

        void degrees_To(float angle);
        void radians_To(float angle);
        void gradians_To(float angle);

};

#endif