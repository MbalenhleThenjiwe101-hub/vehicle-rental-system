#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>

class Vehicle
{
private:
    QString id;
    QString brand;
    QString model;
    double pricePerDay;
    bool isRented;

public:
    Vehicle(QString i,
            QString b,
            QString m,
            double p,
            bool r)

    {
        id = i; brand = b; model = m; pricePerDay = p; isRented = r;
    }

    virtual ~Vehicle() {}

    QString getId() const { return id; }
    QString getBrand() const { return brand; }
    QString getModel() const { return model; }
    double getPricePerDay() const { return pricePerDay; }
    bool getIsRented() const { return isRented; }

    void setId(QString i) { id = i; }
    void setBrand(QString b) { brand = b; }
    void setModel(QString m) { model = m; }
    void setPricePerDay(double p) { pricePerDay = p; }
    void setIsRented(bool r) { isRented = r; }

    virtual QString typeName() const = 0;

    virtual QString extraInfo() const = 0;
};

#endif
