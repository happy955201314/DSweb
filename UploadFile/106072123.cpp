class Student{
    public:
        void makeMove(int Record[5][6],int Max[5][6],Color color[5][6],Color inputColor){
            // Your Code
            int **value = new int*[5];
            for(int i = 0; i < 5; i++) {
                value[i] = new int[6];
            }
            for(int i =0;i<5;i++){
                for(int j =0;j<6;j++){
                    value[i][j] = 0;
                }
            }
            value = this->corner(Record,value);
            value = this->edge(Record,value);
            value = this->explode(Record,Max,value);
            value = this->eat(Record,value,color,inputColor);
            int max=-1;
            for(int i =0;i<5;i++){
                for(int j =0;j<6;j++){
                    if(max<=value[i][j] && color[i][j]!=Black && (color[i][j]==inputColor||color[i][j]==White)){
                        max = value[i][j];
                        this->x = i;
                        this->y = j;
                    }
                }
            }
        }
        int** eat(int Record[5][6],int** value, Color color[5][6], Color inputColor){
            if(inputColor==Red){inputColor = Blue;}else{inputColor=Red;}
            for(int i =0;i<5;i++){
                for(int j =0;j<6;j++){
                    if(color[i][j]==inputColor){
                        if(i+1<5 && Record[i+1][j]>=Record[i][j]) value[i+1][j]+=3;
                        if(i-1>=0 && Record[i-1][j]>=Record[i][j]) value[i-1][j]+=3;
                        if(j+1<5 && Record[i][j+1]>=Record[i][j]) value[i][j+1]+=3;
                        if(j-1>=0 && Record[i][j-1]>=Record[i][j]) value[i][j-1]+=3;
                    }
                }
            }
            return value;
        }
        int** explode(int Record[5][6],int Max[5][6],int** value){
            for(int i =0;i<5;i++){
                for(int j =0;j<6;j++){
                    if(Record[i][j]==Max[i][j]-1) value[i][j]+=3;
                }
            }
            return value;
        }
        int** corner(int Record[5][6],int** value){
            if(Record[0][0]<1 ) value[0][0]+=5;
            if(Record[0][5]<1 ) value[0][5]+=5;
            if(Record[4][0]<1 ) value[4][0]+=5;
            if(Record[4][5]<1 ) value[4][5]+=5;
            return value;
        }
        int** edge(int Record[5][6],int** value){
            for(int i=1;i<5;i++){
                if(Record[0][i]<1) value[0][i]+=2;
            }
            for(int i=1;i<4;i++){
                if(Record[i][0]<1) value[i][0]+=2;
            }
            for(int i=1;i<5;i++){
                if(Record[4][i]<1) value[4][i]+=2;
            }
            for(int i=1;i<4;i++){
                if(Record[i][5]<1) value[i][5]+=2;
            }
            return value;
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