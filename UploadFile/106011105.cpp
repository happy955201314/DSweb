class Student {
public:
    void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
        // 策略 : 前面模仿對手下法，當可以預測結果時，計算勝率，選擇勝率最高者。
        en = 0;
        n_record = 0;
        for ( int i = 0; i < 5; ++i ) {
            for ( int j = 0; j < 6; ++j ) {
                n_record += Record[i][j];
                if ( color[i][j] == inputColor || color[i][j] == White ) {
                    en++;
                    nextMove = i * 6 + j;
                }
            }
        }//cout<<"record : "<<n_record<<endl;
        bool success = false;
        if ( en > 17 )
            success = imitate(Record, Max, color, inputColor);
        if ( success == false ) {
            evaluate(Record, Max, color, inputColor, false, 0);
            //cout<<"can't imitate"<<endl;
        }
        x = nextMove / 6;
        y = nextMove % 6;
        Record_move(Record, color, Max, inputColor);
    }
    float evaluate(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, bool mini, int depth) {
        int max_depth = 6;
        if ( n_record > 80 ) max_depth = 7;
        else if ( n_record > 70 ) max_depth = 6;
        else if ( n_record > 60 ) max_depth = 5;
        else max_depth = 4;
        int winner = checkWinner(color, inputColor);
        if ( winner > 0 ) {
        if ( (mini == false && winner == inputColor) || (mini == true && winner != inputColor) )
                return 1;
            else
                return 0;
        }
        if ( depth >= max_depth ) {
            float WinRate = getScore(Record, Max, color, inputColor);
            return ( mini == false ) ? WinRate : 1 - WinRate;
        }
        bool valid[5][6];
        int valid_num = 0;
        int ChildRecord[5][6];
        Color ChildColor[5][6];
        Color ChildinputColor = TurnColor(inputColor);
        for ( int i = 0; i < 5; ++i ) {
            for ( int j = 0; j < 6; ++j ) {
                if ( color[i][j] == White || color[i][j] == inputColor ) {
                    valid[i][j] = true;
                    valid_num++;
                }
                else
                    valid[i][j] = false;
            }
        }
        float MaxWinRate = -1;
        float Total = 0;
        for ( int k = 0; k < 30; ++k ) {
            int i = k / 6, j = k % 6;
            if ( valid[i][j] == false ) continue;
            move(ChildRecord, ChildColor, Record, color, Max, inputColor, i, j);
            float ChildWinRate = evaluate(ChildRecord, Max, ChildColor, ChildinputColor, !mini, depth+1);
            Total += ChildWinRate;
            if ( depth == 0 && ChildWinRate >= MaxWinRate ) {
                MaxWinRate = ChildWinRate;
                nextMove = k;
                //cout<<"One win rate : "<<ChildWinRate<<" & "<<k/6+1<<" "<<k%6+1<<endl;
            }
        }
        return Total /= valid_num;
    }
    float getScore(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
        float Myscore = 0;
        float EnemyScore = 0;
        Color EnemyColor = TurnColor(inputColor);
        for ( int i = 0; i < 5; ++i ) {
            for ( int j = 0; j < 5; ++j ) {
                if ( color[i][j] == inputColor ) {
                    if ( Max[i][j] == 2 ) {
                        Myscore += 10;
                    }
                    else if ( Max[i][j] == 3 ) {
                        if ( Record[i][j] == 2 ) Myscore += 9*2;
                        else Myscore += 7;
                    }
                    else {
                        if ( Record[i][j] == 3 ) Myscore += 8*3;
                        else if ( Record[i][j] == 2) Myscore += 6*2;
                        else Myscore += 5;
                    }
                }
                else if ( color[i][j] == EnemyColor ) {
                    if ( Max[i][j] == 2 ) {
                        EnemyScore += 10;
                    }
                    else if ( Max[i][j] == 3 ) {
                        if ( Record[i][j] == 2 ) EnemyScore += 9*2;
                        else EnemyScore += 7;
                    }
                    else {
                        if ( Record[i][j] == 3 ) EnemyScore += 8*3;
                        else if ( Record[i][j] == 2) EnemyScore += 6*2;
                        else EnemyScore += 5;
                    }
                }
            }
        }
        return (Myscore + 0 )/(Myscore+EnemyScore);
    }
    void move(int (&ChildRecord)[5][6], Color (&ChildColor)[5][6], int Record[5][6], Color color[5][6], int Max[5][6], Color inputColor, int row, int col) {
        for ( int i = 0; i < 5; ++i ) {
            for ( int j = 0; j < 6; ++j ) {
                ChildRecord[i][j] = Record[i][j];
                ChildColor[i][j] = color[i][j];
            }
        }
        queue<int> Q;
        Q.push(row); Q.push(col);
        while ( !Q.empty() ) {
            int r = Q.front(); Q.pop();
            int c = Q.front(); Q.pop();
            if ( ChildRecord[r][c] < Max[r][c] )
                ChildRecord[r][c]++;
            if ( ChildColor[r][c] == Black ) continue;
            ChildColor[r][c] = inputColor;
            if ( ChildRecord[r][c] == Max[r][c] ) {
                ChildColor[r][c] = Black;
                if ( r-1 >= 0 ) {
                    if (ChildColor[r-1][c] != Black) {
                        Q.push(r-1); Q.push(c);
                    }
                }
                if ( r+1 < 5 ) {
                    if (ChildColor[r+1][c] != Black) {
                        Q.push(r+1); Q.push(c);
                    }
                }
                if ( c-1 >= 0 ) {
                    if (ChildColor[r][c-1] != Black) {
                        Q.push(r); Q.push(c-1);
                    }
                }
                if ( c+1 < 6 ) {
                    if (ChildColor[r][c+1] != Black) {
                        Q.push(r); Q.push(c+1);
                    }
                }
            }
        }
    }
    int checkWinner(Color color[5][6], Color inputColor) {
        bool AllBlack = true;
        bool SameColor = true;
        Color tmp;
        for ( int k = 0; k < 30; ++k ) {
            int i = k / 6;
            int j = k % 6;
            if ( color[i][j] != Black ) {
                tmp = color[i][j];
                break;
            }
        }
        for ( int i = 0; i < 5; ++i ) {
            if ( !AllBlack && !SameColor )
                break;
            for ( int j = 0; j < 6; ++j ) {
                if ( color[i][j] != Black )
                    AllBlack = false;
                if ( color[i][j] != Black && color[i][j] != tmp )
                    SameColor = false;
            }
        }
        if ( AllBlack )
            return TurnColor(inputColor);
        if ( SameColor )
            return tmp;
        return -1;
    }
    bool imitate(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
        if ( en == 30 ) {
            nextMove = 14;
            return true;
        }
        else {
            Color EnemyColor = TurnColor(inputColor);
            bool same = false;
            int k;
            for ( k = 0; k < 30; ++k ) {
                int i = k / 6, j = k % 6;
                if ( pre_Record[i][j] != Record[i][j] && color[i][j] != inputColor)
                    same = move_test(Record,Max,color,EnemyColor, i, j);
                if ( same ) {
                    if ( k == 14 || k == 15 )
                        return false;
                    int m = (29-k) / 6, n = (29-k) % 6;
                    if ( Record[m][n] >= Max[m][n] || color[m][n] == Black || color[m][n] == EnemyColor )
                        return false;
                    break;
                }
            }

            if ( same ) {
                nextMove = 29 - k;
                return true;
            }

            return false;
        }
    }
    bool move_test(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor, int row, int col) {
        int ChildRecord[5][6];
        Color ChildColor[5][6];
        for ( int i = 0; i < 5; ++i ) {
            for ( int j = 0; j < 6; ++j ) {
                ChildRecord[i][j] = pre_Record[i][j];
                ChildColor[i][j] = pre_color[i][j];
            }
        }
        queue<int> Q;
        Q.push(row); Q.push(col);
        while ( !Q.empty() ) {
            int r = Q.front(); Q.pop();
            int c = Q.front(); Q.pop();
            if ( ChildRecord[r][c] < Max[r][c] )
                ChildRecord[r][c]++;
            if ( ChildColor[r][c] == Black ) continue;
            ChildColor[r][c] = inputColor;
            if ( ChildRecord[r][c] == Max[r][c] ) {
                ChildColor[r][c] = Black;
                if ( r-1 >= 0 ) {
                    if (ChildColor[r-1][c] != Black) {
                        Q.push(r-1); Q.push(c);
                    }
                }
                if ( r+1 < 5 ) {
                    if (ChildColor[r+1][c] != Black) {
                        Q.push(r+1); Q.push(c);
                    }
                }
                if ( c-1 >= 0 ) {
                    if (ChildColor[r][c-1] != Black) {
                        Q.push(r); Q.push(c-1);
                    }
                }
                if ( c+1 < 6 ) {
                    if (ChildColor[r][c+1] != Black) {
                        Q.push(r); Q.push(c+1);
                    }
                }
            }
        }
        for ( int k = 0; k < 30; ++k ) {
            int i = k / 6, j = k % 6;
            if ( ChildRecord[i][j] != Record[i][j] || ChildColor[i][j] != color[i][j] )
                return false;
        }
        return true;
    }
    void Record_move(int Record[5][6], Color color[5][6], int Max[5][6], Color inputColor)
    {
        for ( int i = 0; i < 5; ++i )
        {
            for ( int j = 0; j < 6; ++j )
            {
                pre_Record[i][j] = Record[i][j];
                pre_color[i][j] = color[i][j];
            }
        }
        queue<int> Q;
        Q.push(x); Q.push(y);
        while ( !Q.empty() ) {
            int r = Q.front(); Q.pop();
            int c = Q.front(); Q.pop();
            if ( pre_Record[r][c] < Max[r][c] )
                pre_Record[r][c]++;
            if ( pre_color[r][c] == Black ) continue;
            pre_color[r][c] = inputColor;
            if ( pre_Record[r][c] == Max[r][c] ) {
                pre_color[r][c] = Black;
                if ( r-1 >= 0 ) {
                    if (pre_color[r-1][c] != Black) {
                        Q.push(r-1); Q.push(c);
                    }
                }
                if ( r+1 < 5 ) {
                    if (pre_color[r+1][c] != Black) {
                        Q.push(r+1); Q.push(c);
                    }
                }
                if ( c-1 >= 0 ) {
                    if (pre_color[r][c-1] != Black) {
                        Q.push(r); Q.push(c-1);
                    }
                }
                if ( c+1 < 6 ) {
                    if (pre_color[r][c+1] != Black) {
                        Q.push(r); Q.push(c+1);
                    }
                }
            }
        }
    }
    Color TurnColor(Color inputColor) {
        return (inputColor == Blue) ? Red : Blue;
    }
    int getX() { return x; }
    int getY() { return y; }
private:
    int x, y;
    int en, n_record, nextMove;
    int pre_Record[5][6] = {{}};
    Color pre_color[5][6] = {{}};
};