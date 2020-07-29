/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution
{
public:
    class Node
    {
    public:
        Node *next[26];
        vector<int> suffix;
        bool isWord;
        int index;

        Node()
        {
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }

            isWord = false;
            index = -1;
        }
    };

    Node *root;
    vector<vector<int>> res;

    void insert(string &s, int index)
    {
        Node *curr = root;
        int n = s.size();
        int i = n - 1;
        for (i = n - 1; i >= 0; i--)
        {
            if (!curr->next[s[i] - 'a'])
            {
                curr->next[s[i] - 'a'] = new Node();
            }

            if (isPal(s, 0, i))
            {
                curr->suffix.push_back(index);
            }

            curr = curr->next[s[i] - 'a'];
        }
        curr->suffix.push_back(index);
        curr->isWord = true;
        curr->index = index;
    }

    bool isPal(string &res, int i, int j)
    {
        while (i < j)
        {
            if (res[i] != res[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void checkPalindrome(vector<string> &words, string &s, int index)
    {
        int n = s.size();
        int i = 0;
        int j = 0;

        Node *curr = root;

        for (i = 0; i < n; i++)
        {

            if (curr->isWord && curr->index != index && isPal(s, i, n - 1))
            {
                res.push_back({index, curr->index});
            }

            curr = curr->next[s[i] - 'a'];
            if (!curr)
                return;
        }

        for (int j : curr->suffix)
        {
            if (index == j)
                continue;

            res.push_back({index, j});
        }
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new Node();
        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i], i);
        }

        for (int i = 0; i < words.size(); i++)
        {
            checkPalindrome(words, words[i], i);
        }
        return res;
    }
};
// @lc code=end
