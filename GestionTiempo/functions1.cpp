#include <lib1.h>

char* leerarchivo(char *nombrearchivo){

    ifstream archivo(nombrearchivo);

    if (!archivo.is_open()) {
            cout << "No fue posible abrir el archivo." << endl;
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
        cout << "No fue posible abrir el archivo." << endl;
        return 1;
    }

    while (archivo.getline(linea, 151)) {
        for(int j=0; j<10; j++){
            aux = *(linea + (j))-48;
            cedula=(cedula*10)+aux;
        }
        if(documento==cedula) {
            delete[] linea;
            return true;
        }
        cedula=0;

    }

    archivo.close();
    delete[] linea;
    return false;
}


int creditosmateria(int codigo){

    int creditos=0;
    char* linea;
    linea = informacioncurso(codigo);

    creditos=*(linea+14)-48;

    delete[] linea;
    return creditos;

}

char* informacioncurso(int codigo){
    int codigo2=0;
    int aux=0;
    char* linea;
    linea = new char[60];
    ifstream archivo("cursos.txt");

    if (!archivo.is_open()) {
        cout << "No fue posible abrir el archivo." << endl;
        return NULL;
    }

    while (archivo.getline(linea, 61)) {
        for(int j=0; j<7; j++){
            aux = *(linea + (j))-48;
            codigo2=(codigo2*10)+aux;
        }
        if(codigo==codigo2) return linea;

        codigo2=0;

    }

    return NULL;
}

int ht_materia(int codigo){
    int ht=0;

    char* linea;
    linea = informacioncurso(codigo);

    ht=*(linea+8)-48;

    delete[] linea;
    return ht;

}

int hp_materia(int codigo){
    int hp=0;

    char* linea;
    linea = informacioncurso(codigo);

    hp=*(linea+10)-48;

    delete[] linea;
    return hp;

}

int htp_materia(int codigo){
    int htp=0;

    char* linea;
    linea = informacioncurso(codigo);

    htp=*(linea+12)-48;

    delete[] linea;
    return htp;

}

char* nombremateria(int codigo){
    char* linea;
    linea = informacioncurso(codigo);
    char* nombre;
    nombre = new char[44];

    for(int i=16; i<60; i++) *(nombre+(i-16))=*(linea+i);

    return nombre;
}

bool registrarmateria4(int codigo, char* dias, int hora1, char dia, int hora2){
    ofstream archivo("estudiantes.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "No fue posible abrir el archivo." << endl;
        return false;
    }

    archivo << '-';
    archivo << codigo;
    archivo << '(';

    for(int i=0; i<2; i++) archivo << *(dias+i);

    archivo << '[';
    archivo << hora1;
    archivo << ']';
    archivo << dia;
    archivo << '[';
    archivo << hora2;
    archivo << ']';
    archivo << ')';

    return true;
}

bool registrarmateria3(int codigo, char* dias, int hora){
    ofstream archivo("estudiantes.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "No fue posible abrir el archivo." << endl;
        return false;
    }

    archivo << '-';
    archivo << codigo;
    archivo << '(';

    for(int i=0; i<2; i++) archivo << *(dias+i);

    archivo << '[';
    archivo << hora;
    archivo << ']';
    archivo << ')';

    return true;
}

bool registrardocumeto(int documento){

    ofstream archivo("estudiantes.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "No fue posible abrir el archivo." << endl;
        return false;
    }
    archivo << '\n';
    archivo << documento;

    return true;
}

void imprimircurso(int codigo){

    cout << "Curso: " << nombremateria(codigo) << endl;
    cout << "Horas de teoria: " << ht_materia(codigo) << endl;
    cout << "Horas de practica: " << hp_materia(codigo) << endl;
    cout << "Horas teorico-practicas: " << htp_materia(codigo) << endl;
    cout << "Creditos: " << creditosmateria(codigo) << endl << endl;

}
