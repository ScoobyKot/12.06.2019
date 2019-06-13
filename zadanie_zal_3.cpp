#include <iostream>

using namespace std;

template<class T>
class Array {
private:
    T *table; //deklaracja dynamicznej tablicy
    int cnt{}; // licznik zajętych elementów tablicy
    unsigned int capacity{}; // aktualny rozmiar tablicy
    //iterator
    int itr = 0;

public:

    Array(int initSize) // konstruktor
    {
        this->Resize(initSize);
        this->cnt = -1;

    }

    void Resize(int newSize) {         // funkcja zarządzająca dynamicznym rozmiarzem tablicy
        auto resized_table = new T[newSize];       //tworzy nową tablice , w którą przepisują się elementy przeszłej tablicy
        if (this->table != nullptr) {
            for (int i = 0; i < this->capacity; i++) {
                resized_table[i] = this->table[i];
            }
        }

        this->table = resized_table;
        this->capacity = newSize;
    }

    int check_arr() {
        int check_res = 0;
        for (int i = 0; i < this->capacity; i++) {
            if (table[i] % 5 == 0) { check_res++; }
        }
        return check_res;
    }
	// funkcja usuwa bieżący element tablicy, i zwraca true, jeśli operacja powiodła się
    bool erase() {
        int current_i = 0;
        auto resized_table = new T[this->capacity -1];       //tworzy nową tablice , w którą przepisują się elementy przeszłej tablicy
        if (this->table != nullptr) {
            for (int i = 0; i < this->capacity; i++) {
                if (i == this->itr) {
                    current_i++;
                }
                resized_table[i] = this->table[current_i];
                current_i++;
            }
        } else {
            return false;
        }

        this->table = resized_table;
        this->capacity--;
        this->itr--;
        return true;
    }


    void Add(T new_element) {  //dodawanie elementu

        if (this->cnt == this->capacity - 1) {
            this->Resize(this->capacity + 1);
        }

        this->table[this->cnt + 1] = new_element;
        this->cnt++;
    }


    ~Array() //destruktor
    {
        delete[]table;
    }

    int getItr() { return itr; } //Podaje iterator

    int getLength() { return capacity; } //Podaje rozmiar tablicy

    //Operator
    void operator++() //dodaje zeatEn
    {
        this->itr++;//    T *element;
        if (this->atEnd()) {
            this->itr = 0;
        }
    }

    //funkcja informują , czy iterator osiągł koniec kontenera
    bool atEnd() {
        if (this->itr == this->capacity) {
            cout << "Iterator na końcu" << endl;
            return true;
        }
        return false;
    }

    // funkcja zwracająca referencję do bieżącego (wskazywanego przez kursor) elementu tablicy
    T &get() {
        return (this->table[this->itr]);
    }


    //funkcja wypisuje zawartość tablicy this-> this->
    void Print() {
        cout << "Rozmiar tablicy : " << this->capacity << endl;
        for (int count = 0; count < this->capacity; ++count)
            cout << this->table[count] << ' ';
        cout << endl;
    }

};


int main() {
    Array<int> tabela(3); // tworzenie objektu klasa array
    tabela.Add(5);
    tabela.Add(3);
    tabela.Add(543);
    tabela.Add(1);
    tabela.Add(4);
    tabela.Add(5);
    tabela.Print();

	//przykład iteracji po Array<int>, podczas której usuwane są elementy podzielne na 5
    for (int i = 0; i < tabela.getLength(); i++) { 
        if (tabela.get() % 5 == 0) {
            tabela.erase();
        } else {
            cout << tabela.get() << " ";
        }
        ++tabela;
    }


    return 0;
}
