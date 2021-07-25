#include "shape.h"

// build object
shape::shape()
{
  this->setFlag(QGraphicsItem::ItemIsSelectable);

  this->rotation_shape = 0.0f;
  this->scaling_shape = 5.0f;

  this->position_shape = QVector2D(0,0);
  this->color_shape = Qt::black;

  this->isStatic = false;
  if(!isStatic){ this->setFlags(QGraphicsItem::ItemIsMovable); this->setZValue(1);}
  else this->setZValue(-1);


  this->setTransformOriginPoint(5,5);

}

shape::shape(QVector2D pos_shape, float rot_shape,
             float scal_shape, QColor color_shape, bool isStatic)
{
  this->rotation_shape = rot_shape;
  this->scaling_shape = scal_shape;

  this->position_shape = pos_shape;

  this->color_shape = color_shape;

  this->setFlags(QGraphicsItem::ItemIsSelectable);
  this->isStatic = isStatic;

  if(!isStatic){
      this->setFlag(QGraphicsItem::ItemIsMovable);
      this->color_shape = color_shape;
      this->setZValue(1);
  }else{
      this->color_shape = Qt::black;
      this->setZValue(-1);
    }


  this->setTransformOriginPoint(pos_shape.x() + (10*scal_shape)/2,  pos_shape.y() + (10*scal_shape)/2);
}

// destroy item
shape::~shape(){}

//Getters and Setters of shape.h

QVector2D shape::getPosition_shape() const
{
  return this->position_shape;
}

void shape::setPosition_shape(QVector2D& pos_shape)
{
  this->position_shape = pos_shape;
}

float shape::getRotation_shape() const
{
  return this->rotation_shape;
}

void shape::setRotation_shape(float rot)
{
  this->rotation_shape = rot;
  this->setRotation(rot);
}

float shape::getScaling_shape() const
{
  return this->scaling_shape;
}

void shape::setScaling_shape(float scal)
{
  this->scaling_shape = scal;
}

QColor shape::getColor_shape() const
{
  return this->color_shape;
}

void shape::setColor_shape(QColor color)
{
  this->color_shape = color;
}

bool shape::isStatic_() const
{
  return this->isStatic;
}

shape::FIGURE_TYPES shape::get_figuret() const
{
  return this->fig_type;
}







//Events


/*
void shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
  QGraphicsItem::mouseReleaseEvent(event);
  if(event->button() == Qt::RightButton){
      this->rotation_shape -= 45;
      this->setRotation(this->rotation_shape);

      this->update(this->boundingRect());

  }


  //qDebug() << this->mapFromScene(QPointF(10,10)) << " " << this->mapToScene(QPoint(10,10));
  qDebug() << this->contains(this->mapFromScene(QPointF(10,10)));
  //qDebug() << this->contains(event->pos());
  //qDebug() << event->pos();

  qDebug() << this->mapFromScene(this->boundingRect().topLeft());
  qDebug() << this->mapFromScene(this->boundingRect().topRight());
  qDebug() << this->mapFromScene(this->boundingRect().bottomRight());
  qDebug() << this->mapFromScene(this->boundingRect().bottomLeft());


}*/







void shape::mousePressEvent(QGraphicsSceneMouseEvent *event){
   QGraphicsItem::mousePressEvent(event);

   bool _click_on_fig =  this->contains_shape(event->pos());


   if(event->button() == Qt::RightButton && !this->isStatic && _click_on_fig){

         this->rotation_shape += 15;
         if(this->rotation_shape == 360) this->rotation_shape = 0;

         this->setRotation(this->rotation_shape);


   }

   /*qDebug() << this->mapToScene(this->boundingRect().topLeft())
   << " " << this->mapToScene(this->boundingRect().topRight())
   << " " << this->mapToScene(this->boundingRect().bottomRight())
   << " " << this->mapToScene(this->boundingRect().bottomLeft()) << " " << this->getRotation_shape();*/

   //qDebug() << this->contains(event->pos());
   //qDebug() << this->contains(this->mapFromScene(event->pos()));
   //qDebug() << this->contains(this->mapToScene(event->pos()));

}
