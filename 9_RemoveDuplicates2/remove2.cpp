#include<iostream>
#include<cstdio>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* ptr = new ListNode(0);
        ptr->next = head;

        ListNode* lead = ptr;
        int cur = 0;

        while(ptr->next != NULL && ptr->next->next != NULL){
            if(ptr->next->val == ptr->next->next->val){
                cur = ptr->next->val;
                ptr->next->next = ptr->next->next->next;
            }
            else{
                if(ptr->next->val == cur){
                    ptr->next = ptr->next->next;
                }else{
                    ptr = ptr->next;
                }

            }
        }
        if(ptr->next != NULL && ptr->next->val == cur){
            ptr->next = NULL;
        }
        return lead->next;
    }
};
