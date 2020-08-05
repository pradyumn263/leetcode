/*
 * @lc app=leetcode id=444 lang=cpp
 *
 * [444] Sequence Reconstruction
 *
 * https://leetcode.com/problems/sequence-reconstruction/description/
 *
 * algorithms
 * Medium (21.96%)
 * Likes:    264
 * Dislikes: 927
 * Total Accepted:    26.9K
 * Total Submissions: 121.3K
 * Testcase Example:  '[1,2,3]\r\n[[1,2],[1,3]]\r'
 *
 * Check whether the original sequence org can be uniquely reconstructed from
 * the sequences in seqs. The org sequence is a permutation of the integers
 * from 1 to n, with 1 ≤ n ≤ 10^4. Reconstruction means building a shortest
 * common supersequence of the sequences in seqs (i.e., a shortest sequence so
 * that all sequences in seqs are subsequences of it). Determine whether there
 * is only one sequence that can be reconstructed from seqs and it is the org
 * sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: org = [1,2,3], seqs = [[1,2],[1,3]]
 * Output: false
 * Explanation: [1,2,3] is not the only one sequence that can be reconstructed,
 * because [1,3,2] is also a valid sequence that can be reconstructed.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: org = [1,2,3], seqs = [[1,2]]
 * Output: false
 * Explanation: The reconstructed sequence can only be [1,2].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
 * Output: true
 * Explanation: The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct
 * the original sequence [1,2,3].
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * org is a permutation of {1,2,...,n}.
 * 1 <= segs[i].length <= 10^5
 * seqs[i][j] fits in a 32-bit signed integer.
 * 
 * 
 * 
 * 
 * UPDATE (2017/1/8):
 * The seqs parameter had been changed to a list of list of strings (instead of
 * a 2d array of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */

// @lc code=start
class Solution
{
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs)
    {
        int num = 0;
        int min_num = 0;
        for (int i = 0; i < seqs.size(); i++)
        {
            for (int j = 0; j < seqs[i].size(); j++)
            {
                num = max(num, seqs[i][j]);
                min_num = min(min_num, seqs[i][j]);
            }
        }
        if (num > 10000 || min_num < 0)
            return false;

        if (num > org.size())
            return false;

        vector<vector<int>> g(num + 1);
        vector<int> indeg(num + 1, 0);

        for (int i = 0; i < seqs.size(); i++)
        {
            for (int j = seqs[i].size() - 1; j > 0; j--)
            {
                g[seqs[i][j - 1]].push_back(seqs[i][j]);
                indeg[seqs[i][j]]++;
            }
        }

        queue<int> q;

        for (int i = 1; i < indeg.size(); i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }

        if (q.size() > 1)
            return false;
        vector<int> res;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            res.push_back(n);
            for (int i = 0; i < g[n].size(); i++)
            {
                indeg[g[n][i]]--;

                if (indeg[g[n][i]] == 0)
                    q.push(g[n][i]);
            }
            if (q.size() > 1)
                return false;
        }

        if (res.size() != org.size())
            return false;

        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] != org[i])
                return false;
        }

        return true;
    }
};
// @lc code=end
