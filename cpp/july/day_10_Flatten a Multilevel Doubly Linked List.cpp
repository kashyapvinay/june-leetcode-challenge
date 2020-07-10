/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flatten(Node* head) {
        Node *ptr = head;
        while(ptr){
            if(ptr->child){
                Node* next = ptr->next;
                ptr->next = ptr->child;
                ptr->child = NULL;
                ptr->next->prev = ptr;
                Node *ptr1 = ptr->next;
                while(ptr1->next){
                    ptr1 = ptr1->next;
                }
                ptr1->next = next;
                if(next){
                    next->prev = ptr1;
                }
            }
            ptr = ptr->next;
        }        
        return head;
    }
};
