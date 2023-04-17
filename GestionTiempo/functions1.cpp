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

bool buscardocumento(int documento){
    int cedula=0;
    int aux=0;
    char* linea;
    linea = new char[150];
    ifstream archivo("estudiantes.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    while (archivo.getline(linea, 151)) {
        for(int j=0; j<10; j++){
            aux = *(linea + (j))-48;
            cedula=(cedula*10)+aux;
        }
        if(documento==cedula) return true;

        cedula=0;

    }

    archivo.close();
    delete[] linea;
    return false;
}
