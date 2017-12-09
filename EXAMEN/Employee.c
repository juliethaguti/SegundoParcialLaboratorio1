#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"



Employee* emp_new(int id, char* name, char* lastname, int age, int type)
{
    Employee* nuevoEmployee = malloc(sizeof(Employee));
    emp_setNombre(nuevoEmployee,name);
    emp_setApellido(nuevoEmployee,lastname);
    emp_setAge(nuevoEmployee,age);
    emp_setId(nuevoEmployee,id);
    emp_setType(nuevoEmployee,type);

    return nuevoEmployee;
}

int emp_delete(Employee* this)
{
    free(this);
    return 0;
}



int emp_setNombre(Employee* this,char* name)
{
    strcpy(this->name,name);
    return 0;
}


char* emp_getNombre(Employee* this)
{
    return this->name;
}


int emp_setApellido(Employee* this,char* lastname)
{
    strcpy(this->lastName,lastname);
    return 0;
}


char* emp_getApellido(Employee* this)
{
    return this->lastName;
}


int emp_setAge(Employee* this,int age)
{
    this->age = age;
    return 0;
}


int emp_getAge(Employee* this)
{
    return this->age;
}


int emp_setId(Employee* this,int id)
{

    this->id = id;
    return 0;
}

int emp_getId(Employee* this)
{
    return this->id;
}

int emp_setType(Employee* this,int type)
{

    this->type = type;
    return 0;
}

int emp_getType(Employee* this)
{
    return this->type;
}


Employee* emp_findById(ArrayList* pArrayEmployee, int id)
{
    int i;
    Employee *auxEmployee;
    void* retorno=NULL;

    for(i=0;i<al_len(pArrayEmployee);i++)
    {
        auxEmployee = al_get(pArrayEmployee,i);
        if(id == auxEmployee->id)
        {
            retorno = auxEmployee;
            break;
        }
    }

    return retorno;
}


void employee_print(Employee* this)
{
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - AGE: %d - TYPE: %d\n",emp_getNombre(this),
                            emp_getApellido(this),emp_getId(this),emp_getAge(this),emp_getType(this));
}

int employee_filterEmployee(void* item)
{
    int retorno = 0;
    int age;
    age = emp_getAge((Employee*)item);
    int type = emp_getType((Employee*)item);

    if(30 < age && type == EMPLOYEE_TYPE_PROGRAMMER)
    {
        retorno = 1;
    }

    return retorno;
}




