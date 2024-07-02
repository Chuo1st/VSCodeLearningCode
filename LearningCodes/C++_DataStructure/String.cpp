#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace:: std;


/*
1694
*/
string reformat_number( string &num )
{
    string s1;
    for( char ch: num )
    {
        if( isdigit(ch) )
        {
            s1.push_back(ch);
        }
    }

    int n = s1.size();
    string res;
    int pos = 0;
    while( n )
    {
        if( n > 4 )
        {
            res += s1.substr( pos, 3 ) + '-';
            n -= 3;
            pos += 3;
        }else{
            if( n == 4 )
            {
                res += s1.substr( pos,2 ) + '-' + s1.substr( pos + 2, 2 );
            }else{
                res += s1.substr( pos, n );
            }
            break;
        }
    }
    return res;
}

/*
最长回文字符串(Mid)
思路：寻找中点往左右两边扩展，中点有两种，子串如果是奇数长度，中点就是一个，如果子串是偶数长度，中点就有两个，从s的第一个字符开始当作中点，以奇和偶两种形式扩张，寻找最长的回文子串，难点就在循环结束判断条件和begin位置和max的更新
*/
string longestPalindrome(string s)
{
    int length = s.size();
    if(length < 2)
    return s;
    int begin = 0;
    int max = 1;
    for(int i = 0; i < length; ++i)
    {
        // odd
        for(int j = 1; (i + j < length) && (i - j >= 0); ++j)
        {
            if(s[i + j] == s[i - j])
            {
                if(max < j * 2 + 1)
                {
                    max = j * 2 + 1;
                    begin = i - j;
                }
            }else{
                break;
            }
        }

        // even
        if(s[i] == s[i + 1])
        {
            for(int j = 0; (i - j >= 0) && (i + j + 1 < length); ++j)
            {
                if(s[i - j] == s[i + 1 + j])
                {
                    if(max < 2 + j * 2)
                    {
                        max = 2 + j * 2;
                        begin = i - j;
                    }
                }else{
                    break;
                }
            }
        }
    }
    return s.substr(begin, max);
}


int findTheLongestBalancedSubstring(string s) {
    int len = s.size();
    if(len < 2)
    return 0;

    int preLen = 0;
    int curLen = 0;
    bool isZero = (s[0] == '0')? true : false;
    int max = 0;
    for(int i = 0; i < len; ++i)
    {
        if(isZero)
        {
            if(s[i] == '0')
            {
                ++curLen;
            }else{
                preLen = curLen;
                curLen = 1;
                isZero = false;
            }
        }else{
            if(s[i] == '1')
            {
                ++curLen;
            }else{
                int minLen = preLen > curLen ? curLen : preLen;
                if(max < minLen)
                max = minLen;
                curLen = 1;
                isZero = true;
            }
        }
    }
    if(!isZero)
    {
        int minLen = preLen > curLen ? curLen : preLen;
        if(max < minLen)
        {
            max = minLen;
        }
    }
    return max * 2;
}


int main()
{
    string str = "cbbd";
    str = longestPalindrome(str);

    cout << findTheLongestBalancedSubstring("01000111");
}

