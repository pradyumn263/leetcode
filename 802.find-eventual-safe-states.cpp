/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 *
 * https://leetcode.com/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (48.41%)
 * Likes:    799
 * Dislikes: 150
 * Total Accepted:    39.8K
 * Total Submissions: 81.3K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * In a directed graph, we start at some node and every turn, walk along a
 * directed edge of the graph.  If we reach a node that is terminal (that is,
 * it has no outgoing directed edges), we stop.
 * 
 * Now, say our starting node is eventually safe if and only if we must
 * eventually walk to a terminal node.  More specifically, there exists a
 * natural number K so that for any choice of where to walk, we must have
 * stopped at a terminal node in less than K steps.
 * 
 * Which nodes are eventually safe?  Return them as an array in sorted order.
 * 
 * The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the
 * length of graph.  The graph is given in the following form: graph[i] is a
 * list of labels j such that (i, j) is a directed edge of the graph.
 * 
 * 
 * Example:
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * Here is a diagram of the above graph.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * graph will have length at most 10000.
 * The number of edges in the graph will not exceed 32000.
 * Each graph[i] will be a sorted list of different integers, chosen within the
 * range [0, graph.length - 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    unordered_set<int> white;
    unordered_set<int> gray;
    unordered_set<int> black;

    bool dfs(vector<vector<int>> &g, int curr) {
        if(white.find(curr) == white.end()) {
            return gray.find(curr) == gray.end();
        }

        white.erase(curr);
        gray.insert(curr);

        for(int neighbour : g[curr]) {
            if(!dfs(g, neighbour))
                return false;
        }

        gray.erase(curr);
        black.insert(curr);
        return true;
    } 

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            white.insert(i);
        }

        for(int i = 0; i < n; i++) {
            if(dfs(graph, i))
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

