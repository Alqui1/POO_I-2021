#include "main_window.h"

// ======= Constructors  ======= //



Main_Window::Main_Window(string name,QWidget *parent) : QMainWindow(parent)
{


  //Set properties to Main Window
  this->setWindowTitle(name.c_str());
  this->setGeometry(50,50,1200,800);
  this->setFixedSize(1200,800);
  this->setWindowIcon(QIcon(":/tangram.png"));





  //Opening a file, to create a new game
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

        new_game << "User_1 Anonymus = " << 1 << endl;

        new_game.close();
      }
  }*/






  //Function to loadLevels
  loadLevels();

  //Create the pages
  arch_mainpage();
  arch_level_selection();
  arch_level();
  arch_defaultSandBox();
  arch_user_level();

  //Add widget to the heap of widgets
  stack->addWidget(&main_page);
  stack->addWidget(&level_menu);
  stack->addWidget(&level);
  stack->addWidget(&default_sandboxmode);
  stack->addWidget(&user_games);

  //Main_page is the first widget to be shown
  stack->setCurrentWidget(&main_page);


  //The heap of widgets is the central widget, disposed over all window
  this->setCentralWidget(stack);



}


// ======= Destructors =======//
Main_Window::~Main_Window()
{
}




// ======= CREATE WIDGETS-PAGES ======= //


//Create main page

void Main_Window::arch_mainpage()
{

  //Static variable (Main Layout),
  static QHBoxLayout hbox;






 //Main Label
  QLabel* main_label = new QLabel("Tangram");
  main_label->setFont(QFont("ADAM.CG PRO", 50, 10));
  hbox.addWidget(main_label, 0,Qt::AlignCenter);



  //Button Layout
  QVBoxLayout* vbox = new QVBoxLayout();


  //Button Construction
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

  //Button Styles
  gallery_lvl->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");
  sandbox_mode->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");
  open_user_ga->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");
  closebtn->setStyleSheet("QPushButton{background-color: rgb(215, 151, 113); color: black; font-size: 20px} QPushButton:hover{background-color:#753422; color: white} ");

  //Spacing between buttons
  vbox->setSpacing(70);

  vbox->setAlignment(Qt::AlignVCenter); //Setting alignment


  //Box of buttons
  QGroupBox* box = new QGroupBox;
  box->setFlat(true);
  box->setLayout(vbox);

  //Add box widget to Main layout
  hbox.addWidget(box);




  //Signal-Slots connections
  connect(gallery_lvl, SIGNAL(clicked()), this, SLOT(Show_Selection_Menu() ));
  connect(sandbox_mode,SIGNAL(clicked()), this, SLOT(Show_SandboxDefault() )  );
  connect(open_user_ga, SIGNAL(clicked()), this, SLOT(Show_UserLevel())  );
  connect(closebtn, &QPushButton::clicked, this, &Main_Window::close);



  //Set Layout to Widget
  this->main_page.setStyleSheet("background-color: white;");
  this->main_page.setLayout(&hbox);
}





//Level selection page
void Main_Window::arch_level_selection()
{

  //Static variable (Level selection layout). A Grid layout
  static QGridLayout grid_levels;
  grid_levels.setHorizontalSpacing(50); //Spacing between levels button (Horizontal)




  //Label "Gallery Level"
  QLabel* text = new QLabel("Gallery Level");
  text->setFixedHeight(150);
  text->setFont(QFont("ADAM.CG PRO", 50, 10));
  text->setStyleSheet("color: black;");
  grid_levels.addWidget(text, 0,0,1,4, Qt::AlignHCenter); //Add label to Grid. It has a rowSpan=1 and columnSpan=4




  //Create buttons using a for. j is the row
  for(int i = 0, j = 1; i<NUMBER_LEVELS;i++){

      //String with level name
      QString level;
      level = QString("Level %1").arg(i+1);

      //Level button, class PushButton_Menu
      PushButton_Menu *push = new PushButton_Menu(level);
      push->setFixedSize(200,200);

      //Level no available
      if(i+1 > index_currentLevel){
        push->setDisabled(true);
        push->setStyleSheet("QPushButton{background-color: gray; color: white; font-size: 20px}");
        push->setIcon(QPixmap(":/lock.png"));
      }else if(i+1 == index_currentLevel){
          push->setStyleSheet("QPushButton{background-color: black; color: white; font-size: 20px} QPushButton:pressed{background-color: white; color: black}");
      }else{

          push->setStyleSheet("QPushButton{background-color: green; color: white; font-size: 20px} QPushButton:pressed{background-color: white; color: black}");
          push->setIcon(QPixmap(":/corona.png"));
        }

      //Append the button to grid.
      grid_levels.addWidget(push,j, i%4);

      if(i%4 == 3) j++;

      //Connect SIGNALS-SLOTS
      connect(push, &PushButton_Menu::clicked, push,&PushButton_Menu::emit_level);
      connect(push, SIGNAL(file_name(int)), this, SLOT(Show_Levels(int)));
    }



  //Back to Menu button
  QPushButton* return_menu= new QPushButton("Return Menu!");
  return_menu->setFixedSize(70,40);
  grid_levels.addWidget(return_menu, 3,0, Qt::AlignLeft);
  connect(return_menu, SIGNAL(clicked()),this, SLOT(Show_MainPage()) );




  //Add Grid Layout to Widget Level_menu
  this->level_menu.setStyleSheet("background-color: white;");
  this->level_menu.setLayout(&grid_levels);
}




//Levels page
void Main_Window::arch_level()
{


  //Static Variable Main Level layout
  static QVBoxLayout level_layout(this);

  //QGraphicsView, to view the scene of level
  QGraphicsView *view = new QGraphicsView();
  //Properties for unexpected behaviour
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setResizeAnchor(QGraphicsView::AnchorViewCenter);

  //Add view to main level layout
  level_layout.addWidget(view, 3);

  //Return menu button
  QPushButton *push1 = new QPushButton("Come back to Menu!");
  level_layout.addWidget(push1,1);

  //Connection SIGNAL-SLOT to return to menu
  connect(push1, SIGNAL(clicked()), this, SLOT(Show_Selection_Menu()));

  //Add level_layout to widget level
  this->level.setLayout(&level_layout);

}


//User level page, to open user's levels.
void Main_Window::arch_user_level()
{

  //Static variable (User level layout)
  static QVBoxLayout uslevel_layout(this);

  //View, to see scene.
  QGraphicsView *view = new QGraphicsView();
  //Properties to QGraphicsView
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setResizeAnchor(QGraphicsView::AnchorViewCenter);
  //Add view to User level layout
  uslevel_layout.addWidget(view, 3);


  //Buttons layout sandbox (Return menu / Open level)
  QHBoxLayout* buttons_sandbox_default = new QHBoxLayout;

  //Buttons
  QPushButton *selection_modemenu_btn = new QPushButton("Main Menu");
  QPushButton *open_level = new QPushButton("Open Level");
  buttons_sandbox_default->addWidget(selection_modemenu_btn);
  buttons_sandbox_default->addWidget(open_level);

  //Add layout to User_level layout
  uslevel_layout.addLayout(buttons_sandbox_default, 1);

  //Connection between buttons and functions
  connect(selection_modemenu_btn, SIGNAL(clicked()), this, SLOT(Show_MainPage()));
  connect(open_level, SIGNAL(clicked()), this, SLOT(openLevel()));

  //Add layout to user_games widgets
  this->user_games.setLayout(&uslevel_layout);

}



//Sandbox mode page
void Main_Window::arch_defaultSandBox(){

  //Static variable (Sandbox layout)
  static QVBoxLayout sandbox_default_layout(this);

  //View to scene.
  QGraphicsView *view = new QGraphicsView();


  //Figure on canvas, a square. These figures can be moved to create our levels.
  triangle *tr_big1 = new triangle(QVector2D(207,84), 315.0f, 20, TANGRAM_GREENY, false, 2.0f),
      *tr_big2 = new triangle(QVector2D(55,228), 225.0f, 20, TANGRAM_ORANGE, false, 2.0f),
      *tr_med = new triangle(QVector2D(315,333), 270.0f, 15, TANGRAM_RED, false,2.0f),
        *tr_peq1 = new triangle(QVector2D(255,352), 135.0f, 10, TANGRAM_BLUE, false, 2.0f),
      *tr_peq2 = new triangle(QVector2D(413,199), 45.0f, 10, TANGRAM_CYAN, false, 2.0f);
  trapezoid* trap = new trapezoid(QVector2D(159,407),0.0f,15,TANGRAM_DARKGREENY,false, 2.0f, 20.0f);
  rect_t* square = new rect_t(QVector2D(335,276),45.0f,10,TANGRAM_MAGENTA,false, 2.0f);

  //Scene of sandbox. Belong to Sandbox_Scene class
  Sandbox_Scene* scene = new Sandbox_Scene(&default_sandboxmode);
  //Add figures to scene
  scene->addItem(tr_big1);
  scene->addItem(tr_big2);
  scene->addItem(tr_med);
  scene->addItem(tr_peq1);
  scene->addItem(tr_peq2);
  scene->addItem(trap);
  scene->addItem(square);
  scene->setSceneRect(0,0,100,100);
  //View properties
  view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setResizeAnchor(QGraphicsView::AnchorViewCenter);
  //Set scene to view
  view->setScene(scene);

  //Add view to sandbox_default layout
  sandbox_default_layout.addWidget(view, 3);


  //Buttons layout (Return menu/Save level)
  QHBoxLayout* buttons_sandbox_default = new QHBoxLayout;
  //Buttons
  QPushButton *selection_modemenu_btn = new QPushButton("Main Menu");
  QPushButton *save_level_btn = new QPushButton("Save Level");
  buttons_sandbox_default->addWidget(selection_modemenu_btn);
  buttons_sandbox_default->addWidget(save_level_btn);
  //Add Button layout to sandbox_default
  sandbox_default_layout.addLayout(buttons_sandbox_default, 1);


  //Connection SIGNAL-SLOT of buttons to it's function
  connect(selection_modemenu_btn, SIGNAL(clicked()), this, SLOT(Show_MainPage()));
  connect(save_level_btn, SIGNAL(clicked()), this, SLOT(saveFig()));

  //Set layout to Main Widget
  this->default_sandboxmode.setLayout(&sandbox_default_layout);

}













// ======= Other functions ======= //



// Build Level created on sanbox
void Main_Window::Sandbox_ConstructLevel(Sandbox_Scene* scene)
{

      number_userlevels += 1;

      //Get properties to create level
      int n_figures = scene->get_ListFigs().count(); //get_ListFigs method from SandBox_Scene
      int index_level = number_userlevels;

      //Array of pointers to shape (Polymorphism, shape is an abstract class)
      shape** figures_level = new shape*[n_figures];

      //QList of figures in the scene
      QList<shape*> fig_list =scene->get_ListFigs();


      //Add figures to figures_level
      for(int fig_index = 0; fig_index < n_figures; fig_index++){

        //Save current rotation
        double rotation_Save = fig_list[fig_index]->getRotation_shape();

        //Set a rotation to the shape, to get points.
        fig_list[fig_index]->setRotation_shape(0);

        QPointF pos_topleft_ver = fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().topLeft()); //Get
        QPointF pos_bottom_left_ver = fig_list[fig_index]->mapToScene( fig_list[fig_index]->boundingRect().bottomLeft()); //Only for Trapezoid, correction

        //Another properties
        float scale_shape = fig_list[fig_index]->getScaling_shape();
        float edge_shape = fig_list[fig_index]->getEdge_shape();

        //Build figures and append to the array
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

      //Create level
      level_class* level_user = new level_class(n_figures,index_level,figures_level);

      //Serialize level
      level_user->writeLevel(file_save);


      //QMessagebox when the serialize was successful
      QMessageBox::information(nullptr, "Guardado Exitoso", "El archivo fue guardado exitosamente");



}


//Load levels
int Main_Window::loadLevels()
{
  int loaded_levels = 0;

  Tangram_Levels = new level_class[NUMBER_LEVELS];
  for(int lvl = 0; lvl < NUMBER_LEVELS; lvl++){

      //Build levels
      level_class* ref_level = new level_class(*level_class::readLevel(lvl+1));

      //Append levels to array
      Tangram_Levels[lvl] = ref_level;

      //Delete level to prevent a waste in memory
      delete ref_level;

      loaded_levels++;
    }


  return loaded_levels;
}






// ======= SIGNALS ======= //












// ======= SLOTS ======= //



void Main_Window::Show_MainPage()
{
  this->stack->setCurrentWidget(&main_page);

}



void Main_Window::Show_Levels(int level_index)
{


  QGraphicsView* view = level.findChild<QGraphicsView*>();
  view->setScene(Tangram_Levels[level_index-1].get_Scene() );

  this->stack->setCurrentWidget(&this->level);
}

void Main_Window::Show_Selection_Menu()
{

  if(Tangram_Levels[index_currentLevel-1].get_IsTangramComp()){
    index_currentLevel+=1;
    arch_level_selection();
    }



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

//Save figure created on sandbox
void Main_Window::saveFig() const
{
  //File dialog to create level
  QDialog save_figDialog;
  save_figDialog.setWindowTitle("Save Game");
  save_figDialog.setGeometry(200,200,300,300);

  //Dialog layout
  QVBoxLayout *save_level_lay = new QVBoxLayout();

  //File line edit
  QLineEdit* file_name_edit = new QLineEdit();
  //Button
  QPushButton* save_file = new QPushButton("Save File!");
  save_file->setFixedSize(100,20);

  //Apend widget to layout
  save_level_lay->addWidget(file_name_edit);
  save_level_lay->addWidget(save_file);

  //Set layout to dialog
  save_figDialog.setLayout(save_level_lay);

  //Connect SIGNAL-SLOT
  connect(file_name_edit, SIGNAL(textChanged(const QString&)), this, SLOT(get_NameFile(const QString&))  );
  connect(save_file, &QPushButton::clicked, this, &Main_Window::getFigures_FromDefaultSandbox);

  //setModal, to display this window and set it as main window while we save the game
  save_figDialog.setModal(true);
  save_figDialog.exec();


}

//Open level
void Main_Window::openLevel() const
{
  //Open level
  QGraphicsView *view_ = user_games.findChild<QGraphicsView*>();

  //Get fileDir, and get the file name
  QString fileDir = QFileDialog::getOpenFileName(nullptr,"Open Level", ".", tr("JSON Files (*.json)"));

  //Create level
  level_class* level_user = new level_class(*level_class::readLevel(0,QFileInfo(fileDir).fileName()) );
  view_->setScene(level_user->get_Scene());

}


//Get and set file name of opened file, while LineEdit is changed
string Main_Window::get_NameFile(const QString& file_name)
{
  file_save = file_name;
  return file_save.toStdString();
}

//Get figures from the sandbox, to build level
void Main_Window::getFigures_FromDefaultSandbox()
{
  Sandbox_Scene *level_scene = default_sandboxmode.findChild<Sandbox_Scene*>();

  //If file name is empty or has a file extension distinct to .json, we cannot open the file
  if(QFileInfo(file_save).suffix() != "json" || file_save == ""){
    QMessageBox::warning(nullptr, "Informacion del archivo", "El archivo debe tener extension .json y no ser vacio");
  }
  else{
    Sandbox_ConstructLevel(level_scene);
  }

}





