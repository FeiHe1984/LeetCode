class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return false;
		return judge(sequence, 0, sequence.size() - 1);
	}
	bool judge(vector<int>& a, int l, int r){
		if (l >= r) return true;
		int i = r;
		while (i > l && a[i - 1] > a[r]) --i;
		for (int j = i - 1; j >= l; --j) if (a[j] > a[r]) return false;
		return judge(a, l, i - 1) && (judge(a, i, r - 1));
	}

};