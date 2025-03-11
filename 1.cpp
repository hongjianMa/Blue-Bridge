#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans;
int f[N]; 
void solve()
{
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        f[i] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (s[j][0] == s[i].back())
            {
                f[j] = max(f[j], f[i] + 1);
            }
        }
        ans = max(f[j], ans);
    }
    cout << n - ans;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}