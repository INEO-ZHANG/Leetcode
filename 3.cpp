#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;
        int MAX=1;
        string t;
        int len=s.length();
        int i=0;
        for(int j=i;j<len;j++){
            t=s.substr(i,j-i+1);
            //检查字符串是否有重复
            bool flag=0;
            for(int k=0;k<t.length();k++){
                for(int m=k+1;m<t.length();m++){
                    if(t[k]==t[m]){
                        flag=1;
                        break;
                    }
                }
                if(flag==1)break;
            }
            if(flag==0){
                MAX=MAX>t.length()?MAX:t.length();
            }
            if(flag==1){
                i++;
            }
        }
        return MAX;
    }
};

int main(){
    string test;
    cin>>test;
    Solution Sol;
    cout<<Sol.lengthOfLongestSubstring(test);
    return 0;
}