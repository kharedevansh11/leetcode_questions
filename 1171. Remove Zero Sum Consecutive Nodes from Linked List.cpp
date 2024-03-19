class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL) return 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        unordered_map<int, ListNode*> mp;
        int preSum = 0;

        while (temp != NULL) {
            preSum += temp->val;
            if (mp.find(preSum) != mp.end()) {
               int sum = preSum;
                ListNode* start = mp[preSum]->next;
               
                while(start!=temp && start!=NULL){
                    sum+=start->val;
                    start = start->next;
                    if(start!=head){
                        mp.erase(sum);
                    }
                }
                mp[preSum ]->next = temp->next;
            }
            else {
                mp[preSum] = temp;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};
