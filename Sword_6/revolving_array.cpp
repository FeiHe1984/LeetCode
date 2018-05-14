class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		size_t len = rotateArray.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return rotateArray[0];
		vector<int>::iterator low = rotateArray.begin();
		vector<int>::iterator mid;
		vector<int>::iterator high = rotateArray.end() - 1;
		while (low <= high)
		{
			//·ÀÖ¹µü´úÆ÷Ê§Ð§
			mid = low + (high - low) / 2;
			if (*mid >*high)
			{
				low = mid + 1;
			}
			else if (*mid < *high)
			{
				high = mid;
			}
			else
			{
				high = high - 1;
			}
			if (low >= high)
			{
				break;
			}
		}
		return *low;

	}
};