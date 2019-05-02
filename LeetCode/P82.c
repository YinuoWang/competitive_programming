#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    node *newHead = NULL, *prev = NULL, *cur = head;
    while(cur){
        if (!cur->next || cur->val!=(cur->next)->val){
            if (!newHead){
                newHead = cur;
            }
            else{
                prev->next = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else{
            int val = cur->val;
            node *newCur = cur;
            while(newCur && newCur->val == val){
                newCur = newCur->next;
            }
            if (prev){
                prev->next = newCur;    
            }
            cur = newCur;
        }
    }
    return newHead;
}