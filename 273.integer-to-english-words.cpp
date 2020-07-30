/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (26.75%)
 * Likes:    1062
 * Dislikes: 2805
 * Total Accepted:    178K
 * Total Submissions: 660K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 2^31 - 1.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * 
 * Example 3:
 * 
 * 
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<pair<string, int>> mp;

    Solution()
    {
        mp = {
            {"Billion", 1000000000},
            {"Million", 1000000},
            {"Thousand", 1000},
            {"Hundred", 100},
            {"Ninety", 90},
            {"Eighty", 80},
            {"Seventy", 70},
            {"Sixty", 60},
            {"Fifty", 50},
            {"Forty", 40},
            {"Thirty", 30},
            {"Twenty", 20},
            {"Nineteen", 19},
            {"Eighteen", 18},
            {"Seventeen", 17},
            {"Sixteen", 16},
            {"Fifteen", 15},
            {"Fourteen", 14},
            {"Thirteen", 13},
            {"Twelve", 12},
            {"Eleven", 11},
            {"Ten", 10},
            {"Nine", 9},
            {"Eight", 8},
            {"Seven", 7},
            {"Six", 6},
            {"Five", 5},
            {"Four", 4},
            {"Three", 3},
            {"Two", 2},
            {"One", 1}};
    }

    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        for (int i = 0; i < mp.size(); i++)
        {
            if (num / mp[i].second)
            {
                return (
                    (num >= 100 ? (numberToWords(num / mp[i].second) + " ") : "") +
                    mp[i].first +
                    (((num % mp[i].second == 0) ? "" : (" " + numberToWords(num % mp[i].second)))));
            }
        }
        return "";
    }
};
// @lc code=end
