#include "mainwindow.h"
#include <QApplication>
#include "bank.h"

int main(int argc, char *argv[])
{
    Bank bank;
    bank.read_data();
    bank.reset_days();
    bank.save_data();
    QApplication a(argc, argv);
    QFont font("Segoe Print");
    font.setStyleHint(QFont::Monospace);
    a.setFont(font);
    MainWindow w;
    w.set_bank(bank);
    w.show();
    return a.exec();
}
