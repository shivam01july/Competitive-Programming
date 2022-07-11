/************************************************/
/*              Fibonacci Number                */
/************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;


int fibBasic(int n)
{
    int x1 = 0;
    int x2 = 1;
    int res;
    for(int i = 2; i <= n; i++)
    {
        res = x1 + x2;
        x1 = x2;
        x2 = res;
    }
    
    return res;
}

int fibRec(int n)
{
    if(n <= 1)
        return n;    
    
    return fibRec(n-1) + fibRec(n-2);
}

int fibDpTabulation(int n)
{
    int res[n+2];
    res[0] = 0;
    res[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        res[i] = res[i-1] + res[i-2];
    }
    
    return res[n];
}

int fibDpMemoization(int n)
{
    static vector<int> fib(n, 0);
    
    if(n <= 1)
        return n;
        
    if(fib[n])
        return fib[n];
    
    return fib[n] = fibDpMemoization(n-1) + fibDpMemoization(n-2);    
}


int main()
{
    int num = 9;
    
    cout << "Iteration      : " << fibBasic(num) << endl;
    cout << "Recursion      : " << fibRec(num) << endl;
    cout << "Dp Tabulation  : " << fibDpTabulation(num) << endl;
    cout << "Dp Memoization : " << fibDpMemoization(num) << endl;

    return 0;
}
