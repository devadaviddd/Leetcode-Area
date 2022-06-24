#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int elements = 0;
        int cnt = 1;
        int sum = 0;
        int adjacent = 0;
        vector<int> number;
        vector<vector<int>> list;
        vector<int> rows;
        


        for(int i = 0; i < numRows; i++) {
            rows.push_back(1);
            for(int j = 0; j < i; j++) {
                if(j + 1 != i) {
                    int next = list[i - 1][j] + list[i - 1][j + 1];
                    rows.push_back(next);
                } else {
                    rows.push_back(1);
                }
            }
            list.push_back(rows);
            rows.clear();
        }
        return list;
    }
};

int main() {
    int numRows = 5;
    Solution Sol;
    vector<vector<int>> list;
    list = Sol.generate(numRows);
    for(int i = 0; i < list.size(); i++) {
        cout << "{";
        for(int j = 0; j < list[i].size(); j++) {
            cout << list[i][j] << ",";
        }
        cout << "}\n";
    }
    return 0;
}