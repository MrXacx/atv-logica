#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 3

int vet[TAM][TAM],i,a;

void clear(void);
void inputQuadrado();
bool validaQuadrado();

main(){
	bool aux;
	inputQuadrado(&vet[TAM][TAM]);
	clear();
	aux = validaQuadrado();
	switch(aux){
		case true:
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
void inputQuadrado(int *vet[TAM][TAM]){
	int j,z;
	bool aux;
	for(i=0;i<TAM;i++){
		for(a=0;a<TAM;a++){
			do{
				clear();
				printf("Adicione o valor da celula %dx%d: ",i+1,a+1);
				scanf("%d",&vet[i][a]);
				aux = false;
				for(j=0;j<=i;j++){
					for(z=0; z<=a+1;z++){
						if(vet[i][a] == vet[j][z] && (j!=i || z!=a)){
							aux = true;
						}
					}
				}
			} while(aux == true);
		}
	}
}

bool validaQuadrado(){
	int dp,ds,lin[TAM],col[TAM];
	
 for(i=0;i<TAM;i++){
 	for(a=0;a<TAM;a++){
 		lin[i] = lin[i] + vet[i][a]; // realiza a soma dos elementos de cada linha
 		col[i] = col[i] + vet[a][i]; // realiza a coma dos elementos de cada coluna

 	}
 	dp = dp + vet[i][i]; // realiza a soma dos elementos da diagonal principal
 }
  
 a = 0;
 for(i=TAM-1;i>=0; i--){
 	if(i==a){
 		ds = ds + vet[i][i]; // evita soma em excesso
 	}
 	else{
 		ds = ds + vet[i][a] + vet[a][i]; // soma elementos da diagonal secundaria
 	}
 	a++;
 }
 
 switch(dp != ds){ // compara diagonais
 	case true: 
 		return false;
 	break;
 	default: // diagonais sao iguais
 		 for(i=0;i<TAM;i++){
 			if(lin[i] != dp || col[i] != dp){ // compara diagonal com a soma decada linha e a soma de cada coluna
 				return false;
 			}
 			else{ // ds, 
 	
 				a = 1;
 			}
 		}
 		if(a==1){ return true;}
 }
}
