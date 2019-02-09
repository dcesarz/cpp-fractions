#include <iostream>
#include <string>

class ZlyUlamek
{
public:
	friend std::ostream& operator <<(std::ostream& out, ZlyUlamek & u)
	{
		out << "zly mianownik!" << std::endl;
		return out;
	}
};

class Ulamek {

private:
	int licznik;
	int mianownik;

public:
	Ulamek(int licznik, int mianownik) { 
		this->licznik = licznik;
		if (mianownik == 0) throw ZlyUlamek();
		this->mianownik = mianownik;
	};

	friend std::ostream& operator << (std::ostream& out, Ulamek & u);
	

};

std::ostream& operator << (std::ostream& out, Ulamek & u){
	out << u.licznik;
	out << "/";
	out << u.mianownik << std::endl;
	return out;
};



int main() {
	try {
		Ulamek u1(2, 3);
		std::cout << u1;
		}

	catch (ZlyUlamek zu)
	{
		std::cout << zu;
	}
	system("PAUSE");
}
