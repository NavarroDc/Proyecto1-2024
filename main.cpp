#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int opcionElegida;
    string cedula;
    string nombreCompleto;
    float talla = 0.0;
    float peso = 0.0;
    bool salir = false;
    bool cedulaValida = false;
    bool nombreValido = false;
    bool continuar = false;

    setlocale(LC_ALL, "");

    do {
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

        if(opcionErronea) {
            cout<<"Opci�n inv�lida, vuelva a intentarlo. Debe escribir un n�mero del 1 al 5."<<endl;
            cin.clear();
            cin.ignore();
            system("Pause");
            system("CLS");
        } else {
            switch(opcionElegida) {

            //CASO 1 PEDIR CEDULA Y NOMBRE
            case 1: {
                char espacio = ' ';
                // Preguntar hasta que la c�dula sea un n�mero
                do {
                    cout<<"Ingrese su n�mero de c�dula."<<endl;
                    cedula = "";
                    cin.clear();
                    cin.ignore();
                    getline(cin,cedula);
                    // � la c�dula son s�lo n�meros entre 1 a 9 d�gitos ?
                    int numeroDigitos = 0;


                    for ( char c : cedula) { // Para cada caracter en cedula
                        if (isdigit(c)) {//�El caracter actual es un digito?
                            numeroDigitos++;//Si lo es, el contador aumenta
                        }
                    }
                    //Verifica que los digitos contados sea igual al tama�o de (cedula) y que esa cantidad de digitos est� entre 1 y 15
                    if (numeroDigitos == cedula.length() &&  numeroDigitos >= 1 && numeroDigitos <= 15) {
                        //Si se cumple, la c�dula es v�lida
                        cedulaValida = true;
                        //Si no se cumple, debe escribir de nuevo la c�dula
                    } else {
                        cedulaValida = false;
                        cout<<"S�lo puede ingresar n�meros en el apartado de la c�dula."<<endl;
                    }
                    // � La c�dula es inv�lida ?
                } while(cedulaValida == false);

                cout<<"Ingrese su nombre con dos apellidos. "<<endl;

                // Preguntarle al usuario hassta que el nombre sea v�lido
                do {
                    cin.clear();
                    cin.ignore();
                    getline (cin, nombreCompleto);

                    int contadorEspacios = 0;
                    //Loop for recorre lo que hay en nombreCompleto
                    for (char i : nombreCompleto) {
                        //Condicional if indica que se encontr� un espacio
                        // � es el caracter actual (i) un espacio ?
                        if (i == espacio) {
                            contadorEspacios++;//Aumenta el contador en caso de que s�
                        }
                    }
                    //Condici�n de que los espacios en el string tenga que ser 2
                    //� la cantidad de espacio es diferente de 2 ?
                    if (contadorEspacios != 2) {
                        nombreValido = false;
                        cout << "Error, el nombre debe estar compuesto por 3 palabras y 2 espacios. Nombre ingresado:" << nombreCompleto << endl;
                        cout << " " << endl;
                        cout << "Ingrese de nuevo su nombre."<< endl;
                        nombreCompleto = ""; // limpiar el nombre para vaidarlo de nuevo
                    } else {
                        nombreValido = true;
                    }
                    //�El nombre es inv�lido? Si es inv�lido, se repite el lopp (do)
                } while(nombreValido == false);
                break;
            }

            case 2: {
                bool tallaValida = false;
                bool pesoValido = false;
                string tallaString = "";
                stringstream valorRedondeado;

                cout<<"Ingrese su talla en metros."<<endl;

                do {
                    cin>>talla;
                    int contadorTalla = 0;

                    for(char c : tallaString) {
                        if(isdigit(c) || c == '.') {
                            contadorTalla++;
                        }
                    }

                    if(contadorTalla == valorRedondeado.length()) {
                        valorRedondeado<<setprecision(2) << stof(valorRedondeado);
                        valorRedondeado>>talla;
                        if(talla >= 0.30 && talla <= 3.00) {
                            cout<<"La talla est� en el rango."<<endl;
                        } else {
                            cout<<"La talla est� en el rango."<<endl;
                        }
                    }else{
                          cout<<"No es un n�mero flotante v�lido."<<endl;
                    }
                } while(tallaValida == false);
            }


            }

        }
    } while(salir == false);


    return 0;
}


