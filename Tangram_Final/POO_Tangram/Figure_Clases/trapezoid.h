
#include "shape.h"
#ifndef TRAPEZOID_H
#define TRAPEZOID_H

// ============ trapezoid class ============ //

/*
  trapezoid class is a class that represent the trapezoid in the tangram

*/

class trapezoid: public shape
{
  private:

    float edge_shape;
    QPointF points[4];
    QPointF points_move[4];

    float angle_slope;


  public:
    //Constructor and destructor
    trapezoid();
    trapezoid(QVector2D pos_shape, float rot_shape,
              float scal_shape, QColor color_shape, bool isStatic, float edge_shape,
              float angles_slope);

    ~trapezoid();

    //Getters and setters
    float getEdge_shape() const override;
    void setEdge_shape(float) override;

    float getAngle_slope() const override;
    void setAngle_slope(float) override;

    //Look if the shape has the point
    bool contains_shape(QPointF) const override;

    QPointF* get_Points() override;

    //Overloaded methods
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    //Event
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // TRAPEZOID_H
