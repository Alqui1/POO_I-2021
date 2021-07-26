#include "shape.h"


#ifndef TRIANGLE_H
#define TRIANGLE_H

// ============ triangle class ============ //

/*
  triangle class is a class that represent the triangle in the tangram

*/

class triangle : public shape
{
  private:
    float edge_shape;

    QPointF points[3];
    QPointF points_move[3];

    QPolygon triangle_pol;
  public:

    //Constructor and destructor
    triangle();
    triangle(QVector2D pos_shape, float rot_shape,
         float scal_shape, QColor color_shape, bool isStatic, float edge_shape);
    ~triangle();


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

#endif // TRIANGLE_H
