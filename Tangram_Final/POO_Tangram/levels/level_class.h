
//Include headers files
#include "QObject"
#include "QtWidgets"
#include "QtMultimedia/QSound"

#include "./Figure_Clases/shape.h"
#include "./Figure_Clases/rect_t.h"
#include "./Figure_Clases/triangle.h"
#include "./Figure_Clases/trapezoid.h"

#ifndef LEVEL_CLASS_H
#define LEVEL_CLASS_H




// ======= scene_level Class ======= //

/*
  scene_level is a class used to create the QGraphicsScene in levels.
  It inherits from QGraphicsScene, class of Qt.

  This class has some extra members (Especially, for level verification):

    -void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
    -void lock_SceneEvent(bool tangram_full)

    -void eval_signal() SIGNAL

*/


struct scene_level : public QGraphicsScene{
  Q_OBJECT

  private:
    bool tangram_complete = false;

  public:
  scene_level() : QGraphicsScene() { };
  ~scene_level(){};

  //mouseReleaseEvent reimplemented. When event occurs, it verificates if figure is completed.
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent){
    //qDebug() << mouseEvent->pos();
    if(!tangram_complete){
        QGraphicsScene::mouseReleaseEvent(mouseEvent);
        emit eval_signal();
    }

  };

  //mouseMoveEvent reimplemented. When Tangram is completed, block mouse gestures
  void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent){
    if(!tangram_complete) QGraphicsScene::mouseMoveEvent(mouseEvent);
  }


  //Lockscene when tangram is full, disable events
  void lock_SceneEvent(bool tangram_full){
    if(tangram_full){
        qDebug() << "Tangram is full";
        tangram_complete = true;

        QSound::play(":/passed.wav");
      }

  }



  signals:
    void eval_signal();

};

// ======= level_class Class ======= //

/*
  level_class is a class used to create the levels in the Tangram Project.
  It inherits from QObjects, class of Qt, to enable SLOTS-SIGNALS system.

  This class has some extra members (Especially, for level verification):

    -int number_figures
    -shape** figures_dynamic
    -shape** static_figures
    -int index
    -scene_level* level_scene
    -bool tangram_completion


    -void build_scene(shape* figures[]);
    -void writeLevel(QString level_name = "NULL");
    -static level_class* readLevel(int, QString = "NULL");
    -int get_NumberFigures() const
    -int get_Index() const
    -shape** getStatic_figures() const
    -bool get_IsTangramComp() const

    -QGraphicsScene* get_Scene()

    -level_class operator=(level_class*);
    -level_class operator=(level_class);

    -bool eval_figures()


*/

class level_class: public QObject
{
  Q_OBJECT

  protected:
    //Number figures
    int number_figures;

    //Shapes static and dynamic in Tangram
    shape** figures_dynamic;
    shape** static_figures;


    int index;
    scene_level* level_scene = new scene_level();

    //Verify completion of tangram
    bool tangram_completion = false;




  public:
    //Constructor of tangram
    level_class();
    level_class(int number_figures, int index,shape* array_figures[]);
    level_class(level_class&);

    ~level_class();

    //Build scene, place the figures on canvas
    void build_scene(shape* figures[]);

    //Functions to write (read) level to (from) a JSON
    void writeLevel(QString level_name = "NULL");
    static level_class* readLevel(int, QString = "NULL");

    //Getters
    int get_NumberFigures() const;
    int get_Index() const;
    shape** getStatic_figures() const;
    bool get_IsTangramComp() const;
    QGraphicsScene* get_Scene();


    //Operator overloading
    level_class operator=(level_class*);
    level_class operator=(level_class);


public slots:
    //Eval the tangram
    bool eval_figures();


};

#endif // LEVEL_CLASS_H
