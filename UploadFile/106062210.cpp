class Student{
public:
    void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
        set(Record,Max,color);
        int done = 0;
        if(color[4][5]==0||color[4][5]==inputColor){
            Record[4][5]++;
            x = 4;
            y = 5;
            done = 1;
        }
        else if(color[0][5]==0||color[0][5]==inputColor){
            Record[0][5]++;
            x = 0;
            y = 5;
            done = 1;
        }
        else if(color[4][0]==0||color[4][0]==inputColor){
            Record[4][0]++;
            x = 4;
            y = 0;
            done = 1;
        }
        else if(color[0][0]==0||color[0][0]==inputColor){
            Record[0][0]++;
            x = 0;
            y = 0;
            done = 1;
        }
        for(int i=0;i<5&&(!done);i++){
            for(int j=0;j<6&&(!done);j++){
                if(color[i][j]==inputColor&&Record[i][j]==Max[i][j]-1){
                    Record[i][j]++;
                    x = i;
                    y = j;
                    done = 1;
                    break;
                }
            }
        }
        for(int i=0;i<5&&(!done);i++){
            for(int j=0;j<6&&(!done);j++){
                if(color[i][j]==inputColor&&Record[i][j]==Max[i][j]-2){
                    Record[i][j]++;
                    x = i;
                    y = j;
                    done = 1;
                    break;
                }
            }
        }
        if(!done){
            for(int i=0;i<5&&(!done);i++){
                for(int j=0;j<6&&(!done);j++){
                    if(color[i][j]==inputColor&&Record[i][j]==Max[i][j]-3){
                        Record[i][j]++;
                        x = i;
                        y = j;
                        done = 1;
                        break;
                    }
                    if(color[i][j]==0){
                        Record[i][j]++;
                        x = i;
                        y = j;
                        done = 1;
                        break;
                    }
                }
            }
        }
//        Explode(x,y);
//        RESET(Record,Max,color);
        // Your Code
    }
/*    void Explode(int a,int b){
        if(CO[a][b]!=3){
            if(RE[a][b]==MA[a][b]){
                RE[a][b] = 3;
                if(a==0){
                    if(b==0){
                        if(RE[a+1][b]<MA[a+1][b]) {RE[a+1][b]++;Explode(a+1,b);}
                        if(RE[a][b+1]<MA[a][b+1]) {RE[a][b+1]++;Explode(a,b+1);}
                    }
                    else if(b==5){
                        if(RE[a+1][b]<MA[a+1][b]) {RE[a+1][b]++;Explode(a+1,b);}
                        if(RE[a][b-1]<MA[a][b-1]) {RE[a][b-1]++;Explode(a,b-1);}
                    }
                    else{
                        if(RE[a+1][b]<MA[a+1][b]) {RE[a+1][b]++;Explode(a+1,b);}
                        if(RE[a][b+1]<MA[a][b+1]) {RE[a][b+1]++;Explode(a,b+1);}
                        if(RE[a][b-1]<MA[a][b-1]) {RE[a][b-1]++;Explode(a,b-1);}
                    }
                }
                else if(a==4){
                    if(b==0){
                        if(RE[a-1][b]<MA[a-1][b]) {RE[a-1][b]++;Explode(a-1,b);}
                        if(RE[a][b+1]<MA[a][b+1]) {RE[a][b+1]++;Explode(a,b+1);}
                    }
                    else if(b==5){
                        if(RE[a-1][b]<MA[a-1][b]) {RE[a-1][b]++;Explode(a-1,b);}
                        if(RE[a][b-1]<MA[a][b-1]) {RE[a][b-1]++;Explode(a,b-1);}
                    }
                    else{
                        if(RE[a-1][b]<MA[a-1][b]) {RE[a-1][b]++;Explode(a-1,b);}
                        if(RE[a][b+1]<MA[a][b+1]) {RE[a][b+1]++;Explode(a,b+1);}
                        if(RE[a][b-1]<MA[a][b-1]) {RE[a][b-1]++;Explode(a,b-1);}
                    }
                }
                else{
                    if(b==0){
                        if(RE[a+1][b]<MA[a+1][b]) {RE[a+1][b]++;Explode(a+1,b);}
                        if(RE[a-1][b]<MA[a-1][b]) {RE[a-1][b]++;Explode(a-1,b);}
                        if(RE[a][b+1]<MA[a][b+1]) {RE[a][b+1]++;Explode(a,b+1);}
                    }
                    else if(b==5){
                        if(RE[a+1][b]<MA[a+1][b]) {RE[a+1][b]++;Explode(a+1,b);}
                        if(RE[a-1][b]<MA[a-1][b]) {RE[a-1][b]++;Explode(a-1,b);}
                        if(RE[a][b-1]<MA[a][b-1]) {RE[a][b-1]++;Explode(a,b-1);}
                    }
                    else{
                        if(RE[a+1][b]<MA[a+1][b]) {RE[a+1][b]++;Explode(a+1,b);}
                        if(RE[a-1][b]<MA[a-1][b]) {RE[a-1][b]++;Explode(a-1,b);}
                        if(RE[a][b+1]<MA[a][b+1]) {RE[a][b+1]++;Explode(a,b+1);}
                        if(RE[a][b-1]<MA[a][b-1]) {RE[a][b-1]++;Explode(a,b-1);}
                    }
                }
            }
        }
    }*/
    // Any Code You Want to Add
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    void set(int A[5][6],int B[5][6],Color C[5][6]){
        for(int i=0;i<5;i++){
            for(int j = 0;j<6;j++){
                RE[i][j]=A[i][j];
                MA[i][j]=B[i][j];
                CO[i][j]=C[i][j];
            }
        }
    }/*
    void RESET(int A[5][6],int B[5][6],Color C[5][6]){
        for(int i=0;i<5;i++){
            for(int j = 0;j<6;j++){
                A[i][j]=RE[i][j];
                B[i][j]=MA[i][j];
                C[i][j]=CO[i][j];
            }
        }
    }*/
private:
    int RE[5][6];
    int MA[5][6];
    Color CO[5][6];
    int x;
    int y;
    };
