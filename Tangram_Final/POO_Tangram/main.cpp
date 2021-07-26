#include "main_window.h"

#include <QApplication>


//Main Function, Init Window
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Main_Window w("Tangram");
  w.show();


  //Exec Main App
  return a.exec();
}
