#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int data;
    struct ListNode* next;
};

// 函数：创建链表（通过用户输入）
struct ListNode* createList() {
    struct ListNode *head = NULL;
    struct ListNode *current = NULL;
    struct ListNode *newNode = NULL;
    int value;

    printf("请输入链表的元素（输入-1结束）：\n");

    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break; // 输入-1时结束输入
        }

        // 创建新节点
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (newNode == NULL) {
            printf("内存分配失败！\n");
            exit(1);
        }
        newNode->data = value;
        newNode->next = NULL;

        // 如果是第一个节点
        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// 函数：删除整个链表，释放所有节点内存
void deleteList(struct ListNode** headRef) {
    struct ListNode* current = *headRef;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;   // 保存下一个节点
        free(current);          // 释放当前节点
        current = next;
    }

    *headRef = NULL; // 将头指针置为 NULL
    printf("链表已成功删除并释放内存。\n");
}

// 函数：打印链表
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    printf("链表内容：");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 主函数，演示创建和删除链表
int main() {
    struct ListNode* head = NULL;

    // 创建链表
    head = createList();

    // 打印链表
    printList(head);

    // 删除链表
    deleteList(&head);

    // 再次打印（应为空）
    printList(head);

    return 0;
}
