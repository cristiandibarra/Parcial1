#include <lib1.h>
#include <fstream>

using namespace std;

int main()
{       
    int opcion=0;
    int cedula=0;
    int codigo=0;


    /*
    cout << "BIENVENIDO AL SISTEMA DE GESTION DEL TIEMPO PARA ESTUDIANTES DE INGENIERIA ELECTRONICA :)" << endl << endl;
    cout << "Por favor selecciona la opcion:" << endl;
    cout << "[1] Gestionar mi tiempo" << endl << "[2] Registrarme en el sistema." << endl << endl;
    cin >> opcion;

    switch(opcion){
    case 1:

        //int selector=0;

        cout << "Ingrese su numero de documento: ";
        cin >> cedula;

        cout << "Ingresa la opcion: " << endl << endl;
        cout << "[1] Gestionar manualmente." << endl << "[2] Permitir que el sistema genere de forma alearotia." << "[3] Reiniciar matricula." << endl << endl;
        //cin >>selector;

        int** horario=new int*[7];
        for (int i = 0; i < 7; i++) {
            *(horario+i) = new int[15];
        }
        cout << "Tu horario es: ";

        delete[] horario;
    break;

    case 2:

        cout << "Ingrese su numero de documento: ";
        cin >> cedula;

        bool estado=true;

        if(buscardocumento(cedula)!=""){
            cout << "El documento ya se encuentra registrado. Intente nuevamamente." << endl << endl;
            return 0;
        }

        cout << "Registra tu primera materia!" << endl << endl;
        estado=registrardocumeto(cedula);
        if(estado==false) cout << "Ocurrio un error durante el registro." << endl << endl;

        while(estado){
            char* dias;
            dias = new char[2];
            char dia;
            int hora1=0;
            int hora2=0;

            *(dias)='_';
            *(dias+1)='_';
            *(dias+2)='\0';

            cout << "Ingresa el codigo de la materia: ";
            cin >> codigo;
            cout << endl << endl;

            imprimircurso(codigo);                   //Funcion para imprimir los datos del curso

            if(creditosmateria(codigo)==4){
                cout << "Ingresa los dias en que matriculaste las clases teoricas (Ejemplo: WV): ";
                cin >> *(dias) >> *(dias+1);
                cout << endl;
                cout << "Ingresa la hora de inicio de estas clases (Formato de 24 horas): ";
                cin >> hora1;
                cout << endl;
                cout << "Ingresa el dia en que matriculaste la clase practica (Ejemplo: J): ";
                cin >> dia;
                cout << endl;
                cout << "Ingresa la hora de inicio de esta clase (Formato de 24 horas): ";
                cin >> hora2;

                if(registrarmateria4(codigo, dias, hora1, dia, hora2)) cout << "Materia registrada con exito!" << endl << endl;
            }

            if(creditosmateria(codigo)==3){
                cout << "Ingresa los dias en que matriculaste las clases teoricas (Ejemplo: WV): ";
                cin >> *(dias) >> *(dias+1);
                cout << endl;
                cout << "Ingresa la hora de inicio de estas clases (Formato de 24 horas): ";
                cin >> hora1;
                cout << endl;

                if(registrarmateria3(codigo, dias, hora1)) cout << "Materia registrada con exito!" << endl << endl;
            }

            cout << "Desea registrar otra materia?      [0]NO       [1]SI";
            cin >> estado;

            delete[] dias;
        }



    break;

    }
    */
    //imprimirhorario(1018374996);
    int**horario;
    horario=obtenerhorario(1018374996);
    imprimirhorario(horario);

    delete[] horario;

    return 0;
}
