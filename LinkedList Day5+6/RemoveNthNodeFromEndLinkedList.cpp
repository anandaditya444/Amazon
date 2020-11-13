
Time - O(n) i.e. 2 Pass Algorithm

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int len = 0;
        while (ptr != NULL)
        {
            len++;
            ptr = ptr->next;
        }
        int moves = len - n;
        ListNode* cur = head;
        ListNode* prev = NULL;
        if (moves == 0)
        {
            return head->next;
        }
        while (cur != NULL && moves)
        {
            prev = cur;
            cur = cur->next;
            moves--;
        }
        prev->next = cur->next;
        return head;
    }
};