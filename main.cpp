#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <limits>

using namespace std;

int main()
{
    int opcionElegida;
    int cedula;
    string nombreCompleto;
    float talla;
    float peso;
    bool salir = false;
    bool cedulaValida = false;
    bool nombreValido = false;
    bool continuar = false;

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
            cout<<"Opci�n inv�lida, vuelva a intentarlo. Debe escribir un n�mero del 1 al 5."<<endl;
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
                char espacio = ' ';
                int contadorEspacios = 0;

                    cout<<"Ingrese su n�mero de c�dula."<<endl;
                    cin>>cedula;
                    if(cedula >= 1 && cedula <= 999999999)
                    {
                     cedulaValida = true;

                    }
                    else{ do
                             {
                                cout<<"S�lo puede ingresar n�meros en el apartado de la c�dula."<<endl;
                                cout<<" "<<endl;
                                cout<<"Digite de nuevo la c�dula."<<endl;
                                cin>>cedula;

                             } while(continuar = false);
                         }



                      cout<<"Ingrese su nombre con dos apellidos."<<endl;
                      cin>>nombreCompleto;
                      for (char i : nombreCompleto)
                      if (i == espacio)
                      {
                        nombreValido = true;
                        contadorEspacios++;
                      }

                      do{ if (contadorEspacios != 2)
                            {
                                nombreValido = false;
                                cout << "Debe ingresar �nicamente su nombre con dos apellidos." << endl;
                            }
                        }while(nombreValido = false);

                  break;
              }


            }

        }
    }
    while(salir = false);


    return 0;
}


