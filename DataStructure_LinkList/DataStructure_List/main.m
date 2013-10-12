//
//  main.m
//  DataStructure_List
//
//  Created by 陈隼 on 13-10-12.
//  Copyright (c) 2013年 陈隼. All rights reserved.
//

#import "LinkList.h" // 单链表结构以及函数头文件

int main()
{
    /**************************************************/
    /* 单链表基本函数 */
    
    Node *pList = NULL;
     
    initList(&pList); // 1.初始化链表
    creatList(&pList, 3); // 3.创建链表，长度为3个元素
     
    NSLog(@"链表长度为：%d\n", listLength(pList));  // 6.返回链表长度
     
    NSLog(@"链表第2个元素是：%d", getElem(pList, 2));  // 7.返回链表第二个元素
     
    insertElem(pList, 2, 10); // 12.在链表第二个位置插入元素10
     
    deleteElemInPos(pList, 2); // 16.删除链表第二个位置的元素
     
    insertElemAtHead(pList, 4); // 10.在链表头插入数据元素4
     
    insertElemAtEnd(pList, 0); // 11.在链表尾插入数据元素0
     
    insertElemOrder(pList, 5); // 13. 插入数据元素5，使得原有序链表仍然有序
     
    //getElemAdd(pList, 3); // 8.返回满足查找参数的链表元素地址
     
    modifyElem(pList, 2, 100); // 9.将第2个数据单元的元素修改成100
     
    NSLog(@"删除的表头结点值为 %d\n", deleteHead(pList)); // 14. 删除表头结点，返回其值
     
    NSLog(@"删除的链尾元素为：%d\n", deleteLast(pList)); // 15. 删除链表最后的元素，并返回数值
     
    deleteElem(pList, 3); // 17. 从单链表中删除值为3的第一个结点
     
    changePos(pList, 1, 3); // 18.交换第1和第3，2个元素的位置
     
    sortList(pList); // 19.将线性表进行快速排序，降序
     
    print(pList);
     
    freeList(pList); // 5.清除单链表
    isListEmpty(pList); // 2.检查单链表是否为空
    
    /**************************************************/
    
    /**************************************************/
    /* 合并两个递减有序链表为一个有序链表 */
    
    Node *pList1 = NULL;
    Node *pList2 = NULL;
    Node *pList3 = NULL;
     
    initList(&pList1);
    initList(&pList2);
    initList(&pList3);
    creatList(&pList1, 5);
    creatList(&pList2, 3);
    sortList(pList1);
    sortList(pList2);
     
    mergeList(&pList1, &pList2, &pList3);
    print(pList3);
    
    /**************************************************/
    
    return 0;
    
}



