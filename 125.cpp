#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        bool isAlphabet(char a) {
            if(a>='a'&&a<='z')return true;
            if(a>='A'&&a<='Z')return true;
            if(a>='0'&&a<='9')return true;
            return false;
        }
        bool isPalindrome(string s) {
            int n=s.size();
            for(int i=0,j=n-1;i<=j;){
                if(!isAlphabet(s[i])){
                    i++;
                    continue;
                }
                if(!isAlphabet(s[j])){
                    j--;
                    continue;
            }
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]='a'+ s[i] - 'A';
            }
            if(s[j]>='A'&&s[j]<='Z'){
                s[j]='a'+ s[j] - 'A';
            }
            if(s[i]==s[j]||s[i]==s[j]+'A'-'a'||s[i]==s[j]-'A'+'a'){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution demo;
    string s = "0P";
    cout<<demo.isPalindrome(s);
}