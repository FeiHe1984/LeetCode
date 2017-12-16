#include<iostream>
#include<cstdio>
using namespace std;

class Solution{
public:
    string addBinary(string a, string b){
        stack<bool> s;

        int cur_a = a.size() - 1;
        int cur_b = b.size() - 1;

        int carry = 0;

        while(cur_a > -1 || cur_b > - 1){
            int val_a = 0;
            if(cur_a > -1){
                val_a = char2int(a[cur_a--])
            }

            int val_b = 0;
            if(cur_b > -1)
            {
                val_b = char2int(b[cur_b--]);
            }
            int tmp = val_a + val_b + carry;
            carry = tmp / 2;
            s.push((tmp % 2 ) == 1);
        }

        if(carry == 1){
            s.puth(true)
        }

        string result;
        while(!s.empty()){
            result.push_back(bool2char())
            s.pop();
        }
        return result;
    }

    int char2int(char c)
    {
        return c - '0';
    }

    char bool2char(bool b){
        if(b){
            return '1';
        }
        return '0';
    }
};
