#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            int s_len=s.size(),t_len=t.size();
            if(s_len!=t_len)return false;
            vector<char> count(26,0);
            for(int i=0;i<s_len;i++){
                count[s[i]-'a']++;
            }
            for(int i=0;i<t_len;i++){
                count[t[i]-'a']--;
                if(count[t[i]-'a']<0)return false;
            }
            return true;
        }
    };

int main(){
    Solution demo;
    string t = "abba";
    string s = "dog cat cat dog";
    demo.isAnagram(s, t);
}