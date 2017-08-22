#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton button;
    button.setText("My text");
    button.setToolTip("A tooltip");

    QFont font("Courier");
    button.setFont(font);

    button.show();

    return app.exec();
}

