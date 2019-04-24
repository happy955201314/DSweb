class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
        {
            // Your Code
            if(color[0][0]==White || color[0][5]==White || color[4][0]==White || color[4][5]==White)
            {
                cornor(Record, Max, color, inputColor);
                return;
            }

            int p_i=0, p_j=0, p_max_amount=0, p_amount=0;
            for(int i=0; i<5; i++)  //most enemy's critical mass around my critical mass
            {
                for(int j=0; j<6; j++)
                {
                    p_amount=0;
                    if(color[i][j]==inputColor || color[i][j]==White)
                    {
                        if(Record[i][j]==Max[i][j]-1)
                        {
                            if(i+1<5 && color[i+1][j]!=inputColor && color[i+1][j]!=Black && Record[i+1][j]==Max[i+1][j]-1)
                            {
                                p_amount++;
                            }
                            if(i-1>=0 && color[i-1][j]!=inputColor && color[i-1][j]!=Black && Record[i-1][j]==Max[i-1][j]-1)
                            {
                                p_amount++;
                            }
                            if(j+1<6 && color[i][j+1]!=inputColor && color[i][j+1]!=Black && Record[i][j+1]==Max[i][j+1]-1)
                            {
                                p_amount++;
                            }
                            if(j-1>=0 && color[i][j-1]!=inputColor && color[i][j-1]!=Black && Record[i][j-1]==Max[i][j-1]-1)
                            {
                                p_amount++;
                            }
                            if(p_amount>p_max_amount)
                            {
                                p_i=i;
                                p_j=j;
                                p_max_amount=p_amount;
                            }
                        }
                    }
                }
            }
            if(p_max_amount!=0)
            {
                x=p_i;
                y=p_j;
                return;
            }
            p_amount=0;
            p_max_amount=0;

            for(int i=0; i<5; i++)  //most enemy's mass around my critical mass
            {
                for(int j=0; j<6; j++)
                {
                    p_amount=0;
                    if(color[i][j]==inputColor || color[i][j]==White)
                    {
                        if((i+1<5 && color[i+1][j]!=inputColor && color[i+1][j]!=Black && color[i+1][j]!=White && Record[i+1][j]==Max[i+1][j]-1) || (i-1>=0 && color[i-1][j]!=inputColor && color[i-1][j]!=Black && color[i-1][j]!=White && Record[i-1][j]==Max[i-1][j]-1) || (j+1<6 && color[i][j+1]!=inputColor && color[i][j+1]!=Black && color[i][j+1]!=White && Record[i][j+1]==Max[i][j+1]-1) || (j-1>=0 && color[i][j-1]!=inputColor && color[i][j-1]!=Black && color[i][j-1]!=White && Record[i][j-1]==Max[i][j-1]-1))
                        {
                            break;
                        }

                        if(Record[i][j]==Max[i][j]-1)
                        {
                            if(i+1<5 && color[i+1][j]!=inputColor && color[i+1][j]!=Black)
                            {
                                p_amount++;
                            }
                            if(i-1>=0 && color[i-1][j]!=inputColor && color[i-1][j]!=Black)
                            {
                                p_amount++;
                            }
                            if(j+1<6 && color[i][j+1]!=inputColor && color[i][j+1]!=Black)
                            {
                                p_amount++;
                            }
                            if(j-1>=0 && color[i][j-1]!=inputColor && color[i][j-1]!=Black)
                            {
                                p_amount++;
                            }
                            if(p_amount>p_max_amount)
                            {
                                p_i=i;
                                p_j=j;
                                p_max_amount=p_amount;
                            }
                        }
                    }
                }
            }
            if(p_max_amount!=0)
            {
                x=p_i;
                y=p_j;
                return;
            }
            p_amount=0;
            p_max_amount=0;

            for(int i=0; i<5; i++)  //make my almost critical mass become critical mass
            {
                for(int j=0; j<6; j++)
                {
                    p_amount=0;
                    if(color[i][j]==inputColor || color[i][j]==White)
                    {
                        if((i+1<5 && color[i+1][j]!=inputColor && color[i+1][j]!=Black && color[i+1][j]!=White && Record[i+1][j]==Max[i+1][j]-1) || (i-1>=0 && color[i-1][j]!=inputColor && color[i-1][j]!=Black && color[i-1][j]!=White && Record[i-1][j]==Max[i-1][j]-1) || (j+1<6 && color[i][j+1]!=inputColor && color[i][j+1]!=Black && color[i][j+1]!=White && Record[i][j+1]==Max[i][j+1]-1) || (j-1>=0 && color[i][j-1]!=inputColor && color[i][j-1]!=Black && color[i][j-1]!=White && Record[i][j-1]==Max[i][j-1]-1))
                        {
                            break;
                        }
                        
                        if(Record[i][j]==Max[i][j]-2)
                        {
                            if(i+1<5 && color[i+1][j]!=inputColor && color[i+1][j]!=Black && Record[i+1][j]!=Max[i+1][j]-1)
                            {
                                p_amount++;
                            }
                            if(i-1>=0 && color[i-1][j]!=inputColor && color[i-1][j]!=Black && Record[i-1][j]!=Max[i-1][j]-1)
                            {
                                p_amount++;
                            }
                            if(j+1<6 && color[i][j+1]!=inputColor && color[i][j+1]!=Black && Record[i][j+1]!=Max[i][j+1]-1)
                            {
                                p_amount++;
                            }
                            if(i-1>=0 && color[i][j-1]!=inputColor && color[i][j-1]!=Black && Record[i][j-1]!=Max[i][j-1]-1)
                            {
                                p_amount++;
                            }
                            if(p_amount>p_max_amount)
                            {
                                p_i=i;
                                p_j=j;
                                p_max_amount=p_amount;
                            }
                        }
                    }
                }
            }
            if(p_max_amount!=0)
            {
                x=p_i;
                y=p_j;
                return;
            }
            p_amount=0;
            p_max_amount=0;

            for(int i=0; i<5; i++)  //click 0
            {
                for(int j=0; j<6; j++)
                {
                    p_amount=0;
                    if(color[i][j]==White)
                    {
                        if((i+1<5 && color[i+1][j]!=inputColor && color[i+1][j]!=Black && color[i+1][j]!=White && Record[i+1][j]==Max[i+1][j]-1) || (i-1>=0 && color[i-1][j]!=inputColor && color[i-1][j]!=Black && color[i-1][j]!=White && Record[i-1][j]==Max[i-1][j]-1) || (j+1<6 && color[i][j+1]!=inputColor && color[i][j+1]!=Black && color[i][j+1]!=White && Record[i][j+1]==Max[i][j+1]-1) || (j-1>=0 && color[i][j-1]!=inputColor && color[i][j-1]!=Black && color[i][j-1]!=White && Record[i][j-1]==Max[i][j-1]-1))
                        {
                            break;
                        }
                        
                        if(i+1<5 && color[i+1][j]==inputColor)
                        {
                            p_amount++;
                        }
                        if(i-1>=0 && color[i-1][j]==inputColor)
                        {
                            p_amount++;
                        }
                        if(j+1<6 && color[i][j+1]==inputColor)
                        {
                            p_amount++;
                        }
                        if(j-1>=0 && color[i][j-1]==inputColor)
                        {
                            p_amount++;
                        }
                        if(p_amount>p_max_amount)
                        {
                            p_i=i;
                            p_j=j;
                            p_max_amount=p_amount;
                        }
                    }
                }
            }
            if(p_max_amount!=0)
            {
                x=p_i;
                y=p_j;
                return;
            }
            p_amount=0;
            p_max_amount=0;
            
            for(int i=0; i<5; i++)  //click 1
            {
                for(int j=0; j<6; j++)
                {
                    p_amount=0;
                    if(color[i][j]==inputColor)
                    {
                        if((i+1<5 && color[i+1][j]!=inputColor && color[i+1][j]!=Black && color[i+1][j]!=White && Record[i+1][j]==Max[i+1][j]-1) || (i-1>=0 && color[i-1][j]!=inputColor && color[i-1][j]!=Black && color[i-1][j]!=White && Record[i-1][j]==Max[i-1][j]-1) || (j+1<6 && color[i][j+1]!=inputColor && color[i][j+1]!=Black && color[i][j+1]!=White && Record[i][j+1]==Max[i][j+1]-1) || (j-1>=0 && color[i][j-1]!=inputColor && color[i][j-1]!=Black && color[i][j-1]!=White && Record[i][j-1]==Max[i][j-1]-1))
                        {
                            break;
                        }
                        
                        if(Record[i][j]==1)
                        {
                            if(i+1<5 && color[i+1][j]==inputColor)
                            {
                                p_amount++;
                            }
                            if(i-1>=0 && color[i-1][j]==inputColor)
                            {
                                p_amount++;
                            }
                            if(j+1<6 && color[i][j+1]==inputColor)
                            {
                                p_amount++;
                            }
                            if(j-1>=0 && color[i][j-1]==inputColor)
                            {
                                p_amount++;
                            }
                            if(p_amount>p_max_amount)
                            {
                                p_i=i;
                                p_j=j;
                                p_max_amount=p_amount;
                            }
                        }
                    }
                }
            }
            if(p_max_amount!=0)
            {
                x=p_i;
                y=p_j;
                return;
            }
            p_amount=0;
            p_max_amount=0;

            for(int i=0; i<5; i++)  //just click
            {
                for(int j=0; j<6; j++)
                {
                    if(color[i][j]==inputColor || color[i][j]==White)
                    {
                        x=i;
                        y=j;
                        return;
                    }
                }
            }
        }

        void cornor(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
        {
            if(color[0][0]==White)
            {
                if(Record[0][1]<=1 && Record[1][0]<=1)
                {
                    x=0;
                    y=0;
                }
                else
                {
                    if(Record[0][1]==2 && color[0][1]==inputColor && Record[1][0]<=1)
                    {
                        x=0;
                        y=0;
                    }
                    else if(Record[1][0]==2 && color[1][0]==inputColor && Record[0][1]<=1)
                    {
                        x=0;
                        y=0;
                    }
                }
            }
            else if(color[0][5]==White)
            {
                if(Record[0][4]<=1 && Record[1][5]<=1)
                {
                    x=0;
                    y=5;
                }
                else
                {
                    if(Record[0][4]==2 && color[0][4]==inputColor && Record[1][5]<=1)
                    {
                        x=0;
                        y=5;
                    }
                    else if(Record[1][5]==2 && color[1][5]==inputColor && Record[0][4]<=1)
                    {
                        x=0;
                        y=5;
                    }
                }
            }
            else if(color[4][0]==White)
            {
                if(Record[3][0]<=1 && Record[1][4]<=1)
                {
                    x=4;
                    y=0;
                }
                else
                {
                    if(Record[3][0]==2 && color[3][0]==inputColor && Record[1][4]<=1)
                    {
                        x=4;
                        y=0;
                    }
                    else if(Record[3][0]==2 && color[3][0]==inputColor && Record[1][4]<=1)
                    {
                        x=4;
                        y=0;
                    }
                }
            }
            else if(color[4][5]==White)
            {
                if(Record[3][5]<=1 && Record[4][4]<=1)
                {
                    x=4;
                    y=5;
                }
                else
                {
                    if(Record[3][5]==2 && color[3][5]==inputColor && Record[4][4]<=1)
                    {
                        x=4;
                        y=5;
                    }
                    else if(Record[3][5]==2 && color[3][5]==inputColor && Record[4][4]<=1)
                    {
                        x=4;
                        y=5;
                    }
                }
            }
        }
        
        int getX()
        {
            // Your Code
            return x;
        }
        int getY()
        {
            // Your Code
            return y;
        }
    private:
        int x;
        int y;
    };
