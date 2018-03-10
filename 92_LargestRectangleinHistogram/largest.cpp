class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		height.push_back(0);
		int length = height.size();
		stack<int> stack;

		int max = 0;
		int i = 0;

		while (i<length){
			if (stack.empty() || height[stack.top()] < height[i]){
				stack.push(i++);
			}
			else{
				int index = stack.top();
				stack.pop();
				int area = height[index] * (stack.empty() ? i : i - stack.top() - 1);
				if (area>max)
					max = area;
			}
		}
		return max;
	}

};