//
// Created by Ryan on 4/24/2022.
//
#include "prelab11.h"

EmpDatabase createSearchableEmployeeDB() {
    EmpDatabase database;
    database.ec = 0;
    database.headTreeSortedByID = NULL;
    database.headTreeSortedBySSN = NULL;
    return database;
}

Employee * insertViaSSN(Employee * emp, Employee * head) {
    if(head == NULL) {
        head = emp;
    }
    if(emp->ssn < head->ssn ) {
        head->left = insertViaSSN(emp, head->left);
    }
    else if(emp->ssn > head->ssn) {
        head->right = insertViaSSN(emp, head->right);
    }
    return head;
}

Employee * insertViaID(Employee * emp, Employee * head) {
    if(head == NULL) {
        head = emp;
    }
    if(emp->empID < head->empID ) {
        head->left = insertViaID(emp, head->left);
    }
    else if(emp->empID > head->empID) {
        head->right = insertViaID(emp, head->right);
    }
    return head;

}
EmpDatabase insertEmp(Employee * emp, EmpDatabase database) {
    database.headTreeSortedBySSN = insertViaSSN(emp, database.headTreeSortedBySSN);
    Employee * temp = malloc(sizeof(Employee));
    temp->empID = emp->empID;
    temp->ssn = emp->ssn;
    temp->left = emp->left;
    temp->right = emp->right;
    database.headTreeSortedByID = insertViaID(temp, database.headTreeSortedByID);
    return database;
}

Employee * BSTwithHeadSSN(int ssn, Employee * head) {
    if(head == NULL) {
        return NULL;
    }
    if(head->ssn == ssn) {
        return head;
    }
    else if(ssn < head->ssn) {
        return BSTwithHeadSSN(ssn, head->left);
    }
    return BSTwithHeadSSN(ssn, head->right);

}

Employee * findEmpBySSN(int ssn, EmpDatabase database) {
    return BSTwithHeadSSN(ssn, database.headTreeSortedBySSN);
}

Employee * BSTwithHeadID(int id, Employee * head) {
    if(head == NULL) {
        return NULL;
    }
    if(head->empID == id) {
        return head;
    }
    else if(id < head->empID) {
        return BSTwithHeadID(id, head->left);
    }
    return BSTwithHeadID(id, head->right);

}
//NULL returned if employee not found
Employee * findEmpByID(int id, EmpDatabase database) {
    return BSTwithHeadID(id, database.headTreeSortedByID);
}
void freeBST(Employee * head) {
    if(head == NULL) {
        return;
    }
    freeBST(head->left);
    freeBST(head->right);
    free(head);
    head = NULL;
}
void freeEmpDatabase(EmpDatabase database) {
    freeBST(database.headTreeSortedByID);
    freeBST(database.headTreeSortedBySSN);
}