class Solution {
public:
	int rectCover(int number) {
		if (number < 1) return 0;
		int g = 1, f = 2;
		while (--number) {
			f = f + g;
			g = f - g;
		}
		return g;
	}
};