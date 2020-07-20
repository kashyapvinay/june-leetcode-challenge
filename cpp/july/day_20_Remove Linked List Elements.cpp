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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        ListNode *p1, *p2;
        dummy->next = head;
        p2 = head;
        p1 = dummy;
        while(p2){
            if(p2->val == val){
                p1->next = p2->next;
                p2 = p2->next;
            }else{
                p1 = p2;
                p2 = p2->next;
            }
        }
        return dummy->next;
    }
};
