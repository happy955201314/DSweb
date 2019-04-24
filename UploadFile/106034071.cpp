struct Move
{
    int x;
    int y;
}MovePos,Best;

class Student
{
public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor);
        // Any Code You Want to Add
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
private:
        int nextstep(int,int,int);
        Color iswin();
        int evaluate(Color);
        void corner();
        void set(int,int,Color);
        int getMoveList(vector<Move>&,Color);
        void changePlayer();
        int surround(int,int,Color);
        bool canReach(int,int,int,int);
        bool canReach1(int,int);
        int countBlack();
        int chains(int,int,Color);
        bool get;
        int x;
        int y;
        int depth;
        int cornerx,cornery;
        int tmpMax[5][6];
        std::vector<std::vector<int>> tmpRec;
        std::vector<std::vector<Color>> tmpColor;
        Color tmpinputColor;
        Color MyColor;
        Color oppColor;
};

void Student::makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
{
    
    for(int i=0;i<5;i++)
    {
        std::vector<int> Rec;
        std::vector<Color> Col;
        for(int j=0;j<6;j++)
        {
            Rec.push_back(Record[i][j]);
            Col.push_back(color[i][j]);
            tmpMax[i][j] = Max[i][j];
        }
        tmpRec.push_back(Rec);
        tmpColor.push_back(Col);
    }
    tmpinputColor = inputColor;
    MyColor = inputColor;
    if(MyColor==Red)oppColor = Blue;
    else oppColor = Red;
    get = false;
    depth=countBlack();
    corner();

    if(get==false) 
    {
        nextstep(depth,-1000000,1000000);
        x=Best.x;
        y=Best.y;
        get=true;
    }
    tmpColor.clear();
    tmpRec.clear();
}

int Student::countBlack()
{
    int counts=0;
    int counts1=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(tmpColor[i][j]==White) counts++;
            if(tmpColor[i][j]==Black) counts1++;
        }
    }
    if(counts1<15) return 4;
    if(counts1<12) return 6;
    if(counts1<20) return 8;
    return 120;
}

void Student::corner()
{
    if(tmpColor[0][0]==White && tmpRec[0][0]==0)
    {
        x=0;
        y=0;
        get=true;
    }
    else if(tmpColor[4][5]==White && tmpRec[4][5]==0)
    {
        x=4;
        y=5;
        get=true;
    }
    else if(tmpColor[0][5]==White && tmpRec[0][5]==0)
    {
        x=0;
        y=5;
        get=true;
    }
    else if(tmpColor[4][0]==White && tmpRec[4][0]==0)
    {
        x=4;
        y=0;
        get=true;
    } 
}


int Student::nextstep(int D,int alpha,int beta)
{
    int value;
    int moveCount=0;
    //Move moveList[30]={0};
    vector<Move> moveList;
    if(iswin()==MyColor)
    {
        return 100000;
    }
    else if(iswin()==oppColor)
    {
        return -100000;
    }
    Color opp;
    if(tmpinputColor==MyColor)opp=oppColor;
    else if(tmpinputColor==oppColor)opp=MyColor;
    if(D==0)
    {
        int x  =  evaluate(MyColor);
        return x;
    }


    vector<vector<int>> R = tmpRec;
    vector<vector<Color>> C = tmpColor;
   
    getMoveList(moveList,tmpinputColor);
    if(tmpinputColor==MyColor)
    {
        while(!moveList.empty())
        {
            Move curMove = moveList.back();
            moveList.pop_back();
            set(curMove.x,curMove.y,tmpinputColor);
            changePlayer();
            value = nextstep(D-1,alpha,beta);
            //cout << value << endl;
            changePlayer();
            tmpRec = R;
            tmpColor = C;
            if(value>alpha)
            {
                alpha = value;
                if(D==depth)
                {
                    Best = curMove; 
                } 
            }
            if(alpha >= beta) 
            {
                return alpha;
            }
        }
        return alpha;
    }
    else if(tmpinputColor==oppColor)
    {
        while(!moveList.empty())
        {
            Move curMove = moveList.back();
            moveList.pop_back();
            set(curMove.x,curMove.y,tmpinputColor);
            changePlayer();
            value = nextstep(D-1,alpha,beta);
            changePlayer();
            tmpRec = R;
            tmpColor = C;
            if(value<beta)
            {
                beta = value;
            } 
            if(alpha>=beta) return beta;
        }
        return beta;
    }
    
    moveList.clear();
}

int Student::getMoveList(vector<Move> &List,Color C)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(tmpRec[i][j] < tmpMax[i][j] && (tmpColor[i][j]==White || tmpColor[i][j]==C))
            {
                Move M;
                M.x=i;
                M.y=j;
                List.push_back(M);
            }
        }
    }
}

void Student::set(int x,int y,Color C)
{
    if(tmpRec[x][y]+1 < tmpMax[x][y])
    {
        tmpRec[x][y]++;
        tmpColor[x][y] = C;
    }
    else if(tmpRec[x][y]+1==tmpMax[x][y])
    {
        tmpRec[x][y]++;
        tmpColor[x][y] = Black;
        if(x+1<5) set(x+1,y,C);
        if(x-1>=0)set(x-1,y,C);
        if(y+1<6) set(x,y+1,C);
        if(y-1>=0)set(x,y-1,C);
    }
}

void Student::changePlayer()
{
    if(tmpinputColor==Red) tmpinputColor = Blue;
    else if(tmpinputColor==Blue) tmpinputColor = Red;
}

int Student::evaluate(Color C)
{
    int weight=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(tmpColor[i][j]==C)
            {
                weight ++;
                weight += surround(i,j,C);
            }
            if(tmpColor[i][j]==Black)
            {
                weight += (5-tmpMax[i][j]);
            }
        }
    }
    return weight;
}



int Student::surround(int x,int y,Color C)
{
    Color opp;
    if(C==MyColor)opp=oppColor;
    else if(C==oppColor)opp=MyColor;
    int w=0,counts=1,cc=0;
    for(int i=x-1;i<=x+1;i++)
    {
        for(int j=y-1;j<=y+1;j++)
        {
            if(canReach(i,j,x,y))
            {
                if(tmpColor[i][j]==opp)
                {
                    w -= (5-tmpMax[i][j]);
                    counts=0;
                }
            }
        }
    }
    if(counts)
    {
        if(tmpMax[x][y]==3) w+=2;
        else if(tmpMax[x][y]==2) w+=3;
        if(tmpRec[x][y]==tmpMax[x][y]-1) w+=2;
    }
   // w += 2*chains(x,y,MyColor);
    return w;
}

int Student::chains(int x,int y,Color C)
{
    int w=0;
    if(tmpRec[x][y]+1 < tmpMax[x][y])
    {
        return w;
    }
    else if(tmpRec[x][y]+1==tmpMax[x][y] && tmpColor[x][y]==C)
    {
        w++;
        Color now = tmpColor[x][y];
        tmpColor[x][y]=Black;
        if(x+1<5)  w += chains(x+1,y,C);
        if(x-1>=0) w += chains(x-1,y,C);
        if(y+1<6)  w += chains(x,y+1,C);
        if(y-1>=0) w += chains(x,y-1,C);
        tmpColor[x][y]=now;
        return w;
    }
}

bool Student::canReach(int x,int y,int cx,int cy)
{
    if(    x+1>=5
        || x-1<0
        || y+1>=6
        || y-1<0
        || abs(x-cx)+abs(y-cy)!=1
        || tmpColor[x][y]==Black
    )return false;
    return true;
}

bool Student::canReach1(int x,int y)
{
    if(    x+1>=5
        || x-1<0
        || y+1>=6
        || y-1<0
    )return false;
    return true;
}

Color Student::iswin()
{
    int opp=0;
    int self=0;
    int blackcount=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(tmpColor[i][j]==MyColor)
            {
                self++;
            }
            if(tmpColor[i][j]==Black)
            {
                blackcount++;
            }
            if(tmpColor[i][j]==oppColor)
            {
                opp++;
            }
        }
    }
    if(blackcount==30 && tmpinputColor==oppColor) return MyColor;
    else if(blackcount==30 && tmpinputColor==MyColor) return oppColor;
    if(opp+blackcount==30)
    {
        return oppColor;
    } 
    else if(self+blackcount==30)
    {
        return MyColor;
    } 
     
    return Black;
}



