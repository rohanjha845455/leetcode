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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;
        while(temp1 != NULL || temp2 != NULL){
            int data1 = temp1 != NULL ? temp1->val : 0;
            int data2 = temp2 != NULL ? temp2->val : 0;
            int sum = data1 + data2 + carry;
            carry = sum/10;
            int val = sum%10;
            ListNode* newNode = new ListNode(val);
            ptr->next = newNode;
            ptr = ptr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;

        }
        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            ptr->next = newNode;
        }
        return dummy->next;
    }
};