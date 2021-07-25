
#include "QObject"
#include "QtWidgets"



#include "./Figure_Clases/shape.h"
#include "./Figure_Clases/rect_t.h"
#include "./Figure_Clases/triangle.h"
#include "./Figure_Clases/trapezoid.h"

#ifndef LEVEL_CLASS_H
#define LEVEL_CLASS_H


struct scene_level : public QGraphicsScene{
  Q_OBJECT


  public:
  scene_level() : QGraphicsScene() { };


  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent){
    qDebug() << mouseEvent->pos();
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
    emit eval_signal();

  };

  void lock_SceneEvent(bool tangram_full){
    if(tangram_full){
        qDebug() << "Tangram is full";
      }

  }

  signals:
    void eval_signal();

};



class level_class: public QObject
{
  Q_OBJECT

  protected:
    int number_figures; //Numero de figuras

    //shape** figures_dynamic = new shape*[number_figures];
    //shape** static_figures = new shape*[number_figures];

    shape** figures_dynamic;
    shape** static_figures;

    int index;
    scene_level* level_scene = new scene_level();

    bool tangram_completion = false;




  public:
    level_class();
    level_class(int number_figures, int index,shape* array_figures[]);
    level_class(level_class&);
    //level_class();

    ~level_class();

    void build_scene(shape* figures[]);


    void writeLevel(QString level_name = "NULL");
    static level_class* readLevel(int, QString = "NULL");

    int get_NumberFigures() const;
    int get_Index() const;
    shape** getStatic_figures() const;
    bool get_IsTangramComp() const;



    QGraphicsScene* get_Scene();

    level_class operator=(level_class*);
    level_class operator=(level_class);


public slots:
    bool eval_figures();







};

#endif // LEVEL_CLASS_H
