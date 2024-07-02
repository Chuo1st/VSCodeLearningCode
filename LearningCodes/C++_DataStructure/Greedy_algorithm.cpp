#include <vector>
#include <algorithm>
#include<string>
#include<iostream>
using namespace ::std;

/*
976. �����ε�����ܳ�(��)
������һЩ�����������ȣ���ɵ����� nums?������ ����������������ɵġ������Ϊ��������ε�����ܳ�?����������γ��κ������Ϊ��������Σ�����?0��
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
769. ������������Ŀ�(�е�)
ʾ�� 1:

����: arr = [4,3,2,1,0]
���: 1
����:
������ֳ�2����߸���飬���޷��õ�����Ľ����
���磬�ֳ� [4, 3], [2, 1, 0] �Ľ���� [3, 4, 0, 1, 2]���ⲻ����������顣
ʾ�� 2:

����: arr = [1,0,2,3,4]
���: 4
����:
���ǿ��԰����ֳ����飬���� [1, 0], [2, 3, 4]��
Ȼ�����ֳ� [1, 0], [2], [3], [4] ���Եõ����Ŀ�����

n == arr.length
1 <= n <= 10
0 <= arr[i] < n
arr ��ÿ��Ԫ�ض� ��ͬ
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

    // 1.����L��Ҫ���ƣ�ȷ����L���Ƶ�Ŀ��Ϊֹ��·������R���ҿո���������
    // 2.����R��ҪR��Ҫ���ƣ�ȷ��·������L���ҿո���������
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
                        return false; // start�е�L��������target��L�����
                    int spaceNeed = j - i; // ������Ҫ�Ŀո���
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
