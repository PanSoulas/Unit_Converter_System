#ifndef ENERGY_SYSTEM_H
#define ENERGY_SYSTEM_H

#include "ConverterSystem.h"

class EnergySystem : public ConverterSystem{
    protected:
    const std::vector<std::pair<int, std::string>> available_Energy_options = {{1, "Joules (J)"},
                                                            {2, "Kilojoules (kJ)"},
                                                            {3, "Calories (cal)"},
                                                            {4, "Kilocaloriess (kcal)"},
                                                            {5, "Electron volts (eV)"},
                                                            {6, "Watt hours (Wh)"},
                                                            {0, "Exit"}
                                                            };
        const std::vector<int> acceptable_Energy_options = { 1, 2, 3, 4, 5, 6, 0};
        int user_choice;
        float energy;
    public:
        EnergySystem() = default;

        void printMenu();

        void printOptions();

        void getChoice();

        void validateChoice(int user_choice, const std::vector<int> &acceptable_Energy_options);

        float getEnergy(float energy);

        void startSystem();

        void joules_To(float energy);
        void kilojoules_To(float energy);
        void calories_To(float energy);
        void kilocalories_To(float energy);
        void electrovolts_To(float energy);
        void wattHours_To(float energy);
};

#endif