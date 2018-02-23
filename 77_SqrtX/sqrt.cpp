class Solution {
public:
	int sqrt(int x) {
		if (x <= 0) return 0;

		int curr = 0;
		int res = 0;
		int add = 1;
		while (curr <= x){
			if (INT_MAX - curr < add) return res;
			curr += add;
			res++;
			add += 2;
		}
		return res - 1;

	}
};