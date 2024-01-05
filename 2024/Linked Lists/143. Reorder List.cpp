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
class Solution
{
public:
    ListNode *getmiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;

        while (curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
    void reorderList(ListNode *head)
    {
        ListNode *mid = getmiddle(head);
        ListNode *reversed = reverse(mid->next);
        mid->next = nullptr;

        while (head && reversed)
        {
            ListNode *h1 = head->next;
            ListNode *r1 = reversed->next;
            head->next = reversed;
            head->next->next = h1;
            head = h1;
            reversed = r1;
        }
    }
};