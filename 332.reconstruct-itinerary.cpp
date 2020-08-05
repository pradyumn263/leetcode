/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (35.07%)
 * Likes:    1939
 * Dislikes: 1001
 * Total Accepted:    163.9K
 * Total Submissions: 447.5K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 * 
 * Note:
 * 
 * 
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * One must use all the tickets once and only once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    list<int> res;
    vector<int> outdeg;
    vector<string> op;

    void dfs(vector<vector<int>> &g, int curr)
    {
        while (outdeg[curr] != 0)
        {
            dfs(g, g[curr][--outdeg[curr]]);
        }
        res.push_front(curr);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        int node = 0;
        unordered_map<string, int> mp;
        unordered_map<int, string> revmp;

        for (int i = 0; i < tickets.size(); i++)
        {
            for (int j = 0; j < tickets[i].size(); j++)
            {
                if (mp.find(tickets[i][j]) == mp.end())
                {
                    mp[tickets[i][j]] = node;
                    revmp[node] = tickets[i][j];
                    node++;
                }
            }
        }

        vector<vector<int>> g(node);
        outdeg.resize(node);

        for (int i = 0; i < tickets.size(); i++)
        {
            g[mp[tickets[i][0]]].push_back(mp[tickets[i][1]]);
            outdeg[mp[tickets[i][0]]]++;
        }

        auto comp = [&](int &a, int &b) {
            return revmp[a] > revmp[b];
        };

        for (int i = 0; i < g.size(); i++)
        {
            sort(g[i].begin(), g[i].end(), comp);
        }

        for (int i = 0; i < g.size(); i++)
        {
            cout << revmp[i] << " --> ";
            for (int j = 0; j < g[i].size(); j++)
            {
                cout << revmp[g[i][j]] << " ";
            }
            cout << endl;
        }

        dfs(g, mp["JFK"]);

        for (int i : res)
        {
            op.push_back(revmp[i]);
        }
        return op;
    }
};
// @lc code=end
