class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            // Your Code
            clock_t t;
            int tmpi, tmpj;
            do{
                t = clock();
                tmpi = t % 5;
                t = clock();
                tmpj = t % 6;
            } while(color[tmpi][tmpj]!=White && color[tmpi][tmpj]!=inputColor);
            x = tmpi;
            y = tmpj;
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