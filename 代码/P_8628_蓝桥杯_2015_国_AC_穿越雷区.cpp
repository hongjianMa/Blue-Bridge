#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 110;
int n, ans = 1e9;
char g[N][N];
bool st[N][N];
int a1, b1, c2, d2;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int cnt, char ch)
{
    // 剪枝
    if (cnt >= ans) return ;
    if (x == c2 && y == d2)
    {
        ans = min (ans, cnt);
        return ;
    }
    for (int i = 0; i < 4; i ++)
    {
        int a = x + dx[i], b = y + dy[i];
        // 判断图的边界
        if (a < 1 || b < 1 || a > n || b > n);
        // 判断状态
        if (st[a][b]) continue;
        // 判断题目限制 -- 交替
        if (g[a][b] == ch) continue;
        st[a][b] = 1;
        dfs(a, b, cnt + 1, g[a][b]);
        st[a][b] = 0; // 回溯
    }
    
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
                a1 = i, b1 = j;
            if (g[i][j] == 'B')
                c2 = i, d2 = j;
        }
    dfs(a1, b1, 0, 'A');
    if (ans != 1e9)
        cout << ans << "\n";
    else 
        cout << -1 << "\n";
    
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}