#include<stdio.h>
#include<string.h>


int main(void){
FILE *input, *output;

int i = 0;

char buffer[250];


input = fopen("text.txt", "r");
output = fopen("hidden.txt", "w");

while(1){
	buffer[i] = fgetc(input);
	if(buffer[i] == EOF)
		{ buffer[i] = '\0'; 
			break; }
	i++;
}

int a = 0;
printf("verschlüsselungscode eingeben: ");
scanf("%d", &a);
getchar();

i = 0;

while(buffer[i] != '\0'){

if(buffer[i] >= 65 && buffer[i] <= 90 )
{
	buffer[i] += a;

	if(buffer [i] > 90)
		buffer[i] -= 26;
}
		
 if( buffer[i] >= 97 && buffer[i] <= 122 )
{		
		
	
		if((buffer[i]+a) > 122)
			buffer[i] -= 26;
		buffer[i] += a;
	

}
i++;
}


fprintf(output,"%s", buffer);

fclose(output);
fclose(input);

return(0);
}




