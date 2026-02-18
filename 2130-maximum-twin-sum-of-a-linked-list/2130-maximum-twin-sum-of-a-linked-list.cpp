/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
     int maxi =  0 ;
     unordered_map<int,int> mp;
     int n = 0 ;
     ListNode * curr = head;
     while(curr != nullptr) {
        mp[n] = curr->val;
        curr = curr->next;
        n += 1; 
     }  
     for(int j = 0 ; j < (n / 2) ; j++){
        int twin = (n - 1) - j;
        if(mp.find(twin) != mp.end())
            maxi = max(maxi , mp[j] + mp[twin]);
     }
     return maxi;
    }
};