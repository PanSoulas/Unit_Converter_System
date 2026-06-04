#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <vector>
#include <string>


using std::cout;   using std::endl;
using std::cin;    using std::set;
using std::string; using std::vector;
using std::pair;


class ConverterSystem{
    protected:
        //User's options
        const vector<pair<char, string>> available_options = {{'A', "Temperature"},
                                                            {'B', "Length"},
                                                            {'C', "Mass"},
                                                            {'D', "Angle"},
                                                            {'E', "Pressure"},
                                                            {'F', "Speed"},
                                                            {'G', "Energy"},
                                                            {'H', "Frequency"}
                                                            };
        const vector<pair<char, char>> acceptable_options = { {'a', 'A'},
                                                            {'b', 'B'},
                                                            {'c', 'C'},
                                                            {'d', 'D'},
                                                            {'e', 'E'},
                                                            {'f', 'F'},
                                                            {'g', 'G'},
                                                            {'h', 'H'}};
        char user_choice;
    public:
        ConverterSystem() =  default;

        virtual void printMenu(){
            cout << "====================" << endl;
            cout << "      Welcome       " << endl;
            cout << "====================" << endl;
            cout << "\n";
            cout << " - Thank you for using the Converter System <3 " << endl;
            cout << " - Please choose which physical unit you want to convert - " << endl;

            for (auto option : available_options)
            {
                cout << option.first << ") " << option.second << endl; 
            }
        }                                    
        
        virtual bool validate_User_Choice(char user_choice, const vector<pair<char, char>> &acceptable_options){
            for (auto choice : acceptable_options)
            {
                if (user_choice == choice.first || user_choice == choice.second)
                {
                    return true;
                }
            }
            return false;
        }


        virtual void startSystetm(){
            printMenu();


            cout << "Your choice is : " ;
            cin >> user_choice;

            while (validate_User_Choice(user_choice, acceptable_options) == false)
            {
                cout << "Invalid input. Please choose one of the following options ! " << endl;
                for (auto option : available_options)
                {
                    cout << option.first << ") " << option.second << endl;
                }
                cin >> user_choice;
            }

            if (user_choice == 'a' || user_choice == 'A')
            {
                /* code */
            }

            if (user_choice == 'b' || user_choice == 'B')
            {
                /* code */
            }

            if (user_choice == 'c' || user_choice == 'C')
            {
                /* code */
            }

            if (user_choice == 'd' || user_choice == 'D')
            {
                /* code */
            }

            if (user_choice == 'e' || user_choice == 'E')
            {
                /* code */
            }

            if (user_choice == 'f' || user_choice == 'F')
            {
                /* code */
            }

            if (user_choice == 'g' || user_choice == 'G')
            {
                /* code */
            }

            if (user_choice == 'h' || user_choice == 'H')
            {
                /* code */
            }

            
        }
};


class TemperatureSystem : public ConverterSystem{
    protected:
        unsigned int user_choice;
        const vector<pair<unsigned int, string>> temperature_options = {{1, "Celsius"},
                                                        {2, "Fahrenheit"},
                                                        {3, "Kelvin"},
                                                        {4, "Rankine"}};
        const vector<unsigned int> acceptable_temperature_options = {1, 2, 3, 4};
        float temperature;
    public:
        TemperatureSystem() = default;

        void printMenu(){
            cout << "-------------------- \n";
            cout << " Temperature System  \n";
            cout << "-------------------- \n";
            cout << "Here are the S.I. measurement units for Temperature ! " << endl;

            for(auto option : temperature_options){
                cout << option.first << ") " << option.second << endl;
            }
        }

        bool validate_User_Choice(unsigned int user_choice, const vector<unsigned int> &acceptable_temperature_options ) {
            for (auto option : acceptable_temperature_options)
            {
                if(user_choice == option){
                    return true;
                }
            }
            return false;
        }
        
        void startSystem(){
            printMenu();    
            
            cout << "Choose : " ;
            cin >> user_choice;
            cout << '\n';
            cout << "You have chosen : " << user_choice << endl;

            while (validate_User_Choice(user_choice, acceptable_temperature_options) == false)
            {
                cout << "Invalid input. Please choose one of the following options ! " << endl;
                for (auto option : acceptable_temperature_options)
                {
                    cout << option << endl;
                }
                cin >> user_choice;
            }

            cout << "Please insert the value of the temperature you want to convert: " << endl;
            cout << "Temperature = ";
            cin >> temperature;
            cout << "\n";

            if (user_choice == 1)
            {
                celsius_To(temperature);
            }

            if (user_choice == 2)
            {
                fahrenheit_To(temperature);
            }
            
            if (user_choice == 3)
            {
                kelvin_To(temperature);
            }

            if (user_choice == 4)
            {
                rankine_To(temperature);
            }
        }


        void celsius_To(float temperature){
            cout << "User's temperature for measurement is : " << temperature << "Celsius (\u00B0C)" << endl;

            cout << "In Fahrenheit (\u00B0F): ";
            float fahrenheit = (temperature * 1.8) + 32.0;
            cout << fahrenheit << "\u00B0F" << endl; 

            cout << "In Kelvin (K): " ;
            float kelvin = temperature + 273.15;
            cout << kelvin << "K" << endl;

            cout << "In Rankine (R) : ";
            float rankine = fahrenheit + 459.67;
            cout << rankine << " R " << endl;
        }

        void fahrenheit_To(float temperature){
            cout << "User's temperature for measurement is : " << temperature << "Fahrenheit (\u00B0F)" << endl;;

            cout << "In Celsius (\u00B0C): ";
            float celsius = (temperature - 32.0) / 1.8;
            cout << celsius << "\u00B0C" << endl; 

            cout << "In Kelvin (K): " ;
            float kelvin = ((temperature - 32) / 1.8) + 273.15;
            cout << kelvin << "K" << endl;

            cout << "In Rankine (R) : ";
            float rankine = temperature + 459.67;
            cout << rankine << " R " << endl;
        }   

        void kelvin_To(float temperature){
            cout << "User's temperature for measurement is : " << temperature << "Kelvin (K)" << endl;

            cout << "In Celsius (\u00B0C): ";
            float celsius = temperature - 273.15;
            cout << celsius << "\u00B0C" << endl;

            cout << "In Fahrenheit (\u00B0F): ";
            float fahrenheit = ((temperature - 273.15) * 1.8) + 32.0;
            cout << fahrenheit << "\u00B0F" << endl;

            cout << "In Rankine (R): ";
            float rankine = 1.8 * temperature;
            cout << rankine << "R" << endl;
        }

        void rankine_To(float temperature){
            cout << "User's temperature for measurement is : " << temperature << "Rankine (R)" << endl;

            cout << "In Celsius (\u00B0C): ";
            float celsius = (temperature - 491.67) / 1.8;
            cout << celsius << "\u00B0C" << endl;

            cout << "In Fahrenheit (\u00B0F): ";
            float fahrenheit = temperature - 459.67;
            cout << fahrenheit << "\u00B0F" << endl;

            cout << "In Kelvin (K): " ;
            float kelvin = temperature / 1.8;
            cout << kelvin << "K" << endl;
        }
};

int main(){
}