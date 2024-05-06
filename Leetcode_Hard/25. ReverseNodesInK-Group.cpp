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
    ListNode* reverseLinkedList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp && k){
            temp = temp->next;
            k -= 1;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
