int FAIL=444;
    int DEFAULT_X=0;
    int DEFAULT_Y=0;

    typedef std::pair<int, int> Pair;
    typedef std::pair<int, Pair> t_Pair;
    class Student{
        public:
            Student(){}
            ~Student(){}
            void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
                ///declaration
                std::vector<t_Pair> can_kill;
                std::vector<t_Pair> can_domain;
                std::vector<t_Pair> can_defend;
                std::vector<t_Pair> can_place;

                analyst(Record, Max, color, inputColor, can_domain, can_kill, can_place, can_defend);
                decision_maker(Record, Max, color, inputColor, can_domain, can_kill, can_place, can_defend);
            }
            int getX(){return x;}
            int getY(){return y;}

        private:
            int x;
            int y;
            void analyst(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor,
                        std::vector<t_Pair>& can_domain, std::vector<t_Pair>& can_kill, std::vector<t_Pair>& can_place,
                        std::vector<t_Pair>& can_defend){
                ///declaration
                bool attack_area[5][6];
                bool threat_area[5][6];
                bool defend_area[5][6];
                int conceal_area[5][6];
                Color enemyColor = (inputColor == Blue)? Red : Blue;

                ///initialize
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        threat_area[i][j]=0;
                        attack_area[i][j]=0;
                        defend_area[i][j]=0;
                        conceal_area[i][j]=Max[i][j]-Record[i][j];
                    }
                }

                ///count treat, attack_area
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        if(Record[i][j]==Max[i][j]-1){
                            if(i!=0){
                                if(color[i][j]==enemyColor) threat_area[i-1][j]=1;
                                if(color[i][j]==inputColor) attack_area[i-1][j]=1;
                            }
                            if(i!=4){
                                if(color[i][j]==enemyColor) threat_area[i+1][j]=1;
                                if(color[i][j]==inputColor) attack_area[i+1][j]=1;
                            }
                            if(j!=0){
                                if(color[i][j]==enemyColor) threat_area[i][j-1]=1;
                                if(color[i][j]==inputColor) attack_area[i][j-1]=1;
                            }
                            if(j!=5){
                                if(color[i][j]==enemyColor) threat_area[i][j+1]=1;
                                if(color[i][j]==inputColor) attack_area[i][j+1]=1;
                            }
                        }
                    }
                }
                ///count defend_area
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        if(color[i][j]==enemyColor){
                            if(i!=0&&j!=0) defend_area[i-1][j-1]=1;//UP, LEFT
                            if(i!=4&&j!=0) defend_area[i+1][j-1]=1;//DOWN, LEFT
                            if(i!=0&&j!=5) defend_area[i-1][j+1]=1;//UP, RIGHT
                            if(i!=4&&j!=5) defend_area[i+1][j+1]=1;//DOWN, RIGHT
                        }
                    }
                }

                ///count can_domain
                for(int i=0;i<5;i++){
                    if(i==1||i==3) continue;
                    for(int j=0;j<6;j++){
                        if(j==1||j==4) continue;
                        bool color_flag = (color[i][j]==White)? 1 : 0;
                        bool ex_u = (i!=0)? (Record[i-1][j]==0) : 1;
                        bool ex_d = (i!=4)? (Record[i+1][j]==0) : 1;
                        bool ex_l = (j!=0)? (Record[i][j-1]==0) : 1;
                        bool ex_r = (j!=5)? (Record[i][j+1]==0) : 1;
                        if(ex_u&&ex_d&&ex_r&&ex_l&&color_flag){
                            can_domain.push_back({Max[i][j], {i, j}});
                        }
                    }
                }
                ///count can_kill
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        if(color[i][j]==enemyColor){
                            int ex = Max[i][j]-Record[i][j];
                            int ex_u = (i!=0&&threat_area[i][j]==0&&(color[i-1][j]==inputColor||color[i-1][j]==White))? conceal_area[i-1][j] : FAIL;
                            int ex_d = (i!=4&&threat_area[i][j]==0&&(color[i+1][j]==inputColor||color[i+1][j]==White))? conceal_area[i+1][j] : FAIL;
                            int ex_l = (j!=0&&threat_area[i][j]==0&&(color[i][j-1]==inputColor||color[i][j-1]==White))? conceal_area[i][j-1] : FAIL;
                            int ex_r = (j!=5&&threat_area[i][j]==0&&(color[i][j+1]==inputColor||color[i][j+1]==White))? conceal_area[i][j+1] : FAIL;
                            if(ex>=ex_u) can_kill.push_back({ex_u+color[i-1][j], {i-1, j}});
                            if(ex>=ex_d) can_kill.push_back({ex_d+color[i+1][j], {i+1, j}});
                            if(ex>=ex_l) can_kill.push_back({ex_l+color[i][j-1], {i, j-1}});
                            if(ex>=ex_r) can_kill.push_back({ex_r+color[i][j+1], {i, j+1}});
                        }
                    }
                }

                ///count can_place
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        if(color[i][j]==White||color[i][j]==inputColor){
                            can_place.push_back({threat_area[i][j], {i, j}});
                        }
                    }
                }

                ///count can_defend
                //the affiliated product of can_domain.
                for(int i=0;i<5;i++){
                    if(i==1||i==3) continue;
                    for(int j=0;j<6;j++){
                        if(j==1||j==4) continue;
                        if(color[i][j]!=inputColor) continue;
                        int ex = Max[i][j]-Record[i][j];
                        int ex_u = (i!=0&&!threat_area[i-1][j])? conceal_area[i-1][j] : FAIL;
                        int ex_d = (i!=4&&!threat_area[i+1][j])? conceal_area[i+1][j] : FAIL;
                        int ex_l = (j!=0&&!threat_area[i][j-1])? conceal_area[i][j-1] : FAIL;
                        int ex_r = (j!=5&&!threat_area[i][j+1])? conceal_area[i][j+1] : FAIL;
                        if(ex==ex_u||ex==ex_d||ex==ex_l||ex==ex_r){
                            can_defend.push_back({0-Record[i][j], {i, j}});
                        }
                    }
                }
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        if(!(color[i][j]==inputColor||color[i][j]==White)) continue;
                        bool ex_u = (i==0||color[i-1][j]==inputColor||conceal_area[i][j]>=conceal_area[i-1][j])? 1 : 0;
                        bool ex_d = (i==4||color[i+1][j]==inputColor||conceal_area[i][j]>=conceal_area[i+1][j])? 1 : 0;
                        bool ex_l = (j==0||color[i][j-1]==inputColor||conceal_area[i][j]>=conceal_area[i][j-1])? 1 : 0;
                        bool ex_r = (j==5||color[i][j+1]==inputColor||conceal_area[i][j]>=conceal_area[i][j+1])? 1 : 0;
                        if(defend_area[i][j]&&ex_u&&ex_d&&ex_l&&ex_r){
                            can_defend.push_back({0-Record[i][j], {i, j}});
                        }
                    }
                }
            }
            void decision_maker(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor,
                        std::vector<t_Pair>& can_domain, std::vector<t_Pair>& can_kill, std::vector<t_Pair>& can_place,
                        std::vector<t_Pair>& can_defend){
                std::sort(can_kill.begin(), can_kill.end());
                int s = can_kill.size();
                for(int i=0;i<s;i++){//std::cout<<"can_kill\n";
                        int tx = can_kill[i].second.first;
                        int ty = can_kill[i].second.second;
                        if(examine(Record, Max, color, inputColor, tx, ty)){x = tx; y = ty; return;}
                }

                if(!can_domain.empty()){//std::cout<<"can_domain\n";
                    std::sort(can_domain.begin(), can_domain.end());
                    x = can_domain.front().second.first;
                    y = can_domain.front().second.second;
                    return;
                }
                if(!can_defend.empty()){//std::cout<<"can_defend\n";
                    //std::sort(can_defend.begin(), can_defend.end());
                    x = can_defend.front().second.first;
                    y = can_defend.front().second.second;
                    return;
                }
                if(!can_place.empty()){//std::cout<<"can_place\n";
                    std::sort(can_place.begin(), can_place.end());
                    x = can_place.front().second.first;
                    y = can_place.front().second.second;
                    return;
                }
                x = DEFAULT_X;
                y = DEFAULT_Y;
                return;
            }
            bool examine(int Record[5][6], int Max[5][6], Color color[5][6], Color playerColor, int x, int y){
                Color enemyColor = (playerColor == Blue)? Red : Blue;
                int sim_Record[5][6];
                int sim_Max[5][6];
                Color sim_color[5][6];
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        sim_Record[i][j] = Record[i][j];
                        sim_Max[i][j] = Max[i][j];
                        sim_color[i][j] = color[i][j];
                    }
                }
                simulation(sim_Record, sim_Max, sim_color,playerColor, x, y);
                for(int i=0;i<5;i++){
                    for(int j=0;j<6;j++){
                        if(sim_color[i][j]==enemyColor&&sim_Record[i][j]==sim_Max[i][j]-1){
                            if(i!=0&&sim_Record[i-1][j]==sim_Max[i-1][j]-1&&color[i-1][j]==playerColor) return false;
                            if(i!=4&&sim_Record[i+1][j]==sim_Max[i+1][j]-1&&color[i+1][j]==playerColor) return false;
                            if(j!=0&&sim_Record[i][j-1]==sim_Max[i][j-1]-1&&color[i][j-1]==playerColor) return false;
                            if(j!=5&&sim_Record[i][j+1]==sim_Max[i][j+1]-1&&color[i][j+1]==playerColor) return false;
                        }
                    }
                }
                return true;
            }

            void simulation(int Record[5][6], int Max[5][6], Color color[5][6], Color playerColor, int x, int y){
                Color enemyColor = (playerColor == Blue)? Red : Blue;
                ///placement
                std::queue<std::pair<int, int>> chain_reaction;
                Record[x][y]++;
                color[x][y]=playerColor;
                if(Record[x][y]==Max[x][y]){
                    color[x][y]=Black;
                    chain_reaction.push({x-1, y});//UP
                    chain_reaction.push({x+1, y});//DOWN
                    chain_reaction.push({x, y-1});//LEFT
                    chain_reaction.push({x, y+1});//RIGHT
                }

                while(!chain_reaction.empty()){
                    //get.
                    std::pair<int, int> position = chain_reaction.front();
                    chain_reaction.pop();

                    //chain reaction.
                    int i = position.first;
                    int j = position.second;
                    if(i==-1||j==-1||i==5||j==6) continue;

                    if(color[i][j]!=Black)color[i][j] = playerColor;
                    if(color[i][j]!=Black)Record[i][j]++;

                    if(Record[i][j]==Max[i][j]&&color[i][j]!=Black){
                        color[i][j]=Black;
                        chain_reaction.push({i-1, j});//UP
                        chain_reaction.push({i+1, j});//DOWN
                        chain_reaction.push({i, j-1});//LEFT
                        chain_reaction.push({i, j+1});//RIGHT
                    }
                }
            }
    };
