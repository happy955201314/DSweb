 class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            for(int i=4;i>=0;i=i-2){
                for(int j=5;j>=0;j--){
                    if(color[0][0]==White)//先下1次角落
                    {
                        x=0;
                        y=0;
                    }
                    else if(color[4][5]==White)
                    {
                        x=4;
                        y=5;
                    }
                    else if(color[4][0]==White)
                    {
                        x=4;
                        y=0;
                    }
                    else if(color[0][5]==White)
                    {
                        x=0;
                        y=5;
                    }
                    else if(Record[i][j]<4 && Max[i][j]<=2 && (color[i][j]==White || color[i][j]==inputColor))//角落
                    {
                        x=i;
                        y=j;
                    }
                    else if(Record[i][j]<4 && Max[i][j]<=3 &&(color[i][j]==White || color[i][j]==inputColor))//邊邊
                    {
                        x=i;
                        y=j;
                    }
                    else if(Record[i][j]<4 && Max[i][j]<=4 && (color[i][j]==White || color[i][j]==inputColor))//中間
                    {
                        x=i;
                        y=j;
                    }
                } 
            }
        }
        // Any Code You Want to Add
        int getX(){
            return x;
            // Your Code
        }
        int getY(){
            return y;
            // Your Code
        }
    private:
        int x;
        int y;
    };