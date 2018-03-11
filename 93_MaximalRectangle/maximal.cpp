class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> heights(col, 0);
		int areaMax = 0;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (matrix[i][j] == '1'){
					heights[j]++;
				}
				else{
					heights[j] = 0;
				}
			}
			int area = largestRectangleArea(heights);
			areaMax = max(areaMax, area);
		}
		return areaMax;
	}

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