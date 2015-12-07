#include <stdio.h>
#include <string.h>

#define FILENAME "storage.txt"
#define LENGTH 35

void print_menu( void );
void add_new( void );
void find( void );
void print_all( void );

int main(int argc, char const *argv[]){

	int quit = 1; 																				// Checks when to terminate execution
	char answer;																				// Action answered by user

	while(quit != 0){
		print_menu();																			// Prints actions menu
		answer = getchar();																		// Gets the answer
		switch(answer){
			case '1':
				add_new();
				break;
			case '2':
				find();
				break;
			case '3':
				print_all();
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
	printf("3. Print all\n");
	printf("0. Exit.\n");
	return;
}

// Adds a new service
void add_new(){
	FILE *fp;
	char service[LENGTH], username[LENGTH], password[LENGTH];

	printf("Give service.\n");																	//
	scanf("%s", service);																		//
	getchar();																					//
																								//
	printf("Give username.\n");																	//
	scanf("%s", username);																		// Reads the information to add the new service
	getchar();																					//
																								//
	printf("Give password.\n");																	//
	scanf("%s", password);																		//
	getchar();																					//
	fp = fopen(FILENAME, "a+");																	//
	fprintf(fp, "%s %s %s\n", service, username, password );									// Stores the new service in database
	fclose(fp);																					//
}

// Finds an existing service
void find(){
	FILE *fp;
	char service[LENGTH], service_to_find[LENGTH], username[LENGTH], password[LENGTH];

	printf("Give service\n");																	//
	scanf("%s", service_to_find);																// Reads from user the service to search for
	getchar();																					//

	fp = fopen(FILENAME, "r");

	while(fscanf(fp, "%s %s %s", service, username, password) != EOF){							//
		if(strcmp(service, service_to_find) == 0){												//
			printf("Service: \t%s\nUsername: \t%s\nPassword: \t%s\n", service, username, password);	// Searches the entire database untill it finds the service or the End Of File
			fclose(fp);
			return;																				//
		}																						//
	}
	printf("Service not found!\n");																// Alerts user that this service does not exist
	fclose(fp);
	return;
}

void print_all( void ){
	FILE *fp;
	char service[LENGTH], username[LENGTH], password[LENGTH];
	getchar();

	fp = fopen(FILENAME, "r");
	
	while(fscanf(fp, "%s %s %s", service, username, password) != EOF){
		printf("%-30s:%-30s,%-30s\n", service, username, password);
	}

	fclose(fp);
	return;
}
