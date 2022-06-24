#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <functional>
#include <algorithm> 
#include <set>
#include<bits/stdc++.h>


using namespace std;

/*You are given a large sample of integers in the range [0, 255]. Since the sample is so large, it is represented by an array count where count[k] is the number of times that k appears in the sample.

Calculate the following statistics:

minimum: The minimum element in the sample.
maximum: The maximum element in the sample.
mean: The average of the sample, calculated as the total sum of all elements divided by the total number of elements.
median:
If the sample has an odd number of elements, then the median is the middle element once the sample is sorted.
If the sample has an even number of elements, then the median is the average of the two middle elements once the sample is sorted.
mode: The number that appears the most in the sample. It is guaranteed to be unique.
Return the statistics of the sample as an array of floating-point numbers [minimum, maximum, mean, median, mode]. Answers within 10-5 of the actual answer will be accepted.*/

void generateRandomStats(vector<int>& stat) {
    
    int i = 0;
    while(i < 256) {
        int random = 0 + (rand() % 225);
        stat.push_back(random);
        i++;
    }
    std::sort(stat.begin(), stat.end());
}

void printVector(vector<int> stat) {
    int i = 0;
    for(auto each : stat) {
        cout << each << ",";
        if(i % 20 == 0 && i != 0) {
            cout << "\n";
        }
    }
}
void printVector(vector<double> stat) {
    int i = 0;
    for(auto each : stat) {
        cout << each << ",";
        if(i % 20 == 0 && i != 0) {
            cout << "\n";
        }
    }
}

vector<int> ArrayCount(vector<int> stat) {
    vector<int> count;
    int i = 0;
    while(i < 256) {
        count.push_back(0);
        i++;
    }
    int index = 0;
    for(auto each : stat) {
        count[each] = count[each] + 1;
    }
    return count;
}

int maxOccurrence(vector<int> A, int size){
   int mxcount=0;
   int res=-1;
   unordered_map<int,int>mp;
   for(int i=0;i<size;i++){
      mp[A[i]]++;
   }
   for(auto x:mp){
      if(x.second>mxcount){
         res= x.first;
         mxcount=x.second;
      }
   }
   return res;
}

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> result; 
        for(int i = 0; i < count.size(); i++) {
            if(count[i] != 0) {
                result.push_back(i);
                break;
            }
        }
        for(int i = count.size() - 1; i >= 0; i--) {
            if(count[i] != 0) {
                result.push_back(i);
                break;
            }
        }
        int sum = 0;
        int total= 0;
        for(int i = 0; i < count.size(); i++) {
            sum = sum + (i * count[i]);
            total = total + count[i];
        }
        // cout << sum << "\n" << total << "\n";

        result.push_back((double)sum/(double)total);

        if(total % 2 != 0) {
            int position = total/2 + 1;
            int cnt = 0;
            for(int i = 0; i < count.size(); i++) {
                if(count[i] != 0) {
                    cnt = cnt + count[i];
                    if(cnt > position) {
                        result.push_back(i);
                        break;
                    }
                }
            }
        } else {
            int First_position = total/2;
            int Second_position = total/2 - 1;
            // cout << "Second = " << Second_position << ". First = " << First_position << "\n";
            double first = 0;
            double second = 0;
            bool con1 = false;
            bool con2 = false;
            int cnt = 0;
            //1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 
            for(int i = 0; i < count.size(); i++) {
                if(count[i] != 0) {
                    cnt = cnt + count[i];
                    if(cnt > Second_position) {
                        second = i;
                        break;  
                    }
                }
            }
            int c = 0;
            for(int i = 0; i < count.size(); i++) {
                if(count[i] != 0) {
                    c = c + count[i];
                    if(c > First_position) {
                        first = i;
                        break;  
                    }
                }
            }
            // cout << "First Value = "<< first << ". Second Value = " << second << "\n";
            double median = (first + second) / 2.0;
            result.push_back(median);
        }
        //Mode
        int max = 0;
        for(int i = 0; i <= 255; i++) {
            if(count[i] > max) {
                max = count[i];
            }
        }
        for(int i = 0; i <= 255; i++) {
            if(count[i] == max) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main()
{
    
    srand((unsigned) time(NULL));
    vector<int> stat;
    vector<int> count;
    vector<double> result;
    // generateRandomStats(stat);
    // printVector(stat);
    // count = ArrayCount(stat);
    // cout << "\n-------------------\n";
    // printVector(count);

    // cout << "\n-------------------\n";
    Solution answer;
    vector<int> testCase = {0,1,5,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    result = answer.sampleStats(testCase);
    printVector(result);
    cout << "\n-------------------\n";
    


    return 0;
}