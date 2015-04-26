#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_BUFFER 512 //valor para leer lineas de carcacteres con un maximo de 512 caracteres

struct dato_persona{//struct para guardar datos correspondientes a personas
	
		
		char nombre[20];// variable que contendra el nombre
		int rojos; //los colores representan la cantidad de dulces de ese tipo que tiene la persona
		int verdes;
		int amarillos;
		int naranjos;
		char primer_gusto[10];
		char segundo_gusto[10];
		char tercer_gusto[10];
		char cuarto_gusto[10];
		
	};typedef struct dato_persona persona;


int cantidad_persona(){//funcion que me retorna la cantidad de personas

int cantidad;
FILE *fr=fopen("entrada.in","r");
char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
char*temp=(char*)malloc (sizeof(char));
fgets(texto,SIZE_BUFFER,fr);
temp=strtok(texto," ");//leo hasta un espacio en blanco
cantidad=atoi(temp);//asigno el primer valor del txt
fclose(fr);
return cantidad;
}

void asignar_dulces_totales(int *rojos,int *amarillos,int *verdes, int *naranjos, int cantidad_persona ){
FILE *fr=fopen("entrada.in","r");
char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
char*temp=(char*)malloc (sizeof(char));
int linea_datos=cantidad_persona+2;//en esta linea se encuentran los datos que requiero
int i=1;//contador para llegar a la linea en donde se encuentran lo valores que requiero

while(fgets(texto,SIZE_BUFFER,fr)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
		temp=strtok(texto," ");//divido las lineas segun aparecen espacios
       
       if(i==linea_datos){
       while(temp != NULL ){  
		
		*rojos=atoi(temp);//empiezo a  asignar valores segun los colores de los dulces 
		temp=strtok(NULL," ");
		*amarillos=atoi(temp);
		temp=strtok(NULL," ");
		*verdes=atoi(temp);
		temp=strtok(NULL," ");
		*naranjos=atoi(temp);
		temp=strtok(NULL," ");

	
	}
}
		i++;		
		}

		fclose(fr);
}

void asignar_valores_personas(persona array_persona[], int cantidad_persona){

FILE *fr=fopen("entrada.in","r");
char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
char*temp=(char*)malloc (sizeof(char));
int i=0;//contador para llenar los datos del arreglo

while(fgets(texto,SIZE_BUFFER,fr)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
		temp=strtok(texto," ");//divido las lineas segun aparecen espacios
		
       
       if(i>=1 && i<=cantidad_persona){//wuuuuuuut esto no deberia funcionar pero funciona **********revisar
       	
       	strcpy(array_persona[i-1].primer_gusto,temp);
		temp=strtok(NULL," ");
		strcpy(array_persona[i-1].segundo_gusto,temp);
		temp=strtok(NULL," ");
		strcpy(array_persona[i-1].tercer_gusto,temp);
		temp=strtok(NULL," ");
		strcpy(array_persona[i-1].cuarto_gusto,temp);
		temp=strtok(NULL," ");
		strcpy(array_persona[i-1].nombre,temp);
		temp=strtok(NULL," ");
		array_persona[i-1].rojos=0;
		array_persona[i-1].verdes=0;
		array_persona[i-1].naranjos=0;
		array_persona[i-1].amarillos=0;
}
		i++;		
		}
		fclose(fr);


} 







 int sacar_dulce_primer_gusto(persona *persona_saca_dulce, int *dulces_rojos_totales, int *dulces_amarillos_totales, int *dulces_verdes_totales, int *dulces_naranjos_totales){

if (strcmp((*persona_saca_dulce).primer_gusto,"R")==0 ){
	if(*dulces_rojos_totales>0){
(*persona_saca_dulce).rojos=(*persona_saca_dulce).rojos+1;

*dulces_rojos_totales=*dulces_rojos_totales-1;
return 1;
}}


if (strcmp((*persona_saca_dulce).primer_gusto,"A")==0 ){
	if(*dulces_amarillos_totales>0){
(*persona_saca_dulce).amarillos=(*persona_saca_dulce).amarillos+1;
*dulces_amarillos_totales=*dulces_amarillos_totales-1;
   
return 1;
}

}if (strcmp((*persona_saca_dulce).primer_gusto,"V")==0 ){
	if(*dulces_verdes_totales>0){
(*persona_saca_dulce).verdes=(*persona_saca_dulce).verdes+1;
*dulces_verdes_totales=*dulces_verdes_totales-1;
return 1;
}
   

}if (strcmp((*persona_saca_dulce).primer_gusto,"N")==0 ){
	if(*dulces_naranjos_totales>0){
(*persona_saca_dulce).naranjos=(*persona_saca_dulce).naranjos+1;
*dulces_naranjos_totales=*dulces_naranjos_totales-1;
   
return 1;
}
 
}
else{

	return 0;
}}


 int sacar_dulce_segundo_gusto(persona *persona_saca_dulce, int *dulces_rojos_totales, int *dulces_amarillos_totales, int *dulces_verdes_totales, int *dulces_naranjos_totales){

if (strcmp((*persona_saca_dulce).segundo_gusto,"R")==0 ){
	if(*dulces_rojos_totales>0){
(*persona_saca_dulce).rojos=(*persona_saca_dulce).rojos+1;
*dulces_rojos_totales=*dulces_rojos_totales-1;
return 1;}
}

if (strcmp((*persona_saca_dulce).segundo_gusto,"A")==0 ){
	if(*dulces_amarillos_totales>0){
(*persona_saca_dulce).amarillos=(*persona_saca_dulce).amarillos+1;
*dulces_amarillos_totales=*dulces_amarillos_totales-1;
   
return 1;
}
 
}if (strcmp((*persona_saca_dulce).segundo_gusto,"V")==0 ){
	if(*dulces_verdes_totales>0){
(*persona_saca_dulce).verdes=(*persona_saca_dulce).verdes+1;
*dulces_verdes_totales=*dulces_verdes_totales-1;
return 1;
}
   

}if (strcmp((*persona_saca_dulce).segundo_gusto,"N")==0 ){
	if(*dulces_naranjos_totales>0){
(*persona_saca_dulce).naranjos=(*persona_saca_dulce).naranjos+1;
*dulces_naranjos_totales=*dulces_naranjos_totales-1;
     
return 1;
}

}
else{

	return 0;
}}


 int sacar_dulce_tercer_gusto(persona *persona_saca_dulce, int *dulces_rojos_totales, int *dulces_amarillos_totales, int *dulces_verdes_totales, int *dulces_naranjos_totales){

if (strcmp((*persona_saca_dulce).tercer_gusto,"R")==0 ){
	if(*dulces_rojos_totales>0){
(*persona_saca_dulce).rojos=(*persona_saca_dulce).rojos+1;
*dulces_rojos_totales=*dulces_rojos_totales-1;
   
return 1;
}

}

if (strcmp((*persona_saca_dulce).tercer_gusto,"A")==0 ){
	if(*dulces_amarillos_totales>0){
(*persona_saca_dulce).amarillos=(*persona_saca_dulce).amarillos+1;
*dulces_amarillos_totales=*dulces_amarillos_totales-1;
 
return 1;}
  
}if (strcmp((*persona_saca_dulce).tercer_gusto,"V")==0 ){
	if(*dulces_verdes_totales>0){
(*persona_saca_dulce).verdes=(*persona_saca_dulce).verdes+1;
*dulces_verdes_totales=*dulces_verdes_totales-1;
return 1;}
     

}if (strcmp((*persona_saca_dulce).tercer_gusto,"N")==0 ){
	if(*dulces_naranjos_totales>0){
(*persona_saca_dulce).naranjos=(*persona_saca_dulce).naranjos+1;
*dulces_naranjos_totales=*dulces_naranjos_totales-1;
   
return 1;
}
  
}
else{

	return 0;
}}

 int sacar_dulce_cuarto_gusto(persona *persona_saca_dulce, int *dulces_rojos_totales, int *dulces_amarillos_totales, int *dulces_verdes_totales, int *dulces_naranjos_totales){

if (strcmp((*persona_saca_dulce).cuarto_gusto,"R")==0 ){
	if(*dulces_rojos_totales>0){
(*persona_saca_dulce).rojos=(*persona_saca_dulce).rojos+1;
*dulces_rojos_totales=*dulces_rojos_totales-1;
return 1;}
  

}

if (strcmp((*persona_saca_dulce).cuarto_gusto,"A")==0 ){
	if(*dulces_amarillos_totales>0){
(*persona_saca_dulce).amarillos=(*persona_saca_dulce).amarillos+1;
*dulces_amarillos_totales=*dulces_amarillos_totales-1;

return 1;
}
    
}if (strcmp((*persona_saca_dulce).cuarto_gusto,"V")==0 ){
	if(*dulces_verdes_totales>0){
(*persona_saca_dulce).verdes=(*persona_saca_dulce).verdes+1;
*dulces_verdes_totales=*dulces_verdes_totales-1;
return 1;
}
     

}if (strcmp((*persona_saca_dulce).cuarto_gusto,"N")==0 ){
	if(*dulces_naranjos_totales>0){
(*persona_saca_dulce).naranjos=(*persona_saca_dulce).naranjos+1;
*dulces_naranjos_totales=*dulces_naranjos_totales-1;
  
return 1;}
 
}
else{
 
	return 0;
}




}


void imprimirResultados(persona array_persona[],int cantidad_persona ){//funcion para escribir en el archivode salida

FILE *fe=fopen("salida.out","a");
FILE *vaciar=fopen("salida.out","w");//se usara en la primera escritura para vaciar el archivo si es que se ha utilizado anteriormente el codigo


int i;
for (i=0;i<cantidad_persona;i++){
	if(i==0){
fprintf(vaciar,"NOmbre: %s   Rojos: %d    Amarillo: %d     VErde: %d     Naranjo: %d    \n",array_persona[i].nombre,array_persona[i].rojos,array_persona[i].amarillos,array_persona[i].verdes,array_persona[i].naranjos );
 }
if(i!=0){
fprintf(fe,"NOmbre: %s   Rojos: %d    Amarillo: %d     VErde: %d     Naranjo: %d    \n",array_persona[i].nombre,array_persona[i].rojos,array_persona[i].amarillos,array_persona[i].verdes,array_persona[i].naranjos );
}
}
fclose(vaciar);
 fclose(fe);}


int main(int argc, char **argv){

int cantidad_personas =cantidad_persona();
int dulces_rojos_totales;
int dulces_amarillos_totales;
int dulces_verdes_totales;
int dulces_naranjos_totales;
int contador=0;
asignar_dulces_totales(&dulces_rojos_totales, &dulces_amarillos_totales, &dulces_verdes_totales, &dulces_naranjos_totales, cantidad_personas);

persona array_personas[cantidad_personas]; //arreglo de struct tipo persona
asignar_valores_personas(array_personas, cantidad_personas);

//ahora ordeno los valores dentro del arreglo
	persona aux;
	int k=0;
	int j=0;
	for(k=0;k<cantidad_personas-1;k++) { 
for(j=k+1;j<cantidad_personas;j++) { 
if(strcmp(array_personas[k].nombre,array_personas[j].nombre)>0) { 
aux = array_personas[k]; 
array_personas[k] = array_personas[j]; 
array_personas[j] = aux; 
}}}


while(dulces_rojos_totales>0 || dulces_amarillos_totales>0 || dulces_verdes_totales>0 || dulces_naranjos_totales>0){//reparto los dulces


if(sacar_dulce_primer_gusto(&array_personas[contador],&dulces_rojos_totales, &dulces_amarillos_totales, &dulces_verdes_totales, &dulces_naranjos_totales)==0){

if(sacar_dulce_segundo_gusto(&array_personas[contador],&dulces_rojos_totales, &dulces_amarillos_totales, &dulces_verdes_totales, &dulces_naranjos_totales)==0){

if(sacar_dulce_tercer_gusto(&array_personas[contador],&dulces_rojos_totales, &dulces_amarillos_totales, &dulces_verdes_totales, &dulces_naranjos_totales)==0){

if(sacar_dulce_cuarto_gusto(&array_personas[contador],&dulces_rojos_totales, &dulces_amarillos_totales, &dulces_verdes_totales, &dulces_naranjos_totales)==0){

}}}}

contador++;
if(contador==cantidad_personas)
	{contador=0;}

}

imprimirResultados(array_personas,cantidad_personas);

	return 0;

}