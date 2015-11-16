#include <stdio.h>
#include <string.h>

void print_menu( void );
void add_new( void );
void find( void );

int main(int argc, char const *argv[]){

	int quit = 1; 
	char answer;

	while(quit != 0){
		print_menu();
		answer = getchar();
		switch(answer){
			case '1':
				add_new();
				break;
			case '2':
				find();
				break;
			case '0':
				quit = 0;
			default:
				break;
		}
	}
}

void print_menu(){
	printf("1. Add new.\n");
	printf("2. Find.\n");
	printf("0. Exit.\n");
	return;
}

void add_new(){
	FILE *fp;
	char service[20], username[20], password[20];

	printf("Give service.\n");
	scanf("%s", service);
	getchar();

	printf("Give username.\n");
	scanf("%s", username);
	getchar();

	printf("Give password.\n");
	scanf("%s", password);
	getchar();

	fp = fopen("storage.txt", "a+");
	fprintf(fp, "%s %s %s\n", service, username, password );
	fclose(fp);
}

void find(){
	FILE *fp;
	char service[20], service_to_find[20], username[20], password[20];

	printf("Give service\n");
	scanf("%s", service_to_find);
	getchar();

	fp = fopen("storage.txt", "r");

	while(fscanf(fp, "%s %s %s", service, username, password) != EOF){
		if(strcmp(service, service_to_find) == 0){
			printf("Service: %s\nUsername: %s\nPassword: %s\n", service, username, password);
			return;
		}
	}
	printf("Service not found!\n");
	return;
}