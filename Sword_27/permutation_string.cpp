class Solution {
public:
	vector<string> vs;

	vector<string> Permutation(string str) {
		if (str.empty()) return vs;
		Permutatio(str, 0);
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		return vs;
	}

	void Permutatio(string A, int i){
		if (A.length() == i)
			vs.push_back(A);
		else{
			for (int j = i; j<A.length(); ++j){
				swap(A[j], A[i]);
				Permutatio(A, i + 1);
				swap(A[j], A[i]);
			}
		}
	}

};