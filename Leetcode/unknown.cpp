#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100000
#define falg flag
#define ture true
#define esle else
typedef long long ago;
typedef double kill_;

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode* tmp = head;
        while(tmp){
            tmp = tmp -> next;
            cnt++;
        }

        ListNode* o = head->next, *n = head, *h = head, *c;

        for(int a = 1; a <= cnt / 2 - 1; a++){
            c = o;
            o = o->next;
            c->next = n;
            n = c;
        }
        if(cnt % 2 == 1) o = o->next;
        int flag = 0;
        for(int a = 1; a <= cnt / 2; a++){
            if(n->val != o->val){
                flag = 1;
                break;
            }
            if (a+1 <= cnt/2){
                n = n->next; o = o->next;
            }
        }
        if (flag) {
            cout << "false";
            return false;
        }
        else {
            cout << "true";
            return true;
        }
    }
};

int main(){
#define LOCAL
#ifdef LOCAL
    freopen("../Create_use_cases/data.in.txt","r",stdin);
#endif
    int a;
    ListNode* h = (ListNode*)malloc(sizeof(ListNode));
    ListNode* q = h;
    while(cin >> a){
        ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->val = a;
        tmp->next = NULL;
        q->next = tmp;
        q = tmp;
    }
    Solution z;
    z.isPalindrome(h->next);

    return 0;
}
