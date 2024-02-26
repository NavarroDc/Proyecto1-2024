#include <iostream>
#include <wchar.h>
#include <locale.h>
#include <limits>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    setlocale(LC_CTYPE,"Spanish");


    int opcionElegida;
    string cedula = "";
    string nombreCompleto = "";
    float talla = 0.0f;
    float peso = 0.0f;
    float imc = 0.0f;
    bool salir = false;
    bool cedulaValida = false;
    bool nombreValido = false;
    bool continuar = false;

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
                    if (numeroDigitos == cedula.length() &&  numeroDigitos >= 1 && numeroDigitos <= 15 ) {
                        //Si se cumple, la cédula es válida
                        cedulaValida = true;
                        //Si no se cumple, debe escribir de nuevo la cédula
                    } else {
                        cedulaValida = false;
                        cout<<"Sólo puede ingresar números en el apartado de la cédula."<<endl;
                        cout<<" "<<endl;

                    }
                    // ¿ La cédula es inválida ?
                } while(cedulaValida == false);

                cout<<"Ingrese su nombre con dos apellidos. "<<endl;

                // Preguntarle al usuario hassta que el nombre sea válido
                do {
                    //cin.clear();
                    //cin.ignore();
                    getline (cin, nombreCompleto);
                    system("CLS");

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
            //CASO 2 PEDIR TALLA Y PESO CORPORAL
            case 2: {
                //¿Se ingresó el nombre y la cédula en la opción 1?
                if(nombreCompleto.length() != 0 && cedula.length() != 0) {

                    bool tallaValida = false; //Variable para continuar preguntando una talla válida en loop do/while
                    bool pesoValido = false; //Variable para continuar preguntando un peso válido en loop do/while
                    string pesoString = ""; //Variable de peso que ingresa el usuario para la conversión
                    string tallaString = ""; //Variable de talla que ingresa el usuario para la conversión
                    cout<<"Ingrese su talla en metros. Ejemplo: 1.80"<<endl;

                    //Pregunta una talla hasta que sea válida
                    do {
                        talla = 0.0f; //Se inicializa la variable talla en un número flotante
                        tallaString= "";//Se inicializa en una string vacío lo que ingresa el usuario cada vez que se repite
                        cin.ignore();//Ignorar el primer espacio en el dato ingresado
                        cin>>tallaString;

                        int contadorTalla = 0;
                        //Ciclo for recorre cada caracter de la talla ingresada ´por el usuario
                        for(char c : tallaString) {
                            //¿El caracter es un digito o un punto?
                            if(isdigit(c) || c == '.') {
                                //Si lo hay el contador de talla aumenta +1
                                contadorTalla++;
                            }
                        }
                        //¿El contador de talla contiene los mismo caracteres de tallaString?
                        if(contadorTalla == tallaString.length()) {
                            talla = stof(tallaString);//Convierte el string a un float
                            //¿La talla está entre 0.30 y 3.00?
                            if(talla >= 0.30 && talla <= 3.00) {
                                cout<<"La talla está en el rango. " <<fixed<<setprecision(2)<< talla <<endl;
                                cout<<" " <<endl;
                                tallaValida = true;
                            } else {
                                cout<<"La talla no está en el rango. "<<fixed<<setprecision(2)<< talla <<endl;
                                cout<<" "<<endl;

                                tallaValida = false;
                            }
                        } else {
                            cout<<"No es una talla válida."<<endl;
                            tallaValida = false;
                        }
                    } while(tallaValida == false);//El loop do se repite mientras la talla sea inválida

                    cout<<"Ingrese su peso corporal en kilogramos."<<endl;

                    //Verifica un peso hasta que sea válido
                    do {
                        peso = 0.0f;
                        pesoString = "";
                        cin.ignore();
                        cin>> pesoString;
                        //Se limpia la variable
                        int contadorPeso = 0;
                        //Recorre cada caracter de lo que ingresó el usuario
                        for(char c : pesoString) {
                            //¿El caracter es un digito o un punto?
                            if(isdigit(c) || c == '.') {
                                //Si lo es, el contador aumenta +1
                                contadorPeso++;
                            }
                        }
                        //¿El contador peso contiene los mismos caracteres de pesoString?
                        if(contadorPeso == pesoString.length()) {
                            peso = stof(pesoString);//Convierte el string a float

                            //¿El peso está entre 30 y 350?
                            if(peso >= 30 && peso <=350) {
                                cout<<" "<<endl;
                                cout<<"El peso está en el rango. " <<fixed<<setprecision(2)<< peso <<endl;
                                cout<<" "<<endl;
                                pesoValido = true;
                            } else {
                                cout<<" "<<endl;
                                cout<<"El peso no está en el rango. " <<fixed<<setprecision(2)<< peso <<endl;
                                cout<<" "<<endl;
                            }
                        } else {
                            cout<<"No es un peso válido."<<endl;
                            pesoValido = false;

                        }

                    } while(pesoValido == false);//El loop se va repetir mientras el peso sea inválido

                    //¿Ya ingresó cédula y nombre?
                } else {
                    cout<<"Error, debe ingresar la cédula y el nombre antes de ingresar a esta opción."<<endl;
                }
                system("Pause");
                break;
            }
            //CASO 3 CÁLCULO DEL IMC
            case 3: {

                //¿Se ingresó talla y peso antes?
                if(talla != 0.0 && peso != 0.0) {

                    cout<<"Cálculo del índice de masa corporal."<<endl;
                    cout<<" "<<endl;
                    cout<<"El índice de masa corporal (IMC) se calcula según la siguiente f\xA1rmula: IMC = peso (kg)/ [estatura (m)]^2"<<endl;

                    //Se limpia el imc cada vez que se repite
                    imc = 0.0f;

                    cin.ignore();
                    std::setprecision(2);//Para imprimir números a dos decimales

                    imc = peso / (talla*talla);//Fórmula imc

                    cout<<"Su índice de masa corporal (IMC) es: "<<fixed<<setprecision(2)<<imc<<endl;
                    //¿El imc es menor a 18.5?
                    if(imc < 18.5) {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de peso insuficiente."<<endl;
                        //¿El imc está entre 18.5 y 24.9?
                    } else if(imc >= 18.5 && imc <= 24.9) {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de peso normal o saludable."<<endl;
                        //¿El imc está entre 25.0 y 29.9?
                    } else if(imc >= 25.0 && imc <= 29.9) {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de sobrepeso."<<endl;
                        //¿El imc es mayor a 30.0?
                    } else {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de obesidad."<<endl;
                    }
                    //¿Ya ingresó talla y peso?
                } else {
                    cout<<"Error, debe ingresar la talla y el peso antes de ingresar a esta opción."<<endl;
                }
                system("Pause");
                break;
            }
            //CASO 4 SE MUESTRA EL REPORTE
            case 4: {
                //¿Los datos del paciente fueron ingresados?
                if(nombreCompleto.length() != 0 && cedula.length() != 0 && talla != 0.0 && peso != 0.0) {

                    cout<<"Reporte de información del paciente."<<endl;
                    cout<<" "<<endl;
                    cout<<"Céduladula: "<< cedula <<endl;
                    cout<<" "<<endl;
                    cout<<"Nombre: "<<nombreCompleto<<endl;
                    cout<<" "<<endl;
                    cout<<"Peso: "<<peso<<" kg"<<endl;
                    cout<<" "<<endl;
                    cout<<"Talla: "<<talla<<" m"<<endl;
                    cout<<" "<<endl;
                    cout<<"IMC: "<<imc<<endl;
                    cout<<" "<<endl;
                    cout<<"Diagnóstico: "<<endl;
                    cout<<" "<<endl;
                    //¿El IMC se encuentra en los rangos correctos?
                    if(imc < 18.5) {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de peso insuficiente."<<endl;
                        cout<<" "<<endl;
                        //¿El imc está entre 18.5 y 24.9?
                    } else if(imc >= 18.5 && imc <= 24.9) {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de peso normal o saludable."<<endl;
                        cout<<" "<<endl;
                        //¿El imc está entre 25.0 y 29.9?
                    } else if(imc >= 25.0 && imc <= 29.9) {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de sobrepeso."<<endl;
                        cout<<" "<<endl;
                        //¿El imc es mayor a 30.0?
                    } else {
                        cout << " " << endl;
                        cout<<"Se encuentra dentro del rango de obesidad."<<endl;
                        cout<<" "<<endl;
                    }
                  //En caso de que no se ingrese a las opciones en orden
                } else {
                    cout<<"Debe ingresar primero la información del paciente."<<endl;
                }
                system("Pause");
                break;
            }

            case 5:{
                //Salir del programa
                cout<<"Saliendo del programa..."<<endl;
                system("Pause");
                salir = true;
            }

            }

        }
        system("CLS");

    } while(salir == false);


    return 0;
}


