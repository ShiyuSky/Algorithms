/* Detect cycle in singly-linked list using Floyd Cycle Detection algorithm */

typedef struct ListNode ListNode;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(val): val(val), next(NULL) {}
};


bool hasCycle(ListNode* head) {
    if (head == NULL)   return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
