struct ListNode {
    int val;
    struct ListNode *next;
};
 

typedef struct ListNode* node;

node nonVal(node cur, int val){
    while(cur && cur->val == val){
        cur = cur->next;
    }
    return cur;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    node cur = nonVal(head,val);
    node returnNode = cur;
    while(cur){
        cur->next = nonVal(cur->next, val);
        cur = cur->next;
    }
    return returnNode;
}