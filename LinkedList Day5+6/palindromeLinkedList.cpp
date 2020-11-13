
Time - O(n)
Space - O(1)

Reverse second half of the linked list and then check for palindrome

class Solution {
public:
    ListNode* reverse(ListNode* head)
        {
            ListNode* cur = head;
            ListNode* prev = NULL;

            while (cur != NULL)
            {
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            return prev;
        }

        bool isPalindrome(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while (slow && fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            //cout<<slow->val<<endl;
            ListNode* ptr = reverse(slow);
            // cout<<ptr->val<<endl;
            while (ptr != NULL)
            {
                if (ptr->val != head->val)
                    return false;
                ptr = ptr->next;
                head = head->next;
            }
            return true;
        }
    };