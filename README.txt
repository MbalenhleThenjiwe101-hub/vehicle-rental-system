Vehicle Rental Management System

Student Name: Mbalenhle Mdakane
Student Number: 26492733

Description:
This is a console-based Vehicle Rental Management System developed using C++ and Qt. The program allows users to add vehicles, search for vehicles, display vehicle information, rent vehicles, return vehicles, and save/load vehicle data from a file.

Files Included:
- main.cpp
- vehicle.h
- car.h
- motorcycle.h
- CMakeLists.txt
- vehicles.txt 

Build Instructions:
1. Open Qt Creator.
2. Select File > Open File or Project.
3. Open the CMakeLists.txt file.
4. Select the Desktop Qt MinGW kit when prompted.
5. Configure the project.
6. Click Build or press Ctrl+B.

Run Instructions:
1. After building successfully, click Run or press Ctrl+R.
2. The console application will start.
3. Use the menu options to:
   - Add Vehicle
   - Search Vehicle
   - Display All Vehicles
   - Display Available Vehicles
   - Rent Vehicle
   - Return Vehicle
   - Exit the program

Features Implemented:
- Abstract base class (Vehicle)
- Inheritance (Car and Motorcycle)
- Polymorphism using virtual functions
- Encapsulation using private data members and getters/setters
- Vehicle storage using QVector
- File handling using QFile and QTextStream
- Vehicle rental management functions