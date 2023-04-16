#include <lib1.h>
#include <fstream>

using namespace std;

int main()
{
    char* nombrearchivo;
    nombrearchivo = new char[20];

    cout << "Ingrese el nombre del archivo (Máx. 20 caracteres): ";
    cin.getline(nombrearchivo, 20);


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
    return 0;
}
