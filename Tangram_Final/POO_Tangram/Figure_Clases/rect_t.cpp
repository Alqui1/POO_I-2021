#include "rect_t.h"


// ============ Constructors ============ //

rect_t::rect_t() : shape()
{
  this->edge_shape = 1.0f;
  points[0] = QPoint(getPosition_shape().x(), getPosition_shape().y());
  points[1] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y());
  points[2] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y() + 10*getScaling_shape());
  points[3] = QPoint(getPosition_shape().x(), getPosition_shape().y() + 10*getScaling_shape());

  this->fig_type = shape::RECTANGLE;


}


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

// ============ Destructors ============ //

rect_t::~rect_t(){}



// ============ Getters and Setters ============ //

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

QPointF *rect_t::get_Points()
{
  return this->points;
}


// ============  ============ //

bool rect_t::contains_shape(QPointF point) const
{
  bool has_p = this->contains(point);
  return has_p;
}




// ============ Override methods ============ //

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

// ============ Events ============ //

void rect_t::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);

    points[0] = this->mapToScene(this->boundingRect().topLeft());
    points[1] = this->mapToScene(this->boundingRect().topRight());
    points[2] = this->mapToScene(this->boundingRect().bottomRight());
    points[3] = this->mapToScene(this->boundingRect().bottomLeft());


}

