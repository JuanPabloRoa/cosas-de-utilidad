#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_BUFFER 512 //valor para leer lineas de carcacteres con un maximo de 512 caracteres
 
int dimension= 10;//para trabajar con arreglos bidimensionales necesito pasar el tamaño de la segunda dimension a  la funcion

//funcion para imprimir la solucion encontrada
void ImprimirSolucion(int MatrizSol[dimension][dimension])
{
    FILE *fe=fopen("salida.out","a");
    FILE *vaciar=fopen("salida.out","w");//se usara en la primera escritura para vaciar el archivo si es que se ha utilizado anteriormente el codigo


    int i,j;
    for (i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++){
         if(j==dimension-1){
       ////////////////////777     
            if(MatrizSol[i][j]==1){  
            fprintf(fe," X ");
        
            fprintf(fe,"\n");

        }
            //////////////////////////
           else{
             fprintf(fe," %d ", MatrizSol[i][j]);
        fprintf(fe,"\n");
            }
    }
            
        else{

             if(MatrizSol[i][j]==1){  
            fprintf(fe," X ");
            
        }

                else{
               fprintf(fe," %d ", MatrizSol[i][j]);
        }

        }

    }
    }
fclose(vaciar);
 fclose(fe);

}
 
//funcion que revisa si una posicion es accesible o no
int PosValida(int Matriz[dimension][dimension], int x, int y)
{
    
    if(x >= 0 && x < dimension && y >= 0 && y < dimension && Matriz[x][y] == 1)
        return 1;
 
    return 0;
}
 
//Funcion que resuelve el problema utilizando backtracking, ademas verifica si existe o no una salucion,
//si existe solucion lo demuestra en la MatrizSol
int SolucionLaberinto(int matriz[dimension][dimension])
{
    int MatrizSol[dimension][dimension] ;
int i,j;//llenare la matriz de ceros
for (i = 0; i < dimension; ++i)
{
    for ( j = 0; j < dimension; ++j)
    {
        MatrizSol[i][j]=0;
    }
}


   
    if(FuncionRecursiva(matriz, 0, 0, MatrizSol) == 0)
    {
        printf("No existe solucion");
        return 0;
    }
 
    ImprimirSolucion(MatrizSol);
    return 1;
}
 
//funcion recursiva que sera utilizada para resolver el problema
int FuncionRecursiva(int matriz[dimension][dimension], int x, int y, int solucion[dimension][dimension])
{
    
    if(x == dimension-1 && y == dimension-1)
    {
        solucion[x][y] = 1;
        return 1;
    }
 
    
    if(PosValida(matriz, x, y) == 1)
    {
        // marca como parte de la solucion
        solucion[x][y] = 1;
 
        //me muevo en direccion de x si es accesible
        if (FuncionRecursiva(matriz, x+1, y, solucion) == 1)
            return 1;
 
      //si x no es accesible pruebo con la direccion de Y
        if (FuncionRecursiva(matriz, x, y+1, solucion) == 1)
            return 1;
 
      //si no me puedo mover a  ningun lugar accesible me devuelvo y busco otro camino
        solucion[x][y] = 0;
        return 0;
    }   
 
    return 0;
}

int ObtenerDimension(){

int capacidad;
FILE *fr=fopen("entrada.in","r");
char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
char*temp=(char*)malloc (sizeof(char));
fgets(texto,SIZE_BUFFER,fr);
temp=strtok(texto," ");//leo hasta un espacio en blanco
capacidad=atoi(temp);//asigno el primer valor del txt
fclose(fr);
return capacidad;

}

void ObtenerMatriz(int matrizEntrada[dimension][dimension],int capacidad){//funcion para obtener los datos de la matriz contenida en entrada.in

FILE *fr=fopen("entrada.in","r");
char *texto = (char *) malloc (SIZE_BUFFER * sizeof(char));
char*temp=(char*)malloc (sizeof(char));
int i=0;//contador para llenar los datos de la matriz
int j;
while(fgets(texto,SIZE_BUFFER,fr)!=NULL){//mientras las lineas del archivo de texto no esten vacias avanzare
        temp=strtok(texto," ");//divido las lineas segun aparecen espacios
     // printf("%s\n",temp );

       if(i>=1 && i<=capacidad){
            
     for(j=0; j< capacidad; j++){
        matrizEntrada[i-1][j]=atoi(temp);//empiezo a  asignar valores segun los colores de los dulces 
        temp=strtok(NULL," ");
        
        }      
        }
        i++;

}
 fclose(fr);
}


 

int main()
{
    int  capacidad = ObtenerDimension();//representara la dimension de  la matriz
    dimension=capacidad;
    
    int matriz[capacidad][capacidad];//creo la matriz que utilizare
  
   ObtenerMatriz(matriz,capacidad);//asigno los valores a  la matriz creada recientemente 

   SolucionLaberinto(matriz);

    return 0;
}