

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


struct PushButton_Menu : public QPushButton{

  Q_OBJECT

  private:
    QString associated_file = "";
    int level_index;

  public:
    PushButton_Menu(QWidget* parent = nullptr) : QPushButton(parent){ getAssociated_file();};
    PushButton_Menu(QString s, QWidget* parent = nullptr) : QPushButton(s,parent){getAssociated_file(); };

    void getAssociated_file(){

       QString level_name = this->text();
       QTextStream stream;
       stream.setString(&level_name);

       int number;
       QString word_level;

       stream >> word_level >> number;

       associated_file = QString("LVL_%1.json").arg(number);
       this->level_index = number;


       //connect(this, SIGNAL(file_name(QString&)), this, SLOT(open_level(QString&))  );
    }

    void emit_level(){

      emit file_name(level_index);
    }

  signals:
    void file_name(int);

  public slots:



};



struct Sandbox_Scene : public QGraphicsScene{

  public:
    enum TYPE_SANDBOX{DEFAULT=100, FREE_SANDBOX=200};
  private:

    QList<shape*> figures_on_Canvas;
    TYPE_SANDBOX sandbox_mode;

  public:



    Sandbox_Scene(QWidget* parent = nullptr) : QGraphicsScene(parent){this->sandbox_mode = DEFAULT;};
    Sandbox_Scene(TYPE_SANDBOX mode_sanbx,QWidget* parent = nullptr) : QGraphicsScene(parent){this->sandbox_mode = mode_sanbx;};
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



class Main_Window : public QMainWindow
{
  Q_OBJECT

private:



  string name;


  QWidget main_page, level, level_menu, sandbox_mode, default_sandboxmode, user_games;
  QStackedWidget *stack = new QStackedWidget();

  int index_currentLevel = 8;
  string userName;

  level_class* Tangram_Levels;
  int level_to_charge;


  int number_userlevels = 0;

  QString file_save = "";

  //level_class* open_level;

public:
  enum Tangram_Exception{OPEN_FILE, LEVEL_PROC};

  Main_Window(string name="Null",QWidget *parent = nullptr);
  ~Main_Window();


  void arch_mainpage();
  void arch_level();
  void arch_level_selection();
  void arch_user_level();

  void arch_defaultSandBox();


  int loadLevels();


  void Sandbox_ConstructLevel(Sandbox_Scene*);

signals:

public slots:
  void Show_MainPage();
  void Show_Levels(int level_index);
  void Show_Selection_Menu();

  void Show_SandboxDefault();
  void Show_UserLevel();


  void saveFig() const;
  void openLevel() const;
  string get_NameFile(const QString&);


  void getFigures_FromDefaultSandbox();



private slots:

};
#endif // MAIN_WINDOW_H
