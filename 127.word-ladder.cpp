/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (29.02%)
 * Likes:    3281
 * Dislikes: 1187
 * Total Accepted:    437.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
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
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
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
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *  *  *  *  *  */

//         @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (beginWord.size() != endWord.size())
            return 0;

        unordered_map<string, int> mp;
        int wordLen = 0;
        for (int i = 0; i < wordList.size(); i++)
        {
            wordLen = wordList[i].size();
            mp[wordList[i]] = 1;
        }

        if (wordLen != beginWord.size())
            return 0;

        int distance = 0;

        queue<string> q;
        unordered_set<string> st;

        for (int i = 0; i < beginWord.size(); i++)
        {
            char ch = beginWord[i];
            for (int j = 0; j < 26; j++)
            {
                beginWord[i] = 'a' + j;
                if (mp.find(beginWord) != mp.end() && st.find(beginWord) == st.end())
                {
                    q.push(beginWord);
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
                    for (int j = 0; j < 26; j++)
                    {
                        curr[i] = 'a' + j;
                        if (mp.find(curr) != mp.end() && st.find(curr) == st.end())
                        {
                            q.push(curr);
                        }
                    }
                    curr[i] = ch;
                }
            }
            if (!found)
                len++;
        }

        if (found)
            return len + 1;

        return 0;
    }
};
// @lc code=end
