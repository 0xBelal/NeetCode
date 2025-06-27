//
// Created by Belal on 27-Jun-25.
//

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

        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL && l2 != NULL) return l2;
        if(l1 != NULL && l2 == NULL) return l1;

        ListNode* head1 = l1,*head2 = l2;
        ListNode* temp = new ListNode();
        ListNode* new_head = temp;


        int sum =0,carr=0,digit = 0;

        while(head1 != NULL && head2 != NULL) {

            sum = head1->val + head2->val + carr;

            if(sum >= 10){
                digit = sum % 10;
                carr = sum/10;
            }else{
                carr = 0;
                digit = sum;
            }

            ListNode* node = new ListNode(digit);
            temp->next = node;

            temp = temp->next;

            head1 = head1->next;
            head2 = head2->next;

        }


        while(head1 != NULL){

            sum = head1->val + carr;
            carr = sum / 10;

            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;

            head1 = head1->next;

        }

        while(head2 != NULL){
            sum = head2->val + carr;
            carr = sum / 10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;

            temp = temp->next;
            head2 = head2->next;
        }

        if(carr != 0){
            ListNode* node = new ListNode(carr);
            temp->next = node;
        }

        return new_head->next;
    }
};