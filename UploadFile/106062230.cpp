class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            for(int i=4; i>=0; i--){
				for(int j=5; j>=0; j--){
					if(color[i][j]==inputColor || color[i][j]==White){
						this->x = i;
						this->y = j;
						return;
					}
				}
			}
        }
        // Any Code You Want to Add
        int getX(){
            return this->x;
        }
        int getY(){
            return this->y;
        }
    private:
        int x;
        int y;
    };
