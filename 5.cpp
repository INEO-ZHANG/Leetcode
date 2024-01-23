#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if(len==1)return s;

        int MAX=0,MAXloc=0;
        for(int i=1;i<len-1;i++){
            int L=0;
            while(i-L-1>=0&&i+L+1<len){
                if(s[i-L-1]==s[i+L+1])L++;
                else break;
            }
            if(L>MAX){
                MAXloc=i;
                MAX=L;
            }
        }
        int MAX1=0,MAXloc1=0;
        for(int i=0;i<len-1;i++){
            int L=0;
            while(i-L>=0&&i+L+1<len){
                if(s[i-L]==s[i+L+1])L++;
                else break;
            }
            if(L>MAX1){
                MAXloc1=i;
                MAX1=L;
            }
        }
        string result;
        if(MAX1>MAX){
            result=s.substr(MAXloc1-MAX1+1,2*MAX1);
            return result;
        }
        result=s.substr(MAXloc-MAX,2*MAX+1);
        return result;
    }
};

int main(){
    Solution sol;
    string s="abb";
    string result=sol.longestPalindrome(s);
    cout<<result;
}