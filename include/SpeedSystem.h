#ifndef SPEEDSYSTEM_H
#define SPEEDSYSTEM_H

#include "ConverterSystem.h"

class SpeedSystem : public ConverterSystem {
    protected:
        const std::vector<std::pair<int, std::string>> available_Speed_options = { {1, "Meters per second (m/s)"},
                                                                                            {2, "Kilometers per hour (km/h)"},
                                                                                            {3, "Miles per hour (mph)"},
                                                                                            {4, "Knots (knot)"},
                                                                                            {5, "Feet per second (ft/s)"},
                                                                                            {0, "Exit"}
                                                                                        };
        const std::vector<int> acceptable_Speed_options = {1, 2, 3, 4, 5, 0};
        int user_choice;
        float speed;
    public:
        SpeedSystem() = default;

        void printMenu();

        void printOptions();

        void getChoice();

        void validateChoice(int user_choice, const std::vector<int> &acceptable_Speed_options);

        float getSpeed(float speed);

        void startSystem();

        void metersPerSecond_To(float speed);
        void kilometersPerHour_To(float speed);
        void milesPerHour_To(float speed);
        void knots_To(float speed);
        void feetPerSecond_To(float speed);
};

#endif