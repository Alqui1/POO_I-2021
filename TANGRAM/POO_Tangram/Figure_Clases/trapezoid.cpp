#include "trapezoid.h"

//Builder

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

  /*long double angle_in_radians = this->angle_slope * (PI/180);

  QRectF rect;
  if(PI/2 - angle_in_radians >= 0) rect = QRectF(x,y, 10*scaling + sin(PI/2 - angle_in_radians)* 5*scaling , 5*scaling);
  else rect = QRectF(x + sin(PI/2 - angle_in_radians)* 5*scaling ,y, 10*scaling + abs(sin(PI/2 - angle_in_radians)* 5*scaling) , 5*scaling);
  this->setTransformOriginPoint();*/


  if(PI/2 - angle_in_radians >= 0) this->setTransformOriginPoint( this->getPosition_shape().x() + (10*getScaling_shape() + abs(sin(PI/2 - angle_in_radians)* 5*getScaling_shape() ) )/2  ,
                                                                  this->getPosition_shape().y() + (  5 *getScaling_shape() ) /2 );
  else if(PI/2 - angle_in_radians < 0) this->setTransformOriginPoint( (this->getPosition_shape().x() - abs(sin(PI/2 - angle_in_radians) * 5*getScaling_shape())   ) + (  10*getScaling_shape() + abs(sin(PI/2 - angle_in_radians)* 5*getScaling_shape()) )/2  ,
                                      this->getPosition_shape().y() + (  5 *getScaling_shape() ) /2 );

}

trapezoid::trapezoid(QVector2D pos_shape, float rot_shape, float scal_shape, QColor color_shape, bool isStatic,
                     float edge_shape, float angle_slope) : shape(pos_shape, rot_shape, scal_shape, color_shape,isStatic)
{

  this->edge_shape = edge_shape;
  this->angle_slope = angle_slope;

  this->fig_type = shape::TRAPEZOID;

  /*
  Getting Points
  */
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



//Destructor
trapezoid::~trapezoid()
{

}




//Getters / Setters
float trapezoid::getEdge_shape() const
{
  return this->edge_shape;
}

void trapezoid::setEdge_shape(float)
{

}

float trapezoid::getAngle_slope() const
{
  return this->angle_slope;
}

void trapezoid::setAngle_slope(float)
{

}


//Override Methods
void trapezoid::aspect()
{

}

bool trapezoid::contains_shape(QPointF point) const
{
  QPolygonF update_pol;

  long double angle_in_radians = this->angle_slope * (PI/180);
  long double _angle_translation = sin(PI/2 - angle_in_radians)* 5*getScaling_shape() ;

  QPointF correctionTopLeft = QPointF( this->boundingRect().topLeft().x() + _angle_translation   , this->boundingRect().topLeft().y() ),
      correctionTopRight = QPointF( this->boundingRect().topRight().x() + _angle_translation , this->boundingRect().topRight().y() );



  update_pol << this->boundingRect().topLeft() << this->boundingRect().topRight() <<
                this->boundingRect().bottomRight() << this->boundingRect().bottomLeft() ;

  /*update_pol << correctionTopLeft << correctionTopRight <<
                  this->boundingRect().bottomRight() << this->boundingRect().bottomLeft() ;*/
  /*update_pol << points_move[0] << points_move[1] <<
                  points_move[2] << points_move[3] ;*/

  bool has_p = update_pol.containsPoint(point, Qt::OddEvenFill);
  return has_p;

}

QPointF *trapezoid::get_Points()
{
  return this->points_move;
}

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

  //QRectF rect = boundingRect();


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

  /*qDebug() << "Type: TRAPEZOID " << " PT1: " << points[0]
           << ", PT2: "<< points[1]
           << ", PT3: "<< points[2]
           << ", PT4: " << points[3];
  */


  //qDebug() << "Print Trapezoid";
  //qDebug() << this->contains_shape(event->pos());

  //qDebug() << points_move[0] << " " << points_move[1] << " " << points_move[2] << " " << points_move[3];
}
