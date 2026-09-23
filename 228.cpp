#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            int n = nums.size();
            int a, b;
            vector<string> res;
            for (int i = 0; i < n; i++) {
                a = i;
                b = i;
                for (int j = i + 1; j < n; j++) {
                    if (nums[j - 1] + 1 == nums[j]) {
                        b++;
                        if (j == n - 1) {
                            b = n - 1;
                            break;
                        }
                    } else {
                        i = j - 1;
                        b = j - 1;
                        break;
                    }
                }
                string t;
                if (a == b) {
                    t = to_string(nums[a]);
                } else {
                    t = to_string(nums[a]) + "->" + to_string(nums[b]);
                }
                res.push_back(t);
                if(b==n-1)break;
            }
            return res;
        }
    };

int main(){
    Solution demo;
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> res = demo.summaryRanges(nums);
    for(auto r: res){
        cout<<r;
    }
}