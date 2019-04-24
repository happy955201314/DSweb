class Student{
    public:
        /*void scroe(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            total = 0;
            otherColor = (inputColor==Blue)? Red : Blue ;
            for (i=0; i<5; i++) {
                for (j=0; j<6; j++) {
                    if (color[i][j]==inputColor)
                        total += Max[i][j]-Record[i][j];
                }
            }
        }*/
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            int i,j;
            for (i=0; i<5; i++) {
                for (j=0; j<6; j++) {
                    if (color[i][j]==White) {
                        x = i ; y = j; return;
                    }
                }
            }
            for (i=0; i<5; i++) {
                for (j=0; j<6; j++) {
                    if (color[i][j]==inputColor) {
                        x = i ; y = j; return;
                    }
                }
            }
        }

        // Any Code You Want to Add
        int getX(){return x ;}
        int getY(){return y ;}
    private:
        int x;
        int y;
    };
