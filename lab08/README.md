# Lab 08 - GUI Programming: What You See Is What You Get

## Our Goal in Lab 08

1. Install the development environment for GUI programming using Qt
2. Build and run your first GUI program.
3. Learn the basic concepts in Qt.

## What is GUI?

**User interface (UI)** is the interface or bridge that connects the user and the machine, everything that serves this purpose can be regarded as an UI. During your study of C++ Programming, you have already designed some UIs in a very primary way - the command-line interface (CLI), although most of the time you are the only one interacting with your program.

**Graphical User Interface, a.k.a. GUI**, is a form of UI that allows you to interact with your machine visually or graphically. 

Before learning programming, I believe most of you thought every program should have a GUI - a window with some button to press, and some messages or images are displayed, all you need is to click here and click there. 

That is fully correct for most of the users, and GUIs are so natural to interact with because humans just love the feeling of **“What You See Is What You Get”**. However, it is much more complex than it looks like for programmers. In this lab, you will find out the reason.

## What is Qt?

**Qt (pronounced as "cute", not "cu-tee") is a cross-platform GUI framework** that is usually used as a graphical toolkit, although it is also very helpful in creating CLI applications. It runs on many platforms: desktop platforms like Windows, Mac, and Linux, mobile platforms like Android, and iOS, and also some other platforms like your cars, watches, etc..

Qt supports both C++ and Python, if you are also learning Python, it’s a good time to see the difference between these two languages.

Qt has an impressive collection of modules, and what we are going to use in the labs are:

- **QtCore**, a base library that provides containers, thread management, event management, and much more
- **QtGui** and **QtWidgets**, a GUI toolkit for Desktop, provides a lot of graphical components to design applications.


## Task 0: Get Your Qt

1. Follow the instructions here([Install Qt Creator on Linux (stanford.edu)](https://web.stanford.edu/dept/cs_edu/resources/qt/install-linux#)) to install Qt Creator on Linux. The installer link is https://www.qt.io/download-qt-installer.
2. By default, suppose your username is **alice**, Qt is installed in
`/home/**alice**/Qt/6.6.0/` folder. You can add the following lines to your `/.bashrc` file (using `vim` or `vscode`), and then open a new terminal (then these lines will take effect).

```bash
export PATH="**/home/alice**/Qt/6.6.0/gcc_64/bin:${PATH}"
export LD_LIBRARY_PATH="**/home/alice**/Qt/6.6.0/gcc_64/lib:${LD_LIBRARY_PATH}"
```

3. Remember to replace `/home/alice` with your own username `/home/<your username>`.

**P.S. If you are a Mac/Windows user, you can ignore steps 2 and 3, but you still need to install the Qt following step 1.**

4. After the installation, check if you have the application - **Qt Creator**.

## Basic Application of Qt

```cpp
// QApplication is the foundation of a Qt application
#include <QApplication>

int main(int argc, char **argv){

    // Create an application
    QApplication app(argc, argv);

    // Start the application
    return app.exec();
}
```

For each Qt project, we also need a QMake file, which generates a Makefile:

```makefile
TEMPLATE = app
TARGET = name-of-your-target

# Include the required components
QT = core gui widgets

# Add the source files and header files
SOURCES += lab08.cpp
HEADERS += lab08.h
```

It’s very similar to Makefile, but easier to understand.

## Task 1: Build the “Hello, World“ Program in Lab 08 folder

1. Get or update the Lab code using git.
2. Enter the `lab08` folder using VS Code or Open it using the **Qt Creator (open `lab08.pro`)**.
3. Use the following commands to build and run the code:
    ```bash
    qmake 
    make
    ./lab08
    ```
4. If you are using Qt Creator, just click the build and run buttons on the bottom left part of the GUI.
5. Check the GUI program and click the button to see what will happen.

## Task 2: Modify and Build Again

1. There are many numbers and strings in the code, modify them and build again.
2. For example, try to change the size of the window or the location of the button.
3. Run the new program to see what has been changed.
4. Try to add more buttons to the windows.

## Thinking Time

1. What does the function `connect` do in the program, how does it **connect** the button with the output function?
2. We use the `clicked()` to check if the button is clicked, how about using `pressed()` or `released()`? What’s the difference between them?
3. After executing `qmake`, a Makefile is generated, read the content and find the relationship between `lab08.pro` and the Makefile.

## Additional Contents

The official tutorial is always a good place to learn the basics:

[Qt for Beginners - Qt Wiki](https://wiki.qt.io/Qt_for_Beginners) 

### Class Hierarchy of Qt:

![Qt Hierarchy](https://qt-wiki-uploads.s3.amazonaws.com/images/4/4c/Beginner-Class-Hierarchy.jpg)

As we mentioned in previous labs, classes are used to build the **hierarchy** for our program, this is exactly how they are used in Qt. But what do all these arrows represent? You will learn it after a few lectures in the future.