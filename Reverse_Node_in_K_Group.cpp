class Solution {
public:
    ListNode* reverse(ListNode* temp) {
        ListNode* prev = NULL, *next = temp;

        while(temp) {
            next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp, int k) {
        k-= 1;
        while(temp && k > 0) {
            temp = temp -> next;
            k--;
        }
        return temp;    
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while(temp) {

            ListNode* KthNode = getKthNode(temp, k);
            if(!KthNode) {
                if(prevNode) prevNode -> next = temp;
                break;
            }
            else {
                nextNode = KthNode->next;
                KthNode -> next = NULL;

                ListNode* revNode = reverse(temp);

                if(temp == head){ // only run 1st time
                    head = revNode; 
                }
                else {
                    prevNode -> next = revNode;
                }
            }
            prevNode = temp;
            temp = nextNode;
        }

        return head;

    }
};