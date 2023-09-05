/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)    return head;

        Node* temp = head;
        Node* idx = head;
        Node* here = NULL;

        int pos = 0;

        vector<int> arr;

        while(temp) {
            if(temp->random) {
                here = temp->random;

                while(idx!=here) {
                    idx=idx->next;
                    pos++;
                }

                arr.push_back(pos);
                pos = 0;
                idx = head;
            } else
                arr.push_back(-1);

            temp = temp->next;
        }

        temp = head;

        Node* newHead = new Node(0);
        Node* curr = newHead;

        while(temp) {
            Node* newNode = new Node(temp->val);
            curr->next = newNode;
            curr = newNode;

            temp = temp -> next;
        }

        curr->next = NULL;

        temp = newHead->next;
        idx = newHead->next;
        int i = 0;
        pos = 0;

        while(temp) {
            if(arr[i] == -1) {
                temp = temp->next;
                i++;
                continue;
            }
            
            while(pos != arr[i]) {
                idx = idx->next;
                pos++;
            }

            i++;
            pos = 0;
            temp->random = idx;
            temp = temp->next;
            idx = newHead->next;
        }

        return newHead->next;
    }
};