# Unit Converter System

A comprehensive **Object-Oriented C++ application** for converting physical measurements across different SI units. This system provides an intuitive menu-driven interface where users can select a measurement type and convert values between various units.

## Table of Contents

- [Features](#features)
- [Architecture](#architecture)
- [Measurement Types](#measurement-types)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Features

**Multi-Unit Conversion** - Convert between numerous SI units for each measurement type

**User-Friendly Interface** - Interactive menu system for easy navigation

**Modular OOP Design** - Parent class with specialized child classes for each conversion type

**Efficient Implementation** - Direct conversion methods for each measurement type

**Type Safety** - Leverages C++ type system for reliable conversions

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
├── src                       # Contains all the .cpp files
  ├── ConversionSystem.cpp      # Parent class implementation
  ├── Temperature.cpp           # Temperature converter implementation
  ├── Length.cpp                # Length converter implementation
  ├── Mass.cpp                  # Mass converter implementation
  ├── Angle.cpp                 # Angle converter implementation
  ├── Pressure.cpp              # Pressure converter implementation
  ├── Speed.cpp                 # Speed converter implementation
  ├── Energy.cpp                # Energy converter implementation
  ├── Frequency.cpp             # Frequency converter implementation
├── include                       # Contains all the .h files
  ├── ConversionSystem.h        # Parent class header
  ├── Temperature.h             # Temperature converter header
  ├── Length.h                  # Length converter header
  ├── Mass.h                    # Mass converter header
  ├── Angle.h                   # Angle converter header
  ├── Pressure.h                # Pressure converter header
  ├── Speed.h                   # Speed converter header
  ├── Energy.h                  # Energy converter header
  ├── Frequency.h               # Frequency converter header
└── Makefile                  # Build configuration (optional)
```

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
g++ main.cpp src/*.cpp -I include -o UnitConverter
./UnitConverter
```

---

**Happy Converting!** 

For questions or issues, please open a GitHub issue on the repository.
