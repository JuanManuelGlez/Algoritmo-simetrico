#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class algoritmoSimetrico {
private:
  int m = 0;
  string cadena;
  string llave;
  char matriz[10][10];
  char desplazarCaracter(char c, int val);
  void calculaDimensiones(string cadena);
  void llenarMatriz(string cadenaActual);
  void swapColumnas(int col1, int col2);
  string aplicaXOR(string cadenaActual);
  string desplazarCaracteres(int val);
  string matrizACadena();

  map<char, char> alfabetoCifrado = {
      {'0', 'a'}, {'1', 'l'}, {'2', 'P'}, {'3', 'T'}, {'4', '5'}, {'5', 'E'},
      {'6', 'R'}, {'7', 'W'}, {'8', 's'}, {'9', 'k'}, {'a', 'C'}, {'b', 'B'},
      {'c', '0'}, {'d', 'V'}, {'e', 'd'}, {'f', 'j'}, {'g', 'f'}, {'h', '4'},
      {'i', 'I'}, {'j', 'L'}, {'k', 'F'}, {'l', 'h'}, {'m', 'g'}, {'n', 'M'},
      {'o', 'q'}, {'p', '6'}, {'q', 'p'}, {'r', 'X'}, {'w', 'Z'}, {'s', 'w'},
      {'t', 'u'}, {'u', '9'}, {'v', 'e'}, {'x', 'S'}, {'y', 'N'}, {'z', 'y'},
      {'A', 'r'}, {'B', '3'}, {'C', 't'}, {'D', 'i'}, {'E', 'O'}, {'F', 'A'},
      {'G', 'o'}, {'H', 'z'}, {'I', '7'}, {'J', 'K'}, {'K', 'G'}, {'L', 'm'},
      {'M', 'x'}, {'N', 'J'}, {'O', '2'}, {'P', 'H'}, {'Q', 'D'}, {'R', 'b'},
      {'S', 'c'}, {'T', '8'}, {'U', 'v'}, {'V', 'U'}, {'W', 'n'}, {'X', 'Q'},
      {'Y', '1'}, {'Z', 'Y'}, {'?', '?'}};

  map<char, char> alfabetoDecifrado = {
      {'a', '0'}, {'l', '1'}, {'P', '2'}, {'T', '3'}, {'5', '4'}, {'E', '5'},
      {'R', '6'}, {'W', '7'}, {'s', '8'}, {'k', '9'}, {'C', 'a'}, {'B', 'b'},
      {'0', 'c'}, {'V', 'd'}, {'d', 'e'}, {'j', 'f'}, {'f', 'g'}, {'4', 'h'},
      {'I', 'i'}, {'L', 'j'}, {'F', 'k'}, {'h', 'l'}, {'g', 'm'}, {'M', 'n'},
      {'q', 'o'}, {'6', 'p'}, {'p', 'q'}, {'X', 'r'}, {'Z', 'w'}, {'w', 's'},
      {'u', 't'}, {'9', 'u'}, {'e', 'v'}, {'S', 'x'}, {'N', 'y'}, {'y', 'z'},
      {'r', 'A'}, {'3', 'B'}, {'t', 'C'}, {'i', 'D'}, {'O', 'E'}, {'A', 'F'},
      {'o', 'G'}, {'z', 'H'}, {'7', 'I'}, {'K', 'J'}, {'G', 'K'}, {'m', 'L'},
      {'x', 'M'}, {'J', 'N'}, {'2', 'O'}, {'H', 'P'}, {'D', 'Q'}, {'b', 'R'},
      {'c', 'S'}, {'8', 'T'}, {'v', 'U'}, {'U', 'v'}, {'n', 'W'}, {'Q', 'X'},
      {'1', 'Y'}, {'Y', 'Z'}, {'?', '?'}};

public:
  string encriptar(string cadena, string llave);
  string desencriptar (string cadena,string llave);
};

void algoritmoSimetrico::calculaDimensiones(string cadena) {
  m = ceil(sqrt(cadena.length()));
}

void algoritmoSimetrico::llenarMatriz(string cadenaActual) {
  int posF = 0;
  int posC = 0;
  for (int i = 0; i < cadenaActual.length(); i++) {
    matriz[posF][posC] = cadenaActual[i];
    posC++;
    if (posC >= m) {
      posF++;
      posC = 0;
    }
  }

  for (int i = posF; i < m; i++) {
    for (int j = posC; j < m; j++) {
      matriz[i][j] = '?';
    }
    posC = 0;
  }
}

string algoritmoSimetrico::matrizACadena() {
  string cadenaRes = "";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cadenaRes += matriz[i][j];
    }
  }

  return cadenaRes;
}

void algoritmoSimetrico::swapColumnas(int col1, int col2) {
  for (int i = 0; i < m; i++) {
    swap(matriz[i][col1], matriz[i][col2]);
  }
}

string algoritmoSimetrico::desplazarCaracteres(int val) {
  string cadenaNueva = "";
  for (int i = 0; i < cadena.length(); i++) {
    cadenaNueva += desplazarCaracter(cadena[i], val);
  }
  return cadenaNueva;
}

char algoritmoSimetrico::desplazarCaracter(char c, int val) {

  for (int i = 0; i < val; i++) {
    if (c == 32) {
      break;
    } else if (c >= 48 && c < 57) {
      c = c + 1;
    } else if (c == 57) {
      c = c + 8;
    } else if (c >= 65 && c < 90) {
      c = c + 1;
    } else if (c == 90) {
      c = c + 7;
    } else if (c >= 97 && c < 122) {
      c = c + 1;
    } else if (c == 122) {
      c = 48;
    } else {
      c = 63;
    }
  }
  return (char)c;
}

void stream2hex(const string str, string& hexstr, bool capital = false)
{
    hexstr.resize(str.size() * 2);
    const size_t a = capital ? 'A' - 1 : 'a' - 1;

    for (size_t i = 0, c = str[0] & 0xFF; i < hexstr.size(); c = str[i / 2] & 0xFF)
    {
        hexstr[i++] = c > 0x9F ? (c / 16 - 9) | a : c / 16 | '0';
        hexstr[i++] = (c & 0xF) > 9 ? (c % 16 - 9) | a : c % 16 | '0';
    }
}

void hex2stream(const string hexstr, string& str)
{
    str.resize((hexstr.size() + 1) / 2);

    for (size_t i = 0, j = 0; i < str.size(); i++, j++)
    {
        str[i] = (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) << 4, j++;
        str[i] |= (hexstr[j] & '@' ? hexstr[j] + 9 : hexstr[j]) & 0xF;
    }
}

string algoritmoSimetrico::aplicaXOR(string cadenaActual) {
  int posL = 0;
  
  string res="";
  for (int i = 0; i < cadenaActual.length(); i++) {
    res +=(cadenaActual[i] ^ llave[posL]);
    posL++;
    if (posL >= llave.length()) {
      posL = 0;
    }
  }
    
  return res;
}

string algoritmoSimetrico::encriptar(string c, string l) {
  cadena = c;
  llave = l;
  string cadenaActual = "";
  calculaDimensiones(cadena);

  cadenaActual = desplazarCaracteres(llave[1]);

  llenarMatriz(cadenaActual);
  for (int i = llave.length() - 1; i > 0; i -= 2) {
    swapColumnas((int)llave[i] % m, (int)llave[i - 1] % m);
  }
  cadenaActual = matrizACadena();
  for (int i = 0; i < cadenaActual.length(); i++) {
    cadenaActual[i] = alfabetoCifrado[cadenaActual[i]];
  }
  cadenaActual = aplicaXOR(cadenaActual);
  cout<<"XOR="+ cadenaActual;
  stream2hex(cadenaActual,cadenaActual,true);
  return cadenaActual;
}

string algoritmoSimetrico::desencriptar(string c, string l){
    hex2stream(c,c);
    string cadenaActual=aplicaXOR(c);
    calculaDimensiones(cadenaActual);
    for(int i=0;i<cadenaActual.length();i++){
        cadenaActual[i] = alfabetoDecifrado[cadenaActual[i]];
    }
    llenarMatriz(cadenaActual);
    for (int i = llave.length() - 1; i > 0; i -= 2) {
    swapColumnas((int)llave[i] % m, (int)llave[i - 1] % m);
    }
    cadenaActual = matrizACadena();
    cout<<cadenaActual;

    return cadenaActual;
    
}
