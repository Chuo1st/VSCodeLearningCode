#include <vector>
#include <algorithm>
#include<string>
#include<iostream>
using namespace ::std;

/*
976. 三角形的最大周长(简单)
给定由一些正数（代表长度）组成的数组 nums?，返回 由其中三个长度组成的、面积不为零的三角形的最大周长?。如果不能形成任何面积不为零的三角形，返回?0。
*/

int largestPerimeter(vector<int> &nums)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = size - 1; i >= 2; --i)
    {
        if (nums[i] < nums[i - 1] + nums[i - 2])
        {
            return nums[i] + nums[i - 1] + nums[i - 2];
        }
    }
    return 0;
}

/*
769. 最多能完成排序的块(中等)
示例 1:

输入: arr = [4,3,2,1,0]
输出: 1
解释:
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。
示例 2:

输入: arr = [1,0,2,3,4]
输出: 4
解释:
我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。

n == arr.length
1 <= n <= 10
0 <= arr[i] < n
arr 中每个元素都 不同
*/
int maxChunksToSorted(vector<int> &arr)
{
    int ans = 0;
    int isum = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        sum += arr[i];
        isum += i;
        if (sum == isum)
            ++ans;
    }
    return ans;
}

bool canChange(string start, string target) {

    // 1.假如L需要左移，确定在L左移到目标为止的路上有无R并且空格数够不够
    // 2.假如R需要R需要右移，确定路上有无L并且空格数够不够
    int targetLen = target.size();
    int startLen = start.length();
    int targetLastIndex = 0;
    int startLastIndex = 0;
    for(int i = 0; i < targetLen; ++i)
    {
        if(target[i] == 'L'){
            int spaceCount = 0;
            bool flag = false;
            for(int j = startLastIndex; j < startLen; ++j)
            {
                if(start[j] == 'R')
                {
                    return false;
                } else if(start[j] == 'L')
                {
                    if(j < i)
                        return false; // start中的L不可以在target的L的左边
                    int spaceNeed = j - i; // 左移需要的空格数
                    if(spaceNeed > spaceCount)
                        return false;
                    start[j] = '_';
                    ++startLastIndex;
                    flag = true;
                    break;
                }else{
                    ++spaceCount;
                }
            }
            if(!flag)
                return false;

        }else if (target[i] == 'R'){
            int spaceCount = 0;
            bool flag = false;
            for(int j = startLastIndex; j < startLen; ++j)
            {
                if(start[j] == 'L')
                {
                    return false;
                }else if(start[j] == 'R')
                {
                    if(j > i)
                        return false; // the index R of start cant be the right of target'R
                    int spaceNeed = i - j;
                    if(spaceNeed > spaceCount)
                        return false;
                    start[j] = '_';
                    ++startLastIndex;
                    flag = true;
                    break;
                }else{
                    ++spaceCount;
                }
            }
            if(!flag)
                return false;
        }
    }
    return true;
}

bool check(const string& str1, const string& str2)
{
    int countL = 0, countR = 0;
    for(int i = 0; i < str1.length(); ++i)
    {
        if(str1[i] == 'L' || str1[i] == 'R')
            if(str1[i] == 'L')
                ++countL;
        else
            ++countR;
        else if(str2[i])
    }
}

int main(int argc, char* argv[])
{
    cout << canChange("_L__R__R_", "L______RR") << endl;
}
