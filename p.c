#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <regex.h>

typedef struct estaciones{
  int numero;
  float coordenada1;
  float coordenada2;
}esta;

typedef struct clientes{
  int numero;
  float coordenada1;
  float coordenada2;
}clie;

typedef struct instancia{
  char *nombre;
  clie *clientes;
  esta *estaciones;
  int maxTiempo;
  int maxDistancia;
  int velocidad;
  int tiempoServicio;
  int tiempoCarga;
  float dCoordenada1;
  float dCoordenada2;
}inst;

int main(){
  DIR *folder;
  FILE *fp;
  struct dirent *entry;
  inst ins;
  folder = opendir("instanciaPrueba"); //Abre las instanciaPrueba
  if(folder == NULL){
    perror("F");
    return(1);
  }
  while((entry=readdir(folder))!=NULL) { //Itera las instanciaPrueba
    if ( !strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") || !strcmp(entry->d_name, "readme.txt") ){
      continue;
    }
    ins.nombre=entry->d_name; //Nombre de la instancia
    printf("%s\n", ins.nombre);
    char direc[100];
    strcpy(direc,"instanciaPrueba/");
    char data[100];
    strcat(direc,ins.nombre);
    fp = fopen(direc, "r");
    int cantClientes,cantEstaciones;
    if (fgets(data,100,fp)!=NULL){
      strtok(data,"   ");
      cantClientes = atoi(strtok (NULL,"   "));
      cantEstaciones = atoi(strtok (NULL,"   "));
      int maxTiempo = atoi(strtok (NULL,"   "));
      int maxDistancia = atoi(strtok(NULL,"   "));
      float velocidad = atof(strtok(NULL,"   "));
      int tiempoServicio = atoi(strtok(NULL,"   "));
      int tiempoCarga = atoi(strtok(NULL,"   "));
      //ins.clientes[cantClientes];
      //ins.estaciones[cantEstaciones];
      ins.maxTiempo = maxTiempo;
      ins.maxDistancia = maxDistancia;
      ins.velocidad = velocidad;
      ins.tiempoServicio = tiempoServicio;
      ins.tiempoCarga = tiempoCarga;
      printf("%d\n", tiempoCarga);
    }
    if (fgets(data,100,fp)!=NULL){
      strtok(data,"  ");
      strtok(NULL,"  ");
      float dCoordenada1 = atof(strtok (NULL,"   "));
      float dCoordenada2 = atof(strtok (NULL,"   "));
      ins.dCoordenada1 = dCoordenada1;
      ins.dCoordenada2 = dCoordenada2;
      printf("%f\n", ins.dCoordenada1);
      printf("%f\n", ins.dCoordenada2);
    }
    for (int i=0;i<cantEstaciones;i++){
      if (fgets(data,100,fp)!=NULL){
        strtok(data,"   ");
        strtok(NULL,"  ");
        float coordenada1 = atof(strtok (NULL,"   "));
        float coordenada2 = atof(strtok (NULL,"   "));
        ins.estaciones = malloc(100 * sizeof(esta *));
        ins.estaciones[i].numero = i;
        printf("%d\n", ins.estaciones[i].numero);
        ins.estaciones[i].coordenada1 = coordenada1;
        ins.estaciones[i].coordenada2 = coordenada2;
        printf("%f\n", ins.estaciones[i].coordenada1);
        printf("%f\n", ins.estaciones[i].coordenada2);
      }
    }
    for (int i=0;i<cantClientes;i++){
      if (fgets(data,100,fp)!=NULL){
        strtok(data,"   ");
        strtok(NULL,"  ");
        float coordenada1 = atof(strtok (NULL,"   "));
        float coordenada2 = atof(strtok (NULL,"   "));
        ins.clientes = malloc(100 * sizeof(clie *));
        ins.clientes[i].numero = i+1;
        printf("%d\n", ins.clientes[i].numero);
        ins.clientes[i].coordenada1 = coordenada1;
        ins.clientes[i].coordenada2 = coordenada2;
        printf("%f\n", ins.clientes[i].coordenada1);
        printf("%f\n", ins.clientes[i].coordenada2);
      }
    }
  }
  return 0;
}
