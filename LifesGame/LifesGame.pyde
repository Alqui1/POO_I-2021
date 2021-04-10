import random
import time

width_w = 700
height_w = 700

n_columns = 0
n_rows = 0


_cells_alive = int(random.randrange(200, 350,1))


cellsTable = []


class Celulas: #CLASE CELULA, ES MAS FACIL TRATARLA COMO UN OBJETO
    
    def __init__(self, posx, posy, filler_c):

        self.posx = posx
        self.posy = posy
        self.filler_c = filler_c
        #self.is_alive_ = self.is_alive()
        
        self.vecinas_vivas = 0
    
    def is_alive(self):
        if(self.filler_c == 100):
            return False
        elif(self.filler_c == 255):
            return True
        
        
    def draw_itself(self):
        fill(self.filler_c)
        rect(self.posx,self.posy,20,20)
        
    def change_fill(self, filler_a):
        self.filler_c = filler_a
        self.draw_itself()
        

        

def do_table(): #HACER TABLA
    
    global width_w
    global height_w
    
    global n_columns
    global n_rows
    
    

    Table_Array = []
   # n_columns = 0
    for i in range(0, width_w - 20, 20):
        #n_rows = 0
        row = []
        for j in range(0, height_w - 20, 20):
            j = Celulas(10+i,10+j,100)
            j.draw_itself()
            
            row.append(j)
            
        n_rows += 1    
        n_columns += 1
        Table_Array.append(row)
        
    
    print(str(n_rows) + " : " + str(n_columns))
    
    return Table_Array


def set_Cells(arr): #Algoritmo Pseudoaleatorio para escoger celulas de forma aleatoria
    
    global _cells_alive
    cnt = 0

    
    while(cnt < _cells_alive):
         i = int(random.randrange(0, n_rows))
         j = int(random.randrange(0, n_columns))

         if(arr[i][j].is_alive() != True):
             arr[i][j].change_fill(255)
             cnt += 1

         else:
             pass
             

    
    

    
    
            
             
def Games_Life(arr): #EL JUEGO, SU PARAMETRO ES UNA TABLA
    
    
    #Esquinas


    c_sup_izq = 0
    if(arr[0][1].is_alive() == True): c_sup_izq += 1
    if(arr[1][0].is_alive() == True): c_sup_izq += 1
    if(arr[1][1].is_alive() == True): c_sup_izq += 1
    arr[0][0].vecinas_vivas = c_sup_izq

    #print(arr[0][0].vecinas_vivas)

    c_sup_der = 0
    if(arr[n_columns-2][0].is_alive() == True): c_sup_der += 1
    if(arr[n_columns-1][1].is_alive() == True): c_sup_der += 1
    if(arr[n_columns-2][1].is_alive() == True): c_sup_der += 1
    arr[n_columns-1][0].vecinas_vivas = c_sup_der

    #print(arr[n_columns-1][0].vecinas_vivas)
    

    

    c_inf_izq = 0
    if(arr[0][n_rows-2].is_alive() == True): c_inf_izq += 1
    if(arr[1][n_rows-1].is_alive() == True): c_inf_izq += 1
    if(arr[1][n_rows-2].is_alive() == True): c_inf_izq += 1
    arr[0][n_rows-1].vecinas_vivas = c_inf_izq
    #print(arr[0][n_rows-1].vecinas_vivas)

    c_inf_der = 0
    if(arr[n_columns-1][n_rows-2].is_alive() == True): c_inf_der += 1
    if(arr[n_columns-2][n_rows-1].is_alive() == True): c_inf_der += 1
    if(arr[n_columns-2][n_rows-2].is_alive() == True): c_inf_der += 1
    arr[n_columns-1][n_rows-1].vecinas_vivas = c_inf_der

    #print( arr[n_columns-1][n_rows-1].vecinas_vivas)

    #Laterales
    
    for i in range(1, n_rows-1,1):
        
        c_lives_cells = 0
        if(arr[0][i-1].is_alive() == True): c_lives_cells += 1
        if(arr[1][i-1].is_alive() == True): c_lives_cells += 1
        if(arr[1][i].is_alive() == True): c_lives_cells += 1
        if(arr[1][i+1].is_alive() == True): c_lives_cells += 1
        if(arr[0][i+1].is_alive() == True): c_lives_cells += 1
        arr[0][i].vecinas_vivas = c_lives_cells
    

        
    println("")
        
    for i in range(1, n_rows-1,1):
        
        c_lives_cells = 0
        if(arr[n_columns-1][i-1].is_alive() == True): c_lives_cells += 1
        if(arr[n_columns-2][i-1].is_alive() == True): c_lives_cells += 1
        if(arr[n_columns-2][i].is_alive() == True): c_lives_cells += 1
        if(arr[n_columns-2][i+1].is_alive() == True): c_lives_cells += 1
        if(arr[n_columns-1][i+1].is_alive() == True): c_lives_cells += 1
        arr[n_columns-1][i].vecinas_vivas = c_lives_cells
    
    
        
    for j in range(1, n_columns-1,1):
        
        c_lives_cells = 0
        if(arr[j-1][0].is_alive() == True): c_lives_cells += 1
        if(arr[j-1][1].is_alive() == True): c_lives_cells += 1
        if(arr[j][1].is_alive() == True): c_lives_cells += 1
        if(arr[j+1][1].is_alive() == True): c_lives_cells += 1
        if(arr[j+1][0].is_alive() == True): c_lives_cells += 1
        arr[j][0].vecinas_vivas = c_lives_cells
    

        
    for j in range(1, n_columns-1,1):
        
        c_lives_cells = 0
        if(arr[j-1][n_rows-1].is_alive() == True): c_lives_cells += 1
        if(arr[j-1][n_rows-2].is_alive() == True): c_lives_cells += 1
        if(arr[j][n_rows-2].is_alive() == True): c_lives_cells += 1
        if(arr[j+1][n_rows-2].is_alive() == True): c_lives_cells += 1
        if(arr[j+1][n_rows-1].is_alive() == True): c_lives_cells += 1
        arr[j][n_rows-1].vecinas_vivas = c_lives_cells
    


    #DEMAS


    
    for i in range(1, n_rows-1,1):
        for j in range(1, n_columns-1,1):
            c_lives = 0
            if(arr[j-1][i-1].is_alive() == True): c_lives += 1
            if(arr[j-1][i].is_alive() == True): c_lives += 1
            if(arr[j-1][i+1].is_alive() == True): c_lives += 1
            
            if(arr[j+1][i-1].is_alive() == True): c_lives += 1
            if(arr[j+1][i].is_alive() == True): c_lives += 1
            if(arr[j+1][i+1].is_alive() == True): c_lives += 1
            
            if(arr[j][i-1].is_alive() == True): c_lives += 1
            if(arr[j][i+1].is_alive() == True): c_lives += 1

            
            arr[j][i].vecinas_vivas = c_lives
            
            
            
            
            
    
    #JUEGO EN SI        
    
    
    for i in range(1, n_rows,1):
        for j in range(1, n_columns,1):
            
            if(arr[j][i].is_alive() == True):
                
                if(arr[j][i].vecinas_vivas == 2 or arr[j][i].vecinas_vivas == 3): pass
                else: arr[j][i].change_fill(100)
                
            elif(arr[j][i].is_alive() == False):
                if(arr[j][i].vecinas_vivas == 3): arr[j][i].change_fill(255)
                else: pass
    
def table_Disposal(): #DISPOSICION AUTOMATICA, PSEUDOALEATORIA
    global cellsTable
    global n_columns
    global n_rows
    
    n_rows = 0
    n_columns = 0
    cellsTable=[]
    cellsTable = do_table()
    set_Cells(cellsTable)

def manual_Disposal(): #DISPOSICION MANUAL
    global cellsTable
    global n_columns
    global n_rows
    
    n_rows = 0
    n_columns = 0
    cellsTable=[]
    cellsTable = do_table()

    
        
def MenuStarting(): #CREAR MENU
    f = createFont("Arial",16)
    textFont(f,30)
    text("Game's Life by Conway",20,100)
    
    textFont(f,25)
    text("David Alquichire",20,150)
    textFont(f,25)
    text("Object Oriented Programming, 2020-1",20,200)
    
    textFont(f,20)
    text("Press keys to start:\n1: Random layout\n2: Manual Layout\n3: Menu\n4: Exit",20,250)
    
    text("Controls:\n-Press + for more speed\n-Press - for getting down speed\n-Press p to pause\n-Press s to start in Manual Mode or\nresume the game\n\nIn Manual Mode: \n-Press + for getting more click scope\n-Press - for reduce click scope",300, 250)
    
    
    

def setup():
        
        size(width_w, height_w)
        background(0,0,0)
        strokeWeight(2)
        
        f = MenuStarting()   
        
         
_GENERATE_MAP = 0
_DONT_GENERATE_YET = 0
FRAMES_RATES = 6

RANDOM_MOMENT = 0

def draw():
    
    frameRate(FRAMES_RATES)
    if _GENERATE_MAP == 1:
        Games_Life(cellsTable)
    
RATIO = 1
def mousePressed(): #SELECCIONAR EN MODO MANUAL LAS FICHAS
    if RANDOM_MOMENT == 1:
        if( (mouseX >= 20 and mouseX <= width_w - 20) and (mouseY >= 20 and mouseY <= height_w - 20)):
            for i in range(0, n_rows):
                for j in range(0, n_columns):
                    if( (mouseX <=   cellsTable[i][j].posx + 20*RATIO and mouseX >   cellsTable[i][j].posx) and (mouseY <=   cellsTable[i][j].posy + 20*RATIO and mouseY >   cellsTable[i][j].posy)):
                        
                        if(not(cellsTable[i][j].is_alive())): cellsTable[i][j].change_fill(255)
                        else: cellsTable[i][j].change_fill(100)
                        
                        
            

def keyPressed(): #INTERACCION TECLADO
    global _GENERATE_MAP
    global _DONT_GENERATE_YET
    global FRAMES_RATES
    global RANDOM_MOMENT
    global RATIO
    
    if key == '1': #DISPOSICION AUTOMATICA
        RANDOM_MOMENT = 0
        if _DONT_GENERATE_YET == 0:
            table_Disposal()
            _GENERATE_MAP = 1
            _DONT_GENERATE_YET = 1

    elif key == '2': #DISPOSICION MANUAL
        _GENERATE_MAP = 0
        _DONT_GENERATE_YET = 0
        RANDOM_MOMENT = 1
        manual_Disposal()
        
    elif key == '3': #MENU PRINCIPAL
        _GENERATE_MAP = 0
        _DONT_GENERATE_YET = 0
        clear()
        MenuStarting()
        RANDOM_MOMENT = 0
    
    elif key == '4': #SALIR
        exit()
    
    elif key == "p": #PAUSA
        noLoop()
    
    elif key == "s": #COMENZAR O REANUDAR
        if RANDOM_MOMENT == 1:
            _GENERATE_MAP = 1
            _DONT_GENERATE_YET = 1
            RANDOM_MOMENT = 0
        loop()
    
    elif key == "+":  #AUMENTAR RADIO O VELOCIDAD
        if _GENERATE_MAP == 1:
            FRAMES_RATES *= 2
        elif RANDOM_MOMENT == 1:
            RATIO += 1
            
    
    elif key == "-": #DISMINUIR RADIO O VELOCIDAD
        if FRAMES_RATES >= 2 and _GENERATE_MAP == 1:
            FRAMES_RATES /= 2    

        elif RANDOM_MOMENT == 1:
            if(RATIO > 1): RATIO -= 1
            

  
