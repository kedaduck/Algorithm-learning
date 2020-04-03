/* 
* @Author: leoren  
* @Date: 2020-04-02 18:20:04  
 * @Last Modified by: leoren
 * @Last Modified time: 2020-04-02 23:56:05
* @Description: 链表的一些基本操作　　　反转链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <set>

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

/**
 * 找到交叉链表的交点  做法１
 * 1-> 2-> 3-> 4-> 5-> 
 * 2-> 3->-^
 * 找到A链表的３　　Ｂ链表的第二个３
 * 返回该交点的指针
 */
ListNode *GetINtersectionNode(ListNode *headA, ListNode *headB){
    std::set<ListNode*> node_set;
    while (headA){
        node_set.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if(node_set.find(headB) != node_set.end()){
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

int getListLength(ListNode *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

/**
 * 将长链表的指针向后移动　使链表长度一致
 */
ListNode *forwardLongList(int longLen, int shortLen, ListNode *head){
    int delta = longLen - shortLen;
    while(head && delta){
        head = head->next;
        delta--;
    }
    return head;
}

/**
 * 找到交叉链表的交点  做法2
 */
ListNode *GetINtersectionNode2(ListNode *headA, ListNode *headB){
    int listALen = getListLength(headA);
    int listBLen = getListLength(headB);
    if(listALen > listBLen){
        headA = forwardLongList(listALen, listBLen, headA);
    }else{
        headB = forwardLongList(listBLen, listALen, headB);
    }
    while(headA && headB){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

/**
 * 链表中有环　　返回环的开始节点指针 方法１
 */
ListNode *detectCycle(ListNode *head){
    std::set<ListNode *> node_set;
    while(head){
        //说明在set中已经出现了
        if(node_set.find(head) != node_set.end()){
            return head;
        }
        node_set.insert(head);
        head = head->next;
    }
    return NULL;
}

/**
 * 快慢指针 详解看ｐｉｃｔｕｒｅｓ下的图　
 */
ListNode *detectCycle1(ListNode *head){
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *meet = NULL;
    while(fast){
        slow = slow->next;
        fast = fast->next;
        if(!fast){
            return NULL;
        }
        fast = fast->next;
        if(fast == slow){
            meet = fast;
            break;
        }
    }
    if(meet == NULL){
        return NULL;
    }
    while(head && meet){
        if(head == meet){
            return head;
        }
        head = head->next;
        meet = meet->next;
    }
    return NULL;
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
    e.next = &c;
    ListNode *head = &a;
    // printf("反转之前：\n");
    // Traversal(head);
    // ListNode *new_head = ReverseLinkListFromMToN(head, 2, 4);
    // printf("反转之后：\n");
    // Traversal(new_head);
    ListNode* headC = detectCycle1(head);
    printf("环开始节点数值为%d\n", headC->val);
    system("pause");
    return 0;
}