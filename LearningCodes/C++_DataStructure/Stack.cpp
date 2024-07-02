#include<stack>
#include<string>
#include<vector>
#include<map>

using namespace::std;

/********************************************************************************************************
856. ���ŵķ���(�е�)
����һ��ƽ�������ַ���?S�����������������ַ����ķ�����

() �� 1 �֡�
AB ��?A + B?�֣����� A �� B ��ƽ�������ַ�����
(A) ��?2 * A?�֣����� A ��ƽ�������ַ�����
*/
int scoreOfParentheses(string s)
{
    //����1������Ƚ��
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

    //����2��ջ
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
496. ��һ������Ԫ�� I (����)
���룺nums1 = [4,1,2], nums2 = [1,3,4,2].
�����[-1,3,-1]
���ͣ�nums1 ��ÿ��ֵ����һ������Ԫ������������
- 4 ���üӴ�б���ʶ��nums2 = [1,3,4,2]����������һ������Ԫ�أ����Դ��� -1 ��
- 1 ���üӴ�б���ʶ��nums2 = [1,3,4,2]����һ������Ԫ���� 3 ��
- 2 ���üӴ�б���ʶ��nums2 = [1,3,4,2]����������һ������Ԫ�أ����Դ��� -1 ��
*/

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    //ʹ�õ���ջ����β����nums2��β��Ԫ��û���ұ߽ڵ��ˣ�������ջ����map��¼��Ӧֵ�Ķ�Ӧ��
    if( nums1.size() == 0 )
    return nums1;

    stack<int> m_stack;
    map<int, int> m_map;
    vector<int> ans;
    for( int i = nums2.size(); i >= 0; ++i )
    {
        int x = nums2[i];
        while( !m_stack.empty() && x > m_stack.top() )//���ջ�ǿղ���ջ�е�Ԫ�ض���xС����ջ��ջ�е�Ԫ��ʵ���Ͼ��ǵ�ǰԪ���ұߵ���ЩԪ��
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