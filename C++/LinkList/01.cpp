/* 
* @Author: leoren  
* @Date: 2020-04-02 18:20:04  
 * @Last Modified by: leoren
 * @Last Modified time: 2020-04-02 18:20:31
* @Description: 链表的一些基本操作　　　反转链表
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
};

/**
 * 便利链表
 * 
 * */
void *Traversal(ListNode *head){
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
} 
/**
 * 反转链表　　10->20->30->40->50 =====> 50->40->30->20->10
*/
ListNode *ReverseLinkList(ListNode *head){
    ListNode *new_head;
    while (head){
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}

/**
 * 反转链表　　从链表的Ｍ位置逆置到Ｎ位置
 * */
ListNode* ReverseLinkListFromMToN(ListNode *head, int m, int n){
    int changeLen = n - m + 1;
    ListNode *preHead = NULL;
    ListNode *result = head;
    while (head && m != 1){
        preHead = head;
        head = head->next;
        m--;
    }
    ListNode *modify_list_tail = head;
    ListNode *new_head = NULL;
    while(head && changeLen){
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        changeLen--;
    }
    modify_list_tail->next = head;
    if(preHead){
        preHead->next = new_head;
    }else{
        result = new_head;
    }
    return result;
}

int main(){
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;
    a.val = 10;
    b.val = 20;
    c.val = 30;
    d.val = 40;
    e.val = 50;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    ListNode *head = &a;
    printf("反转之前：\n");
    Traversal(head);
    ListNode *new_head = ReverseLinkListFromMToN(head, 2, 4);
    printf("反转之后：\n");
    Traversal(new_head);
    system("pause");
    return 0;
}