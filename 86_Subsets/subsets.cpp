class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int>> allSets;
		sort(S.begin(), S.end());
		unsigned long long maxNum = pow(2, S.size()) - 1;
		for (unsigned long long i = 0; i <= maxNum; i++)
			allSets.push_back(num2subset(S, i));

		int setSize[allSets.size()];
		int max = 0;
		for (int i = 0; i < allSets.size(); i++){
			setSize[i] = allSets[i].size();
			if (max < allSets[i].size()){
				max = allSets[i].size();
			}
		}
		sort(allSets.begin(), allSets.end());
		vector<vector<int>> res;
		for (int i = 0; i <= max; i++){
			for (int j = 0; j < allSets.size(); j++){
				if (i == allSets[j].size()) res.push_back(allSets[j]);
			}
		}

		return res;
	}

	vector<int> num2subset(vector<int> &S, unsigned long long num) {
		vector<int> sol;
		int i = 0;
		while (num) {
			if (num & 1) sol.push_back(S[i]);
			num >>= 1;
			i++;
		}
		return sol;
	}

};