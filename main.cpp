#include "include/ConverterSystem.h"
#include "include/TemperatureSystem.h"
#include "include/LengthSystem.h"
#include "include/MassSystem.h"
#include "include/AngleSystem.h"
#include "include/PressureSystem.h"

int main(){
    ConverterSystem object_converter_system;
    object_converter_system.startSystem();
    while (true)
    {
        char choosing = object_converter_system.getUserChoice();
        if ( choosing == 'a' || choosing == 'A')
        {
            TemperatureSystem object_temperature;
            object_temperature.startSystem();
        }
        if (choosing == 'b' || choosing == 'B')
        {
            LengthSystem object_length;
            object_length.startSystem();
        }
        
        if (choosing == 'c' || choosing == 'C')
        {
            MassSystem object_mass;
            object_mass.startSystem();
        }
        
        if (choosing == 'd' || choosing == 'D')
        {
            AngleSystem object_angle;
            object_angle.startSystem();
        }
        
        if (choosing == 'e' || choosing == 'E')
        {
            PressureSystem object_pressure;
            object_pressure.startSystem();
        }
        
        /*
        if (choosing== 'f' || choosing == 'F')
        {
                
        }

            if (choosing == 'g' || choosing == 'G')
            {
                
        }
        
        if (choosing == 'h' || choosing == 'H')
            {
                
        }
    
        */
        if (choosing == '0')
        {
            std::cout << "Closing \n";
            break;
        }
        
        object_converter_system.printHeader();
        object_converter_system.printOptions();
        object_converter_system.getChoice();
    }

    return 0;
}