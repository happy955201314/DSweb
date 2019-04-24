class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            int enemyColor;
            int i,j,nowi,nowj,M,D,P;
            if(inputColor==Red) enemyColor = Blue;
            else enemyColor = Red;

            if(color[0][0]==White) {x = 0; y = 0; return;}
            if(color[4][0]==White) {x = 4; y = 0; return;}
            if(color[0][5]==White) {x = 0; y = 5; return;}
            if(color[4][5]==White) {x = 4; y = 5; return;}
            for(i=0;i<5;i++){
                for(j=0;j<6;j++){
                    nowi = A[i];
                    nowj = B[j];
                    D = DONT(nowi,nowj,Record,Max,color,enemyColor);
                    if((color[nowi][nowj]==inputColor)&&(Record[nowi][nowj]==Max[nowi][nowj]-1)&&D){
                        x=nowi;
                        y=nowj;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                for(j=0;j<6;j++){
                    nowi = A[i];
                    nowj = B[j];
                    M = here(nowi,nowj,color,enemyColor);
                    D = DONT(nowi,nowj,Record,Max,color,enemyColor);
                    P = PLUS(nowi,nowj,Record,Max,color,enemyColor);
                    if((color[nowi][nowj]==inputColor)&&M&&!D){
                        x=nowi;
                        y=nowj;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                for(j=0;j<6;j++){
                    nowi = A[i];
                    nowj = B[j];
                    D = DONT(nowi,nowj,Record,Max,color,enemyColor);
                    if(color[nowi][nowj]==White&&!D){
                        x=nowi;
                        y=nowj;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                for(j=0;j<6;j++){
                    nowi = A[i];
                    nowj = B[j];
                    D = DONT(nowi,nowj,Record,Max,color,enemyColor);
                    if(color[nowi][nowj]==White){
                        x=nowi;
                        y=nowj;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                for(j=0;j<6;j++){
                    nowi = A[i];
                    nowj = B[j];
                    if(color[nowi][nowj]==inputColor){
                        x=nowi;
                        y=nowj;
                        return;
                    }
                }
            }
        }
        bool DONT(int a,int b,int Record[5][6], int Max[5][6],Color color[5][6],int enemyColor){
            if(a==0&&b==0){
                if((color[a+1][b]==enemyColor||color[a][b+1]==enemyColor)&&
                    (Record[a+1][b]==Max[a+1][b]-1||Record[a][b+1]==Max[a][b+1]-1)) return true;
                }
            else if(a==0&&b==5){
                if((color[a+1][b]==enemyColor||color[a][b-1]==enemyColor)&&
                    (Record[a+1][b]==Max[a+1][b]-1||Record[a][b-1]==Max[a][b-1]-1)) return true;
                }
            else if(a==4&&b==0){
                if((color[a-1][b]==enemyColor||color[a][b+1]==enemyColor)&&
                    (Record[a-1][b]==Max[a-1][b]-1||Record[a][b+1]==Max[a][b+1]-1)) return true;
                }
            else if(a==4&&b==5){
                if((color[a-1][b]==enemyColor||color[a][b-1]==enemyColor)&&
                    (Record[a-1][b]==Max[a-1][b]-1||Record[a][b-1]==Max[a][b-1]-1)) return true;
                }
            else if(a==0){
                if((color[a+1][b]==enemyColor||color[a][b+1]==enemyColor||color[a][b-1]==enemyColor)&&
                    (Record[a+1][b]==Max[a+1][b]-1||Record[a][b+1]==Max[a][b+1]-1||Record[a][b-1]==Max[a][b-1]-1)) return true;
                }
            else if(a==4){
                if((color[a-1][b]==enemyColor||color[a][b+1]==enemyColor||color[a][b-1]==enemyColor)&&
                    (Record[a-1][b]==Max[a-1][b]-1||Record[a][b+1]==Max[a][b+1]-1||Record[a][b-1]==Max[a][b-1]-1)) return true;
                }
            else if(b==0){
                if((color[a+1][b]==enemyColor||color[a-1][b]==enemyColor||color[a][b+1]==enemyColor)&&
                    (Record[a+1][b]==Max[a+1][b]-1||Record[a-1][b]==Max[a-1][b]-1||Record[a][b+1]==Max[a][b+1]-1)) return true;
                }
            else if(b==5){
                if((color[a+1][b]==enemyColor||color[a-1][b]==enemyColor||color[a][b-1]==enemyColor)&&
                    (Record[a+1][b]==Max[a+1][b]-1||Record[a-1][b]==Max[a-1][b]-1||Record[a][b+1]==Max[a][b-1]-1)) return true;
                }
            else{
                if((color[a-1][b]==enemyColor||color[a+1][b]==enemyColor||color[a][b-1]==enemyColor||color[a][b+1]==enemyColor)&&
                    (Record[a-1][b]==Max[a-1][b]-1||Record[a+1][b]==Max[a+1][b]-1||Record[a][b-1]==Max[a][b-1]-1||Record[a][b+1]==Max[a][b+1]-1))
                    return true;
                else
                    return false;
                }
            return false;

        }
        bool here(int a,int b,Color color[5][6],int enemyColor){
            if(a==0&&b==0){
                if(color[a+1][b]==enemyColor||color[a][b+1]==enemyColor) return true;
            }
            else if(a==0&&b==5){
                if(color[a+1][b]==enemyColor||color[a][b-1]==enemyColor) return true;
            }
            else if(a==4&&b==0){
                if(color[a-1][b]==enemyColor||color[a][b+1]==enemyColor) return true;
            }
            else if(a==4&&b==5){
                if(color[a-1][b]==enemyColor||color[a][b-1]==enemyColor) return true;
            }
            else if(a==0){
                if(color[a+1][b]==enemyColor||color[a][b+1]==enemyColor||color[a][b-1]==enemyColor) return true;
                }
            else if(a==4){
                if(color[a-1][b]==enemyColor||color[a][b+1]==enemyColor||color[a][b-1]==enemyColor) return true;
                }
            else if(b==0){
                if(color[a+1][b]==enemyColor||color[a-1][b]==enemyColor||color[a][b+1]==enemyColor) return true;
                }
            else if(b==5){
                if(color[a+1][b]==enemyColor||color[a-1][b]==enemyColor||color[a][b-1]==enemyColor) return true;
                }
            else {
                if(color[a-1][b]==enemyColor||color[a+1][b]==enemyColor||color[a][b-1]==enemyColor||color[a][b+1]==enemyColor)
                    return true;
                else
                    return false;
            }
            return false;
        }
        bool PLUS(int a,int b,int Record[5][6], int Max[5][6],Color color[5][6],int enemyColor){
            if(a==0&&b==0){
                if((color[a+1][b]==enemyColor&&Record[a][b]>=Record[a+1][b])||(color[a][b+1]==enemyColor&&Record[a][b]>=Record[a][b+1]))
                    return true;
                }
            else if(a==0&&b==5){
                if((color[a+1][b]==enemyColor&&Record[a][b]>=Record[a+1][b])||(color[a][b-1]==enemyColor&&Record[a][b]>=Record[a][b-1]))
                    return true;
                }
            else if(a==4&&b==0){
                if((color[a-1][b]==enemyColor&&Record[a][b]>=Record[a-1][b])||(color[a][b+1]==enemyColor&&Record[a][b]>=Record[a][b+1]))
                    return true;
                }
            else if(a==4&&b==5){
                if((color[a-1][b]==enemyColor&&Record[a][b]>=Record[a-1][b])||(color[a][b-1]==enemyColor&&Record[a][b]>=Record[a][b-1]))
                    return true;
                }
            else if(a==0){
                if((color[a+1][b]==enemyColor&&Record[a][b]>=Record[a+1][b])||(color[a][b+1]==enemyColor&&Record[a][b]>=Record[a][b+1])
                   ||(color[a][b-1]==enemyColor&&Record[a][b]>=Record[a][b-1])) return true;
                }
            else if(a==4){
                if((color[a-1][b]==enemyColor&&Record[a][b]>=Record[a-1][b])||(color[a][b+1]==enemyColor&&Record[a][b]>=Record[a][b+1])
                   ||(color[a][b-1]==enemyColor&&Record[a][b]>=Record[a][b-1])) return true;
                }
            else if(b==0){
                if((color[a+1][b]==enemyColor&&Record[a][b]>=Record[a+1][b])||(color[a-1][b]==enemyColor&&Record[a][b]>=Record[a-1][b])
                   ||(color[a][b+1]==enemyColor&&Record[a][b]>=Record[a][b+1])) return true;
                }
            else if(b==5){
                if((color[a+1][b]==enemyColor&&Record[a][b]>=Record[a+1][b])||(color[a-1][b]==enemyColor&&Record[a][b]>=Record[a-1][b])
                   ||(color[a][b-1]==enemyColor&&Record[a][b]>=Record[a][b-1])) return true;
                }
            else{
                if((color[a+1][b]==enemyColor&&Record[a][b]>=Record[a+1][b])||(color[a-1][b]==enemyColor&&Record[a][b]>=Record[a-1][b])
                   ||(color[a][b+1]==enemyColor&&Record[a][b]>=Record[a][b+1])||(color[a][b-1]==enemyColor&&Record[a][b]>=Record[a][b-1]))
                    return true;
                else
                    return false;
                }
            return false;
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
        int A[5] = {0,2,4,1,3};
        int B[6] = {1,3,5,0,2,4};
    };
