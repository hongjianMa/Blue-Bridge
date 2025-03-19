#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e3 + 10;
char g[N][N];
int n, m, k;
struct Node
{
    int x, y, sum = 0;
    char ch;
};

// Node node[N * N];
int ans = -1;

// 因为节点可能被重复经过，开三维
bool st[N][N][15];
Node q[N * N * 10]; // 可能重复走，要开大点，考场直接寄
int tt = -1, hh = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
    q[++tt] = {1, 1, 0, 'A'};
    st[1][1][0] = 1;
    while (hh <= tt)
    {
        auto t = q[hh++];
        if (t.x == n && t.y == m)
        {
            ans = t.sum;
            cout << ans <<"\n";
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 1 || b < 1 || a > n || b > m)
                continue;

            // 判断走没有走完k步
            int tmp = ((t.sum + 1) / k) % 2;
            char nextch = tmp + 'A';

            if (g[a][b] == nextch && !st[a][b][(t.sum + 1) % k])
            {
                st[a][b][(t.sum + 1) % k] = true;
                q[++tt] = {a, b, t.sum + 1, g[a][b]};
            }
        }
    }
    cout << -1;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> (g[i] + 1);
    bfs();
    // cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}