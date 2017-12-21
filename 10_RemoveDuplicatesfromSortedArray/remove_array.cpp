#include<isotream>
#include<cstdio>
using namespace std;

class Solution{
public:
    int removeDuplicated(int A[], int n){
        if(n==0){
            return 0;
        }

        int slow = 0;
        int fast = 1;

        while(fast < n){
            if(A[slow] != A[fast]){
                A[++slow] = A[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};
