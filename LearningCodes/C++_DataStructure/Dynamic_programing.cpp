#include<vector>
#include<queue>
#include<limits.h>
#include<iostream>
using namespace::std;

/***********************************************************************************************************************
1800.给你一个正整数组成的数组 nums ，返回 nums 中一个 升序 子数组的最大可能元素和。

子数组是数组中的一个连续数字序列。

已知子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，若对所有 i（l <= i < r），numsi < numsi+1 都成立，则称这一子数组为 升序 子数组。注意，大小为 1 的子数组也视作 升序 子数组。
 */

int maxAscendingSum(vector<int>& nums) {
    int cur = nums[0];
    int res = nums[0];
    for( int i = 1; i < nums.size(); ++i )
    {
        if( nums[i] > nums[i - 1] )
        {
            cur += nums[i];
        }else{
           cur = nums[i];
        }
        res = max( cur, res );
    }
    return res;
}

/************************************************************************************************************************
53.最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
*/
int maxSubArray(vector<int>& nums)
{
    int max = nums[0];
    int sum = nums[0];
    int size = nums.size();
    for( int i = 1; i < size; ++i )
    {
        if( nums[i] > sum && sum < 0 )
        {
            sum = nums[i];
        }
        else{
            sum += nums[i];
        }

        if( max < sum )
        {
            max = sum;
        }
    }
    return max;
}

/********************************************************************************************************
 198. 打家劫舍1
 f(k) = max(f(k - 1), f(k - 2) + nums[k - 1])
 */
int rob(vector<int>& nums) {
    int length = nums.size();
    if(length == 0)
    return 0;

    vector<int> dp(length + 1, 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i <= length; ++i)
    {
        dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp[length];
}

/************************************************************************************************************
213. 打家劫舍2
*/
int func(const vector<int> &nums, int start, int end);
int rob1(vector<int>& nums) {
    // 1.有开头无结尾
    int res = 0;
    int tmp = func(nums, 0, nums.size() - 1);
    res = (tmp > res) ? tmp : res;
    // 2.无开头有结尾
    tmp = func(nums, 1, nums.size());
    res = (tmp > res) ? tmp : res;
    return res;
}

int func(const vector<int> &nums, int start, int end)
{
    vector<int> tmp(nums.begin() + start, nums.begin() + end);
    if(tmp.size() == 1)
    return tmp[0];

    vector<int> dp(tmp.size() + 1, 0);
    dp[0] = 0;
    dp[1] = tmp[0];
    for(int i = 2; i < dp.size(); ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + tmp[i - 1]);
    }
    return dp[dp.size() - 1];
}

/********************************              股票问题                          ****************************************/
// T[i][k][1] 和 T[i][k][0]，i代表截止到某日，k股票操作次数，1代表截止到i时掌握着股票，0则相反
// 121.买卖股票的最佳时机：此题k = 1，dp只是一个二维数组
int maxProfit(vector<int>& prices)
{
    int res = 0, n = prices.size();
    if(n < 2)
    return res;

    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for(int i = 1; i < n; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(-prices[i], dp[i - 1][1]);
    }
    return dp[n - 1][0];
}

// 122.买卖股票的最佳时机II：此题k的取值范围为0到i



int main()
{
    vector<int> nums = {1,2,3};
    cout << rob1(nums);
    
}