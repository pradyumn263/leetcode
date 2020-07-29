/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)

    {

        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int> &nums, int k)
    {
        int res = 0, i = 0, j = 0, countOdd = 0;
        unordered_map<int, int> mp;

        while (i < nums.size())
        {
            if (nums[i] % 2)
            {
                countOdd++;
            }
            mp[nums[i]]++;

            while (countOdd > k)
            {
                mp[nums[j]]--;
                if (nums[j] % 2)
                {
                    countOdd--;
                }
                j++;
            }
            int narrays = i - j + 1;
            res += narrays;
            i++;
        }

        return res;
    }
};
// @lc code=end
