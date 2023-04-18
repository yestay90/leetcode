//
//  main.cpp
//  ZigzagConversion
//
//  Created by Yestay Muratov on 18.04.2023.
//

#include <iostream>
using namespace std;
class Solution {
    public:
    string convert(string s, int numRows) {
        int currentRow = 0;
        int currentCol = 0;

        char ** A;
        A = new char*[numRows];
        for (int a = 0; a < numRows; a++)
            A[a] = new char[s.length()];
        
        A[currentRow][currentCol] = s[0];
        string converted;
        int i = 1;
        bool isRowDirection = true;
        
        while (i < s.length()) {
            if (isRowDirection) {
                if (currentRow + 1 < numRows) {
                    A[++currentRow][currentCol] = s[i];
                    i++;
                } else {
                    isRowDirection = false;
                }
            } else {
                if (currentRow > 0 && currentCol + 1 < s.length()) {
                    A[--currentRow][++currentCol] = s[i];
                    i++;
                } else {
                    isRowDirection = true;
                }
            }
        }
        
        for (int r = 0; r < numRows; r++){
            for (int c = 0; c < s.length(); c++) {
                if (A[r][c])
                    converted += A[r][c];
            }
        }
        
        return converted;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution myObj;
  
    string s = "YEstayMuratov";
    
    string v = myObj.convert(s, 4);
    
    cout<<v<<endl;
    
    return 0;
}
