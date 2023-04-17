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


    /*
    ofstream archivo("estudiantes.txt", ios::app);
    int documento=0;
    int codigo=0;
    int creditos=0;
    int tipoc=0;
    int hora=0;
    char* dias;
    dias = new char[2];
    bool estado=true;

    cout << "Ingrese el numero de documento: ";
    cin >> documento;

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

            cout << "Cuantos creditos tiene la materia?: ";
            cin >> creditos;

            if(creditos==1 || creditos==3){
                cout << "El curso es de 2 o 4 horas?: ";
                cin >> tipoc;
                cout << endl;

                *(dias)='_';
                *(dias+1)='_';
                *(dias+2)='\0';

                if(tipoc==2){
                    cout << "Ingrese el dia en que matriculó el curso: ";
                    cin >> *(dias);
                    cout << endl;
                    archivo << *(dias);
                }
                else if(tipoc==4){
                    cout << "Ingrese los días en que matriculo los cursos: ";
                    cin >> *(dias) >> *(dias+1);
                    cout << endl;
                    for(int i=0; i<2; i++) archivo << *(dias+i);
                }
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


    delete[] dias;
    */


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int documento=0;
    bool existe=false;
    cout << "Ingrese el numero de documento: ";
    cin >> documento;
    cout << endl;

    existe=buscardocumento(documento);
    if(existe) cout << "El documento esta registrado!" << endl << endl;
    else cout << "El documento no exixte." << endl << endl;



    return 0;
}
