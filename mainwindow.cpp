#include "MainWindow.h"

#include "Car.h"
#include "Motorcycle.h"

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
    loadVehicles();
    refreshTable();
}

MainWindow::~MainWindow()
{
    saveVehicles();

    QVector<Vehicle*>::iterator it;

    for(it = vehicles.begin(); it != vehicles.end(); ++it)
    {
        Vehicle *v = *it;

    }
}

void MainWindow::setupUI()
{
    setWindowTitle("Vehicle Rental Management System");

    resize(950,650);

    QLabel *idLabel = new QLabel("Vehicle ID");
    QLabel *brandLabel = new QLabel("Brand");
    QLabel *modelLabel = new QLabel("Model");
    QLabel *priceLabel = new QLabel("Price Per Day");
    QLabel *typeLabel = new QLabel("Vehicle Type");
    QLabel *extraLabel = new QLabel("Doors / Engine CC");

    idEdit = new QLineEdit;
    brandEdit = new QLineEdit;
    modelEdit = new QLineEdit;
    priceEdit = new QLineEdit;
    extraEdit = new QLineEdit;

    typeCombo = new QComboBox;
    typeCombo->addItem("Car");
    typeCombo->addItem("Motorcycle");

    addButton = new QPushButton("Add");
    searchButton = new QPushButton("Search");
    rentButton = new QPushButton("Rent");
    returnButton = new QPushButton("Return");
    removeButton = new QPushButton("Remove");
    saveButton = new QPushButton("Save");

    table = new QTableWidget;

    table->setColumnCount(7);

    table->setHorizontalHeaderLabels(
        QStringList()
        << "ID"
        << "Brand"
        << "Model"
        << "Type"
        << "Price"
        << "Extra"
        << "Status");

    table->horizontalHeader()->setStretchLastSection(true);

    QGridLayout *grid = new QGridLayout;

    grid->addWidget(idLabel,0,0);
    grid->addWidget(idEdit,0,1);

    grid->addWidget(brandLabel,1,0);
    grid->addWidget(brandEdit,1,1);

    grid->addWidget(modelLabel,2,0);
    grid->addWidget(modelEdit,2,1);

    grid->addWidget(priceLabel,3,0);
    grid->addWidget(priceEdit,3,1);

    grid->addWidget(typeLabel,4,0);
    grid->addWidget(typeCombo,4,1);

    grid->addWidget(extraLabel,5,0);
    grid->addWidget(extraEdit,5,1);

    QHBoxLayout *buttons = new QHBoxLayout;

    buttons->addWidget(addButton);
    buttons->addWidget(searchButton);
    buttons->addWidget(rentButton);
    buttons->addWidget(returnButton);
    buttons->addWidget(removeButton);
    buttons->addWidget(saveButton);

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addLayout(grid);
    layout->addLayout(buttons);
    layout->addWidget(table);

    totalLabel = new QLabel;
    availableLabel = new QLabel;
    rentedLabel = new QLabel;

    layout->addWidget(totalLabel);
    layout->addWidget(availableLabel);
    layout->addWidget(rentedLabel);

    connect(addButton, &QPushButton::clicked,
            this, &MainWindow::addVehicle);

    connect(searchButton, &QPushButton::clicked,
            this, &MainWindow::searchVehicle);

    connect(rentButton, &QPushButton::clicked,
            this, &MainWindow::rentVehicle);

    connect(returnButton, &QPushButton::clicked,
            this, &MainWindow::returnVehicle);

    connect(removeButton, &QPushButton::clicked,
            this, &MainWindow::removeVehicle);

    connect(saveButton, &QPushButton::clicked,
            this, &MainWindow::saveVehicles);
    setLayout(layout);
}
void MainWindow::refreshTable()
{
    table->setRowCount(0);

    QVector<Vehicle*>::iterator it;

    for (it = vehicles.begin(); it != vehicles.end(); ++it)
    {
        Vehicle *v = *it;

        int row = table->rowCount();

        table->insertRow(row);

        table->setItem(row,0,new QTableWidgetItem(v->getId()));
        table->setItem(row,1,new QTableWidgetItem(v->getBrand()));
        table->setItem(row,2,new QTableWidgetItem(v->getModel()));
        table->setItem(row,3,new QTableWidgetItem(v->typeName()));
        table->setItem(row,4,new QTableWidgetItem(QString::number(v->getPricePerDay())));
        table->setItem(row,5,new QTableWidgetItem(v->extraInfo()));
        table->setItem(row,6,new QTableWidgetItem(
                                   v->getIsRented() ? "Rented" : "Available"));
    }

    int available = 0;

    for (Vehicle *v : vehicles)
    {
        if (!v->getIsRented())
            available++;
    }

    totalLabel->setText("Total Vehicles: " +
                        QString::number(countItems(vehicles)));

    availableLabel->setText("Available Vehicles: " +
                            QString::number(available));

    rentedLabel->setText("Rented Vehicles: " +
                         QString::number(countItems(vehicles) - available));
}
void MainWindow::loadVehicles()
{
    QFile file("vehicles.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString type = in.readLine();

        QString id = in.readLine();
        QString brand = in.readLine();
        QString model = in.readLine();
        double price = in.readLine().toDouble();
        bool rented = in.readLine().toInt();

        if(type == "Car")
        {
            int doors = in.readLine().toInt();

            vehicles.append(
                new Car(id,
                        brand,
                        model,
                        price,
                        rented,
                        doors));
        }
        else if(type == "Motorcycle")
        {
            int cc = in.readLine().toInt();

            vehicles.append(
                new Motorcycle(id,
                               brand,
                               model,
                               price,
                               rented,
                               cc));
        }
    }

    file.close();
}
void MainWindow::saveVehicles()
{
    QFile file("vehicles.txt");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);

    for(Vehicle *v : vehicles)
    {
        out << v->typeName() << "\n";
        out << v->getId() << "\n";
        out << v->getBrand() << "\n";
        out << v->getModel() << "\n";
        out << v->getPricePerDay() << "\n";
        out << v->getIsRented() << "\n";

        if(v->typeName() == "Car")
        {
            Car *c = dynamic_cast<Car*>(v);
            out << c->getNumberOfDoors() << "\n";
        }
        else
        {
            Motorcycle *m = dynamic_cast<Motorcycle*>(v);
            out << m->getEngineCapacityCC() << "\n";
        }
    }

    file.close();

    QMessageBox::information(this,
                             "Saved",
                             "Vehicles saved successfully.");
}
void MainWindow::addVehicle()
{
    QString id = idEdit->text().trimmed();
    QString brand = brandEdit->text().trimmed();
    QString model = modelEdit->text().trimmed();

    double price = priceEdit->text().toDouble();

    // Check for duplicate ID
    for (Vehicle *v : vehicles)
    {
        if (v->getId() == id)
        {
            QMessageBox::warning(this,
                                 "Duplicate ID",
                                 "A vehicle with this ID already exists.");
            return;
        }

    }
    if (typeCombo->currentText() == "Car")
    {
        int doors = extraEdit->text().toInt();

        vehicles.append(
            new Car(id,
                    brand,
                    model,
                    price,
                    false,
                    doors));
    }
    else
    {
        int cc = extraEdit->text().toInt();

        vehicles.append(
            new Motorcycle(id,
                           brand,
                           model,
                           price,
                           false,
                           cc));
    }

    refreshTable();

    idEdit->clear();
    brandEdit->clear();
    modelEdit->clear();
    priceEdit->clear();
    extraEdit->clear();

    QMessageBox::information(this,
                             "Success",
                             "Vehicle added successfully.");
}

void MainWindow::searchVehicle()
{
    QString id = idEdit->text().trimmed();

    for (Vehicle *v : vehicles)
    {
        if (v->getId() == id)
        {
            brandEdit->setText(v->getBrand());
            modelEdit->setText(v->getModel());
            priceEdit->setText(QString::number(v->getPricePerDay()));

            typeCombo->setCurrentText(v->typeName());

            if (v->typeName() == "Car")
            {
                Car *c = dynamic_cast<Car*>(v);
                extraEdit->setText(QString::number(c->getNumberOfDoors()));
            }
            else
            {
                Motorcycle *m = dynamic_cast<Motorcycle*>(v);
                extraEdit->setText(QString::number(m->getEngineCapacityCC()));
            }

            QMessageBox::information(this,
                                     "Found",
                                     "Vehicle found.");
            return;
        }
    }

    QMessageBox::warning(this,
                         "Not Found",
                         "Vehicle not found.");
}

void MainWindow::rentVehicle()
{
    QString id = idEdit->text().trimmed();

    for (Vehicle *v : vehicles)
    {
        if (v->getId() == id)
        {
            if (v->getIsRented())
            {
                QMessageBox::warning(this,
                                     "Already Rented",
                                     "This vehicle is already rented.");
                return;
            }

            v->setIsRented(true);

            refreshTable();

            QMessageBox::information(this,
                                     "Success",
                                     "Vehicle rented successfully.");

            return;
        }
    }

    QMessageBox::warning(this,
                         "Not Found",
                         "Vehicle not found.");
}

void MainWindow::returnVehicle()
{
    QString id = idEdit->text().trimmed();

    for (Vehicle *v : vehicles)
    {
        if (v->getId() == id)
        {
            if (!v->getIsRented())
            {
                QMessageBox::warning(this,
                                     "Available",
                                     "Vehicle is already available.");
                return;
            }

            v->setIsRented(false);

            refreshTable();

            QMessageBox::information(this,
                                     "Success",
                                     "Vehicle returned successfully.");

            return;
        }
    }

    QMessageBox::warning(this,
                         "Not Found",
                         "Vehicle not found.");
}

void MainWindow::removeVehicle()
{
    QString id = idEdit->text().trimmed();

    for (int i = 0; i < vehicles.size(); i++)
    {
        if (vehicles[i]->getId() == id)
        {
            delete vehicles[i];

            vehicles.removeAt(i);

            refreshTable();

            QMessageBox::information(this,
                                     "Removed",
                                     "Vehicle removed successfully.");

            return;
        }
    }

    QMessageBox::warning(this,
                         "Not Found",
                         "Vehicle not found.");
}
