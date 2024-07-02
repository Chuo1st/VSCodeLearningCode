
//算法：滑动窗口

#include<vector>
#include<string>
#include<set>
#include<iostream>
#include<unordered_map>

using namespace :: std;


/*******************************************************************************************************************************************
3. 无重复字符的最长子串(难度：中等)

s 由英文字母、数字、符号和空格组成
示例?1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是?"wke"，所以其长度为 3。
?    请注意，你的答案必须是 子串 的长度，"pwke"?是一个子序列，不是子串。
*/

int lengthOfLongestSubstring(string s)
{
    set<char> m_set;
    int max = 0;
    int left = 0;
    for( int i = 0; i < s.size(); ++i )
    {
        while(m_set.count(s[i]) == 1)
        {
            m_set.erase(s[left]);
            ++left;
        }
        max = max > (i - left + 1) ? max : i - left + 1;
        m_set.emplace(s[i]);
    }
    return max;
}

/************************************************************************************************************************************
567. 字符串的排列(难度中等)
给你两个字符串?s1?和?s2 ，写一个函数来判断 s2 是否包含 s1?的排列。如果是，返回 true ；否则，返回 false 。
换句话说，s1 的排列之一是 s2 的 子串 。

示例 1：

输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false

s1 和 s2 仅包含小写字母
*/
bool checkInclusion(string s1, string s2)
{
    int len1 = s1.size(), len2 = s2.size();
    if( len1 > len2 )
    return false;

    vector<int> v1(26, 0);
    vector<int> v2(26, 0);
    for( int i = 0; i < len1; ++i )//记录前len1中s1和s2的字母数量
    {
        ++v1[s1[i] - 'a'];
        ++v2[s2[i] - 'a'];
    }

    if( v1 == v2 )
    return true;

    for( int i = len1; i < len2; ++i )
    {
        ++v2[s2[i] - 'a'];
        --v2[s2[i - len1] - 'a'];
        if( v1 == v2 )
        return true;
    }
    return false;
}


/************************************************************************************************************************************
904. 水果成篮
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

示例 1：

输入：fruits = [1,2,1]
输出：3
解释：可以采摘全部 3 棵树。

示例 2：

输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
示例 3：

输入：fruits = [1,2,3,2,2]
输出：4
解释：可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
*/
int totalFruit(vector<int>& fruits)
{
    int left = 0, ans = 0;
    unordered_map<int, int> map;
    for( int right = 0; right < fruits.size(); ++right )
    {
        map[fruits[right]]++;
        while(map.size() > 2)
        {
            auto tmp = map.find(map[fruits[left]]);
            --tmp->second;
            if(tmp->second == 0)
            {
                map.erase(tmp);
            }
            ++left;
        }
        ans = max(right - left - 1, ans);
    }
    return ans;
}

/************************************************************************************************************************************
438. 找到字符串中所有字母异位词 (中等)
给定两个字符串?s?和 p，找到?s?中所有?p?的?异位词?的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

示例?1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
*/
vector<int> findAnagrams(string s, string p)
{
    if(s.size() < p.size())
    return {};

    //方法是滑动窗口，从左到右限制窗口大小为p的大小，移动更新v_s数组对应字母数量的数据，然后判断v_s是否和v_p相同
    vector<int> v_s(26, 0);//用于动态移动窗口时的字母个数
    vector<int> v_p(26, 0);//记录p的字母个数

    vector<int> ans;//返回值

    for( int i = 0; i < p.size(); ++i )
    {
        v_p[p[i] - 'a'] += 1;
    }

    //记录s字符串前p.size - 1个字母个数，所以就循环到p.size - 1
    for( int i = 0; i < p.size() - 1; ++i )
    {
        v_s[s[i] - 'a'] += 1;
    }
    
    int left = 0, right = p.size() - 1;
    while(right < s.size())
    {
        v_s[s[right] - 'a'] += 1;//就是这个位置的缘故
        if(v_s == v_p)
        {
            ans.emplace_back(left);
        }

        v_s[s[left] - 'a'] -= 1;
        ++left;
        ++right;
    }
    return ans;
}

int main()
{
    string str1 = "horse";
    string str2 = "osr";
    if( checkInclusion(str2, str1) )
    {
        cout << "yes" << endl;
    }
}