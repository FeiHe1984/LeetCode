/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		map<RandomListNode*, RandomListNode*> nodeMap;
		nodeMap.insert(pair<RandomListNode*, RandomListNode*>(NULL, NULL));
		RandomListNode* cur = head;
		while (cur != NULL){
			nodeMap.insert(pair<RandomListNode*, RandomListNode*>(cur, new RandomListNode(cur->label)));
			cur = cur->next;
		}
		cur = head;
		while (cur != NULL){
			nodeMap.find(cur)->second->next = nodeMap.find(cur->next)->second;
			nodeMap.find(cur)->second->random = nodeMap.find(cur->random)->second;
			cur = cur->next;
		}
		return nodeMap.find(head)->second;

	}
};