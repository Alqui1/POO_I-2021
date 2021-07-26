#include "triangle.h"


// ============ Constructors ============ //

triangle::triangle() : shape()
{
  this->edge_shape = 1.0f;

  points[0] = QPoint(getPosition_shape().x(), getPosition_shape().y());
  points[1] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y() + 10*getScaling_shape());
  points[2] = QPoint(getPosition_shape().x(), getPosition_shape().y() + 10*getScaling_shape());

  points_move[0] = QPoint(getPosition_shape().x(), getPosition_shape().y());
  points_move[1] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y() + 10*getScaling_shape());
  points_move[2] = QPoint(getPosition_shape().x(), getPosition_shape().y() + 10*getScaling_shape());



  this->fig_type = shape::TRIANGLE;
}

triangle::triangle(QVector2D pos_shape, float rot_shape,
                   float scal_shape, QColor color_shape, bool isStatic, float edge_shape)
      : shape(pos_shape, rot_shape, scal_shape, color_shape, isStatic)
{
  this->edge_shape = edge_shape;

  points[0] = QPoint(pos_shape.x(), pos_shape.y());
  points[1] = QPoint(pos_shape.x() + 10*scal_shape, pos_shape.y() + 10*scal_shape);
  points[2] = QPoint(pos_shape.x(), pos_shape.y() + 10*scal_shape);

  points_move[0] = QPoint(getPosition_shape().x(), getPosition_shape().y());
  points_move[1] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y() + 10*getScaling_shape());
  points_move[2] = QPoint(getPosition_shape().x(), getPosition_shape().y() + 10*getScaling_shape());



  this->fig_type = shape::TRIANGLE;
}

// ============ Destructors ============ //
triangle::~triangle()
{

}


// ============ Getters and Setters ============ //

float triangle::getEdge_shape() const
{
  return edge_shape;
}

void triangle::setEdge_shape(float edge_shape)
{
  this->edge_shape = edge_shape;
}

float triangle::getAngle_slope() const
{
  return 0;
}

void triangle::setAngle_slope(float angle)
{

}





// ============  ============ //

bool triangle::contains_shape(QPointF point) const
{
  QPolygonF update_pol;
  update_pol << this->boundingRect().topLeft() << this->boundingRect().bottomLeft()
             << this->boundingRect().bottomRight();
  bool has_p = update_pol.containsPoint(point, Qt::OddEvenFill);
  return has_p;
}

QPointF* triangle::get_Points()
{
  return points_move;
}



// ============ Override methods ============ //

QRectF triangle::boundingRect() const
{
  //shape::boundingRect();
  QVector2D pos = getPosition_shape();
  float x = pos.x(), y = pos.y();

  float scaling = getScaling_shape();

  return QRectF(x,y, 10*scaling, 10*scaling);
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  QColor color = getColor_shape();
  QBrush brush(color,Qt::SolidPattern);
  QPen pen(QBrush(Qt::black), getEdge_shape());

  QPolygon triangle_draw;
  triangle_draw << points[0].toPoint() << points[1].toPoint() << points[2].toPoint();


  this->setRotation(getRotation_shape());

  painter->setBrush(brush);
  painter->setPen(pen);
  painter->drawPolygon(triangle_draw);


}


void triangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{


  QGraphicsItem::mouseReleaseEvent(event);


  points_move[0] = this->mapToScene(this->boundingRect().topLeft());
  points_move[1] = this->mapToScene(this->boundingRect().bottomLeft());
  points_move[2] = this->mapToScene(this->boundingRect().bottomRight());



}


