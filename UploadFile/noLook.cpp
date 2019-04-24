class Student {
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            bool checkWhite = false;
            bool checkConner = false;
            bool checkEdge = false;
            bool checkCenter = false;

            int x_white, y_white;
            int x_conner, y_conner;
            int x_edge, y_edge;
            int x_center, y_center;

            for(int i=0; i<5; i++){
                for(int j=0; j<6; j++){
                    if(color[i][j] == White){
                        x_white = i;
                        y_white = j;

                        checkWhite = true;
                    }
                    if(color[i][j] == inputColor){
                        if(Max[i][j] == 2){
                            x_conner = i;
                            y_conner = j;
                            checkConner = true;
                        }else if(Max[i][j] == 3){
                            x_edge = i;
                            y_edge = j;
                            checkEdge = true;
                        }else{
                            x_center = i;
                            y_center = j;
                            checkCenter = true;
                        }
                    }
                }
            }

            if(checkCenter == true){
                x = x_center;
                y = y_center;
            }else if(checkEdge == true){
                x = x_edge;
                y = y_edge;
            }else if(checkConner){
                x = x_conner;
                y = y_conner;
            }else if(checkWhite == true){
                x = x_white;
                y = y_white;
            }
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
    private:
        int x;
        int y;
	};
