class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > res;
		if (num.size() == 0) return res;
		vector<int> temp;
		vector<bool> used(num.size(), false);
		permute_helper(num, used, temp, res);
		return res;
	}
private:
	void permute_helper(vector<int> &num, vector<bool> used, vector<int>temp, vector<vector<int>>& res){
		if (temp.size() == num.size()){
			res.push_back(temp);
			return;
		}

		for (int i = 0; i < num.size(); i++){
			if (!used[i]){
				temp.push_back(num[i]);
				used[i] = true;
				permute_helper(num, used, temp, res);
				temp.erase(temp.end() - 1);
				used[i] = false;

			}
		}
		return;
	}
};