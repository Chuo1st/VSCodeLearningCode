#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include<time.h>
using namespace ::std;

// 展示数组
void show(const vector<int> &v)
{
    for (auto tmp : v)
    {
        cout << tmp << " ";
    }
    cout << endl;
}
// 用随机数初始化数组
void random_create_number(vector<int> &v)
{
    for( int i = 0; i < 3; ++i )
    {
        v.emplace_back( rand() % time(nullptr) % 20);
    }
}

// 冒泡
template <class T>
void bubblesort(vector<T> &v)
{
    int size = v.size();
    T tmp;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (v[j] > v[j + 1])
            {
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}

// 选择
void selectsort(vector<int> &v)
{
    int size = v.size();
    int min;
    for (int i = 0; i < size - 1; ++i)
    {
        min = v[i];
        for (int j = i + 1; j < size; ++j)
        {
            if (min > v[j])
            {
                swap(min ,v[j]);
            }
        }
        v[i] = min;
    }
}

// 插入
template <class T>
void insertsort(vector<T> &v)
{
    int size = v.size();
    int j;

    for (int i = 1; i < size; ++i)
    {
        j = i;
        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j - 1], v[j]);
            --j;
        }
    }
}

// 快排
int partition(vector<int> &v, int left, int right)
{
    int tmp = v[left];
    while(left < right)
    {
        //循环为什么要是<=和>=，比如说出现 6 12 6 这样的排序情况，写成<和>，将会在这个循环中死循环
        while(left < right && v[right] >= tmp)
        {
            --right;
        }
        v[left] = v[right];
        while(left < right && v[left] <= tmp)
        {
            ++left;
        }
        v[right] = v[left];
    }
    v[left] = tmp;
    return left;
}

void quicksort(vector<int> &v, int left, int right)
{
    if(left < right)
    {
        int mid = partition(v, left, right);
        quicksort(v, left, mid - 1);
        quicksort(v, mid + 1, right);
    }
}


// 堆排序
void heapify(vector<int> &v, int low, int high)
{
    
}

void build_heap(vector<int> &v)
{
    if(v.size() <= 1)
    return;

    int low = 0;
    int high = v.size() - 1;

}
void heapsort(vector<int> &v)
{

}


int main()
{
    string str;
    vector<int> v;
    random_create_number(v);
    show(v);
    //bubblesort(v);
    //selectsort(v);
    //insertsort(v);
    quicksort(v, 0, v.size() - 1);
    show(v);
    return 0;
}
