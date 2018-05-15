# The-game-of-life

Task in Polish:

Gra w życie
Gra w życie jest jednym z pierwszych i najbardziej znanych przykładów automatu komórkowego. Została ona wymyślona w roku 1970 przez brytyjskiego matematyka Johna Conwaya.

Gra toczy się na prostokątnej planszy, podzielonej na kwadratowe komórki o boku długości jeden. Każda komórka ma ośmiu sąsiadów – przylegających bokami i stykających się wierzchołkami, za wyjątkiem brzegów planszy, gdzie tych sąsiadów jest mniej.
Każda komórka jest żywa lub martwa. W każdej turze gry, najpierw wszystkie komórki (zarówno żywe jak i martwe) obliczają liczbę swoich żywych sąsiadów. Następnie, w tym samym momencie, wszystkie komórki zmieniają swój stan według następujących reguł:
komórka z dokładnie trzema żywymi sąsiadami staje się żywa, niezależnie od swojego poprzedniego stanu,
komórka z dokładnie dwoma żywymi sąsiadami nie zmienia się (żywa pozostaje żywa, martwa pozostaje martwa),
w pozostałych przypadkach komórka umiera.
Grupą żywych komórek będziemy nazywali takie skupisko żywych komórek, w którym każda żywa komórka albo sąsiaduje z inną żywą z grupy komórką, albo sąsiaduje martwą komórką, która to z kolei sąsiaduje z żywą komórką z grupy. Na poniższym przykładzie kropki oznaczają martwe komórki, zaś litery opisują żywe komórki z podziałem na grupy:

A.A.A....D
..........
A.A.A.....
..........
.......C.C
BBB......C
BBB...CCCC

Zadanie polega na obliczeniu K-tej tury gry (plansza startowa jest turą zerową) i znalezieniu na niej największej grupy żywych komórek.
Wejście
Na wejściu podane zostaną szerokość (x) wysokość (y) planszy oraz liczba tur K. Żaden wymiar nie będzie mniejszy niż 3 i większy niż 100, zaś liczba tur będzie się zawierać w przedziale od 0 do 10000. W kolejnych liniach y pojawi się opis planszy początkowej. Każda linia będzie zawierać x znaków . (kropka) lub # (hasz). Kropka oznacza martwą komórkę, znak # oznacza żywą.
Wyjście
Na wyjściu należy wypisać jedną liczbę – liczbę żywych komórek w największej grupie w K-tej turze gry.


Przykład

Wejście
7 7 21
.#.....
..#....
###....
.......
.......
.......
.......


Wyjście
4
