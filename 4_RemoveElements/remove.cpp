#include<iostream>
#include<cstdio>
using namespace std;

class Solution{
public:
    int removeElement(int A[], int n, int elem){
        int start = 0;
        int end = n-1;

        while(start <= end)
        {
            if(A[start]==elem)
            {
                swap(A, start, end);
                end--;
            }
            else
            {
                start++;
            }
        }
        return start;
    }

    void swap(int A[], int i, int j){
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

};
