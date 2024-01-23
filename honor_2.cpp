#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

void swap(string& a, string& b){
    string tmp;
    tmp=a;
    a=b;
    b=tmp;
}

int main(){
    int N;
    cin>>N;
    int n=N;
    vector<string> strs;
    vector<string> times;
    vector<string> mess;
    while(n--){
        string s;
        cin>>s;
        strs.emplace_back(s);
        int i=0;
        for(;i<s.length();i++){
            if(s[i]=='-')break;
        }
        string time=s.substr(i-4,19);
        times.emplace_back(time);
        string mes;
        for(int j=0;j<s.length();j++){
            if(j==i-4){
                j+=18;
                continue;
            }
            if(s[j]=='/')continue;
            mes+=s[j];
        }
        mess.emplace_back(mes);
        //cout<<time<<" "<<mes<<endl;
    }
    for(int i=0;i<mess.size();i++){
        for(int j=0;j<mess.size();j++){
            if(mess[i]<mess[j]){
                swap(mess[i],mess[j]);
                swap(strs[i],strs[j]);
                swap(times[i],times[j]);
            }
        }
    }
    for(int i=0;i<mess.size();i++){
        for(int j=0;j<mess.size();j++){
            if(mess[i].length()<mess[j].length()){
                swap(mess[i],mess[j]);
                swap(strs[i],strs[j]);
                swap(times[i],times[j]);
            }
        }
    }
    
    for(int i=0;i<times.size();i++){
        for(int j=0;j<times.size();j++){
            if(times[i]<times[j]){
                swap(times[i],times[j]);
                swap(strs[i],strs[j]);
            }
        }
    }
    for(int i=0;i<strs.size();i++){
        if(i>0&&strs[i]==strs[i-1])continue;
        cout<<strs[i]<<endl;

    }
}