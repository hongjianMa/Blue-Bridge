#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1010;
int m, n, k;
int f[N * N];
int find(int x)
{
    return f[x] == x? x : f[x] = find(f[x]);
}
void solve()
{
    cin >> m >> n >> k;
    
    for (int i = 1; i <= n * m; i ++)
        f[i] = i;

    for (int i = 1; i <= k; i ++)
    {
        int a, b;
        cin >> a >> b;
        int x = find(a), y = find(b);
        if (x != y)
        {
            f[x] = y;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n * m; i ++)
        if (f[i] == i) ans ++;
    cout << ans;

}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}