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

/*******************************************��ת����**************************************************************************************/
//�ݹ�ķ�ʽ�ܸ��ӣ����ͺá�������
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
  �е��Ѷȣ���ת��n����㵽��m����������
  ����1������һ���ռ����ڴ��ÿһ����㣬Ȼ��ת�ֲ����ݣ�����ȫ����������
  ����2����ȡ�м������ת��Ȼ��ƴ��
*/

//����1
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

//����2
class Solution {
private:
    void reverseLinkedList(ListNode *head) {
        // Ҳ����ʹ�õݹ鷴תһ������
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
        // ��Ϊͷ�ڵ��п��ܷ����仯��ʹ������ͷ�ڵ���Ա��⸴�ӵķ�������
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        // �� 1 ����������ͷ�ڵ��� left - 1 �������� left �ڵ��ǰһ���ڵ�
        // ����д�� for ѭ�����������
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        // �� 2 ������ pre ���� right - left + 1 �������� right �ڵ�
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        // �� 3 �����жϳ�һ����������ȡ����
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        // ע�⣺�ж�����
        pre->next = nullptr;
        rightNode->next = nullptr;

        // �� 4 ����ͬ�� 206 �⣬��ת�����������
        reverseLinkedList(leftNode);

        // �� 5 �����ӻص�ԭ����������
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};

/*  �����Ѷȣ���ת���ȵ���k����������ж�γ���Ϊk�ľͷ�size / k �η�ת������С��k�Ĳ��ô���
    ��ʵ���ַ������Ǻ���һ��һ���ģ�ֻ�Ǹ���һ��
    ����1������һ��vector�������node��Ȼ��ֲ���תsize/k�Σ�Ȼ��ȫ������
*/

//����1
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

//����2
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

/******************************************************************��������******************************************************************************/
/*
�Ѷȣ���
141. ��������:�ж��Ƿ��ǻ�������
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
�Ѷȣ��е�
    142.���ػ����������ڴ������ǻ���������nullptr
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
�е��Ѷȣ���������
���ź͹鲢
*/

//����1�����ţ����ҽ���Ԫ�ص�ֵ�� ��LeetCode�Ϲ����ˣ���Ϊ���ڼ���������������������鲻��������ʣ��е��鷳

ListNode* partition_list(ListNode *head, ListNode *tail)
{
    int cmp_value = head->val;
    ListNode *l = head;
    ListNode *r = head->next;
    //ѭ��������ǽ���ֵ������,�״�partition��r!=nullptr���Ժ�partition��ߵ�partition�ǲ��ñȽ���һ�ε�mid���ұ߾�ѭ����nullptrΪֹ
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
    quicksort_list(head, nullptr);//����nullptr��Ӧ�״�partition��ѭ�����������������״�partition�����䶼��[head,mid),[mid, tail)
    return head;
}

/*****************************************************************************************************
138.����һ�����ӵ�����  (�е�)
��ʵ�� copyRandomList ����������һ�����������ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬����һ�� random ָ��ָ�������е�����ڵ���� null��
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
    //�����½ڵ�;ɽ���ӳ���ϵ
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