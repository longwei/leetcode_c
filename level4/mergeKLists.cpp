ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr && l2 == nullptr){
        return NULL;
    }
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode head(0);
    ListNode* runner = &head;
    while(p1 && p2 ) {
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
    if(p1 != nullptr){
        runner->next = p1;
    } else if (p2 != nullptr){
        runner->next = p2;
    }
    return head.next;
}


ListNode* mergeKLists(vector<ListNode *> &lists) {
    ListNode* p;
    ListNode* p1;
    ListNode* p2;
    while(lists.size() > 1){
        p1 = lists.back();
        lists.pop_back();
        p2 = lists.back();
        lists.pop_back();
        p = mergeTwoLists(p1, p2);
        //push_back have performace issue.
        //maybe using 
        lists.insert(lists.begin(), p);
    }
    return lists.size() == 1? lists[0]: nullptr;
}