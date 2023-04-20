#include <registro.h>

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

char* buscardocumento(int documento){
    int cedula=0;
    int aux=0;
    char* linea;
    linea = new char[150];
    ifstream archivo("estudiantes.txt");

    if (!archivo.is_open()) {
        cout << "No fue posible abrir el archivo." << endl;
        return "";
    }

    while (archivo.getline(linea, 151)) {
        for(int j=0; j<10; j++){
            aux = *(linea + (j))-48;
            cedula=(cedula*10)+aux;
        }
        if(documento==cedula) {
            return linea;
        }
        cedula=0;

    }

    archivo.close();
    delete[] linea;
    return "";
}
