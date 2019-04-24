class Student{
	#include<time.h>
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            srand(time(NULL));
            int cnt = 0;

            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (color[i][j] == White || color[i][j] == inputColor) {
                        cnt++;
                    }
                }
            }

            int location = (rand() % cnt) + 1;

            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if(color[i][j] == White || color[i][j] == inputColor) {
                        location--;
                    }
                    if(location == 0){
                        x = i;
                        y = j;
                        break;
                    }
                }
                if(location == 0) break;
            }
        }

        int getX() {
            return x;
        }
        int getY() {
            return y;
        }
        Student() {
            x = 0;
            y = 0;
        }
    private:
        int x;
        int y;
    };
