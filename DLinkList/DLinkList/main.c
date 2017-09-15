//
//  main.c
//  DLinkList
//
//  Created by zhoutq on 2017/9/15.
//  Copyright © 2017年 zhoutq. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

/*
 定义双链表节点类型
 */
typedef struct DNode {
    char data;
    struct DNode *pre;
    struct DNode *next;
}DLinkList;

/*
 创建双链表
 */
DLinkList* CreateDLinkList(char a[], int n) {
    
    // 创建头结点
    DLinkList *head = (DLinkList *)malloc(sizeof(DLinkList));
    head->pre = NULL;
    head->next = NULL;
    
    DLinkList *p, *q;
    p = head; // p 指向头结点
    for (int i = 0; i < n; i++) {
        
        q = (DLinkList *)malloc(sizeof(DLinkList));
        q->data = a[i];
        q->pre = p; // 新创建节点的pre指向p
        q->next = NULL;
        
        p->next = q; // p的next指向q
        p = q; // p 后移
    }
    
    return head;
}

/*
 打印双链表
 */
void PrintfDLinkList(DLinkList *head) {
    
    DLinkList *p = head->next;
    while (p) {
        printf("%c,",p->data);
        p = p->next;
    }
    printf("\n");
}


/*
 双链表指定节点数之前插入新的元素: a前面插入c
 */
void InsterDLinkList(DLinkList *head, char a, char c) {
    
    DLinkList *p = head;
    DLinkList *q = NULL;
    
    while (p->next) {
        
        // 判断 p 下一个节点数据是否为 a 数据
        if (p->next->data == a) {
            break;
        }
        p = p->next;
    }
    
    // break 后 创建新节点 q
    q = (DLinkList *)malloc(sizeof(DLinkList));
    q->data = c;
    q->pre = p;
    q->next = p->next;  // 将 q->next 为原先 p->next
    
    p->next->pre = q; // p->next 即data == a的节点的pre指向q
    p->next = q; // 然后 p->next 指向 q
}

/*
 双链表删除元素
 */
void DeleteDLinkList(DLinkList *head, char a) {
    
    DLinkList *p = head->next;
    while (p) {
        
        if (p->data == a) {
            
            p->pre->next = p->next;
            p->next->pre = p->pre;
            free(p);
            break;
        }
        
        p = p->next;
    }
}

int main(int argc, const char * argv[]) {
    
    char a[5] = {'a','c','d','e','f'};
    DLinkList *dlist = CreateDLinkList(a, 5);
    PrintfDLinkList(dlist);
    InsterDLinkList(dlist, 'c', 'b');
    PrintfDLinkList(dlist);
    DeleteDLinkList(dlist, 'c');
    PrintfDLinkList(dlist);
    return 0;
}
