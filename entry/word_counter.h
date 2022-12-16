#pragma once
#include "entry.h"
#include <vector>
#include <ostream>

/*
Zadanie polega na zaimplementowaniu klasy word_counter z
wykorzystaniem kolekcji vector z biblioteki standardowej oraz klasy
entry z poprzedniego zadania.
Klasa word_counter powinna udostępniać:
Konstruktor domyślny tworzący pusty licznik (konkretyzację
szablonu vector dla entry).
Metodę add_word dodającą do bieżącego licznika słowo, które
jest parametrem metody (wartość to liczba wystąpień tego
słowa).
Metodę size dającą liczbę różnych słów w liczniku.
Metody sort_alpha i sort_count sortujące zawartość licznika
alfabetycznie lub według częstości wystąpień.
Klasę iteratora const_iterator pozwalającą na przechodzenie
(bez modyfikacji) przez elementy licznika.

Klasę wykorzystamy do policzenia częstości użycia słów przez
Melville’a w Moby Dick.
word_counter md_cnt;
ifstream is("moby_dick.txt");
if (!is) {
cout << "Error opening input file.\n";
return 1;
}
string word;
while (is >> word) {
md_cnt.add_word(word);
}
is.close();
// to oczywiście zły pomysł
cout << md_cnt << "\n";
*/

class word_counter {
    std::vector<entry> word_cnt;
public:
    typedef std::vector<entry>::const_iterator const_iterator;
    const_iterator end() const;
    const_iterator begin() const;
    int add_word(const std::string& word);
    size_t size() const;
	void sort_alpha();
	void sort_count();
    
	friend std::ostream& operator<<(std::ostream& os, const word_counter& wc);
};
