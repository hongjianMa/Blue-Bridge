#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e5 + 10;
int n, ans;
unordered_map<int, int> dp;
void solve()
{
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i ++)
    {
        // 对于每一个序列
        int head = s[i][0];
        int tail = s[i].back();
        int curLen = dp[head] + 1; // 当前数结尾的最长序列
        dp[tail] = max(dp[tail], curLen);  //更新以当前数末尾结尾的最长序列长度
        ans = max(ans, dp[tail]); // 全局答案
    }
    cout << n - ans; 
    

}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}