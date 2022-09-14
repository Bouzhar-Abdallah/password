#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
FILE *fptr;
struct users {
		int id;
		char login[40];
		char first_name[20];
		char last_name[20];
		
	//	char* password;
	};
/*
int read_stdin(char *chaine, int size)
{
    char *positionEntree = NULL;
 
    // On lit le texte saisi au clavier
    if (fgets(chaine, size, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return *chaine; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        return 'error'; // On renvoie 0 s'il y a eu une erreur
    }
}

*/

char * passwordV() {//working
	
	int i,a=0,b=0,c=0;
    static char password[20];
    
    start:
    	
    printf( "Enter a password that contains a capital, symbol and a number \n" );
    scanf( "%s", password );
    
    /****** test if password is between 8 and 20 caracters *******/
    
		while(strlen(password)>20 || strlen(password)<8){
			if(strlen(password)>20)
			{printf( "password too long please do not exceed 20 character \n" );scanf( "%s", password );}
			else {printf( "password too short minimum is 8 characters \n" );scanf( "%s", password );}
		goto start;
		}


	/******check if password coantains a numbre, a capital and a symbol*******/
    for(i=0; i<strlen(password);i++)
	    {
			if (isdigit(password[i]))
		    a++;
		    else {
		
			if (isalpha(password[i]))
			    {
			    	if(isupper(password[i]))
			    		b++;
				}
				else if ((password[i])!=0)
								c++;  		}
		}
		
	/*****password fulfills criteria ******/
	
if (a>0 && b>0 && c>0){
	    printf( "your password is strong\n");
	
}
	/*****password doesn't fulfill criteria ******/

	else 
	{  
		if (a==0) printf( "password need atleast one digit \n" );	
		if (b==0) printf( "password need atleast one capital letter \n" ); 
		if (c==0) printf( "password need atleast one symbol \n" );	
	sleep(5);
	system("CLS");
	goto start;
	}
    return password;
    
}
int find_current_id(){//working with gets to read input
			
	int id=1;

	fptr = fopen("users.txt","r");
	    if (fptr != NULL)
    {
        // On peut lire et écrire dans le fptr
        fseek(fptr, 0, SEEK_END);
       
       do{
        fseek(fptr, -2, SEEK_CUR);
		}while(fgetc(fptr)!='#');
		fscanf(fptr,"%d",&id);
		id++;
    }
    else
    {
        printf("Impossible d'ouvrir le fptr test.txt");
    }
	return id;
}

void singup(int id){
struct users user;

	printf("id is :%d\n",id);
	printf("\n\n\n\n\nentrez votre prenom\n");
	//fgets(user.first_name,10,stdin);
	gets(user.first_name);

	
	printf("\n\n\n\n\nentrez fotre nom\n");
//	scanf("%s",&user.last_name);
//	fgets(user.last_name,10,stdin);
    gets(user.last_name);
	
	strcpy(user.login, user.first_name);
    strcat(user.login,".");
    strcat(user.login,user.last_name);
    
    
	user.id=id;
	 //FILE *fptr;
   fptr = fopen("users.txt","a");

	fprintf(fptr, "#%d %s %s %s",user.id, user.first_name,user.last_name, user.login);
   fclose(fptr);
   
	
/*
	//writing first name into login
 	for (length=0; user.first_name[length] != '\0';++length) {
    user.login[length] = user.first_name[length];}
    
    //adding a '.' between first name and last name into login
    user.login[length]= '.';
    length++;
    
	//writing last name into login
	for (j=0; user.last_name[j] != '\0';++j,length++) {
    user.login[length] = user.last_name[j];}
    user.login[length]= '\0';
    
	*/

	
}

int main(){
			int a=0;
		
		printf("\n\n\n\n\n1: to sign up\n2: to log-in\n");
		scanf(" %d",&a);
		fflush(stdin);
			while(a!=1 &&a!=2){
			system("CLS");
			printf("\n\n\nvieuller entrez 1 ou 2\n\n");
			printf("1: to sign up\n2: to log-in\n");
			scanf("%d",&a);fflush(stdin);
		}
				if(a==1){
					system("CLS");
					int id=find_current_id();
			
					singup(id);
				}else{
					passwordV();
				}

				return 0;
}












