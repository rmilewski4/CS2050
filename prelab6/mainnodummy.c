#include "prelab6nodummy.h"

int main(void) {
    List * empList; 
    int ec;  
    empList = initList(&ec); 
    Employee *emp; 
    FILE * fp;
    fp = fopen("employee.txt","r");
    for (int i=0; i<5; i++) {  
        emp = malloc(sizeof(Employee)); 
        readEmpRecordFromFile(fp, emp);   // Read employee struct 
        empList=insertAtHead(emp, empList, &ec); // Put it at head of list 
    } 
    fclose(fp);
    int counter = 0;
    List * p = NULL;
    for(p = empList;p != NULL; p = p->next) {
        int EmpID = ((Employee *) p->object)->empID;
        float salary = ((Employee *) p->object)->salary;
        printf("Node %d.id = %d, Node %d.salary = %f, Node->Next = %p\n",counter,EmpID,counter,salary,p->next);
        counter++;
    }
    emp = getAtIndex(1,empList);
    printf("emplist = %p\n",emp);
    printf("Details from Node %d\nid = %d, salary = %f\n",1,emp->empID,emp->salary);
    printf("The list is %d nodes long\n",getListLength(empList));
    freeEmployees(empList);
    empList = freeList(empList); 
}