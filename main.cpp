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
        cout<<"Cálculos de acuerdo al peso de la persona."<<endl;
        cout<<" "<<endl;
        cout<<"1. Ingresar datos de la persona."<<endl;
        cout<<"2. Ingresar datos físicos."<<endl;
        cout<<"3. Calcular el índice de masa corporal."<<endl;
        cout<<"4. Reporte de información del paciente."<<endl;
        cout<<"5. Salir."<<endl;
        cout<<" "<<endl;
        cout<<"Elija una opción."<<endl;
        cin>>opcionElegida;
        system("Pause");
        system("CLS");
        bool opcionErronea = cin.bad() || !(opcionElegida >= 1 && opcionElegida <= 5);

        if(opcionErronea) {
            cout<<"Opción inválida, vuelva a intentarlo. Debe escribir un número del 1 al 5."<<endl;
            cin.clear();
            cin.ignore();
            system("Pause");
            system("CLS");
        } else {
            switch(opcionElegida) {

            //CASO 1 PEDIR CEDULA Y NOMBRE
            case 1: {
                char espacio = ' ';
                // Preguntar hasta que la cédula sea un número
                do {
                    cout<<"Ingrese su número de cédula."<<endl;
                    cedula = "";
                    cin.clear();
                    cin.ignore();
                    getline(cin,cedula);
                    // ¿ la cédula son sólo números entre 1 a 9 dígitos ?
                    int numeroDigitos = 0;


                    for ( char c : cedula) { // Para cada caracter en cedula
                        if (isdigit(c)) {//¿El caracter actual es un digito?
                            numeroDigitos++;//Si lo es, el contador aumenta
                        }
                    }
                    //Verifica que los digitos contados sea igual al tamaño de (cedula) y que esa cantidad de digitos esté entre 1 y 15
                    if (numeroDigitos == cedula.length() &&  numeroDigitos >= 1 && numeroDigitos <= 15) {
                        //Si se cumple, la cédula es válida
                        cedulaValida = true;
                        //Si no se cumple, debe escribir de nuevo la cédula
                    } else {
                        cedulaValida = false;
                        cout<<"Sólo puede ingresar números en el apartado de la cédula."<<endl;
                    }
                    // ¿ La cédula es inválida ?
                } while(cedulaValida == false);

                cout<<"Ingrese su nombre con dos apellidos. "<<endl;

                // Preguntarle al usuario hassta que el nombre sea válido
                do {
                    cin.clear();
                    cin.ignore();
                    getline (cin, nombreCompleto);

                    int contadorEspacios = 0;
                    //Loop for recorre lo que hay en nombreCompleto
                    for (char i : nombreCompleto) {
                        //Condicional if indica que se encontró un espacio
                        // ¿ es el caracter actual (i) un espacio ?
                        if (i == espacio) {
                            contadorEspacios++;//Aumenta el contador en caso de que sí
                        }
                    }
                    //Condición de que los espacios en el string tenga que ser 2
                    //¿ la cantidad de espacio es diferente de 2 ?
                    if (contadorEspacios != 2) {
                        nombreValido = false;
                        cout << "Error, el nombre debe estar compuesto por 3 palabras y 2 espacios. Nombre ingresado:" << nombreCompleto << endl;
                        cout << " " << endl;
                        cout << "Ingrese de nuevo su nombre."<< endl;
                        nombreCompleto = ""; // limpiar el nombre para vaidarlo de nuevo
                    } else {
                        nombreValido = true;
                    }
                    //¿El nombre es inválido? Si es inválido, se repite el lopp (do)
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
                            cout<<"La talla está en el rango."<<endl;
                        } else {
                            cout<<"La talla está en el rango."<<endl;
                        }
                    }else{
                          cout<<"No es un número flotante válido."<<endl;
                    }
                } while(tallaValida == false);
            }


            }

        }
    } while(salir == false);


    return 0;
}


