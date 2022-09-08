#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int vet[TAM][TAM];

void clear(void);
void inputQuadrado(int vet[TAM][TAM]);
int validaQuadrado(int vet[TAM][TAM]);

int main(void){
	int aux;
	inputQuadrado(&vet[TAM][TAM]);
	clear();
	aux = validaQuadrado(&vet[TAM][TAM]);
	switch(aux){
		case 1:
			printf("A matriz apresentada eh um quadrado magico");
		break;
		default:
			printf("A matriz apresentada nao eh um quadrado magico");
	}
}
void clear(void){
	#ifdef __linux__
		system("clear");

	#elif 
		system("cls");
	#endif
}
void inputQuadrado(int vet[TAM][TAM]){
	int aux,i,a,j,z;
	for(i=0;i<TAM;i++){
		for(a=0;a<TAM;a++){
			do{
				clear();
				printf("Adicione o valor da celula %dx%d: ",i+1,a+1);
				scanf("%d",&vet[i][a]);
				aux = 0;
				for(j=0;j<=i;j++){
					for(z=0; z<=a+1;z++){
						if(vet[i][a] == vet[j][z] && (j!=i || z!=a)){
							aux = 1;
						}
					}
				}
			} while(aux == 1);
		}
	}
}
int validaQuadrado(int vet[TAM][TAM]){
	int i,a,dp,ds,lin[TAM],col[TAM];
	dp=0;
 for(i=0;i<TAM;i++){
 	lin[i] = 0;
 	col[i]=0;
 	for(a=0;a<TAM;a++){
 		lin[i] = lin[i] + vet[i][a]; // realiza a soma dos elementos de cada linha
 		
 		col[i] = col[i] + vet[a][i]; // realiza a coma dos elementos de cada coluna
 	}
 	dp = dp + vet[i][i]; // realiza a soma dos elementos da diagonal principal
}
 a = 0; ds =0;
 for(i=TAM-1;i>=0; i--){
 	ds = ds + vet[i][a]; // soma elementos da diagonal secundaria
 	a++;
} 
 switch(dp != ds){ // compara diagonais
 	case 1: 
 		return 0;
 	break;
 	default: // diagonais sao iguais
 		 for(i=0;i<TAM;i++){
 			if(lin[i] != dp || col[i] != dp){ // compara diagonal com a soma decada linha e a soma de cada coluna
 				return 0;
 			}
 			else{ // ds, 
 				a = 1;
 			}
 		}
 		if(a==1){ return 1;}
 }
}
