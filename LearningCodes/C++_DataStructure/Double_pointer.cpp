/*                                          ˫ָ��                                                              */
#include <vector>
#include <set>
#include<string>
#include<algorithm>
using namespace ::std;

/****************************************************************************************************************************
287.����һ������n + 1 ������������?nums �������ֶ���[1, n]��Χ�ڣ����� 1 �� n������֪���ٴ���һ���ظ���������

���� nums ֻ�� һ���ظ������� ������?����ظ����� ��

����ƵĽ���������� ���޸� ���� nums ��ֻ�ó����� O(1) �Ķ���ռ䡣
*/
int findDuplicate(vector<int> &nums)
{
    //����1ʹ�ù�ϣ��
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
    ����2 ˫ָ��
    ����ֵ��ͬ��Ԫ�أ�����ֵ�Ĵ�С��1��n֮�䣬��ô�ض��ж��Ԫ�ص�ֵָ��ͬһ���±꣬�����ͽ�����������ͼ��������ķ�ʽ��ʹ�������ڻػ�����ķ�ʽ����������
    */
    int fast = nums[0];
    int slow = nums[0];

    do
    {
        fast = nums[nums[fast]]; //������
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
202. ������ (��)

��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

����������?����Ϊ��

����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
���������� ���Ϊ?1����ô��������ǿ�������
��� n �� ������ �ͷ��� true �����ǣ��򷵻� false 

ʾ�� 1��

���룺n = 19
�����true
���ͣ�
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
    //��Ҫ���ɂ�׃��ӛ���ָᘺͿ�ָᘵČ���ֵ
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
809. ��зḻ������(�е�)
��ʱ�����ǻ����ظ�дһЩ��ĸ����ʾ����ĸ��ܣ����� "hello" -> "heeellooo", "hi" -> "hiii"�����ǽ�������ĸ����ͬ��һ���ַ�����Ϊ��ͬ��ĸ�飬���磺"h", "eee", "ll", "ooo"��

����һ���������ַ��� S �������һ�������ܹ�ͨ����һЩ��ĸ�����ŴӶ�ʹ��� S ��ͬ�����ǽ�������ʶ���Ϊ�����ŵģ�stretchy�������Ų����������£�ѡ��һ����ĸ�飨������ĸ?c?����Ȼ�������������ͬ����ĸ?c?ʹ�䳤�ȴﵽ 3 �����ϡ�

���磬��?"hello" Ϊ�������ǿ��Զ���ĸ��?"o" ���ŵõ� "hellooo"�������޷���ͬ���ķ����õ� "helloo" ��Ϊ��ĸ�� "oo" ����С��?3�����⣬���ǿ��Խ�����һ������ "ll" -> "lllll" �Ի��?"helllllooo"�����?s = "helllllooo"����ô��ѯ��?"hello" �ǿ����ŵģ���Ϊ���Զ���ִ�����������Ų���ʹ��?query = "hello" -> "hellooo" ->?"helllllooo" = s��

����һ���ѯ���ʣ�������п����ŵĵ���������

ʾ����

���룺 
s = "heeellooo"
words = ["hello", "hi", "helo"]
�����1
���ͣ�
������ͨ������ "hello" �� "e" �� "o" ���õ� "heeellooo"��
���ǲ���ͨ������ "helo" ���õ� "heeellooo" ��Ϊ "ll" �ĳ���С�� 3 ��
*/
int expressiveWords(string s, vector<string>& words)
{
    int ans = 0;
    int left, right, w_left, w_right; //�ֱ���s��˫ָ���wordsԪ�ص�˫ָ��
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

                if( ( s[left] != s[right] && words[i][w_left] != words[i][w_right] ) || ( len_s == right && len_i_words == w_right ) )//�ؼ���
                {
                    int count1 = right - left;
                    int count2 = w_right - w_left;
                    if(count1 < count2 || (count1 > count2 && count1 < 3))//�ж��Ƿ�ƥ��Ҫ�󣬹ؼ���
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

        if(right != len_s || w_right != len_i_words)//�ж��Ƿ��������һ��û���ߵ�ĩβ��˵����ƥ��
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

