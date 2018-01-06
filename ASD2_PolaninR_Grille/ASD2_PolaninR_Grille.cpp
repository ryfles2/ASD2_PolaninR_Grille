#include <iostream>
#include <string>
using namespace std;

class grill
{
public:

	long size_ = 0;
	//2 tablice 1 na matryce 1 na wiadomoœæ
	char **tab_;
	char **tab_2;

	grill::grill()
	{
		tab_ = new char *;
		tab_2 = new char *;
	}
	grill::~grill()
	{
		for (int i = 0; i < size_; i++)
		{
			delete[] tab_[i];
			delete[] tab_2[i];
		}
		
		delete[] tab_;
		delete[] tab_2;
	}
	void SetSize(long _s)//ustawaianie rozmiaru tablic kwadratowych
	{
		size_ = _s;
		tab_ = new char * [size_];
		for (int i = 0; i < size_; i++)
		{
			tab_[i] = new char[size_];
		}
		tab_2 = new char *[size_];
		for (int i = 0; i < size_; i++)
		{
			tab_2[i] = new char[size_];
		}
			
	}
	void Dodaj()//wype³nianie tablic danymi
	{
	
		char x;
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				cin >> x;
				tab_[i][j] = x;
				//cout << tab_[i][j] << endl;
				
			}
		}
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				cin >> x;
				tab_2[i][j] = x;
				//cout << tab_2[i][j] << endl;
			}
		}

	}
	
	void Deszyfr()//deszyfrowanie i odczytywanie tablicy
	{
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				if (tab_[i][j]=='O')
				{
					cout << tab_2[i][j];
				}
				
			}
		}
	}

	void Odwracanie()//odwraca tablicê o 90 stopni
	{
		//kwadratowa tablica pomocnicza
		char ** tab_pom = new char *[size_];
		for (int i = 0; i < size_; i++)
		{
			tab_pom[i] = new char[size_];
		}


		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				tab_pom[j][i] = tab_[size_-1 - i][j];
			}
		}
		for (int i = 0; i < size_; i++)
		{
			for (int j = 0; j < size_; j++)
			{
				tab_[j][i] = tab_pom[j][i];
			}
		}

		for (int i = 0; i < size_; i++)
		{
			delete[] tab_pom[i];
		}
		delete[] tab_pom;
	}
	
		

};



int main()
{
	grill g;
	long pom=1;
	while (pom != 0)
	{
		cin >> pom;
		g.SetSize(pom);
		g.Dodaj();
		g.Deszyfr();
		g.Odwracanie();
		g.Deszyfr();
		g.Odwracanie();
		g.Deszyfr();
		g.Odwracanie();
		g.Deszyfr();
		cout << endl;
	} 

	return 0;
}