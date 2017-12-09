#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "Validaciones.h"


int parserEmployee(ArrayList* pArrayListEmployee)
{
    FILE *pFile;
	Employee* auxEmployee;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("data.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarDescripcion(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)
				{
					auxEmployee=emp_new(atoi(var1), var2, var3,atoi(var4), atoi(var5));
					al_add(pArrayListEmployee, auxEmployee);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}
