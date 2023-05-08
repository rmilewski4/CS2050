#include "prelab11.h"

void printEmployee(Employee * emp) {
    printf("SSN: %d\t, empID: %d\n",emp->ssn,emp->empID);
}
void inorder(Employee * head) {
    if(head != NULL) {
        inorder(head->left);
        printf("%d \n",head->empID);
        inorder(head->right);
    }
}
Employee *  newNode(int empID, int ssn) {
    Employee * newnode = malloc(sizeof(Employee));
    newnode->empID = empID;
    newnode->ssn = ssn;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main(void) {
    EmpDatabase database = createSearchableEmployeeDB();

    /*for(int i = 0; i< 10; i++) {
        Employee * emp = malloc(sizeof(Employee));
        int random = rand() % 50;
        emp->ssn = random;
        random = rand() % 50;
        emp->empID = random;
        emp->left = NULL;
        emp->right = NULL;
        database = insertEmp(emp, database);
    }*/
    Employee * temp = newNode(25,30);
    database = insertEmp(temp,database);
    temp = newNode(22,45);
    database = insertEmp(temp, database);
    temp = newNode(23,40);
    database = insertEmp(temp, database);
    inorder(database.headTreeSortedByID);
    Employee * emp = malloc(sizeof(Employee));
    emp->ssn = 2;
    emp->empID = 49;
    emp->left = NULL;
    emp->right = NULL;
    database = insertEmp(emp, database);
    emp = findEmpByID(23, database);
    printEmployee(emp);
    emp = findEmpBySSN(46, database);
    if(emp != NULL) {
    printEmployee(emp);
    }
    else {
        printf("Could not find employee with that SSN!\n");
    }
    freeEmpDatabase(database);
}