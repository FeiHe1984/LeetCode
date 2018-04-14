class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> Q;
		Q.push(start);
		int res = 1;
		while (!Q.empty()){
			int qsize = Q.size();
			while (qsize--){
				string cur_front = Q.front();
				Q.pop();
				int size = cur_front.size();
				for (int i = 0; i < size; i++){
					char ch = cur_front[i];
					for (int j = 0; j < 26; j++){
						cur_front[i] = 'a' + j;
						if (cur_front == end) return res + 1;
						if (dict.find(cur_front) != dict.end()){
							Q.push(cur_front);
							dict.erase(cur_front);
						}
					}
					cur_front[i] = ch;
				}
			}
			res++;
		}
		return 0;
	}
};