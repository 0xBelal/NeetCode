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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = siz(head);
        ListNode* p = getPerant(head,n,size);

        if(p == NULL ){
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }else{
            ListNode* node = p->next;
            p->next = node->next;
            delete node;
            return head;
        }

        return NULL;

    }
    ListNode* getPerant(ListNode* head, int n,int sz){

        int  i = sz - n;

        if(i == 0) return NULL;

        ListNode* temp = head;

        while(--i){
            temp = temp->next;
        }
        return temp;
    }
    int siz(ListNode* head){
        int counter=1;

        ListNode* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
            counter++;
        }
        return counter;
    }

};