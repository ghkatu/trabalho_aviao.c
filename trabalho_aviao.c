//// TRABALHO DE IP ////
//ALEC
//GABRIEL
//GUSTAVO
//WICTOR HUGO

//// AVIAO ///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LIN 33
#define COL 4
#define TRUE 1
#define FALSE 0
#define MAX 132

//DECLARACAO DE ESTRUTURAS:
typedef struct {
    int cod;
    char nome[40];
    char rg[10];
    char telefone[20];
    char email[40];
    char contato_emerg[40];
    char tel_contato[16];
    int cad;
    int fila;
    int Ocupado;
}passagem;

typedef struct{
    passagem viagem[LIN][COL];
    int qtde;
    unsigned int num_voo;
    char data[11];
    unsigned int hora;
    unsigned int minuto;
    char origem[20];
    char destino[20];
    char painel[LIN][COL];
    float valor;
}aviao;

// FUNCOES:

void Inicializar_Assentos(aviao *A){
	int i,j;
	for(i=0;i<LIN;i++){
		for(j=0;j<COL;j++){
			A->viagem[i][j].Ocupado=FALSE;
		}
	}	
}

void Inicializar_Painel(aviao *A){											//Inicia os valores da matriz de assentos com '.'(LIVRE)
	int i,j;
	for(i=0;i<LIN;i++){
		for(j=0;j<COL;j++){
			A->painel[i][j]='.';
		}
	}	
}
void legenda(){										//Legenda do painel
   printf("\n\n\n        .-Livre  X-Ocupado  \n\n");

}
void Mostrar_Painel(aviao A){									//Funcao para mostrar o painel de ocupacoes do aviao
	int i,j;
  printf("\n\n         %c   PAINEL DE OCUPACOES   %c\n\n",16,17);
  printf("          ");
  
  for(i=1;i<=COL;i++)
    printf("%d     ",i);
  
  for(i=1;i<=LIN;i++){
     printf("\n\n     %d",i);
     for(j=1;j<=COL;j++)
       printf("   (%c)",A.painel[i][j]);     
  }
  //apresenta a legenda na tela
  legenda();
  getch();
}
	

void iniciar_viagem(aviao *A){
    getchar();
    printf("\nPREENCHA OS DADOS DA VIAGEM\n");
    printf("Insira o numero do voo: ");
    scanf("%u", &(A->num_voo));
    printf("\n");

    getchar();
    printf("Qual a data da viagem: ");
    fgets(A->data, 11, stdin);
    printf("\n");

    getchar();
    printf("Qual a hora da viagem: ");
    scanf("%u", &A->hora);
    printf("\n");

    getchar();
    printf("Qual o minuto da viagem: ");
    scanf("%u", &(A->minuto));
    printf("\n");

    getchar();
    printf("Qual o local de origem da viagem: ");
    fgets(A->origem, 20, stdin);
    printf("\n");

    getchar();
    printf("Qual o local de destino da viagem: ");
    fgets(A->destino, 20, stdin);
    printf("\n");
    
    getchar();
    printf("Qual o valor da passagem do voo: ");
    scanf("%f",&A->valor);
    printf("\n");
    printf("Viagem registrada com sucesso!\n");
    getch();
}

void Adicionar_Passageiro(aviao *A){												
		int x=0;
        int cad, fila, aux=0;
        getchar();
        printf("\n ESCOLHA A OPCAO DE CADEIRA:\n [1] Janela \n [2] Corredor \n");
        printf("Opcao: "); scanf("%d", &aux);
        if(aux!=1 && aux!=2){
        	x=1;
        	while(x==1){
        		printf("CADEIRA INVALIDA, TENTE NOVAMENTE!\n");
        		printf("[1] Janela \n [2] Corredor\nCADEIRA: ");
        		printf("Opcao: "); scanf("%d", &aux);
        		if(aux==1 || aux==2)
        			x=0;
			}
		}

        if(aux==1){
            printf("\n [1] Lado esquerdo \n [2] Lado direito \n");
              printf("          Opcao: "); scanf("%d",&aux);
            
				if(aux!=1 && aux!=2){
        	x=1;
        	while(x==1){
        		printf("LADO INVALIDO, TENTE NOVAMENTE!\n");
        		printf("[1] Lado esquerdo \n [2] Lado direito \nLado: ");
        		scanf("%d",&aux);
        		if(aux==1 || aux==2)
        			x=0;
			}
		} 
            if(aux==1)
                cad=0;
            else if (aux==2)
                cad=3;
        }
        else if(aux==2){
            printf("\n [1] Lado esquerdo \n [2] Lado direito \n");
            scanf("%d", &aux);
            
            if(aux!=1 && aux!=2){
        	x=1;
        	while(x==1){
        		printf("LADO INVALIDO, TENTE NOVAMENTE!\n");
        		printf("[1] Lado esquerdo \n [2] Lado direito \nLado: ");
        		scanf("%d",&aux);
        		if(aux==1 || aux==2)
        			x=0;
			}
		}
            if(aux==1)
                cad=1;
            else if (aux==2)
                cad=2;
        }
        printf("\nCADEIRA ESCOLHIDA: %d\n",cad);
        
        

        printf("\n ESCOLHA A FILEIRA DE 1 a 33: ");
        scanf("%d", &fila);
			
			while(fila<1 || fila>33){
				printf("FILEIRA INVALIDA, TENTE NOVAMENTE!\n");
				printf("Fileira: ");
				scanf("%d",&fila);	
			}
		printf("\nFILEIRA ESCOLHIDA: %d\n",fila);
		
    fila--;
    cad--;
    
    A->painel[fila][cad]='X';
    A->viagem[fila][cad].Ocupado=TRUE;
    
    printf("\nCADASTRO DO PASSAGEIRO\n");
    
    getchar();
    printf("Insira o nome: ");
    fgets(A->viagem[fila][cad].nome, 40, stdin);
    printf("\n");

    getchar();
    printf("Insira o RG: ");
    fgets(A->viagem[fila][cad].rg, 10, stdin);
    printf("\n");

    getchar();
    printf("Insira o telefone com DDD: ");
    fgets(A->viagem[fila][cad].telefone, 16, stdin);
    printf("\n");

    getchar();
    printf("Insira o email: ");
    fgets(A->viagem[fila][cad].email, 40, stdin);
    printf("\n");

    getchar();
    printf("Insira o nome de um contato para emergencias: ");
    fgets(A->viagem[fila][cad].contato_emerg, 40, stdin);
    printf("\n");

    getchar();
    printf("Insira o telefone do contato de emergencia com DDD: ");
    fgets(A->viagem[fila][cad].tel_contato, 16, stdin);
    printf("\n");

	getchar();
	A->qtde++;
    A->viagem[fila][cad].cod=A->qtde;					//!
    printf("Passageiro adicionado com sucesso!\n");
    printf("Codigo do passageiro: %d\n",A->viagem[fila][cad].cod);
	getch();
}

void buscar_passageiro (aviao A){						//Busca pelo codigo "gerado" automaticamente ao passageiro na compra
	
	int c,i,j,cont=0;
	printf("Digite o codigo do passageiro: "); 
	scanf("%d",&c);
		for(i=0;i<LIN;i++){
			for(j=0;j<COL;j++){
				if(c==A.viagem[i][j].cod){
					printf("Passageiro de codigo %d encontrado!\n",c);
					printf("            DADOS           \n\n");
					printf("Nome: %s\n",A.viagem[i][j].nome);
					printf("RG: %s\n",A.viagem[i][j].rg);
					printf("Telefone: %s\n",A.viagem[i][j].telefone);
					printf("Email: %s\n",A.viagem[i][j].email);
					printf("Contato de Emergencia: %s\n",A.viagem[i][j].contato_emerg);
					printf("Telefone do Contato de Emergencia: %s\n",A.viagem[i][j].tel_contato);
					printf("Cadeira: %d\n",A.viagem[i][j].cad);
					printf("Fileira: %d\n",A.viagem[i][j].fila);
					cont++;
				}
				
			}
		}
			if(cont>=A.qtde)
				printf("Passageiro de codigo %d nao encontrado!\n\n",c);
		getch();	
}

void relatorio_vendas(aviao A){
	float Lucro;
	Lucro = A.valor*A.qtde;
	printf("Numero do voo: %u\n",A.num_voo);
	printf("Origem: %s\n",A.origem);
	printf("Destino: %s\n",A.destino);
	printf("Data: %s\n",A.data);
	printf("Horario do voo: %d:%d\n",A.hora,A.minuto);
	printf("Valor total arrecadado no voo: %.2f\n",Lucro);
	system("pause");
}

void lista_passageiros(aviao A){
	int Loop=TRUE;
	int i=0,j=0,cont=0;
		if(A.qtde>0){
		
		for(i=0;i<LIN;i++){
			for(j=0;j<COL;j++){
					if(A.viagem[i][j].Ocupado==TRUE){
					
					printf("********************************************************\n");
					printf("CODIGO DO PASSAGEIRO: %d\n",A.viagem[i][j].cod);
					printf("            DADOS           \n\n");
					printf("Nome: %s\n",A.viagem[i][j].nome);
					printf("RG: %s\n",A.viagem[i][j].rg);
					printf("Telefone: %s\n",A.viagem[i][j].telefone);
					printf("Email: %s\n",A.viagem[i][j].email);
					printf("Contato de Emergencia: %s\n",A.viagem[i][j].contato_emerg);
					printf("Telefone do Contato de Emergencia: %s\n",A.viagem[i][j].tel_contato);
					printf("Cadeira: %d\n",A.viagem[i][j].cad);
					printf("Fileira: %d\n",A.viagem[i][j].fila);
					cont++;
					}
				}			
			}
			getch();
	}
	
	else{
		printf("********************Nao ha passageiros no voo.*********************\n");
		getch();
	}
}




// MENU:

/*void menu(){
    printf("\n******MENU*******\n");
    printf("ESCOLHA UMA DAS OPCOES A SEGUIR\n");
    printf("[1] INICIAR VIAGEM \n");
    printf("[2] VENDER PASSAGEM \n");
    printf("[3] RELATORIO DE VENDAS \n");
    printf("[4] CONSULTAR PASSAGEIRO \n");
    printf("[5] LISTA DE PASSAGEIROS \n");
    printf("[6] SAIR \n");
}*/

int menuOpcao(aviao A){
    int opcao=6;
    do {
         system("cls"); 
         printf("\n\n                      MENU   \n\n",16,17);
        
         printf("                  1- Iniciar Viagem        \n\n");
        
         printf("                  2- Vender Passagem       \n\n");
        
         printf("                  3- Relatorio de Vendas \n\n");
        
         printf("                  4- Consultar Passageiro           \n\n");
         
         printf("                  5- Listar Passageiros   (%d Assentos Ocupados)        \n\n",A.qtde);
         
         printf("                  6- Mostrar Painel De Ocupacoes do Voo           \n\n");
         
         printf("                  7- Sair          \n\n",16,17);
        
         printf("                   opcao: ");scanf("%d",&opcao);
         
         if(opcao <= 0 || opcao > 7){
            printf("\n\n\n    DIGITE APENAS VALORES CORESPONDENTES AO MENU !!");
            getch();
         }
            
     }while(opcao <= 0 || opcao > 7);
    
    return opcao;
}


int main(){
	
	aviao A;
	A.qtde=0;
	int opcao;
	int loopContinue=TRUE;
	Inicializar_Assentos(&A);
	Inicializar_Painel(&A);
	
		do{
     system("cls");              
     opcao=menuOpcao(A);                   
     switch(opcao){
        case 1: 	
		system("cls");
					iniciar_viagem(&A);
					break;
					
		case 2:		
		system("cls");
					Adicionar_Passageiro(&A);
					break;
					
		case 3:     
		system("cls");
					relatorio_vendas(A);
					break;
					
		case 4: 	
		system("cls");
					buscar_passageiro(A);
					break;
					
		case 5:     
		system("cls");
					lista_passageiros(A);
					break;
					
		case 6: 
		system("cls");
					Mostrar_Painel(A);
					break;
		case 7:		
					system("cls");
					printf("ENCERRANDO O PROGRAMA\n");
					loopContinue=FALSE;			
     }
  }while(loopContinue);

  return 0;       
}

