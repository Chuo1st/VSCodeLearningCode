#include<iostream>
#include<algorithm>
#include<utility>
#include<assert.h>
#define DEFAULT_CAPACITY 3


template<class T>
class my_vector
{
protected:
    int m_size, m_capacity;
    T* m_elem;
    void copy_from( const T *t, int lo, int hi );
    void expand();
    void shrink(); //解决下溢
    bool bubble( int lo, int hi );
    void bubble_sort();
    int max( int lo, int hi );
    void selection_sort( int lo, int hi );
    void merge( int lo, int mid, int hi );
    void merger_sort( int lo, int hi );
    int partition( int lo, int hi );
    void quick_sort( int lo, int hi );
    void heap_sort( int lo, int hi );

public:
    //构造
    my_vector( int c = DEFAULT_CAPACITY , int s = 0, T v = 0 ) : m_size( s ), m_capacity( c )
    { m_elem = new T[ DEFAULT_CAPACITY ]; for( int i = 0; i < s; m_elem[i++] = v); }
    my_vector( const T *a, int n ) { copy_from( a, 0, n ); }
    my_vector( const T *a, int lo, int hi ) { copy_from( a, lo, hi ); }
    my_vector( const my_vector<T> &a ) { copy_from( a , 0, a.m_size() ); }
    my_vector( const my_vector<T> &a, int lo, int hi ) { copy_from( a, lo, hi ); }

    ~my_vector(){ delete [] m_elem; }
    //只读访问接口
    int  size() const { return m_size; }
    bool empty() const { return !m_size; }
    int disorderd() const; //是否有序
    int find( const T &a ) { return find( a, 0, m_size ); }
    int find( const T &a, int lo, int hi ) const; //-1表示没有
    int search( const T &a ) { if( m_size < 0 ) return -1; search( a, 0, m_size ); }
    int search( const T &a, int lo, int hi ) const;
    //可访问接口
    T& operator[] ( int r ) const;
    my_vector<T>& operator= ( const my_vector<T> &a );
    T remove( int r );
    int remove( int lo ,int hi );
    int insert( int r, const T &e );
    int insert( const T &e ) { return insert( m_size, e ); }
    void push_back( const T &a );
    void sort( int lo, int hi );
    void sort() { sort( 0, m_size ); }
    void unsort( int lo, int hi ); //打乱顺序
    void unsort() { unsort( 0, m_size) ;} //
    int deduplicate(); //无序去重
    int uniquify(); //有序去重
    //遍历
    void traverse( void (*)(const T &e) );
    template<class VT> void traverser( VT &visit );
};

template<class T> 
void my_vector<T>::copy_from( const T *a, int lo, int hi )
{
    m_elem = new T[m_capacity = 2 * (hi - lo)];
    m_size = 0;
    while( lo < hi )
    {
        m_elem[m_size++] = a[lo++];
    }
}

template< class T >
void my_vector<T>::expand()
{
    if( m_size < m_capacity )
    return;
    T* tmp = new T[m_capacity <<= 1];
    for( int i = 0; i < m_size; ++i )
    {
        tmp[i] = m_elem[i];
    }
    delete []m_elem;
    m_elem = tmp;
}

template<class T>
void my_vector<T>::shrink()
{
    if( m_size < DEFAULT_CAPACITY << 1)
    return;
    if( m_size << 2 > m_capacity )
    return;
    T* tmp = new T[m_capacity = m_capacity << 1];
    for( int i = 0; i < m_size; ++i )
    tmp[i] = m_elem[i];
    delete [] m_elem;
    m_elem = tmp;
}

template<class T>
T& my_vector<T>::operator[] ( int r ) const
{
    assert( r <= m_size - 1 );
    return m_elem[r];
}

template<class T>
my_vector<T>& my_vector<T>::operator=( const my_vector<T> &a )
{
    if( m_elem )
    delete [] m_elem;

    copy_from( a, 0, a.size() );
    return *this;
}

//乱置函数模板
template<class T>
void permute( my_vector<T> &a )
{
    for( int i = a.m_size ; i > 0; --i )
    {
        std::swap(a[i -1], a[rand() % i]);
    }
}

template<class T>
void my_vector<T>::unsort( int lo, int hi )
{
    T* V = m_elem + lo;
    for( int i = hi - lo; i > 0; --i )
    {
        swap(V[i - 1], V[rand() % i]);
    }
}

//比较器,lt:less than, eq: equal
template<class T>
static bool lt( const T &a, const T &b )
{
    return a < b;
}
template<class T>
static bool lt( T* a, T* b )
{
    return lt(*a, *b);
}

template<class T>
static bool eq( const T &a, const T &b )
{
    return a == b;
}
template<class T>
static bool eq( T *a, T *b )
{
    return eq( *a, *b );
}

template<class T>
int my_vector<T>::find( const T &a, int lo, int hi ) const
{
    while( ( lo < hi-- ) && m_elem[hi] != a );
    return hi;
}

template<class T>
int my_vector<T>::insert( int r, const T &a )
{
    if( r < 0 || r > m_size - 1 )
    return -1;
    expand();
    for( int i = m_size; i > r; --i )
    {
        m_elem[i] = m_elem[i-1];
    }
    m_elem = a;
    m_size++;
    return r;
}

template<class T>
void my_vector<T>::push_back( const T &a )
{
    expand();
    m_elem[m_size++] = a;
}

template<class T>
int my_vector<T>::remove( int lo, int hi )
{
    if( lo == hi )
    return 0;
    while( hi < m_size )
    m_elem[lo++] = m_elem[hi++];
    m_size = lo;
    shrink();
    return hi - lo;
}

template<class T>
T my_vector<T>::remove( int r )
{
    T ret = m_elem[r];
    remove( r, r + 1 );
    return ret;
}

template<class T>
int my_vector<T>::deduplicate()
{
    int old_size = m_size;
    for( int i = 0; i < m_size; ++i )
    {
        if( find( m_elem[i] ) > 0 )
        remove(i);
    }
    return old_size - m_size;
}

template<class T>
void my_vector<T>::traverse( void (*visit)( const T &a ) )
{
    for( int i = 0; i < m_size; ++i )
    {
        visit(m_elem[i]);
    }
}


template<class T> template<class T2>
void my_vector<T>::traverser( T2 &visit)
{
    for( int i = 0; i < m_size; ++i )
    {
        visit(m_elem[i]);
    }
}

int main()
{
    my_vector<int> v;
    v.push_back(1);
    std :: cout << v[0] << std::endl;
    return 0;
}