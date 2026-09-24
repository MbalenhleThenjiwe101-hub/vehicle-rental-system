# Vehicle Rental Management System

A C++ and Qt-based Vehicle Rental Management System developed as an academic project.

## Project Overview

The Vehicle Rental Management System allows users to manage vehicles and their rental status.

The system allows users to:

- Add vehicles
- Search for vehicles
- Display vehicle information
- Display available vehicles
- Rent vehicles
- Return vehicles
- Save and load vehicle data from a file

## Technologies Used

- C++
- Qt
- Qt Creator
- CMake
- Qt MinGW

## Object-Oriented Programming Concepts

The project demonstrates several object-oriented programming concepts:

- **Abstraction** — `Vehicle` is an abstract base class.
- **Inheritance** — `Car` and `Motorcycle` inherit from `Vehicle`.
- **Polymorphism** — Virtual functions are used to provide different behaviour for derived vehicle types.
- **Encapsulation** — Private data members are accessed through getters and setters.

## Data Structures and File Handling

The system uses:

- `QVector` for vehicle storage.
- `QFile` for file handling.
- `QTextStream` for reading and writing vehicle data.
- `vehicles.txt` for storing vehicle information.

## Main Features

### Add Vehicle

Users can add vehicles to the rental system.

### Search Vehicle

Users can search for vehicles stored in the system.

### Display Vehicles

The system can display vehicle information and available vehicles.

### Rent Vehicle

Users can rent an available vehicle.

### Return Vehicle

Users can return a rented vehicle.

### File Handling

Vehicle information can be saved to and loaded from a file.

## Project Structure

```text
Vehicle Rental Management System/
│
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── vehicle.cpp
├── vehicle.h
├── car.cpp
├── car.h
├── motorcycle.cpp
├── motorcycle.h
├── CMakeLists.txt
├── vehicles.txt
├── README.md
└── screenshots/

```

## How to Build

1. Open **Qt Creator**.
2. Select **File > Open File or Project**.
3. Open the `CMakeLists.txt` file.
4. Select the **Desktop Qt MinGW** kit when prompted.
5. Configure the project.
6. Click **Build** or press `Ctrl+B`.

## How to Run

1. After building successfully, click **Run** or press `Ctrl+R`.
2. The application will start.
3. Use the menu options to manage the vehicles.

Available menu options include:

- Add Vehicle
- Search Vehicle
- Display All Vehicles
- Display Available Vehicles
- Rent Vehicle
- Return Vehicle
- Exit

## Screenshots

### Main Vehicle Rental Management System

![Vehicle Rental Management System](Screenshot%202026-08-06%20145706.png)

### Adding a Vehicle

![Adding a Vehicle](Screenshot%202026-08-06%20150111.png)

### Searching for a Vehicle

![Searching for a Vehicle](Screenshot%202026-08-06%20150209.png)

### Renting a Vehicle

![Renting a Vehicle](Screenshot%202026-08-06%20150221.png)

### Vehicle List

![Vehicle List](Screenshot%202026-08-06%20150234.png)

### Vehicle Management Summary

![Vehicle Management Summary](Screenshot%202026-08-06%20152521.png)

## Academic Project

**Student:** Mbalenhle Mdakane  
**Student Number:** 26492733
