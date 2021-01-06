
/*
King =====:(i,j+1) (i+1,j) (i,j-1) (i-1,j) (i+1,j+1) (i+1,j-1) (i-1,j+1) (i-1,j-1)
Queen ====:(i,j+n) (i+n,j) (i,j-n) (i-n,j) (i+n,j+n) (i+n,j-n) (i-n,j+n) (i-n,j-n)
Bishop ===:(i+n,j+n) (i+n,j-n) (i-n,j+n) (i-n,j-n)
Knight ===:(i+2,j+1) (i+2,j-1) (i-2,j+1) (i-2,j-1) (i+1,j+2) (i-1,j+2) (i+1,j-2) (i-1,j-2)
Rook =====:(i+n,j) (i-n,j) (i,j+n) (i,j-n)
Pawn =====:if(step==1):(i,j+2) (i,j+1) 
		   else:(i,j+1) ¦Y:(i+1,j+1) (i-1,j+1)
*/

struct step
{
	bool moveable;
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

private:
	int count_step = 8;
	int x;
	int y;
	void generate_steps() {
		for (int i = 0; i < count_step; i++) {
			steps[i];
		}
	}
	
};
 