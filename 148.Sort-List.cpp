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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        vector <int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        
        sort(arr.begin(), arr.end());
        
        ListNode * newhead = new ListNode(arr[0]);
        ListNode * temp1 = newhead;
        temp1->next = NULL;
        
        for(int i = 1; i < arr.size(); i++){
            ListNode * temp = new ListNode(arr[i]);
            temp1->next = temp;
            temp->next = NULL;
            temp1 = temp;
        }
        
        return newhead;
    }
};