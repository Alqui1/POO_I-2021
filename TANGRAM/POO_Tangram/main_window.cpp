#include "main_window.h"


Main_Window::Main_Window(string name,QWidget *parent)
  : QMainWindow(parent)
{



  this->setWindowTitle(name.c_str());
  this->setGeometry(50,50,1200,800);
  this->setFixedSize(1200,800);

  /*try{
    ifstream readfile;
    readfile.open("LEVEL_USER.bin", ios::binary);

    if(!readfile) throw (Tangram_Exception)OPEN_FILE;
    else{


      string name;
      int index_currentLevel;
      readfile.seekg(6);

      readfile >> name;

      long actual_cursor = readfile.tellg();
      readfile.seekg(actual_cursor+3);
      readfile >> index_currentLevel;

      this->userName = name;
      this->index_currentLevel = index_currentLevel;


      readfile.close();
    }


  }catch(Tangram_Exception& excep){
    if(excep == 0){
        cout << "Partida no encontrada, se creará nuevo archivo" << endl;
        ofstream new_game("LEVEL_USER.bin", ios::binary);

        new_game << "User_1 Sandra = " << 1 << endl;

        new_game.close();
      }
  }
  */

  loadLevels();

  arch_mainpage();
  arch_level_selection();
  arch_level();
  arch_defaultSandBox();
  arch_user_level();


  stack->addWidget(&main_page);
  stack->addWidget(&level_menu);
  stack->addWidget(&level);
  stack->addWidget(&default_sandboxmode);
  stack->addWidget(&user_games);


  stack->setCurrentWidget(&main_page);



  this->setCentralWidget(stack);







}

Main_Window::~Main_Window()
{
}

//CreatePages

void Main_Window::arch_mainpage()
{

  static QHBoxLayout hbox;


  QLabel* main_label = new QLabel("Tangram");

  main_label->setFont(QFont("ADAM.CG PRO", 50, 10));

  hbox.addWidget(main_label, 0,Qt::AlignCenter);


  QVBoxLayout* vbox = new QVBoxLayout();



  QPushButton *gallery_lvl = new QPushButton("Gallery Level");
  gallery_lvl->setFixedSize(400,50);
  vbox->addWidget(gallery_lvl,0,Qt::AlignHCenter);



  QPushButton *sandbox_mode = new QPushButton("Sandbox Mode");
  sandbox_mode->setFixedSize(400,50);
  vbox->addWidget(sandbox_mode,0,Qt::AlignHCenter);


  QPushButton *open_user_ga = new QPushButton("Open User Game");
  open_user_ga->setFixedSize(400,50);
  vbox->addWidget(open_user_ga,0,Qt::AlignHCenter);

  QPushButton *closebtn = new QPushButton("Close Game");
  closebtn->setFixedSize(400,50);
  vbox->addWidget(closebtn,0,Qt::AlignHCenter);


  gallery_lvl->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");
  sandbox_mode->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");
  open_user_ga->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");
  closebtn->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");


  vbox->setSpacing(70);

  vbox->setAlignment(Qt::AlignVCenter);

  QGroupBox* box = new QGroupBox;
  box->setFlat(true);
  box->setLayout(vbox);


  hbox.addWidget(box);

  connect(gallery_lvl, SIGNAL(clicked()), this, SLOT(Show_Selection_Menu() ));
  connect(sandbox_mode,SIGNAL(clicked()), this, SLOT(Show_SandboxDefault() )  );
  connect(open_user_ga, SIGNAL(clicked()), this, SLOT(Show_UserLevel())  );
  connect(closebtn, &QPushButton::clicked, this, &Main_Window::close);

  this->main_page.setStyleSheet("background-color: white;");
  this->main_page.setLayout(&hbox);
}

void Main_Window::arch_level()
{


  static QVBoxLayout level_layout(this);
  //Buscar archivo con datos de nivel, y lo crea



  /*shape* array[] = {
    new triangle(QVector2D(100,-10), -90.0f, 10.0f, Qt::yellow, true,1.0f),
    new rect_t(QVector2D(200,-10), 0.0f, 10.0f, Qt::gray, true,1.0f),
    new triangle(QVector2D(200,-110), -90.0f, 10.0f, Qt::yellow, true,1.0f),
    new triangle(QVector2D(300,-160), 0.0f, 16.0f, Qt::yellow, true,1.0f)
  };*/

  //shape* array[] = {new rect_t(QVector2D(200,-10), 45.0f, 10.0f, Qt::gray, true,1.0f)};

  //level_class*  my_level = new level_class(4,1,array);
  //QGraphicsScene* scene = my_level->get_Scene();


  //QGraphicsScene* scene = new QGraphicsScene();



  //new rect_t(QVector2D(700,100),45.0f,10,Qt::green,true, 1.0f),

  //triangle* tri_1 =new triangle(QVector2D(600,300), -90.0F, 10, Qt::cyan, true, 1.0f);
  //rect_t* square = new rect_t(QVector2D(700,300),0.0f,10,Qt::green,true, 1.0f);
  //trapezoid* tra = new trapezoid(QVector2D(700,200),0.0f,10,Qt::red,true, 3, 40.0f);

  QGraphicsView *view = new QGraphicsView();

  //view->setViewport(new QOpenGLWidget());

  /*shape* array[] = {new trapezoid(QVector2D(700,200),45.0f,15,TANGRAM_DARKGREENY,true, 1.0f, 45.0f)};

  level_class*  my_level = new level_class(1,1,array);
  QGraphicsScene* scene = my_level->get_Scene();*/

  //QGraphicsScene* scene = new QGraphicsScene();



  //level_class* my_level = new level_class( level_class::readLevel(1));


  /*triangle *tr_big1 = new triangle(QVector2D(748,330), 225.0f, 20, TANGRAM_GREENY, true, 2.0f),
      *tr_big2 = new triangle(QVector2D(725,491), 270.0f, 20, TANGRAM_ORANGE, true, 2.0f),
      *tr_med = new triangle(QVector2D(775,320), 45.0f, 15, TANGRAM_RED, true, 2.0f),
        *tr_peq1 = new triangle(QVector2D(730,104), 225.0f, 10, TANGRAM_BLUE, true, 2.0f),
      *tr_peq2 = new triangle(QVector2D(873,104), 45.0f, 10, TANGRAM_CYAN, true, 2.0f);

  trapezoid* trap = new trapezoid(QVector2D(992,600),135.0f,15,TANGRAM_DARKGREENY,true, 2.0f, 160.0f);

  rect_t* square = new rect_t(QVector2D(801,174),45.0f,10,TANGRAM_MAGENTA,true, 2.0f);

  shape* array[] = {tr_big1,tr_big2,tr_med, tr_peq1, tr_peq2, trap, square};

  level_class*  my_level = new level_class(7,1,array);

  QGraphicsScene* scene = my_level->get_Scene();*/



  //my_level->writeLevel();

  //scene->setSceneRect(0,0,100,100);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);




  //view->setSceneRect(scene->sceneRect());
  //view->setScene(scene);


  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setResizeAnchor(QGraphicsView::AnchorViewCenter);


  //scene->addItem(tri_1);
  //scene->addItem(square);
  //scene->addItem(tra);
  //scene->addItem(tr_static);

  //scene->addEllipse(QRectF( tri_1->mapFromScene(QPointF(400,300)) , QSizeF(10,10))  , QPen(), QBrush(Qt::green));
  //scene->addEllipse(QRectF( tri_1->mapToScene(QPointF(400,300)) , QSizeF(10,10))  , QPen(), QBrush(Qt::green));
  //scene->addEllipse(QRectF( QPointF(540,340) , QSizeF(10,10))  , QPen(), QBrush(Qt::black));

  //qDebug() << "To: " << tr_static->contains_shape(tr_static->mapToScene(QPoint(498,450)));
  //qDebug() << "From: " << tr_static->contains_shape(tr_static->mapFromScene(QPoint(498,450)));
  //qDebug() << "None: " << tr_static->contains_shape(QPoint(498,450));


  level_layout.addWidget(view, 3);

  QPushButton *push1 = new QPushButton("Come back to Menu!");




  level_layout.addWidget(push1,1);

  connect(push1, SIGNAL(clicked()), this, SLOT(Show_Selection_Menu()));



  this->level.setLayout(&level_layout);



}

void Main_Window::arch_level_selection()
{
  static QGridLayout grid_levels;
  grid_levels.setHorizontalSpacing(50);

  QLabel* text = new QLabel("Gallery Level");
  text->setFixedHeight(150);
  text->setFont(QFont("ADAM.CG PRO", 50, 10));
  text->setStyleSheet("color: black;");
  grid_levels.addWidget(text, 0,0,1,4, Qt::AlignHCenter);

  for(int i = 0, j = 1; i<NUMBER_LEVELS;i++){

      QString level;
      level = QString("Level %1").arg(i+1);


      PushButton_Menu *push = new PushButton_Menu(level);
      push->setFixedSize(200,200);



      if(i+1 > index_currentLevel){
        push->setDisabled(true);
        push->setStyleSheet("QPushButton{background-color: gray; color: white; font-size: 20px}");
        push->setIcon(QPixmap(":/lock.png"));
        }else{
          push->setStyleSheet("QPushButton{background-color: black; color: white; font-size: 20px} QPushButton:pressed{background-color: white; color: black}");
        }

      grid_levels.addWidget(push,j, i%4);

      if(i%4 == 3) j++;

      connect(push, &PushButton_Menu::clicked, push,&PushButton_Menu::emit_level);
      connect(push, SIGNAL(file_name(int)), this, SLOT(Show_Levels(int)));
    }

  QPushButton* return_menu= new QPushButton("Return Menu!");
  return_menu->setFixedSize(70,40);
  grid_levels.addWidget(return_menu, 3,0, Qt::AlignLeft);
  connect(return_menu, SIGNAL(clicked()),this, SLOT(Show_MainPage()) );



  this->level_menu.setStyleSheet("background-color: white;");
  this->level_menu.setLayout(&grid_levels);
}



void Main_Window::arch_user_level()
{
  static QVBoxLayout uslevel_layout(this);

  QGraphicsView *view = new QGraphicsView();

  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);



  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setResizeAnchor(QGraphicsView::AnchorViewCenter);



  uslevel_layout.addWidget(view, 3);

  QHBoxLayout* buttons_sandbox_default = new QHBoxLayout;


  QPushButton *selection_modemenu_btn = new QPushButton("Main Menu");
  QPushButton *open_level = new QPushButton("Open Level");


  buttons_sandbox_default->addWidget(selection_modemenu_btn);
  buttons_sandbox_default->addWidget(open_level);

  uslevel_layout.addLayout(buttons_sandbox_default, 1);

  connect(selection_modemenu_btn, SIGNAL(clicked()), this, SLOT(Show_MainPage()));
  connect(open_level, SIGNAL(clicked()), this, SLOT(openLevel()));


  this->user_games.setLayout(&uslevel_layout);

}










void Main_Window::arch_defaultSandBox(){


  static QVBoxLayout sandbox_default_layout(this);


  QGraphicsView *view = new QGraphicsView();



  triangle *tr_big1 = new triangle(QVector2D(207,84), 315.0f, 20, TANGRAM_GREENY, false, 2.0f),
      *tr_big2 = new triangle(QVector2D(55,228), 225.0f, 20, TANGRAM_ORANGE, false, 2.0f),
      *tr_med = new triangle(QVector2D(315,333), 270.0f, 15, TANGRAM_RED, false,2.0f),
        *tr_peq1 = new triangle(QVector2D(255,352), 135.0f, 10, TANGRAM_BLUE, false, 2.0f),
      *tr_peq2 = new triangle(QVector2D(413,199), 45.0f, 10, TANGRAM_CYAN, false, 2.0f);

  trapezoid* trap = new trapezoid(QVector2D(159,407),0.0f,15,TANGRAM_DARKGREENY,false, 2.0f, 20.0f);

  rect_t* square = new rect_t(QVector2D(335,276),45.0f,10,TANGRAM_MAGENTA,false, 2.0f);

  //shape* array[] = {tr_big1,tr_big2,tr_med, tr_peq1, tr_peq2, trap, square};



  Sandbox_Scene* scene = new Sandbox_Scene(&default_sandboxmode);


  scene->addItem(tr_big1);
  scene->addItem(tr_big2);
  scene->addItem(tr_med);
  scene->addItem(tr_peq1);
  scene->addItem(tr_peq2);
  scene->addItem(trap);
  scene->addItem(square);

  scene->setSceneRect(0,0,100,100);
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);


  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setResizeAnchor(QGraphicsView::AnchorViewCenter);


  view->setScene(scene);



  sandbox_default_layout.addWidget(view, 3);

  QHBoxLayout* buttons_sandbox_default = new QHBoxLayout;


  QPushButton *selection_modemenu_btn = new QPushButton("Main Menu");
  QPushButton *save_level_btn = new QPushButton("Save Level");


  buttons_sandbox_default->addWidget(selection_modemenu_btn);
  buttons_sandbox_default->addWidget(save_level_btn);

  sandbox_default_layout.addLayout(buttons_sandbox_default, 1);

  connect(selection_modemenu_btn, SIGNAL(clicked()), this, SLOT(Show_MainPage()));
  connect(save_level_btn, SIGNAL(clicked()), this, SLOT(saveFig()));
  //connect(save_level_btn, &QPushButton::clicked, this, &Main_Window::Show_Levels);


  this->default_sandboxmode.setLayout(&sandbox_default_layout);

}





void Main_Window::Sandbox_ConstructLevel(Sandbox_Scene* scene)
{



      number_userlevels += 1;

      int n_figures = scene->get_ListFigs().count();
      int index_level = number_userlevels;

      shape** figures_level = new shape*[n_figures];


      QList<shape*> fig_list =scene->get_ListFigs();
      for(int fig_index = 0; fig_index < n_figures; fig_index++){

        double rotation_Save = fig_list[fig_index]->getRotation_shape();


        /*qDebug() << fig_list[fig_index]->get_figuret() << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().topLeft()) << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().topRight()) << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().bottomRight()) << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().bottomLeft()) << " ";*/
        fig_list[fig_index]->setRotation_shape(0);
       //fig_list[fig_index]->setRotation(0);
        /*qDebug() << fig_list[fig_index]->get_figuret() << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().topLeft()) << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().topRight()) << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().bottomRight()) << " "
           << fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().bottomLeft()) << " ";*/

        QPointF pos_topleft_ver = fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().topLeft());
        QPointF pos_bottom_left_ver = fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().bottomLeft()); //Only for Trapezoid

        float scale_shape = fig_list[fig_index]->getScaling_shape();
        float edge_shape = fig_list[fig_index]->getEdge_shape();

         if(fig_list[fig_index]->get_figuret() == shape::RECTANGLE){

             QVector2D pos(pos_topleft_ver);
             figures_level[fig_index] = new rect_t(pos, rotation_Save,scale_shape,Qt::black,true,edge_shape);
           }
         else if(fig_list[fig_index]->get_figuret() == shape::TRIANGLE){

             QVector2D pos(pos_topleft_ver);

             figures_level[fig_index] = new triangle(pos,rotation_Save,scale_shape,Qt::black,true,edge_shape);

         }else if(fig_list[fig_index]->get_figuret() == shape::TRAPEZOID){

             long double angle_in_radians = fig_list[fig_index]->getAngle_slope() * (PI/180);

             QVector2D pos;

             if(fig_list[fig_index]->getAngle_slope() > 90) pos = QVector2D(pos_bottom_left_ver.x() - sin(PI/2 - angle_in_radians)* 5*fig_list[fig_index]->getScaling_shape(), pos_topleft_ver.y());
             else pos = QVector2D(pos_bottom_left_ver.x(), pos_topleft_ver.y());
             figures_level[fig_index] = new trapezoid(pos,rotation_Save,scale_shape,Qt::black,true, edge_shape, fig_list[fig_index]->getAngle_slope());





          }
         fig_list[fig_index]->setRotation_shape(rotation_Save);

        }

      level_class* level_user = new level_class(n_figures,8,figures_level);


      level_user->writeLevel(file_save);

      QMessageBox::information(nullptr, "Guardado Exitoso", "El archivo fue guardado exitosamente");



}


int Main_Window::loadLevels()
{
  int loaded_levels = 0;

  Tangram_Levels = new level_class[NUMBER_LEVELS];
  for(int lvl = 0; lvl < NUMBER_LEVELS; lvl++){

      level_class* ref_level = new level_class(*level_class::readLevel(lvl+1));

      //level_class ref_level(*level_class::readLevel(lvl+1));
      Tangram_Levels[lvl] = ref_level;
      delete ref_level;

    }

  return loaded_levels;
}



//Emit Funcs
/*
void Main_Window::emit_numberlevel() const
{

}
*/



//Signals


//Slots
void Main_Window::Show_MainPage()
{
  this->stack->setCurrentWidget(&main_page);


}



void Main_Window::Show_Levels(int level_index)
{
  //Numero de nivel

  //level_class::readLevel(level_index);
  //level_class* my_level = new level_class;
  //level_class* ref_level = new level_class();
  /*level_class* my_level = new level_class;
  QGraphicsView* view = level.findChild<QGraphicsView*>();*/


  /*shape* array[] = {
    new triangle(QVector2D(100,-10), -90.0f, 10.0f, Qt::yellow, true,1.0f),
    new rect_t(QVector2D(200,-10), 0.0f, 10.0f, Qt::gray, true,1.0f),
    new triangle(QVector2D(200,-110), -90.0f, 10.0f, Qt::yellow, true,1.0f),
    new triangle(QVector2D(300,-160), 0.0f, 16.0f, Qt::yellow, true,1.0f)
  };*/

  //shape* array[] = {new rect_t(QVector2D(200,-10), 45.0f, 10.0f, Qt::gray, true,1.0f)};

  //QGraphicsScene* scene = my_level->get_Scene();


  QGraphicsView* view = level.findChild<QGraphicsView*>();
  view->setScene(Tangram_Levels[level_index-1].get_Scene() );



  //view->setScene(ref_level->get_Scene());
  //view->setScene(scene);

  this->stack->setCurrentWidget(&this->level);
}

void Main_Window::Show_Selection_Menu()
{


  this->stack->setCurrentWidget(&level_menu);


}


void Main_Window::Show_SandboxDefault()
{
  this->stack->setCurrentWidget(&default_sandboxmode);
}

void Main_Window::Show_UserLevel()
{
  this->stack->setCurrentWidget(&user_games);
}


void Main_Window::saveFig() const
{
  QDialog save_figDialog;
  save_figDialog.setWindowTitle("Save Game");

  save_figDialog.setGeometry(200,200,300,300);

  QVBoxLayout *save_level_lay = new QVBoxLayout();


  QLineEdit* file_name_edit = new QLineEdit();
  connect(file_name_edit, SIGNAL(textChanged(const QString&)), this, SLOT(get_NameFile(const QString&))  );


  QPushButton* save_file = new QPushButton("Save File!");
  save_file->setFixedSize(100,20);

  save_level_lay->addWidget(file_name_edit);
  save_level_lay->addWidget(save_file);


  save_figDialog.setLayout(save_level_lay);

  connect(save_file, &QPushButton::clicked, this, &Main_Window::getFigures_FromDefaultSandbox);


  save_figDialog.setModal(true);
  save_figDialog.exec();


}

void Main_Window::openLevel() const
{
  QGraphicsView *view_ = user_games.findChild<QGraphicsView*>();

  QString fileDir = QFileDialog::getOpenFileName(nullptr,"Open Level", ".", tr("JSON Files (*.json)"));
  qDebug() << QFileInfo(fileDir).fileName();

  level_class* level_user = new level_class(*level_class::readLevel(0,QFileInfo(fileDir).fileName()) );
  view_->setScene(level_user->get_Scene());

}



string Main_Window::get_NameFile(const QString& file_name)
{
  file_save = file_name;
  return file_save.toStdString();
}

void Main_Window::getFigures_FromDefaultSandbox()
{
  Sandbox_Scene *level_scene = default_sandboxmode.findChild<Sandbox_Scene*>();
  //qDebug() << level_scene->get_ListFigs();

  if(QFileInfo(file_save).suffix() != "json" || file_save == ""){
    QMessageBox::warning(nullptr, "Informacion del archivo", "El archivo debe tener extension .json y no ser vacio");
  }
  else{
  Sandbox_ConstructLevel(level_scene);
  }


}





