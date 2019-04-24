#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

enum PlayStatus{
    Ready,
    PlayerOneTurn,
    PlayerTwoTurn,
    PlayerOneWin,
    PlayerTwoWin
};

enum Color{
    White, //Initial, 0
    Blue, //Player One => Blue, 1
    Red,  //Player Two => Red, 2
    Black //Explosion => Black, 3
};

namespace playerOne
{
	//Replace_playerOne_here

};

namespace playerTwo
{
	//Replace_playerTwo_here
};


void BumpExplosion(int BoardRecord[5][6], int BoardMax[5][6], Color BoardColor[5][6], int x, int y, Color changeColor){

    if(BoardColor[x][y] != Black){
        BoardRecord[x][y]++;
        BoardColor[x][y] = changeColor;

        // test explosion
        if(BoardRecord[x][y] == BoardMax[x][y]){

            BoardColor[x][y] = Black;

            // left
            if(x >= 0 && y-1 >= 0 && (BoardColor[x][y-1] != Black)) BumpExplosion( BoardRecord, BoardMax, BoardColor, x, y-1, changeColor);

            // top
            if(x-1 >= 0 && y >= 0 && (BoardColor[x-1][y] != Black)) BumpExplosion( BoardRecord, BoardMax, BoardColor, x-1, y, changeColor);

            // down
            if(x+1 < 5 && y < 6 && (BoardColor[x+1][y] != Black)) BumpExplosion( BoardRecord, BoardMax, BoardColor, x+1, y, changeColor);

            // right
            if(x < 5 && y+1 < 6 && (BoardColor[x][y+1] != Black)) BumpExplosion( BoardRecord, BoardMax, BoardColor, x, y+1, changeColor);
        }
    }
}

PlayStatus checkWin(Color BoardColor[5][6], PlayStatus status){
    bool white = false;
    bool blue = false;
    bool red = false;

    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            if(BoardColor[i][j] == White){
                white = true;
            }else if(BoardColor[i][j] == Blue){
                blue = true;
            }else if(BoardColor[i][j] == Red){
                red = true;
            }
        }
    }

    if(white == true){
        if(status == PlayerOneTurn) return PlayerTwoTurn;
        else return PlayerOneTurn;
    }else{
        if(blue == true && red == true){
            if(status == PlayerOneTurn) return PlayerTwoTurn;
            else return PlayerOneTurn;
        }else{
            if(blue == true) return PlayerOneWin;
            else if(red == true) return PlayerTwoWin;
            else{
                if(status == PlayerOneTurn) return PlayerOneWin;
                else return PlayerTwoWin;
            }
        }
    }

}

int main()
{
    playerOne::Student StudentOne; // namespace student1
    playerTwo::Student StudentTwo; // namespace student2

    int BoardRecord[5][6]; // Player Gaming Board, recording pixel in cell
    int BoardMax[5][6];    // Pixel max number in ever cell
    Color BoardColor[5][6];  // which player occur cell


    // initial
    PlayStatus Status = Ready;

    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            BoardColor[i][j] = White;
            BoardRecord[i][j] = 0;
            if((i==0 || i== 4) && (j==0 || j==5)){
                BoardMax[i][j] = 2;
            }else if(i == 0 || i== 4 || j == 0 || j == 5){
                BoardMax[i][j] = 3;
            }else{
                BoardMax[i][j] = 4;
            }
        }
    }

    Status = PlayerOneTurn;
	cout<<"Start"<<endl;
    while (Status != PlayerOneWin && Status != PlayerTwoWin) {

        int x,y;
        // copy Board and send to student
        int _BoardRecord[5][6];
        int _BoardMax[5][6];
        Color _BoardColor[5][6];

        for(int i=0; i<5; i++){
            for(int j=0; j<6; j++){
                _BoardRecord[i][j] = BoardRecord[i][j];
                _BoardMax[i][j] = BoardMax[i][j];
                _BoardColor[i][j] = BoardColor[i][j];
            }
        }

        if (Status == PlayerOneTurn) {

            StudentOne.makeMove(_BoardRecord, _BoardMax, _BoardColor, Blue);
            // get position
            x = StudentOne.getX();
            y = StudentOne.getY();

            cout<<"Player One : "<<"("<<x+1<<","<<y+1<<")"<<endl;

            if(x < 0 || x > 4 || y < 0 || y > 5) Status = PlayerTwoWin;

        } else if (Status == PlayerTwoTurn) {

            StudentTwo.makeMove(_BoardRecord, _BoardMax, _BoardColor, Red);
            // get position
            x = StudentTwo.getX();
            y = StudentTwo.getY();

            cout<<"Player Two : "<<"("<<x+1<<","<<y+1<<")"<<endl;

            if(x < 0 || x > 4 || y < 0 || y > 5) Status = PlayerOneWin;

        }

        // if wrong color, you lose
        Color cellcolor = BoardColor[x][y];
        if((cellcolor == Blue || cellcolor == Black) && Status == PlayerTwoTurn){
            Status = PlayerOneWin;
            break;
        }
        if((cellcolor == Red  || cellcolor == Black) && Status == PlayerOneTurn){
            Status = PlayerTwoWin;
            break;
        }

        // Explosion
        if(Status == PlayerOneTurn){
            BumpExplosion(BoardRecord, BoardMax, BoardColor, x, y, Blue);
            Status = checkWin(BoardColor,Status);
        }else if(Status == PlayerTwoTurn){
            BumpExplosion(BoardRecord, BoardMax, BoardColor, x, y, Red);
            Status = checkWin(BoardColor,Status);
        }

    }

    if(Status == PlayerOneWin) cout<<"Player One Win !"<<endl;
    else cout<<"Player Two Win !"<<endl;

    return 0;
}
