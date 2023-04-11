//
//  main.cpp
//  TwoSumCPP
//
//  Created by Yestay Muratov on 09.04.2023.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int,int> hashTable;

vector<int> twoSum(vector<int>& nums, int target) {
  
    vector<int> answer;
    
    for (int i = 0; i < nums.size(); i++){
        int s1 = nums[i];
        int s2 = target - s1;
        
        if (hashTable.contains(s2)) {
            auto savedItem = hashTable.find(s2);
            answer.push_back(savedItem->second);
            answer.push_back(i);
            hashTable.clear();
        } else {
            hashTable[s1] = i;
        }
    }
    
    return answer;
};

int main(int argc, const char * argv[]) {
    
    vector<int> v1 = {2, -7, 11, 15 };
    vector<int> ans = twoSum(v1, 4);
    
    for (int i = 0; i<ans.size(); i++)
        cout<< ans[i] << " ";
    
    
    return 0;
}
