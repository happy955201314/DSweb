class Student{
    public:
        int Score[5][6];

        Color counter(Color inputColor) {
            if(inputColor == Blue) return Red;
            else return Blue;
        }

        bool valid(int x, int y) {
            return (x >= 0 && x < 5 && y >= 0 && y < 6);
        }

        int surroundCritical(int x, int y, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, Color counterColor) {
            int sum = 0;
            if(valid(x - 1, y)) { // up is a critical enemy
                if(color[x - 1][y] == counterColor && Record[x - 1][y] == Max[x - 1][y]) sum++;
            }
            if(valid(x + 1, y)) {
                if(color[x + 1][y] == counterColor && Record[x + 1][y] == Max[x + 1][y]) sum++;
            }
            if(valid(x, y - 1)) {
                if(color[x][y - 1] == counterColor && Record[x][y - 1] == Max[x][y - 1]) sum++;
            }
            if(valid(x, y + 1)) {
                if(color[x][y + 1] == counterColor && Record[x][y + 1] == Max[x][y + 1]) sum++;
            }
            return sum;
        }

        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            Color counterColor = counter(inputColor);
            int sum;
            int maxScore = -1000;
            int max_x = x, max_y = y;
            // Your Code
            for(int i = 0; i<5; i++) {
                for(int j = 0; j<6; j++) {
                    Score[i][j] = 0;
                    if(color[i][j] == inputColor) {
                        if(Record[i][j] == Max[i][j]) {// is critical
                            sum = surroundCritical(i, j, Record, Max, color, inputColor, counterColor);
                            Score[i][j] += sum * 10;
                        } else {
                            sum = surroundCritical(i, j, Record, Max, color, inputColor, counterColor);
                            Score[i][j] -= sum * 10;
                            Score[i][j] -= (Max[i][j] - Record[i][j]) * 5;
                        }
                    } else {
                        Score[i][j] -= 500;
                    }
                    if(Score[i][j] > maxScore) {
                        maxScore = Score[i][j];
                        max_x = i;
                        max_y = j;
                    }
                }
            }
            x = max_x;
            y = max_y;
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