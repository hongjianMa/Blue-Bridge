#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e3 + 10;
char g[N][N];
int n, m, k;
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        cin >> (g[i]+1);
    if (g[1][2] == 'B' && g[2][1] == 'B') cout << -1;
    else cout << -1;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}