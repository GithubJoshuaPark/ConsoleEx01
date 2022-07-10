#include "myperson.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void showPerson(Person* p) {
    cout << "Person's age: " << p->age << endl;
    cout << "Person's name: " << p->name << endl;
}
void showPerson(Person& p) {
    cout << "Person's age: " << p.age << endl;
    cout << "Person's name: " << p.name << endl;
}


PNode* createPNode(Person& person) {
    PNode* pNode = (PNode*)malloc(sizeof(PNode));
    pNode->person= person;
    pNode->nextPNode = NULL;
    return pNode;
}

PNode* insertNode(PNode* curNode, Person& person) {
    PNode* pNode = (PNode*)malloc(sizeof(PNode));
    pNode->nextPNode = curNode->nextPNode;
    pNode->person = person;
    curNode->nextPNode = pNode;
    return pNode;
}

void destroyNode(PNode* forDestroy, PNode* head) {
    PNode* next = head;

    //
    if (forDestroy == head) {
        cout << head << " is freed" << endl;
        free(forDestroy);
        return;
    }

    while (next) {
        if (next->nextPNode == forDestroy) {
            next->nextPNode = forDestroy->nextPNode;
        }
        next = next->nextPNode;
    }
    cout << forDestroy << " is freed" << endl;
    free(forDestroy);
}

void printNodeFrom(PNode* from) {
    while (from) {
        drawline();
        cout << "[" << from->person.no << "]" << " name: [" << from->person.name << "]" << " age: [" << from->person.age << "]" << endl;
        from = from->nextPNode;
    }
}