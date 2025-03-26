#include <bits/stdc++.h>
using namespace std;
// #define int long long
// const int N = ;
int n, d, k;
void solve()
{
    cin >> n >> d >> k;
    unordered_map<int, vector<int>>logs;  // 字典
    // 需要把有了的id存下来
    set<int> ids;
    for (int i = 1; i<= n; i ++)
    {
        int a, b;
        cin >> a >> b;
        logs[b].push_back(a);
        ids.insert(b);
    }

    // 记录答案id的数组
    vector<int> res;

    // 对每个id进行单独操作
    for (int id : ids)
    {
        auto &tsList = logs[id];
        int cnt = 0, left = 0;
        bool flag = false;
        // 排序时间戳
        sort(tsList.begin(), tsList.end());

        for (int i = 0; i < tsList.size(); i ++)
        {
            cnt ++; // 点赞数量加1

            // 窗口移动
            while (tsList[i] - tsList[left] >= d)
            {
                left ++;
                cnt--;  // 窗口里面的时间戳数量
            }
            if (cnt >= k)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            res.push_back(id);
        }
    }
    
    // 得到了所有符合条件的id
    sort(res.begin(), res.end());

    // 输出
    for (int id : res)
    {
        cout << id << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}