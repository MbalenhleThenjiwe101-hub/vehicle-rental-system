#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVector>
#include "Vehicle.h"

class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;
class QTableWidget;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

private slots:

    void addVehicle();
    void searchVehicle();
    void rentVehicle();
    void returnVehicle();
    void removeVehicle();
    void saveVehicles();

private:
    template <typename T>
    int countItems(const T &container);

    void setupUI();
    void refreshTable();
    void loadVehicles();

       QVector<Vehicle*> vehicles;

    QLabel *totalLabel;
    QLabel *availableLabel;
    QLabel *rentedLabel;

    // Input fields
    QLineEdit *idEdit;
    QLineEdit *brandEdit;
    QLineEdit *modelEdit;
    QLineEdit *priceEdit;
    QLineEdit *extraEdit;

    QComboBox *typeCombo;

    // Buttons
    QPushButton *addButton;
    QPushButton *searchButton;
    QPushButton *rentButton;
    QPushButton *returnButton;
    QPushButton *removeButton;
    QPushButton *saveButton;

    // Display table
    QTableWidget *table;
};

template <typename T>
int countAvailable(const T &container)
{
    int count = 0;

    for(auto item : container)
    {
        if(!item->getIsRented())
            count++;
    }

    return count;
}

template <typename T>
int MainWindow::countItems(const T &container)
{
    return container.size();
}

#endif
