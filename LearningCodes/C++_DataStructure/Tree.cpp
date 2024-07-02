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


/*                       144.������ǰ���v�����Σ�                   */
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

/*                       94.�����������v�����Σ�                   */
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
        // ע�⣺���������ôд�����д��if�ж��ҽڵ��Ƿ�Ϊ�ղŸ�ֵ����ôroot���ǿվ�һֱ��ѭ������Ϊroot��ֵһֱֻ��ͣ����ĳ���ǿս��
        root = root->right;
    }
}


/*                       145.�����ĺ����v�����Σ�                   */
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
589. N ������ǰ��������򵥣�
*/
// n�������ı�ʾ
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
    //����
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
    //     for( int i = size - 1; i >= 0; --i )//�����ǹؼ�
    //     {
    //         s.emplace(tmp->children[i]);
    //     }
    // }
    // return ans;

    //�ݹ�
    vector<int> ans;
    pre_recursion_589(root, ans);
    return ans;
}

/*************************************************************************************************************************
617. �ϲ�������(��)
*/
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    // DFS�������BFS�е��ѣ��Ͳ�����
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
102. �������Ĳ������ (�е�)
���룺root = [3,9,20,null,null,15,7]
�����[[3],[9,20],[15,7]]
ʾ�� 2��

���룺root = [1]
�����[[1]]

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
 101. �Գƶ�����(��)
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
226. ��ת������(����)
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
112.·������
����������ĸ��ڵ�?root ��һ����ʾĿ��͵�����?targetSum ���жϸ������Ƿ���� ���ڵ㵽Ҷ�ӽڵ� ��·��������·�������нڵ�ֵ��ӵ���Ŀ���?targetSum ��������ڣ����� true �����򣬷��� false ��
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
98. ��֤����������(�е�)
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
    //�ݹ飬���ý���
    return recursion_validBST(root, LONG_MIN, LONG_MAX);//����Ϊ��������С�����ֵ��Ϊ�������һ�εݹ�root->val��ֵ
}



/*******************************************************************************************************************************
110. ƽ�������(��)����֤�Ƿ���ƽ�������
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
    //�ӵײ�������
    return check(root) != -1;
}

/***************************************************************************************** 1448. ͳ�ƶ������кýڵ����Ŀ:
����һ�ø�Ϊ root �Ķ����������㷵�ض������кýڵ����Ŀ��
���ýڵ㡹X ����Ϊ���Ӹ����ýڵ� X �������Ľڵ��У�û���κνڵ��ֵ���� X ��ֵ��
***********************************************************************************************/
int goodNodes(TreeNode* root)
{
    // ˼·��ǰ�����������ÿһ������·��ֻ��һ����ջ���������ұ߽����ұ߽���ǰ������ֵ������������pair�࣬��TreeNode����ָ��͵�ǰλ��ǰ�������ֵ
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
865.Ѱ�����������������  
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
1038. �Ӷ������������������
*******************************************************************************************************************************/
TreeNode* bstToGst(TreeNode* root) {
    vector<int> v = PreTravelGetVector(root);
    sort(v.begin(), v.end());
    // �ٴα��������򣩣��ö��ַ����ҵ�v�д��ڵ��������±꣬�ۼӾ��Ǳ��ڵ��ֵ
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

// �ݹ��
vector<int> res;
vector<int> postorderTraversal(TreeNode* root) {
    if (!root)
        return res;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    res.emplace_back(root->val);
}

// ������
vector<int> postorderTraversal(TreeNode* root) {
    
}


int main()
{
    vector<int> v;
    string str; 

    stack<int> s;
}