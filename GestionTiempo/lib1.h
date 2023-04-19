#ifndef LIB1_H
#define LIB1_H

#include <iostream>
#include <fstream>

using namespace std;

char* leerarchivo(char *nombrearchivo);
bool buscardocumento(int documento);
int creditosmateria(int codigo);
int ht_materia(int codigo);
int hp_materia(int codigo);
int htp_materia(int codigo);
char* nombremateria(int codigo);
char* informacioncurso(int codigo);
bool registrardocumeto(int documento);
bool registrarmateria4(int codigo, char* dias, int hora1, char dia, int hora2);
bool registrarmateria3(int codigo, char* dias, int hora);
void imprimircurso(int codigo);


#endif // LIB1_H
