#include "algoritmoSimetrico.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// transposicion revolver por segmentos entre la cadena misma
// XOR con la cadena completa
// diccionario para susticion nosotros mismos
// desplazamiento

// 48 al 57 num
// 65 al 90 mayusculas
// 97 al 122 minusculas
// 32 espacio no moverle ahi
int main() {
  int x = 0, flag = 0;
  algoritmoSimetrico clave;
  while (flag == 0) {
    cout << "Presione 1 para Encriptar, 2 para Desencriptar, 3 para salir: \n";
    cin >> x;
    if (x == 1) {
      string cadena, llave;
      cout << "Escriba la cadena a cifrar : ";
      cin >> cadena;
      cout << "Escriba la llave : ";
      cin >> llave;
      string encriptada = clave.encriptar(cadena, llave);
      cout <<"Clave encriptada="+ encriptada;
      flag = 1;
    } else if (x == 2) {
      string cadena, llave;
      cout << "Escriba la cadena a descifrar: ";
      cin >> cadena;
      cout << "Escriba la llave: ";
      cin >> llave;
      string desencriptada = clave.desencriptar(cadena, llave);
      cout<< desencriptada;
      flag = 1;
    } else if (x == 3) {
      flag = 1;
    } else {
      cout << "Intentelo otra vez";
    }
  }
}