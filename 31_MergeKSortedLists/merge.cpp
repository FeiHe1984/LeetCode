/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//For adding operator < and >; So that we can form priority_queue  
struct AdaptNode{
	int val;
	ListNode *cur;
	AdaptNode(ListNode *node) :cur(node)
	{
		if (node == NULL)
			val = INT_MAX;
		else
		{
			val = node->val;
		}
	}

	bool operator<(const AdaptNode& an)const
	{
		return val<an.val;
	}
	bool operator>(const AdaptNode& an)const
	{
		return val>an.val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {

		if (lists.empty()) return NULL;

		priority_queue<AdaptNode, vector<AdaptNode>, greater<AdaptNode> > pq(lists.begin(), lists.end());

		ListNode head(0);
		ListNode *cura, *small;
		cura = &head;
		small = pq.top().cur;

		while (pq.top().val != INT_MAX)
		{
			//nextNode = small->next;  
			cura->next = small;
			cura = cura->next;
			//small->next = NULL;  
			pq.pop();
			pq.push(AdaptNode(small->next));
			small = pq.top().cur;
		}
		return head.next;
	}
};