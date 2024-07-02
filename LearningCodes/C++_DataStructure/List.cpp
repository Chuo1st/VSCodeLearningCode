#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace::std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode( int v = 0 )
    {
        val =v;
        next = nullptr;
    }
};


void show(  ListNode* head )
{
    ListNode *tmp = head;
    while( tmp )
    {
        cout << tmp->val << " ";
    }
    cout << endl;
}

/*******************************************反转链表**************************************************************************************/
//递归的方式很复杂，理解就好。。。。
ListNode* reverse_recursion( ListNode* head)
{
    if( !head || !head->next )
    return head;

    ListNode *newnode = reverse_recursion( head->next );
    head->next->next = head;
    head->next = nullptr;
    return newnode;
}

ListNode* reverse( ListNode* head )
{
    if( !head )
    return head;

    ListNode* cur = head;
    ListNode* next = head->next;
    cur->next = nullptr;
    ListNode* tmp;
    while( next )
    {
        tmp = next->next;
        next->next = cur;
        cur = next;
        next = tmp;
    }
    return cur;
}

/*
  中等难度：反转第n个结点到第m个结点的链表
  方法1：开辟一个空间用于存放每一个结点，然后反转局部数据，最后把全部几点连接
  方法2：截取中间的链表反转，然后拼接
*/

//方法1
ListNode* reverseBetween(ListNode *head, int m, int n) {
    if( !head )
    return head;

    vector<ListNode*> v;
    //ListNode* tmp = head;
    while( head )
    {
        v.emplace_back(head);
        head = head->next;
    }

    int i = m - 1;
    int j = n - 1;
    while( i < j )
    {
        swap( v[i], v[j] );
        ++i;
        --j;
    }

    head = v[0];
    for( int k = 1; k < v.size(); ++k )
    {
        head->next = v[k];
        head = head->next;
    }
    head->next = nullptr;
    return v[0];
}

//方法2
class Solution {
private:
    void reverseLinkedList(ListNode *head) {
        // 也可以使用递归反转一个链表
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
        // 建议写在 for 循环里，语义清晰
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        // 第 3 步：切断出一个子链表（截取链表）
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        // 注意：切断链接
        pre->next = nullptr;
        rightNode->next = nullptr;

        // 第 4 步：同第 206 题，反转链表的子区间
        reverseLinkedList(leftNode);

        // 第 5 步：接回到原来的链表中
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};

/*  困难难度：反转长度等于k的链表，如果有多段长度为k的就分size / k 次反转，长度小于k的不用处理
    其实两种方法都是和上一题一样的，只是复杂一点
    方法1：创建一个vector存放所有node，然后局部反转size/k次，然后全部连上
*/

//方法1
ListNode* reverseKGroup( ListNode* head, int k )
{
    if( !head )
    return head;

    vector<ListNode*> v;
    while( head )
    {
        v.emplace_back( head );
        head = head->next;
    }

    int times = v.size() / k;
    int i = 0;
    int j = k - 1;
    for( int o = 1; o <= times; ++o )
    {
        while( i < j )
        {
            swap( v[i], v[j] );
            ++i;
            --j;
        }
        i = o * k;
        j = i + k - 1;
    }

    head = v[0];
    for( i = 1; i < v.size(); ++i )
    {
        head->next = v[i];
        head = head->next;
    }
    head->next = nullptr;
    return v[0];
}

//方法2
ListNode* reverse_hard( ListNode* head )
{
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* tmp = nullptr;

    while( cur )
    {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

// ListNode* reverseKGroup( ListNode* head, int k )
// {
//     if( !head )
//     return head;

//     ListNode* dummy = new ListNode( -1 );
//     dummy->next = head;
//     ListNode* pre = dummy;
//     ListNode* end = dummy;
//     while( end->next )
//     {
//         for( int i = 0; i < k && end ; ++i )
//         {
//             end = end->next;
//         }
//         if( !end )
//         break;
//         ListNode* start = pre->next;
//         ListNode* next = end->next;
//         end->next = nullptr;

//         pre->next = reverse_hard( start );
//         start->next = next;
        
//         pre = start;
//         end = pre;
//     }
//     return dummy->next;
// }

/******************************************************************环形链表******************************************************************************/
/*
难度：简单
141. 环形链表:判断是否是环形链表
*/
bool hasCycle(ListNode *head)
{
    if( !head || !head->next )
    return false;

    ListNode* fast = head;
    ListNode* slow = head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    }while( slow && fast && slow->next && fast->next && slow != fast );

    if( fast == slow )
    return true;
    else return false;
}

/*
难度：中等
    142.返回环形链表的入口处，不是环形链表返回nullptr
*/
ListNode *detectCycle(ListNode *head)
{
    if( !head || !head->next )
    return nullptr;

    ListNode* fast =head;
    ListNode* slow = head;

    while( fast )
    {
        if( fast == slow )
        {
            fast = head;
            while( fast != slow )
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        slow = slow->next;
        if( !fast->next )
        return nullptr;
        fast = fast->next->next;
    }
    return nullptr;
}



/**********************************************************************************************************************
中等难度，排序链表
快排和归并
*/

//方法1：快排，并且交换元素的值。 在LeetCode上过不了，因为存在极端情况，由于链表不是数组不能随机访问，有点麻烦

ListNode* partition_list(ListNode *head, ListNode *tail)
{
    int cmp_value = head->val;
    ListNode *l = head;
    ListNode *r = head->next;
    //循环这里就是交换值，很妙,首次partition是r!=nullptr，以后partition左边的partition是不用比较上一次的mid，右边就循环到nullptr为止
    while( r != tail )
    {
        if( r->val < cmp_value )
        {
            l = l->next;
            swap(l->val, r->val);
        }
        r = r->next;
    }
    swap(l->val,head->val);
    return l;
}

void quicksort_list(ListNode *head, ListNode *tail)
{
    if( head != tail )
    {
        ListNode *mid = partition_list(head, tail);
        quicksort_list(head, mid);
        quicksort_list(mid->next, tail);
    }
}

ListNode* sortList(ListNode *head)
{
    quicksort_list(head, nullptr);//设置nullptr对应首次partition的循环结束条件，经过首次partition后区间都是[head,mid),[mid, tail)
    return head;
}

/*****************************************************************************************************
138.复制一个复杂的链表  (中等)
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) { 
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    if(!head)
    return nullptr;

    Node* tmp = head;
    map<Node*, Node*> m;
    //建立新节点和旧结点的映射关系
    while(tmp)
    {
        m[tmp] = new Node(tmp->val);
        tmp = tmp->next;
    }

    tmp = head;
    while(tmp)
    {
        if(m.find(m[tmp->random]) != m.end())
        {
            m[tmp]->random = m[tmp->random];
        }else{
            m[tmp]->random = nullptr;
        }
        tmp = tmp->next;
    }

    tmp = head;
    while(tmp->next)
    {
        m[tmp]->next = m[tmp->next];
        tmp = tmp->next;
    }
    return m[head];
}

/*****************************************************************************************************/

ListNode* reverseList(ListNode* head)
{
    if(!head || !head->next)
    return nullptr;

    ListNode* prev= nullptr;
    while(head)
    {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* removeNodes(ListNode* head) {
    ListNode* res = reverseList(head);
    
    ListNode* begin = res;
    while(begin)
    {
        ListNode* next = begin->next;
        while(next && begin->val > next->val)
        {
            next = next->next;
        }
        begin->next = next;
        begin = begin->next;
    }
    res = reverseList(res);
    return res;
}

//-----------------------------------------------------

bool compLength(string str1, string str2)
{
    return str1.size() < str2.size();
}
int main()
{
    vector<string> v = {"asdf", "a", "", "adsfasfd"};
    sort(v.begin(), v.end(),compLength);
    for(string str : v)
    {
        cout << str << endl;
    }
}