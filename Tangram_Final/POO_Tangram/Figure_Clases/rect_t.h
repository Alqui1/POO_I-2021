
#include "shape.h"

#ifndef RECT_T_H
#define RECT_T_H


// ============ rect_t class ============ //

/*
  rect_t class is a class that represent the square in the tangram

*/
class rect_t: public shape{


  private:
    float edge_shape;
    QPointF points[4];



  public:

    //Constructor and destructor
    rect_t();
    rect_t(QVector2D pos_shape, float rot_shape,
           float scal_shape, QColor color_shape, bool isStatic, float edge_shape);
    ~rect_t();

    //Getters and setters
    float getEdge_shape() const override;
    void setEdge_shape(float) override;

    float getAngle_slope() const override;
    void setAngle_slope(float) override;

    QPointF* get_Points() override;

    //Look if the shape has the point
    bool contains_shape(QPointF) const override;


    //Overloaded methods
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;


    //Event
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif

