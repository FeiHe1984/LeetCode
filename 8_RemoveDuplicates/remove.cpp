#include<iostream>
#include<cstdio>
using namespace std;

Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution{
public:
    ListNode* deleteDuplicates(List* head){
        if(head == NULL){
            return NULL;
        }

        ListNode* ptr = head;
        while(ptr != NULL && ptr->next != NULL){
            if(ptr->val == ptr->next->val){
                ptr->next = ptr->next->next
            }
            else{
                ptr = ptr->next
            }
        }
        return head;
    }
};
