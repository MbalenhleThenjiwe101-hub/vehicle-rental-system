#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
private:
    int numberOfDoors;

public:
    Car(QString id,
        QString brand,
        QString model,
        double price,
        bool rented,
        int doors)
        : Vehicle(id, brand, model, price, rented)
    {
        numberOfDoors = doors;
    }

    int getNumberOfDoors() const
    {
        return numberOfDoors;
    }

    void setNumberOfDoors(int doors)
    {
        numberOfDoors = doors;
    }

    QString typeName() const override
    {
        return "Car";
    }

    QString extraInfo() const override
    {
        return QString::number(numberOfDoors) + " Doors";
    }
};

#endif
