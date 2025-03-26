#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D, K;
    cin >> N >> D >> K;

    unordered_map<int, vector<int>> logs;
    set<int> ids;

    for (int i = 0; i < N; ++i)
    {
        int ts, id;
        cin >> ts >> id;
        logs[id].push_back(ts);
        ids.insert(id);
    }

    vector<int> res;

    for (int id : ids)
    {
        vector<int> &ts_list = logs[id];
        sort(ts_list.begin(), ts_list.end());
        int left = 0;
        int count = 0;
        bool found = false;

        for (int right = 0; right < ts_list.size(); ++right)
        {
            count++;

            while (ts_list[right] - ts_list[left] >= D)
            {
                left++;
                count--;
            }

            if (count >= K)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            res.push_back(id);
        }
    }

    sort(res.begin(), res.end());

    for (int id : res)
    {
        cout << id << '\n';
    }

    return 0;
}