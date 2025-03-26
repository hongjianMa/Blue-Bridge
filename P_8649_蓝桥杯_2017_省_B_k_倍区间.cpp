#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, k;
int a[N];
int s[N]; // 前缀和数组
int st[N]; // 哈希表
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    // 预处理前缀和数组
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];

    int cnt = 0;
    // for (int i = 1; i <= n; i ++)
    //     for(int j = i; j <= n; j ++)
    //     {
    //         if ((s[j] - s[i - 1]) % k == 0) cnt ++;
    //     }
    // cout << cnt;
    // st[0] = 1
    for (int i = 0; i <= n; i ++)
    {
        cnt += st[s[i] % k]++;
    }
    cout << cnt;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}