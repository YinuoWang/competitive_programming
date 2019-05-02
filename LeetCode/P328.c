#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

struct ListNode* oddEvenList(struct ListNode* head) {
    
    node *oddCur = head;
    node *evenCur = head ? (head->next) : NULL;
    node *startingEven = evenCur;
    
    while(oddCur && evenCur){
        oddCur -> next = evenCur ? evenCur -> next : NULL;
        evenCur -> next = (oddCur -> next) ? (oddCur->next)->next : NULL;
        if (!oddCur->next){
            oddCur->next = startingEven;
        }
        else{
            oddCur = oddCur -> next;
        }
        evenCur = evenCur -> next;
    }
    if (oddCur){
        oddCur->next = startingEven;
    }

    return head;
}