#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int carry = 0, sum, digit;
        ListNode *pl1, *pl2, *pHead = new ListNode(-1), *p=pHead;

		for (pl1=l1, pl2=l2; pl1!=NULL || pl2!=NULL;)
		{
			if (pl1 == NULL)
			{
				sum = pl2->val + carry;
			}
			else if (pl2 == NULL)
			{
				sum = pl1->val + carry;
			}
			else
			{
				sum = pl1->val + pl2->val + carry;
			}
			digit = sum % 10;
			p->next = new ListNode(digit);
			carry = sum / 10;
			p = p->next;
			if (pl1!=NULL)
			{
				pl1=pl1->next;
			}
			if (pl2!=NULL)
			{
				pl2=pl2->next;
			}
		}
		if (carry != 0)
		{
			p->next = new ListNode(carry);
		}
		return pHead->next;
    }
};

void main()
{
}