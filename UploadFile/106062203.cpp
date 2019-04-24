
const int H = 5;
const int W = 6;
const int INF = 2000000000;
const int MAX_DIR = 4;
struct Point {
	int y, x;

	inline bool operator==(const Point& rhs) {
		return y == rhs.y && x == rhs.x;
	}
};

const Point dir[MAX_DIR] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Board {
	int b[H][W];

	inline void copy_arr(const int from[H][W], int to[H][W]) {
		std::copy(&from[0][0], &from[0][0] + H*W, &to[0][0]);
	}
public:
	// b[i][j] is 1, 2, 3, 4: red(1)'s pieces.
	// b[i][j] is 0: empty.
	// b[i][j] is -1, -2, -3, -4: green(2)'s pieces.
	// b[i][j] is INF.
	int player;

	Board() {
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++)
				b[y][x] = 0;
		}
		player = 1;
	}

	Board(const int b[H][W], const int player) {
		copy_arr(b, this->b);
		this->player = player;
	}

	Board(int Record[H][W], int Max[H][W], Color color[H][W], Color inputColor) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (color[i][j] == 0)
					b[i][j] = 0;
				else if (color[i][j] == 3)
					b[i][j] = INF;
				else
					b[i][j] = Record[i][j] * (color[i][j] == 1 ? 1 : -1);
			}
		}
		this->player = inputColor;
	}

	Board(const Board &obj) : Board(obj.b, obj.player) {}

	Board operator=(const Board & rhs)
	{
		if (this == &rhs)
			return *this;
		copy_arr(rhs.b, b);
		player = rhs.player;
		return *this;
	}

	int get(const Point& p) {
		return b[p.y][p.x];
	}

	bool is_in_board(const Point& p) {
		return p.y >= 0 && p.y < H && p.x >= 0 && p.x < W;
	}

	// Input must be valid.
	int get_max_count(const Point& p) {
		int c = 0;
		Point ortho;
		for (int i = 0; i < MAX_DIR; i++) {
			ortho.y = p.y + dir[i].y;
			ortho.x = p.x + dir[i].x;
			if (!is_in_board(ortho))
				continue;
			c++;
		}
		return c;
	}

	bool is_not_wall(const Point& p) {
		if (!is_in_board(p))
			return false;
		if (b[p.y][p.x] == INF)
			return false;
		return true;
	}

	bool is_can_play(const Point& p) {
		if (!is_not_wall(p))
			return false;
		if (player == 1) {
			if (b[p.y][p.x] < 0)
				// It's another player's space.
				return false;
		} else {
			if (b[p.y][p.x] > 0)
				// It's another player's space.
				return false;
		}
		return true;
	}
	std::vector<Point> get_next_steps() {
		std::vector<Point> vec;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (is_can_play({ y, x }))
					vec.push_back({ y, x });
			}
		}
		return vec;
	}
	void move(Point pnt) {
		if (!is_can_play(pnt))
			throw "The move is not valid";
		int delta = 0;
		if (player == 1)
			delta = 1;
		else if (player == 2)
			delta = -1;
		b[pnt.y][pnt.x] += delta;
		std::queue<Point> update;
		update.push(pnt);
		while (!update.empty()) {
			Point p = update.front();
			update.pop();
			const int max_count = get_max_count(p);
			// If is wall.
			if (!is_not_wall(p))
				continue;
			if (abs(b[p.y][p.x]) >= max_count) {
				b[p.y][p.x] = INF;
			} else {
				// Won't explode.
				continue;
			}
			// If will explode.
			for (int i = 0; i < MAX_DIR; i++) {
				Point ortho = { p.y + dir[i].y, p.x + dir[i].x };
				if (!is_not_wall(ortho))
					continue;
				// It's not outside and not wall.
				b[ortho.y][ortho.x] = abs(b[ortho.y][ortho.x]) * delta;
				b[ortho.y][ortho.x] += delta;
				update.push(ortho);
			}
		}
		player = 3 - player;
	}
	Board get_moved_board(Point pnt) {
		if (!is_can_play(pnt))
			throw "The move is not valid";
		Board board(b, player);
		board.move(pnt);
		return board;
	}
	int get_who_wins() {
		int rem = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (b[i][j] == 0)
					return 0;
				if (b[i][j] != INF) {
					if (rem == 0) {
						rem = b[i][j] > 0 ? 1 : 2;
					}
					if (rem != (b[i][j] > 0 ? 1 : 2))
						return 0;
				}
			}
		}
		/*if (rem != 0) {
			return rem;
		}*/
		if (player != rem)
			return 3 - player;
		else
			return 0;
	}
	void get_copy_record(int to[H][W]) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				to[i][j] = abs(b[i][j]);
			}
		}
	}
	void get_copymax(int to[H][W]) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				to[i][j] = get_max_count({ i, j });
			}
		}
	}
	void get_copy_color(int to[H][W]) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (!is_not_wall({ i, j }))
					to[i][j] = 3;
				else if (b[i][j] == 0)
					to[i][j] = 0;
				else if (b[i][j] > 0)
					to[i][j] = 1;
				else
					to[i][j] = 2;
			}
		}
	}
};
class Student {
public:


	int eval(Board& board, int player, int depth) {
#ifdef LOG
		std::cout << "==start==" << '\n';
#endif
		int val = 0;
		int _c1, _c2, _n1, _n2, _nn1, _nn2;
		_c1 = _c2 = 0;
		_n1 = _n2 = 0;
		_nn1 = _nn2 = 0;
		if (board.get_who_wins() == player) {
#ifdef LOG
			std::cout << "Will Win" << '\n';
#endif
			val += 100000000;
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int belong;
				int count = board.get({ i, j });
				if (count == 0 || count == INF) {
					belong = 0;
					if (count == INF) {
#ifdef LOG
						std::cout << "Found wall" << '\n';
#endif
						//val -= 2 * (board.player == player ? 1 : -1);
					}
				} else if (count < 0) {
					belong = 2;
					_n2++;
					switch (abs(count)) {
					case 1:
						_c2 += 1;
						break;
					case 2:
						_c2 += 3;
						break;
					case 3:
						_c2 += 8;
						break;
					}
				} else {
					belong = 1;
					_n1++;
					switch (abs(count)) {
					case 1:
						_c1 += 1;
						break;
					case 2:
						_c1 += 3;
						break;
					case 3:
						_c1 += 8;
						break;
					}
				}
				count = abs(count);
				if (belong == 3 - player) {
					//Enemy.
					if (count + 1 == board.get_max_count({ i, j })) {
#ifdef LOG
						std::cout << "1 enemy pending" << '\n';
#endif
						val -= 6;
					}
					if ((i == 0 || i == H - 1) && (j == 0 || j == W - 1)) {
#ifdef LOG
						std::cout << "1 enemy corner" << '\n';
#endif
						/*bool isolated = true;
						for (int k = 0; k < MAX_DIR; k++) {
						Point p = { i + dir[k].y, j + dir[k].x };
						if (!board.is_not_wall(p))
						continue;
						if (board.get(p) != 0)
						isolated = false;
						}
						if (isolated)
						val -= 200;*/
						val -= 40;
					}
				} else if (belong == player) {
					if (count + 1 == board.get_max_count({ i, j })) {
#ifdef LOG
						std::cout << "1 self pending" << '\n';
#endif
						val += 4;
					}
				}
				bool minus_n = false;
				bool safe = true;
				int dis = board.get_max_count({ i, j }) - count;
				for (int k = 0; k < MAX_DIR; k++) {
					Point p = { i + dir[k].y, j + dir[k].x };
					if (!board.is_not_wall(p))
						continue;
					int belong2;
					int count2 = board.get(p);
					if (count2 == 0)
						belong2 = 0;
					else if (count2 < 0)
						belong2 = 2;
					else
						belong2 = 1;
					if (i == 1 && j == 0) {
						int a = 0;
					}
					if (belong2 != 0) {
						minus_n = true;
					}
					count2 = abs(count2);
					int ene_dis = board.get_max_count(p) - count2;
					if (belong == player) {
						//Center Self.
						if (belong2 == 0) {
							// Adjacent empty.
							/*if (dis > ene_dis) {
							safe = false;
							val -= 2 * 3;
							} else if (dis == ene_dis) {
							if (board.player == 3 - player) {
							safe = false;
							val -= 2 * 3;
							}
							}*/
						} else if (belong2 == 3 - player) {
							// Adjacent enemy.
							if (dis >= ene_dis) {
								switch (dis - ene_dis) {
								case 0:
									if (board.player == 3 - player) {
										safe = false;
										val -= 5 * 3;
									} else
										val += 5 * 3;
									break;
								case 1:
									safe = false;
									val -= 4 * 3;
									break;
								case 2:
									safe = false;
									val -= 3 * 3;
									break;
								case 3:
									safe = false;
									val -= 2 * 3;
									break;
								}
#ifdef LOG
								std::cout << "enemy adjacent" << '\n';
#endif
							}
						} else if (belong2 == player) {
							// Adjacent self.
#ifdef LOG
							std::cout << "self adjacent" << '\n';
#endif
							//if (count2 < count)
							//	val -= 2 * 3;
						} else {
							// Empty.
							if (count == 1)
								val += count;
							else if (count == 2)
								val += count + 1;
							else if (count == 3)
								val += count + 2;
						}
					} else if (belong == 3 - player) {
						//Center Enemy.
					}
				}
				if (safe)
					val += 50;
				if (belong == 2 && !minus_n) {
					_nn2++;
#ifdef LOG
					std::cout << "1 n2 empty" << '\n';
#endif
				} else if (belong == 1 && !minus_n) {
					_nn1++;
#ifdef LOG
					std::cout << "1 n1 empty" << '\n';
#endif
				}
			}
		}
		if (player == 1) {
			if (_c2 != 0)
				val += (float)_c1 / _c2 * 100;
			val += _n1 * 10;
			val += _nn1 * 70;
		} else {
			if (_c1 != 0)
				val += (float)_c2 / _c1 * 100;
			val += _n2 * 10;
			val += _nn2 * 70;
		}
		if (depth == 0) {
			val -= eval(board, 3 - player, 1);
		}
		return val;
	}
const int MAXDEPTH = 3;
	Point minimax(Board& bd, int depth, int alpha, int beta, bool maximizing, int player) {
		if (bd.get_who_wins() != 0) {
			if (depth == MAXDEPTH) {
				return bd.get_next_steps()[0];
			}
			// Perspective: self.
			return{ 0, eval(bd, player, 0) };
		}
		if (depth == 0)
			// Perspective: self.
			return{ 0, eval(bd, player, 0) };
		int bestVal, val;
		Point bestIndex;
		bestVal = maximizing ? -INF : INF;
		auto boards = bd.get_next_steps();
		for (auto p : boards) {
			Board board(bd);
			board.move(p);
			val = minimax(board, depth - 1, alpha, beta, !maximizing, player).x;
			if (maximizing) {
				//bestVal = std::max(bestVal, val);
				if (val > bestVal)
				{
					bestVal = val;
					bestIndex = p;
				}
				alpha = std::max(alpha, val);
				if (beta <= alpha)
					// Cut branch.
					break;
			} else {
				//bestVal = std::min(bestVal, val);
				if (val < bestVal)
				{
					bestVal = val;
					bestIndex = p;
				}
				beta = std::min(beta, val);
				if (beta <= alpha)
					// Cut branch.
					break;
			}
		}
		if (depth == MAXDEPTH) {
			return bestIndex;
		}
		return{ 0, bestVal };
	}
	void makeMove(int Record[H][W], int Max[H][W], Color color[H][W], Color inputColor) {
		Board b = Board(Record, Max, color, inputColor);
		Point p;
		/*if (b.get({ 0, 0 }) == 0)
			p = { 0, 0 };
		else if (b.get({ H - 1, W - 1 }) == 0)
			p = { H - 1, W - 1 };
		else if (b.get({ H - 1, 0 }) == 0)
			p = { H - 1, 0 };
		else if (b.get({ 0, W - 1 }) == 0)
			p = { 0, W - 1 };
		else*/
			p = minimax(b, MAXDEPTH, -INF, INF, true, inputColor);
		x = p.y;
		y = p.x;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
private:
	int x;
	int y;
};
