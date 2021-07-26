
//Including all headers file we need.
#include <QtWidgets>
#include <QtGui>
#include <QtCore>


#include "Figure_Clases/shape.h"
#include "Figure_Clases/rect_t.h"
#include "Figure_Clases/triangle.h"
#include "Figure_Clases/trapezoid.h"

#include "levels/level_class.h"


#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#define NUMBER_LEVELS 8



// ======= PushButton_Menu Class ======= //

/*
  PushButton_Menu is a class used to create the buttons in the Level Gallery.
  It inherits from QPushButton, class of Qt.

  This class has some extra members (Especially, for level charging):

    -QString associated_file
    -int level_index

    -QString getAssociated_file()
    -void emit_level()

    -void file_name() SIGNAL

*/

struct PushButton_Menu : public QPushButton{

  //Q_OBJECT Macro to signals and slots
  Q_OBJECT


  //Private members
  private:
    QString associated_file = ""; //Name of associated_file to level
    int level_index; //Index from number


  //Public member
  public:

    //Constructor
    PushButton_Menu(QWidget* parent = nullptr) : QPushButton(parent){ getAssociated_file();};
    PushButton_Menu(QString s, QWidget* parent = nullptr) : QPushButton(s,parent){getAssociated_file(); };

    //Destructor
    ~PushButton_Menu(){};

    //Get and set the associated_file member
    QString getAssociated_file(){

       QString level_name = this->text();
       QTextStream stream;
       stream.setString(&level_name);

       int number;
       QString word_level;

       stream >> word_level >> number;

       associated_file = QString("LVL_%1.json").arg(number);
       this->level_index = number;

       return associated_file;

    }

    //Emit signal, to exec an event (SLOT)
    void emit_level(){

      emit file_name(level_index);
    }


  //Signals
  signals:
    void file_name(int);


  //Public Slots
  public slots:



};






// ======= Sanbox_Scene Class ======= //

/*
  Sandbox_Scene is a class used to create a scene in Sandbox mode.
  It inherits from QGraphicsScene of Qt.

  This class has some extra members (Especially, to save figures)

    -QList<shape*> figures_on_Canvas
    -TYPE_SANDBOX sandbox_mode

    -QList<shape*> get_ListFigs() const
    -TYPE_SANDBOX get_TypeSandbox() const


*/

struct Sandbox_Scene : public QGraphicsScene{

  public:
    //Type of sandbox (NOT FULLY IMPLEMENTED)
    enum TYPE_SANDBOX{DEFAULT=100, FREE_SANDBOX=200};
  private:

    QList<shape*> figures_on_Canvas;
    TYPE_SANDBOX sandbox_mode; //Type of sandbox

  public:

    //Constructors
    Sandbox_Scene(QWidget* parent = nullptr) : QGraphicsScene(parent){this->sandbox_mode = DEFAULT;};
    Sandbox_Scene(TYPE_SANDBOX mode_sanbx,QWidget* parent = nullptr) : QGraphicsScene(parent){this->sandbox_mode = mode_sanbx;};
    //Destructor
    ~Sandbox_Scene(){};

    //Add item to canvas
    void addItem(shape* item){
      QGraphicsScene::addItem(item);
      figures_on_Canvas.append(item);

    };

    QList<shape*> get_ListFigs() const{
      return figures_on_Canvas;
    };

    TYPE_SANDBOX get_TypeSandbox() const{
      return sandbox_mode;
    }

};





// ======= Main_Window Class ======= //

/*

  Main_Window is the main class of Tangram Proyect. Used to create main window and
  to control the main events in the window.
  It inherits from QMainWindow, class of Qt.


  Some members are:

    -string name
    -QWidget main_page, level, level_menu, sandbox_mode, default_sandboxmode, user_games
    -QStackedWidget *stack
    -int index_currentLevel
    -string userName
    -level_class* Tangram_Levels
    -int level_to_charge
    -int number_userlevels = NUMBER_LEVELS
    -QString file_save

    -enum Tangram_Exception{OPEN_FILE, LEVEL_PROC}

    -void arch_mainpage();
    -void arch_level();
    -void arch_level_selection();
    -void arch_user_level();
    -void arch_defaultSandBox();
    -void Sandbox_ConstructLevel(Sandbox_Scene*);
    -int loadLevels();

    SLOTS
      -void Show_MainPage()
      -void Show_Levels(int level_index)
      -void Show_Selection_Menu()
      -void Show_SandboxDefault()
      -void Show_UserLevel()

      -void saveFig() const
      -void openLevel() const
      -string get_NameFile(const QString&)
      -void getFigures_FromDefaultSandbox()

*/

class Main_Window : public QMainWindow
{
  Q_OBJECT

private:



  string name; // ???

  //All widgets of main window, page from QStackedWidget
  QWidget main_page, level, level_menu, sandbox_mode, default_sandboxmode, user_games;
  QStackedWidget *stack = new QStackedWidget(); //QStackedWidget, allow movement between pages

  int index_currentLevel = 1; //Current level of user
  string userName; //User name

  level_class* Tangram_Levels; //Array of levels
  int level_to_charge; //Levels to charge


  int number_userlevels = NUMBER_LEVELS; //Number of levels

  QString file_save = ""; //Name of the current file to save


public:
  enum Tangram_Exception{OPEN_FILE}; //List of Tangram_Exceptions, NOT IMPLEMENTED FULLY

  Main_Window(string name="Null",QWidget *parent = nullptr); //Constructor
  ~Main_Window(); //Destructor

  //Functions, create the layouts and set it to "pages" (Widges)
  void arch_mainpage();
  void arch_level();
  void arch_level_selection();
  void arch_user_level();
  void arch_defaultSandBox();

  //Other functions
  void Sandbox_ConstructLevel(Sandbox_Scene*);
  int loadLevels();


signals:

public slots:

  //Slots, show the page
  void Show_MainPage();
  void Show_Levels(int level_index);
  void Show_Selection_Menu();
  void Show_SandboxDefault();
  void Show_UserLevel();

  //open and save
  void saveFig() const;
  void openLevel() const;

  //Get functions to save file
  string get_NameFile(const QString&);
  void getFigures_FromDefaultSandbox();



private slots:

};
#endif // MAIN_WINDOW_H
