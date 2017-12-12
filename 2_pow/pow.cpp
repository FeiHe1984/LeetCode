#include<iostream>
#include<cstdio>
using namespace std;

class Solution{
public:
    double pow(double x, int n){
        if(n==0){
            return 1;
        }

        else if(n < 0){
            x = 1 / x;
            n = -1 * n;
        }

        double result = 1;

        while(n > 0){
            if(n % 2 == 1){
                result *= x;
            }
            n /= 2;
            x *=x;
        }
        return result;
    }
};


int main(){
    Solution sol;
    double x = 4;
    int n = 2;
    double result = sol.pow(x,n);
    cout << result << endl;
    return 0;
}
