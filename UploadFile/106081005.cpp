class Student{
public:
    void copy(Color color1[][6],Color color[][6],int record1[][6],int Record[][6]){
        for (int i=0; i<5; i++) {
            for (int j=0;j<6; j++) {
                record1[i][j]=Record[i][j];
                if(color[i][j]==White) color1[i][j]=White;
                if(color[i][j]==Red) color1[i][j]=Red;
                if(color[i][j]==Blue) color1[i][j]=Blue;
                if(color[i][j]==Black) color1[i][j]=Black;
            }
        }
    }
    
    void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
        if(color[0][0]==White){x=0;y=0;return;}
        if(color[0][5]==White){x=0;y=5;return;}
        if(color[4][0]==White){x=4;y=0;return;}
        if(color[4][5]==White){x=4;y=5;return;}
        mycolor=inputColor;
        int deep,best=-INF-1,A,count=0;
        if(inputColor==Blue)playercolor=Red;
        else playercolor=Blue;
        copy(nowcol,color,now,Record);
        for (int i=0; i<5; i++) {
            for (int j=0; j<6; j++) {
                mx[i][j]=Max[i][j];
                if(color[i][j]==Black)count++;
            }
        }
        deep=4;
       // if(count>25)deep=6;
        
        for (int i=0; i<5; i++) {
            for (int j=0; j<6; j++) {
                if(color[i][j]==mycolor|| color[i][j]==White){
                    Color color1[5][6];int record1[5][6];
                    copy(color1,color,record1,Record);
                    change(i,j,record1,color1,mycolor);
                    A=min(record1,color1,deep-1);
                    if(A>=best){
                        best=A;x=i;y=j;
                    }
                }
            }
        }
    }
    
    int min(int Record[][6],Color color[][6],int deep){//playercolor,deep==1
       // if(deep<=0)return determine(color,mycolor,Record);//I win //determine my point,max for win
        int best=INF+1;
        int B;
        for (int i=0; i<5; i++) {
            for (int j=0; j<6; j++) {
                if(color[i][j]==playercolor || color[i][j]==White){
                    Color color1[5][6];int record1[5][6];
                    copy(color1,color,record1,Record);
                    change(i,j,record1,color1,playercolor);
                    B=max(record1,color1,deep-1);//return value from line 56
                }
                if(B<best)best=B;
            }
        }
        return ::min(INF,best);
    }
    
    int max(int Record[][6],Color color[][6],int deep){//mycolor
        if(deep<=0)return determine(color,mycolor,Record)-determine(color, playercolor, Record);//player win// determine playerpoint//max for playerwin
        int best=-INF-1;
        int B;
        for (int i=0; i<5; i++) {
            for (int j=0; j<6; j++) {
                if(color[i][j]==mycolor || color[i][j]==White){
                    Color color1[5][6];int record1[5][6];
                    copy(color1,color,record1,Record);
                    change(i,j,record1,color1,mycolor);
                    B=min(record1,color1,deep-1);
                }
                if(B>best)best=B;
            }
        }
        return ::max(-INF,best);
        
    }
    
    void change(int s,int q,int Record[][6],Color color[][6],Color input){
        color[s][q]=input;
        Record[s][q]++;
        if (Record[s][q]==mx[s][q]) {
            color[s][q]=Black;
            if(s!=4 && color[s+1][q]!=Black)change(s+1,q,Record,color,input);
            if(s!=0 && color[s-1][q]!=Black)change(s-1,q,Record,color,input);
            if(q!=5 && color[s][q+1]!=Black)change(s,q+1,Record,color,input);
            if(q!=0 && color[s][q-1]!=Black)change(s,q-1,Record,color,input);
        }
    }
    
    int determine(Color color[][6],Color input,int Record[][6]){
        Color opcolor;
        if(input==Blue)opcolor=Red;
        else opcolor=Blue;
        int value=0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<6; j++) {
                if(color[i][j]==input){
                    value++;
                    if(Record[i][j]==(mx[i][j]-1))value+=2;
                    if((mx[i][j]==2||mx[i][j]==3) &&
                       (i==4||(i!=4 && (color[i+1][j]!=opcolor && Record[i+1][j]!=(mx[i+1][j]-1)))) &&
                       (i==0||(i!=0 && (color[i-1][j]!=opcolor && Record[i-1][j]!=(mx[i-1][j]-1)))) &&
                       (j==5||(j!=5 && (color[i][j+1]!=opcolor && Record[i][j+1]!=(mx[i][j+1]-1)))) &&
                       (j==0||(j!=0 && (color[i][j-1]!=opcolor && Record[i][j-1]!=(mx[i][j-1]-1))))){
                        if(mx[i][j]==2)value+=3;
                        else value+=2;
                    }
                    if(i!=4 && color[i+1][j]==opcolor && Record[i+1][j]==(mx[i+1][j]-1)) value-=(5-mx[i+1][j]);
                    if(i!=0 && color[i-1][j]==opcolor && Record[i-1][j]==(mx[i-1][j]-1)) value-=(5-mx[i-1][j]);
                    if(j!=5 && color[i][j+1]==opcolor && Record[i][j+1]==(mx[i][j+1]-1)) value-=(5-mx[i][j+1]);
                    if(j!=0 && color[i][j-1]==opcolor && Record[i][j-1]==(mx[i][j-1]-1)) value-=(5-mx[i][j-1]);
                }
            }
        }
        return value;
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
    Color mycolor,playercolor,nowcol[5][6];
    int mx[5][6],now[5][6];
    const int INF=100000000;
};

