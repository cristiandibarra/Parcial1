#include <lib1.h>
#include <fstream>

using namespace std;

int main()
{       
    int opcion=0;
    int cedula=0;
    int codigo=0;

    cout << "BIENVENIDO AL SISTEMA DE GESTION DEL TIEMPO PARA ESTUDIANTES DE INGENIERIA ELECTRONICA :)" << endl << endl;
    cout << "Por favor selecciona la opcion:" << endl;
    cout << "[1] Gestionar mi tiempo" << endl << "[2] Registrarme en el sistema." << endl << endl;
    cin >> opcion;
    cout << endl;


    switch(opcion){
    case 1:{

        cout << "Ingrese su numero de documento: ";
        cin >> cedula;

        cout << "Ingresa la opcion: " << endl << endl;
        cout << "[1] Gestionar manualmente." << endl << "[2] Permitir que el sistema genere de forma alearotia." << endl << endl;
        //cin >>selector;

        int** horario=obtenerhorario(cedula);
        int* lista;
        int nmaterias=0;
        int tiempo=0;
        bool state=true;
        int n=0;
        int d=0;
        int h=0;

        cout << "Tu horario es: " << endl << endl;
        imprimirhorario(horario);

        cout << endl << endl;
        cout << "Actualmente tienes: " << cantidadmaterias(cedula) << " materias matriculadas." << endl;
        cout << "Necesitas estudiar: " << endl << endl;

        lista=listamaterias(cedula);
        nmaterias=cantidadmaterias(cedula);

        for(int i=0; i<nmaterias; i++){
            tiempo=((creditosmateria(*(lista+i))*48)/16)-(cantidadhorasmateria(*(lista+i), horario));
            cout << i+1 << ". " << nombremateria(*(lista+i)) << " " << tiempo << " horas." << endl;
        }

        cout << endl << endl;

        while(state){
            cout << "Por favor ingresa el numero de la materia para incluirla en el horario de repaso: " << endl;
            for(int k=0; k<nmaterias; k++){
                cout << "[" << k+1 << "] " << nombremateria(*(lista+k)) << "." << endl;
            }
            cin >> n;
            cout << endl << endl;
            cout << "Selecciona el dia: " << endl << endl;
            for(int j=0; j<7; j++){
                cout << j+1 << ". " << diachar(j) << endl;
            }
            cin >> d;
            cout << endl << endl;
            cout << "Selecciona la hora (de 6 a 21): " << endl << endl;
            cin >> h;

            if(horario[d-1][h-1]!=0) cout << "Espacio ocupado." << endl;
            else horario[d-1][h-6]=*(lista+n-1)*-1;

            cout << endl << "Tu horario queda: " << endl;
            imprimirhorario(horario);

            cout << "Necesitas estudiar: " << endl << endl;

            lista=listamaterias(cedula);
            nmaterias=cantidadmaterias(cedula);

            for(int i=0; i<nmaterias; i++){
                tiempo=((creditosmateria(*(lista+i))*48)/16)-(cantidadhorasmateria(*(lista+i), horario));
                cout << i+1 << ". " << nombremateria(*(lista+i)) << " " << tiempo << " horas." << endl;
            }

            for(int i=0; i<nmaterias; i++){
                tiempo=((creditosmateria(*(lista+i))*48)/16)-(cantidadhorasmateria(*(lista+i), horario));
                if(tiempo==0) state=false;
                else state=true;
            }
        }

        delete[] lista;
        delete[] horario;
    }

    break;

    case 2:{

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


    }
    break;

    }


    return 0;
}
