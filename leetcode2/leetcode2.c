 //Definition for singly-linked list.
#include <stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* start, * l_cur, * l_next;
    int sum, carry;

    start = (struct ListNode*)malloc(sizeof(struct ListNode));
    l_cur = start;

    sum = l1->val + l2->val;
    l_cur->val = sum >= 10 ? sum - 10 : sum;
    carry = (int)(sum / 10);

    while (1)
    {
        if (l1->next != NULL && l2->next != NULL)
        {
            l_next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l_cur->next = l_next;
            l_cur = l_next;

            l1 = l1->next;
            l2 = l2->next;

            sum = l1->val + l2->val + carry;
            l_cur->val = sum >= 10 ? sum - 10 : sum;
            carry = (int)(sum / 10);
        }
        else if (l1->next != NULL && l2->next == NULL)
        {
            l_next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l_cur->next = l_next;
            l_cur = l_next;

            l1 = l1->next;

            sum = l1->val + carry;
            l_cur->val = sum >= 10 ? sum - 10 : sum;
            carry = (int)(sum / 10);
        }
        else if (l1->next == NULL && l2->next != NULL)
        {
            l_next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l_cur->next = l_next;
            l_cur = l_next;

            l2 = l2->next;

            sum = l2->val + carry;
            l_cur->val = sum >= 10 ? sum - 10 : sum;
            carry = (int)(sum / 10);
        }
        else if (l1->next == NULL && l2->next == NULL)
        {
            if (carry)
            {
                l_next = (struct ListNode*)malloc(sizeof(struct ListNode));
                l_cur->next = l_next;
                l_cur = l_next;

                l_cur->val = carry;
                l_cur->next = NULL;
                break;
            }
            else
            {
                l_cur->next = NULL;
                break;
            }
        }
    }



    return start;
}