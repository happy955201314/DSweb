class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            // Your Code
            bool done=0 ;
            if (color[4][0]==White ) { x = 4 ; y = 0 ; return ; }
            if (color[4][5]==White ) { x = 4 ; y = 5 ; return ; }
            if (color[0][5]==White ) { x = 0 ; y = 5 ; return ; }
            if (color[0][0]==White ) { x = 0 ; y = 0 ; return ; }
            for (int i=3; i>0; i--) {
                if (color[i][0]==White || color[i][0]==inputColor) {
                        x = i ; y = 0 ; return ;
                }
            }
            for (int j=1; j<5; j++) {
                if (color[4][j]==White || color[4][j]==inputColor) {
                        x = 4 ; y = j ; return ;
                }
            }
            /*for (int j=4; j>0; j--) {
                if (color[0][j]==White || color[0][j]==inputColor) {
                        x = 0 ; y = j ; return ;
                }
            }
            for (int i=3; i>0; i--) {
                if (color[i][0]==White || color[i][0]==inputColor) {
                        x = i ; y = 0 ; return ;
                }
            }*/
            for (int i=0; i<5; i++) {
                for (int j=0; j<6; j++) {
                    if (color[i][j]!=Black && (color[i][j]==White || color[i][j]==inputColor)) {
                        x = i ; y = j ; done = 1 ; break ;
                    }
                }
                //if (done == 1) break ;
            }
        }
        // Any Code You Want to Add
        int getX(){
            return x ;
        }
        int getY(){
            return y ;
        }
    private:
        int x;
        int y;
};
