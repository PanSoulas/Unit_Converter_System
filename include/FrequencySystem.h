#ifndef FREQUENCY_SYSTEM_H
#define FREQUENCY_SYSTEM_H

#include "ConverterSystem.h"

class FrequencySystem{
    protected:
        const std::vector<std::pair<int, std::string>> available_Frequency_options = {{1, "Hertz (Hz)"},
                                                                                        {2, "Kilohertz (kHz)"},
                                                                                        {3, "Megahertz (MHz)"},
                                                                                        {4, "Gigahertz (GHz)"},
                                                                                        {5, "Revolutions per minute (RPM)"},
                                                                                        {0, "Exit"}};
        const std::vector<int> acceptable_Frequency_options = {0, 1, 2, 3, 4 ,5};
        float frequency;
        int user_choice;
    public:
        FrequencySystem() = default;

        void printMenu();

        void printOptions();

        void getChoice();

        void validateChoice(int user_choice, const std::vector<int> &acceptable_Frequency_options);

        float getFrequency(float frequency);

        void startSystem();

        void hertz_To(float frequency);
        void kilohertz_To(float frequency);
        void megahertz_To(float frequency);
        void gigahertz_To(float frequency);
        void revolutions_per_minute_To(float frequency);
};


#endif