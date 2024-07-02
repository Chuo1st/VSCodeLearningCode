#include<vector>
#include<queue>
#include<limits.h>
#include<iostream>
using namespace::std;

/***********************************************************************************************************************
1800.����һ����������ɵ����� nums ������ nums ��һ�� ���� �������������Ԫ�غ͡�

�������������е�һ�������������С�

��֪������ [numsl, numsl+1, ..., numsr-1, numsr] ���������� i��l <= i < r����numsi < numsi+1 �������������һ������Ϊ ���� �����顣ע�⣬��СΪ 1 ��������Ҳ���� ���� �����顣
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
53.����������
����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
������ �������е�һ���������֡�
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
 198. ��ҽ���1
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
213. ��ҽ���2
*/
int func(const vector<int> &nums, int start, int end);
int rob1(vector<int>& nums) {
    // 1.�п�ͷ�޽�β
    int res = 0;
    int tmp = func(nums, 0, nums.size() - 1);
    res = (tmp > res) ? tmp : res;
    // 2.�޿�ͷ�н�β
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

/********************************              ��Ʊ����                          ****************************************/
// T[i][k][1] �� T[i][k][0]��i�����ֹ��ĳ�գ�k��Ʊ����������1�����ֹ��iʱ�����Ź�Ʊ��0���෴
// 121.������Ʊ�����ʱ��������k = 1��dpֻ��һ����ά����
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

// 122.������Ʊ�����ʱ��II������k��ȡֵ��ΧΪ0��i



int main()
{
    vector<int> nums = {1,2,3};
    cout << rob1(nums);
    
}