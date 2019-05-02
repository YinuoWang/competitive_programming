/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(!l1){
        return l2;
    }
    else if (!l2){
        return l1;
    }
    
    node *cur1 = l1, *cur2 = l2, *prev = NULL, *newHead = NULL;
    while(cur1 && cur2){
        if (cur1->val < cur2->val){
            if (!newHead){
                newHead = cur1;
            }
            else{
                prev->next = cur1;
            }
            prev = cur1;
            cur1 = cur1->next;
        }
        else{
            if (!newHead){
                newHead = cur2;
            }
            else{
                prev->next = cur2;
            }
            prev = cur2;
            cur2 = cur2->next;
        }
    }
    if (!cur1){
        prev->next = cur2;
    }
    else{
        prev->next = cur1;
    }
    return newHead;
}