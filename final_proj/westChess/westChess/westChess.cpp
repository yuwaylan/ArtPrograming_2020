
#include <iostream>
#include <fstream>
#include <string>
#include"chesses.cpp"

#define FAIL_INVALID_STEP 0
#define SUCCEED 1

#define ifdebug true

using namespace std;




string Symbol[2][7] =
{
	{ " ","Kw", "Qw", "Bw", "Nw", "Rw", "Pw" },
	{ " ","Kb", "Qb", "Bb", "Nb", "Rb", "Pb" }
};
enum { Kw = 1, Qw, Bw, Nw, Rw, Pw, Kb = 11, Qb, Bb, Nb, Rb, Pb };

int* get_Pos();
int* get_Chess();
void set_chesses(int,struct Node*);


//--------------------------------------------------------------------------

bool readPieceFromFile(ifstream& file, struct Piece& p)
{
	if (file.eof())
		return false;
	else
	{
		file >> p.id;
		file >> p.x;
		file >> p.y;
	}
	return true;
}
void writePieceToFile(ofstream& file, struct Piece p)
{
	file << p.id;
	file << " ";
	file << p.x;
	file << " ";
	file << p.y;
	file << endl;
}
string PieceSymbol(struct Piece p)
{
	return Symbol[p.id / 10][p.id % 10];
}
void showPiece(struct Piece p)
{
	cout << PieceSymbol(p) << ":" << p.x << "," << p.y << endl;

}
bool equal(struct Piece p1, struct Piece p2)
{
	return (p1.id == p2.id && p1.x == p2.x && p1.y == p2.y);
}
//--------------------------------------------------------------------------


void resetNodes(struct Node* root)
{
	struct Piece pieces[2][16][3] = {
		{ { 1, 0, 3 },{ 2, 0, 4 },{ 3, 0,2 },{ 3,0,5 },{ 4, 0,6 },{ 4, 0, 1 },{ 5, 0,0 },{ 5, 0,7 },{ 6 ,1 ,0 },
	{ 6, 1, 1 },{ 6, 1,2 },{ 6 ,1 ,3 },{ 6, 1, 4 },{ 6, 1, 5 },{ 6 ,1, 6 },{ 6,1 ,7 } },
	{ { 11, 7, 4 },{ 12, 7, 3 },{ 13, 7, 2 },{ 13, 7, 5 },{ 14, 7, 1 },{ 14, 7, 6 },{ 15, 7, 0 },{ 15, 7, 7 },
	{ 16, 6, 0 },{ 16, 6, 1 },{ 16, 6, 2 },{ 16, 6, 3 },{ 16, 6, 4 },{ 16, 6, 5 },{ 16, 6, 6 },{ 16 ,6 ,7 } }
	};
	struct Node * node = root;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 16; j++)
		{
			node->pNext = new struct Node;
			node = node->pNext;
			node->pNext = 0;
			node->piece.id = pieces[i][j]->id;
			node->piece.x = pieces[i][j]->x;
			node->piece.y = pieces[i][j]->y;
		}
}

struct Node* findNode(struct Node* root, struct Piece p)
{
	struct Node* temp;
	temp = root->pNext;
	while (temp)
	{
		if (equal(temp->piece, p)) return temp;
		temp = temp->pNext;
		// cout << temp->piece.id;
	}
	return 0;
}
struct Node* findNode(struct Node* root, int id, int x, int y)
{
	struct Piece p = { id,x,y };
	return findNode(root, p);
}
bool removeNode(struct Node* root, int id, int x, int y)
{
	//還沒辦法刪除最後一個
	struct Node* temp;
	struct Node* pre;
	pre = temp = root->pNext;

	while (temp)
	{
		if (temp->piece.id == id && temp->piece.x == x && temp->piece.y == y)
		{
			struct Node* t = temp;
            if(!pre->pNext->pNext){
                pre->pNext = 0;//應該是刪除最後一個吧？
            }else{
            pre->pNext = pre->pNext->pNext;
            delete t;
            }
			return true;
        }
		// cout << temp->piece.id;
		pre = temp;
		temp = temp->pNext;
	}
	return false;
}
bool updateNode(struct Node* root, int id, int srcX, int srcY, int destX, int destY)
{

	struct Node* p = findNode(root, id, srcX, srcY);
	if (p == 0) {
		cout << "nothing found";
		return false;
	}
	p->piece.x = destX;
	p->piece.y = destY;
	return true;
}
void showNodes(struct Node* root)
{
	struct Node* temp;
	temp = root->pNext;
	while (temp)
	{
		showPiece(temp->piece);
		temp = temp->pNext;
	}
}
void clearNodes(struct Node* root)
{
	struct Node* temp = root->pNext;
	struct Node* pre;
	pre = temp;
	while (temp->pNext)
	{
		temp = temp->pNext;
		delete pre;
		pre = temp;
	}
}
void readNodesFromFile(ifstream& file, struct Node* root)
{
	struct Piece p;
	struct Node* node = root;
	while (readPieceFromFile(file, p))
	{
		node->pNext = new struct Node;
		node = node->pNext;
		node->pNext = 0;
		node->piece = p;

	}
}
void writeNodesToFile(ofstream& file, struct Node* root)
{
	struct Node* temp;
	temp = root->pNext;
	while (temp)
	{
		writePieceToFile(file, temp->piece);
		temp = temp->pNext;
	}
}
//--------------------------------------------------------------------------
void initBoard(int board[8][8])
{
	int i;
	int j;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			board[i][j] = 0;
}
void setBoardFromNodes(int board[8][8], struct Node* root)
{
	initBoard(board);
	struct Node * temp = root->pNext;
	while (temp)
	{
		board[temp->piece.y][temp->piece.x] = temp->piece.id;
		temp = temp->pNext;
	}
}
void showBoard(int board[8][8])
{
	int i;
	int j;
	cout << " 0 1 2 3 4 5 6 7 " << endl;
	cout << " -------------------------" << endl;
	for (i = 0; i < 8; i++)
	{

		cout << i << "| ";
		for (j = 0; j < 8; j++)
		{
			cout << Symbol[board[j][i] / 10][board[j][i] % 10];
			cout << "|";
		}
		cout << endl;
		cout << " -------------------------" << endl;
	}
}
//--------------------------------------------------------------------------
void updateboardfromfile(string filename, struct Node* root)
{
	clearNodes(root);
	ifstream file;
	file.open(filename);
	readNodesFromFile(file, root);
	file.close();
}
int move(int board[8][8], struct Node* root, int srcX, int srcY, int destX, int destY)
{
	if (board[srcX][srcY] == 0) return FAIL_INVALID_STEP;
	else if (board[destX][destY] != 0)
	{
		if (board[srcX][srcY] / 10 == board[destX][destY] / 10)
			return FAIL_INVALID_STEP;
		removeNode(root, board[destX][destY], destY, destX);
	}
	updateNode(root, board[srcX][srcY], srcY, srcX, destY, destX);
	setBoardFromNodes(board, root);

	return SUCCEED;
}

//------------------------------------------------------------------------------------------------
void play(int me, string chessfile)
{
	struct Node root;
	root.pNext = 0;

	ifstream file;
	file.open(chessfile);
	readNodesFromFile(file, &root);
	file.close();

//	clearNodes(&root);
//	resetNodes(&root);

	int board[8][8];
	setBoardFromNodes(board, &root);
	showBoard(board);

	//--- decide move -----

    set_chesses(me,&root);
    int* src =get_Chess();
    int* dst =get_Pos();
    
	int srcX = src[0];
	int srcY = src[1];
	int destX = dst[0];
	int destY = dst[1];

	//-------------------------
	if (SUCCEED == move(board, &root, srcX, srcY, destX, destY))
	{
		cout << "move from (" << srcX << "," << srcY << ") to (" << destX << "," << destY << ")";
		cout << endl;
		showBoard(board);
	}
	else
		cout << "something wrong" << endl;

	ofstream ofile;
	ofile.open("text.txt");
	writeNodesToFile(ofile, &root);
	ofile.close();

	clearNodes(&root);
}

//================================================================================================


struct get_Steps{
    int best_Src_X;
    int best_Src_Y;
    int best_Dst_X;
    int best_Dst_Y;
    int best_grade;
};
int dx,dy,sx,sy;

int* get_Pos(){
    static int  r[2]={dx,dy};
    return r;
};
int* get_Chess(){
    static int  r[2]={sx,sy};
    return r;
};

void set_chesses(int who ,struct Node* root){
    int shift_who=(who>1?10:0);
    int highest_index=0;
    struct get_Steps peices[16];
    struct Node* board_list = root;
    struct Node* temp;
    temp = root->pNext;
    
    while (temp)
    {
        // enum { Kw = 1, Qw, Bw, Nw, Rw, Pw, Kb = 11, Qb, Bb, Nb, Rb, Pb };
        int id = temp->piece.id;
        if(id - shift_who > 0 && id - shift_who < 10)//id's field is between 1-6
        {
            id =temp->piece.id - shift_who;
            peices[id-1].best_Src_X = temp->piece.x;
            peices[id-1].best_Src_Y = temp->piece.y;
            switch (id) {
                case 1:{
                    King k(temp->piece.x, temp->piece.y, who, board_list);
                    k.generate_steps();
                    peices[id-1].best_Dst_X = k.dest_x;
                    peices[id-1].best_Dst_Y = k.dest_y;
                    peices[id-1].best_grade = k.grade;
                    break;
                }
                case 2:{
                    Queen q(temp->piece.x, temp->piece.y, who, board_list);
                    q.generate_steps();
                    peices[id-1].best_Dst_X = q.dest_x;
                    peices[id-1].best_Dst_Y = q.dest_y;
                    peices[id-1].best_grade = q.grade;
                    break;
                }
                case 3:{
                    Bishop b(temp->piece.x, temp->piece.y, who, board_list);
                    b.generate_steps();
                    peices[id-1].best_Dst_X = b.dest_x;
                    peices[id-1].best_Dst_Y = b.dest_y;
                    peices[id-1].best_grade = b.grade;
                    break;
                }
                case 4:{
                    Knight k(temp->piece.x, temp->piece.y, who, board_list);
                    k.generate_steps();
                    peices[id-1].best_Dst_X = k.dest_x;
                    peices[id-1].best_Dst_Y = k.dest_y;
                    peices[id-1].best_grade = k.grade;
                    break;
                }
                case 5:{
                    Rook r(temp->piece.x, temp->piece.y, who, board_list);
                    r.generate_steps();
                    peices[id-1].best_Dst_X = r.dest_x;
                    peices[id-1].best_Dst_Y = r.dest_y;
                    peices[id-1].best_grade = r.grade;
                    break;
                }
                case 6:{
                    Pawn p(temp->piece.x, temp->piece.y, who, board_list);
                    p.generate_steps();
                    peices[id-1].best_Dst_X = p.dest_x;
                    peices[id-1].best_Dst_Y = p.dest_y;
                    peices[id-1].best_grade = p.grade;
                    break;
                }
                default:
                    break;
            }
        }//end if is me
        temp = temp->pNext;
    }//end while
    
    int tmp_high=0;
    //determin heighest grade
    for(int i =0;i<16;i++){
        
        if(peices[i].best_grade>tmp_high){
            tmp_high = peices[i].best_grade;
            highest_index = i;
        }
    }
    if(ifdebug){
    cout<<"best grade = "<<peices[highest_index].best_grade<<endl;
    cout<<"best move = "<<peices[highest_index].best_Src_X<<","<<peices[highest_index].best_Src_Y <<" to "<< peices[highest_index].best_Dst_X<<","<<peices[highest_index].best_Dst_Y<<endl;
    }
    dx = peices[highest_index].best_Dst_X;
    dy = peices[highest_index].best_Dst_Y;
    sx = peices[highest_index].best_Src_X;
    sy = peices[highest_index].best_Src_Y;
    
    
    
    
    
};



//================================================================================================

int main(int argc, char* argv[])
{
	int me = 0;
    if(ifdebug){
    cout<<"argc:=="<<argc<<endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }}
	if (argc == 3)
		me = atoi(argv[1]);
	play(me, argv[2]);

	return 0;
}
