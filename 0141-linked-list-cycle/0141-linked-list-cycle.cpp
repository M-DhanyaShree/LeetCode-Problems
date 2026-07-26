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
    bool hasCycle(ListNode *head) {
        ListNode*tmp=head;
        unordered_map<ListNode*,int> visited;
        while(tmp!=NULL) {
            if(visited[tmp]==1) return true;
            else {
                visited[tmp]=1;
            }
            tmp=tmp->next;
        }
        return false;
    }
};