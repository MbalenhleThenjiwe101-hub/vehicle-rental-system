#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"

class Motorcycle : public Vehicle
{
private:
    int engineCapacityCC;

public:

    Motorcycle(QString id,
               QString brand,
               QString model,
               double price,
               bool rented,
               int cc)

        : Vehicle(id, brand, model, price, rented)
    {
        engineCapacityCC = cc;
    }

    // Getter
    int getEngineCapacityCC() const
    {
        return engineCapacityCC;
    }

    // Setter
    void setEngineCapacityCC(int cc)
    {
        engineCapacityCC = cc;
    }

    // Override pure virtual function
    QString typeName() const override
    {
        return "Motorcycle";
    }

    QString extraInfo() const override
    {
        return QString::number(engineCapacityCC) + " CC";
    }
};

#endif
