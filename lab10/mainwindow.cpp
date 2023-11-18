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

    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open a file", ""
                                                    , "Text Files (*.txt);;All Files (*)");

    if (filePath.isEmpty()) return; // end if no file selected

    openedFile = new QFile(filePath);
    if (!openedFile->open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Failed to open the file");
        return; // end if failed to open the file
    }

    QTextStream in(openedFile);

    textEdit->show();

    textEdit->setText(in.readAll());

    setCentralWidget(textEdit);
}

void MainWindow::menuFileSave(){
    if(!openedFile->isOpen()){return;}
    QTextStream out(openedFile);

    //TODO: Output the text in the textEdit to the file
}

void MainWindow::menuFileClose(){
    if(!openedFile->isOpen()){return;}
    openedFile->close();
    textEdit->close();
}

MainWindow::~MainWindow()
{
    delete openedFile;
    delete textEdit;
}

