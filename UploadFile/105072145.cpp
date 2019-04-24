





class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
			// alpha, beta :  used for alpha-beta pruning algorithm
			int alpha = -1000000;
			int beta = 1000000;
			// store the best choice (x,y)
			x = -1;
			y = -1;
			minimax(0, Record, Max, color, inputColor, alpha, beta);
        }
		
		// search for the best move
		int minimax(int depth, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, int alpha, int beta){
			int blue = 0, red = 0, white = 0; // record the available points for each color
			int blueScore = 0, redScore = 0; // calculate current board's score for blue and red
			for(int i=0; i<5; i++){
				for(int j=0; j<6; j++){
					if(Record[i][j]<Max[i][j]){ // available
						int K = 10;
						if(i==0 || i==4) K += 10;
						if(j==0 || j==5) K += 10;
						if(color[i][j]==Blue){ // available only for Blue
							blue += Max[i][j]-Record[i][j];
							blueScore += K*(Max[i][j]-Record[i][j]);
						}
						if(color[i][j]==Red){ // available only for Red
							red += Max[i][j]-Record[i][j];
							redScore += K*(Max[i][j]-Record[i][j]);
						}
						if(color[i][j]==White){ // available for both Blue and Red
							white += Max[i][j]-Record[i][j];
							blueScore += Max[i][j]-Record[i][j];
							redScore += Max[i][j]-Record[i][j];
						}
					}
				}
			}
			int flag = (depth%2==0?1:-1);
			// check anyone win ?
			if(white==0){
				if(inputColor==Blue){
					if(blue==0) return -1000000 * flag;
					if(red==0) return 1000000 * flag;
				}
				if(inputColor==Red){
					if(red==0) return -1000000 * flag;
					if(blue==0) return 1000000 * flag;
				}
			}
			if(depth>4){ // set an appropriate depth for minimax search
				// evaluation current board's score for blue or red
				if(inputColor==Blue) return (blueScore-redScore) * flag;
				if(inputColor==Red) return (redScore-blueScore) * flag;
				return 0;
			}
			
			// a copy, only for recover
			int tmp_Record[5][6];
			Color tmp_color[5][6];
			for(int i=0; i<5; i++){
				for(int j=0; j<6; j++){
					tmp_Record[i][j] = Record[i][j];
					tmp_color[i][j] = color[i][j];
				}
			}
			Color nextColor = (inputColor==Blue ? Red:Blue);
			
			int maxScore = -1000001, minScore = 1000001;
			for(int i=0; i<5; i++){
				for(int j=0; j<6; j++){
					if(color[i][j]==White || color[i][j]==inputColor){ // available point
						makeMove(i, j, Record, Max, color, inputColor);
						int score = minimax(depth+1, Record, Max, color, nextColor, alpha, beta);
						//if(depth==0) printf("%d, %d,  depth= %d, score=%d, maxScore=%d\n",i,j,depth,score,maxScore);
						if(depth%2==0){ // 0/2/4/... represent Blue's turn (or Blue's turn)
							if(maxScore<score){
								maxScore = score;
								// the root's children, it's next move
								if(depth==0){ this->x = i; this->y = j; }
							}
							if(score > alpha) alpha = score; // update the MAX alpha value
						}else{ // 1/3/5/... represent Red's turn (or Blue's turn)
							if(minScore>score) minScore = score;
							if(score < beta) beta = score; // update the MIN beta value
						}
						
						// recover
						for(int ii=0; ii<5; ii++){
							for(int jj=0; jj<6; jj++){
								Record[ii][jj] = tmp_Record[ii][jj];
								color[ii][jj] = tmp_color[ii][jj];
							}
						}
						// alpha-beta pruning algorithm, to speed up the search
						if(alpha >= beta) break; 
					}
				}
				// alpha-beta pruning algorithm, to speed up the search
				if(alpha >= beta) break;
			}
			return (depth%2==0 ?maxScore:minScore);
		}
		
		// one choose to place (px, py), simulate the game process
		void makeMove(int px, int py, int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
			int q[30]={0}, qn = 0, d[8] = {-1, 0, 1, 0, 0, -1, 0, 1};
			Record[px][py] += 1;
			color[px][py] = inputColor;
			if(Record[px][py]>=Max[px][py]){ // explode
				q[qn++] = px*6+py;
				color[px][py] = Black;
			}
			
			while(qn>0){
				px = q[qn-1]/6;
				py = q[qn-1]%6;
				qn--;
				
				for(int i=0; i<8; i+=2){ // visit all the four direction
					int xx = px + d[i];
					int yy = py + d[i+1];
					if(0<=xx && xx<5 && 0<=yy && yy<6 && color[xx][yy]!=Black){
						color[xx][yy] = inputColor;
						Record[xx][yy] += 1;
						if(Record[xx][yy]>=Max[xx][yy]){ // explode
							q[qn++] = xx*6+yy;
							color[xx][yy] = Black;
						}
					}
				}
			}
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











