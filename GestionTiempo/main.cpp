#include <lib1.h>
#include <fstream>

using namespace std;

int main()
{
    //char* nombrearchivo;
    //nombrearchivo = new char[20];

    //cout << "Ingrese el nombre del archivo (Máx. 20 caracteres): ";
    //cin.getline(nombrearchivo, 20);


    /*
    int i = 0;
    char* contenido = leerarchivo(nombrearchivo);

    cout << "Contenido del archivo:" << endl;
        while (contenido[i]!='\0') {
            cout << contenido[i];
            i++;
        }
    cout << endl;

    delete[] contenido;
    delete[] nombrearchivo;   
    */

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int opcion=0;
    int cedula=0;

    cout << "BIENVENIDO AL SISTEMA DE GESTION DEL TIEMPO PARA ESTUDIANTES DE INGENIERIA ELECTRONICA :)" << endl << endl;
    cout << "Por favor selecciona la opcion:" << endl;
    cout << "[1] Gestionar mi tiempo" << endl << "[2] Registrarme en el sistema." << endl << endl;
    cin >> opcion;

    switch(opcion){
    case 1:

    break;

    case 2:
        cout << "Ingrese su numero de documento: ";
        cin >> cedula;

        if(registrarestudiante(cedula)) cout << "Registro exitoso!" << endl << endl;;
    break;
    }





    return 0;
}
