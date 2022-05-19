/*autor:Oscar Vivaldi Partido Ramirez    fecha:17/03/2022
programa que almacena las edades de un salon de clases de 10 alumnos 
	-imprimir
	-la media
	-varianza
	-desviacion estandar 
	-mediana
	-ordenar por edad 
	 usando los tipos de datos que utilicen menos memoria 
*/

#include<stdio.h>
#include<math.h>
//macro 
#define MAX 10
int main(){
	unsigned char edades[MAX], aux;
	unsigned char centro ;
	float media,suma=0, var,desviacion,mediana;
	int validar;
	
	//leer datos del tecladso para llenar el arreglo completo
	for(int i=0; i<MAX; i++){

	do{
		
		printf("Introduce la edad del alumno #%d: ",i);
		scanf("%d",&validar);
		if(!(validar>=0 &&  validar<=150)){
			printf("edad invalida!!! intenta nuevamente.\n");
		}
	}while(!(validar>=0&& validar<=150));
	edades[i]=validar;
	}
	
	//Imprimir todo el arreglo 
	printf("listado de Alumnos \n");
	for(int i=0; i<MAX; i++){
		printf("Edad del alumno#%d: %d \n",i,edades[i]);
		
	}
	//calcular la media 
	for(int i=0; i<MAX; i++){
		suma=suma+edades[i];
	}
	media=suma/MAX;
	printf("La media es %.2f\n",media);
	
	
	//varianza
	suma=0;
	for (int i=0; i<MAX;i++){
		suma=suma+pow(edades[i]-media,2);
	}
	var=suma/MAX;
	printf("La varianza es %.2f\n",var);
	
	
	//desviacion estandar 
	desviacion=sqrt(var);
	printf("La desviacion estandar es %.2f\n",desviacion);
	
	
	//ordenamiento del arreglo por el metodo de la burbuja 
	//usando el codigo de https://es.wikipedia.org/wiki/Ordenamiento_de_burbuja
	for(int z = 1; z < MAX; ++z) {
      for(int v = 0; v < (MAX - z); v++) {
         if(edades[v] > edades[v+1]){
            aux = edades[v];
            edades[v] = edades[v + 1];
            edades[v + 1] = aux;
         }
      }
    }
	//imprimir todo el arreglo
	printf("Listado de alumnos ordenados\n");
	for (int i=0;i<MAX; i++){
		printf("edad del alumno #%d: %d\n",i,edades[i]);
	}
	
	//calculo de mediana
	if(MAX%2==0){
		centro=MAX/2;
		mediana=(edades[centro]+edades[centro-1])/2.0;

	}
	else{
		centro=MAX/2;
		mediana=edades[centro];
	}
	printf("la mediana es %.2f\n",mediana);
	return 0;
}

