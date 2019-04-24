    class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            int a = 7,b = 7;
            for (int i=4;i>=0;i--){
                for(int j=5;j>=0;j--){
                    if(color[i][j] == inputColor||color[i][j] == 0){
                        if(a == 7&&b == 7){
                            a=i;
                            b=j;
                        }
                        if(j<5&&color[i][j+1]==(3-inputColor)&&Record[i][j]<Record[i][j+1])continue;
                        if(j>0&&color[i][j-1]==(3-inputColor)&&Record[i][j]<Record[i][j-1])continue;
                        if(i>0&&color[i-1][j]==(3-inputColor)&&Record[i][j]<Record[i-1][j])continue;
                        if(i<4&&color[i+1][j]==(3-inputColor)&&Record[i][j]<Record[i+1][j])continue;
                        x = i;
                        y = j;
                        return; 
                    }
                }
            }
            x = a;y = b;
            a = 7;b = 7;
        }
        // Any Code You Want to Add
        int getX(){
            // Your Code
            return x;
        }
        int getY(){
            return y;
            // Your Code
        }
    private:
        int x;
        int y;
    };