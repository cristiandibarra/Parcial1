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
bool registrarestudiante(int documento){
    ofstream archivo("estudiantes.txt", ios::app);
    int codigo=0;
    int creditos=0;
    int hora=0;
    char* dias;
    dias = new char[2];
    bool estado=true;

    if(buscardocumento(documento)) {
        cout << "El documento ya esta registrado!" << endl << endl;
        return false;
    }


    if (archivo.is_open()){
        archivo << '\n';
        archivo << documento;
        archivo << '-';
        cout << "Registra tu primera materia: " << endl << endl;

        while(estado){
            cout << "Ingresa el codigo de la materia: ";
            cin >> codigo;
            cout << endl;
            archivo << codigo;
            archivo << '(';

            creditos=creditosmateria(codigo);
            cout << "Esta materia tiene " << creditos << " creditos." << endl;

            if(creditos==3){
                cout << endl;

                *(dias)='_';
                *(dias+1)='_';
                *(dias+2)='\0';

                cout << "Ingrese los días en que matriculo los cursos: ";
                cin >> *(dias) >> *(dias+1);
                cout << endl;
                for(int i=0; i<2; i++) archivo << *(dias+i);

                archivo << '[';

                cout << "Ingrese la hora de inicio de clase: ";
                cin >> hora;
                archivo << hora;
                archivo << ']';
                archivo << ')';

                cout << "Desea registrar otra materia?    0(NO)    1(SI)";
                cin >> estado;
            }
            else if(creditos==4){

            }
        }

    } else{
            cout << "No se pudo abrir el archivo." << endl;
    }

    archivo.close();

    return true;
}

int creditosmateria(int codigo){
    int codigo2=0;
    int creditos=0;
    int aux=0;
    char* linea;
    linea = new char[60];
    ifstream archivo("cursos.txt");

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    while (archivo.getline(linea, 61)) {
        for(int j=0; j<7; j++){
            aux = *(linea + (j))-48;
            codigo2=(codigo2*10)+aux;
        }
        if(codigo==codigo2) creditos=*(linea + 14)-48;

        codigo2=0;

    }

    archivo.close();
    delete[] linea;
    return creditos;

}
