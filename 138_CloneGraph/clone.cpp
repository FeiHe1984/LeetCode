/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/
class Solution {

public:
	std::map<UndirectedGraphNode *, UndirectedGraphNode *> m;
	std::map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator iter;
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return node;
		return cloneGraphHelp(node);
	}
	UndirectedGraphNode *cloneGraphHelp(UndirectedGraphNode *node){
		iter = m.end();
		iter = m.find(node);
		if (iter != m.end()) return iter->second;//已经创建的结点直接在map中查找
		UndirectedGraphNode *p;
		p = new UndirectedGraphNode(node->label);
		m.insert(std::pair<UndirectedGraphNode *, UndirectedGraphNode *>(node, p));
		for (int i = 0; i < node->neighbors.size(); i++)
			p->neighbors.push_back(cloneGraphHelp(node->neighbors[i]));
		return p;
	}
};