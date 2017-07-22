#include<iostream>
#include<vector>
using namespace std;

//The O(N^2) simple algorithm
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, sum;
        vector<int> results;
        for(i=0; i<(nums.size()-1); i++){
            for(j=i+1; j<nums.size(); j++){
                sum = nums[i] + nums[j];
                if(sum==target){
                results.push_back(i + 1);
                results.push_back(j+1);
                }
            }
        }
        return results;

    }
};

void print_vector(vector<int>& numbers)
{
    for(vector<int>::iterator ite = numbers.begin();ite!=numbers.end();ite++){
        cout<<*ite<<" ";
    }

}

int main()
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(5);

    int target = 9;
    //print_vector(numbers);

    Solution sol;
    vector<int> results = sol.twoSum(numbers, target);
    print_vector(results);


    return 0;
}
