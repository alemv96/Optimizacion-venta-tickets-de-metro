// TicketsProyecto.cpp : Defines the entry point for the console application.
//DATE: 21/07/2017

#include "stdio.h"
#include "stdlib.h"
#include "Lista.h"

/*Functions of my program*/
void ID_Entry();
void User_Menu();
void Get_Divided_ID(int id);

Lista *turnos = NULL;

void User_Menu() {
	int option;

	do {
		printf("----> Pulse tecla 1 para ingresar nueva cedula \n");
		printf("----> Pulse tecla 2 para mostrar el siguiente turno\n");
		printf("----> pulse 3 para salir del sistema \n");
		scanf("%i", &option);

		if (option == 1) ID_Entry();
		else if (option == 2) mostrar(turnos);
		else {
			system("cls");
			printf("Hasta luego\n");
			system("pause");
		}
	} while ((option == 1) || (option == 2));
}

void ID_Entry() {
	int id;

	system("cls");
	printf("Introduzca la cedula de identidad\n");
	scanf("%i", &id);
	Get_Divided_ID(id);
}

void Get_Divided_ID(int id) {
	/*while id != 0*/
	int turno = 0;
	int residue = 0 , exitCycle = 0;
	int result = 0;
	//int num = id;
	
	/*while (num != 0) {	
		for (int i = 0; i != 3; i++) {
			if (num != 0) {
				int n = num % 10;
				num = num / 10;
				result = (result * 10) + n;
			}
		}
		turno += result;
		result = 0;
	}
*/
	__asm {
		For_Cycle:
			MOV eax, exitCycle
			CMP eax, 3
			JA Inner_For
			CMP eax, 3
			JE While_Cycle			
		
		Inner_For:
			MOV eax, id
			CMP eax, 0
			JNE Get_Result
			CMP eax, 0
			JE While_Cycle

		Get_Result:
			MOV eax, id 
			MOV ecx, 10
			DIV ecx
			MOV residue, edx
			MOV id, eax
			
			MOV eax, result
			MUL ecx
			ADD eax, residue
			MOV result, eax

			MOV eax, exitCycle
			INC eax
			MOV exitCycle, eax
			JMP For_Cycle

		While_Cycle:
			MOV eax, turno
			MOV ebx, result
			ADD eax, ebx
			;MOV ebx, 0
			MOV turno, eax
			MOV result, 0
			MOV exitCycle, 0
			MOV eax, id
			CMP eax, 0
			JNE For_Cycle

	}
		
	insertar(&turnos, turno);
	printf("Cedula a~adida con exito al sistema");
	system("pause");
	
}

void main()
{
	User_Menu();
}

