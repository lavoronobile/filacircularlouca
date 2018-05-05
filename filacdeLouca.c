
#include <stdio.h>
#include <stdlib.h>


struct Fila {

	int capacidade;
	char *louca;
	int primeiro;
	int ultimo;
	int nItens; 

};

void criarFila( struct Fila *f, int c ) { 

	f->capacidade = c;
	f->louca = (char*) malloc (f->capacidade * sizeof(char));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 
}
void inserir(struct Fila *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->louca[f->ultimo] = v; 
	f->nItens++;

}

 int remover( struct Fila *f ) {

	int temp = f->louca[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  
	return temp;

}

int estaVazia( struct Fila *f ) { 

	return (f->nItens==0);

}

int estaCheia (struct Fila * f ) {

     return (f->nItens == f->capacidade );
}

void mostrarFila (struct Fila *f) {
    int cont ;
    int i ;

       for ( cont =0 , i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\t",f->louca[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");
}


  void main (){


        int opcao, capa;
	char loucasuja;
	struct Fila filaLouca;

	
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&filaLouca, capa);


	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // inserindo elemento na fila de louca
				if (estaCheia(&filaLouca)){

					printf("\n a pia está cheia de louça , lave você mesmo!!!\n\n");

				}
				else {

					printf("\n insira a louça que você vai lavar ! ");
					scanf("%c", &loucasuja);
					inserir(&filaLouca,loucasuja);

				}

				break;

			case 2: // removendo elemento da fila de louça
				if (estaVazia(&filaLouca)){

					printf("\n UFA ! Lavei toda a loça !!!\n\n");

				}
				else {

					loucasuja = remover(&filaLouca);
					printf("\n%1f estava com preguiça e lavei apenas o último ítem da pia \n\n", loucasuja) ; 

				}          
                                break;

				case 3: // mostrando a fila de louça 
					if (estaVazia(&filaLouca)){

						printf("\n toda a louça está lavada!!!\n\n");

					}
					else {

						printf("\nConteudo da fila => ");
						mostrarFila(&filaLouca);

					}
					break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}     



}
