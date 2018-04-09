class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.empty()) return 0;
		int minPrice = prices[0];
		int profit = 0;
		for (int price : prices){
			minPrice = min(price, minPrice);
			profit = max(profit, price - minPrice);
		}
		return profit;

	}
};