#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* head = new ListNode(0);
        ListNode* runner = head;
        while(l1 != NULL && l2 != NULL ) {
            if (l1->val < l2->val) {
                runner->next = l1;
                l1 = l1->next;
                runner = runner->next;
            } else {
                runner->next = l2;
                l2 = l2->next;
                runner = runner->next;
            }
        }
        if(l1 != NULL){
            runner->next = l1;
        } else if (l2 != NULL){
            runner->next = l2;
        } else {
        }
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};

int main()
{
    Solution s;
    return 0;
}


