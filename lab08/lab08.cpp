// Include headers for needed Qt components
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QIcon>

// Include iostream for cout
#include <iostream>

void SayHello(){
    // a simple output function
    std::cout << "Hello World!" << std::endl;
}

int main(int argc, char **argv){

    // Create an application
    QApplication app(argc, argv);
    // Create a window and set the size of the window
    QWidget window;
    window.setFixedSize(400, 200);

    // Create a button and set its parent to the window
    QPushButton button("Hello World", &window);
    // Create some styling components
    QFont font("Courier");
    QIcon icon(QIcon::fromTheme("face-smile"));

    // Display the window
    window.show();

    // Set the attributes of the button
    button.setText("Hello World!");
    button.setToolTip("Say Hello to the World.");
    button.setFont(font);
    button.setIcon(icon);
    button.setGeometry(100, 50, 200, 100);
    button.show();

    // Connect the click event of the button to the output function
    QObject::connect(&button, &QPushButton::clicked, &SayHello);

    // Start the application
    return app.exec();
}
