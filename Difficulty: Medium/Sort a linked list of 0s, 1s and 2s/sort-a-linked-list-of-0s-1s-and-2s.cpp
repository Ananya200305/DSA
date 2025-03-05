//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        
        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return prev;
    }
    
    Node* merge(Node* l1, Node* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        Node* head = NULL;
        
        if(l1 -> data < l2 -> data){
            head = l1;
            l1 = l1 -> next;
        }else{
            head = l2;
            l2 = l2 -> next;
        }
        
        Node* tail = head;
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> data < l2 -> data){
                tail -> next = l1;
                l1 = l1 -> next;
            }else{
                tail -> next = l2;
                l2 = l2 -> next;
            }
            tail = tail -> next;
        }
        
        if(l1 != NULL){
            tail -> next = l1;
        }else{
            tail -> next = l2;
        }
        
        return head;
    }
    
    Node* segregate(Node* head) {
        if(head == NULL || head -> next == NULL) return head;
        
        Node* mid = getMid(head);
        Node* rightHalf = mid -> next;
        mid -> next = NULL;
        
        Node* left = segregate(head);
        Node* right = segregate(rightHalf);
        
        return merge(left,right);
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends