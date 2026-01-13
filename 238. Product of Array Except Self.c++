class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix(nums.size(), 1);
        vector<int> sufix(nums.size(), 1);
        prefix[0] = nums[0];
        sufix[nums.size() - 1] = nums[nums.size() - 1];
        int i = 1, j = nums.size() - 2;
        while (i < nums.size() && j >= 0)
        {
            prefix[i] = nums[i] * prefix[i - 1];
            sufix[j] = nums[j] * sufix[j + 1];
            i++, j--;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && i < nums.size() - 1)
                nums[i] = prefix[i - 1] * sufix[i + 1];
            if (i == 0)
                nums[i] = sufix[i + 1];
            if (i == nums.size() - 1)
                nums[i] = prefix[i - 1];
        }
        return nums;
    }
};
