#include "mainwindow.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>

/* Box Layout */
MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(button1);
    hLayout->addWidget(button2);

    setLayout(hLayout);
}


/* Grid Layout
MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QGridLayout *gridLayout = new QGridLayout(this);

    gridLayout->addWidget(new QPushButton("Button 1"), 0, 0);
    gridLayout->addWidget(new QPushButton("Button 2"), 0, 1);
    gridLayout->addWidget(new QPushButton("Button 3"), 1, 0, 1, 2); // Spanning two columns

    setLayout(gridLayout);
}
*/

/* Form Layout
MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QFormLayout *formLayout = new QFormLayout;

    formLayout->addRow("Name:", new QLineEdit);
    formLayout->addRow("Age:", new QSpinBox);

    setLayout(formLayout);
}
*/

