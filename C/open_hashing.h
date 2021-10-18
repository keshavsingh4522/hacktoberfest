/**
 Created by https://github.com/rajendrakumaryadav on 18/10/21.
 for https://github.com/rajendrakumaryadav/hacktoberfest2021
*/

#ifndef DATA_STRUCTURE_OPEN_HASHING_H
#define DATA_STRUCTURE_OPEN_HASHING_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
typedef struct node *Node;
struct node {
    int data;
    Node next;
};

Node chain[SIZE];
// initialize all elements as null;
void init();
// insert a new element into open hashed data structure.
void insert(int value);
// print method allow you to print all the elements
void print();

#endif //DATA_STRUCTURE_OPEN_HASHING_H
