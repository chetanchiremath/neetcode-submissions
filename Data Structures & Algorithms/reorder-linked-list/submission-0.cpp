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

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        head->next = nullptr;
        front->next = head;
        return newHead;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list2 = reverse(slow->next);
        slow->next = nullptr;

        ListNode* temp = head;
        while(list2 != nullptr) {
            ListNode* next = list2->next;
            list2->next = temp->next;
            temp->next = list2;
            list2 = next;
            temp = temp->next->next;
        }
    }
};
