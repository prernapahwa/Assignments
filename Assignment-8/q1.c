/**
 * Program to print n even elements of fibonacci series
 * 
 * @Prerna(1910990964)
 * 
 * Assignment-8-Algorithm
 * Question1
 */

#include<stdio.h>

int even_fib(int n) {
    //first even element of fibonacci
    if(n == 0 ) {
        return 0;
    }
    //second even 
    if(n == 1) {
        return 2;
    }
    // 3rd even
    if(n == 2) {
        return 8;
    }
    return (4 * even_fib(n-1)) + even_fib(n-2);
}

int main() {
    int n;
    scanf("%d",&n);

    int i;
    while(n--) {
        printf("%d ",even_fib(i));
        i++;
    }
    return 0;
}
