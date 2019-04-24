    enum Pick {_MAX, _MIN};

    enum Dir {UP, DOWN, LEFT, RIGHT};

    const char _DAYE[4] = {-1, 1, 0, 0};
    const char _DJAY[4] = {0, 0, -1, 1};
    const int MAXDEPTH = 5;
    const int DISLIKE = 123456;
    const int NOWAY = 654321;
    bool maxRecorded = false;

    inline Pick oppoPick(Pick p) {return p == _MAX ? _MIN : _MAX;}
    inline Color oppoColor(Color c) {return c == Blue ? Red : Blue;}


    struct GameState
    {
        char record[5][6];
        char max[5][6];
        Color color[5][6];
        char streakID[5][6];
        char streakCount[15];
        Color ratingColor;
        Color placingColor;
        bool rated;
        short rating;
        bool won;
        bool noCritEnemy = true;
        char streakCursor = 1;


        GameState(int r[5][6], int m[5][6], Color c[5][6], Color rc, Color pc) {
            { // record
                record[0][0] = r[0][0];
                record[0][1] = r[0][1];
                record[0][2] = r[0][2];
                record[0][3] = r[0][3];
                record[0][4] = r[0][4];
                record[0][5] = r[0][5];
                record[1][0] = r[1][0];
                record[1][1] = r[1][1];
                record[1][2] = r[1][2];
                record[1][3] = r[1][3];
                record[1][4] = r[1][4];
                record[1][5] = r[1][5];
                record[2][0] = r[2][0];
                record[2][1] = r[2][1];
                record[2][2] = r[2][2];
                record[2][3] = r[2][3];
                record[2][4] = r[2][4];
                record[2][5] = r[2][5];
                record[3][0] = r[3][0];
                record[3][1] = r[3][1];
                record[3][2] = r[3][2];
                record[3][3] = r[3][3];
                record[3][4] = r[3][4];
                record[3][5] = r[3][5];
                record[4][0] = r[4][0];
                record[4][1] = r[4][1];
                record[4][2] = r[4][2];
                record[4][3] = r[4][3];
                record[4][4] = r[4][4];
                record[4][5] = r[4][5];
            }
            { // max
                max[0][0] = m[0][0];
                max[0][1] = m[0][1];
                max[0][2] = m[0][2];
                max[0][3] = m[0][3];
                max[0][4] = m[0][4];
                max[0][5] = m[0][5];
                max[1][0] = m[1][0];
                max[1][1] = m[1][1];
                max[1][2] = m[1][2];
                max[1][3] = m[1][3];
                max[1][4] = m[1][4];
                max[1][5] = m[1][5];
                max[2][0] = m[2][0];
                max[2][1] = m[2][1];
                max[2][2] = m[2][2];
                max[2][3] = m[2][3];
                max[2][4] = m[2][4];
                max[2][5] = m[2][5];
                max[3][0] = m[3][0];
                max[3][1] = m[3][1];
                max[3][2] = m[3][2];
                max[3][3] = m[3][3];
                max[3][4] = m[3][4];
                max[3][5] = m[3][5];
                max[4][0] = m[4][0];
                max[4][1] = m[4][1];
                max[4][2] = m[4][2];
                max[4][3] = m[4][3];
                max[4][4] = m[4][4];
                max[4][5] = m[4][5];
            }
            { // color
                color[0][0] = c[0][0];
                color[0][1] = c[0][1];
                color[0][2] = c[0][2];
                color[0][3] = c[0][3];
                color[0][4] = c[0][4];
                color[0][5] = c[0][5];
                color[1][0] = c[1][0];
                color[1][1] = c[1][1];
                color[1][2] = c[1][2];
                color[1][3] = c[1][3];
                color[1][4] = c[1][4];
                color[1][5] = c[1][5];
                color[2][0] = c[2][0];
                color[2][1] = c[2][1];
                color[2][2] = c[2][2];
                color[2][3] = c[2][3];
                color[2][4] = c[2][4];
                color[2][5] = c[2][5];
                color[3][0] = c[3][0];
                color[3][1] = c[3][1];
                color[3][2] = c[3][2];
                color[3][3] = c[3][3];
                color[3][4] = c[3][4];
                color[3][5] = c[3][5];
                color[4][0] = c[4][0];
                color[4][1] = c[4][1];
                color[4][2] = c[4][2];
                color[4][3] = c[4][3];
                color[4][4] = c[4][4];
                color[4][5] = c[4][5];
            }
            memset(streakID, 0, sizeof(char)*30);
            memset(streakCount, 0, sizeof(char)*15);
            ratingColor = rc;
            placingColor = pc;
            rated = false;
            rating = 0;
        }
        GameState(GameState*& gs, bool changePC) {
            { // record
                record[0][0] = gs->record[0][0];
                record[0][1] = gs->record[0][1];
                record[0][2] = gs->record[0][2];
                record[0][3] = gs->record[0][3];
                record[0][4] = gs->record[0][4];
                record[0][5] = gs->record[0][5];
                record[1][0] = gs->record[1][0];
                record[1][1] = gs->record[1][1];
                record[1][2] = gs->record[1][2];
                record[1][3] = gs->record[1][3];
                record[1][4] = gs->record[1][4];
                record[1][5] = gs->record[1][5];
                record[2][0] = gs->record[2][0];
                record[2][1] = gs->record[2][1];
                record[2][2] = gs->record[2][2];
                record[2][3] = gs->record[2][3];
                record[2][4] = gs->record[2][4];
                record[2][5] = gs->record[2][5];
                record[3][0] = gs->record[3][0];
                record[3][1] = gs->record[3][1];
                record[3][2] = gs->record[3][2];
                record[3][3] = gs->record[3][3];
                record[3][4] = gs->record[3][4];
                record[3][5] = gs->record[3][5];
                record[4][0] = gs->record[4][0];
                record[4][1] = gs->record[4][1];
                record[4][2] = gs->record[4][2];
                record[4][3] = gs->record[4][3];
                record[4][4] = gs->record[4][4];
                record[4][5] = gs->record[4][5];
            }
            { // max
                maxRecorded = true;
                max[0][0] = gs->max[0][0];
                max[0][1] = gs->max[0][1];
                max[0][2] = gs->max[0][2];
                max[0][3] = gs->max[0][3];
                max[0][4] = gs->max[0][4];
                max[0][5] = gs->max[0][5];
                max[1][0] = gs->max[1][0];
                max[1][1] = gs->max[1][1];
                max[1][2] = gs->max[1][2];
                max[1][3] = gs->max[1][3];
                max[1][4] = gs->max[1][4];
                max[1][5] = gs->max[1][5];
                max[2][0] = gs->max[2][0];
                max[2][1] = gs->max[2][1];
                max[2][2] = gs->max[2][2];
                max[2][3] = gs->max[2][3];
                max[2][4] = gs->max[2][4];
                max[2][5] = gs->max[2][5];
                max[3][0] = gs->max[3][0];
                max[3][1] = gs->max[3][1];
                max[3][2] = gs->max[3][2];
                max[3][3] = gs->max[3][3];
                max[3][4] = gs->max[3][4];
                max[3][5] = gs->max[3][5];
                max[4][0] = gs->max[4][0];
                max[4][1] = gs->max[4][1];
                max[4][2] = gs->max[4][2];
                max[4][3] = gs->max[4][3];
                max[4][4] = gs->max[4][4];
                max[4][5] = gs->max[4][5];
            }
            { // color
                color[0][0] = gs->color[0][0];
                color[0][1] = gs->color[0][1];
                color[0][2] = gs->color[0][2];
                color[0][3] = gs->color[0][3];
                color[0][4] = gs->color[0][4];
                color[0][5] = gs->color[0][5];
                color[1][0] = gs->color[1][0];
                color[1][1] = gs->color[1][1];
                color[1][2] = gs->color[1][2];
                color[1][3] = gs->color[1][3];
                color[1][4] = gs->color[1][4];
                color[1][5] = gs->color[1][5];
                color[2][0] = gs->color[2][0];
                color[2][1] = gs->color[2][1];
                color[2][2] = gs->color[2][2];
                color[2][3] = gs->color[2][3];
                color[2][4] = gs->color[2][4];
                color[2][5] = gs->color[2][5];
                color[3][0] = gs->color[3][0];
                color[3][1] = gs->color[3][1];
                color[3][2] = gs->color[3][2];
                color[3][3] = gs->color[3][3];
                color[3][4] = gs->color[3][4];
                color[3][5] = gs->color[3][5];
                color[4][0] = gs->color[4][0];
                color[4][1] = gs->color[4][1];
                color[4][2] = gs->color[4][2];
                color[4][3] = gs->color[4][3];
                color[4][4] = gs->color[4][4];
                color[4][5] = gs->color[4][5];
            }
            ratingColor = gs->ratingColor;
            placingColor = !changePC ? gs->placingColor : oppoColor((Color)gs->placingColor);
            rated = false;
            rating = 0;
        }

        inline void ChangePlacingColor() {
            if (placingColor == Blue) placingColor = Red;
            else if (placingColor == Red) placingColor = Blue;
            else {
                printf("[ERROR]  Changing color of cell other than blue or red\n");
            }
        }

        void PlaceOrb(int x, int y) {
            rated = false;
            rating = 0;

            if (color[x][y] == (placingColor == Blue ? Red : Blue)) {
                //log("\n///////////////////////////////////////////////\n");
                //log("[ERROR]  Wrong color!  placing %c @ %d, %d\n", "WBRX"[placingColor], x, y);
                //PrintAll();
                //log("///////////////////////////////////////////////\n\n");
                exit(1);
            }

            if (record[x][y] + 1 < max[x][y]) {
            // peace.
                color[x][y] = placingColor;
                record[x][y] ++;
            } else {
            // EXPLOOOOSION!!
                queue< pair<int, int> > addedCell;
                // record[x][y] = 0; doesn't matter
                color[x][y] = Black;

                for (int i=0; i<4; i++) {
                    if (IsValidPos(x + _DAYE[i], y + _DJAY[i])) {
                        if (color[x + _DAYE[i]][y + _DJAY[i]] != Black) {
                            if (color[x + _DAYE[i]][y + _DJAY[i]] != placingColor)
                                color[x + _DAYE[i]][y + _DJAY[i]] = placingColor;
                            record[x + _DAYE[i]][y + _DJAY[i]] ++;
                            addedCell.push(pair<int, int>(x + _DAYE[i], y + _DJAY[i]));
                        }
                    }
                }

                while (addedCell.size() > 0) {
                    pair<int, int> pos = addedCell.front();
                    addedCell.pop();
                    if (record[pos.first][pos.second] < max[pos.first][pos.second]) {
                    // peace.
                    } else {
                    // EXPLOOOOSION!!
                        // record[pos.first][pos.second] -= max[pos.first][pos.second];  doesn't matter
                        color[pos.first][pos.second] = Black;
                        for (int i=0; i<4; i++) {
                            if (IsValidPos(pos.first + _DAYE[i], pos.second + _DJAY[i])) {
                                if (color[pos.first + _DAYE[i]][pos.second + _DJAY[i]] != Black) {
                                    if (color[pos.first + _DAYE[i]][pos.second + _DJAY[i]] != placingColor)
                                        color[pos.first + _DAYE[i]][pos.second + _DJAY[i]] = placingColor;
                                    record[pos.first + _DAYE[i]][pos.second + _DJAY[i]] ++;
                                    addedCell.push(pair<int, int>(pos.first + _DAYE[i], pos.second + _DJAY[i]));
                                }
                            }
                        }
                    }
                }
            }

            ////log("Placed %c @ %d, %d\n\n", "WBRX"[placingColor], x, y);
        }
        int Rating() {
            for (int aye = 0; aye < 5; aye++) {
                for (int jay = 0; jay < 6; jay++) {
                    int value = 0;
                    if (color[aye][jay] != Black && color[aye][jay] != White) {
                        if (record[aye][jay] + 1 >= max[aye][jay]) {
                            value += max[aye][jay] * 4;
                        } else {
                            value += record[aye][jay];
                        }

                        if (color[aye][jay] == ratingColor) {
                            rating += value;
                        } else {
                            rating -= value;
                        }
                    }
                }
            }
        }
        /*
        int Rating() {
            if (rated) {
                return rating;
            } else {
                won = true;
                rated = true;
                rating = 0;

                for (int aye = 0; aye < 5; aye++) {
                    for (int jay = 0; jay < 6; jay++) {

                        if (color[aye][jay] == ratingColor) {
                            for (int i = 0; i < 4; i++) {
                                if (IsValidPos(aye + _DAYE[i], jay + _DJAY[i])) {
                                    if (record[aye + _DAYE[i]][jay + _DJAY[i]] + 1 >= max[aye + _DAYE[i]][jay + _DJAY[i]]) {
                                        if (color[aye + _DAYE[i]][jay + _DJAY[i]] == oppoColor(ratingColor)) {
                                            rating -= (5 - max[aye + _DAYE[i]][jay + _DJAY[i]]) * record[aye][jay];
                                            noCritEnemy = false;
                                        } else {
                                            if (record[aye][jay] + 1 >= max[aye][jay]) {
                                                if (streakID[aye][jay] == 0) {
                                                    streakID[aye][jay] = streakCursor++;
                                                    streakCount[streakID[aye][jay]] ++;
                                                }
                                                if (streakID[aye + _DAYE[i]][jay + _DJAY[i]] == 0) {
                                                    streakID[aye + _DAYE[i]][jay + _DJAY[i]] = streakID[aye][jay];
                                                    streakCount[streakID[aye][jay]] ++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if (noCritEnemy) {
                                if (max[aye][jay] != 4) {
                                    rating += (4 - max[aye][jay]) * record[aye][jay];
                                }

                                if (record[aye][jay] + 1 >= max[aye][jay]) {
                                    rating += 2;
                                }
                            }
                            rating += record[aye][jay];
                            for (int i = 1; i < streakCursor; i++) {
                                rating += streakCount[i] * 2;
                            }
                        } else if (color[aye][jay] == oppoColor(ratingColor)) {
                            won = false;
                        }
                    }
                }

                if (won) {
                    return 10000;
                }
                return rating;
            }
        }
        */

        inline bool IsValidPos(int x, int y) {
            return x >= 0 && x <= 4 && y >= 0 && y <= 5;
        }

        void PrintAll() {
            printf("All:\tplacing: %c, rating: %c\n", "WBRX"[placingColor], "WBRX"[ratingColor]);
            for (int aye = 0; aye < 5; aye++) {
                for (int jay = 0; jay < 6; jay++) {
                    if (color[aye][jay] == White || color[aye][jay] == Black) {
                        printf("%c   ", "wbrX"[color[aye][jay]]);
                    } else {
                        printf("%c%d  ", "wbrX"[color[aye][jay]], record[aye][jay]);
                    }
                }
                printf("\n");
            }
            //printf("\n");
        }
    };


    inline void DBPA(GameState*& gs) {
        //gs->PrintAll();
    }
    inline void DBPA(GameState& gs) {
        //gs.PrintAll();
    }

    struct Node
    {
        Node(Pick p, int d, int par_fav, int r[5][6], int m[5][6], Color c[5][6], Color rc, Color pc) :
            pick(p), base(new GameState(r,m,c,rc,pc)), parent_fav_rating(par_fav), depth(d) {
            fav_rating = (p == _MAX) ? -99999 : 99999;
        }
        Node(Pick p, int d, int par_fav, GameState* b) : pick(p), base(new GameState(b, true)), parent_fav_rating(par_fav), depth(d) {
            fav_rating = (p == _MAX) ? -99999 : 99999;
        }
        ~Node() {
            delete base;
        }


        int GetBestRating() {
            //log("Getting best rating of...\n");
            DBPA(base);
            if (depth+1 >= MAXDEPTH) {
                while(CurrPosValid()) {
                    if ( ! (base->color[curr_x][curr_y] == oppoColor((Color)base->placingColor) || base->color[curr_x][curr_y] == White)) {
                    // if we can't place orb here
                        AdvancePos();
                        continue;
                    }
                    atLeast1Way = true;
                    //log("@Depth %d(2nd to last), Can be placed @ %d %d\n", depth, curr_x, curr_y);
                    tmpState = new GameState(base, true);
                    tmpState->PlaceOrb(curr_x, curr_y);
                    tmpRating = tmpState->Rating();
                    DBPA(tmpState);
                    //log("\tRating = %d\n", tmpRating);


                    delete tmpState;

                    if (pick == _MAX) {
                    // if we should pick the maximum rating at this level,
                    //   once a rating higher than the parent_fav_rating appears, we can stop checking.
                    // Because the parent will not choose a route that have less favorable outcome for them.
                        if (tmpRating > parent_fav_rating) {
                            //log("[SKIP]  picking MAX @ depth %d, parent_fav_rating: %d, found rating:%d @ %d %d.\n", depth+1, parent_fav_rating, tmpRating, curr_x, curr_y);
                            return DISLIKE;
                        }

                        if (tmpRating > fav_rating) {
                            //log("Noice.  best so far was %d.\n", fav_rating);
                            fav_rating = tmpRating;
                        } else {
                            //log("\tNot better than %d, HIGHER!\n", fav_rating);
                        }
                    } else { // if pick == _MIN
                        if (tmpRating < parent_fav_rating) {
                            //log("[SKIP]  picking MIN @ depth %d, parent_fav_rating: %d, found rating:%d @ %d %d.\n", depth+1, parent_fav_rating, tmpRating, curr_x, curr_y);
                            return DISLIKE;
                        }

                        if (tmpRating < fav_rating) {
                            //log("Noice.  best so far was %d.\n", fav_rating);
                            fav_rating = tmpRating;
                        } else {
                            //log("\tNot better than %d, LOWER!\n", fav_rating);
                        }
                    }
                    AdvancePos();
                }
                if (atLeast1Way) {
                    //log("So, depth %d...\n", depth);
                    DBPA(base);
                    // should have chosen a position...
                    //log("has best rating of %d.\n", fav_rating);
                    return fav_rating;
                } else {
                    //log("So, depth %d...");
                    DBPA(base);
                    //log("Has no where to place orb.  Guess I'll die.\n");
                    return NOWAY;
                }
            } else { // this is internal level,
                while(CurrPosValid()) {
                    if ( ! (base->color[curr_x][curr_y] == oppoColor((Color)base->placingColor) || base->color[curr_x][curr_y] == White)) {
                    // if we can't place orb here
                        AdvancePos();
                        continue;
                    }
                    // else we CAN place orb here.
                    atLeast1Way = true;
                    //log("@Depth %d, Can be placed @ %d %d\n", depth, curr_x, curr_y);
                    tmpNode = new Node(oppoPick(pick), depth+1, fav_rating, base);
                    tmpNode->PlaceOrb(curr_x, curr_y);
                    tmpRating = tmpNode->GetBestRating();
                    DBPA(tmpNode->base);
                    //log("\tRating = %d\n", tmpRating);

                    delete tmpNode;

                    if (tmpRating == DISLIKE) {
                    // if the node produces unfavorable rating, do nothing, check next pos.
                        //log("Ahh...  A more favorable rating for depth %d appeared(%d), but we @ depth %d do not want that, do we?\n", depth+1, tmpRating, depth);
                    } else if (tmpRating == NOWAY) {
                    // Guess we won?
                        //log("Guess @ depth %d it managed to eliminate all enemy...  ", depth);
                        if (pick == _MAX) {
                            //log("return rating: 10000\n");
                            return 10000;
                        } else {
                            //log("return rating: -10000\n");
                            return -10000;
                        }
                    } else {
                    // else tmpRating may hold better rating.
                        if (pick == _MAX) {
                            if (tmpRating > parent_fav_rating) {
                                //log("[SKIP]  picking MAX @ depth %d, parent_fav_rating: %d, found rating:%d @ %d %d.\n", depth, parent_fav_rating, tmpRating, curr_x, curr_y);
                                return DISLIKE;
                            }

                            if (tmpRating > fav_rating) {
                                //log("Noice.  best so far was %d.\n", fav_rating);
                                fav_rating = tmpRating;
                            } else {
                                //log("\tNot better than %d, HIGHER!\n", fav_rating);
                            }
                        } else { // if (pick == _MIN)
                            if (tmpRating < parent_fav_rating) {
                                //log("[SKIP]  picking MIN @ depth %d, parent_fav_rating: %d, found rating:%d @ %d %d.\n", depth, parent_fav_rating, tmpRating, curr_x, curr_y);
                                return DISLIKE;
                            }

                            if (tmpRating < fav_rating) {
                                //log("Noice.  best so far was %d.\n", fav_rating);
                                fav_rating = tmpRating;
                            } else {
                                //log("\tNot better than %d, LOWER!\n", fav_rating);
                            }
                        }
                    }
                    AdvancePos();
                }
                if (atLeast1Way) {
                    return fav_rating;
                } else {
                    return NOWAY;
                }
            }
        }


        void PlaceOrb(int x, int y) {
            base->PlaceOrb(x, y);
        }

        void AdvancePos() {
            if (curr_y >= 5) {
                curr_y = 0;
                curr_x ++;
            } else {
                curr_y++;
            }
        }
        bool CurrPosValid() {
            return curr_x <= 4 && curr_y <= 5;
        }

        Pick pick;
        GameState* base;
        GameState* tmpState;
        Node* tmpNode;
        int parent_fav_rating;
        int tmpRating;
        int curr_x = 0, curr_y = 0;
        //int fav_x = 0, fav_y = 0;
        int fav_rating;
        int depth = 1;
        bool atLeast1Way = false;
    };

    class Student{
    public:
        void makeMove(int record[5][6], int max[5][6], Color color[5][6], Color inputColor){
            int fav_rating = -99999;
            int fav_x, fav_y;
            int tmpRating;
            Node* tmpNode;
            GameState dbGS(record, max, color, inputColor, inputColor);

            //log("Making move...  Starting state:\n");
            DBPA(dbGS);
            //log("\n");

            for (int aye = 0; aye < 5; aye++) {
                for (int jay = 0; jay < 6; jay++) {
                    if (color[aye][jay] == inputColor || color[aye][jay] == White) {
                        tmpNode = new Node(_MIN, 2, fav_rating, record, max, color, inputColor, inputColor);
                        //log("Can place %c @ %d %d:\n", "WBRX"[inputColor], aye, jay);
                        tmpNode->PlaceOrb(aye, jay);
                        DBPA(tmpNode->base);
                        tmpRating = tmpNode->GetBestRating();

                        //log("\t@%2d, %2d  Rating: %d\n", aye, jay, tmpRating);

                        delete tmpNode;
                        if (tmpRating == DISLIKE) {

                        } else if (tmpRating > fav_rating) {
                            fav_rating = tmpRating;
                            fav_x = aye;
                            fav_y = jay;
                        }
                    }
                }
            }
            _x = fav_x;
            _y = fav_y;
            _rating = fav_rating;
        }
        // Any Code You Want to Add
        int getX(){
            return _x;
        }
        int getY(){
            return _y;
        }
        int getRating(){
            return _rating;
        }
    private:
        int _x;
        int _y;
        int _rating;

    };
