#include<stack>
#include<string>
#include<vector>
#include<map>

using namespace::std;

/********************************************************************************************************
856. 括号的分数(中等)
给定一个平衡括号字符串?S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得?A + B?分，其中 A 和 B 是平衡括号字符串。
(A) 得?2 * A?分，其中 A 是平衡括号字符串。
*/
int scoreOfParentheses(string s)
{
    //方法1：用深度解决
    int size = s.size();
    int deep = 0, ans = 0;

    for( int i = 0; i < size; ++i )
    {
        if( s[i] == '(' )
        {
            ++deep;
        }else{
            if( s[i-1] !=')' )
            ans += 1 << (deep - 1);
            
            --deep;
        }
    }
    return ans;

    //方法2：栈
    // int size = s.size();
    // stack<int> m_stack;
    // m_stack.push(0);
    
    // for( int i = 0; i < size; ++i )
    // {
    //     if( s[i] == '(' )
    //     m_stack.push(0);
    //     else{
    //         int top = m_stack.top();
    //         m_stack.pop();
    //         m_stack.top() += top*2 > 1 ? top*2 : 1;
    //     }
    // }
    // return m_stack.top();
}

/*
496. 下一个更大元素 I (容易)
输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    //使用单调栈，从尾遍历nums2，尾部元素没有右边节点了，所以入栈，用map记录对应值的对应答案
    if( nums1.size() == 0 )
    return nums1;

    stack<int> m_stack;
    map<int, int> m_map;
    vector<int> ans;
    for( int i = nums2.size(); i >= 0; ++i )
    {
        int x = nums2[i];
        while( !m_stack.empty() && x > m_stack.top() )//如果栈非空并且栈中的元素都比x小，出栈，栈中的元素实际上就是当前元素右边的那些元素
        {
            m_stack.pop();
        }
        m_map[x] = (!m_stack.empty()) ? m_stack.top() : -1;
        m_stack.emplace(x);
    }

    for( int i = 0; i < nums1.size(); ++i )
    {
        ans.emplace_back(m_map[nums1[i]]);
    }
    return ans;
}

int main()
{
    stack<int> s;
}