//Karla Sofia Gómez Tobar  9959-21-1896
#include <iostream>

using namespace std;

//esta es la clase base de todo
class comida {
  public:
    void numbercalorias() {
      cout << "Los comida suele tener muchas calorias \n" ;
    }
};


class pizza : public comida {
  public:
    void numbercalorias() {
      cout << "La pizza tiene mas de 1500 calorias \n" ;
    }
};


class ensalada : public comida {
  public:
    void numbercalorias() {
      cout << "la ensalada tiene 150 calorias \n" ;
    }
};

class chocolate : public comida {
  public:
    void numbercalorias() {
      cout << "El chocolate tiene 100 calorias \n" ;
    }
};

int main() {
  comida Lacomida;
  pizza Esapizza;
  ensalada EsaEnsalada;
  chocolate Esechocolate;

  Lacomida.numbercalorias();
  Esapizza.numbercalorias();
  EsaEnsalada.numbercalorias();
  Esechocolate.numbercalorias();
  return 0;
}
