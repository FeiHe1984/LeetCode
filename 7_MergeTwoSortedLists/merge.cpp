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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;

        while(l1 != NULL || l2 != NULL){
            ListNode* cur = NULL;
            if(l1 == NULL){
                cur = l2;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                cur = l1;
                l1 = l1->next;
            }
            else{
                if(l1->val < l2->val){
                    cur = l1;
                    l1 = l1->next;
                }else{

                    cur = l2;
                    l2 = l2->next;
                }

            }
            ptr->next = cur;
            ptr = ptr->next;
        }
        return head->next;
    }
};
