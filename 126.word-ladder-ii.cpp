/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (21.74%)
 * Likes:    1815
 * Dislikes: 250
 * Total Accepted:    188.1K
 * Total Submissions: 850.6K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;
    int numNodes;

    void helper(vector<set<int>> &g, unordered_map<int, string> &revmp, int curr, int end, vector<string> &currset, int depth)
    {
        if (curr == end)
        {
            currset.push_back(revmp[curr]);
            res.push_back(currset);
            return;
        }

        if (depth == 0)
            return;

        currset.push_back(revmp[curr]);

        for (int it : g[curr])
        {
            helper(g, revmp, it, end, currset, depth - 1);
        }
        currset.pop_back();
    }

    void dfs(vector<set<int>> &g, unordered_map<int, string> &revmp, int start, int end, int length)
    {
        vector<string> currset;
        currset.push_back(revmp[start]);
        helper(g, revmp, start, end, currset, length);
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        if (beginWord.size() != endWord.size())
            return {};

        unordered_map<string, int> mp;
        unordered_map<int, string> revmp;
        int wordLen = 0;
        int node = 0;
        for (int i = 0; i < wordList.size(); i++)
        {
            wordLen = wordList[i].size();
            mp[wordList[i]] = node;
            revmp[node] = wordList[i];
            node++;
        }

        if (wordLen != beginWord.size())
            return {};

        int distance = 0;
        numNodes = node;
        queue<string> q;
        unordered_set<string> st;
        vector<set<int>> g(node);
        vector<string> currset;

        for (int i = 0; i < beginWord.size(); i++)
        {
            char ch = beginWord[i];
            int id = mp[beginWord];
            cout << beginWord << " " << id << " " << revmp[id] << " " << endl;
            for (int j = 0; j < 26; j++)
            {
                beginWord[i] = 'a' + j;
                if (mp.find(beginWord) != mp.end() && st.find(beginWord) == st.end())
                {

                    q.push(beginWord);
                    g[id].insert(mp[beginWord]);
                }
            }
            beginWord[i] = ch;
        }

        bool found = false;
        int len = 1;

        while (!q.empty() && !found)
        {
            int k = q.size();

            while (k--)
            {
                string curr = q.front();
                q.pop();
                if (st.find(curr) != st.end())
                {
                    continue;
                }
                st.insert(curr);

                if (curr == endWord)
                {
                    found = true;
                    break;
                }

                for (int i = 0; i < curr.size(); i++)
                {
                    char ch = curr[i];
                    int id = mp[curr];
                    for (int j = 0; j < 26; j++)
                    {
                        curr[i] = 'a' + j;
                        if (mp.find(curr) != mp.end() && st.find(curr) == st.end())
                        {

                            q.push(curr);
                            g[id].insert(mp[curr]);
                        }
                    }
                    curr[i] = ch;
                }
            }
            if (!found)
                len++;
        }
        if (!found)
            return {};

        dfs(g, revmp, mp[beginWord], mp[endWord], len);
        return res;
    }
};
// @lc code=end
