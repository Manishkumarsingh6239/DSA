#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x=0, ListNode *next=nullptr) : val(x), next(next) {} 
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head,*fast=head;
        for(int i=0; i<n; i++){
            fast=fast->next;
        }
        if(!fast) return head=head->next;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;

    }
};

int main(){
    
}