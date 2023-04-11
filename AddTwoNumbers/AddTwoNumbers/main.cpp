//
//  main.cpp
//  AddTwoNumbers
//
//  Created by Yestay Muratov on 09.04.2023.
//

#include <iostream>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    struct ListNode *listNode = NULL;
    struct ListNode *p = listNode;
    int carrier = 0;
    
    while (l1 || l2) {
        
        int sum = NULL;
        
        if (l1 && l2)
            sum = l1->val + l2->val + carrier;
        else if (l1)
            sum = l1->val + carrier;
        else if (l2)
            sum = l2->val + carrier;
        
        if (sum > 9) {
            sum %= 10;
            carrier = 1;
        } else
            carrier = 0;
        
        struct ListNode *newList = new ListNode(sum);
        
        if (!p) {
            listNode = newList;
            p = newList;
        } else {
            p->next = newList;
            p = p->next;
        }
        
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    
    if (carrier > 0) {
        struct ListNode *newList = new ListNode(carrier);
        p->next = newList;
    }
    
    return listNode;
};

int main(int argc, const char * argv[]) {
    
//    struct ListNode *l3 = new ListNode(3);
//    struct ListNode *l4 = new ListNode(4, l3);
//    struct ListNode *l2 = new ListNode(2, l4);
//
//    struct ListNode *s4 = new ListNode(4);
//    struct ListNode *s6 = new ListNode(6, s4);
//    struct ListNode *s5 = new ListNode(5, s6);
//
//    struct ListNode *answer = addTwoNumbers(l2, s5);
//
//    while (answer) {
//        printf("%d ", answer->val);
//        answer = answer->next;
//    }
    
    struct ListNode *l1 = new ListNode(9);
    struct ListNode *l2 = new ListNode(9, l1);
    struct ListNode *l3 = new ListNode(9, l2);
    struct ListNode *l4 = new ListNode(9, l3);
    struct ListNode *l5 = new ListNode(9, l4);
    struct ListNode *l6 = new ListNode(9, l5);
    struct ListNode *l7 = new ListNode(9, l6);
    
    struct ListNode *s1 = new ListNode(9);
    struct ListNode *s2 = new ListNode(9, s1);
    struct ListNode *s3 = new ListNode(9, s2);
    struct ListNode *s4 = new ListNode(9, s3);
    
    struct ListNode *answer = addTwoNumbers(l7, s4);
    
    while (answer) {
        printf("%d ", answer->val);
        answer = answer->next;
    }
    
    return 0;
}
