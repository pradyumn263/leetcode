/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxTurbulenceSize(vector<int> &A)
    {
        int n = A.size();
        int i;

        vector<int> minTurb(n, 1);
        vector<int> maxTurb(n, 1);

        int ans = 1;

        for (i = 1; i < n; i++)
        {
            if (A[i] > A[i - 1])
            {
                maxTurb[i] = minTurb[i - 1] + 1;
            }
            else if (A[i] < A[i - 1])
            {
                minTurb[i] = maxTurb[i - 1] + 1;
            }

            ans = max(ans, minTurb[i]);
            ans = max(ans, maxTurb[i]);
        }

        return ans;
    }
};
// @lc code=end
