// ConsoleEx01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>  // malloc
#include <string.h>
#include <memory.h>
#include "myperson.h"

using namespace std;


int main()
{
    cout << "Hello World!\n";
    drawline(NULL);
    cout << "myhead.add(5,5)" << add(5, 5) << endl;

    FILE* fp;
    char buff[255];

    fopen_s(&fp, "myheader.cpp", "r");
    if (fp == NULL) {
        cout << "File open failed" << endl;
        return 1;
    }

    while (!feof(fp)) {
        fgets(buff, sizeof(buff), fp);
        cout << buff;
    }
   
    fclose(fp);

    drawline(NULL);
    drawline(NULL);
    //drawline();
    //showPerson(&p1);

    //drawline();
    //showPerson(p1);

    //drawline();

    //int howMany = 0;
    //cout << "how many people?" << endl;
    //cin >> howMany;

    //Person* people = (Person*)malloc(sizeof(Person)*howMany); // heap area memory alloc should be free after using mandatory

    //for (int i = 0; i < howMany; i++) {
    //    people[i].no = i + 1;
    //    people[i].age = 50;
    //    strcpy_s(people[i].name, sizeof("miso"), "miso");
    //}

    //for (int i = 0; i < howMany; i++) {
    //    cout << people[i].no << endl;
    //    cout << people[i].age << endl;
    //    cout << people[i].name << endl;
    //}

    //free(people);

    Person p1;
    p1.no = 1;
    p1.age = 50;
    strcpy_s(p1.name, sizeof(JOSHUA), JOSHUA);
    PNode* pNodeHead = createPNode(p1);

    Person p2;
    p2.no = 2;
    p2.age = 40;
    strcpy_s(p2.name, sizeof(SORO), SORO);
    PNode* pNodeNext1 = insertNode(pNodeHead, p2);

    Person p3;
    p3.no = 3;
    p3.age = 30;
    strcpy_s(p3.name, sizeof(MISO), MISO);
    PNode* pNodeNext2 = insertNode(pNodeNext1, p3);

    Person p4;
    p4.no = 4;
    p4.age = 20;
    strcpy_s(p4.name, sizeof(GN), GN);
    PNode* pNodeNext3 = insertNode(pNodeNext2, p4);

    char title[] = "Person Count";
    drawline(title);
    cout << "The number of Person node is: " << countNode(pNodeHead) << endl;

    cout << "Which name do you search for in PNode?" << endl;
    char ls_name[20];
    cin >> ls_name;
    PNode* searchForNode = hasNode(pNodeHead, ls_name);
    if (searchForNode != NULL) {
        cout << "Your search name is [" 
             << searchForNode->person.no 
             << "] "
             << searchForNode->person.name
             << " and age: "
             << searchForNode->person.age
             << endl;
    }
    else {
        cout << "Your search name is not in PNode" << endl;
    }
    
    printNodeFrom(pNodeHead);
    
    destroyNode(pNodeNext3, pNodeHead);
    destroyNode(pNodeNext2, pNodeHead);
    destroyNode(pNodeHead, pNodeHead);

    drawline(NULL);

    return 0;
}

