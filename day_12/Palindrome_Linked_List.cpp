#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x=0, ListNode *next=nullptr) : val(x), next(next) {} 
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr && curr->val == stack.top()) {
            stack.pop();
            curr = curr->next;
        }
        return curr == nullptr;
    }
};