#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include <stdio.h>

//环状链表
//需要返回入环的入口点
//题目链接：https://leetcode-cn.com/problems/linked-list-cycle-ii


/*
	思路：
    使用快慢指针
	这里有两种做法
	一种是采用公式法，但是这种方法需要知道并且能够推断出公式
	另一种是将环转化成求交点问题
*/
/*
    扩展追问：（快慢指针在单向不带头不循环带环中的应用）
    当slow一次走一步，fast一次走两步，一定能追上吗？
    答：一定能，当slow到了入环口，不管fast在环里走了几圈或者什么位置
    slow进入以后，fast开始追击slow，并且他们的距离在以一步的距离逐渐减小
    当他们之间的距离减少到等于0的时候，就能追的上，因为fast是以slow的两倍速度追击slow
    所以一圈之内的距离必能追上

    当slow一次走一步，fast一次走三步，走四步，走n步呢？
    答：不一定
    当slow到环的入口处，设fast距离slow的距离为N，设环的长度为C

    在第一次追击过程中，如果N是偶数，那是追得上的，因为两者的距离以差值为2在不断减小，当差值为0就追上了
    在第一次追击过程，如果N是奇数，fast就会超过slow，而且有可能超过一步也有可能超过两步
    
    当超过一步，进行第二次追击时，两者的距离N就变成了C-1
    当C-1为奇数时，因为fast和slow的距离以差值为2不断减少，于是乎，第二次追击又会变成fast超过slow一步
    直到n次也是如此，所以这种情况是不可能追上的
    当C-1为偶数时，因为fast和slow的距离以差值为2不断减少，所以能追上
    
    当超过两步，进行第二次追击时，两者的距离N就变成C-2
    当C-2为偶数，因为fast和slow的距离以差值为2不断减少，所以能追上
    当C-2为奇数时，因为fast和slow的距离以差值为2不断减少，所以fast就会超过slow一步
    这就会进行第三次的追击，并且又变成了C-1的情况了

    据上同理n步也是这样
*/


struct ListNode 
{
    int val;
    struct ListNode* next;
    
};

//公式法
struct ListNode* detectCycle(struct ListNode* head) {
   
    //先创建两个快慢指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    //遍历，注意链表长度是否偶数奇数
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //相遇的时候判断
        if (fast == slow)
        {
            /*
                采用公式法
                L + X = N*C
                head开始即为L+X，fast开始即为N*C
                当这两个相等时，即会跳出循环，这里注意，一定会相等
            */
            while (head != fast)
            {
                head = head->next;
                fast = fast->next;
            }
            //返回入环的第一个结点
            return head;
        }
    }

    //没有环才会走到这
    return NULL;
}

//找交点法
struct ListNode* detectCycle(struct ListNode* head) {

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    //遍历，注意链表长度是否偶数奇数
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //相遇的时候，找交点
        if (fast == slow)
        {
            //将fast和fast->next断开
            struct ListNode* headtemp = fast->next;
            fast->next = NULL;

            //记录长度
            int lenA = 0;
            int lenB = 0;

            //创建遍历指针
            struct ListNode* headA = head;
            struct ListNode* headB = headtemp;

            //求出两个链表的长度
            while (headA)
            {
                headA = headA->next;
                lenA++;
            }
            while (headB)
            {
                headB = headB->next;
                lenB++;
            }

            //两个长度的差值
            int gap = abs(lenA - lenB);

            //让长的先走差值步
            if (lenA > lenB)
            {
                while (gap--)
                {
                    head = head->next;
                }
            }
            else
            {
                while (gap--)
                {
                    headtemp = headtemp->next;
                }
            }

            //找交点
            while (head != headtemp)
            {
                headtemp = headtemp->next;
                head = head->next;
            }

            //找到交点并返回
            return head;
        }
    }

    //找不到交点说明没有环
    return NULL;

}
