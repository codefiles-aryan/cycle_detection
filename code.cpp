/////My Solution (More space consuming)//////////////
ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        if(head==NULL||head->next==NULL)
            return NULL;
        while(fast && fast->next && slow)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(fast==NULL||fast->next==NULL)
            return NULL;
        if(slow==head)
        {
            return head;
        }
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }


////Google solution(More space efficient but same in time as mine)/////////////


ListNode *detectCycle(ListNode *head) {
if (!head || !head->next)
            return nullptr;
        ListNode *fast = head, *slow = head;
        while(fast && fast->next && slow) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {                    
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
