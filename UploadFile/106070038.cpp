		class Student{
			public:
				void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
					for (int i=0;i<5;i++)
						for (int j=0;j<6;j++)
							if (Record[i][j]<Max[i][j] && (color[i][j]==White || color[i][j]==inputColor))
								{x=i; y=j; return;}
				}
				// Any Code You Want to Add
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