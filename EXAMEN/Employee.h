#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#define EMPLOYEE_TYPE_ARCHITECT    0
#define EMPLOYEE_TYPE_MANAGER      1
#define EMPLOYEE_TYPE_DESIGNER     2
#define EMPLOYEE_TYPE_JUNIOR       3
#define EMPLOYEE_TYPE_PROGRAMMER   4

struct
{
    int id;
    char name[51];
    char lastName[51];
    int age;
    int type;
}typedef Employee;

Employee* emp_new(int id, char* name, char* lastname, int age, int type);
int emp_delete(Employee* this);
int emp_setNombre(Employee* this,char* name);
char* emp_getNombre(Employee* this);
int emp_setApellido(Employee* this,char* lastname);
char* emp_getApellido(Employee* this);
int emp_setAge(Employee* this,int age);
int emp_getAge(Employee* this);
int emp_setId(Employee* this,int id);
int emp_getId(Employee* this);
int emp_setType(Employee* this,int type);
int emp_getType(Employee* this);
Employee* emp_findById(ArrayList* pArrayEmployee, int id);
void employee_print(Employee* this);
int employee_filterEmployee(void* item);

#endif // _EMPLOYEE_H



