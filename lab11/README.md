# Lab 11 - Layout and Connection
## Our Goal in Lab 10

1. Creating Qt application with different `Layout`.
2. Understand the machnism of `signal and slot`(connect) in Qt.

## Part A: Introduction to Qt Layouts
Layouts in Qt are a fundamental aspect of creating GUI applications. They manage the size and position of widgets within a window, ensuring that the GUI is responsive and looks consistent across different devices and window sizes.

## Core Concepts
- **Responsiveness**: Layouts automatically adjust the size and position of widgets when the window is resized.
- **Consistency**: They help maintain a consistent look and feel across different platforms.
- **Ease of Use**: Layouts simplify the process of GUI design, as you don't need to manually calculate positions and sizes of widgets.

## Types of Layouts
1. QHBoxLayout and QVBoxLayout

These are the simplest layouts, arranging widgets in a line either horizontally or vertically.

**Usage Example:**
```cpp
QPushButton *button1 = new QPushButton("Button 1");
QPushButton *button2 = new QPushButton("Button 2");

QHBoxLayout *hLayout = new QHBoxLayout;
hLayout->addWidget(button1);
hLayout->addWidget(button2);

QWidget *window = new QWidget;
window->setLayout(hLayout);
window->show();
```

2. QGridLayout


This layout arranges widgets in a grid. It's useful for complex interfaces with multiple rows and columns.

**Usage Example**
```cpp
QGridLayout *gridLayout = new QGridLayout;

gridLayout->addWidget(new QPushButton("Button 1"), 0, 0);
gridLayout->addWidget(new QPushButton("Button 2"), 0, 1);
gridLayout->addWidget(new QPushButton("Button 3"), 1, 0, 1, 2); // Spanning two columns

QWidget *window = new QWidget;
window->setLayout(gridLayout);
window->show();
```

3. QFormLayout


Optimized for creating forms with labels and fields aligned in two columns.

**Usage Example**
```cpp
QFormLayout *formLayout = new QFormLayout;

formLayout->addRow("Name:", new QLineEdit);
formLayout->addRow("Age:", new QSpinBox);

QWidget *window = new QWidget;
window->setLayout(formLayout);
window->show();
```


4. (Optional) Advanced Layout Management: Nesting Layouts

You can nest layouts within each other. This is a powerful feature for creating complex interfaces.

```cpp
QVBoxLayout *vLayout = new QVBoxLayout;
QHBoxLayout *hLayout = new QHBoxLayout;

hLayout->addWidget(new QPushButton("Button 1"));
hLayout->addWidget(new QPushButton("Button 2"));

vLayout->addLayout(hLayout);
vLayout->addWidget(new QPushButton("Button 3"));

QWidget *window = new QWidget;
window->setLayout(vLayout);
window->show();

```

## An full example of Grid Layout

### main.cpp
```cpp
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
```

### mainwindow.cpp

```cpp
#include "mainwindow.h"
#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    QGridLayout *gridLayout = new QGridLayout(this);

    gridLayout->addWidget(new QPushButton("Button 1"), 0, 0);
    gridLayout->addWidget(new QPushButton("Button 2"), 0, 1);
    gridLayout->addWidget(new QPushButton("Button 3"), 1, 0, 1, 2); // Spanning two columns

    setLayout(gridLayout);
}
```

### mainwindow.h
```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H

```

6. Your Task


Run different layout by your own.

## Part B: Understand Signal and Slot in Qt

1. Understanding Signals and Slots

Qt uses a mechanism called signals and slots to allow communication between objects. A signal is emitted when a particular event occurs, and a slot is a function that is called in response to a particular signal. This mechanism is a core feature of Qt and a big part of what makes it powerful and flexible.

2. Declaring Signals and Slots
**Signals**: Declared in a class using the signals keyword. They are member functions that are only declared, not defined.
**Slots**: Normal C++ member functions and can be public, protected, or private. They are declared using the slots keyword.

Example:

```cpp
class MyClass : public QObject {
    Q_OBJECT // This macro must appear in the private section of a class that declares its own signals and slots

public:
    MyClass();

signals:
    void mySignal();

public slots:
    void mySlot();
};

```

3. Implementing a Slot:

Slots are implemented like normal C++ member functions. For example,

```cpp
void MyClass::mySlot() {
    // Your code here
}
```

4. Connecting Signals to Slots

You connect a signal to a slot using the `connect` function. For instance:

```cpp
MyClass obj;
QObject::connect(&obj, &MyClass::mySignal, &obj, &MyClass::mySlot);
```

5. Emitting Signals

Signals are emitted using the `emit` keyword, followed by the signal name and its parameters. For example:

```cpp
emit mySignal();
```

6. A Pratical Example


Here's a simple example of how you might use signals and slot in Qt application

```cpp
// MyClass.h
#include <QObject>

class MyClass : public QObject {
    Q_OBJECT

public:
    MyClass();

signals:
    void valueChanged(int newValue);

public slots:
    void setValue(int value);

private:
    int m_value;
};

// MyClass.cpp
#include "MyClass.h"

MyClass::MyClass() : m_value(0) {}

void MyClass::setValue(int value) {
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}
```

In this example, `setValue` is a slot that updates `m_value` and emits `valueChanged` if the value actually changes. Other part of the application can connect the `valueChanged` signal to react to changes to `m_value`.

7. Your task

Try to understand and describe the logic in folder `connect` using the description above.