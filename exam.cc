
//Ohjelma joka kysyy käyttäjältä nimen, opiskelijanumeron ja 6 eri tenttitehtävän pisteet
//ja laskee pisteet yhteen sekä kirjoittaa tulokset .csv tiedostoon.
//Hannu Ranta

//Include-direktiivit
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

//Avataan nimiavaruus
using namespace std;

//Pääohjelma
int main()
{
  //Alustetaan muuttujat
  string nimi = "";
  int piste = 0;
  int opnumero = 0;
  int summa = 0;

  //Määritellään virtamuuttuja
  ofstream virta;

  //Avataan tulostiedosto append-moodissa
  virta.open("Tulokset_hannu.csv", fstream::app);

  //Silmukka, jossa tietoja kysytään
  while (true)
    {
      //Kysytään opiskelijan nimeä
      cout << "Syötä nimi (Etunimi Sukunimi):" << endl;
      getline(cin,nimi);

      //Jos käyttäjä painoi 'q' poistutaan ohjelmasta
      if (nimi == "q")
	{
	  break;
	}

      //Kysytään opiskelijanumeroa
      cout << "Syötä opiskelijanumero:" << endl;
      cin >> opnumero;

      //Syötetään opnumero ja nimi virtaan
      virta << opnumero << ":"; 
      virta << nimi << ":";

      //Kysytään for-silmukassa tehtävien pistemäärät ja lasketaan yhteispisteet summa-muuttujaan
      for (int i = 0; i < 10; ++i)
	{
	  cout << "Tehtävä " << i + 1 << ":" << endl;
	  cin >> piste;

	  //Tulostetaan piste virtaan
	  virta << piste << ":";

	  summa = summa + piste;
	}

      //Tulostetaan summa virtaan
      virta << summa << endl;

      //Nollataan muuttujat
      nimi.clear();
      opnumero = 0;
      piste = 0;
      summa = 0;

      //Tyhjennetään lukuvirta
      cin.ignore(100,'\n');
    }
 
  //Lopetetaan paluuarvolla 0.
  return EXIT_SUCCESS;
}
