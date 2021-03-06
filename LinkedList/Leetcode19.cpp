/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast=head,*slow=head ,*tmp=NULL;
    int i=0;
    if(!head||!n)
        return head;
    if(!head->next)/*如果只有一个节点，则返回空链表*/
        return NULL;
    while(n){
        fast=fast->next;
        n--;
        if(!fast)/*如果快指针没有前进n个单位就已经为空，则返回head->next，也就是去除了第一个元素，很简单，自行推导*/
            return head->next;
    }
    /*找到待删除结点的前驱*/
	while(fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    tmp=slow->next;
    slow->next=tmp->next;
    free(tmp);
    tmp=NULL;
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode dummy(0);
        dummy.next=head;
        struct ListNode * fast=&dummy,*slow=&dummy,*tmp=NULL;
        for(int i=n;i>0;i--)
            fast=fast->next;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        tmp=slow->next;
        slow->next=tmp->next;
        delete tmp;
        return dummy.next;
    }
};
