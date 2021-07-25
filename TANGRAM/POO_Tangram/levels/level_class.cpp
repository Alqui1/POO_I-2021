#include "level_class.h"


#include <sys/time.h>


level_class::level_class() : QObject()
{


    this->level_scene->setSceneRect(0,0,100,100);
    this->number_figures = 1;
    shape** figures = new shape*[1];
    figures[0] = new triangle(QVector2D(500,300), 45.0f, 10.0f, Qt::green, true,1.0f);

    this->index = 1;

    this->build_scene(figures);
    delete[] figures;

}

level_class::level_class(int number_figures, int index, shape *array_figures[]) : QObject()
{

    level_scene->setSceneRect(0,0,100,100);


    this->number_figures = number_figures;


    this->index = index;

    this->build_scene(array_figures);

    //delete[] array_figures;

}

level_class::level_class(level_class &lvl)
{

  level_scene->setSceneRect(0,0,100,100);

  this->number_figures = lvl.get_NumberFigures();


  this->index = lvl.get_Index();


  this->build_scene(lvl.getStatic_figures());

}

level_class::~level_class()
{

}



void level_class::build_scene(shape* figures[])
{


  figures_dynamic = new shape*[this->number_figures];
  static_figures = new shape*[this->number_figures];


  struct timeval time_now{};
  gettimeofday(&time_now, nullptr);
  time_t msecs_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);

  srand(msecs_time);

  QColor random_colors[] = {TANGRAM_GREENY, TANGRAM_ORANGE, TANGRAM_RED, TANGRAM_BLUE, TANGRAM_CYAN,
                           TANGRAM_DARKGREENY, TANGRAM_MAGENTA, TANGRAM_YELLOW};

  for(int i = 0; i < this->number_figures; i++){

      this->level_scene->addItem(figures[i]);



      int variation_x = rand()%250, variation_y = rand()%100 ;
      //int variation_x = 0, variation_y=0;

      if(figures[i]->get_figuret() == shape::RECTANGLE){
          figures_dynamic[i] = new rect_t(QVector2D(100 + variation_x,300 + variation_y),
             0.0f, figures[i]->getScaling_shape() - 0.8f, random_colors[rand()%8],false,figures[i]->getEdge_shape());
          this->level_scene->addItem(figures_dynamic[i]);

          static_figures[i] = new rect_t(QVector2D(figures[i]->getPosition_shape().x(),figures[i]->getPosition_shape().y()),
             figures[i]->getRotation_shape(), figures[i]->getScaling_shape(), random_colors[rand()%4],true,figures[i]->getEdge_shape());
          /*this->level_scene->addItem(static_figures[i]);*/

       }
      else if(figures[i]->get_figuret() == shape::TRIANGLE){

          figures_dynamic[i] = new triangle( QVector2D(100 + variation_x,300 + variation_y),
               0.0f, figures[i]->getScaling_shape() - 1.2f, random_colors[rand()%8],
               false, figures[i]->getEdge_shape());
           this->level_scene->addItem(figures_dynamic[i]);

          static_figures[i] = new triangle( QVector2D(figures[i]->getPosition_shape().x(),figures[i]->getPosition_shape().y()),
           figures[i]->getRotation_shape(), figures[i]->getScaling_shape(), random_colors[rand()%4],
            true, figures[i]->getEdge_shape());
          /*this->level_scene->addItem(static_figures[i]);*/
        }else if(figures[i]->get_figuret() == shape::TRAPEZOID){



          figures_dynamic[i] = new trapezoid( QVector2D(100 + variation_x,300 + variation_y ),
               0.0f, figures[i]->getScaling_shape() - 1.2f, random_colors[rand()%8],
               false, figures[i]->getEdge_shape(), figures[i]->getAngle_slope());
           this->level_scene->addItem(figures_dynamic[i]);

          static_figures[i] = new trapezoid( QVector2D(figures[i]->getPosition_shape().x(),figures[i]->getPosition_shape().y()),
                                             figures[i]->getRotation_shape(), figures[i]->getScaling_shape(), random_colors[rand()%8],
                                             true, figures[i]->getEdge_shape(), figures[i]->getAngle_slope());



        }



  }

  QObject::connect(this->level_scene, SIGNAL(eval_signal()), this, SLOT(eval_figures()));
  //qDebug() << *figures_dynamic;

  /**OJOOOOOOOO   FUNCION PUEDE DAR PROBLEMAS*/
  //delete[] figures;

}




bool level_class::eval_figures()
{



  int figures_into = 0;
  bool any_coll = true;

  bool complete_Tangram = false;
  for(int dynamic_fig = 0; dynamic_fig < number_figures; dynamic_fig++){
      //Iteramos sobre cada dinámica
      bool hasFigure = false;
      int total_vert = 0;

      //qDebug() << *figures_dynamic[dynamic_fig]->get_Points() << " " << *static_figures[dynamic_fig]->get_Points();

      int total_coll = 0;

      if(figures_dynamic[dynamic_fig]->get_figuret() == shape::RECTANGLE || figures_dynamic[dynamic_fig]->get_figuret() == shape::TRAPEZOID){
        total_vert = 4;
        }
      else if(figures_dynamic[dynamic_fig]->get_figuret() == shape::TRIANGLE){
        total_vert = 3;

      }

      int vert_into = 0;


      for(int vert = 0; vert < total_vert; vert++){ //Iterar sobre cada vertice
          bool hasVert = false;




          for(int static_fig = 0; static_fig<number_figures*2; static_fig++){ //Itera sobre cada estática

              shape* figure = static_cast<shape*>(this->level_scene->items()[static_fig]);

               if(figure->isStatic_()){
                   //qDebug() << figures_dynamic[dynamic_fig]->get_Points()[vert];
                   //qDebug() << figure->mapFromScene(figures_dynamic[dynamic_fig]->get_Points()[vert]);

                   //qDebug() << figure->contains_shape( figure->mapFromScene(figures_dynamic[dynamic_fig]->get_Points()[vert])  );
                   hasVert = figure->contains_shape( figure->mapFromScene(figures_dynamic[dynamic_fig]->get_Points()[vert])  );
                  //figures_dynamic[dynamic_fig]->get_Points()[vert]
                   //hasVert = figure->contains_shape(figure->mapFromScene(figures_dynamic[dynamic_fig]->get_Points()[vert]));
               }
               if(hasVert){
                   vert_into += 1;
                    break;
                 }



           }

          if(vert_into == total_vert){
            hasFigure = true;
            figures_into += 1;
          }


          for(int check_coll = 0; check_coll < number_figures; check_coll++){
              if(dynamic_fig != check_coll){
                if(figures_dynamic[check_coll]->contains_shape( figures_dynamic[check_coll]->mapFromScene(figures_dynamic[dynamic_fig]->get_Points()[vert]) )){

                    if(figures_dynamic[check_coll]->get_figuret() != shape::TRAPEZOID && figures_dynamic[dynamic_fig]->get_figuret() != shape::TRAPEZOID){
                        any_coll = false;
                        //qDebug() << "Collision by: " << figures_dynamic[check_coll]->get_figuret();
                      }
                    total_coll += 1;



                    // && total_coll < 2)


             }
           }

      }


    }




    //qDebug() << "Type: " << figures_dynamic[dynamic_fig]->get_figuret() << " Vertix on: " << vert_into;
    //qDebug() << "Collisions: " << total_coll;
  }

  if(figures_into == number_figures && any_coll){
      complete_Tangram = true;

    }

  if(complete_Tangram){
      QMessageBox::about(NULL,"Tangram Complete", "You win!");

    }

  /*if(!any_coll){
      QMessageBox::warning(NULL, "Take care", "Some figures are collision!");
    }*/



  tangram_completion = complete_Tangram;

  this->level_scene->lock_SceneEvent(tangram_completion);

  return complete_Tangram;

}




int level_class::get_NumberFigures() const
{
  return this->number_figures;
}

int level_class::get_Index() const
{
  return this->index;
}

shape **level_class::getStatic_figures() const
{
  return this->static_figures;
}

bool level_class::get_IsTangramComp() const
{
  return tangram_completion;
}

QGraphicsScene *level_class::get_Scene()
{
  return this->level_scene;
}









/*  OPERATOR OVERLOADING */

level_class level_class::operator=(level_class* assing_level)
{
    level_class level(*assing_level);

    this->index = level.get_Index();
    this->number_figures = level.get_NumberFigures();

    this->level_scene->clear();

    this->build_scene(level.getStatic_figures());
    return *this;
}


level_class level_class::operator=(level_class assing_level){

  level_class level(assing_level);

  this->index = level.get_Index();
  this->number_figures = level.get_NumberFigures();

  this->level_scene->clear();

  this->build_scene(level.getStatic_figures());

  return *this;

}














/* OPENING AND WRITING METHODS */

void level_class::writeLevel(QString level_name)
{
  QString name_file;
  if(level_name == "NULL") name_file = QString("LVL_%1.json").arg(this->index);
  else name_file = QString(level_name);
  QFile file(name_file);


  try{

    if(file.exists()){
        throw (string) "Archivo ya existe!";
      }

    if(!file.open(QIODevice::WriteOnly)){
      throw (string) "Error al escribir nivel";
    };


    QJsonObject level_jsonobject;


    level_jsonobject["number_level"] = index;
    level_jsonobject["number_figures"] = number_figures;


    QJsonArray arr_figures;

    for(int i = 0;i < number_figures; i++){

        QJsonObject figure;

        if(static_figures[i]->get_figuret() == shape::TRIANGLE){

            QJsonArray point;
            point.append(static_figures[i]->getPosition_shape().x());
            point.append(static_figures[i]->getPosition_shape().y());

            figure["edge"] = static_figures[i]->getEdge_shape();
            figure["scale"] = static_figures[i]->getScaling_shape();
            figure["angle_rot"] = static_figures[i]->getRotation_shape();
            figure["pos"] = point;

            figure["type"] = "TRIANGLE";
          }
        else if(static_figures[i]->get_figuret() == shape::RECTANGLE){



            QJsonArray point;
            point.append(static_figures[i]->getPosition_shape().x());
            point.append(static_figures[i]->getPosition_shape().y());

            figure["edge"] = static_figures[i]->getEdge_shape();
            figure["scale"] = static_figures[i]->getScaling_shape();
            figure["angle_rot"] = static_figures[i]->getRotation_shape();
            figure["pos"] = point;

            figure["type"] = "RECTANGLE";
          }
        else if(static_figures[i]->get_figuret() == shape::TRAPEZOID){


            QJsonArray point;
            point.append(static_figures[i]->getPosition_shape().x());
            point.append(static_figures[i]->getPosition_shape().y());

            figure["angle_slope"] = static_figures[i]->getAngle_slope();
            figure["edge"] = static_figures[i]->getEdge_shape();
            figure["scale"] = static_figures[i]->getScaling_shape();
            figure["angle_rot"] = static_figures[i]->getRotation_shape();
            figure["pos"] = point;

            figure["type"] = "TRAPEZOID";
          }

          arr_figures.append(figure);
      }

     level_jsonobject["figures"] = arr_figures;



     QJsonDocument json_doc(level_jsonobject);
     file.write(json_doc.toJson());



  }catch(string& file_error){
    QMessageBox::critical(nullptr, "Error",QString(file_error.c_str()));
  }

  if(file.isOpen()){
      file.flush();
      file.close();
    }



}

level_class* level_class::readLevel(int lvl, QString file_dic)
{

  int number_figures = 0;
  int index = -1;
  //shape** figures_Array;


  QString name_file;
  //qDebug() << name_file;
  //QString name_file = QString("LVL_%1.json");

  if(file_dic == "NULL") name_file = QString("LVL_%1.json").arg(lvl);
  else name_file = QString(file_dic);

  QFile file(name_file);




  try{

    if(!file.open(QIODevice::ReadOnly)){
      throw (string) "Error al leer nivel";
    };
    if(!file.exists()){
        throw (string) "Archivo no existe!";
      }

    QByteArray level = file.readAll();

    QJsonDocument doc_reader(QJsonDocument::fromJson(level));

    QJsonObject object = doc_reader.object();


    index = object["number_level"].toInt();
    number_figures = object["number_figures"].toInt();




    //cout << "Here " << index << " " << number_figures <<  endl;
    shape** figures_Array = new shape*[number_figures];


    QJsonArray figures = object["figures"].toArray();


    for(int count_figures = 0; count_figures < number_figures; count_figures++){


        QJsonObject figure = figures[count_figures].toObject();

        QVector2D pos( figure["pos"].toArray().at(0).toDouble(), figure["pos"].toArray().at(1).toDouble() );
        double angle_rot = figure["angle_rot"].toDouble();
        double edge = figure["edge"].toDouble();
        double scale = figure["scale"].toDouble();

        //qDebug() << angle_rot;

        if(figure["type"] == "TRIANGLE"){
           figures_Array[count_figures] = new triangle(pos, angle_rot, scale, Qt::black, true, edge);
          }
        else if(figure["type"] == "RECTANGLE"){
          figures_Array[count_figures] = new rect_t(pos, angle_rot, scale, Qt::black, true, edge);
          }
        else if(figure["type"] == "TRAPEZOID"){
          figures_Array[count_figures] = new trapezoid(pos, angle_rot, scale, Qt::black, true, edge, figure["angle_slope"].toDouble());

          }



      }


    /*shape* array[] = {
      new triangle(QVector2D(100,-10), -90.0f, 10.0f, Qt::yellow, true,1.0f),
      new rect_t(QVector2D(200,-10), 0.0f, 10.0f, Qt::gray, true,1.0f),
      new triangle(QVector2D(200,-110), -90.0f, 10.0f, Qt::yellow, true,1.0f),
      new triangle(QVector2D(300,-160), 0.0f, 16.0f, Qt::yellow, true,1.0f)
    };el_class* level_loaded = new level_class(4,1,array);*/





      level_class* level_loaded = new level_class(number_figures, index, figures_Array);



      return level_loaded;


  }catch(string& file_error){
    QMessageBox::critical(nullptr, "Error",QString(file_error.c_str()));

    level_class* level_loaded1 = new level_class;

    return level_loaded1;

  }catch(exception& e){

    level_class* level_loaded2 = new level_class;
    QMessageBox::critical(nullptr, "Error",QString(e.what()));

    return level_loaded2;
  }catch(...){
    level_class* level_loaded3 = new level_class;

    QMessageBox::critical(nullptr, "Error",QString("Ocurrio un error desconocido"));
    return level_loaded3;
  }


  if(file.isOpen()){
      file.flush();
      file.close();
    }



}




