#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e3 + 10;
int n, m, k;
char g[N][N];
struct Node
{
    int x, y, sum = 0;
    char ch;
    Node() : x(0), y(0), sum(0), ch('\0') {}
    Node(int _x, int _y, int _sum, char _ch) : x(_x), y(_y), sum(_sum), ch(_ch) {}
};

Node q[N * N * 10];

// 三维-引入了连续k次A或B
bool st[N][N][15];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
    int tt = -1, hh = 0;
    q[++tt] = {1, 1, 0, 'A'}; // 存起点
    // 一个状态数组st--判断是否走过
    st[1][1][0] = true;
    while (hh <= tt)
    {


        auto t = q[hh++];
        if (t.x == n && t.y == m)
        {
            cout << t.sum;
            return ;
        }
        for (int i = 0; i < 4; i ++)
        {
            int a = t.x + dx[i];
            int b = t.y + dy[i];
            //判断边界
            if (a < 1 || b < 1 || a > n || b > m) continue;
            // 计算下一个应该走的字符是什么
            int tmp = ((t.sum + 1) / k) % 2;
            char nextch = 'A' + tmp;

            // 判断是否走过
            if(st[a][b][t.sum % k + 1]) continue;
            if (g[a][b] == nextch)
            {
                st[a][b][(t.sum % k) + 1] = true;
                q[++tt] = {a, b, t.sum + 1, g[a][b]};
            }
        }

    }

    cout << -1;

}





void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        cin >> (g[i] + 1); 
    bfs();
   
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}