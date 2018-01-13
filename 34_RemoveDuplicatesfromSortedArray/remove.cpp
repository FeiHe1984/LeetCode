class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0)
		{
			return 0;
		}
		int slow = 1;

		for (int fast = 1; fast < n; fast++){
			if (A[fast - 1] != A[fast])
				A[slow++] = A[fast];
		}
		return slow;
	}
};