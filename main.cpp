#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <limits>

using namespace std;

int main()
{
    int opcionElegida;
    string cedula;
    string nombreCompleto;
    float talla;
    float peso;
    bool salir = false;

    setlocale(LC_ALL, "");

    do
    {

        cout<<"C�lculos de acuerdo al peso de la persona."<<endl;
        cout<<" "<<endl;
        cout<<"1. Ingresar datos de la persona."<<endl;
        cout<<"2. Ingresar datos f�sicos."<<endl;
        cout<<"3. Calcular el �ndice de masa corporal."<<endl;
        cout<<"4. Reporte de informaci�n del paciente."<<endl;
        cout<<"5. Salir."<<endl;
        cout<<" "<<endl;
        cout<<"Elija una opci�n."<<endl;
        cin>>opcionElegida;
        system("Pause");
        system("CLS");
        bool opcionErronea = cin.bad() || !(opcionElegida >= 1 && opcionElegida <= 5);

        if(opcionErronea)
        {
            cout<<"Opci�n inv�lidad, vuelva a intentarlo. Debe escribir un n�mero del 1 al 5."<<endl;
            cin.clear();
            cin.ignore();
            system("Pause");
            system("CLS");

        }
        else
        {
            switch(opcionElegida)
            {

            case 1:
            {
               do{cout<<"Ingrese su n�mero de c�dulasss."<<endl;


               }while()

                break;
            }

            case 2:
            {

                break;
            }

            case 3:
            {
                cout<<"op3"<<endl;
                break;
            }

            case 4:
            {
                cout<<"op4"<<endl;
                break;
            }

            case 5:
            {
                cout<<"Saliendo del programa..."<<endl;
                salir = true;
                break;
            }
            default:{cout<<"Opci�n inv�lidad, vuelva a intentarlo. Debe escribir un n�mero del 1 al 5."<<endl;}
            }


        }


    }
    while(salir == false);


    return 0;
}


