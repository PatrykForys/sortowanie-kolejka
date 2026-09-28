# Program sortujący liczby

 ## Opis programu

 Program został napisany w języku **C++**. Jego zadaniem jest wczytanie liczb całkowitych z pliku `dane.txt`, zapisanie ich w **liście jednokierunkowej**, posortowanie metodą **sortowania bąbelkowego** oraz zapisanie posortowanych danych do pliku `wynik.txt`.

 Program posiada proste menu tekstowe, za pomocą którego można wykonywać poszczególne operacje.

 ## Funkcje programu

 Program umożliwia:

 1. Wczytanie liczb z pliku `dane.txt`.
2. Posortowanie liczb metodą bąbelkową.
3. Wyświetlenie aktualnych danych na ekranie.
4. Zapisanie posortowanych liczb do pliku `wynik.txt`.
5. Zakończenie programu.

 ## Format pliku `dane.txt`

 Plik `dane.txt` powinien zawierać wyłącznie liczby całkowite oddzielone spacjami lub zapisane w osobnych liniach.

 Przykład:

```
41 22 1 2 5 6 3 43 9 25 64 11
```

 Program odczytuje każdą liczbę osobno i dodaje ją do listy.

 ## Przykład działania

 Po uruchomieniu programu pojawia się menu:

```
1. Wczytaj dane z pliku
2. Sortuj babelkowo
3. Wyswietl dane
4. Zapisz wynik do pliku
0. Zakoncz program
Podaj wybor:
```

 Po wybraniu opcji `1`:

```
Lista przed sortowaniem:
Numery: 41 22 1 2 5 6 3 43 9 25 64 11
```

 Po wybraniu opcji `2` liczby zostają posortowane rosnąco.

 Po wybraniu opcji `3`:

```
Dane:
Numery: 1 2 3 5 6 9 11 22 25 41 43 64
```

 Po wybraniu opcji `4` posortowane liczby zostają zapisane do pliku `wynik.txt`.

 ## Struktura danych

 Program wykorzystuje **listę jednokierunkową**.

 Każdy element listy przechowuje:

 - `wartosc` – liczbę całkowitą,
- `nastepny` – wskaźnik na następny element listy.

 Struktura elementu:

```
struct Element
{
    int wartosc;
    Element* nastepny;
};
```

 ## Sortowanie bąbelkowe

 Do sortowania wykorzystano algorytm **Bubble Sort**.

 Program porównuje ze sobą sąsiednie elementy listy. Jeżeli element po lewej stronie jest większy od elementu po prawej, ich wartości zostają zamienione.

 Operacja jest powtarzana do momentu, aż podczas całego przejścia nie zostanie wykonana żadna zamiana.

 Przykład:

```
41 22 1 2
```

 Po sortowaniu:

```
1 2 22 41
```

 ## Pliki programu

 Projekt składa się z:

```
projekt/
│
├── main.cpp
├── dane.txt
└── wynik.txt
```

 ### `main.cpp`

 Główny plik programu zawierający całą implementację listy, sortowania oraz menu.

 ### `dane.txt`

 Plik wejściowy zawierający liczby do posortowania.

 ### `wynik.txt`

 Plik wyjściowy, do którego zapisywane są posortowane liczby.

 ## Kompilacja

 Program można skompilować za pomocą kompilatora `g++`:

```
g++ main.cpp -o program
```

 Następnie uruchomić:

```
./program
```

 W systemie Windows można użyć:

```
g++ main.cpp -o program.exe
program.exe
```

 ## Wymagania

 - C++ w standardzie obsługującym `iostream` i `fstream`
- kompilator C++, np. GCC, MinGW lub Visual Studio
- plik `dane.txt` znajdujący się w tym samym katalogu co program

 ## Autor

 Projekt wykonany w języku C++.