#include<iostream>
#include<vector>
#include<map>
using namespace std;

//The O(N^2) simple algorithm
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, sum;
        vector<int> results;
        map<int, int> hmap;
        for(i=0; i<(nums.size()); i++){
            if(hmap.find(target - nums[i]) != hmap.end())
             {
                results.push_back(hmap[target - nums[i]]+1);
                results.push_back(i+1);
                return results;
            }
             hmap[nums[i]] = i;
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

    int target = 13;
    //print_vector(numbers);

    Solution sol;
    vector<int> results = sol.twoSum(numbers, target);
    print_vector(results);


    return 0;
}
