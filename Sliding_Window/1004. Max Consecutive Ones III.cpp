class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int right = 0 ;
       int left = 0;
       int countZero = 0;
       int maxWindow = 0;
       for(right ; right < nums.size() ; right++) {
            if(nums[right] == 0)
                countZero += 1;
            while( countZero > k) {
                if(nums[left] == 0) 
                    countZero--;
                left++;
            }
            maxWindow = max(maxWindow , right - left + 1);
       }
       return maxWindow;
    }
};
/*
I move and save my progress about the earlier winodw by riht - left + 1 , also moving and taking one from right and down from left element in case i reached to a maximum flips
such that i make left++ because i am already save the old record and the element before me it is useless  it's guranteed that i have to reach a point to construct a new valid window so we go left++ even it 0 or 1.
*/
