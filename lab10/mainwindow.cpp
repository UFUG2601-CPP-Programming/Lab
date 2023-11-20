#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QTextEdit();
    // Set MenuBar
    QMenuBar *menuBar = new QMenuBar(this); // Create a menu bar

    // Create menus to be added to the menu bar
    QMenu *fileMenu = menuBar->addMenu("File");
    // TODO: Add Edit to menu bar

    // Add actions to the 'File' menu
    QAction *openAction = new QAction("Open", this);
    fileMenu->addAction(openAction);

    // Add Save Action to the 'File' menu, Disabled at first.
    QAction *saveAction = new QAction("Save", this);
    fileMenu->addAction(saveAction);

    QAction *closeAction = new QAction("Close", this);
    fileMenu->addAction(closeAction);

    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(menuFileOpen()));
    connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(menuFileSave()));
    connect(closeAction, SIGNAL(triggered(bool)), this, SLOT(menuFileClose()));

    // TODO: Add a menu to change the apperance of the editor (e.g. color, font, size)

    // Set the menu bar for the main window
    setMenuBar(menuBar);
}

void MainWindow::menuFileOpen(){

    filePath = QFileDialog::getOpenFileName(nullptr, "Open a file", ""
                                                    , "Text Files (*.txt);;All Files (*)");

    if (filePath.isEmpty()) return; // end if no file selected

    QFile* openedFile = new QFile(filePath);
    if (!openedFile->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Failed to open the file");
        return; // end if failed to open the file
    }

    QTextStream in(openedFile);

    textEdit->show();

    textEdit->setText(in.readAll());

    openedFile->close();

    setCentralWidget(textEdit);
}

void MainWindow::menuFileSave(){
    if(filePath.isEmpty()){return;}
    QFile* openedFile = new QFile(filePath);
    if (!openedFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Failed to open the file");
        return; // end if failed to open the file
    }

    QTextStream out(openedFile);
    // TODO: Output the text in the textEdit to the file
    // You can use textEdit->ToPlainText() to get the text in the box
    
    openedFile->close();
}

void MainWindow::menuFileClose(){
    if(filePath.isEmpty()){return;}
    filePath.clear();
    textEdit->close();
}

MainWindow::~MainWindow()
{
    delete textEdit;
}

