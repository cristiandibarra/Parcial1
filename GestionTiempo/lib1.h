#ifndef LIB1_H
#define LIB1_H

#include <iostream>
#include <fstream>
#include <registro.h>

using namespace std;


int creditosmateria(int codigo);
int ht_materia(int codigo);
int hp_materia(int codigo);
int htp_materia(int codigo);
char* nombremateria(int codigo);
char* informacioncurso(int codigo);
void imprimircurso(int codigo);
void imprimirhorario(int** horario);
int diaentero(char dia);
int** obtenerhorario(int documento);
char* diachar(int dia);
int cantidadmaterias(int documento);
int* listamaterias(int documento);
int cantidadhorasmateria(int codigo, int** horario);



#endif // LIB1_H
