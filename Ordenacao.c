#include<stdio.h>

int main(){

	int vetor[10]= {0};
	int x = 0, aux = 0;

	printf("Entre com os 10 números na seguida....\n");
	
	for(int y=0; y < 10; y++){
		x = y+1;
		printf("Digite o %iº número:\n", x);
		scanf("%i",&vetor[y]);
	}

	for(int t=0; t < 10; t++){
		printf("%i  ", vetor[t]);
		
	}

	printf("\nOrdem dos números descritos: \n");


	for(int a = 0; a < 10 ; a++){

		for(int b = 0; b< 10; b++){
			
			aux = vetor[a];
			if(vetor[a] < vetor[b]){
			
				vetor[a] = vetor[b];
				vetor[b] = aux;
			}
		}
			
	}

	for(int t=0; t < 10; t++){
		printf("%i  ", vetor[t]);
		
	}
	

}


