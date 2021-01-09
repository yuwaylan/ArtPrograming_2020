//
//  chesses.cpp
//  Art_programing_final_proj
//
//  Created by ChengHanYU on 2021/1/8.
//


/*
King =8====:(i,j+1) (i+1,j) (i,j-1) (i-1,j) (i+1,j+1) (i+1,j-1) (i-1,j+1) (i-1,j-1)
Queen =8===:(i,j+n) (i+n,j) (i,j-n) (i-n,j) (i+n,j+n) (i+n,j-n) (i-n,j+n) (i-n,j-n)
Bishop =4==:(i+n,j+n) (i+n,j-n) (i-n,j+n) (i-n,j-n)
Knight =8==:(i+2,j+1) (i+2,j-1) (i-2,j+1) (i-2,j-1) (i+1,j+2) (i-1,j+2) (i+1,j-2) (i-1,j-2)
Rook =4====:(i+n,j) (i-n,j) (i,j+n) (i,j-n)
Pawn =2/1/2:if(step==1):(i,j+2) (i,j+1)
           else:(i,j+1)
           if can eat:(i+1,j+1) (i-1,j+1)
*/
#include <iostream>



struct step
{
     /*
      dest_has_chess ?(isme ? false : ( high_grade ? true : false )) : ( high_grade ? true : false )
      */
    bool moveable;
    //從最遠開始算
    int length;
    int grade;
    
    int src[2];
    int dest[2];
};


class chess
{
public:
    const int border=8;//要小於8
    int x;
    int y;
    int me;
    int dest_x;
    int dest_y;
    int grade=0;
    bool many_steps = true;

    struct step steps[8];
    void generate_steps() {};
    int generate_grade(){return 0;};
//    int get_X(){return 0;};
//    int get_Y(){return 0;};
    bool dest_has_chess(){return false;}
    bool is_that_chess_me(){return false;}
    int hi_grade(){return 0;};
    int* go_F(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    int* go_B(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    int* go_L(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    int* go_R(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    int* go_FR(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    int* go_FL(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    int* go_BR(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    int* go_BL(bool many, int steps, int srcX, int srcY){static int p[2]={0}; return p;};
    //馬沒寫
    
    
};

class King : public chess
{
    int count_step = 8;
    int step_length=1;
public:
    King(int peice_x, int peice_y, int who){
        x = peice_x;
        y = peice_y;
        many_steps=false;
    };
    void generate_steps(){
        
    }
   
    
    
};

class Queen : public chess
{
    int count_step = 8;
public:
    Queen(int peice_x, int peice_y, int who){
        x = peice_x;
        y = peice_y;
    };
    
    
    
    
    
};

class Bishop : public chess
{
    int count_step = 4;
public:
    Bishop(int peice_x, int peice_y, int who){
        x = peice_x;
        y = peice_y;
    };
    
    
    
    
};
class Knight : public chess
{
    int count_step = 8;
public:
    Knight(int peice_x, int peice_y, int who){
        x = peice_x;
        y = peice_y;
        many_steps=false;
    };

    
    
    
};
class Rook : public chess
{
    int count_step = 4;
public:
    Rook(int peice_x, int peice_y, int who){
        x = peice_x;
        y = peice_y;
    };
    
    
    
};
class Pawn : public chess
{
    bool can_eat = false;
    bool is_firstStep = true;
    int count_step = 2;
public:
    Pawn(int peice_x, int peice_y, int who){
        x = peice_x;
        y = peice_y;
    };
    
    
    
};

 
