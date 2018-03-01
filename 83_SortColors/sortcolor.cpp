class Solution {
public:
	void sortColors(int A[], int n) {
		if (A == NULL || n <= 1) return;
		int colFirst = 0;
		while (colFirst < n && A[colFirst] == 0) colFirst++;
		int colLast = n - 1;
		while (colLast >= 0 && A[colLast] == 2) colLast--;

		int index = colFirst;
		while (index <= colLast){
			if (A[index] == 1) index++;
			else if (A[index] == 0){
				switchColor(A, colFirst, index);
				colFirst++;
				index++;
			}
			else if (A[index] == 2){
				switchColor(A, colLast, index);
				colLast--;
			}
		}

	}
	void switchColor(int A[], int i, int j){
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
};