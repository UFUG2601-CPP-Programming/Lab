# Lab 11 - Layout and Connection
## Our Goal in Lab 10

1. Creating Qt application with different `Layout`.
2. Understand the machnism of `signal and slot`(connect) in Qt.

## Introduction to Qt Layouts
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

4. QStackedLayout


Allows stacking of widgets on top of each other, showing one at a time. This is useful for implementing wizards or tab-like interfaces.

```cpp
QStackedLayout *stackedLayout = new QStackedLayout;

stackedLayout->addWidget(new QLabel("Page 1"));
stackedLayout->addWidget(new QLabel("Page 2"));

QWidget *window = new QWidget;
window->setLayout(stackedLayout);
window->show();

```

5. (Optional) Advanced Layout Management: Nesting Layouts

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
