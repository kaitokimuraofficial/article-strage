#include <stdio.h>
#include <stdlib.h>

#include "node.h"


// create new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// return length of linked list
// length of linked list of only head node is 1.
// length of HEAD -> 3 -> 5 -> NULL is 3.
int len(Node* head) {
    int length = 0;
    Node *temp = head;

    while (temp != NULL) {
        length ++;
        temp = temp->next;
    }
    free(temp);

    return length;
}

// print every node from beginning to end
void print(Node* head) {
    if (head == NULL) {
        printf("Head is NULL\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
    free(temp);

    return;
}

// insert node at the head
int insertAtBeginning(Node** head, int data) {
    Node *nodeInserted = createNode(data);

    nodeInserted->next = *head;
    *head = nodeInserted;

    return 0;
}

// insert node at the end
int insertAtEnd(Node** head, int data) {
    Node *nodeInserted = createNode(data);

    if (*head == NULL) {
        *head = nodeInserted;
        return 0;
    }

    Node *temp = *head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = nodeInserted;

    return 0;
}

// insert node at given index
//
// Head node is located on index 0.
// If head is HEAD -> 3 -> 5 -> NULL, and exec insertAtIndex(head, 10, 2),
// it results in HEAD -> 3 -> 10 -> 5 -> NULL.
// insertAtBeginning equals in insertAtIndex(head, x, 0)
int insertAtIndex(Node** head, int data, int index) {
    if (index < 0) return -1;

    Node *newNode = createNode(data);
    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return 0;
    }

    Node *temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) temp = temp->next;

    if (temp == NULL) return -1;

    newNode->next = temp->next;
    temp->next = newNode;
    
    return 0;
}

// delete head node
int deleteHead(Node** head) {
    if (*head == NULL) return -1;

    Node *temp = *head;
    *head = temp->next;
    free(temp);

    return 0;
}

// delete tail node
int deleteTail(Node** head) {
    if (*head == NULL) return -1;

    Node *temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return 0;
    }

    while (temp->next->next != NULL) {
        free(temp->next);
        temp = temp->next;
    }
    temp->next = NULL;

    return 0;
}

// delete node at given index
//
// If head is HEAD -> 3 -> 5 -> NULL, and exec deleteAtIndex(head, 1),
// it results in HEAD -> 5 -> NULL.
// deleteHead equals in deleteAtIndex(head, 0)
// deleteTail equals in deleteAtIndex(head, len(*head))
int deleteAtIndex(Node** head, int index) {
    if (index < 0) return -1;

    if (index == 0) {
        *head = (*head)->next;
        return 0;
    }

    Node *temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) temp = temp->next;

    if (temp == NULL) return -1;

    temp->next = temp->next->next;
    return 0;
}
