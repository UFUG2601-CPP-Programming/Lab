#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create a button
    myButton = new QPushButton("Click me", this);
    myButton->setGeometry(50, 50, 100, 30);

    // Connect the button's clicked signal to the onButtonClicked slot
    connect(myButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

void MainWindow::onButtonClicked() {
    myButton->setText("Button Clicked!");
}
