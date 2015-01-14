#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <unordered_set>
using namespace std;



struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbersR(ListNode *l1, ListNode *l2, int carry) {
    //both l1 and l2 could be null
    if(l1== NULL && l2 == NULL && carry == 0) return NULL;
    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    ListNode* ret = new ListNode(sum % 10);
    ret->next = addTwoNumbersR(l1?l1->next:NULL, l2?l2->next:NULL, sum/10);
    return ret;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* result = addTwoNumbersR(l1, l2,0);
    return result;
}




int main()
{
     ListNode *node1 = new ListNode(0);
     ListNode *node2 = new ListNode(8);
     ListNode *node3 = new ListNode(1);
//     node1->next = node2;
     ListNode* ret = addTwoNumbers(node1, node3);
     cout << ret->val << endl;

    return 0;
}
