#ifndef REGISTRO_H
#define REGISTRO_H

#include <lib1.h>

char* buscardocumento(int documento);
bool registrardocumeto(int documento);
bool registrarmateria4(int codigo, char* dias, int hora1, char dia, int hora2);
bool registrarmateria3(int codigo, char* dias, int hora);

#endif // REGISTRO_H
