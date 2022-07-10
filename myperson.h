#pragma once

#include "myheader.h"  // int sum(int, int), void drawline()

typedef struct {
    int no;
    int age;
    char name[100];
} Person, *PPerson;

void showPerson(Person* p);
void showPerson(Person& p);

struct PNode {
    Person person;
    PNode* nextPNode;
};

PNode* createPNode(Person& person);
PNode* insertNode(PNode* curNode, Person& person);
void destroyNode(PNode* forDestroy, PNode* head);
void printNodeFrom(PNode* from);