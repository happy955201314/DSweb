
class Student{
    public:
        bool check(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, int r, int c){
            Color Opponent = inputColor==Blue?Red:Blue;
            if(r>0&&color[r-1][c]==Opponent)    return true;
            if(c>0&&color[r][c-1]==Opponent)    return true;
            if(r<4&&color[r+1][c]==Opponent)    return true;
            if(c<5&&color[r][c+1]==Opponent)    return true;
            return false;
        }
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            // Your Code
            Color Opponent = inputColor==Blue?Red:Blue;
            if(color[0][0]==White){
                x=0,y=0;
                return;
            }
            if(color[0][5]==White){
                x=0,y=5;
                return;
            }
            if(color[4][0]==White){
                x=4,y=0;
                return;
            }
            if(color[4][5]==White){
                x=4,y=5;
                return;
            }
            for(int i=0; i<5; i++){
                for(int j=0; j<6; j++){
                    if(color[i][j]==Opponent)   continue;
                    if(Record[i][j]+1==Max[i][j]&&this->check(Record,Max,color,inputColor,i,j)){
                        x=i,y=j;
                        return;
                    }
                }
            }
            for(int i=0; i<5; i++){
                for(int j=0; j<6; j++){
                    if(color[i][j]==Opponent||color[i][j]==Black)   continue;
                    if(Record[i][j]+1<Max[i][j]){
                        x=i,y=j;
                        return;
                    }
                }
            }
            if(color[x][y]==Opponent||color[x][y]==Black){
                for(int i=0; i<5; i++){
                    for(int j=0; j<6; j++){
                        if(color[i][j]==White||color[i][j]==inputColor){
                            x=i,y=j;
                            return;
                        }
                    }
                }
            }
            return;
        }
        // Any Code You Want to Add
        int getX(){
            // Your Code
            return x;
        }
        int getY(){
            // Your Code
            return y;
        }
    private:
        int x;
        int y;
    };