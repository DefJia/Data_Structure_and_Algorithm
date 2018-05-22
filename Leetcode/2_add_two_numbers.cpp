//
// Created by defjia on 18-5-21.
// https://leetcode.com/problems/add-two-numbers/description/
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ex = 0;
        ListNode * l3;
        l3 = new ListNode();// l3 = new ListNode(0);
        ListNode * l4 = l3;
        l3->val = l1->val + l2 ->val >= 10? l1->val + l2 ->val - 10: l1->val + l2 ->val;
        if(l1->val + l2 ->val >= 10) ex = 1;
        l1 = l1->next; l2 = l2->next;
        while(l1 || l2 || ex){
            ListNode *tmp;
            tmp = new ListNode();// tmp = new ListNode(0);
            l3->next = tmp;
            int aa = 0, bb = 0;
            if(l1){
                aa = l1->val;
                l1 = l1->next;
            }
            if(l2){
                bb = l2->val;
                l2 = l2->next;
            }
            if(aa+bb+ex >= 10){
                l3->next->val = aa+bb+ex - 10;
                ex = 1;
            }else{
                l3->next->val = aa+bb+ex;
                ex = 0;
            }
            l3 = l3->next;
        }
        return l4;
    }
};