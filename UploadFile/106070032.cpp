class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            //int i=0,j=0;
            //x=i;
            //y=j;
            // Your Code
            
            x=0;
            y=0;
            if(color[x][y]==White && Record[x][y]==0){
                color[x][y]=inputColor;
                Record[x][y]++;
                return;
            }
            x=4;
            y=0;
            if(color[x][y]==White && Record[x][y]==0){
                color[x][y]=inputColor;
                Record[x][y]++;
                return;
            }
            x=0;
            y=5;
            if(color[x][y]==White && Record[x][y]==0){
                color[x][y]=inputColor;
                Record[x][y]++;
                return;
            }
            x=4;
            y=5;
            if(color[x][y]==White && Record[x][y]==0){
                color[x][y]=inputColor;
                Record[x][y]++;
                return;
            }
            
            x=0;
            y=0;
            if(Record[x][y]==1 && color[x][y]==inputColor){
                Record[x][y]++;
                return;
            }
            x=4;
            y=0;
            if(Record[x][y]==1 && color[x][y]==inputColor){
                Record[x][y]++;
                return;
            }
            x=0;
            y=5;
            if(Record[x][y]==1 && color[x][y]==inputColor){
                Record[x][y]++;
                return;
            }
            x=4;
            y=5;
            if(Record[x][y]==1 && color[x][y]==inputColor){
                Record[x][y]++;
                return;
            }
            for(x=0;x<5;x++){
                
                for(y=0;y<6;y++){
                    if(color[x][y]==inputColor || color[x][y]==White){
                        
                        if(Record[x][y]==2){
                            color[x][y]=inputColor;
                            Record[x][y]++;
                            
                            return;
                        }
                        if(Record[x][y]==3){
                            color[x][y]=inputColor;
                            Record[x][y]++;
                            
                            return;
                        }
                        
                    }

                }
            }
            for(x=0;x<5;x++){
                
                for(y=0;y<6;y++){
                    if(color[x][y]==inputColor || color[x][y]==White){
                        
                        
                        color[x][y]=inputColor;
                        Record[x][y]++;
                        return;
                    }

                }
            }

            /*
            for( i=0,j=0;i<5,j<6;i++,j++){
                if(Record)
            }*/
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
