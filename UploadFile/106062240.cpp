typedef pair<int,int> pii;
struct pos
{
	int x,y;
	pos(){}
	pos(int _x, int _y):x(_x),y(_y){}
};
// make moves such that the enemy have only even moves
class Student
{
	public:
		void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
		{
			if(inputColor==Blue) opp_clr=Red;
			else opp_clr=Blue;
			my3.clear();
			my3_cnt.clear();
			for(int i=0;i<5;i+=4)
				for(int j=0;j<6;j+=5)
					if(color[i][j]==White)
					{
						x=i,y=j;
						return;
					}
			for(int i=0;i<5;i++)
			{
				if(color[i][0]==White&&(i-1<0||color[i-1][0]==White)&&(i+1>4||color[i+1][0]==White)&&(0-1<0||color[i][0-1]==White)&&(0+1>5||color[i][0+1]==White))
				{
					x=i,y=0;
					return;
				}
				if(color[i][5]==White&&(i-1<0||color[i-1][5]==White)&&(i+1>4||color[i+1][5]==White)&&(5-1<0||color[i][5-1]==White)&&(5+1>5||color[i][5+1]==White))
				{
					x=i,y=5;
					return;
				}
			}
			for(int j=0;j<6;j++)
			{
				if(color[0][j]==White&&(0-1<0||color[0-1][j]==White)&&(0+1>4||color[0+1][j]==White)&&(j-1<0||color[0][j-1]==White)&&(j+1>5||color[0][j+1]==White))
				{
					x=0,y=j;
					return;
				}
				if(color[4][j]==White&&(4-1<0||color[4-1][j]==White)&&(4+1>4||color[4+1][j]==White)&&(j-1<0||color[4][j-1]==White)&&(j+1>5||color[4][j+1]==White))
				{
					x=4,y=j;
					return;
				}
			}
			// special for rlawrenc
			if(Record[3][2]==1&&color[3][2]==opp_clr&&Record[2][2]==3&&color[2][2]==opp_clr&&Record[1][2]==3&&color[1][2]==opp_clr&&Record[3][3]==3&&color[3][3]==opp_clr&&color[4][1]==White)
			{
				x=4,y=1;
				return;
			}
			for(int i=0;i<5;i++)
				for(int j=0;j<6;j++)
				{
					if(Record[i][j]==Max[i][j]-1&&color[i][j]==inputColor)
						my3.emplace_back(i,j);
				}
			for(auto i:my3)
			{
				copyData(Record,Max,color);
				my3_cnt.emplace_back(nearEnemy(i.x,i.y,inputColor));
			}
			if(!my3.empty())
			{
				int cnt=0;
				for(int i=1;i<(int)(my3.size());i++)
					if(my3_cnt[i]>my3_cnt[cnt]) cnt=i;
				if(my3_cnt[cnt]>0)
				{
					x=my3[cnt].x;
					y=my3[cnt].y;
					return;
				}
			}
			for(int i=0;i<5;i++)
				for(int j=0;j<6;j++)
				{
					if(color[i][j]!=inputColor) continue;
					if((i-1>=0&&color[i-1][j]==inputColor)+(i+1<5&&color[i+1][j]==inputColor)+(j-1>=0&&color[i][j-1]==inputColor)+(j+1<6&&color[i][j+1]==inputColor)>=2) continue;
					if(
							(i-1>=0&&color[i-1][j]!=inputColor&&Record[i-1][j]==Max[i-1][j]-1)||
							(i+1<5&&color[i+1][j]!=inputColor&&Record[i+1][j]==Max[i+1][j]-1)||
							(j-1>=0&&color[i][j-1]!=inputColor&&Record[i][j-1]==Max[i][j-1]-1)||
							(j+1<6&&color[i][j+1]!=inputColor&&Record[i][j+1]==Max[i][j+1]-1)
							) continue;
					if(Record[i][j]!=Max[i][j]-1)
					{
						x=i;
						y=j;
						return;
					}
				}
			for(int i=0;i<5;i++)
				for(int j=0;j<6;j++)
				{
					if(color[i][j]==White&&(i-1<0||color[i-1][j]==White)&&(i+1>4||color[i+1][j]==White)&&(j-1<0||color[i][j-1]==White)&&(j+1>5||color[i][j+1]==White))
					{
						x=i;
						y=j;
						return;
					}
				}
			for(int i=0;i<5;i++)
				for(int j=0;j<6;j++)
				{
					if(color[i][j]==White&&(i-1<0||color[i-1][j]!=inputColor)&&(i+1>4||color[i+1][j]!=inputColor)&&(j-1<0||color[i][j-1]!=inputColor)&&(j+1>5||color[i][j+1]!=inputColor))
					{
						x=i;
						y=j;
						return;
					}
				}
			for(int i=4;i>=0;i--)
				for(int j=5;j>=0;j--)
				{
					if(color[i][j]==inputColor&&Record[i][j]!=Max[i][j]-1&&(i-1<0||color[i-1][j]!=opp_clr)&&(i+1>4||color[i+1][j]!=opp_clr)&&(j-1<0||color[i][j-1]!=opp_clr)&&(j+1>5||color[i][j+1]!=opp_clr))
					{
						x=i;
						y=j;
						return;
					}
				}
			for(int i=0;i<5;i++)
				for(int j=0;j<6;j++)
				{
					if(color[i][j]==White)
					{
						x=i;
						y=j;
						return;
					}
				}
			for(int i=0;i<5;i++)
				for(int j=0;j<6;j++)
				{
					if(color[i][j]==inputColor)
					{
						x=i;
						y=j;
						return;
					}
				}
		}

		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
	private:
		int record[5][6];
		int limit[5][6];
		Color clr[5][6];
		Color opp_clr;
		int x;
		int y;
		vector<pos> my3;
		vector<int> my3_cnt;

		void copyData(int X[5][6], int Y[5][6], Color Z[5][6])
		{
			memcpy(record,X,sizeof(record));
			memcpy(limit,Y,sizeof(limit));
			memcpy(clr,Z,sizeof(clr));
		}
		int nearEnemy(int px, int py, Color color) // potential filter
		{
			int rtn;
			if(clr[px][py]==color)
			{
				if(record[px][py]==limit[px][py]-1) rtn=-4;
				else rtn=0;
			}
			else if(clr[px][py]==Black) rtn=0;
			else if(clr[px][py]==White) rtn=1;
			else
			{
				int cnt=0;
				for(int i=0;i<5;i++)
					for(int j=0;j<6;j++)
						if(clr[i][j]!=Black&&clr[i][j]!=color) cnt++;
				if(cnt==1) rtn=1000000000;
				else if(record[px][py]==limit[px][py]-1) rtn=9;
				else rtn=4;
			}
			record[px][py]++;
			clr[px][py]=color;
			if(record[px][py]>=limit[px][py])
			{
				clr[px][py]=Black;
				if(px-1>=0&&clr[px-1][py]!=Black)
					rtn+=nearEnemy(px-1,py,color);
				if(px+1<5&&clr[px+1][py]!=Black)
					rtn+=nearEnemy(px+1,py,color);
				if(py-1>=0&&clr[px][py-1]!=Black)
					rtn+=nearEnemy(px,py-1,color);
				if(py+1<6&&clr[px][py+1]!=Black)
					rtn+=nearEnemy(px,py+1,color);
			}
			return rtn;
		}
};
