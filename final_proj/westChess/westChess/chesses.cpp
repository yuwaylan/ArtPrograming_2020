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

struct Piece
{
	int id;
	int x;
	int y;
};

struct Node
{
	struct Piece piece;
	struct Node* pNext;
};


struct step
{
     /*
      dest_has_chess ?(isme ? false : ( high_grade ? true : false )) : ( high_grade ? true : false )
      */
    bool moveable;
//    從最遠開始算
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
    bool many_steps ;
    struct Node* b;

    struct step steps[8];
    void generate_steps() {};
    int generate_grade(){return 0;};
//    int get_X(){return 0;};
//    int get_Y(){return 0;};
	bool is_that_chess_me(int id) {
		int shift_me = (me > 1 ? 10 : 0);
		if (id - shift_me > 0 && id - shift_me < 10) { return true; }
		else return false;
	}
	int dest_has_chess(int dx, int dy) {
		struct Node* temp;
		temp = b->pNext;
		while (temp)
		{
			if (temp->piece.x == dx && temp->piece.x == dy)
			{
				return temp->piece.id;
			}
			temp = temp->pNext;
		}
		return 999;
	}
    int hi_grade(){

		return 0;
	};
    
    //把go合再一起寫了 因為有的可以走很多步 所以到時候可以用地回
    /*int* go(bool many, int steps, int srcX, int srcY, int method){static int p[2]={0};if(!many){}return p;};*/

    int* go_F(bool many, int steps, int srcX, int srcY){
		static int p[2]={0}; 

		return p;
	};
    int* go_B(bool many, int steps, int srcX, int srcY) {
		static int p[2] = { 0 };
		return p;
	};
    int* go_L(bool many, int steps, int srcX, int srcY) {
		static int p[2] = { 0 };
		return p;
	};
    int* go_R(bool many, int steps, int srcX, int srcY) {
		static int p[2] = { 0 };
		return p;
	};
    int* go_FR(bool many, int steps, int srcX, int srcY) {
		static int p[2] = { 0 };
		return p;
	};
    int* go_FL(bool many, int steps, int srcX, int srcY) {
		static int p[2] = { 0 };
		return p;
	};
    int* go_BR(bool many, int steps, int srcX, int srcY) {
		static int p[2] = { 0 };
		return p;
	};
    int* go_BL(bool many, int steps, int srcX, int srcY) {
		static int p[2] = { 0 };
		return p;
	};
    
    
};

class King : public chess
{
    int count_step = 8;
    int step_length=1;
public:
    King(int peice_x, int peice_y, int who, struct Node* node){
        x = peice_x;
        y = peice_y;
		b = node;
		me = who;
        many_steps=false;
    };
    void generate_steps(){
        
    }
   
    
    
};

class Queen : public chess
{
    int count_step = 8;
public:
    Queen(int peice_x, int peice_y, int who, struct Node* node){
		x = peice_x;
		y = peice_y;
		b = node;
		me = who;
    };
    
    
    
    
    
};

class Bishop : public chess
{
    int count_step = 4;
public:
    Bishop(int peice_x, int peice_y, int who, struct Node* node){
		x = peice_x;
		y = peice_y;
		b = node;
		me = who;
    };
    
    
    
    
};
class Knight : public chess
{
    int count_step = 8;
public:
    Knight(int peice_x, int peice_y, int who, struct Node* node){
		x = peice_x;
		y = peice_y;
		b = node;
		me = who;
        many_steps=false;
    };

//    Knight =8==:(i+2,j+1) (i+2,j-1) (i-2,j+1) (i-2,j-1) (i+1,j+2) (i-1,j+2) (i+1,j-2) (i-1,j-2)
    void generate_steps() {
        steps[0].dest[0]=x+2;
        steps[0].dest[1]=y+1;
        
        steps[1].dest[0]=x+2;
        steps[1].dest[1]=y-1;
        
        steps[2].dest[0]=x-2;
        steps[2].dest[1]=y+1;
        
        steps[3].dest[0]=x-2;
        steps[3].dest[1]=y-1;
        
        steps[4].dest[0]=x+1;
        steps[4].dest[1]=y+2;
        
        steps[5].dest[0]=x-1;
        steps[5].dest[1]=y+2;
        
        steps[6].dest[0]=x+1;
        steps[6].dest[1]=y-2;
        
        steps[7].dest[0]=x-1;
        steps[7].dest[1]=y-2;
        
        for(int i=0;i<8;i++){
            steps[i].src[0]=x;
            steps[i].src[1]=y;
			int temp = dest_has_chess(steps[i].dest[0], steps[i].dest[1]);
            if(temp<100){
                if(is_that_chess_me(temp)){
                    steps[i].moveable =false;
                }else{
					steps[i].moveable = true;
					steps[i].grade = hi_grade();
                }// is not me end
            }else{
                // has no chess
                steps[i].moveable =true;
				steps[i].grade = hi_grade();
            }
            
        }



    };

    
    
    
};
class Rook : public chess
{
    int count_step = 4;
public:
    Rook(int peice_x, int peice_y, int who, struct Node* node){
		x = peice_x;
		y = peice_y;
		b = node;
		me = who;
    };
    
    
    
};
class Pawn : public chess
{
    bool can_eat = false;
    bool is_firstStep = true;
    int count_step = 2;
public:
    Pawn(int peice_x, int peice_y, int who, struct Node* node){
		x = peice_x;
		y = peice_y;
		b = node;
		me = who;
    };
    
    
    
};

 
