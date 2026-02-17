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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)
            return list1;
        if(list1 == nullptr)return list2;
        if(list2 == nullptr) return list1;
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *sortedHead;
        ListNode * tail = nullptr;
        while(head1 != nullptr  && head2 != nullptr){
            if(head1->val <= head2->val){
                if(tail == nullptr){
                    sortedHead = head1;
                    tail = sortedHead;
                }else{
                    tail->next = head1;
                    tail = head1;
                }
                head1 = head1->next;
            }
            else {  
                 if(tail == nullptr){
                    sortedHead = head2;
                    tail = sortedHead;
                }
                else{
                    tail->next = head2;
                    tail = head2;
                }
                head2 = head2->next;
            }
        }
        while(head1 != nullptr) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        while(head2 != nullptr){
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }

        return sortedHead;
    }
};