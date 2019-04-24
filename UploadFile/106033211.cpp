    class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            x=0;y=0;
            if(inputColor==1){
                while(color[(x+count)%5][(y+count)%6]==3||color[(x+count)%5][(y+count)%6]==1){
                    count+=2;
                }
                x=(x+count)%5;
                y=(y+count)%6;
                return;
                // Your Code
            }
            else if(inputColor==2){
                while(color[(x+count)%5][(y+count)%6]==3||color[(x+count)%5][(y+count)%6]==2){
                    count+=2;
                }
                x=(x+count)%5;
                y=(y+count)%6;
                return;
                }
        }
        int count=1;
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