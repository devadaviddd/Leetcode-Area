#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min(int x, int y) {
    if(x < y) {
        return x;
    }
    return y;
}

int max(int x, int y) {
    if(x > y) {
        return x;
    }
    return y;
}

int minMaxGame(vector<int>& nums) {
    if(nums.size() == 1) {
        return nums[0];
    } else {
        int size = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) {
                int winner = min(nums[i], nums[i + 1]);
                if(winner == nums[i]) {
                    nums.erase(nums.begin() + i + 1);
                } else {
                    nums.erase(nums.begin() + i);
                }
            } else {
                int winner = max(nums[i], nums[i + 1]);
                if(winner == nums[i]) {
                    nums.erase(nums.begin() + i + 1);
                } else {
                    nums.erase(nums.begin() + i);
                }
            }            
        }
        return minMaxGame(nums);
    }
}

int main() {
    vector<int> input {1, 3, 5, 2, 4, 8, 2, 2};
    cout << minMaxGame(input);
}