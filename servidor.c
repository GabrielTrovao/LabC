#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


/*	criarUser
 * 	desc
*/
void criarUser(){
	system("cls");
	printf("criar user");
	getch();
}

/*	gerirStocks
 * 	desc
*/
void gerirStocks(){
	system("cls");
	printf("gerir stocks");
	getch();
}

/*	verStats
 * 	desc
*/
void verStats(){
	system("cls");
	printf("ver stats");
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
    printf("username: ");
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
  
  return 1;
}

/*	getOption
 * 	Lê input do utilizador até ser válido
 *  O input é válido quando se encontra entre lower e upper
 *  Isto elimina a necessidade de reescrever menus quando o input lido é inválido
 *  e a de reescrever este ciclo sempre que se 
 *  ex: getOption('1','4') devolve apenas '1', '2', '3' ou '4'
*/
char getOption(char lower, char upper){
	char in;
	do{
		in = getch();
	}while(in < lower || in > upper);
	return in;
}

/*	menuLogin
 * 	desc
*/
char menuLogin(){
  system("cls");
  printf( "**Menu**\n"
					"1) Login\n"
					"2) Close\n");
  char in = getOption('1','2');
  if (in == '1') {
  	return login();
	} else return 0;
}

/*	menuAdmin
 * 	desc
*/
char menuAdmin() {
	system("cls");
  printf( "**Menu**\n"
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
	  	return in;
			break;
		}
		default: break;
	}
}

int main(){
	char option;
	int success;
  
	do{
		success = menuLogin(); 
		if (success) {
		  do {
				option = menuAdmin();
		  }while(option != '4');
		}	
  }while(success);
	
	return 0;
}
