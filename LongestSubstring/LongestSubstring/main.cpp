//
//  main.cpp
//  LongestSubstring
//
//  Created by Yestay Muratov on 10.04.2023.
//

#include <iostream>
#include <map>
#include "limits.h"

using namespace std;



//int lengthOfLongestSubstring(string s) {
//    int currentCount = 0;
//    int maxCount = 0;
//    map<char, int> hashTable;
//    int i = 0;
//
//    while (i < s.size()) {
//        char letter = s.at(i);
//
//        if (hashTable.count(letter) > 0) {
//            auto prevCharData = hashTable.find(letter);
//            i = prevCharData->second;
//            if (i < s.size()-1) {
//                i++;
//            }
//            currentCount = 1;
//            hashTable.clear();
//        } else {
//            currentCount++;
//            if (currentCount > maxCount)
//                maxCount = currentCount;
//        }
//        hashTable[s.at(i)] = i;
//        hashTable.erase(s.at(i));
//
//        i++;
//    }
//
//    hashTable.clear();
//    return maxCount;
//};

int lengthOfLongestSubstring(string s) {
    int maxCount = 0;
    map<char, char> hashTable;
    int i = 0, j = 0;
    
    while (i < s.size() && j < s.size()) {
        if (hashTable.count(s[j]) > 0) {
            hashTable.erase(s[i++]);
        } else {
            hashTable[s[j++]] = s[j];
            int currentCount = j - i;
            maxCount = currentCount > maxCount ? currentCount : maxCount;
        }
    }
    
    hashTable.clear();
    return maxCount;
};

int main(int argc, const char * argv[]) {
    
    int size = lengthOfLongestSubstring("dvdf");
    
    printf("%d size: ", size);
    
    return 0;
}
