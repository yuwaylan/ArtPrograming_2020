//
//  chesses.cpp
//  Art_programing_final_proj
//
//  Created by ChengHanYU on 2021/1/8.
//


/*
King =====:(i,j+1) (i+1,j) (i,j-1) (i-1,j) (i+1,j+1) (i+1,j-1) (i-1,j+1) (i-1,j-1)
Queen ====:(i,j+n) (i+n,j) (i,j-n) (i-n,j) (i+n,j+n) (i+n,j-n) (i-n,j+n) (i-n,j-n)
Bishop ===:(i+n,j+n) (i+n,j-n) (i-n,j+n) (i-n,j-n)
Knight ===:(i+2,j+1) (i+2,j-1) (i-2,j+1) (i-2,j-1) (i+1,j+2) (i-1,j+2) (i+1,j-2) (i-1,j-2)
Rook =====:(i+n,j) (i-n,j) (i,j+n) (i,j-n)
Pawn =====:if(step==1):(i,j+2) (i,j+1)
           else:(i,j+1)
           if can eat:(i+1,j+1) (i-1,j+1)
*/

struct step
{
     /*
      dest_has_chess ?(isme ? false : ( high_grade ? true : false )) : ( high_grade ? true : false )
      */
    bool moveable;
    //從最遠開始算
    int length;
    int grade;
};

class chess
{
public:
    void generate_steps() {};
    struct step steps[8];
protected:
    int piece;
    
};


class King : public chess
{
public:
    King(int peice_x, int peice_y){

    };
    int count_step = 8;
    int x;
    int y;
    
    
};
 
