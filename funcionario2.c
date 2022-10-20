#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
int TAM=50;
struct ficha_funcionario_empresa{
	char nome[30];
	int cpf;
	float salario;
};

void adiciona_funcionario(struct ficha_funcionario_empresa funcionario[TAM]){
	fflush(stdin);
	printf("Informe o nome do funcionario: ");
	gets(funcionario[i].nome);
	printf("Informe o cpf do funcionario: ");
	scanf("%d",&funcionario[i].cpf);
	printf("Informe o salario do funcionario: ");
	scanf("%f",&funcionario[i].salario);
}

int busca_funcionario(int resp, struct ficha_funcionario_empresa funcionario[TAM]){
	int k;
	for(k=0; k<i; k++){
		if(resp==funcionario[k].cpf){
			return k;	
		}
	}
	return -1;
}
void verificar_funcionario(int cpf, struct ficha_funcionario_empresa funcionario[TAM]){
	int posicao = busca_funcionario(cpf, funcionario);
	if(posicao==-1){
		printf("FUNCIONARIO NAO CADASTRADO");
	}
	else{
		printf("Nome: %s \n", funcionario[posicao].nome);
		printf("Cpf: %d\n", funcionario[posicao].cpf);
		printf("Salario: %.1f", funcionario[posicao].salario);
	}
	
}

void remover_funcionario(int cpf, struct ficha_funcionario_empresa funcionario[TAM]){
	int posicao = busca_funcionario(cpf, funcionario);
	if(posicao==-1){
		printf("FUNCIONARIO NAO CADASTRADO");
	}
	else{
		strcpy(funcionario[posicao].nome,"");
		funcionario[posicao].cpf = 0;
		funcionario[posicao].salario = 0;
	}
	printf("FUNCIONARIO REMOVIDO");
}
void imprimir_funcionarios(truct ficha_funcionario_empresa funcionario[TAM]){
    int k;
    for(k=0; k<i; k++){
        printf("--------------------------\n");
        printf("Nome: %s", funcionario[k].nome);
        printf("\nNome: %d", funcionario[k].cpf);
        printf("\nNome: %.2f", funcionario[k].salario);
        printf("\n");
    }
}
void menu(){
	printf("1 - Adiciona funcionario");
	printf("\n2 - Remove funcionario");
	printf("\n3 - Busca funcionario");
	printf("\n4 - Imprime funcionarios");
	printf("\n0 - Sair\n");
}
void main(){
	struct ficha_funcionario_empresa funcionario[TAM];
	int op, cpf;
	i=0;
	do{
		menu();
		scanf("%d",&op);
		if(op==1){
			system("cls");
			printf("CADASTRAR FUNCIONARIO\n");
			adiciona_funcionario(funcionario);
			printf("\nFUNCIONARIO CADASTRADO\n");
			system("pause");
			i++;
		}
		else if(op==2){
			system("cls");
			printf("Informe o CPF: ");
			scanf("%d",&cpf);
			remover_funcionario(cpf, funcionario);
			system("pause");	
		}
		else if(op==3){
			system("cls");
			printf("Informe o CPF: ");
			scanf("%d",&cpf);
			verificar_funcionario(cpf, funcionario);
			system("pause");
		}
		else if(op==4){
		    system("cls");
		    imprimir_funcionarios(funcionario);
		    system("pause");
		}
		system("cls");
	}while(op!=0);
}
