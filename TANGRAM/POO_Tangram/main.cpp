#include "main_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Main_Window w("Tangram POO");
  w.show();



  return a.exec();
}
