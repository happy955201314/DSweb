class Student
{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
        {
            if(color[0][0]==White)
            {
                x=0;y=0;
            }else if(color[0][5]==White)
            {
                x=0;y=5;
            }else if(color[4][0]==White)
            {
                x=4;y=0;
            }else if(color[4][5]==White)
            {
                x=4;y=5;
            }else
            {
                int i,j;
                for(i=0;i<=4;i++)
                {
                    for(j=0;j<=5;j++)
                    {
                        if(color[i][j]==White)
                        {
                            x=i;y=j;
                            break;
                        }else if(color[i][j]==inputColor)
                        {
                            j++;
                        }
                    }
                }
                if(i==5&&(j==6||j==7))
                {
                    for(i=0;i<=4;i++)
                    {
                        for(j=0;j<=5;j++)
                        {
                            if(color[i][j]==inputColor)
                            {
                                x=i;y=j;
                                break;
                            }
                        }
                    }
                }
            }
            if(x==2&&y==3&&Record[2][3]==2&&(color[0][2]==White||color[0][2]==inputColor))
            {
                x=0;y=2;
            }
            else if(x==1&&y==1&&Record[1][1]==3&&(color[0][3]==White||color[0][3]==inputColor))
            {
                x=0;y=2;
            }
            else if(x==1&&y==1&&Record[1][1]==3&&(color[0][3]==White||color[0][3]==inputColor))
            {
                x=0;y=3;
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
