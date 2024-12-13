#include <bits/stdc++.h>
using namespace std;
// varient 1
int ans(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i); // 10*9*8
        res = res / (i + 1); // 10/1*9/2*8/3
    }
    return res;
}

int main()
{
    int r = 5;
    int c = 3;
    printf("%d", ans(r - 1, c - 1)); // to find the element we do, (n-1)C(r-1);
}