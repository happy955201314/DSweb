    class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
			Color enemy;
			if(inputColor==Red)
				enemy = Blue;
			else
				enemy = Red;

			if( color[2][0] == inputColor&&Record[x][y] != Max[x][y]-1 && Record[1][0] == 1&&color[1][0]==enemy){
				x = 2; y = 0; return;
			}
			//¸Õ¸Õ¬Ý 
			if(Record[3][4]==3&&Record[3][5]==2&&Record[4][3]==2&&Record[4][5]==1&&color[4][4]==White ){ x = 4; y=4; return;}
			if(Record[1][2]==3&&color[1][2]==inputColor&&Record[1][3]==2&&color[1][3]==enemy&&Record[1][4]==2&&color[1][4]==inputColor&&color[1][5]==enemy){x = 1; y=4; return;}
			x=0; y=0;
			while(x != 5)
			{
				if( color[2][0] == inputColor&&Record[x][y] == Max[x][y]-1 && Record[1][0] == 2&&color[1][0]==enemy){
					x = 2; y = 0; return;
				}				
			
				if( (color[x][y] == inputColor )
					&& (Record[x][y] == Max[x][y]-1) 
 					&& ( (color[x+1][y] == enemy  && (Record[x+1][y] == Max[x+1][y]-1) ) 
					||   (color[x-1][y] == enemy  && (Record[x-1][y] == Max[x-1][y]-1) )
					||   (color[x][y+1] == enemy  && (Record[x][y+1] == Max[x][y+1]-1) )
					||   (color[x][y-1] == enemy  && (Record[x][y-1] == Max[x][y-1]-1) ) 
					   ) 
			      )
				{
					return;
				}
				if(y==5){ y=0; x++; }
				else { y++; } 
			}

			x=0; y=0;
			while( x != 5)
			{
				if(x==2&&y==0)
				{
					if( color[2][5] == inputColor && Record[1][5] == 1&& color[1][5] == enemy){
						x = 2; y = 5; return;
					}
				}
				
				if( (color[x][y] == inputColor)
					&& (Record[x][y] != Max[x][y] - 1)   
					&& ( (color[x+1][y] == enemy&& (Max[x+1][y]-Record[x+1][y] == Max[x][y]-Record[x][y])) || (color[x-1][y] == enemy&& (Max[x-1][y]-Record[x-1][y] == Max[x][y]-Record[x][y])) || (color[x][y+1] == enemy&& (Max[x][y+1]-Record[x][y+1] == Max[x][y]-Record[x][y])) || (color[x][y-1] == enemy) && (Max[x][y-1]-Record[x][y-1] == Max[x][y]-Record[x][y]) )
				  )
				{
					return;
				}
				if(y==5){ y=0; x++; }
				else { y++; } 
			}
			
			x=0; y=0;
			while(x != 5)
			{
				if( (color[x][y] == inputColor )
					&& (Record[x][y] == Max[x][y]-1) 
 					&& ( (color[x+1][y] == enemy  && (Record[x+1][y] == Max[x+1][y]-2) && (Record[x+2][y] != Max[x+2][y]-1) && (Record[x+1][y+1] != Max[x+1][y+1]-1) && (Record[x+1][y-1] != Max[x+1][y-1]-1)) 
					||   (color[x-1][y] == enemy  && (Record[x-1][y] == Max[x-1][y]-2) && (Record[x-2][y] != Max[x-2][y]-1) && (Record[x-1][y+1] != Max[x-1][y+1]-1) && (Record[x-1][y-1] != Max[x-1][y-1]-1))
					||   (color[x][y+1] == enemy  && (Record[x][y+1] == Max[x][y+1]-2) && (Record[x][y+2] != Max[x][y+2]-1) && (Record[x+1][y+1] != Max[x+1][y+1]-1) && (Record[x-1][y+1] != Max[x-1][y+1]-1))
					||   (color[x][y-1] == enemy  && (Record[x][y-1] == Max[x][y-1]-2) && (Record[x][y-2] != Max[x][y-2]-1) && (Record[x+1][y-1] != Max[x+1][y-1]-1) && (Record[x-1][y-1] != Max[x-1][y-1]-1)) 
					   ) 
			      )
				{
					return;
				}  
				if(y==5){ y=0; x++; }
				else { y++; } 
			}					
				
			if(color[0][0]==White) 
			{
				    x=0; y=0; return;
			}				
			if(color[4][0]==White)
			{
				
					x=4; y=0; return;  
			}
			if(color[0][5]==White)
			{
				
					x=0; y=5; return;  
			}						
			if(color[4][5]==White)
			{
				
					x=4; y=5; return;  
			}

			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if((i==0 || j==0 || i==4 || j==5 )&&color[i][j]==White)
					{
						if(i==0&&color[i][j-1]==White&&color[i][j+1]==White){ x = i; y = j; return;}
						if(i==4&&color[i][j-1]==White&&color[i][j+1]==White){ x = i; y = j; return;}
						if(j==0&&color[i+1][j]==White&&color[i-1][j]==White){ x = i; y = j; return;}
						if(j==5&&color[i+1][j]==White&&color[i-1][j]==White){ x = i; y = j; return;}				
					}
				}

			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if((i!=0 && j!=0 && i!=4 && j!=5 && i!=1 && j!=1 && i!=3 && j!=4 )&&color[i][j]==White&&(color[i+1][j]!=enemy&&color[i-1][j]!=enemy&&color[i][j-1]!=enemy&&color[i][j+1]!=enemy)){ x = i; y = j; return;} 
				}

			x=0; y=0;
			while(x != 5)
			{
				if( color[x][y] ==White
				    &&(color[x+1][y+1] == enemy
					|| color[x+2][y] == enemy
					|| color[x][y+2] == enemy
					|| color[x-1][y-1] == enemy 
					|| color[x-2][y] == enemy 
					|| color[x][y-2] == enemy
					|| color[x-1][y+1] == enemy  
					|| color[x+1][y-1] == enemy ) 
					&& (color[x+1][y] ==White || color[x+1][y] ==Black)
					&& (color[x-1][y] ==White || color[x-1][y] ==Black)
					&& (color[x][y+1] ==White || color[x][y+1] ==Black)
					&& (color[x][y-1] ==White || color[x][y+1] ==Black) )
				{
					return;
				}
				if(y==5){ y=0; x++; }
				else { y++; } 
			}		

		
			x=0; y=0;
			while(x != 5)
			{
				if( color[x][y] ==White
					&&(color[x+1][y+1] == inputColor
					|| color[x+2][y] == inputColor
					|| color[x][y+2] == inputColor
					|| color[x-1][y-1] == inputColor 
					|| color[x-2][y] == inputColor 
					|| color[x][y-2] == inputColor
					|| color[x-1][y+1] == inputColor  
					|| color[x+1][y-1] == inputColor ) 
					&& (color[x+1][y] ==White || color[x+1][y] ==Black)
					&& (color[x-1][y] ==White || color[x-1][y] ==Black)
					&& (color[x][y+1] ==White || color[x][y+1] ==Black)
					&& (color[x][y-1] ==White || color[x][y+1] ==Black) )
				{
					return;
				}
				if(y==5){ y=0; x++; }
				else { y++; } 
			}
				
			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==White&&(color[i+1][j]!=enemy&&color[i-1][j]!=enemy&&color[i][j-1]!=enemy&&color[i][j+1]!=enemy)){ x = i; y = j; return;} 
				}

			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor&&(i==0 || j==0 || i==4 || j==5 )&&(Record[x][y] != Max[x][y] - 1))
					{
						if(i==0&&color[i][j-1]!=enemy&&color[i][j+1]!=enemy){ x = i; y = j; return;}
						if(i==4&&color[i][j-1]!=enemy&&color[i][j+1]!=enemy){ x = i; y = j; return;}
						if(j==0&&color[i+1][j]!=enemy&&color[i-1][j]!=enemy){ x = i; y = j; return;}
						if(j==5&&color[i+1][j]!=enemy&&color[i-1][j]!=enemy){ x = i; y = j; return;}
					} 
				}

			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor&&(i==0 || j==0 || i==4 || j==5 )&&(Record[x][y] != Max[x][y] - 1)){ x = i; y = j; return;} 
				}

			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor&&(Record[x][y] != Max[x][y] - 1)&&(color[i+1][j]==White&&color[i-1][j]==White&&color[i][j-1]==White&&color[i][j+1]==White)){ x = i; y = j; return;} 
				}
			
			if(color[0][0]==inputColor) 
			{
				    x=0; y=0; return;
			}				
			if(color[4][0]==inputColor)
			{
				
					x=4; y=0; return;  
			}
			if(color[0][5]==inputColor)
			{
				
					x=0; y=5; return;  
			}						
			if(color[4][5]==inputColor)
			{
				
					x=4; y=5; return;  
			}				

			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor&&(Record[x][y] != Max[x][y] - 1)&&(color[i+1][j]!=enemy&&color[i-1][j]!=enemy&&color[i][j-1]!=enemy&&color[i][j+1]!=enemy)){ x = i; y = j; return;} 
				}				
			
			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor&&(Record[x][y] != Max[x][y]-1)&&(Record[x+1][y] != Max[x+1][y]-1) && (Record[x-1][y] != Max[x-1][y]-1) && (Record[x][y+1] != Max[x][y+1]-1) && (Record[x][y-1] != Max[x][y-1]-1)){ x = i; y = j; return;} 
				}
				
			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor&&(Record[x][y] == Max[x][y]-1)&&(Record[x+1][y] <= Max[x+1][y]-2) && (Record[x-1][y] <= Max[x-1][y]-2) && (Record[x][y+1] <= Max[x][y+1]-2) && (Record[x][y-1] <= Max[x][y-1]-2)){ x = i; y = j; return;} 
				}	
				
			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor&&(Record[x][y] == Max[x][y]-1)&&((Record[x+1][y] <= Max[x+1][y]-2) || (Record[x-1][y] <= Max[x-1][y]-2) || (Record[x][y+1] <= Max[x][y+1]-2) || (Record[x][y-1] <= Max[x][y-1]-2))){ x = i; y = j; return;}  
				}							

			x=0; y=0;
			while( x != 5)
			{
				if( (color[x][y] == inputColor )
					&& (Record[x][y] != Max[x][y] - 1) && (Record[x+1][y] != Max[x+1][y]-1) && (Record[x-1][y] != Max[x-1][y]-1) && (Record[x][y+1] != Max[x][y+1]-1) && (Record[x][y-1] != Max[x][y-1]-1)
					&& ((color[x+1][y] == enemy   ) 
					||  (color[x-1][y] == enemy   )
					||  (color[x][y+1] == enemy   )
					||  (color[x][y-1] == enemy   )
					   )
				    
				  )
				{
					return;
				}
				if(y==5){ y=0; x++; }
				else { y++; } 
			}

			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==White){ x = i; y = j; return;} 
				}
	
			for(int i = 0; i <= 4; i++ )
				for(int j = 0; j <= 5; j++ )
				{
					if(color[i][j]==inputColor){ x = i; y = j; return;} 
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
