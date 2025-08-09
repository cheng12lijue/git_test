// 函数：按位置删除节点（位置从0开始）
// 返回值：1表示删除成功，0表示位置无效
int deleteNodeByPosition(struct ListNode** headRef, int position) {
    if (*headRef == NULL) {
        printf("链表为空，无法删除\n");
        return 0;
    }
    
    struct ListNode* current = *headRef;
    struct ListNode* previous = NULL;
    
    // 检查位置是否有效
    if (position < 0) {
        printf("位置不能为负数\n");
        return 0;
    }
    
    // 查找指定位置的节点
    int currentIndex = 0;
    while (current != NULL && currentIndex < position) {
        previous = current;
        current = current->next;
        currentIndex++;
    }
    
    // 如果位置超出链表长度
    if (current == NULL) {
        printf("位置 %d 超出链表范围\n", position);
        return 0;
    }
    
    // 找到了要删除的节点
    if (previous == NULL) {
        // 删除头节点
        *headRef = current->next;
    } else {
        // 删除中间或尾部节点
        previous->next = current->next;
    }
    
    // 释放内存
    free(current);
    printf("成功删除位置 %d 的节点\n", position);
    return 1;
}
