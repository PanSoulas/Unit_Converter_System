#ifndef CONVERTER_SYSTEM_H
#define CONVERTER_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>

// περιεχόμενο
class ConverterSystem{
     protected:
        //User's options
        const std::vector<std::pair<char, std::string>> available_options = {{'A', "Temperature"},
                                                            {'B', "Length"},
                                                            {'C', "Mass"},
                                                            {'D', "Angle"},
                                                            {'E', "Pressure"},
                                                            {'F', "Speed"},
                                                            {'G', "Energy"},
                                                            {'H', "Frequency"},
                                                            {'0', "Exit"}
                                                            };
        const std::vector<std::pair<char, char>> acceptable_options = { {'a', 'A'},
                                                            {'b', 'B'},
                                                            {'c', 'C'},
                                                            {'d', 'D'},
                                                            {'e', 'E'},
                                                            {'f', 'F'},
                                                            {'g', 'G'},
                                                            {'h', 'H'},
                                                            {'0', '0'}};
        char user_choice;
    public:
        ConverterSystem() =  default;

        //Getter for choice of user
        char getUserChoice();

        void printHeader();

        void printOptions();

        void getChoice();

        //Menu
        virtual void printMenu();                                    

     
        //Validate choice
        virtual void validate_User_Choice(char user_choice, const std::vector<std::pair<char, char>> &acceptable_options);


        //The system starts
        virtual void startSystem();
};

#endif