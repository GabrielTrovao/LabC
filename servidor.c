#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void criarUser(){
	system("cls");
	printf("criar user");
	getch();
}

void gerirStocks(){
}

void verStats(){
}

int login(){
  char user[100], pass[100];
	int correctLogin = 0;
  do {
  	system("cls");
    printf("username: ");
    scanf("%s", user);
		printf("password: ");
    scanf("%s", pass);
    /* usar unistd para read/write
		while not end of file
			pesquisar user
	    if user then
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

/* getOption(

*/
char getOption(char lower, char upper){
	char in;
	do{
		in = getch();
	}while(in < lower || in > upper);
	return in;
}

char menuLogin(){
  system("cls");
  printf( "1) Login\n"
					"2) Close\n");
  char in = getOption('1','2');
  if (in == '1') {
  	return login();
	} else return 0;
}

char menu() {
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
				option = menu();
		  }while(option != '4');
		}	
  }while(success);
	
	return 0;
}
