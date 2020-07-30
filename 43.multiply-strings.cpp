/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (33.54%)
 * Likes:    1769
 * Dislikes: 805
 * Total Accepted:    299.3K
 * Total Submissions: 885.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1.size() == 0 || num2.size() == 0)
            return 0;

        if (num1.size() == 1 && num1 == "0")
            return "0";

        if (num2.size() == 1 && num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        string res(m + n, '0');

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = (sum % 10) + '0';
                res[i + j] += sum / 10;
            }
        }

        int i = 0;
        while (i < res.size() && res[i] == '0')
            i++;

        if (i == res.size())
            return "0";

        return res.substr(i);
    }
};
// @lc code=end
