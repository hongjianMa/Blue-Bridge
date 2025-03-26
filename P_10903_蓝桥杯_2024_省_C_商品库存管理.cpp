#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m;
int l[N] = {0};
int r[N] = {0};
int diff[N] = {0};
int arr[N] = {0};
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &l[i], &r[i]);
        diff[l[i]]++;
        diff[r[i + 1]]--;
    }
    for (int i = 1; i <= m; i++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            diff[l[i]]--;
            diff[r[i + 1]]++;
            arr[j] = arr[j - 1] + diff[j];
            if (arr[j] == 0)
                res++;
        }
        printf("%d\n", res);
    }
}