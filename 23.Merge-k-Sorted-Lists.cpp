/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * tmp = new ListNode;
        ListNode * current = tmp;

        struct Compare {
            bool operator() (const ListNode *a, const ListNode *b) {
                return a->val > b->val;
            }
        };
        
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        for (auto n : lists) if(n) min_heap.emplace(n);

        while (!min_heap.empty()) {
            ListNode * node = min_heap.top();
            min_heap.pop();
            current->next = node;
            current = current->next;
            if (node->next) min_heap.emplace(node->next);
        }

        return tmp->next;
    }
};