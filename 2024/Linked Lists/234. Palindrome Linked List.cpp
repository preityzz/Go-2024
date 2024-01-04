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
        ListNode *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {

            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *forward = nullptr;

        while (curr != nullptr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {

        if (head->next == nullptr)
            return true;

        ListNode *middle = getmiddle(head);

        ListNode *temp = middle->next;
        middle->next = reverse(temp);

        ListNode *head1 = head;
        ListNode *head2 = middle->next;

        while (head2 != nullptr)
        {
            if (head2->val != head1->val)
                return false;

            head1 = head1->next;
            head2 = head2->next;
        }
        //  temp=middle->next;
        // middle->next = reverse(temp);

        return true;
    }
};