#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Lista {

	int id;
	int turno;
	Lista *prox;
};

Lista *Crear(int turno, int id) {

	Lista *T = new Lista;
	T->id = id;
	T->turno = turno;
	T->prox = NULL;
	return T;
}

void insertar(Lista **P, int turno, int id) {

	Lista *T = Crear(turno, id);
	T->prox = *P;
	*P = T;
}


void eliminarTurno(Lista **P, int x) {

	Lista *T = *P, *Aux;
	if (T) {
		if (T->turno == x) {
			*P = (*P)->prox;
			delete T;
		}
		else
		{
			while ((T->prox) && (T->prox->turno != x)) {
				T = T->prox;
			}
			if (T->prox) {
				Aux = T->prox;
				T->prox = T->prox->prox;
				delete Aux;
			}
		}
	}

}


void ordenarLista(Lista *p)
{
	Lista *actual, *siguiente;
	int t;

	actual = p;
	while (actual->prox != NULL)
	{
		siguiente = actual->prox;

		while (siguiente != NULL)
		{
			if (actual->turno > siguiente->turno)
			{
				t = siguiente->turno;
				siguiente->turno = actual->turno;
				actual->turno = t;
			}
			siguiente = siguiente->prox;
		}
		actual = actual->prox;
		siguiente = actual->prox;
	}
}

void mostrar(Lista *P) {
	if (P) {
		ordenarLista(P);
		printf("\n\Turnos: \n\n");
		while (P) {
			printf("Turno: %i (CI: %i)\n", P->turno, P->id);
			P = P->prox;
		}
	}
}

void eliminar(Lista **p) {

	if ((*p) != NULL) {
		Lista *aux;
		aux = (*p);
		(*p) = (*p)->prox;
		eliminar(p);
		delete aux;
	}
	
}