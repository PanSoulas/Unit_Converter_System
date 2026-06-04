# Unit Converter System

A comprehensive **Object-Oriented C++ application** for converting physical measurements across different SI units. This system provides an intuitive menu-driven interface where users can select a measurement type and convert values between various units.

## Table of Contents

- [Features](#features)
- [Architecture](#architecture)
- [Measurement Types](#measurement-types)
- [Project Structure](#project-structure)
- [Class Hierarchy](#class-hierarchy)
- [Installation](#installation)
- [Usage](#usage)
- [Code Examples](#code-examples)
- [Requirements](#requirements)
- [Contributing](#contributing)
- [License](#license)

## Features

✨ **Multi-Unit Conversion** - Convert between numerous SI units for each measurement type

🎯 **User-Friendly Interface** - Interactive menu system for easy navigation

🏗️ **Modular OOP Design** - Parent class with specialized child classes for each conversion type

⚡ **Efficient Implementation** - Direct conversion methods for each measurement type

🛡️ **Type Safety** - Leverages C++ type system for reliable conversions

## Architecture

This project follows **Object-Oriented Programming (OOP)** principles with a **hierarchical class structure**:

### Class Hierarchy

```
ConversionSystem (Parent Class)
├── Temperature
├── Length
├── Mass
├── Angle
├── Pressure
├── Speed
├── Energy
└── Frequency
```

**Parent Class:** `ConversionSystem`
- Abstract base class providing common functionality
- Manages user interface and menu selection
- Coordinates conversion operations

**Child Classes:** Specialized converters for each measurement type
- Each class implements conversion methods specific to its domain
- Handles multiple unit conversions within the measurement type
- Returns results in standard SI units and other commonly used units

## Measurement Types

The system supports conversion for **8 physical measurement types**:

### A) Temperature
Converts between:
- Celsius (°C)
- Fahrenheit (°F)
- Kelvin (K)
- Rankine (°R)

### B) Length
Converts between:
- Meters (m)
- Kilometers (km)
- Centimeters (cm)
- Millimeters (mm)
- Miles (mi)
- Yards (yd)
- Feet (ft)
- Inches (in)

### C) Mass
Converts between:
- Kilograms (kg)
- Grams (g)
- Milligrams (mg)
- Pounds (lbs)
- Ounces (oz)
- Tons (metric)

### D) Angle
Converts between:
- Degrees (°)
- Radians (rad)
- Gradians (gon)
- Minutes (arcmin)
- Seconds (arcsec)

### E) Pressure
Converts between:
- Pascals (Pa)
- Kilopascals (kPa)
- Atmospheres (atm)
- Bars (bar)
- PSI (psi)
- mmHg (Torr)

### F) Speed
Converts between:
- Meters per second (m/s)
- Kilometers per hour (km/h)
- Miles per hour (mph)
- Knots (kt)
- Feet per second (ft/s)

### G) Energy
Converts between:
- Joules (J)
- Kilojoules (kJ)
- Calories (cal)
- Kilocalories (kcal)
- Electron volts (eV)
- Watt-hours (Wh)

### H) Frequency
Converts between:
- Hertz (Hz)
- Kilohertz (kHz)
- Megahertz (MHz)
- Gigahertz (GHz)
- Revolutions per minute (RPM)

## Project Structure

```
Unit_Converter_System/
├── README.md                 # This file
├── main.cpp                  # Entry point of the application
├── ConversionSystem.h        # Parent class header
├── ConversionSystem.cpp      # Parent class implementation
├── Temperature.h             # Temperature converter header
├── Temperature.cpp           # Temperature converter implementation
├── Length.h                  # Length converter header
├── Length.cpp                # Length converter implementation
├── Mass.h                    # Mass converter header
├── Mass.cpp                  # Mass converter implementation
├── Angle.h                   # Angle converter header
├── Angle.cpp                 # Angle converter implementation
├── Pressure.h                # Pressure converter header
├── Pressure.cpp              # Pressure converter implementation
├── Speed.h                   # Speed converter header
├── Speed.cpp                 # Speed converter implementation
├── Energy.h                  # Energy converter header
├── Energy.cpp                # Energy converter implementation
├── Frequency.h               # Frequency converter header
├── Frequency.cpp             # Frequency converter implementation
└── Makefile                  # Build configuration (optional)
```

## Class Hierarchy

### Parent Class: `ConversionSystem`

```cpp
class ConversionSystem {
public:
    ConversionSystem();
    virtual ~ConversionSystem();
    
    virtual void displayOptions() = 0;
    virtual void convert() = 0;
    void startMenu();
    
protected:
    double inputValue;
    int selectedOption;
};
```

### Child Class Example: `Temperature`

```cpp
class Temperature : public ConversionSystem {
public:
    Temperature();
    
    void displayOptions() override;
    void convert() override;
    
private:
    double celsiusToFahrenheit(double celsius);
    double celsiusToKelvin(double celsius);
    double fahrenheitToCelsius(double fahrenheit);
    // ... other conversion methods
};
```

## Installation

### Prerequisites

- **C++ Compiler** (C++11 or later)
  - GCC 5.0+
  - Clang 3.8+
  - MSVC 2015+
- **Build Tool** (optional)
  - Make
  - CMake

### Compilation

#### Using g++ (GNU C++ Compiler)

```bash
g++ -std=c++11 -o UnitConverter main.cpp ConversionSystem.cpp \
    Temperature.cpp Length.cpp Mass.cpp Angle.cpp \
    Pressure.cpp Speed.cpp Energy.cpp Frequency.cpp
```

#### Using Make

```bash
make
```

#### Using CMake

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

### Running the Application

```bash
./UnitConverter
```

### Interactive Menu

1. The program displays a welcome menu with 8 measurement type options:
   ```
   ================================
   Unit Converter System
   ================================
   A) Temperature
   B) Length
   C) Mass
   D) Angle
   E) Pressure
   F) Speed
   G) Energy
   H) Frequency
   
   Select an option (A-H): 
   ```

2. Select your desired measurement type by entering the corresponding letter

3. Enter the value you want to convert

4. Select the source and target units

5. View the conversion results in multiple units

6. Choose to perform another conversion or exit

## Code Examples

### Example 1: Converting Temperature

```
Select measurement type: A (Temperature)
Enter value: 25
Current unit: Celsius

25°C = 77°F = 298.15K = 536.67°R
```

### Example 2: Converting Length

```
Select measurement type: B (Length)
Enter value: 5
Current unit: Meters

5 m = 5000 mm = 0.005 km = 16.404 ft = 5.468 yd = 0.00311 mi
```

### Example 3: Converting Speed

```
Select measurement type: F (Speed)
Enter value: 100
Current unit: kilometers per hour

100 km/h = 27.78 m/s = 62.14 mph = 53.96 knots
```

## Requirements

### System Requirements

- **RAM:** 512 MB minimum
- **Disk Space:** 5 MB minimum
- **OS:** Windows, macOS, or Linux

### Software Requirements

- C++ Standard Library (STL)
- Standard input/output (iostream)

## Implementation Details

### Conversion Methods

Each child class implements:

1. **Direct Conversion Functions** - Convert from one unit to another
2. **Reference Unit Conversion** - Convert through a standard unit (usually SI)
3. **Error Handling** - Validate input ranges and prevent invalid conversions

### Formula Examples

**Temperature:** 
- °F = (°C × 9/5) + 32
- K = °C + 273.15

**Length:**
- 1 meter = 1000 millimeters
- 1 mile = 1.60934 kilometers

**Speed:**
- 1 m/s = 3.6 km/h
- 1 mph = 0.44704 m/s

## Contributing

Contributions are welcome! To contribute:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/NewFeature`)
3. **Commit** your changes (`git commit -m 'Add NewFeature'`)
4. **Push** to the branch (`git push origin feature/NewFeature`)
5. **Open** a Pull Request

### Contribution Areas

- Add new measurement types
- Improve conversion accuracy
- Enhance user interface
- Add support for custom units
- Improve error handling
- Write unit tests
- Optimize performance

## License

This project is open source and available under the MIT License.

---

## Summary

The **Unit Converter System** is a well-structured, educational project demonstrating OOP principles in C++. With support for 8 measurement types and numerous unit conversions, it provides a practical tool for converting physical quantities while maintaining clean, modular code architecture.

### Quick Start

```bash
# Clone the repository
git clone https://github.com/PanSoulas/Unit_Converter_System.git
cd Unit_Converter_System

# Compile
g++ -std=c++11 -o UnitConverter *.cpp

# Run
./UnitConverter
```

---

**Happy Converting!** 🔄

For questions or issues, please open a GitHub issue on the repository.
