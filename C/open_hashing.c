/**
 *   Created by https://github.com/rajendrakumaryadav on 18/10/21.
 *   for https://github.com/rajendrakumaryadav/hacktoberfest2021


 * KEY = Data % SIZE;
 * e.g. KEY = 120 % 5 = 0, if will be inserted into chain[0] first place,
 * if Collision occurs, Add new node with same key at the end.
 *
 * Simple Represent View.
 *       key         100
 * chain[0] [100] -> [10]-> [NULL]
 *
 * chain[1]  NULL
 * chain[2]  NULL
 *                    3024        3028
 * chain[3] [3024] -> [3][3028]->[8][NULL]
 */
#include "open_hashing.h"

int main(int argc, char **argv) {
    // calling init method.
    init();
    // inserting few elements.
    insert(7);
    insert(12);
    insert(31);
    print();
    return EXIT_SUCCESS;
}

/**
 * initializing linked-list as null.
 * means nothing is in the linked list yet.
 */
void init() {
    int i;
    for (i = 0; i < SIZE; i++) {
        chain[i] = NULL;
    }
}

void insert(int value) {
    Node newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    int key = value % SIZE;
    // if chain have not element yet.
    if (chain[key] == NULL)
        chain[key] = newNode;
    else {
        // if it has already some node in chain.
        Node temp = chain[key];
        // reach at last element into the node.
        while (temp->next != NULL) {
            // making temp as next element.
            temp = temp->next;
        }
        // assign temp->next = newNode;
        temp->next = newNode;
    }
}

/**
 * method will be used to print all the elements
 * into open hashed data structure.
 */
void print() {
    int counter;
    for (counter = 0; counter < SIZE; counter++) {
        Node temp = chain[counter];
        printf("chain[%d] -> ", counter);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}