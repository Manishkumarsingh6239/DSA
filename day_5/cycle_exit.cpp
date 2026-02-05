
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//  class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//       unordered_set<ListNode *> us;
//       ListNode* temp = head;
//       while(temp!=nullptr){
//         us.insert(temp);
//         temp=temp->next;
//         if(us.count(temp)) return true;
//       }  
//       return false;
//     }
// };


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head; // Creating a cycle

    Solution sol;
    bool result = sol.hasCycle(head);
    cout << (result ? "Cycle detected" : "No cycle") << endl;

    return 0;
}