class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> curSeq;
		if (n <= 0 || k <= 0) return res;
		combineHelper(n, k, 1, res, curSeq);
		return res;
	}

	void combineHelper(int n, int k, int st_num, vector<vector<int>>& res, vector<int> curSeq){
		if (k == 0){
			res.push_back(curSeq);
			return;
		}
		else{
			for (int i = st_num; i <= n; i++){
				curSeq.push_back(i);
				combineHelper(n, k - 1, i + 1, res, curSeq);
				curSeq.pop_back();
			}
		}
	}
};