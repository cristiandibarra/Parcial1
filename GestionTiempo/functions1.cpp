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

    if(codigo==0) return "";

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

void imprimirhorario(int** horario){

    cout << "\t";
    for(int k=0; k<7; k++){ 
        cout << diachar(k) << "\t";
        //cout << "\t";
    }

    cout << endl << endl;

    for(int i=0; i<16; i++){

        for(int j=0; j<7; j++){

            if(j==0)cout << i+6 << ":00 \t";
            char* nombre;
            if(horario[j][i]>0) nombre=nombremateria(horario[j][i]);
            else if(horario[j][i]<0) nombre=nombremateria((horario[j][i])*(-1));
            else nombre="";
            if(horario[j][i]>0){
                for(int l=0; l<4; l++) cout << nombre[l];
                cout << " C\t";
            }
            else if(horario[j][i]<0){
                for(int l=0; l<4; l++) cout << nombre[l];
                cout << " R\t\t";
            }

            else cout << "-\t";
        }
        cout << endl;
    }
}

int** obtenerhorario(int documento){
    int d1=0;
    int hora=0;
    char dia=' ';
    int codigo=0, creditos=0;
    int i=0;
    int aux=0;
    int** horario=new int*[7];
    for (int i = 0; i < 7; i++) *(horario+i) = new int[16];

    for(int n=0; n<7; n++) for(int m=0; m<16; m++) horario[n][m]=0;

    char* informacionestudiante;
    informacionestudiante=buscardocumento(documento);

    while(*(informacionestudiante + i)!='\n'){
        if(*(informacionestudiante + i)=='-'){
            for(int j=1; j<8; j++){
                aux=*(informacionestudiante + i + j)-48;
                codigo=codigo*10+aux;
            }
            creditos=creditosmateria(codigo);

            dia=*(informacionestudiante+(i+9));
            d1=diaentero(dia);
            hora=*(informacionestudiante+(i+12))-48;
            if(*(informacionestudiante+(i+13))!=']') hora=hora*10+(*(informacionestudiante+(i+13))-48);

            horario[d1][hora]=codigo;
            horario[d1][hora+1]=codigo;

            dia=*(informacionestudiante+(i+10));
            d1=diaentero(dia);

            horario[d1][hora]=codigo;
            horario[d1][hora+1]=codigo;

            if(creditos==4){
                dia=*(informacionestudiante+(i+14));
                d1=diaentero(dia);
                horario[d1][hora]=codigo;
                horario[d1][hora+1]=codigo;
                horario[d1][hora+2]=codigo;
            }
            codigo=0;
            i+=2;
        }

        i++;
    }
    delete[] informacionestudiante;
    return horario;
}

int diaentero(char dia){
    int ndia=0;

    if(dia=='L') ndia=0;
    else if(dia=='M') ndia=1;
    else if(dia=='W') ndia=2;
    else if(dia=='J') ndia=3;
    else if(dia=='V') ndia=4;
    else if(dia=='S') ndia=5;
    else if(dia=='D') ndia=6;

    return ndia;
}

char* diachar(int dia){
    char* diac;
    if(dia==0)diac="Lun";
    else if(dia==1)diac="Mar";
    else if(dia==2)diac="Mie";
    else if(dia==3)diac="Jue";
    else if(dia==4)diac="Vie";
    else if(dia==5)diac="Sab";
    else if(dia==6)diac="Dom";

    return diac;
}

int cantidadmaterias(int documento){
    int cont=0;
    int cantm=0;
    char* linea;
    linea = buscardocumento(documento);

    while(*(linea+cont)!='\0'){
        if(*(linea+cont)=='-') cantm++;
        cont++;
    }

    delete[] linea;
    return cantm;
}

int* listamaterias(int documento){
    int aux=0;
    int codigo=0;
    int cont=0;
    int cont2=0;
    char* linea;
    linea=buscardocumento(documento);
    int nmaterias=cantidadmaterias(documento);
    int* lista;
    lista=new int[nmaterias];
    for(int k=0; k<nmaterias; k++) *(lista+k)=0;

    while(*(linea+cont)!='\0'){
        if(*(linea+cont)=='-'){
            for(int i=0; i<7; i++){
                aux=*(linea+(cont+i+1))-48;
                codigo=codigo*10+aux;
            }
            *(lista+cont2)=codigo;
            cont2++;
            codigo=0;
        }

        cont++;
    }

    return lista;
}

int cantidadhorasmateria(int codigo, int** horario){
    int cantidad=0;
    int cod=0;

    for(int i=0; i<7; i++){
        for(int j=0; j<16; j++){
            cod=horario[i][j];
            if(cod<0) cod=cod*(-1);
            if(cod==codigo) cantidad++;
        }
    }

    return cantidad;
}
