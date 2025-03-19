#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n;
int a[N], b[N], c[N];
void solve1()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                if (a[i] < b[j] && b[j] < c[k])
                    cnt++;
            }
    cout << cnt << "\n";
}

int bifind_a(int x)
{
    int l = -1, r = n + 1;
    while ( l + 1 != r)
    {
        int mid = l + r >> 1;
        if (a[mid] < x)
            l = mid;
        else
            r = mid;
    }
    if (a[l] < x) return l; // 返回个数
    else return 0;

}

int bifind_c(int x)
{
    int l = -1, r = n + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (c[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    if (c[r] > x)
        return n - r + 1; // 返回个数
    else
        return 0;
}

void solve2()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int cnt = 0;
    sort(a + 1, a + 1 + n);
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++)
    {   
        int x = bifind_a(b[i]);
        int y = bifind_c(b[i]);
        cnt += x * y;

    }
    cout << cnt << "\n";
}
void solve3()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int cnt = 0;
    sort(a + 1, a + 1 + n);
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int x = lower_bound(a + 1, a  + 1 + n, b[i]) - a - 1;
        int y = n - (upper_bound(c + 1, c + 1 + n, b[i]) - c) + 1;
        cnt += x * y;
    }
    cout << cnt << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve2();
    return 0;
}