struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next = list1;
                list1=list1->next;
            }
            else{
                temp->next = list2;
                list2=list2->next;
            }
            temp = temp->next;
        }

        temp->next = (list1) ? list1 : list2;
        return dummy->next;
    }
};

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(list1, list2);

    // Print the merged linked list
    ListNode* temp = mergedHead;
    while(temp){
        cout << temp->val << " ";
        temp=temp->next;
    }
    cout << endl;

    return 0;
}