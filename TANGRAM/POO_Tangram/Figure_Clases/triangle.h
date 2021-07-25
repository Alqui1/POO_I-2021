#include "shape.h"


#ifndef TRIANGLE_H
#define TRIANGLE_H

class triangle : public shape
{
  private:
    float edge_shape;

    QPointF points[3];
    QPointF points_move[3];

    QPolygon triangle_pol;
  public:


    triangle();

    triangle(QVector2D pos_shape, float rot_shape,
         float scal_shape, QColor color_shape, bool isStatic, float edge_shape);

    ~triangle();

    float getEdge_shape() const override;
    void setEdge_shape(float) override;

    float getAngle_slope() const override;
    void setAngle_slope(float) override;

    void aspect() override;
    bool contains_shape(QPointF) const override;

    QPointF* get_Points() override;



    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;



    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // TRIANGLE_H
