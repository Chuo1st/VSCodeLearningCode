#include<vector>
#include<stack>
using namespace::std;

/**************************************************************************************************************************************
503. 下一个更大元素 II(中等)
*/
vector<int> nextGreaterElements(vector<int>& nums)
{
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
}

int main()
{

}