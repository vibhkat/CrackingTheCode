#include"Chapter8.h"


int fibonacci(int n , int* p)
{
if(n==0 || n==1) return n;
if(p[n]== 0)
	p[n]= fibonacci(n-1, p) + fibonacci(n-2 , p);
return p[n];
}

int fibonacci(int n)
{
	int *p = new int[n+1]();  // always initialize it
return fibonacci(n, p);
}

int tripleStep(int n)
{
if (n<0) return 0;
else if(n==0) return 1;
else return tripleStep(n-1)+ tripleStep(n-2)+ tripleStep(n-3);
}

int tripleStepMemo(int n)
{
int *p = new int[n+1]();
return tripleStepMemo(n , p);
}

int tripleStepMemo(int n , int* memo)
{
if (n == 0) return 1;
else if (n < 0 ) return 0;
else if (memo[n] == 0) memo[n] = tripleStepMemo(n-1, memo) + tripleStepMemo(n-2, memo) + tripleStepMemo(n-3, memo);
return memo[n];
}

