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
    float talla = 0.0f;
    float peso = 0.0f;
    float imc = 0.0f;
    bool salir = false;
    bool cedulaValida = false;
    bool nombreValido = false;
    bool continuar = false;

    do {
        cout<<"C\xA0lculoss de acuerdo al peso de la persona."<<endl;
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
                bool tallaValida = false; //
                bool pesoValido = false;
                string pesoString = "";
                string tallaString = ""; // desde CIN
                cout<<"Ingrese su talla en metros. Ejemplo: 1.80m "<<endl;
                do {
                    talla = 0.0f;
                    tallaString= "";
                    cin.ignore();
                    std::setprecision(2);
                    cin>>tallaString;

                    int contadorTalla = 0;

                    for(char c : tallaString) {
                        if(isdigit(c) || c == '.') {
                            contadorTalla++;
                        }
                    }

                    if(contadorTalla == tallaString.length()) {
                        talla = stof(tallaString);

                        //cout << "Analizando.... " << tallaString << " ----> " << fixed <<  setprecision(2) << talla << endl;

                        if(talla >= 0.30 && talla <= 3.00) {
                            cout<<"La talla est� en el rango. " << talla <<endl;
                            tallaValida = true;
                        } else {
                            cout<<"La talla no est� en el rango. "<< talla <<endl;
                            tallaValida = false;
                        }
                    } else {
                        cout<<"No es un n�mero flotante v�lido."<<endl;
                        tallaValida = false;
                    }
                } while(tallaValida == false);

                cout<<"Ingrese su peso corporal en kilogramos."<<endl;
                do {
                    peso = 0.0f;
                    pesoString = "";
                    cin.ignore();
                    std::setprecision(2);
                    cin>> pesoString;

                    int contadorPeso = 0;

                    for(char c : pesoString) {
                        if(isdigit(c) || c == '.') {
                            contadorPeso++;
                        }
                    }
                    if(contadorPeso == pesoString.length()) {
                        peso = stof(pesoString);

                        if(peso >= 30 && peso <=350) {
                            cout<<"El peso est� en el rango. " << peso <<endl;
                            pesoValido = true;
                        } else {
                            cout<<"El peso no est� en el rango. " << peso <<endl;
                        }
                    } else {
                        cout<<"No es un n�mero flotante v�lido."<<endl;
                        pesoValido = false;
                    }
                } while(pesoValido == false);

                break;
            }

            case 3: {

                cout<<"C�lculo del �ndice de masa corporal."<<endl;
                cout<<" "<<endl;
                cout<<"El �ndice de masa corporal (IMC) se calcula seg�n la siguiente f�rmula: IMC = peso (kg)/ [estatura (m)]^2"<<endl;


                imc = 0.0f;
                //imcString = "";
                cin.ignore();
                std::setprecision(2);

                imc = peso / (talla*talla);

                cout<<"Su �ndice de masa corporal (IMC) es: "<< imc <<endl;

            }
            }

        }
    } while(salir == false);


    return 0;
}


