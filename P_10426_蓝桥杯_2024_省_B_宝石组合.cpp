#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
int a[N];
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int cal(int a, int b, int c)
{
    int fz1 = lcm(lcm(a, b), c);
    int fm1 = lcm(a, b);
    int fm2 = lcm(a, c);
    int fm3 = lcm(b, c);
    return a * b * c * fz1 / (fm1 * fm2 * fm3);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int a1, a2, a3;
    int mmax = -1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                if (i == j || i == k || j == k) continue;
                int x = cal(a[i], a[j], a[k]);
                if(x > mmax)
                {
                    a1 = a[i];
                    a2 = a[j];
                    a3 = a[k];
                    mmax = x;
                }
            }
        // cout << a1 << " " << a2 << " " << a3 << "\n";
    }
    cout << a1 << " " << a2 << " " <<a3;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}