//
// Created by defjia on 18-5-22.
//
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
int main(){
    int n = 3;
    char aa;
    scanf("%c", &aa);
    for (int i = 1; i <= 2 * n - 1; ++i)
    {
        for (int j = 0; j < abs(n - i); j++)printf(" ");
        for (int j = 0; j < (n * 2 - 1 - abs(n - i) * 2); j++)printf("%c", aa);
        printf("\n");
    }
}
