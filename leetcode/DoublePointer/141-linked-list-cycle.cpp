//
// Created by 侯正罡 on 2020/1/19.
//

/*
 * 给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。


 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？

来源：力扣（leetcode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <gtest/gtest.h>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr) {
            if (fast->next != nullptr && fast->next->next != nullptr) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                return false;
            }
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

TEST(hasCycle, 3) { /* NOLINT */
    std::cout << std::endl;
    string input = "[1,2,3,4,5,6]";
    auto head = stringToListNode(input);
    prettyPrintLinkedList(head);
    int i = 2;
    auto p = head;
    auto q = head;
    while (p->next != nullptr) {
        if (i-- == 0) q = p;
        p = p->next;
    }
    p->next = q;
    bool answer = true;
    bool output = Solution().hasCycle(head);
    EXPECT_EQ(answer, output);
}