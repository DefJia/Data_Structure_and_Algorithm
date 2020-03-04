//
// Created by Defjia's MiBook on 2020/2/15.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while(num != 0){
            if (num % 2 == 0){
                num /= 2;
            } else{
                num--;
            }
            cnt++;
        }
        cout << cnt;
        return cnt;
    }
};

int main(){
    int num = 14;
    Solution a;
    a.numberOfSteps(num);
}