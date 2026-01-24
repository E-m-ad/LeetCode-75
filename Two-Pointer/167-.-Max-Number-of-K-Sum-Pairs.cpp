class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
         unordered_map<int,int> mp;
        for(int num : nums) 
            mp[num] += 1;
        int numberOfOperations = 0 ;
        for(int num : nums) {
            if(num != k - num && mp.find(k - num) != mp.end()) {
                const int mn = min(mp[num] , mp[k-num]);
                numberOfOperations += mn;
                mp[num] -= mn;
                mp[k-num] -= mn;
            }else if( num == k-num) {
                numberOfOperations += mp[num] / 2;
                mp[num] = mp[num] % 2;
            }
        }
        return numberOfOperations;
    }
}; 
// This is optimized solution where we enhace the algorithm to pass single time and reduce some function complexity like find and some logic.
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int numberOfOperations = 0;
        
        for(int num : nums) {
            int complement = k - num;
            if(mp[complement] > 0) {
                numberOfOperations++;
                mp[complement]--;
            } else {
                mp[num]++;
            }
        }
        
        return numberOfOperations;
    }
};
// this is pretty simple and straight forward we utilize from that if i found a complement it guranted that it before me and it exist so i found a pair and make updates else this first pair make it as record.
