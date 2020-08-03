/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 *
 * https://leetcode.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (54.12%)
 * Likes:    650
 * Dislikes: 1954
 * Total Accepted:    128.7K
 * Total Submissions: 236.7K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]'
 *
 * You have an array of logs.  Each log is a space delimited string of words.
 * 
 * For each log, the first word in each log is an alphanumeric identifier.
 * Then, either:
 * 
 * 
 * Each word after the identifier will consist only of lowercase letters,
 * or;
 * Each word after the identifier will consist only of digits.
 * 
 * 
 * We will call these two varieties of logs letter-logs and digit-logs.  It is
 * guaranteed that each log has at least one word after its identifier.
 * 
 * Reorder the logs so that all of the letter-logs come before any digit-log.
 * The letter-logs are ordered lexicographically ignoring identifier, with the
 * identifier used in case of ties.  The digit-logs should be put in their
 * original order.
 * 
 * Return the final order of the logs.
 * 
 * 
 * Example 1:
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
 * dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5
 * 1","dig2 3 6"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the
 * identifier.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        //Letter logs before digit logs.
        //Digit logs in their original order

        //For same letter logs, identifiers are used.

        vector<pair<string, int>> nums;

        for (int i = 0; i < logs.size(); i++)
        {
            nums.push_back({logs[i], i});
        }

        auto comp = [](pair<string, int> &a, pair<string, int> &b) {
            string identifierA;
            string identifierB;

            int i = 0;
            for (i = 0; i < a.first.size(); i++)
            {
                if (a.first[i] == ' ')
                    break;
            }

            identifierA = a.first.substr(0, i);
            i = 0;
            for (i = 0; i < b.first.size(); i++)
            {
                if (b.first[i] == ' ')
                    break;
            }

            identifierB = b.first.substr(0, i);
            int aStart = identifierA.size();
            int bStart = identifierB.size();

            char a1 = a.first[aStart + 1];
            char b1 = b.first[bStart + 1];

            if (a1 >= '0' && a1 <= '9' && b1 >= '0' && b1 <= '9')
                return a.second < b.second;

            if (a1 >= '0' && a1 <= '9')
                return false;

            if (b1 >= '0' && b1 <= '9')
                return true;

            if (a.first.substr(aStart) == b.first.substr(bStart))
                return identifierA < identifierB;

            return a.first.substr(aStart) < b.first.substr(bStart);
        };

        sort(nums.begin(), nums.end(), comp);
        for (int i = 0; i < nums.size(); i++)
        {
            logs[i] = nums[i].first;
        }
        return logs;
    }
};
// @lc code=end
