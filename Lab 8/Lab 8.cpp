#include <iostream>
using namespace std;
void swap(int *q, int *y);
int srednia(int *tablica, int rozmiar);
void dodawanie(int* tablica, int* tablica2, int rozmiar);
void mnozenie(int* tablica, int* tablica2, int rozmiar);
int max(int* tablica, int* tablica2, int rozmiar);
int min(int* tablica, int* tablica2, int rozmiar);

int main() {

	/*
	//zadanie 2.1
	const int size = 3;
	int tab[size] = { 1,2,3 }; // deklaracja tablicy tab o wielkosci size
	for (int i = 0; i < size; i++) {
		cout << i << "\t" << &tab[i] << endl;; // indeks, wartość
	}

	int* ptr;
	for (int i = 0; i < size; i++) { 
		//przypisanie adresów kolejnych elementów tablicy tab do zmiennej wskaźnikowej ptr
		ptr = &tab[i]; //zmienne ptr wskazuje na kolejne ele. tablicy tab[i]
		cout << i << "\t" << *ptr << "\t" << ptr << endl; // indeks, wartość, adres
	}

	//zadnie 2.2
	int* p;
	p = tab; // wskazuje n pierwszy element tablicy, to samo co p = &tab[0]
	for (int i = 0; i < size; i++) {
		cout << p << "\t" << *p << endl;
		p++; //przejscie do kolejnego elementu tablicy
	}

	//zadanie 2.3
	int a = 10;
	int b = 20;
	swap(&a, &b);
	cout << a << "\t" << b << endl;


	// zadanie 1
	int x;
	int* wskx;
	wskx = &x;

	cout << "podaj wartosc zmiennej x: ";
	cin >> x;
	cout << *wskx << endl;

	//zadanie 2
	int jakas_tablica[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int* wsk;
	for (int i = 0; i < 10; i++) {
		cout << jakas_tablica[i] << endl;
	}
	cout << endl;
	wsk = &jakas_tablica[7];
	*wsk = 77;
	for (int i = 0; i < 10; i++) {
		cout << jakas_tablica[i] << endl;
	}
	cout << endl;

	//zadanie 2.1
	int tablica[10] = { 0,0,0,0,0,0,0,0,0,0};
	int* wsktab;
	wsktab = &tablica[0];
	for (int i = 0; i < 10; i++) {
		*wsktab = 9;
		cout << *wsktab << endl;
		wsktab++;
	}

	//zadanie 3
	int rozmiar;
	float* wskk;
	cout << "Podaj rozmiar tablicy 1-wymiarowej: ";
	cin >> rozmiar;

	float* tablicaa = new float[rozmiar]; // po poleceiu new wpisuje typ 
	// danych jakie maja byc przechowywane w komórkach

	for (int i = 0; i< rozmiar; i++) {
		*(tablicaa+i) = i;
		cout << *(tablicaa+i) << endl;
	}

	wskk = &tablicaa[rozmiar-1];
	
	while(1){
		if (*wskk == 0.0) {
			break;
		}
		wskk--;
	}

	delete[] tablicaa;
	
	//zadanie 4
	int rozmiar;
	cout << "Podaj wielkosc tablicy: ";
	cin >> rozmiar;

	int* tablica = new int[rozmiar];
	cout << "Srednia arytmetyczna: " << srednia(tablica, rozmiar);

	delete[] tablica;
	*/
	//zadanie 5
	int rozmiar, wartosc;
	cout << "Podaj rozmiar tablic: ";
	cin >> rozmiar;

	int* tablica = new int[rozmiar];
	int* tablica2 = new int[rozmiar];

	for (int i = 0; i < rozmiar; i++) {
		cout << "Podaj wartosc: ";
		cin >> wartosc;
		*tablica = wartosc;
		tablica++;
	}

	for (int i = 0; i < rozmiar; i++) {
		cout << "Podaj wartosc: ";
		cin >> wartosc;
		*tablica2 = wartosc;
		tablica2++;
	}

	tablica = tablica - rozmiar;
	tablica2 = tablica2 - rozmiar;

	cout << "Suma: " << endl;
	dodawanie(tablica, tablica2, rozmiar);
	cout << endl << "Iloczyn: " << endl;
	mnozenie(tablica, tablica2, rozmiar);
	cout << endl;
	cout << "Roznica: " << (max(tablica, tablica2, rozmiar) - min(tablica, tablica2, rozmiar));

	delete[] tablica;
	delete[] tablica2;
}
void dodawanie(int* tablica, int* tablica2, int rozmiar) {

	for (int i = 0; i < rozmiar; i++) {
		cout << (*tablica + *tablica2)<< '\t';
		tablica++;
		tablica2++;
	}
}
void mnozenie(int* tablica, int* tablica2, int rozmiar) {

	for (int i = 0; i < rozmiar; i++) {
		cout << (*tablica * *tablica2)<< '\t';
		tablica++;
		tablica2++;
	}
}
int max(int* tablica, int* tablica2, int rozmiar) {
	int aktualnyMAX = *tablica;
	for (int i = 1; i < rozmiar; i++) {
		tablica++;
		if (aktualnyMAX < *tablica) {
			aktualnyMAX=*tablica;
		}
	}
	cout << "Maksymalny element tablicy nr.1 : " << aktualnyMAX << endl;
	return aktualnyMAX;

}
int min(int* tablica, int* tablica2, int rozmiar) {
	int aktualnyMIN = *tablica;
	for (int i = 1; i < rozmiar; i++) {
		tablica++;
		if (aktualnyMIN > *tablica) {
			aktualnyMIN = *tablica;
		}
	}
	cout << "Minimalny element tablicy nr.1 : " << aktualnyMIN << endl;
	return aktualnyMIN;

}
int srednia(int* tablica, int rozmiar) {
	srand(time(NULL));
	int suma=0;

	for (int i = 0; i < rozmiar; i++) {
		*tablica = rand();
		suma += *tablica;
		tablica++;
	}

	return (suma / rozmiar);

}
void swap(int *q, int *y) {
	int c;
	c = *q; // zapamietujemy to co był w int a
	*q = *y; // do a wpisuje wartość b; do "pustego" wskazniki przypisuje wartosc drugiego wskaznika
	*y = c; // do b wpisuje dawną wartość a; teraz *y jest "pusty, dlatego przypisuje do niego wartosc w c
}