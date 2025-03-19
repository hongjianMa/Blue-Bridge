#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n, m, k;
char g[N][N];
bool st[N][N][15];

struct Node
{
    int x, y, step;
    char ch;
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
    queue<Node> q;
    q.push({0, 0, 0, 'A'});
    st[0][0][0] = true;

    while (!q.empty())
    {
        Node t = q.front();
        q.pop();

        if (t.x == n - 1 && t.y == m - 1)
        {
            cout << t.step << endl;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int a = t.x + dx[i];
            int b = t.y + dy[i];

            if (a < 0 || b < 0 || a >= n || b >= m)
                continue;

            int tmp = ((t.step + 1) / k) % 2;
            char expectedChar = tmp + 'A';

            if (g[a][b] == expectedChar && !st[a][b][(t.step + 1) % k])
            {
                st[a][b][(t.step + 1) % k] = true;
                q.push({a, b, t.step + 1, g[a][b]});
            }
        }
    }

    cout << -1 << endl;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    bfs();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}