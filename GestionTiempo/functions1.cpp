#include <lib1.h>

char* leerarchivo(char *nombrearchivo){

    ifstream archivo(nombrearchivo);

    if (!archivo.is_open()) {
            cout << "No se pudo abrir el archivo" << endl;
            return NULL;
    }

    archivo.seekg(0, ios::end);
    int tamanio = archivo.tellg();
    archivo.seekg(0, ios::beg);

    char* contenido = new char[tamanio];

    archivo.read(contenido, tamanio);

    archivo.close();

    return contenido;
}
