//
// Created by defjia on 18-4-18.
//
#include <cstdlib>
#include <stdio.h>
using namespace std;
typedef struct node{
    unsigned int stock_id, deal_id;
    unsigned int amount;
    double price;
    node *next;
}NODE;
int main(){
    unsigned int n, amount, stock_id, record = 0, deal_amount, tmp_stock_id, tmp_deal_id, flag;
    char behavior;
    double price;
    NODE *buy = (node*)malloc(sizeof(node));
    NODE *sell = (node*)malloc(sizeof(node));
    buy->next = NULL; sell->next = NULL;
    NODE *cur, *tmp;
    if(scanf("%d", &n)!=1) exit(1);
    while (n != 0){
        switch (n) {
            case 1: {
                if (scanf("%04d %lf %d %c", &stock_id, &price, &amount, &behavior) != 4) exit(4);
                printf("orderid: %04d\n", ++record);
                flag = 0;
                if (behavior == 'b') {
                    cur = sell;
                    while(cur->next && price >= cur->next->price){
                        if(cur->next->stock_id == stock_id){
                            if(amount >= cur->next->amount){
                                amount -= cur->next->amount;
                                deal_amount = cur->next->amount;
                            } else{
                                cur->next->amount -= amount;
                                deal_amount = amount;
                                amount = 0;
                                flag = 1;
                            }
                            printf("deal--price:%6.1lf  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (cur->next->price + price)/2, deal_amount, record, cur->next->deal_id);
                            if(flag == 1) break;
                            cur->next = cur->next->next;
                            if(amount == 0) break;
                        } else{
                            cur = cur->next;
                        }
                    }
                    if(amount){
                        tmp = (node*)malloc(sizeof(node));
                        tmp->amount = amount;
                        tmp->stock_id = stock_id;
                        tmp->price = price;
                        tmp->deal_id = record;
                        cur = buy;
                        while (cur->next && cur->next->price >= price){
                            cur = cur->next;
                        }
                        tmp->next = cur->next;
                        cur->next = tmp;
                    }
                } else{
                    cur = buy;
                    while(cur->next && price <= cur->next->price){
                        if(cur->next->stock_id == stock_id){
                            if(amount >= cur->next->amount){
                                amount -= cur->next->amount;
                                deal_amount = cur->next->amount;
                            } else{
                                cur->next->amount -= amount;
                                deal_amount = amount;
                                amount = 0;
                                flag = 1;
                            }
                            printf("deal--price:%6.1lf  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (cur->next->price + price)/2, deal_amount, record, cur->next->deal_id);
                            if(flag == 1) break;
                            cur->next = cur->next->next;
                            if(amount == 0) break;
                        } else{
                            cur = cur->next;
                        }
                    }
                    if(amount){
                        tmp = (node*)malloc(sizeof(node));
                        tmp->amount = amount;
                        tmp->stock_id = stock_id;
                        tmp->price = price;
                        tmp->deal_id = record;
                        cur = sell;
                        while (cur->next && cur->next->price <= price){
                            cur = cur->next;
                        }
                        tmp->next = cur->next;
                        cur->next = tmp;
                    }
                }
                break;
            }
            case 2:{
                if(scanf("%d", &tmp_stock_id) != 1) exit(1);
                cur = buy;
                printf("buy orders:\n");
                while (cur->next){
                    if(cur->next->stock_id == tmp_stock_id){
                        printf("orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: b\n", cur->next->deal_id, cur->next->stock_id, cur->next->price, cur->next->amount);
                    }
                    cur = cur->next;
                }
                cur = sell;
                printf("sell orders:\n");
                while (cur->next){
                    if(cur->next->stock_id == tmp_stock_id){
                        printf("orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: s\n", cur->next->deal_id, cur->next->stock_id, cur->next->price, cur->next->amount);
                    }
                    cur = cur->next;
                }
                break;
            }
            case 3:{
                if(scanf("%d", &tmp_deal_id) != 1) exit(1);
                flag = 0;
                cur = buy;
                while (cur->next){
                    if(cur->next->deal_id == tmp_deal_id){
                        printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: b\n", cur->next->deal_id, cur->next->stock_id, cur->next->price, cur->next->amount);
                        cur->next = cur->next->next;
                        flag = 1;
                        break;
                    }
                    cur = cur->next;
                }
                if(flag == 0){
                    cur = sell;
                    while (cur->next){
                        if(cur->next->deal_id == tmp_deal_id){
                            printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1lf, quantity: %4d, b/s: s\n", cur->next->deal_id, cur->next->stock_id, cur->next->price, cur->next->amount);
                            cur->next = cur->next->next;
                            flag = 1;
                            break;
                        }
                        cur = cur->next;
                    }
                }
                if(flag == 0){
                    printf("not found\n");
                }
                break;
            }
            default:
                exit(1);
        }
        if(scanf("%d", &n)!=1) exit(1);
    }
    return 0;
}