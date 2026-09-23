#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            unordered_map<char,string> existed_pattern;
            string t;
            vector<string> s_arr;
            //分割s为字符串数组
            for(int i=0; i<s.size(); i++){
                if(s[i]==' '){
                    s_arr.push_back(t);
                    t="";
                    continue;
                }
                t+=s[i];
            }
            //补上最后一个
            s_arr.push_back(t);
            if(pattern.size()!=s_arr.size())return false;
            for(int i=0;i<pattern.size();i++){
                if(existed_pattern.find(pattern[i])!=existed_pattern.end()){
                    if(existed_pattern[pattern[i]]!=s_arr[i])return false;
                }
                else{
                    //补全不同pattern对应相同s
                    for(auto p:existed_pattern){
                        if(s_arr[i]==p.second)return false;
                    }
                    existed_pattern[pattern[i]]=s_arr[i];
                }
            }
            return true;
        }
    };

int main(){
    Solution demo;
    string pattern = "abba";
    string s = "dog cat cat dog";
    demo.wordPattern(pattern, s);
}