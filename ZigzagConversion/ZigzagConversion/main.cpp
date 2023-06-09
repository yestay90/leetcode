//
//  main.cpp
//  ZigzagConversion
//
//  Created by Yestay Muratov on 18.04.2023.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
    public:
    string convert(string s, int numRows) {
        
        if (numRows == 1)
            return s;
        
        string converted = "";
        int currentRow = 0;
        int currentCol = 0;

        vector<vector<char>> array(numRows);
        
        for (int a = 0; a < numRows; a++)
            array[a] = vector<char>(s.length());
        
        array[currentRow][currentCol] = s[0];
        bool isRowDirection = true;
        int i = 1;
        while (i < s.length()) {
            if (isRowDirection) {
                if (currentRow + 1 < numRows) {
                    array[++currentRow][currentCol] = s[i];
                    i++;
                } else {
                    isRowDirection = false;
                }
            } else {
                if (currentRow > 0 && currentCol + 1 < s.length()) {
                    array[--currentRow][++currentCol] = s[i];
                    i++;
                } else {
                    isRowDirection = true;
                }
            }
        }
        
        for (int r = 0; r < numRows; r++){
            for (int c = 0; c < s.length(); c++) {
                if (array[r][c]) {
                    converted += array[r][c];
                }
            }
        }
        
        return converted;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution myObj;
  
    string s = "AB";
    
    string v = myObj.convert(s, 1);
    
    cout<<v<<endl;
    
    return 0;
}
