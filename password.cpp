#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char * passwordV() {
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
//	char *password = malloc(10);
    return password;
    
}



int main(){

	printf("%s",passwordV());
	return 0;
}
