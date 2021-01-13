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
	int id;
	int shift_me;
    int dest_x;
    int dest_y;
    int grade=0;
    bool many_steps ;
    struct Node* b;

    struct step steps[8];
    void generate_steps() {};
    int generate_grade(int count_steps){


		return 0;};
//    int get_X(){return 0;};
//    int get_Y(){return 0;};
	bool is_that_chess_me(int id) {
		
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
		return 0;
	}
    int hi_grade(int op_id,int dx,int dy){
		//如果 id != 0 算一下吃了值不值錢
		return 110;
	};
    
    //把go合再一起寫了 因為有的可以走很多步 所以到時候可以用地回
    /*int* go(bool many, int steps, int srcX, int srcY, int method){static int p[2]={0};if(!many){}return p;};*/

    step go_F(int steps){
		static struct step s;
		if (me > 1) {
			steps = -steps;
		}
		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y;
		s.dest[0] = x;
		if ((y + steps < 8 && y + steps >= 0)) {
			s.dest[1] = y + steps;
			
			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[1] = y;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[1] = y;
			s.moveable = false;
			/*if (steps > 1) {
				// 有上一步
				//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
			}
			else {
				//沒有上一步
				return s;
			}*/
		}

		s.length = abs(x - s.dest[0]);
		return s;
	};

	step go_B( int steps) {
		static struct step s;
		if (me < 1) {
			steps = -steps;
		}
		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y; 
		s.dest[0] = x;
		if ((y + steps < 8 && y + steps >= 0)) {
			s.dest[1] = y + steps;

			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[1] = y;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[1] = y;
			s.moveable = false;
		}
		s.length = abs(x - s.dest[0]);
		return s;
	};


	step go_L(int steps) {
		static struct step s;
		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y;
		s.dest[1] = y;
		if ((x - steps < 8 && x - steps >= 0)) {
			s.dest[0] = x - steps;

			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[0] = x;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[0] = x;
			s.moveable = false;
		}
		s.length = steps;
		return s;
	};

	step go_R(int steps) {
		static struct step s;
		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y;
		s.dest[1] = y;
		if ((x + steps < 8 && x + steps >= 0)) {
			s.dest[0] = x + steps;

			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[0] = x;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[0] = x;
			s.moveable = false;
		}
		return s;
	};

    
	step go_FR(int steps ) {
		static struct step s;
		int step_F = steps;
		if (me > 1) {
			step_F = -steps;
		}
		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y;

		// x+step y+step_f 
		if ((x + steps < 8 && x + steps >= 0)&& ((y + step_F < 8 && x + step_F >= 0))) {
			s.dest[0] = x + steps;
			s.dest[1] = x + step_F;

			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[0] = x;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[0] = x;
			s.dest[1] = y;
			s.moveable = false;
		}
		return s;
	};





	step go_FL(int steps) {
		static struct step s;
		int step_F = steps;
		if (me > 1) {
			step_F = -steps;
		}
		steps = -steps;

		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y;

		// x+step y+step_f 
		if ((x + steps < 8 && x + steps >= 0) && ((y + step_F < 8 && y + step_F >= 0))) {
			s.dest[0] = x + steps;
			s.dest[1] = y + step_F;

			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[0] = x;
					s.dest[1] = y;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[0] = x;
			s.dest[1] = y;
			s.moveable = false;
		}
		return s;
	};
    

	step go_BR(int steps) {
		static struct step s;
		int step_F = steps;
		if (me < 1) {
			step_F = -steps;
		}
		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y;

		// x+step y+step_f 
		if ((x + steps < 8 && x + steps >= 0) && ((y + step_F < 8 && y + step_F >= 0))) {
			s.dest[0] = x + steps;
			s.dest[1] = y + step_F;

			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[0] = x;
					s.dest[1] = y;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[0] = x;
			s.dest[1] = y;
			s.moveable = false;
		}
		return s;
	};


	step go_BL( int steps) {
		static struct step s;
		int step_F = steps;
		if (me < 1) {
			step_F = -steps;
		}
		steps = -steps;

		s.grade = 0;
		s.src[0] = x;
		s.src[1] = y;

		// x+step y+step_f 
		if ((x + steps < 8 && x + steps >= 0) && ((y + step_F < 8 && y + step_F >= 0))) {
			s.dest[0] = x + steps;
			s.dest[1] = y + step_F;

			int tmp_id = dest_has_chess(s.dest[0], s.dest[1]);
			//有棋子?
			if (tmp_id >= 0) {
				//是我?
				if (is_that_chess_me(tmp_id)) {
					s.dest[0] = x;
					s.dest[1] = y;
					s.moveable = false;
					//return go_F(s.moveable, steps - 1, s.dest[0], s.dest[1]);
				}
			}
			// 沒有棋子 || 不是我 =>算分數
			s.grade = hi_grade(tmp_id, s.dest[0], s.dest[1]);
			s.moveable = true;
		}
		else {
			//界外
			s.dest[0] = x;
			s.dest[1] = y;
			s.moveable = false;
		}
		return s;
	};
    
    
};

class King : public chess
{
    int count_step = 8;
    int step_length=1;
	int grade_Arr[4] = { 0 };
public:
    King(int peice_x, int peice_y, int who, struct Node* node){
		shift_me = (who > 1 ? 10 : 0);
		id = 1 + shift_me;
        x = peice_x;
        y = peice_y;
		b = node;
		me = who;
        many_steps=false;

		std ::cout << "King build \t";
    };
    void generate_steps(){
		steps[0] = go_F(1);
		steps[1] = go_B(1);
		steps[2] = go_L(1);
		steps[3] = go_R(1);
		
		grade = generate_grade(4);
    }
	
   
    
    
};

class Queen : public chess
{
    int count_step = 8;
public:
    Queen(int peice_x, int peice_y, int who, struct Node* node){
		shift_me = (who > 1 ? 10 : 0);
		id = 2 + shift_me;
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
		shift_me = (who > 1 ? 10 : 0);
		id = 3 + shift_me;
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
		shift_me = (who > 1 ? 10 : 0);
		id = 4 + shift_me;
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
            if(temp<=0){
                if(is_that_chess_me(temp)){
                    steps[i].moveable =false;
                }else{
					steps[i].moveable = true;
					steps[i].grade = hi_grade(temp , steps[i].dest[0], steps[i].dest[1]);
                }// is not me end
            }else{
                // has no chess
                steps[i].moveable =true;
				steps[i].grade = hi_grade(temp, steps[i].dest[0], steps[i].dest[1]);
            }
            
        }



    };

    
    
    
};
class Rook : public chess
{
    int count_step = 4;
public:
    Rook(int peice_x, int peice_y, int who, struct Node* node){
		shift_me = (who > 1 ? 10 : 0);
		id = 5 + shift_me;
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
		shift_me = (who > 1 ? 10 : 0);
		id = 6 + shift_me;
		x = peice_x;
		y = peice_y;
		b = node;
		me = who;
    };
    
    
    
};

 
