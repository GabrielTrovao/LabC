#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/* Forward declarations */
char getOption(char lower, char upper);

/* Global vars*/
int itemCount = 0;

typedef struct Item{
	int codigo;
	char nome[100];
	int quantidade;
	int custo;
	int preco;
	char desc[200];
} Item;

typedef struct User{
	char nome[100];	
	int contacto;
	char username[100];
	char password[100];
} User;


/*	findUsername
 * 	desc
*/
int findUsername(char username[]){
	return 0;
}

/*	getItemByCode
 * 	desc
*/
Item getItemByCode(int code){
	Item i;
	return i;
}

/*	getItemByDesc
 * 	desc
*/
Item getItemByDesc(char desc[]){
	Item i;
	return i;
}

/*	writeToFile
 * 	desc
*/
void writeToFile(FILE * f, User u);

/*	criarUser
 * 	desc
*/
void criarUser(){
	User newUser;
	
	system("cls");
	printf( "**Criar Novo Utilizador**\n"
					"Username: ");
	scanf("%s", newUser.username);
	
	if ( !findUsername(newUser.username) ){
		printf("Password: ");
		scanf("%s", newUser.password);
		printf("Nome: ");
		scanf("%s", newUser.nome);
		printf("Contacto: ");
		scanf("%d", &newUser.contacto);
		
		//writeToFile(file, newUser)
		
		printf( "\nUtilizador criado com sucesso.\n");
		
	} else printf("\nUtilizador ja existe.\n");
	
	fflush(stdin);
	getch();
}

/* temp function from rosettacode */
int isNumeric (const char * s){
    if (s == NULL || *s == '\0' || isspace(*s))
      return 0;
    char * p;
    strtod (s, &p);
    return *p == '\0';
}

/*	criarItem
 * 	desc
*/
void criarItem(){	
	Item newItem;
	system("cls");
	printf("**Adicionar novo produto ao stock**\n");

	do{
		printf("Codigo: ");
		scanf("%d", &newItem.codigo);
	}while(newItem.codigo != (itemCount + 1)); // validar código? Tem que ser sequencial, fazia mais sentido atribuir atuomaticamente
	printf("Descricao: ");
	scanf("%s", newItem.desc);
	printf("Quantidade: ");
	scanf("%d", &newItem.quantidade);
	printf("Custo: ");
	scanf("%d", &newItem.custo);
	printf("Preco: ");
	scanf("%d", &newItem.preco);
	
	//writeToFile(stock, newItem);
	printf("\nProduto adicionado com sucesso.\n");
	
	fflush(stdin);
	getch();
}

/*	alterarItem
 * 	desc
*/
void alterarItem(){
	Item oldItem, newItem;
	char input[100];

	system("cls");
	printf("**Alterar produto do stock**\n"
				 "Insira o codigo ou nome do produto que quer alterar\n");
	
	scanf("%s", input);
	if ( isNumeric(input) ) {
		oldItem = getItemByCode( atoi(input) );
	} else {
		oldItem = getItemByDesc( input );
	}
	
	// validar os getItems para quando falhar
	
	newItem = oldItem;
	
	printf("\nProduto encontrado\n\n"
				 "Novos dados:\n");
	printf("Quantidade: ");
	scanf("%d", &newItem.quantidade);
	printf("Preco: ");
	scanf("%d", &newItem.preco);
	printf("Custo: ");
	scanf("%d", &newItem.custo);
	
	// writeToFile(stock, newItem);
	
	fflush(stdin);
	getch();
}

/*	eliminarItem
 * 	desc
*/
void eliminarItem(){
	system("cls");
	printf("**Eliminar produto do stock**\n");
	// puxar todas as linhas seguintes do ficheiro stock para trás
	getch();
}


/*	menuStocks
 * 	desc
*/
void menuStocks(){
	system("cls");
	printf("**Gerir Stocks**\n"
				 "1) Adicionar novo produto\n"
				 "2) Alterar produto em stock\n"
				 "3) Eliminar produto do stock\n"
				 "4) Voltar atras\n");
}

/*	gerirStocks
 * 	desc
*/
void gerirStocks(){
	char option;

	do{
		menuStocks();
		option = getOption('1','4');
		switch(option){
			case '1': {
				criarItem();
				break;
			}
			case '2': {
				alterarItem();
				break;
			}
			case '3': {
				eliminarItem();
				break;
			}
			default : break;
		}
	}	while( option != '4' );
	
}

/*	verStats
 * 	desc
*/
void verStats(){
	system("cls");
	printf("**Estatisticas**");
	// fazer print ao ficheiro com as estatisticas
	getch();
}

/*	login
 * 	desc
*/
int login(){
  char user[100], pass[100];
	int correctLogin = 0;
  
	do {
  	system("cls");
    printf("**Login**\n"
				   "username: ");
    scanf("%s", user);
    /* usar unistd para read/write */
    /*
		while not end of file
			pesquisar user
	    if user then
	    	printf("password: ");
    		scanf("%s", pass);
	    	pesquisar password
	    	if password
	    		return 1
	    	else login
			else login
    */
    correctLogin = 1;
  }while(!correctLogin);
  
  fflush(stdin);
  return 1;
}

/*	getOption
 * 	Lê input do utilizador até ser válido.
 *  O input é válido quando se encontra entre lower e upper.
 *  Isto elimina a necessidade de reescrever menus quando o input é inválido
 *  e a de reescrever este ciclo sempre que se dá opções ao utilizador.
 *  ex: getOption('1','4') devolve apenas '1', '2', '3' ou '4'.
*/
char getOption(char lower, char upper){
	char in;
	do{
		in = getch();
	}while(in < lower || in > upper);
	return in;
}

/*	menuLogin
 * 	Escreve o menu na shell e inicia o login do utilizador
 *  ou termina o programa.
 *  Chama getOption para ler input do utilizador.
*/
char menuLogin(){
  system("cls");
  printf("**Menu**\n"
				 "1) Login\n"
				 "2) Close\n");
  char in = getOption('1','2');
  if (in == '1') {
  	return login();
	} else return 0;
}

/*	menuAdmin
 * 	Escreve o menu na shell e chama getOption para ler input do utilizador.
 *  Chama a função correspondente à opção do utilizador.
*/
char menuAdmin() {
	system("cls");
  printf("**Menu**\n"
				 "1) Criar Novo Utilizador\n"
				 "2) Gerir Stocks\n"
				 "3) Ver Estatisticas\n"
				 "4) Logout\n");
  char in = getOption('1','4');
  switch(in){
		case '1': { 
			criarUser(); 
			break; 
		}
	  case '2': {
			gerirStocks(); 
			break; 
		}
	  case '3': { 
			verStats(); 
			break; 
		}
	  case '4': {
	  	return 1;
			break;
		}
		default: break;
	}
	return 0;
}

int main(){
	int success, logout;

	// Inicializar itemCount 

	do{
		success = menuLogin();   /* 1 se o login for efetuado com sucesso. */
		if (success) {  			   /* 0 se o utilizador terminar a sessão. */
		  do {
				logout = menuAdmin(); 
		  }while( !logout );
		}	
  }while( success );  
	
	return 0;
}
