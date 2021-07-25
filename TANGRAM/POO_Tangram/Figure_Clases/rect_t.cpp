#include "rect_t.h"


// build object

rect_t::rect_t() : shape()
{
  this->edge_shape = 1.0f;
  points[0] = QPoint(getPosition_shape().x(), getPosition_shape().y());
  points[1] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y());
  points[2] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y() + 10*getScaling_shape());
  points[3] = QPoint(getPosition_shape().x(), getPosition_shape().y() + 10*getScaling_shape());

  this->fig_type = shape::RECTANGLE;


}

/*rect_t::rect_t(shape *, float) : shape(s)
{

}*/


rect_t::rect_t(QVector2D pos_shape, float rot_shape,
               float scal_shape, QColor color_shape, bool isStatic,float edge_shape) :
  shape(pos_shape, rot_shape, scal_shape, color_shape, isStatic)
{
  this->edge_shape = edge_shape;

  points[0] = QPoint(pos_shape.x(), pos_shape.y());
  points[1] = QPoint(pos_shape.x() + 10*scal_shape, pos_shape.y());
  points[2] = QPoint(pos_shape.x() + 10*scal_shape, pos_shape.y() + 10*scal_shape);
  points[3] = QPoint(pos_shape.x(), pos_shape.y() + 10*scal_shape);

  this->fig_type = shape::RECTANGLE;




}

// destroy item

rect_t::~rect_t(){}

//Getters and Setters shape.h

float rect_t::getEdge_shape() const
{
  return this->edge_shape;
}

void rect_t::setEdge_shape(float edge_shape)
{
  this->edge_shape = edge_shape;
}

float rect_t::getAngle_slope() const
{
  return 0;
}

void rect_t::setAngle_slope(float)
{

}
//Aspect and Contains
void rect_t::aspect()
{

}

bool rect_t::contains_shape(QPointF point) const
{
  bool has_p = this->contains(point);
  return has_p;
}

QPointF *rect_t::get_Points()
{
  return this->points;
}


//Override Element

QRectF rect_t::boundingRect() const{

  QVector2D pos = getPosition_shape();
  float x = pos.x(), y = pos.y();

  float scaling = getScaling_shape();

  return QRectF(x,y, 10*scaling, 10*scaling);
}

void rect_t::paint(QPainter *painter,
             const QStyleOptionGraphicsItem *options, QWidget *widget)
{


  QColor color = getColor_shape();
  QBrush brush(color,Qt::SolidPattern);
  QPen pen(QBrush(Qt::black), getEdge_shape());

  QRectF rect = boundingRect();
  this->setRotation(getRotation_shape());

  painter->setBrush(brush);
  painter->setPen(pen);
  painter->drawRect(rect);


}

void rect_t::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    /*shape::mouseReleaseEvent(event);*/
    points[0] = this->mapToScene(this->boundingRect().topLeft());
    points[1] = this->mapToScene(this->boundingRect().topRight());
    points[2] = this->mapToScene(this->boundingRect().bottomRight());
    points[3] = this->mapToScene(this->boundingRect().bottomLeft());

    /*qDebug() << "Type: TRAPEZOID " << " PT1: " << points[0]
             << ", PT2: "<< points[1]
             << ", PT3: "<< points[2]
             << ", PT4: " << points[3] << " Angle: " << this->getRotation_shape();*/
    /*qDebug() << "This element is estatic" << this->isStatic_();
    qDebug() << points[0] << " " << points[1] << " " << points[2] << " " << points[3];*/

    //qDebug() << "To: " << this->mapToScene(this->boundingRect().topLeft()) << " / From: " << this->mapFromScene(this->boundingRect().topLeft()) << " / None: "  << this->boundingRect().topLeft();
    //qDebug() << "To: " << this->mapToScene(this->boundingRect().topLeft()) << " / From: " << this->mapFromScene(this->boundingRect().topRight()) << " / None: "  << this->boundingRect().topRight();
    //qDebug() << "To: " << this->mapToScene(this->boundingRect().bottomRight()) << " / From: " << this->mapFromScene(this->boundingRect().bottomRight()) << " / None: "  << this->boundingRect().bottomRight();
    //qDebug() << "To: " << this->mapToScene(this->boundingRect().bottomLeft()) << " / From: " << this->mapFromScene(this->boundingRect().bottomLeft()) << " / None: "  << this->boundingRect().bottomLeft();
    //qDebug() << "Print Square";
    //qDebug() << this->mapToScene(event->pos());
    // FUNCIONAAAA qDebug() << this->contains_shape(event->pos());
    // NO FUNCIONA qDebug() << this->contains_shape(this->mapToScene(event->pos()));

    //FUNCIONAN, TOMAR COMO EJEMPLO
    //qDebug() << this->mapFromScene(QPointF(540,340));
    //qDebug() << this->contains_shape(this->mapFromScene(QPointF(540,340)));
}

