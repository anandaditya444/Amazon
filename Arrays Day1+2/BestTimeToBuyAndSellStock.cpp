Q. 121

class Solution {
public:
	int maxProfit(vector<int>&prices) {
		if (prices.size() == 0)
			return 0;
		int min_price = 1e9, profit = -1e9;
		for (int i = 0; i < prices.size(); i++)
		{
			min_price = min(min_price, prices[i]);
			profit = max(profit, prices[i] - min_price);
			//cout<<profit<<endl;
		}
		return profit;
	}
};