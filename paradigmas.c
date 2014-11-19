#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_BUFFER 512 //valor para leer lineas de carcacteres con un maximo de 512 caracteres


struct dato_articulo{//struct para guardar datos del txt articulos
	
		int id_articulo;
		char titulo[20];//preguntar por q no puede ser char*titulo
		char palabra_clave[20]; 
		int   paginas;
		int  fecha;//al poner año me sa error parasito en el programa
		char revista[20];
		int  volumen;
		int  numero;
		char   doi[20];
	};typedef struct dato_articulo articulo;
	 
struct dato_autor_articulo{//struct para el txt autor_articulo
	
	int id_articulo;
	int id_autor;
	int autor_principal;
	
	};typedef struct dato_autor_articulo autor_articulo;

struct dato_autor{
		
		int  id_autor;
		char nombres[30];
		char apellidos[30];
		char mail_primario[30];
		char mail_segundario[30];
		char afiliacion[30];
		char direccion[30];
	};typedef struct dato_autor autor;


int contador_lineas(char* x){//me contara la cantidas de lineas del txt articulos
	int c=0;
	FILE *fr=fopen(x,"r");//solo lectura
	char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
	while(fgets(texto,SIZE_BUFFER,fr)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
	c++;
      }
      fclose(fr);
     return c;
	}
	
void crea_autor(autor x[], int longitud){

	FILE *fr=fopen("autores.txt","r");
	char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
	char*temp=(char*)malloc (sizeof(char));
	int i=0;//contador para avanzar en el arreglo
	
	while(fgets(texto,SIZE_BUFFER,fr)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
	temp=strtok(texto,",");//divido las lineas segun aparecen comas
    while(temp != NULL ){  
		
		x[i].id_autor=atoi(temp);//empiezo a  asignar valores al arreglo 
		temp=strtok(NULL,",");//utilizo esta asignacion para avanzar entre las comas
		strcpy(x[i].nombres,temp);
		temp=strtok(NULL,",");
		strcpy(x[i].apellidos,temp);
		temp=strtok(NULL,",");
		strcpy(x[i].mail_primario,temp);
		temp=strtok(NULL,",");
		strcpy(x[i].mail_segundario,temp);
		temp=strtok(NULL,",");
		strcpy(x[i].afiliacion,temp);
		temp=strtok(NULL,",");
		strcpy(x[i].direccion,temp);
		temp=strtok(NULL,",");
	

	
	}i++;
	}fclose(fr);
	}

void crea_autor_articulo(autor_articulo x[], int longitud){
	
	
	FILE *fr=fopen("articulos_autores.txt","r");
	char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
	char*temp=(char*)malloc (sizeof(char));
	int i=0;//contador para avanzar en el arreglo
	
	while(fgets(texto,SIZE_BUFFER,fr)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
		temp=strtok(texto,",");//divido las lineas segun aparecen comas
       while(temp != NULL ){  
		x[i].id_articulo=atoi(temp);//empiezo a  asignar valores al arreglo 
		temp=strtok(NULL,",");//utilizo esta asignacion para avanzar entre las comas
		x[i].id_autor=atoi(temp);
		temp=strtok(NULL,","); 
		x[i].autor_principal=atoi(temp); 
		temp=strtok(NULL,",");
	}i++;
	}fclose(fr);
	}
	
	
  void crea_articulos(articulo x[],int longitud){
	  
	  FILE *fr=fopen("articulos.txt","r");//solo lectura
	
	
	char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
	char*temp=(char*)malloc (sizeof(char));//variabe que guardara los datos de las lineas de texto
	int i=0;//contador para avanzar en el arreglo
	
	
	while(fgets(texto,SIZE_BUFFER,fr)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
		temp=strtok(texto,",");//divido las lineas segun aparecen comas
       while(temp != NULL ){  
		
		x[i].id_articulo=atoi(temp);//empiezo a  asignar valores al arreglo 
		temp=strtok(NULL,",");
		strcpy(x[i].titulo,temp);
		temp=strtok(NULL,",");
		strcpy(x[i].palabra_clave,temp);
		temp=strtok(NULL,",");
		x[i].paginas=atoi(temp);
		temp=strtok(NULL,",");
		x[i].fecha=atoi(temp);
		temp=strtok(NULL,",");
		strcpy(x[i].revista,temp);
		temp=strtok(NULL,",");
		x[i].volumen=atoi(temp);
		temp=strtok(NULL,",");
		x[i].numero=atoi(temp);
		temp=strtok(NULL,",");
		strcpy(x[i].doi,temp);
		temp=strtok(NULL,",");
	
	}
		i++;		
		}
		fclose(fr);//termino de leer el txt	  
	  }


int main(int argc, char **argv)
{
	
	if(strcmp(argv[1],"id_articulo")==0){
	
	//se esta consultando por un articulo segun su id	
	int lineas=contador_lineas("articulos.txt");
	
	articulo arreglo_articulos[lineas];//creo un arreglo el cual contendra los datos del txt articulos
	
	crea_articulos(arreglo_articulos,lineas);

	int ide=atoi(argv[2]);//id ingresada
	int c;//contador para recorrer el arreglo
	for(c=0;c<lineas;c++){
		
		if(arreglo_articulos[c].id_articulo==ide){
			FILE *fe=fopen("output.txt","a");//para escribir en el archivo de salida
			fprintf(fe,"%d ,%s,%s,%d,%d,%s,%d,%d,%s",arreglo_articulos[c].id_articulo,arreglo_articulos[c].titulo,arreglo_articulos[c].palabra_clave,arreglo_articulos[c].paginas,arreglo_articulos[c].fecha,arreglo_articulos[c].revista,arreglo_articulos[c].volumen,arreglo_articulos[c].numero,arreglo_articulos[c].doi);
			fclose(fe);
			break;
			}}}//fin primera funcion
	
	if(strcmp(argv[1],"Titulo")==0){
		//se consulta segun titulo
		int lineas=contador_lineas("articulos.txt");
		articulo arreglo_articulos[lineas];//creo un arreglo el cual contendra los datos del txt articulos
		crea_articulos(arreglo_articulos,lineas);
		char *titulo;//titulo ingresado
		titulo=argv[2];
		int c;
		for(c=0;c<lineas;c++){
		
		if(strcmp(arreglo_articulos[c].titulo,titulo)==0){
			FILE *fe=fopen("output.txt","a");//para escribir en el archivo de salida
			fprintf(fe,"%d ,%s,%s,%d,%d,%s,%d,%d,%s",arreglo_articulos[c].id_articulo,arreglo_articulos[c].titulo,arreglo_articulos[c].palabra_clave,arreglo_articulos[c].paginas,arreglo_articulos[c].fecha,arreglo_articulos[c].revista,arreglo_articulos[c].volumen,arreglo_articulos[c].numero,arreglo_articulos[c].doi);
			fclose(fe);
			break;
			}}}//fin segunda funcion
			
		if(strcmp(argv[1],"keyword")==0){
			//consulta por palabra clave
		int lineas=contador_lineas("articulos.txt");
		articulo arreglo_articulos[lineas];//creo un arreglo el cual contendra los datos del txt articulos
		FILE *fe=fopen("output.txt","a");//para escribir en el archivo de salida
		crea_articulos(arreglo_articulos,lineas);
		char*keyword;
		keyword=argv[2];
		int c;
		char*temp=(char*)malloc (sizeof(char));
		
		for(c=0;c<lineas;c++){
		temp=strtok(arreglo_articulos[c].palabra_clave," ");
		while(temp!=NULL){
			if(strcmp(temp,keyword)==0){
			FILE *fe=fopen("output.txt","a");//para escribir en el archivo de salida
			fprintf(fe,"%d ,%s,%s,%d,%d,%s,%d,%d,%s",arreglo_articulos[c].id_articulo,arreglo_articulos[c].titulo,arreglo_articulos[c].palabra_clave,arreglo_articulos[c].paginas,arreglo_articulos[c].fecha,arreglo_articulos[c].revista,arreglo_articulos[c].volumen,arreglo_articulos[c].numero,arreglo_articulos[c].doi);
			}
			temp=strtok(NULL," ");
			}}
			fclose(fe);
			
			}//fin tercera funcion
			
		if(strcmp(argv[1],"numero")==0){
			//consulta de la cantidad de articulos en la cual particiupa un autor segun du ID
			int lineas =contador_lineas("articulos_autores.txt");
			autor_articulo arreglo_autor_articulos[lineas];
			FILE *fe=fopen("output.txt","a");
			crea_autor_articulo(arreglo_autor_articulos,lineas);
			int numero=atoi(argv[2]);//numero ingresado por el cualse realiza la busqueda
			int c;
			int cantidad=0;//contador de cantidad de articulos del autor
			for(c=0;c<lineas;c++){
				if(arreglo_autor_articulos[c].id_autor==numero){
					cantidad++;//se encuentra un articulo
					}}
			fprintf(fe,"%d\n",cantidad);
			fclose(fe);
			}//fin cuarta funcion
			
		if(strcmp(argv[1],"autores_articulo_id")==0){
		//informacion de autores segun id del articulo	
		
		int lineas_autor_articulo=contador_lineas("articulos_autores.txt");
		int lineas_autores=contador_lineas("autores.txt");	
	
		autor arreglo_autores[lineas_autores];
		autor_articulo arreglo_autor_articulo[lineas_autor_articulo];
		FILE *fe =fopen("output.txt","a");
		
		crea_autor_articulo(arreglo_autor_articulo,lineas_autor_articulo);
	
		crea_autor(arreglo_autores,lineas_autores);
		
		int id_articulo=atoi(argv[2]);//id por el cual se pregunta la informacion de autores
		int c,d;//dos contadores para los for que me ayudaran a recorrer los arreglos
		
		for(c=0;c<lineas_autor_articulo;c++){
			if(arreglo_autor_articulo[c].id_articulo==id_articulo){//encuentro el id del articulo y uso el id del autor para obtener su informacion en el txt autores
				
				for(d=0;d<lineas_autores;d++){
					if(arreglo_autores[d].id_autor==arreglo_autor_articulo[c].id_autor){//encuentro la informacion del autor
					fprintf(fe,"%d,%s,%s,%s,%s,%s,%s",arreglo_autores[d].id_autor,arreglo_autores[d].nombres,arreglo_autores[d].apellidos,arreglo_autores[d].mail_primario,arreglo_autores[d].mail_segundario,arreglo_autores[d].afiliacion,arreglo_autores[d].direccion);
						}}}
						}
						//fin busqueda				
			fclose(fe);
			}//fin quinta funcion problema cn txt
			
			
			
			
		if(strcmp(argv[1],"autor_principal_id")==0){
			//informacion del autor principal de un articulo
			int lineas_autor_articulo=contador_lineas("articulos_autores.txt");
		int lineas_autores=contador_lineas("autores.txt");	
	
		autor arreglo_autores[lineas_autores];
		autor_articulo arreglo_autor_articulo[lineas_autor_articulo];
		FILE *fe =fopen("output.txt","a");
		
		crea_autor_articulo(arreglo_autor_articulo,lineas_autor_articulo);
		
		crea_autor(arreglo_autores,lineas_autores);
		int id_articulo=atoi(argv[2]);//id por el cual se pregunta la informacion de autores
		int c,d;//dos contadores para los for que me ayudaran a recorrer los arreglos
	
		for(c=0;c<lineas_autor_articulo;c++){
			if(arreglo_autor_articulo[c].id_articulo==id_articulo && arreglo_autor_articulo[c].autor_principal==1){//encuentro el id del articulo y uso el id del autor para obtener su informacion en el txt autores
				
				for(d=0;d<lineas_autores;d++){
					if(arreglo_autores[d].id_autor==arreglo_autor_articulo[c].id_autor){//encuentro la informacion del autor
					fprintf(fe,"%d,%s,%s,%s,%s,%s,%s",arreglo_autores[d].id_autor,arreglo_autores[d].nombres,arreglo_autores[d].apellidos,arreglo_autores[d].mail_primario,arreglo_autores[d].mail_segundario,arreglo_autores[d].afiliacion,arreglo_autores[d].direccion);
						}}}}//fin busqueda		
			fclose(fe);
		}//fin sexta funcion denuevo problemas con autor
		
		if(strcmp(argv[1],"articulos_autor_mail")==0){
			//listado de articulos de un autor segun su mail
			int lineas_autor_articulos=contador_lineas("articulos_autores.txt");
			int lineas_autores=contador_lineas("autores.txt");
			int lineas_articulos=contador_lineas("articulos.txt");
			autor arreglo_autores[lineas_autores];
		    autor_articulo arreglo_autor_articulo[lineas_autor_articulos];
			articulo arreglo_articulos[lineas_articulos];
			FILE *fe=fopen("output.txt","a");
			crea_autor_articulo(arreglo_autor_articulo,lineas_autor_articulos);
		    crea_autor(arreglo_autores,lineas_autores);
			crea_articulos(arreglo_articulos,lineas_articulos);
			char* mail=argv[2];//mail con el q se inicia la busqueda
			int c,d,e;//contadores para recorrer los 3 for que necesito para buscar los datos en los 3 txt
		for(c=0;c<lineas_autores;c++){
			if(strcmp(arreglo_autores[c].mail_primario,mail)==0 || strcmp(arreglo_autores[c].mail_segundario,mail)==0){
				//encontre el mail y obtengo su id
				for(d=0;d<lineas_autor_articulos;d++){
					if(arreglo_autor_articulo[d].id_autor==arreglo_autores[c].id_autor){
						//encuentro un articulo cn el id del autor
						for(e=0;e<lineas_articulos;e++){
							if(arreglo_articulos[e].id_articulo==arreglo_autor_articulo[d].id_articulo){
								//encontre un articulo del autor
								fprintf(fe,"%d ,%s,%s,%d,%d,%s,%d,%d,%s",arreglo_articulos[e].id_articulo,arreglo_articulos[e].titulo,arreglo_articulos[e].palabra_clave,arreglo_articulos[e].paginas,arreglo_articulos[e].fecha,arreglo_articulos[e].revista,arreglo_articulos[e].volumen,arreglo_articulos[e].numero,arreglo_articulos[e].doi);
								}}}}}}
								fclose(fe);
								}//fin funcion 7	
		
		if(strcmp(argv[1],"actualizar_mail")==0){
			
		int lineas_autor=contador_lineas("autores.txt");	
		autor arreglo_autor[lineas_autor];
		crea_autor(arreglo_autor,lineas_autor);
		int ide=atoi(argv[2]);//id ingresada del autor
		int c,d;
		for(c=0;c<lineas_autor;c++){
			
			if(arreglo_autor[c].id_autor==ide){
				strcpy(arreglo_autor[c].mail_primario,argv[3]);//actualizo el mail
				}}
			//ahora debo actualizar el registro el cual sobreescribire con los datos guardadod en el arreglo de structs
			FILE *fb=fopen("autores.txt","w");//lo utilizare una vez para borrar el contenido del txt y escribir la primera linea
			FILE *fe=fopen("autores.txt","a");//ya teniendo escrita la primera linea seguire escribiendo alfinal del archivo sin borrar nada
		    fprintf(fb,"%d,%s,%s,%s,%s,%s,%s",arreglo_autor[0].id_autor,arreglo_autor[0].nombres,arreglo_autor[0].apellidos,arreglo_autor[0].mail_primario,arreglo_autor[0].mail_segundario,arreglo_autor[0].afiliacion,arreglo_autor[0].direccion);
			fclose(fb);//escribi la primera linea
			for(d=1;d<lineas_autor;d++){
			fprintf(fe,"%d,%s,%s,%s,%s,%s,%s",arreglo_autor[d].id_autor,arreglo_autor[d].nombres,arreglo_autor[d].apellidos,arreglo_autor[d].mail_primario,arreglo_autor[d].mail_segundario,arreglo_autor[d].afiliacion,arreglo_autor[d].direccion);
					}fclose(fe);//termine de actualizar los datos
			}//fin funcion 8
		
		if(strcmp(argv[1],"eliminar_Autor")==0){
			
		int lineas_autor=contador_lineas("autores.txt");
		int lineas_autor_articulo=contador_lineas("articulos_autores.txt");
		autor arreglo_autor[lineas_autor];
		autor_articulo arreglo_autor_articulo[lineas_autor_articulo];
		int ide=atoi(argv[2]);//id ingresada del autor que se desea eliminar
		int c,d;
		FILE *fb=fopen("autores.txt","w");
		FILE *fe=fopen("autores.txt","a");
		for(c=0;c<lineas_autor_articulo;c++){
			
			if(arreglo_autor_articulo[c].id_autor==ide){
				//existe un articulo asociado por ende no se puede eliminar los datos del autor
				break;
				}}
			c++;//para saber si debo eliminar los datos del autor verifico si el contador c reviso todo txt
			   // por ende si este tiene el mismo valor que la cantidad de lineas no se encontro un articulo asociado
			   //y se procede a eliminar los datos
			   
			if(c==lineas_autor_articulo){//elimino los datos y actualizo el txt	
				char *texto="";//lo utilizo para dejar en blanco el txt
				fprintf(fb,"%s",texto);
				fclose(fb);
				for(d=0;d<lineas_autor;d++){
					
					if(ide==arreglo_autor[d].id_autor)//no debo escribir lo que se encuentra en este slot del arreglo
					{
						d++;						
						}
				        fprintf(fe,"%d,%s,%s,%s,%s,%s,%s",arreglo_autor[d].id_autor,arreglo_autor[d].nombres,arreglo_autor[d].apellidos,arreglo_autor[d].mail_primario,arreglo_autor[d].mail_segundario,arreglo_autor[d].afiliacion,arreglo_autor[d].direccion);
					}}    
				fclose(fe);
				}	//fin funcion 9
			
		if(strcmp(argv[1],"agregar_autor")==0){
			
		int lineas=contador_lineas("autores.txt");	
			
		autor arreglo_autor[lineas+1];
		crea_autor(arreglo_autor,lineas+1);//creo un arreglo con los datos del txt y dejo un slot para guardar los datos ingresados por consola
		
		arreglo_autor[lineas+1].id_autor=arreglo_autor[lineas].id_autor+1;
	printf("%d\n",arreglo_autor[lineas].id_autor);
	printf("%d",arreglo_autor[lineas+1].id_autor);
		/*
		strcpy(arreglo_autor[lineas+1].nombres,argv[2]);
		strcpy(arreglo_autor[lineas+1].apellidos,argv[3]);
		strcpy(arreglo_autor[lineas+1].mail_primario,argv[4]);
		strcpy(arreglo_autor[lineas+1].mail_segundario,argv[5]);
		strcpy(arreglo_autor[lineas+1].afiliacion,argv[6]);
		strcpy(arreglo_autor[lineas+1].direccion,argv[7]);
		//con esto ya tengo guardado todos los datos que necesito
		//ahora debo actualizar el txt
	
		int d;
			
			FILE *fb=fopen("autores.txt","w");
			FILE *fe=fopen("autores.txt","a");
		    fprintf(fb,"%d,%s,%s,%s,%s,%s,%s",arreglo_autor[0].id_autor,arreglo_autor[0].nombres,arreglo_autor[0].apellidos,arreglo_autor[0].mail_primario,arreglo_autor[0].mail_segundario,arreglo_autor[0].afiliacion,arreglo_autor[0].direccion);
			fclose(fb);//escribi la primera linea
	        
			for(d=1;d<lineas+1;d++){
			fprintf(fe,"%d,%s,%s,%s,%s,%s,%s",arreglo_autor[d].id_autor,arreglo_autor[d].nombres,arreglo_autor[d].apellidos,arreglo_autor[d].mail_primario,arreglo_autor[d].mail_segundario,arreglo_autor[d].afiliacion,arreglo_autor[d].direccion);
					}fclose(fe);//termine de actualizar los datos
		*/
		}//fin funcion 10
		
		if(strcmp(argv[1],"agregar_articulo")==0){
		
		int lineas_articulo=contador_lineas("articulos.txt");
		
		
		int lineas_autor_articulo=contador_lineas("articulos_autores.txt");
		
		
		
		articulo arreglo_articulo[lineas_articulo+1];
		
		crea_articulos(arreglo_articulo,lineas_articulo+1);
		
		arreglo_articulo[lineas_articulo+1].id_articulo=arreglo_articulo[lineas_articulo].id_articulo+1;
		strcpy(arreglo_articulo[lineas_articulo+1].titulo,argv[2]);
		strcpy(arreglo_articulo[lineas_articulo+1].palabra_clave,argv[3]);
		arreglo_articulo[lineas_articulo+1].paginas=atoi(argv[4]);
		arreglo_articulo[lineas_articulo+1].fecha=atoi(argv[5]);
		strcpy(arreglo_articulo[lineas_articulo+1].revista,argv[6]);
		arreglo_articulo[lineas_articulo+1].volumen=atoi(argv[7]);
		arreglo_articulo[lineas_articulo+1].numero=atoi(argv[8]);
		strcpy(arreglo_articulo[lineas_articulo+1].doi,argv[9]);//guardo los datos del articulo de entrada
		
			int d;
			FILE *fb=fopen("articulos.txt","w");
			FILE *fe=fopen("articulos.txt","a");
		    fprintf(fb,"%d,%s,%s,%d,%d,%s,%d,%d,%s",arreglo_articulo[0].id_articulo,arreglo_articulo[0].titulo,arreglo_articulo[0].palabra_clave,arreglo_articulo[0].paginas,arreglo_articulo[0].fecha,arreglo_articulo[0].revista,arreglo_articulo[0].volumen,arreglo_articulo[0].numero,arreglo_articulo[0].doi);
			fclose(fb);//escribi la primera linea
			for(d=1;d<lineas_articulo+1;d++){
			fprintf(fe,"%d,%s,%s,%d,%d,%s,%d,%d,%s",arreglo_articulo[d].id_articulo,arreglo_articulo[d].titulo,arreglo_articulo[d].palabra_clave,arreglo_articulo[d].paginas,arreglo_articulo[d].fecha,arreglo_articulo[d].revista,arreglo_articulo[d].volumen,arreglo_articulo[d].numero,arreglo_articulo[d].doi);
			}fclose(fe);//termine de actualizar el registro articulos
		    FILE *eaa=fopen("articulos_autores.txt","a");//funcion para escribir en archivo autor_articulo
		    
			char *ids=argv[10];//debo averiguar cuantos numeros id autor se ingresaron y cuales son
			char*temp=(char*)malloc (sizeof(char));//variabe que guardara los datos de las lineas de texto
		     temp=strtok(ids," ");
		     int cantidad_numeros=0;
		     int numeros[20];//arreglo para guardar los numeros
		      while(temp != NULL ){  
				 numeros[cantidad_numeros]=atoi(temp);
				 cantidad_numeros++; 
				temp=strtok(NULL," ");	   
				  }//ahora que se la cantidad de numeros puedo crear un arreglo para guardar los datos que entraran en el txt autores_articulos
				
				autor_articulo arreglo_autor_articulo[lineas_autor_articulo+cantidad_numeros];
				crea_autor_articulo(arreglo_autor_articulo, lineas_autor_articulo+cantidad_numeros);
		
			while(cantidad_numeros>0){
		arreglo_autor_articulo[lineas_autor_articulo+cantidad_numeros-1].id_autor=numeros[cantidad_numeros];
		if(numeros[cantidad_numeros]==atoi(argv[11])){
			//caso que sea el autor principal
		arreglo_autor_articulo[lineas_autor_articulo+cantidad_numeros-1].autor_principal=1;
			}
			else{
				arreglo_autor_articulo[lineas_autor_articulo+cantidad_numeros-1].autor_principal=0;
				}		
				//ahora escribo los datos nuevos en el txt
			fprintf(eaa,"%d,%d,%d",arreglo_articulo[lineas_articulo+1].id_articulo,arreglo_autor_articulo[lineas_autor_articulo+cantidad_numeros-1].id_autor,arreglo_autor_articulo[lineas_autor_articulo+cantidad_numeros-1].autor_principal);	
				cantidad_numeros--;
				}fclose(eaa);//termino de escribir en txt autores_articulos
		
		}
	return 0;
}

