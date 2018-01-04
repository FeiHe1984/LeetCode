class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		if (num.size() == 0) return target;

		sort(num.begin(), num.end());

		int delta = num[0] + num[1] + num[2] - target;
		for (int i = 0; i < num.size() - 2; i++){
			int start = i + 1;
			int end = num.size() - 1;
			while (start < end){
				int newdelta = num[i] + num[start] + num[end] - target;
				if (newdelta == 0) return target;
				if (abs(delta) > abs(newdelta))
					delta = newdelta;
				if (newdelta < 0) start++;
				else end--;
			}
		}
		return target + delta;
	}
};