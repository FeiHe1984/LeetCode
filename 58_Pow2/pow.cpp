class Solution {
public:
	double pow(double x, int n) {
		if (n == 0 || x == 1) return 1;
		if (n == 1) return x;
		if (n < 0) return 1 / (x * pow(x, -(n + 1)));
		double res = 1;
		while (n > 1){
			if (n % 2 == 1) res *= x;
			x = x * x;
			n /= 2;
		}
		res *= x;
		return res;
	}
};