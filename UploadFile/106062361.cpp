class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            // Your Code
            if(occupy_corner(color)) return;
            else {       
                vector<int>Blue_x, Blue_y, Red_x, Red_y;
                int target_x, target_y;
                for(int i=0; i<5; i++) {
                    for(int j=0; j<6; j++) {
                        if(color[i][j]==Blue) {
                            Blue_x.push_back(i);
                            Blue_y.push_back(j);
                        }
                        else if(color[i][j]==Red) {
                            Red_x.push_back(i);
                            Red_y.push_back(j);
                        }
                    }
                }
                for(int i=0; i<Blue_x.size(); i++) {
                    if(Record[Blue_x[i]][Blue_y[i]]==Max[Blue_x[i]][Blue_y[i]]-1 && (
                    TriggerBomb(color, Record, Max, Blue_x[i]-1, Blue_y[i]) ||
                    TriggerBomb(color, Record, Max, Blue_x[i]+1, Blue_y[i]) ||
                    TriggerBomb(color, Record, Max, Blue_x[i], Blue_y[i]-1) ||
                    TriggerBomb(color, Record, Max, Blue_x[i], Blue_y[i]+1))) return;
                }
                for(int step=1; step<=4; step++){
                    for(int i=0; i<Blue_x.size(); i++) {
                        if(MakeBomb(color, Record, Max, Blue_x[i]-1, Blue_y[i], step) ||
                        MakeBomb(color, Record, Max, Blue_x[i]+1, Blue_y[i], step) ||
                        MakeBomb(color, Record, Max, Blue_x[i], Blue_y[i]-1, step) ||
                        MakeBomb(color, Record, Max, Blue_x[i], Blue_y[i]+1, step)) return;
                    }
                }
                if(!addGuard(color)) {
                    for(int step=1; step<=4; step++) {
                        for(int i=0; i<5; i++) {
                            for(int j=0; j<6; j++) {
                                if(MakeBomb(color, Record, Max, i, j, step)) return;
                            }
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
        int count = 0;
        int corner_flag = 0;
        int x;
        int y;
        vector<int> home_x, home_y;

        bool SetIfWhite(Color color[5][6], int i, int j) {
            if(i>=0 && i<5 && j>=0 && j<6 && color[i][j]==White) {
                x = i, y = j;
                home_x.push_back(i);
                home_y.push_back(j);
                return true;
            } else return false;
        }
        bool TriggerBomb(Color color[5][6], int Record[5][6], int Max[5][6], int i, int j) {
            if(i>=0 && i<5 && j>=0 && j<6 && (color[i][j]==Red||color[i][j]==White) && Record[i][j]==Max[i][j]-1) {
                x = i, y = j;
                return true;
            }
            return false;
        }
        bool MakeBomb(Color color[5][6], int Record[5][6], int Max[5][6], int i, int j, int step) {
            if(i>=0 && i<5 && j>=0 && j<6 && (color[i][j]==Red||color[i][j]==White) && Record[i][j]==Max[i][j]-step) {
                x = i, y = j;
                if(isBomb(color, Record, Max, i+1, j) ||
                isBomb(color, Record, Max, i-1, j) ||
                isBomb(color, Record, Max, i, j+1) ||
                isBomb(color, Record, Max, i, j-1)) return false;
                else return true;
            }
            return false;
        }
        bool isBomb(Color color[5][6], int Record[5][6], int Max[5][6], int i, int j) {
            if(i>=0 && i<5 && j>=0 && j<6 && color[i][j]==Blue && Record[i][j]==Max[i][j]-1) return true;
            else return false;
        }
        bool occupy_corner(Color color[5][6]) {
            if(corner_flag) return false;
            else if(SetIfWhite(color, 0, 0) ||
            SetIfWhite(color, 0, 5) ||
            SetIfWhite(color, 4, 0) ||
            SetIfWhite(color, 4, 5)) return true;
            else corner_flag = 1;
            return false;
        }
        bool addGuard(Color color[5][6]) {
            for(int step=1; step<4; step++) {
                for(int i=0; i<home_x.size(); i++) {
                    if(SetIfWhite(color, home_x[i]+step, home_y[i]) ||
                    SetIfWhite(color, home_x[i]-step, home_y[i]) ||
                    SetIfWhite(color, home_x[i], home_y[i]+step) ||
                    SetIfWhite(color, home_x[i], home_y[i]-step)) return true;
                }
            }
            return false;
        }
        /*bool homeDanger(int Record[5][6], int Max[5][6], Color color[5][6]) {
            for(auto v : home) {
                if(color[v[0]][v[1]]==Blue && )
            }
        }*/

};
