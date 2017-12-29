class Solution {
public:
	int maxArea(vector<int> &height) {
		int n = height.size();
		if (n <= 1) return 0;
		int left = 0, right = n - 1;
		int area = 0;

		while (left < right){
			area = max(area, (right - left) * min(height[left], height[right]));
			if (height[left] > height[right]) right--;
			else if (height[left] < height[right]) left++;
			else{
				left++;
				right--;
			}
		}
		return area;
	}
};