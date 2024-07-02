#include<iostream>
#include<vector>

using namespace::std;

/*
48.旋转图像
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
*/
void rotate(vector<vector<int>>& matrix) 
{
    //方法1：第一行变为最后一列：第一行旋转后从左到右的数字就是最后一列从上到下
    vector<vector<int>> tmp = matrix;
    int size = matrix.size();
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            tmp[j][size - i - 1] = matrix[i][j];
        }
    }
    matrix = tmp;
}

/*
m x n的矩阵得对角线和
*/
vector<int> SumDiagnals(vector<vector<int>>& mat)
{
    int m = mat.size(); // rows
    int n = mat[0].size(); // columns
    vector<int> res;

    // 当只有一行或者一列时，就特殊处理
    if(m == 1)
    {
        return mat[0];
    }else if(n == 1)
    {
        for(int i = 0; i < m; ++i)
        {
            res.emplace_back(mat[i][0]);
        }
        return res;
    }

    // 一下是不只有一行或者一列的情况，求结果需要从左到右累加对角线的和，到达最右后再从上到下累加对角线的和
    int diagnals = m + n - 1; // 对角线数量 = 行数 + 列数 - 1
    int x = 0, y =0; //当前坐标
    // 偶数就是从左往右，相反就是
    for(int i = 0; i < diagnals; ++i)
    {
        // 获取对角线的和，需要从当前坐标往左下方45°方向的格子，以m为界限来判断当前对角线的累加是否结束
        // x - 1, y + 1, 则得到当前格子的对角线方向的下一个格子
        int tmp_x = x - 1, tmp_y = y + 1;
        int sum = mat[y][x];
        while(tmp_x >= 0 && tmp_y < m)
        {
            sum += mat[tmp_y][tmp_x];
            tmp_x -= 1;
            tmp_y += 1;
        }
        res.emplace_back(sum);

        // 变更坐标，如果没有超出右边，继续右移，如果超出，就往下移动
        if(x == n - 1)
        {
            ++y;
        }else{
            ++x;
        }
    }
    return res;
}

/*
498. 对角线遍历
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // 思路：第一条对角线的遍历是往右上角45°，第二条是往左下角45°，如此类推，奇数是右上顺序，偶数时左下顺序遍历
        bool isTowardRight = true; // 一开始是右
        int rows = mat.size();
        int columns = mat[0].size();
        int x = 0, y = 0;
        vector<int> res;
        // 规律：如果是往右走，走到最后，如果此时坐标的右边有格子，就是下一个对角线的起始位置，如果右边没有格子但是下面有格子，那么下面的格子就是下一个对角线的坐标，如果下面也没有格子，说明已经是最后一条对角线了，可以结束了
        // 如果往左走，走都最后，如果此时坐标下面有格子，就是下一个对角线的起始位置，如果下面没有格子但是右边有格子，那么右边的格子就是下一个对角线的坐标，如果右边也没有格子，说明已经是最后一条对角线了，可以跳出循环了
        while(true)
        {
            if(isTowardRight)
            {
                isTowardRight = false;
                while(x < columns && y >= 0)
                {
                    res.emplace_back(mat[y][x]);
                    x += 1;
                    y -=1;
                }
                // 恢复位置
                x -= 1;
                y += 1;
                if(x + 1 < columns)
                {
                    // 往右走
                    ++x;
                }
                else if(y + 1 < rows)
                {
                    // 往下走
                    ++y;
                }
                else{
                    // 最后一条对角线，跳出循环
                    break;
                }
            }
            else
            {
                isTowardRight = true;
                while(x >= 0 && y < rows)
                {
                    res.emplace_back(mat[y][x]);
                    y += 1;
                    x -= 1;
                }
                // 恢复位置
                y -= 1;
                x += 1;
                if(y + 1 < rows)
                {
                    ++y;
                }
                else if(x + 1 < columns)
                {
                    ++x;
                }else{
                    break;
                }
            }
        }
        return res;
    }
};



int main()
{
    
}
