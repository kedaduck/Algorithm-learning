#include <stdio.h>
#include <stdlib.h>
#include "listnode.h"

int generateNum(int from, int to);

/**
 * 生成一个链表
 * length  the size of generate linkedlist
 * from  to   the range of generate linkedlist each val
 */
ListNode *generateList(int length, int from, int to){
    ListNode *head;
    ListNode *head_pre = head;
    for(int i = 0; i < length; i++){
        int random = generateNum(from, to);
        ListNode a;
        a.val = random;
        head = &a;
        if(i == 9){
            head->next = NULL;
        }
        head = head->next;
    }
    return head_pre;
}

void Traversal(ListNode *head){
    printf("遍历结果如下：\n");
    while(head){
        printf("%d\t", head->val);
        head = head->next;
    }
}

/**
 * generate a random num which is in range of from To to
 * [from , to]
 */
int generateNum(int from, int to){
    return (rand() % (to-from+1)) + from;
}

int main(int argc, const char** argv) {
    ListNode *head = generateList(10, 0, 100);
    Traversal(head);
    system("pause");
    return 0;
}