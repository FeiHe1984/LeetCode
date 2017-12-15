#include<iostream>
#include<cstdio>

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        vector<int> v;

        int next = 1;
        for(int i = digits.size() - 1; i>=0; i--){

            int tmp = digits[i] + next;
            v.push_back(tmp%10);
            next = tmp / 10;
        }

        if(next != 0)
        {
            v.push_back(next);
        }

        for(int i = 0; i < v.size() / 2; i++)
        {
            int t = v[i];
            v[i] = v[v.size() - 1 - i];
            v[v.size() - 1 - i] = t;
        }
        return v;
    }
};
