#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two
// lists.
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
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};


//pointer to next pointer, 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* head = NULL;
  ListNode** pNext = &head;
  while (l1 != NULL && l2 != NULL) {
    if (l1->val <= l2->val) {
      *pNext = l1; //then update where the next pointer to.
      l1 = l1->next;
    } else {
      *pNext = l2;
      l2 = l2->next;
    }
    pNext = &((*pNext)->next);
  }
  *pNext = (l1 != NULL ? l1 : l2);
  return head;
}

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) {
      return NULL;
    }
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode head(0);
    ListNode* runner = &head;
    while (p1 && p2) {
      if (p1->val < p2->val) {
        runner->next = p1;
        runner = runner->next;
        p1 = p1->next;

      } else {
        runner->next = p2;
        runner = runner->next;
        p2 = p2->next;
      }
    }
    if (p1 != nullptr) {
      runner->next = p1;
    } else if (p2 != nullptr) {
      runner->next = p2;
    } else {
    }
    return head.next;
  };

  int main() {
    Solution s;
    return 0;
  }
