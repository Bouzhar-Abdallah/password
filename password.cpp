#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	int i,a=0,b=0,c=0,t=0;
    char password[20];
    printf( "Enter a password that contains a capital, symbol, and a number \n" );
    scanf( "%s", password );
    
        start:
        	switch (t)
        	{
        		case 1 : {system("CLS");printf( "password too long please do not exceed 20 character \n" );scanf( "%s", password );} break;
        		
        		case 2 : {system("CLS");printf( "password too short minimum is 8 characters \n" );scanf( "%s", password );}break;
        		
        		case 3 : {system("CLS");printf( "password is weak please try again \n" );scanf( "%s", password );}break;
        		
        		case 4 : {system("CLS");printf( "password need atleast one digit \n" );scanf( "%s", password );}break;
        		
        		case 5 : {system("CLS");printf( "password need atleast one capital letter \n" );scanf( "%s", password );}break;
        		
        		case 6 : {system("CLS");printf( "password need atleast one symbol \n" );scanf( "%s", password );}break;
			}
    

    
while(strlen(password)>20 || strlen(password)<8){
	if(strlen(password)>20)
	{t=1;printf( "password too long please do not exceed 20 character \n" );scanf( "%s", password );}
	else {t=2;printf( "password too short minimum is 8 characters \n" );scanf( "%s", password );}
//goto start;
}

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
		
if (a>0 && b>0 && c>0){
	    printf( "your password is strong\n");
	printf( "%d-%d-%d-%d\n",a,b,c,strlen(password));
	
}

	else 
	{  printf( "your password is weak\n");
	//	system("CLS");
		t=3;
		if(a=0) {t=4;printf( "password need atleast one digit \n" );	}
		if (b=0) {t=5;printf( "password need atleast one capital letter \n" ); }
		if (c=0) {t=6; printf( "password need atleast one symbol \n" );	}
	//sleep(10);
	goto start;
	}
    return 0;
}
