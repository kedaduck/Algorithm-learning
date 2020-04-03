/* 
* @Author: leoren  
* @Date: 2020-04-03 16:39:08  
 * @Last Modified by: leoren
 * @Last Modified time: 2020-04-03 16:58:37
* @Description: 划分链表  LeetCode86 PartitionList
    已知链表头指针ｈｅａｄ与数值ｘ，将所有小于x的节点放在大于或等于x的节点前，
    且保证这些节点的原来的相对位置
*/
#include <stdio.h>
#include <stdlib.h>
#include "listnode.h"

ListNode *partition(ListNode* head, int x){
    
    ListNode *small_head;
    ListNode *big_head;
    ListNode *small_ptr = small_head;
    ListNode *big_ptr = big_head;
    while(head){
        if(head->val < x){
            small_head->next = head;
            small_ptr = small_head->next;
        }else{
            big_head->next = head;
            big_ptr = big_head->next;
        }
        head = head->next;
    }
    small_ptr->next = big_head->next;
    return small_head;
}



int main(){

    



    system("pause");
    return 0;
}