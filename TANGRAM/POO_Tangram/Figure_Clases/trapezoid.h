
#include "shape.h"
#ifndef TRAPEZOID_H
#define TRAPEZOID_H


class trapezoid: public shape
{
  private:

    float edge_shape;
    QPointF points[4];
    QPointF points_move[4];

    float angle_slope;


  public:
    trapezoid();
    trapezoid(QVector2D pos_shape, float rot_shape,
              float scal_shape, QColor color_shape, bool isStatic, float edge_shape,
              float angles_slope);

    ~trapezoid();

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

#endif // TRAPEZOID_H
