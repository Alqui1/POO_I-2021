
#include "shape.h"

#ifndef RECT_T_H
#define RECT_T_H

class rect_t: public shape{


  private:
    float edge_shape;
    QPointF points[4];



  public:

    rect_t();
    //rect_t(shape*, float);
    rect_t(QVector2D pos_shape, float rot_shape,
           float scal_shape, QColor color_shape, bool isStatic, float edge_shape);

    ~rect_t();

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

#endif

