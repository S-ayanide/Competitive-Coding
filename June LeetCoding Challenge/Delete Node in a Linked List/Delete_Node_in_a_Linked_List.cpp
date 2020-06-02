// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

#include<bits/stdc++.h>
using namespace std;

class ListNode{
	public:
		int data;
		ListNode *next;
};

void push(ListNode **head_ref, int new_data){
	ListNode *new_node = new ListNode();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void deleteNode(ListNode *node, int value){
	if(node == NULL) return;
	while(node->next != NULL){
		if(node->next->data == value) {			
			node->next = node->next->next;			
			break;
		}
		node = node->next;
	}	
	return;
}

// The LeetCode Way
/**
Considering LeetCode has a different Linked List interpretation as they are sending the node along with the value together
In the problem Leetcode has already figured out the position of the value
We might consider shifting the value of the node corresponding to the one right side of it and keep doing it untill NULL is reachead


void deleteNode(ListNode* node) { 
    while(node->next){
        node->val=node->next->val;
        if(node->next->next)node=node->next;
        else break;
    }
    node->next=NULL;
    return;
}

**/

void printList(ListNode *head){	
	if(head == NULL){
		cout<<"Nothing to print"<<endl;
		return;
	}
	while(head != NULL){
		cout<<" "<<head->data;
		head = head->next;
	}
}

int main(){
	ListNode *head = NULL;
	push(&head, 9);
	push(&head, 1);
	push(&head, 5);
	push(&head, 4);		
	printList(head);
	cout<<endl;
	deleteNode(head, 1);
	printList(head);
	return 0;
}
