#include <stdio.h>
#include <stdlib.h>
#include "listnode.h"

int generateNum(int from, int to);

/**
 * 生成一个链表
 * length  the size of generate linkedlist
 * from  to   the range of generate linkedlist each val
 */
ListNode *geneateLinkList(int length, int from, int to){
    ListNode* head = NULL;
    ListNode* pre = NULL;
    int num = generateNum(from, to);
    ListNode node;
    node.val = num;
    node.next = NULL;
    head = &node;
    pre = head;
    ListNode nodes[9] = {};
    for(int i = 0; i < length-1; i++){
        int num1 = generateNum(0, 100);
        nodes[i].val = num1;
        nodes[i].next = NULL;
        pre->next = &nodes[i];
        pre = pre->next;
    }
    return head;
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
    ListNode *head = geneateLinkList(10, 0, 100);
    while(head){
        printf("%d\t", head->val);
        head = head->next;
    }
    Traversal(head);
    system("pause");
    return 0;
}