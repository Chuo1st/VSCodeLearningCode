#include<string>
#include<vector>
#include<utility>
#include<queue>
using namespace::std;


// 733. 图像渲染(簡單)
const vector<int> row = {1, 0, 0, -1};//左，下，上，右
const vector<int> column = {0, 1, -1, 0};

void dfs_733(vector<vector<int>> &image, int sr, int sc, int value, int color)
{
    if( value == color)
    return;

    int len_x = image[0].size();
    int len_y = image.size();
    image[sr][sc] = color;
    for( int i = 0; i < 4; ++i )
    {
        int mx = sc + row[i];
        int my = sr + column[i];
        if( mx >= 0 && mx < len_x && my >= 0 && my < len_y && image[my][mx] == value )
        {
            dfs_733(image, my, mx, value, color);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    //方法 1：recursion，注意當前點的賦值位置，還有進入循環的條件，要判斷進入的點是否已經賦值為color了，防止進入死循環
    // int value = image[sr][sc];
    // int len = image[0].size();
    // int high = image.size();
    // image[sr][sc] = color;
    // // up
    // if (sr - 1 >= 0 && image[sr - 1][sc] == value && image[sr - 1][sc] != color)
    // {
    //     floodFill(image, sr - 1, sc, color);
    // }
    // // down
    // if (sr + 1 < high && image[sr + 1][sc] == value && image[sr + 1][sc] != color)
    // {
    //     floodFill(image, sr + 1, sc, color);
    // }
    // // left
    // if (sc - 1 >= 0 && image[sr][sc - 1] == value && image[sr][sc - 1] != color)
    // {
    //     floodFill(image, sr, sc - 1, color);
    // }
    // // right
    // if (sc + 1 < len && image[sr][sc + 1] == value && image[sr][sc + 1] != color)
    // {
    //     floodFill(image, sr, sc + 1, color);
    // }
    // return image;

    //方法2：BFS
    // int value = image[sr][sc];
    // if( value == color )
    // return image;

    // queue<pair<int, int>> que;
    // que.emplace(make_pair(sr, sc));
    // image[sr][sc] = color;
    // int len_x = image[0].size();
    // int len_y = image.size();
    // while( !que.empty() )
    // {
    //     pair<int, int> p = que.front();
    //     que.pop();
    //     for( int i = 0; i < 4; ++i )
    //     {
    //         int m_x = p.first + row[i];
    //         int m_y = p.second + column[i];
    //         if( m_x >= 0 && m_x < len_x && m_y >= 0 && m_y < len_y && image[m_y][m_x] == value )
    //         {
    //             image[m_y][m_x] = color;
    //             que.emplace(make_pair(m_y, m_x));
    //         }
    //     }
    // }
    // return image;

    //dfs
    dfs_733(image, sr, sc, image[sr][sc], color);
    return image;
}

// 695. 岛屿的最大面积（中等）

vector<int> left_right = {-1, 1, 0, 0};
vector<int> up_down = {0, 0, 1, -1};
void dfs(vector<vector<int>> &v, int x, int y, int &area)
{
    if(v[y][x])//pay attention to the index of the vector
    {
        area++;
        v[y][x] = 0;
    }
    else return;

    int len_x = v[0].size();
    int len_y = v.size();
    for( int i = 0; i < 4; ++i )
    {
        if( x + left_right[i] >= 0 && x + left_right[i] < len_x && y + up_down[i] >= 0 && y + up_down[i] < len_y )
        {
            dfs(v, x + left_right[i], y + up_down[i], area);
        }
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    //dfs
    int len_x = grid[0].size();
    int len_y = grid.size();
    int max = 0;

    for( int i = 0; i< len_y; ++i )
    {
        for( int j = 0; j < len_x; ++j )
        {
            if(grid[i][j])
            {
                int area = 0;
                dfs(grid, j, i, area);
                max = area > max ? area : max;
            }
        }
    }
    return max;
}


// 2684. 矩阵中移动的最大次数
int maxMovesBFS(int x, int y, vector<vector<int>>& grid, int lastValue);
int maxMoves(vector<vector<int>>& grid) {
    int max = -1;
    for (int i = 0; i < grid.size(); ++i)
    {
        // 减一是因为第一个点进去的时候不算走的步数
        int res = maxMovesBFS(0, i, grid, -1) - 1;
        if (max < res)
        {
            max = res;
            // 如果当前max值已经是等于矩阵的宽度，说明就是最大的值了，直接返回
            if (max == grid[0].size())
            return max;
        }
    }
    return max;
}

int maxMovesBFS(int x, int y, vector<vector<int>>& grid, int lastValue)
{
    int width = grid[0].size(), height = grid.size();
    // 判断是否越界
    if (y < 0 || x >= width || y >= height)
        return 0;
    // 判断当前节点是否大于前一个节点
    int val = grid[y][x];
    if (val <= lastValue)
    {
        return 0;
    }
    // 分别向右上方，右方和右下方递归。 因为到了这里就算走了一步，
    // 所以都要加一（也说明了为什么maxMoves()中调用该函数的返回值需要-1，因为刚进这函数的时候第一次的1不算
    int upRightResult = maxMovesBFS(x + 1, y - 1, grid, val) + 1;
    int rightResult = maxMovesBFS(x + 1, y, grid, val) + 1;
    int downRightResult = maxMovesBFS(x + 1, y + 1, grid, val) + 1;
    // 防止重复访问已经访问过的位置，因为我们需要更大值
    grid[y][x] = 0;
    int max = upRightResult > rightResult ? upRightResult : rightResult;
    max = max > downRightResult ? max : downRightResult;

    return max; 
}

int main()
{
    queue<int> que;
    
}
