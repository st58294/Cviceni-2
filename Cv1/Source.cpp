#include <iostream>

int a;
int b;
int c;
int obvod;
int pocet;

struct Trojuhelnik {
	int a;
	int b;
	int c;
};

bool lzeSestrojit(Trojuhelnik t) {
	if ((t.a + t.b) > t.c && (t.a + t.c) > t.b && (t.b + t.c) > t.a) {
		return true;
	}
	else {
		return false;
	}
}

bool lzeSestrojit(Trojuhelnik* t) {
	if ((t->a + t->b) > t->c && (t->a + t->c) > t->b && (t->b + t->c) > t->a) {
		return true;
	}
	else {
		return false;
	}
}

void vypis(Trojuhelnik t) {
	if (lzeSestrojit(t) == true) {
		obvod = t.a + t.b + t.c;
		std::cout << "Obvod trojuhelniku je: " << obvod << std::endl;
	}
	else {
		std::cout << "Takovy trojuhelnik sestrojit nelze" << std::endl;
	}
}

void vypis(Trojuhelnik* t) {
	if (lzeSestrojit(t) == true) {
		obvod = t->a + t->b + t->c;
		std::cout << "Obvod trojuhelniku je: " << obvod << std::endl;
	}
	else {
		std::cout << "Takovy trojuhelnik sestrojit nelze" << std::endl;
	}
}

int main(int argc, char** argv) {
	std::cout << "\n" << std::endl;
	std::cout << "Zadejte pocet trojuhelniku: " << std::endl;
	std::cin >> pocet;
	std::cout << "\n" << std::endl;

	Trojuhelnik* ukazatel = new Trojuhelnik[pocet];

	int poradi = 1;
	int indexNaPoli = 0;

	for (int i = 0; i < pocet; i++) {
		Trojuhelnik* testovaciTrojuhelnik = new Trojuhelnik;

		std::cout << "Zadejte stranu a " << poradi << ". trojuhelniku: " << std::endl;
		std::cin >> testovaciTrojuhelnik->a;

		std::cout << "Zadejte stranu b " << poradi << ". trojuhelniku: " << std::endl;
		std::cin >> testovaciTrojuhelnik->b;

		std::cout << "Zadejte stranu c " << poradi << ". trojuhelniku: " << std::endl;
		std::cin >> testovaciTrojuhelnik->c;

		std::cout << "\n" << std::endl;

		poradi++;

		if (lzeSestrojit(testovaciTrojuhelnik)) {
			ukazatel[indexNaPoli].a = testovaciTrojuhelnik->a;
			ukazatel[indexNaPoli].b = testovaciTrojuhelnik->b;
			ukazatel[indexNaPoli].c = testovaciTrojuhelnik->c;
			vypis(ukazatel[indexNaPoli]);
			indexNaPoli++;
		}

		std::cout << "\n" << std::endl;
	}

	delete[indexNaPoli] ukazatel;

	system("pause");
	return 0;
}
