#include<float.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stdio.h>
#include<stack>
#include<queue>
#include<map>
#include<queue>
#include <bits/stdc++.h>
#include<numeric>
#include<math.h>
#include<functional>

using namespace::std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};
vector<TreeNode*> nodes;



int min_useful_potion = 0;
struct help{
    bool operator()(int n1)
    {
        return n1 >= min_useful_potion;
    }
};

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //sort(spells.begin(), spells.end());
    sort(potions.begin(), potions.end());
    int spells_len = spells.size();
    int potions_len = potions.size();
    int max_potion = potions[potions_len - 1];
    int min_useful_spell = success % max_potion == 0? success / max_potion : (success /max_potion + 1); // 最小符合要求的咒语
    vector<int> v;
    for(int i = 0; i < spells_len; ++i)
    {
        if(spells[i] >= min_useful_spell)
        {
            min_useful_potion = success % spells[i] == 0? success / spells[i] : (success / spells[i] + 1);
            auto it = find_if(potions.begin(), potions.end(), help());
            int tmp = potions.end() -it;
            v.emplace_back(potions.end() - it);
        }else{
            v.emplace_back(0);
        }
    }
    return v;
}


int maximumSum(vector<int>& nums) {
    map<int, priority_queue<int>> myMap;
    int len = nums.size();
    for(int i = 0; i < len; ++i)
    {
        int total = 0;
        int tmp = nums[i];
        while(tmp)
        {
            total += tmp % 10;
            tmp /= 10;
        }
        myMap[total].push(nums[i]);
    }

    int  max = 0;
    for(auto item : myMap)
    {
        if(item.second.size() > 1)
        {
            int sum = item.second.top();
            item.second.pop();
            sum += item.second.top();
            if(sum > max)
            max = sum;
        }
    }
    return max;
}

int main()
{
    int res = 'a' - 'A';
    map<int, int> m;
    for (auto item : m)
    {
        
    }
    cout << res;
}