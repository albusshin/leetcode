/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        vector<RandomListNode*> vp, vprandom;
        map<RandomListNode*, int> mp;
        RandomListNode *prev, *ret;
        int counter = 0;
        for (RandomListNode *p = head; p; p = p->next, counter++) {
            mp[p] = counter;
            RandomListNode *newNode = new RandomListNode(p->label);
            vp.push_back(newNode);
            vprandom.push_back(p->random);
            if (counter) {
                prev->next = newNode;
            }
            else {
                ret = newNode;
            }
            prev = newNode;
        }
        counter = 0;
        for (RandomListNode *p = ret; p; p = p->next, counter++) {
            RandomListNode *prandom = vprandom[counter];
            if (!prandom) p->random = nullptr;
            else p->random = vp[mp[prandom]];
        }
        return ret;
    }
};