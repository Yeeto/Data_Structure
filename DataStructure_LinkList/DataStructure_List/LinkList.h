//
//  LinkList.h
//  DataStructure_List
//
//  Created by 陈隼 on 13-10-12.
//  Copyright (c) 2013年 陈隼. All rights reserved.
//

#ifndef DataStructure_List_LinkList_h
#define DataStructure_List_LinkList_h

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <malloc/malloc.h>
#import <stdlib.h>
#import <string.h>
#import <stdio.h>
#import <stdbool.h>

/************************************************************************/
/*             以下是关于线性表链接存储（单链表）操作的18种算法        */

/* 1.初始化线性表，即置单链表的表头指针为空 */
/* 2.检查单链表是否为空，若为空则返回１，否则返回０，未初始化链表返回-1 */
/* 3.创建线性表，倒插法 */
/* 4.打印链表，链表的遍历*/
/* 5.清除线性表L中的所有元素，即释放单链表中所有的结点，使之成为一个空表 */
/* 6.返回单链表的长度 */
/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
/* 8.从单链表中查找具有给定值elem的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
/* 10.向单链表的表头插入一个元素，若插入成功返回１，否则返回０ */
/* 11.向单链表的末尾添加一个元素，若插入成功返回１，否则返回０ */
/* 12.向单链表中第pos个结点位置插入元素为elem的结点，若插入成功返回１，否则返回０ */
/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
/* 17.从单链表中删除值为elem的第一个结点，若删除成功则返回1,否则返回0 */
/* 18.交换2个元素的位置 */
/* 19.将线性表进行快速排序 降序 */
/* 20.合并两个递减有序链表为一个有序链表 */

/************************************************************************/

typedef int elemType;

typedef struct Node{    /* 定义单链表结点类型 */
    elemType element;
    struct Node *next;
}Node;


/* 1.初始化线性表，初始化表头，单链表的头结点为空 */
void initList (Node **pHead)
{
    *pHead = (Node *)malloc(sizeof(Node));
    if (!(*pHead)) {
        NSLog(@"内存分配失败！\n");
        exit(0);
    }
    (*pHead)->next = NULL;
    // **pNode 指向-> *pNode 指向-> pNode = struct Node
    NSLog(@"单链表初始化成功。\n");
}

/* 2.检查单链表是否为空，若为空则返回１，否则返回０，未初始化链表返回-1 */
int isListEmpty (Node *pHead)
{
    if (!pHead)
    {
        NSLog(@"链表未初始化！\n");
        return (-1);
    }
    
    if (!(pHead->next))
    {
        NSLog(@"空链表！\n");
        return (1);
    }
    
    NSLog(@"非空链表！\n");
    return (0);
}

/* 3.创建线性表，倒插法 */
void creatList (Node **pHead, int n)
{
    // 初始化链表
    if (!(*pHead))
    {
        initList(pHead);
    }
    
    // 检查是否是空链表
    if ((*pHead)->next)
    {
        NSLog(@"非空链表！\n");
        exit (0);
    }
    
    Node *pNewNode;
    int i;
    
    // 倒插入节点
    for(i=n; i>0; --i)
    {
        pNewNode = (Node *) malloc(sizeof(Node)); // 分配一个新节点空间
        if (pNewNode == NULL)
        {
            NSLog(@"内存分配失败\n");
            exit (0);
        }
        NSLog(@"输入数据元素数值：\n");
        scanf("%d", &pNewNode->element);
        pNewNode->next = (*pHead)->next;
        (*pHead)->next = pNewNode;
        
    }
    
}

/* 4.打印链表，链表的遍历*/
void print (Node *pHead)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;
    p = pHead->next;
    
    while(p != NULL)
    {
        NSLog(@"%d\n", p->element);
        p = p->next;
    }
}

/* 5.清除线性表L中的所有元素，即释放单链表中所有的结点，使之成为一个空表 */
void freeList (Node *pHead)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p2;
    p2 = pHead->next;
    
    while (p2)
    {
        pHead->next = p2->next;
        free(p2);
        p2 = pHead->next;
    }
    
    if (!p2)
    {
        NSLog(@"表单清除成功！\n");
    }
    
}

/* 6.返回单链表的长度 */
int listLength (Node *pHead)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    int i=0;
    Node *p;
    p = pHead->next;
    while (p != NULL)
    {
        ++i;
        p = p->next;
    }
    
    return (i);
}

/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
int getElem (Node *pHead, int pos)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;
    p = pHead->next;
    
    while (p)
    {
        if (pos == 1) {
            return (p->element);
        }
        --pos;
        p = p->next;
    }
    
    NSLog(@"超出链表范围");
    exit(0);
    
}

/* 8.从单链表中查找具有给定值elem的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
elemType *getElemAdd (Node *pHead, elemType elem)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;
    p = pHead->next;
    
    while (p)
    {
        if (elem == p->element)
        {
            elemType *q;
            q = &(pHead->element);
            NSLog(@"数据元素地址为:%p", q);
            
            return (q);
        }
        
        p = p->next;
    }
    
    NSLog(@"链表元素没有%d!\n", elem);
    return NULL;
}

/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
int modifyElem (Node *pHead, int pos, elemType elem)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;
    p = pHead->next;
    
    while (p) {
        if (pos == 1) {
            p->element = elem;
            return (1);
        }
        --pos;
        p = p->next;
    }
    
    NSLog(@"超出链表范围！\n");
    return (0);
    
}

/* 10.向单链表的表头插入一个元素，若插入成功返回１，否则返回０ */
int insertElemAtHead (Node *pHead, elemType elem)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *pNew;
    pNew = (Node *) malloc(sizeof(Node));
    if (pNew == NULL) {
        NSLog(@"内存分配失败！\n");
        return (0);
    }
    pNew->element = elem;
    
    pNew->next = pHead->next;
    pHead->next = pNew;
    
    return (1);
}

/* 11.向单链表的末尾添加一个元素，若插入成功返回１，否则返回０ */
int insertElemAtEnd (Node *pHead, elemType elem)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;
    Node *pNew;
    p = pHead;
    pNew = (Node *) malloc(sizeof(Node));
    if (pNew == NULL) {
        NSLog(@"内存分配失败！\n");
        return (0);
    }
    pNew->element = elem;
    
    while (p->next)
    {
        p = p->next;
    }
    pNew->next = p->next;
    p->next = pNew;
    
    return (1);
}

/* 12.向单链表中第pos个结点位置插入元素为elem的结点，若插入成功返回１，否则返回０ */
int insertElem (Node *pHead, int pos, elemType elem)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p1;
    p1 = pHead;
    
    // 遍历到pos位置，插入元素。p1=NULL则超出范围
    while (p1) {
        if (pos == 1) {
            // 分配新空间
            Node *p2;
            p2 = (Node *) malloc(sizeof(Node));
            if (p2 == NULL) {
                NSLog(@"内存分配失败！\n");
                return (0);
            }
            p2->element = elem;
            
            p2->next = p1->next;
            p1->next = p2;
            return (1);
        }
        
        --pos;
        p1 = p1->next;
    }
    
    NSLog(@"超出链表范围");
    return (0);
}

/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
void insertElemOrder (Node *pHead, elemType elem)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;
    Node *pNew;
    
    p = pHead;
    pNew = (Node *) malloc(sizeof(Node));
    if (pNew == NULL)
    {
        NSLog(@"新插入元素内存分配失败！\n");
        exit (0);
    }
    pNew->element = elem;
    
    while (p->next) {
        if (elem > p->next->element) {
            pNew->next = p->next;
            p->next = pNew;
            return;
        }
        p = p->next;
    }
    
    pNew->next = p->next;
    p->next = pNew;
    
}


/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
elemType deleteHead (Node *pHead)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    elemType elem;
    Node *pDel;
    pDel = pHead->next;
    
    pHead->next = pDel->next;
    elem = pDel->element;
    free(pDel);
    
    return (elem);
    
}

/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
elemType deleteLast (Node *pHead)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    // 检查链表是否空链表
    if (!(pHead->next))
    {
        NSLog(@"空链表!");
        exit (0);
    }
    
    Node *p;
    p = pHead->next;
    elemType elem;
    
    while (p->next)
    {
        p = p->next;
        pHead = pHead->next;
    }
    
    elem = p->element;
    pHead->next = p->next;
    free(p);
    
    return (elem);
    
}


/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
elemType deleteElemInPos (Node *pHead, int pos)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;
    elemType elem;
    p = pHead->next;
    
    // 指向第pos个元素，并判断是否超出范围
    while (p)
    {
        if (pos == 1)
        {
            elem = p->element;
            pHead->next = p->next;
            free(p);
            
            return (elem);
        }
        --pos;
        p = p->next;
        pHead = pHead->next;
    }
    
    NSLog(@"超出链表范围");
    exit (0);
    
}

/* 17.从单链表中删除值为elem的第一个结点，若删除成功则返回1,否则返回0 */
int deleteElem (Node *pHead, elemType elem)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    // 检查链表是否空链表
    if (!(pHead->next))
    {
        NSLog(@"空链表!");
        exit (0);
    }
    
    Node *p;
    p = pHead->next;
    
    // 遍历链表，如果p的数值元素与elem相同则删除p节点
    while (p) {
        if (p->element == elem) {
            pHead->next = p->next;
            free(p);
            return (1);
        }
        p = p->next;
        pHead = pHead->next;
    }
    
    NSLog(@"未找到与值 %d 一致的节点。\n", elem);
    return (0);
    
}

/* 18.交换2个元素的位置 */
void changePos (Node *pHead, int pos1, int pos2)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p1;
    Node *p2;
    elemType elem;
    
    p1 = pHead->next;
    p2 = pHead->next;
    
    //移动指针到pos1和pos2的位置，如果p1和p2为NULL，则位置超出链表范围
    while (p1  && p2  && !(pos1 == 1 && pos2 == 1)) {
        if (pos1 != 1) {
            p1 = p1->next;
            --pos1;
            
        }
        if (pos2 != 1) {
            p2 = p2->next;
            --pos2;
            
        }
        
    }
    
    if (!p1 || !p2) {
        NSLog(@"位置超出范围！\n");
        exit (0);
    }
    
    elem = p1->element;
    p1->element = p2->element;
    p2->element = elem;
    
}


/* 19.将线性表进行快速排序，降序 */
void sortList (Node *pHead)
{
    // 检查链表是否初始化
    if (!pHead)
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    Node *p;                //链表指针
    Node *pNewHead;         //新链表头
    
    // 初始化新链表
    pNewHead = (Node *)malloc(sizeof(Node));
    if (!pNewHead) {
        NSLog(@"空间分配失败！\n");
        exit(0);
    }
    pNewHead->element = pHead->element;
    pNewHead->next = NULL;
    p = pHead->next;
    
    // 将列表元素按序插到新链表
    while (p != NULL) {
        elemType elem = p->element;
        insertElemOrder(pNewHead, elem);
        p = p->next;
        
    }
    
    p = pHead->next;
    pHead->next = pNewHead->next;
    freeList(p);
    free(pNewHead);
    
}

/* 20.合并两个递减有序链表为一个有序链表 */
void mergeList (Node **pHead1, Node **pHead2, Node **pHeadNew)
{
    // 检查链表是否初始化
    if (!(*pHead1) || !(*pHead2) || !(*pHeadNew))
    {
        NSLog(@"链表未初始化!");
        exit (0);
    }
    
    // pHeadNew不是空链表则退出
    if ((*pHeadNew)->next) {
        NSLog(@"合并用链表为非空链表");
        exit (0);
    }
    
    Node *p1;
    Node *p2;
    Node *p3;
    p1 = (*pHead1)->next;
    p2 = (*pHead2)->next;
    p3 = *pHeadNew;
    
    // 遍历两个链表，依次比较，将较大的节点插入新链表
    while (p1 && p2) {
        if (p1->element >= p2->element) {
            p3->next = p1;
            p1 = p1->next;
        }
        else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    
    // 将剩余的链表插入新链表
    if (p1 == NULL) {
        p3->next = p2;
    }
    else {
        p3->next = p1;
    }
    
    // 删除旧链表头
    free(*pHead1);
    free(*pHead2);
    
}

#endif
