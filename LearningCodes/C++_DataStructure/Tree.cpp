#include <vector>
#include <stack>
#include <queue>
#include<limits.h>
#include <iostream>
#include<string>
#include<algorithm>
#include<set>
#include<numeric>

using namespace ::std;

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


/*                       144.二叉樹的前序遍歷（簡單）                   */
void preorderTraversal_recursion(vector<int> &ret, TreeNode *root)
{
    if (!root)
        return;

    ret.emplace_back(root->val);
    preorderTraversal_recursion(ret, root->left);
    preorderTraversal_recursion(ret, root->right);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> mystack;
    mystack.push(root);
    while(!mystack.empty())
    {
        root = mystack.top();
        mystack.pop();
        while(root)
        {
            res.emplace_back(root->val);
            if(root->right)
            {
                mystack.push(root->right);
            }
            root = root->left;
        }
    }
    return res;
}

/*                       94.二叉樹的中序遍歷（簡單）                   */
void inorderTraversal_recursion(vector<int> &ret, TreeNode *root)
{
    if (!root)
        return;

    inorderTraversal_recursion(ret, root->left);
    ret.emplace_back(root->val);
    inorderTraversal_recursion(ret, root->right);
}

void inorderTraversal(vector<int> &ret, TreeNode *root)
{
    if (!root)
        return;
    stack<TreeNode *> s;
    
    while (root || !s.empty())
    {
        while (root)
        {
            s.emplace(root);
            root = root->left;
        }
        root = s.top();
        ret.emplace_back(root->val);
        s.pop();
        // 注意：这里必须这么写，如果写了if判断右节点是否为空才赋值，那么root不是空就一直死循环，因为root的值一直只会停留在某个非空结点
        root = root->right;
    }
}


/*                       145.二叉樹的后序遍歷（簡單）                   */
void postorderTraversal_recursion(vector<int> &ret, TreeNode *root)
{
    if (!root)
        return;

    postorderTraversal_recursion(ret, root->left);
    postorderTraversal_recursion(ret, root->right);
    ret.emplace_back(root->val);
}

vector<int> postorderTraversal(vector<int> &res, TreeNode *root)
{
    if (root == nullptr)
    {
        return res;
    }

    stack<TreeNode *> stk;
    TreeNode *prev = nullptr;
    while (root != nullptr || !stk.empty())
    {
        while (root != nullptr)
        {
            stk.emplace(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->right == nullptr || root->right == prev)
        {
            res.emplace_back(root->val);
            prev = root;
            root = nullptr;
        }
        else
        {
            stk.emplace(root);
            root = root->right;
        }
    }
    return res;
}

/*************************************************************************************************************************
589. N 叉树的前序遍历（简单）
*/
// n叉树结点的表示
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

void pre_recursion_589(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    ans.emplace_back(root->val);
    for (int i = 0; i < root->children.size(); ++i)
    {
        pre_recursion_589(root->children[i], ans);
    }
}

vector<int> preorder(Node *root)
{
    //迭代
    // vector<int> ans;
    // if( !root )
    // return ans;

    // stack<Node*> s;
    // s.emplace(root);

    // while( !s.empty() )
    // {
    //     Node* tmp = s.top();
    //     s.pop();
    //     ans.emplace_back(tmp->val);
    //     int size = tmp->children.size();
    //     for( int i = size - 1; i >= 0; --i )//这里是关键
    //     {
    //         s.emplace(tmp->children[i]);
    //     }
    // }
    // return ans;

    //递归
    vector<int> ans;
    pre_recursion_589(root, ans);
    return ans;
}

/*************************************************************************************************************************
617. 合并二叉树(简单)
*/
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    // DFS（这题的BFS有点难，就不看了
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root2->right = mergeTrees(root1->right, root2->right);
    return root1;
}

/***********************************************************************************************************************************
102. 二叉树的层序遍历 (中等)
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]

*/
vector<vector<int>> levelOrder(TreeNode *root)
{
    // bfs
    if (!root)
        return vector<vector<int>>{};

    queue<TreeNode *> que;
    que.emplace(root);
    vector<vector<int>> ans;
    while (!que.empty())
    {
        int size = que.size();
        vector<int> v;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *tmp = que.front();
            que.pop();
            v.emplace_back(tmp->val);
            if (tmp->left)
            {
                que.emplace(tmp->left);
            }
            else if (tmp->right)
            {
                que.emplace(tmp->right);
            }
        }
        ans.emplace_back(v);
    }
    return ans;
}

/******************************************************************************************************************************
 101. 对称二叉树(简单)
*/
bool isSymmetric(TreeNode *root)
{
    // bfs
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;

    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);
    TreeNode *left, *right;
    while (!q.empty())
    {
        left = q.front();
        q.pop();
        right = q.front();
        q.pop();

        if (!left && !right)
        {
            continue;
        }
        if (!left || !right)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        q.push(left->left);
        q.push(right->right);

        q.push(left->right);
        q.push(right->left);
    }
    return true;
}

/*******************************************************************************************************************************
226. 翻转二叉树(簡單)
*/
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return root;

    queue<TreeNode *> q;
    q.push(root);
    TreeNode *left;
    TreeNode *right;
    TreeNode *tmp;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        left = tmp->left;
        tmp->left = tmp->right;
        tmp->right = left;

        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
    return root;
}

/*******************************************************************************************************************************
112.路徑總和
给你二叉树的根节点?root 和一个表示目标和的整数?targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和?targetSum 。如果存在，返回 true ；否则，返回 false 。
**********************************************************************************************************************************/
 bool hasPathSum(TreeNode* root, int targetSum)
 {
    if(!root)
    {
        return false;
    }

    //bfs
    queue<int> que_val;
    queue<TreeNode*> que_node;
    que_val.emplace(root->val);
    que_node.emplace(root);

}

/*******************************************************************************************************************************
98. 验证二叉搜索树(中等)
******************************************************************************************************************************/

bool recursion_validBST(TreeNode* root, int low, int high)
{
    if(!root)
    return true;

    if(root->val <= low || root->val >= high)
    return false;

    return recursion_validBST(root->left, low, root->val) && recursion_validBST(root->right, root->val, high);
}

bool isValidBST(TreeNode* root)
{
    //递归，设置界限
    return recursion_validBST(root, LONG_MIN, LONG_MAX);//设置为这两个最小和最大值是为了满足第一次递归root->val的值
}



/*******************************************************************************************************************************
110. 平衡二叉树(简单)：验证是否是平衡二叉树
*******************************************************************************************************************************/
int check(TreeNode *root)
{
    if(!root)
    return 0;

    int left = check(root->left);
    if(left == -1)
    return -1;
    int right = check(root->right);
    if(right == -1)
    return -1;

    if(abs(left - right) > 1)//the high difference of the left tree and right tree
    {
        return -1;
    }

    return max(left, right) + 1;
}

bool isBalanced(TreeNode* root)
{
    //从底部到顶部
    return check(root) != -1;
}

/***************************************************************************************** 1448. 统计二叉树中好节点的数目:
给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。
「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
***********************************************************************************************/
int goodNodes(TreeNode* root)
{
    // 思路：前序遍历，到达每一个结点的路径只有一个，栈用来保存右边结点和右边结点的前面的最大值，保存类型是pair类，是TreeNode结点的指针和当前位置前的最大数值
    int res = 0;
    int max = root->val;
    stack<pair<TreeNode*, int>> myStack;
    while(root || myStack.size())
    {
        while(root)
        {
            int rootVal = root->val;
            if(rootVal >= max)
            {
                ++res;
                if(rootVal > max)
                {
                    max = rootVal;
                }
            }

            if(root->right)
            {
                myStack.push(make_pair(root->right, max));
            }
            root = root->left;
        }
        if(myStack.size() == 0)
        {
           break; 
        }
        root = myStack.top().first;
        max = myStack.top().second;
    }
    return res;
}


/*******************************************************************************************************************************
865.寻找最深子树的最长子树  
*******************************************************************************************************************************/
TreeNode* subtreeWithAllDeepest(TreeNode* root) {

    if(root == nullptr)
    return root;

    int leftdeep = dfs(root->left);
    int rightdeep = dfs(root->right);

    if(leftdeep == rightdeep)
    return root;

    if(leftdeep > rightdeep)
    {
        return subtreeWithAllDeepest(root->left);
    }
    
    return subtreeWithAllDeepest(root->right);
}

int dfs(TreeNode* root)
{
    if(root == nullptr)
    return 0;

    return max(dfs(root->left), dfs(root->right)) + 1;
}

/*******************************************************************************************************************************
1038. 从二叉搜索树到更大和树
*******************************************************************************************************************************/
TreeNode* bstToGst(TreeNode* root) {
    vector<int> v = PreTravelGetVector(root);
    sort(v.begin(), v.end());
    // 再次遍历（中序），用二分法查找到v中大于等于他的下标，累加就是本节点的值
    stack<TreeNode*> s;
    TreeNode* tmp = root;
    while(tmp || !s.empty())
    {
        while(tmp)
        {
            s.push(tmp);
            tmp = tmp->left;
        }
        tmp = s.top();
        tmp->val = BinarySearch(tmp->val, v);
        s.pop();
        tmp = tmp->right;
    }
    return tmp;
}

int BinarySearch(int val, const vector<int>& v)
{
    int left = 0, right = v.size(), mid = v.size() / 2;
    while(left < right)
    {
        if(val > v[mid])
        {
            left = mid + 1;
        }
        else if(val < v[mid])
        {
            right = mid - 1;
        }else{
            right = mid;
        }
        mid = (left + (right - left) / 2);
    }
    int index = right;
    return accumulate(v.begin() + index, v.end(), 0);
}

vector<int> PreTravelGetVector(TreeNode *root)
{
    stack<TreeNode*> s;
    s.push(root);
    vector<int> v;
    while(!s.empty())
    {
        TreeNode *tmp = s.top();
        s.pop();
        while(tmp)
        {
            v.emplace_back(tmp->val);
            if(tmp->right)
            {
                s.push(tmp->right);
            }
            tmp = tmp->left;
        }
    }
    return v;
}

// 递归版
vector<int> res;
vector<int> postorderTraversal(TreeNode* root) {
    if (!root)
        return res;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    res.emplace_back(root->val);
}

// 迭代版
vector<int> postorderTraversal(TreeNode* root) {
    
}


int main()
{
    vector<int> v;
    string str; 

    stack<int> s;
}