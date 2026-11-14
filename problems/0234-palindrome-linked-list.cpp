// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
// Difficulty: Easy

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
    bool isPalindrome(ListNode* head) {
        /*
        send a fast + slow
        while reversing the first half
        then compare
        O(N) time + O(1) space
        */

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next; // need to do this first b4 slow

            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        if (fast) {
            slow = slow->next;
        }

        while (slow && prev) {
            if (slow->val != prev->val) {
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};