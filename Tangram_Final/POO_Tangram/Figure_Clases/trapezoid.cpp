#include "trapezoid.h"

//// ============ Constructors ============ //

trapezoid::trapezoid() : shape()
{
  this->edge_shape = 1.0f;

  this->angle_slope =45.0f;
  this->fig_type = shape::TRAPEZOID;


  long double angle_in_radians = angle_slope * (PI/180);

  points[0] = QPoint(getPosition_shape().x() +  sin(PI/2 - angle_in_radians)* 5*getScaling_shape()    , getPosition_shape().y());
  points[1] = QPoint(getPosition_shape().x() + 10*getScaling_shape() + sin(PI/2 - angle_in_radians)* 5*getScaling_shape()   , getPosition_shape().y());
  points[2] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y() + 5*getScaling_shape());
  points[3] = QPoint(getPosition_shape().x(), getPosition_shape().y() + 5*getScaling_shape());

  points_move[0] = QPoint(getPosition_shape().x() +  sin(PI/2 - angle_in_radians)* 5*getScaling_shape()    , getPosition_shape().y());
  points_move[1] = QPoint(getPosition_shape().x() + 10*getScaling_shape() + sin(PI/2 - angle_in_radians)* 5*getScaling_shape()   , getPosition_shape().y());
  points_move[2] = QPoint(getPosition_shape().x() + 10*getScaling_shape(), getPosition_shape().y() + 5*getScaling_shape());
  points_move[3] = QPoint(getPosition_shape().x(), getPosition_shape().y() + 5*getScaling_shape());

  //Ubicate the point of vertix on top left/right corner  according to angle slope using the basis of trigonometry

  if(PI/2 - angle_in_radians >= 0) this->setTransformOriginPoint( this->getPosition_shape().x() + (10*getScaling_shape() + abs(sin(PI/2 - angle_in_radians)* 5*getScaling_shape() ) )/2  ,
                                                                  this->getPosition_shape().y() + (  5 *getScaling_shape() ) /2 );
  else if(PI/2 - angle_in_radians < 0) this->setTransformOriginPoint( (this->getPosition_shape().x() - abs(sin(PI/2 - angle_in_radians) * 5*getScaling_shape())   ) + (  10*getScaling_shape() + abs(sin(PI/2 - angle_in_radians)* 5*getScaling_shape()) )/2  ,
                                      this->getPosition_shape().y() + (  5 *getScaling_shape() ) /2 );

  //The point of transformation depends on its angle slope

}

trapezoid::trapezoid(QVector2D pos_shape, float rot_shape, float scal_shape, QColor color_shape, bool isStatic,
                     float edge_shape, float angle_slope) : shape(pos_shape, rot_shape, scal_shape, color_shape,isStatic)
{

  this->edge_shape = edge_shape;
  this->angle_slope = angle_slope;

  this->fig_type = shape::TRAPEZOID;


  long double angle_in_radians = angle_slope * (PI/180);
  points[0] = QPoint(pos_shape.x() + sin(PI/2 - angle_in_radians)* 5*getScaling_shape() , pos_shape.y());
  points[1] = QPoint(pos_shape.x() + 10*scal_shape  + sin(PI/2 - angle_in_radians)* 5*getScaling_shape() , pos_shape.y());
  points[2] = QPoint(pos_shape.x() + 10*scal_shape, pos_shape.y() + 5*scal_shape);
  points[3] = QPoint(pos_shape.x(), pos_shape.y() + 5*scal_shape);


  points_move[0] = QPoint(pos_shape.x() + sin(PI/2 - angle_in_radians)* 5*getScaling_shape() , pos_shape.y());
  points_move[1] = QPoint(pos_shape.x() + 10*scal_shape  + sin(PI/2 - angle_in_radians)* 5*getScaling_shape() , pos_shape.y());
  points_move[2] = QPoint(pos_shape.x() + 10*scal_shape, pos_shape.y() + 5*scal_shape);
  points_move[3] = QPoint(pos_shape.x(), pos_shape.y() + 5*scal_shape);

  if(PI/2 - angle_in_radians >= 0) this->setTransformOriginPoint( this->getPosition_shape().x() + (10*getScaling_shape() + abs(sin(PI/2 - angle_in_radians)* 5*getScaling_shape() ) )/2  ,
                                                                  this->getPosition_shape().y() + (  5 *getScaling_shape() ) /2 );
  else if(PI/2 - angle_in_radians < 0) this->setTransformOriginPoint( (this->getPosition_shape().x() - abs(sin(PI/2 - angle_in_radians) * 5*getScaling_shape())   ) + (  10*getScaling_shape() + abs(sin(PI/2 - angle_in_radians)* 5*getScaling_shape()) )/2  ,
                                      this->getPosition_shape().y() + (  5 *getScaling_shape() ) /2 );

}



// ============ Destructors ============ //

trapezoid::~trapezoid()
{

}




// ============ Getters and Setters ============ //

float trapezoid::getEdge_shape() const
{
  return this->edge_shape;
}

void trapezoid::setEdge_shape(float edge)
{
  this->edge_shape = edge;
}

float trapezoid::getAngle_slope() const
{
  return this->angle_slope;
}

void trapezoid::setAngle_slope(float angle)
{
  this->angle_slope = angle;
}


QPointF *trapezoid::get_Points()
{
  return this->points_move;
}

// ============  ============ //


bool trapezoid::contains_shape(QPointF point) const
{
  QPolygonF update_pol;

  //long double angle_in_radians = this->angle_slope * (PI/180);
  //long double _angle_translation = sin(PI/2 - angle_in_radians)* 5*getScaling_shape() ;

  /*QPointF correctionTopLeft = QPointF( this->boundingRect().topLeft().x() + _angle_translation   , this->boundingRect().topLeft().y() ),
      correctionTopRight = QPointF( this->boundingRect().topRight().x() + _angle_translation , this->boundingRect().topRight().y() );*/



  update_pol << this->boundingRect().topLeft() << this->boundingRect().topRight() <<
                this->boundingRect().bottomRight() << this->boundingRect().bottomLeft() ;



  bool has_p = update_pol.containsPoint(point, Qt::OddEvenFill);
  return has_p;

}


// ============ Override methods ============ //

QRectF trapezoid::boundingRect() const
{
  QVector2D pos = getPosition_shape();
  float x = pos.x(), y = pos.y();

  float scaling = getScaling_shape();
  long double angle_in_radians = this->angle_slope * (PI/180);

  QRectF rect;
  if(PI/2 - angle_in_radians >= 0) rect = QRectF(x,y, 10*scaling + sin(PI/2 - angle_in_radians)* 5*scaling , 5*scaling);
  else rect = QRectF(x + sin(PI/2 - angle_in_radians)* 5*scaling ,y, 10*scaling + abs(sin(PI/2 - angle_in_radians)* 5*scaling) , 5*scaling);

  return rect;
}

void trapezoid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


  QColor color = getColor_shape();
  QBrush brush(color,Qt::SolidPattern);
  QPen pen(QBrush(Qt::black), getEdge_shape());

  QPolygon trapezoid_draw;
  trapezoid_draw << points[0].toPoint() << points[1].toPoint() << points[2].toPoint() << points[3].toPoint();

  painter->setBrush(brush);
  painter->setPen(pen);

  painter->drawPolygon(trapezoid_draw);


  this->setRotation(getRotation_shape());
}

void trapezoid::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseReleaseEvent(event);


  points_move[0] = this->mapToScene(this->boundingRect().topLeft());
  points_move[1] = this->mapToScene(this->boundingRect().topRight());
  points_move[2] = this->mapToScene(this->boundingRect().bottomRight());
  points_move[3] = this->mapToScene(this->boundingRect().bottomLeft());


}
