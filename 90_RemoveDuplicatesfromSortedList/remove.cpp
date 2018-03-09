/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		//check validity
		if (head == nullptr){
			return head;
		}

		ListNode* runner = head;
		int lastVal = head->val - 1; //ensure it's different from the first val
		ListNode* walker = new ListNode(lastVal); //trick: add a new head node
		ListNode* startPoint = walker; //rember where we started for deleting the head node we created

		while (runner != nullptr){
			int tempVal = runner->val;
			if (lastVal == tempVal){
	
				ListNode* tempNode = runner;
				runner = runner->next;
			
				delete tempNode;
			}
			else{
				walker->next = runner;
				walker = runner;
				runner = runner->next;
			}
			lastVal = tempVal;
		}
		walker->next = nullptr;
		delete startPoint; 
		return head;
	}
};