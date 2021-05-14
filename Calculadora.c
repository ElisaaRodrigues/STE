#include<stdio.h>

int main(){
	
	int n1, n2;
	int opcao, resultado;

	printf("Entre com os dois valores:\n");
	scanf("%i %i", &n1, &n2);

	printf("Digite:\n1 para soma\n2 para subtração\n3 para multiplicação\n4 para divisão\n");
	scanf("%i", &opcao);

	switch(opcao){

		case 1:
			resultado = n1+n2;
			break;

		case 2:
			resultado = n1-n2;
			break;

		case 3:

			resultado = n1*n2;
			break;

		case 4: 
			resultado = n1/n2;
			break;
			
	}

	
	printf("O resultado é: %i\n", resultado);


}
