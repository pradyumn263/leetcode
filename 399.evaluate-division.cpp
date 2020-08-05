/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (51.03%)
 * Likes:    2325
 * Dislikes: 180
 * Total Accepted:    131.7K
 * Total Submissions: 255.4K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * According to the example above:
 * 
 * 
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<pair<int, double>>> &g, int curr, double &res, bool &found, vector<bool> &visited, int start, int end, double currset)
    {
        if (curr == end)
        {
            found = true;
            res = currset;
            return;
        }
        visited[curr] = true;
        for (int i = 0; i < g[curr].size(); i++)
        {
            if (!visited[g[curr][i].first])
            {
                dfs(g, g[curr][i].first, res, found, visited, start, end, currset * g[curr][i].second);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, int> mp;
        int node = 0;

        for (int i = 0; i < equations.size(); i++)
        {
            for (int j = 0; j < equations[i].size(); j++)
            {
                if (mp.find(equations[i][j]) == mp.end())
                {
                    mp[equations[i][j]] = node;
                    node++;
                }
            }
        }

        vector<vector<pair<int, double>>> g(node);

        for (int i = 0; i < equations.size(); i++)
        {
            g[mp[equations[i][0]]].push_back({mp[equations[i][1]], values[i]});
            g[mp[equations[i][1]]].push_back({mp[equations[i][0]], 1 / values[i]});
        }
        vector<double> op;
        for (int i = 0; i < queries.size(); i++)
        {
            vector<bool> visited(node, false);
            double res = -1;
            bool found = false;
            if (mp.find(queries[i][0]) == mp.end() || mp.find(queries[i][1]) == mp.end())
            {
                op.push_back(-1);
                continue;
            }
            dfs(g, mp[queries[i][0]], res, found, visited, mp[queries[i][0]], mp[queries[i][1]], 1.0);
            if (found)
                op.push_back(res);
            else
            {
                op.push_back(-1);
            }
        }
        return op;
    }
};
// @lc code=end
