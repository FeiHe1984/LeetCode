class Solution {
public:
	int atoi(const char *str) {
		if (!str || !strlen(str))
			return 0;
		while (*str == ' ')
			++str;

		bool isPositive = true;
		if (*str == '-'){
			isPositive = false;
			++str;
		}
		else if (*str == '+'){
			++str;
		}

		long long int ans = 0;
		while (*str){
			if (*str < '0' || *str > '9')
				break;
			ans = ans * 10 + *str - '0';
			++str;
		}
		if (isPositive){
			if (ans > INT_MAX)
				return INT_MAX;
			return ans;
		}
		else{
			if (ans - 1 >= INT_MAX)
				return INT_MIN;
			else
				return -ans;
		}
	}
};