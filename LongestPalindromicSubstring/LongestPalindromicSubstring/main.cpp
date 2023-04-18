//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by Yestay Muratov on 17.04.2023.
//

#include <iostream>

using namespace std;

int isPalindrom(string s) {
    int answer = 0;
    int startIndex = 0;
    auto endIndex = s.length() - 1;
    
    while (startIndex < endIndex) {
        if (s[startIndex] == s[endIndex]) {
            startIndex++;
            endIndex--;
        } else {
            break;
        }
    }
    
    answer = startIndex >= endIndex ? 1 : 0;
    
    return answer;
};

string findLongestSubstr(string s) {
    int max = 0;
    int maxStart = 0;
    for (int middleIndex = 0; middleIndex < s.length(); middleIndex++) {
        int startI = middleIndex, endI = middleIndex;
        
        while (endI + 1 < s.length() && s[startI] == s[endI + 1]) {
            endI++;
        }
        
        while(startI - 1 >= 0 && endI + 1 < s.length() && s[startI - 1] == s[endI + 1]) {
            startI--;
            endI++;
        }
        
        int range = endI - startI;
        if (range > max) {
            max = range;
            maxStart = startI;
        }
    }
    
    string ssss = s.substr(maxStart, max + 1);
    return max == 0 ? s.substr(max, 1) : ssss;
};

int main(int argc, const char * argv[]) {
   
    string s = "ac";
    
    cout<<" answer is "<<findLongestSubstr(s)<<endl;
    
    return 0;
}
