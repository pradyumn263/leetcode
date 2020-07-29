/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (tasks.size() <= n)
            return tasks.size();

        vector<int> mp(26, 0);
        for (char ch : tasks)
        {
            mp[ch - 'A']++;
        }

        auto compare = [&]

            priority_queue<int>
                pq;

        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i])
                pq.push(mp[i]);
        }

        vector<vector<char>> st(n * maxCount, vector<int>);

        while (!pq.empty())
        {
            int top = pq.top();
            pq.pop();

            for (int i = 0; top > 0 && i < st.size(); i++)
            {
                if (st[i].size() < n)
                {
                    top--;
                    st[i].push_back(top);
                }
            }

            while (top)
            {
                st.push_back({top});
            }
        }

        int ans = 0;
        for (int i = 0; i < st.size(); i++)
        {
            ans += st[i].size();
        }
        return ans;
    }
};
// @lc code=end
