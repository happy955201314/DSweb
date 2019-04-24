
    class gameTree{
    public:
        int xThis;
        int yThis;
        int board[5][6];
        Color color[5][6];
        int level;
        int childrenNum;
        long long score;
        gameTree* parent;
        vector<gameTree *> children;
    };

    class Student {
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            bool checkWhite = false;
            bool checkConner = false;
            bool checkEdge = false;
            bool checkCenter = false;

            int x_white, y_white;
            int x_conner, y_conner;
            int x_edge, y_edge;
            int x_center, y_center;

            createGameTree( Record, Max, color, inputColor);

            calculateScore(head, Max, inputColor);

            maxScore = -10000;

            queue<gameTree *> q;

            q.push(head);

            bool checker = false;

            while(q.empty()!=true){
                if(q.front()->level == 0){
                    for(int i=0; i<q.front()->children.size(); i++){
                        q.push(q.front()->children[i]);
                    }
                }else if(q.front()->level == 1){
                    if(q.front()->children.empty() == false){
                        for(int i=0; i<q.front()->children.size(); i++){
                            q.push(q.front()->children[i]);
                        }
                    }else{
                        maxNode = q.front();
                        checker = true;
                    }
                }else if(q.front()->level == 2){
                    if(q.front()->children.empty() == false){
                        for(int i=0; i<q.front()->children.size(); i++){
                            q.push(q.front()->children[i]);
                        }
                    }else{
                        q.front()->parent->score += -1000;
                        q.front()->parent->childrenNum += 1;
                    }
                }else if(q.front()->level == 3){
                    q.front()->parent->parent->score += q.front()->score;
                    q.front()->parent->parent->childrenNum += 1;
                }
                q.pop();
            }

            if(checker == false)
            for(int i=0; i<head->children.size();i++){
                if(head->children[i]->score > maxScore){
                    if(head->children[i]->childrenNum != 0){
                        long long sum = (long long)head->children[i]->score/head->children[i]->childrenNum;
                        if(sum > maxScore){
                            maxScore = sum;
                            maxNode = head->children[i];
                        }
                        //maxNode = head->children[i];
                    }
                }
            }

            x = maxNode->xThis;
            y = maxNode->yThis;
            deleteTree(head);
        }

        void calculateScore( gameTree* node, int _Max[5][6], Color _inputColor){
            if(node->level == 3) {
                node->score = score(node->board, _Max, node->color, _inputColor);
            }else{
                for(int i=0; i<node->children.size(); i++){
                    calculateScore(node->children[i], _Max, _inputColor);
                }
            }
        }

        void deleteTree( gameTree* node){

            if(node == NULL) return;
            if(node->children.empty() == false){
                for(int i=0; i<node->children.size(); i++){
                    deleteTree(node->children[i]);
                }
            }

            delete(node);
        }

        void createGameTree(int Record[5][6], int _Max[5][6], Color color[5][6], Color inputColor){

            head = new gameTree;

            for(int i=0; i<5; i++){
                for(int j=0; j<6; j++){
                    head->board[i][j] = Record[i][j];
                    head->color[i][j] = color[i][j];
                }
            }

            head->level = 0;
            head->xThis = -1;
            head->yThis = -1;
            head->parent = NULL;
            head->score = 0;
            head->childrenNum = 0;

            head->children = getChildrenPoint( head, _Max, inputColor);

            if(inputColor == Blue) inputColor = Red;
            else inputColor = Blue;

            for(int i=0; i<head->children.size(); i++)
                createGameTreePartTwo( 1, head->children[i], _Max, inputColor);
        }

        void createGameTreePartTwo(int level,gameTree *node, int _Max[5][6], Color _inputColor){
            node->children = getChildrenPoint( node, _Max, _inputColor);

            if(level != 2){
                if(_inputColor == Red) _inputColor = Blue;
                else _inputColor = Red;
                for(int i=0; i<node->children.size(); i++)
                    createGameTreePartTwo( level+1, node->children[i], _Max, _inputColor);
            }
        }
        // return all the node you can choice
        vector<gameTree*> getChildrenPoint( gameTree *node, int _Max[5][6], Color _inputColor){
            int checkThrough[5][6] = {0};

            vector<gameTree* > l;
            queue<pair<int,int> > bfs;

            for(int i=0; i<5; i++){
                for(int j=0; j<6; j++){
                    if(checkThrough[i][j] == 0 && (node->color[i][j] == _inputColor || node->color[i][j] == White)){

                        checkThrough[i][j] = 1;

                        gameTree *newNode = new gameTree;
                        newNode->xThis = i;
                        newNode->yThis = j;
                        newNode->level = node->level+1;
                        newNode->parent = node;
                        newNode->score = 0;
                        newNode->childrenNum = 0;

                        for(int k=0; k<5; k++){
                            for(int l=0; l<6; l++){
                                newNode->board[k][l] = node->board[k][l];
                                newNode->color[k][l] = node->color[k][l];
                            }
                        }

                        l.push_back(newNode);

                        newNode->board[i][j] ++;
                        newNode->color[i][j] = _inputColor;

                        if(newNode->board[i][j] == _Max[i][j]) {
                            bfs.push(make_pair(i,j));
                            newNode->color[i][j] = Black;
                        }
                        while(bfs.empty() == false){
                            checkThrough[bfs.front().first][bfs.front().second] = 1;

                            if(bfs.front().first-1 >= 0){
                                if(newNode->color[bfs.front().first-1][bfs.front().second] != Black){
                                    newNode->board[bfs.front().first-1][bfs.front().second] ++;
                                    newNode->color[bfs.front().first-1][bfs.front().second] = _inputColor;
                                    if(newNode->board[bfs.front().first-1][bfs.front().second] == _Max[bfs.front().first-1][bfs.front().second]){
                                        newNode->color[bfs.front().first-1][bfs.front().second] = Black;
                                        bfs.push(make_pair(bfs.front().first-1,bfs.front().second));
                                    }
                                }
                            }
                            if(bfs.front().first+1 <= 4){
                                if(newNode->color[bfs.front().first+1][bfs.front().second] != Black){
                                    newNode->board[bfs.front().first+1][bfs.front().second] ++;
                                    newNode->color[bfs.front().first+1][bfs.front().second] = _inputColor;
                                    if(newNode->board[bfs.front().first+1][bfs.front().second] == _Max[bfs.front().first+1][bfs.front().second]){
                                        newNode->color[bfs.front().first+1][bfs.front().second] = Black;
                                        bfs.push(make_pair(bfs.front().first+1,bfs.front().second));
                                    }
                                }
                            }
                            if(bfs.front().second-1 >= 0){
                                if(newNode->color[bfs.front().first][bfs.front().second-1] != Black){
                                    newNode->board[bfs.front().first][bfs.front().second-1] ++;
                                    newNode->color[bfs.front().first][bfs.front().second-1] = _inputColor;
                                    if(newNode->board[bfs.front().first][bfs.front().second-1] == _Max[bfs.front().first][bfs.front().second-1]){
                                        newNode->color[bfs.front().first][bfs.front().second-1] = Black;
                                        bfs.push(make_pair(bfs.front().first,bfs.front().second-1));
                                    }
                                }
                            }
                            if(bfs.front().second+1 <= 5){
                                if(newNode->color[bfs.front().first][bfs.front().second+1] != Black){
                                    newNode->board[bfs.front().first][bfs.front().second+1] ++;
                                    newNode->color[bfs.front().first][bfs.front().second+1] = _inputColor;
                                    if(newNode->board[bfs.front().first][bfs.front().second+1] == _Max[bfs.front().first][bfs.front().second+1]){
                                        newNode->color[bfs.front().first][bfs.front().second+1] = Black;
                                        bfs.push(make_pair(bfs.front().first,bfs.front().second+1));
                                    }
                                }
                            }
                            bfs.pop();
                        }
                    }
                }
            }

            return l;
        }

        int getX(){
            return x;
        }
        int getY(){
            return y;
        }


    private:
        gameTree *head;
        gameTree *maxNode;
        long long maxScore;
        int x;
        int y;

        int score(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor) {
            int score=0, enemy_orbs=0, my_orbs=0, black_orbs=0, white_orbs=0;
            bool myCriticalCell[5][6];
            bool enemyCriticalCell[5][6];
            Color enemyColor;
            if(inputColor == Red) enemyColor = Blue;
            else enemyColor = Red;

            for(int i=0; i<5; i++){
                for(int j=0; j<6; j++){
                    if(color[i][j] == inputColor){
                        bool vulnerable = true;
                        my_orbs += Record[i][j];
                        if(i-1>=0) if(Record[i-1][j] == Max[i-1][j] -1) {score -= 5-Max[i][j]; vulnerable = false;}
                        if(i+1<=4) if(Record[i+1][j] == Max[i+1][j] -1) {score -= 5-Max[i][j]; vulnerable = false;}
                        if(j-1>=0) if(Record[i][j-1] == Max[i][j-1] -1) {score -= 5-Max[i][j]; vulnerable = false;}
                        if(j+1<=5) if(Record[i][j+1] == Max[i][j+1] -1) {score -= 5-Max[i][j]; vulnerable = false;}
                        if(vulnerable == true){
                            if(Max[i][j] == 3) score += 2;
                            else if(Max[i][j] == 2) score += 3;
                            if(Record[i][j] == Max[i][j]-1) score += 2;
                        }
                    }else if(color[i][j] == enemyColor) enemy_orbs += Record[i][j];
                    else if(color[i][j] == Black) black_orbs += 1;
                    else white_orbs += 1;
                }
            }

            score += my_orbs;
            score += black_orbs;

            if(enemy_orbs == 0 && white_orbs == 0) return 1000;
            if(my_orbs == 0 && white_orbs == 0) return -1000;

            return score;
        }
    };


