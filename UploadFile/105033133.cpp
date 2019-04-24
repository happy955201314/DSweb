class Student // linear pick
{
  public:
    void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (color[i][j] == White)
                {
                    y = i, x = j;
                    return;
                }
                else if (color[i][j] == inputColor && Record[i][j] < Max[i][j])
                {
                    y = i, x = j;
                }
            }
        }
    }
    int getX()
    {
        return y;
    }
    int getY()
    {
        return x;
    }

  private:
    const int h = 5, w = 6;
    int x;
    int y;
};