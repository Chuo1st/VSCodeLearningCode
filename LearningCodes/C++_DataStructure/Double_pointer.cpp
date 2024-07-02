/*                                          双指针                                                              */
#include <vector>
#include <set>
#include<string>
#include<algorithm>
using namespace ::std;

/****************************************************************************************************************************
287.给定一个包含n + 1 个整数的数组?nums ，其数字都在[1, n]范围内（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回?这个重复的数 。

你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。
*/
int findDuplicate(vector<int> &nums)
{
    //方法1使用哈希表
    // set<int> s;
    // for( int tmp : nums )
    // {
    //     if( s.count(tmp) )
    //     {
    //         return tmp;
    //     }else{
    //         s.emplace(tmp);
    //     }
    // }
    // return -1;

    /*
    方法2 双指针
    由于值相同的元素，而且值的大小在1到n之间，那么必定有多个元素的值指向同一个下标，这样就建立了类似于图或者链表的方式，使用类似于回环链表的方式解决这个问题
    */
    int fast = nums[0];
    int slow = nums[0];

    do
    {
        fast = nums[nums[fast]]; //走两步
        slow = nums[slow];
    } while (fast != slow);

    fast = nums[0];
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return fast;
}
/****************************************************************************************************************************
202. 快乐数 (简单)

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」?定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为?1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 

示例 1：

输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

int func(int *n)
{
    int res = 0;
    while (*n)
    {
        res += (*n % 10) * (*n % 10);
        *n /= 10;
    }
    *n = res;
    return res;
}

bool isHappy(int n)
{
    int slow = 0, fast = 0;
    //需要以下兩個變量記錄慢指針和快指針的對應值
    int stmp = n;
    int ftmp = n;

    while( slow != 1 && fast != 1 )
    {
        slow = func(&stmp);
        fast = func(&ftmp);
        fast = func(&ftmp);

        if( slow == fast && slow != 1 )
        return false;
    }
    return true;
}

/****************************************************************************************************************************
809. 情感丰富的文字(中等)
有时候人们会用重复写一些字母来表示额外的感受，比如 "hello" -> "heeellooo", "hi" -> "hiii"。我们将相邻字母都相同的一串字符定义为相同字母组，例如："h", "eee", "ll", "ooo"。

对于一个给定的字符串 S ，如果另一个单词能够通过将一些字母组扩张从而使其和 S 相同，我们将这个单词定义为可扩张的（stretchy）。扩张操作定义如下：选择一个字母组（包含字母?c?），然后往其中添加相同的字母?c?使其长度达到 3 或以上。

例如，以?"hello" 为例，我们可以对字母组?"o" 扩张得到 "hellooo"，但是无法以同样的方法得到 "helloo" 因为字母组 "oo" 长度小于?3。此外，我们可以进行另一种扩张 "ll" -> "lllll" 以获得?"helllllooo"。如果?s = "helllllooo"，那么查询词?"hello" 是可扩张的，因为可以对它执行这两种扩张操作使得?query = "hello" -> "hellooo" ->?"helllllooo" = s。

输入一组查询单词，输出其中可扩张的单词数量。

示例：

输入： 
s = "heeellooo"
words = ["hello", "hi", "helo"]
输出：1
解释：
我们能通过扩张 "hello" 的 "e" 和 "o" 来得到 "heeellooo"。
我们不能通过扩张 "helo" 来得到 "heeellooo" 因为 "ll" 的长度小于 3 。
*/
int expressiveWords(string s, vector<string>& words)
{
    int ans = 0;
    int left, right, w_left, w_right; //分别是s的双指针和words元素的双指针
    int len_s = s.size();
    int n_words = words.size();
    int len_i_words;

    for(int i = 0; i < n_words; ++i)
    {
        left = 0, right = 0, w_right = 0, w_left = 0;
        len_i_words = words[i].size();
        bool yes = true;

        while(right < len_s && w_right < len_i_words)
        {
            if(s[left] == words[i][w_left])
            {
                while(right < len_s && s[right] == s[left])
                {
                    ++right;
                }

                while(w_right < len_i_words && words[i][w_left] == words[i][w_right])
                {
                    ++w_right;
                }

                if( ( s[left] != s[right] && words[i][w_left] != words[i][w_right] ) || ( len_s == right && len_i_words == w_right ) )//关键点
                {
                    int count1 = right - left;
                    int count2 = w_right - w_left;
                    if(count1 < count2 || (count1 > count2 && count1 < 3))//判断是否匹配要求，关键点
                    {
                        yes = false;
                        break;
                    }
                    left = right;
                    w_left = w_right;
                }else{
                    yes = false;
                    break;
                }
            }else{
                yes = false;
                break;
            }
        }

        if(right != len_s || w_right != len_i_words)//判断是否二者中有一个没有走到末尾，说明不匹配
        yes = false;

        if(yes)
        ++ans;
    }
    return ans;
}


/****************************************************************************************************************************
 * 
 * 
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > 0)
        {
            break;
        }else{
            
        }
    }  
}

int main(int argc, char**argv)
{

}

