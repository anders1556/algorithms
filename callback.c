/*
 * callback.c
 *
 *  Created on: 2014年4月30日
 *      Author: houbo
 */


#include <stdio.h>

int doit(int (*f)(int),int n)
{
        return f(f(f(n)));
}

int minus2(int n)
{
        return n - 2;
}

int main()
{

        int n =doit(minus2,9);
        printf("%d ",n);
        return 0;
}
