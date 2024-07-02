#include<stdio.h>
#include<stdarg.h>
#include<stack>
#include<iostream>
using namespace :: std;

int fibonacci( int n )
{
    int num[n+1];
    for( int i = 1; i <= n; ++i )
    {
        if( i <= 2 )
        num[i-1] = i - 1;
        else{
            num[i] = num[i - 1] + num[i - 2];
        } 
    }
    return num[n];
}

//递归的裴波那契数 这个速度极慢
int fibonacci_recursion( int n )
{
    if( n <= 2 )
    {
        return n - 1;
    }
    return fibonacci_recursion( n -1 ) + fibonacci_recursion( n - 2 );
}

//优化版



#include<assert.h>

char* my_strcpy( char* target, const char* source )
{
    assert(target);
    assert(source);

    while( *source != '\0' )
    {
        *target++ = *source++;
    }
    *target = '\0';
    return target;
}

char* my_strcat( char* target, const char* source )
{
    assert(target);
    assert(source);

    while( *target != '\0' )
        ++target;
    while( *source != '\0' )
        *target++ = *source++;
    
    *target = '\0';
    return target;
}

int my_strcmp( const char* str1, const char* str2 )
{
    assert(str1);
    assert(str2);

    while( *str1 && *str2 )
    {
        if( *str1 > *str2 )
        return 1;
        else if( *str1 < *str2 )
        {
            return -1;
        }else{
            ++str1;
            ++str2;
        }
    }

    if( *str1 == '\0' )
    {
        return -1;
    }else if( *str1 == *str2 ){
        return 0;
    }else{
        return 1;
    }
}

/************************************************** 实现简单的 printf 只处理c,d,s,  *************************************/

void printchar( const char ch )
{
    putchar(ch);
}

void printstr( const char* str )
{
    while( *str )
    {
        putchar( *str++ );
    }
}

//递归
void printint( const int i )
{
    if( !i )
    {
        return;
    }
    printint( i / 10 );
    putchar( i % 10 + '0' );
}

void my_printf( const char* format, ... )
{
    va_list valist;
    va_start( valist, format );
    while( *format )
    {
        if( *format != '%' )
        {
            printchar(*format++);
        }
        else{
            format++;
            switch(*format)
            {
                case('c') :
                {
                    char ch = va_arg(valist, int);
                    printchar(*format++);
                    break;
                }

                case('d') :
                {
                    int i = va_arg(valist, int);
                    printint(i);
                    format++;
                    break;
                }

                case('s') :
                {
                    const char* str = va_arg(valist, char*);
                    printstr(str);
                    format++;
                    break;
                }
                default :
                {
                    printchar(*format++);
                }
            }
        }
    }
}

/*****************************************************************************************************/


int main()
{
    stack<int> s;
    
    cout << fibonacci_recursion( 5 ) << endl;
}