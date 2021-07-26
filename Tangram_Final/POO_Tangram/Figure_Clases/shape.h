#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <QtWidgets>
#include <QtCore>
#include <QtGui>

using namespace std;

//Definition of colors and another symbolic constants

#define TANGRAM_GREENY QColor(102,196,65)
#define TANGRAM_ORANGE QColor(236,119,16)
#define TANGRAM_RED QColor(213, 76, 76)
#define TANGRAM_BLUE QColor(57, 162, 219)
#define TANGRAM_CYAN QColor(205, 240, 234)
#define TANGRAM_DARKGREENY QColor(121, 135, 119)
#define TANGRAM_MAGENTA QColor(255, 160, 160)
#define TANGRAM_YELLOW QColor(255, 213, 35)

#define PI 3.14159265359

#ifndef SHAPE_IMPORT
#define SHAPE_IMPORT


// ============ shape class ============ //
/*

  Class shape is the first class in the figures hierarchy of tangram.
  Is an abstract class.
  It's inherit from QGraphicsItem, the base class of QGraphicsItems in
  Qt. Methods:

    -boundingRect()
    -paint()

  has to be defined, if our class is discrete. It allows the paint of figure and
  set a rectangle which represents the area of the figure


*/

class shape : public QGraphicsItem{

  public:
    //Type of figures
    enum FIGURE_TYPES{RECTANGLE=100, TRIANGLE=200, TRAPEZOID=300};



  private:
    float rotation_shape, scaling_shape;
    QVector2D position_shape;
    QColor color_shape;

    QPolygon pol_fig; //Polygon which has the points of figure

    bool isStatic; //Is the figure is static or movable?

  protected:
    FIGURE_TYPES fig_type; //Type of figure

  public:



    shape();
    shape(QVector2D pos_shape, float rot_shape,
          float scal_shape, QColor color_shape, bool isStatic);

    virtual ~shape();


    //Getters - Setters
    QVector2D getPosition_shape() const;
    void setPosition_shape(QVector2D&);

    float getRotation_shape() const;
    void setRotation_shape(float);

    float getScaling_shape() const;
    void setScaling_shape(float);

    QColor getColor_shape() const;
    void setColor_shape(QColor);

    bool isStatic_() const;

    //Figure Type

    FIGURE_TYPES get_figuret() const;



    //Abstract methods


    virtual bool contains_shape(QPointF) const = 0; //containts methods in TangramRosetta
    //Name is changed for avoiding a redefinition of Qt method contains


    virtual float getEdge_shape() const = 0;
    virtual void setEdge_shape(float) = 0;

    virtual float getAngle_slope() const = 0;
    virtual void setAngle_slope(float) = 0;

    virtual QPointF* get_Points() = 0;




    //Overloaded methods
    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override = 0;


    //Events
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif


