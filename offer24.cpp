#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode> temp;
        ListNode *t;
        t=head;
        while(t!=NULL){
            temp.push(*t);
            t=t->next;
        }
        ListNode *result;
        ListNode *i;
        i=result;
        while(!temp.empty()){
            *i=temp.top();
            i=i->next;
            temp.pop();
        }
        return result;
    }
};

int main(){
    Solution slo;
    ListNode *head;
    ListNode *t=head;
    for(int i=1;i<6;i++){
        t->val=i;
        t=t->next;
    }
}