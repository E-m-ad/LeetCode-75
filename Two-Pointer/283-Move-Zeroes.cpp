class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int writePtr = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i])
                nums[writePtr++] = nums[i];
        }
            while(writePtr < n){
                nums[writePtr++] = 0;
            }
    }
};