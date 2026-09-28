#include <iostream>
#include <fstream>

using namespace std;

// Element listy jednokierunkowej
struct Element
{
    int wartosc;
    Element* nastepny;
};

class Sortowanie
{
private:
    Element* pierwszy; // poczatek listy

public:

    // Konstruktor
    Sortowanie()
    {
        pierwszy = nullptr;
    }

    // Dodawanie liczby na koniec listy
    void dodajElement(int liczba)
    {
        Element* nowyElement = new Element;

        nowyElement->wartosc = liczba;
        nowyElement->nastepny = nullptr;

        if (pierwszy == nullptr)
        {
            pierwszy = nowyElement;
        }
        else
        {
            Element* pomocniczy = pierwszy;

            while (pomocniczy->nastepny != nullptr)
            {
                pomocniczy = pomocniczy->nastepny;
            }

            pomocniczy->nastepny = nowyElement;
        }
    }

    // Wczytywanie liczb z pliku
    void wczytajDane()
    {
        ifstream wejscie("dane.txt");

        wyczyscListe();

        int liczba;

        // Wczytywanie kolejnych liczb
        while (wejscie >> liczba)
        {
            dodajElement(liczba);
        }

        wejscie.close();

        cout << "lista przed sortowaniem:" << endl;

        wyswietl();
    }

    // Wyswietlanie elementow listy
    void wyswietl()
    {
        if (pierwszy == nullptr)
        {
            cout << "lista jest pusta." << endl;
            return;
        }

        Element* aktualny = pierwszy;

        cout << "numery: ";

        while (aktualny != nullptr)
        {
            cout << aktualny->wartosc << " ";
            aktualny = aktualny->nastepny;
        }

        cout << endl;
    }

    // Sortowanie babelkowe
    void sortujBabelkowo()
    {
        if (pierwszy == nullptr)
        {
            cout << "lista jest pusta." << endl;
            return;
        }

        bool zmiana;

        do
        {
            zmiana = false;

            Element* aktualny = pierwszy;

            // Porownywanie sasiednich elementow
            while (aktualny->nastepny != nullptr)
            {
                if (aktualny->wartosc > aktualny->nastepny->wartosc)
                {
                    // Zamiana wartosci miejscami
                    int pomoc = aktualny->wartosc;

                    aktualny->wartosc = aktualny->nastepny->wartosc;
                    aktualny->nastepny->wartosc = pomoc;

                    zmiana = true;
                }

                aktualny = aktualny->nastepny;
            }

        } while (zmiana);

        cout << "posortowano." << endl;
    }

    // Zapis posortowanych danych do pliku
    void zapiszWynik()
    {
        if (pierwszy == nullptr)
        {
            cout << "lista jest pusta." << endl;
            return;
        }

        ofstream wyjscie("wynik.txt");

        Element* aktualny = pierwszy;

        // Zapisywanie kazdej liczby w osobnej linii
        while (aktualny != nullptr)
        {
            wyjscie << aktualny->wartosc << endl;
            aktualny = aktualny->nastepny;
        }

        wyjscie.close();

        cout << "zapisano do pliku wynik.txt." << endl;
    }

    // Usuwanie wszystkich elementow listy
    void wyczyscListe()
    {
        while (pierwszy != nullptr)
        {
            Element* usuwany = pierwszy;

            pierwszy = pierwszy->nastepny;

            delete usuwany;
        }
    }


    // Destruktor
    ~Sortowanie()
    {
        wyczyscListe();
    }
};

int main()
{
    Sortowanie lista;

    int opcja;

    do
    {
        // Menu programu
        cout << endl;
        cout << "1. wczytaj dane z pliku" << endl;
        cout << "2. sortuj babelkowo" << endl;
        cout << "3. wyswietl dane" << endl;
        cout << "4. zapisz wynik do pliku" << endl;
        cout << "0. zakoncz program" << endl;

        cout << "podaj wybor: ";
        cin >> opcja;

        cout << endl;

        switch (opcja)
        {
            case 1:
                lista.wczytajDane();
                break;

            case 2:
                lista.sortujBabelkowo();
                break;

            case 3:
                cout << "dane:" << endl;
                lista.wyswietl();
                break;

            case 4:
                lista.zapiszWynik();
                break;

            case 0:
                cout << "program zakonczony." << endl;
                break;
        }

    } while (opcja != 0);

    return 0;
}

