
/*
enum Color{
    White, // Initital 0
    Blue, // Player One
    Red, // Player Two
    Black //Explosion
};
*/

class Student{
private:
    static const int R = 5;
    static const int C = 6;
    int x;
    int y;

    void place(int r, int c)
    {
        x = r, y = c;
    }
public:
    void makeMove(int record[R][C], int Max[R][C], Color color[R][C], Color inputColor){
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(record[r][c] < Max[r][c] && (color[r][c] == inputColor || color[r][c] == White))
                {
                    place(r, c);
                    return;
                }
            }
        }
    }
    // Any Code You Want to Add
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};
