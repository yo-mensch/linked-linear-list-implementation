#include <iostream>
#include <fstream>
#include <utility>      // std::pair, std::make_pair
using namespace std;
struct node
{
	int data;
	node* next;
};
ofstream fout("output.txt");
bool artuscias(node pradzia);
void pasalintipirmaelementa(node* pradzia);
void pasalintipaskutinielementa(node* pradzia);
void pasalintielementa(node* pradzia, int kelintas);
int elementuskaicius(node* pradzia);
///////////////////////////////////
void findNode(node* liststart, int t, bool failan);
void pushFront(node* listStart, int data);
void pushBack(node* listStart, int data);
void pushByIndex(node* listStart, int index, int data);
////////////////////////////
void rasyti(node* pradzia, bool failan);
void rasytiatvirksciai(node* pradzia, bool failan);
void nuskaitytipradiniusduomenis(node* pradzia); void meniu();
void suvestipradiniusduomenis(node* pradzia);
int main()
{
	cout << boolalpha;
	node pradzia;
	pradzia.data = NULL;
	pradzia.next = NULL;
	bool failan;

	cout << "ADS SAVARANKISKAS DARBAS 2. 12 uzd. Vienkryptis tiesinis sarasas.\n ";
	cout << "pradinius duomenis suvesti is failo[1] ar klaviaturos[0]?\n";
	cin >> failan;
	if (failan)	nuskaitytipradiniusduomenis(&pradzia);
	else suvestipradiniusduomenis(&pradzia);

	cout << "---------------------------\n";

	cout << "Pradinis sarasas: " << endl;
	rasyti(&pradzia, 0);
	fout << "Pradinis sarasas:\n";
	rasyti(&pradzia, 1);
	cout << endl;

	int ats = 1;
	int data, data1, choice, index;
	while (ats != 0) {
		meniu();
		cin >> ats;
		switch (ats)
		{
		case 1:
		{
			cout << "rasyti i faila? [1- taip, 0- ne]" << endl;
			cin >> failan;
			if (failan) fout << "sarasas tuscias: " << artuscias(pradzia) << endl;
			else cout << "sarasas tuscias: " << artuscias(pradzia) << endl;
			break;

		}
		case 2:
		{
			cout << "---------------------------\n";
			cout << "   1) Prideti elementa i saraso prieki" << endl;
			cout << "   2) Prideti elementa i saraso gala" << endl;
			cout << "   3) Prideti elementa pagal indeksa" << endl;
			cout << "---------------------------\n";
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				cout << "Iveskite pridedama reiksme: ";
				cin >> data1;
				pushFront(&pradzia, data1);
				break;
			}
			case 2:
			{
				cout << "Iveskite pridedama reiksme: ";
				cin >> data1;
				pushBack(&pradzia, data1);
				break;
			}
			case 3:
			{
				cout << "Iveskite pridedama reiksme ir indeksa: [1-" << elementuskaicius(&pradzia) << "] ";
				cin >> data1 >> index;
				pushByIndex(&pradzia, index, data1);
				break;
			}
			default:
				break;

			}
			rasyti(&pradzia, 0);
			cout << "rasyti i faila? [1- taip, 0- ne]" << endl;
			cin >> failan;
			rasyti(&pradzia, failan);
			break;
		}

		case 3:
		{
			cout << "---------------------------\n";
			cout << "   1) Pasalinti elementa is priekio " << endl;
			cout << "   2) Pasalinti elementa is galo" << endl;
			cout << "   3) Pasalinti elementa pagal indeksa" << endl;
			cout << "---------------------------\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				pasalintipirmaelementa(&pradzia);
				break;
			}
			case 2:
			{
				pasalintipaskutinielementa(&pradzia);
				break;
			}
			case 3:
			{
				cout << "Iveskite indeksa:  [1-" << elementuskaicius(&pradzia) << "] ";
				cin >> index;
				pasalintielementa(&pradzia, index);
				break;
			}

			default:
				break;
			}
			rasyti(&pradzia, 0);
			cout << "rasyti i faila? [1- taip, 0- ne]" << endl;
			cin >> failan;
			rasyti(&pradzia, failan);
			break;

		}
		case 4:
		{
			cout << "rasyti i faila? [1- taip, 0- ne]" << endl;
			cin >> failan;
			rasyti(&pradzia, failan);
			break;
		}
		case 5:
		{
			cout << "Iveskite reiksme, kuria norite rasti: ";
			cin >> data;
			cout << "rasyti i faila? [1- taip, 0- ne]" << endl;
			cin >> failan;
			findNode(&pradzia, data, failan);
			break;
		}

		case 6:
		{
			cout << "rasyti i faila? [1- taip, 0- ne]" << endl;
			cin >> failan;
			rasytiatvirksciai(pradzia.next, failan);
			if (failan) fout << endl;
			else cout << endl;
			break;
		}

		default:
			cout << "Patikrinkite output.txt faila" << endl;
			break;
		}
	}
	fout << "galutinis sarasas: \n";
	rasyti(&pradzia, 1);

	return 0;
}
void meniu()
{
	cout << "---------------------------\n";
	cout << "0) Baigti darba" << endl;
	cout << "1) Ar sarasas tuscias?" << endl;
	cout << "2) Prideti elementa" << endl;
	cout << "3) Pasalinti elementa" << endl;
	cout << "4) Perskaityti ir atspausdinti sarasa" << endl;
	cout << "5) Surasti elementa" << endl;
	cout << "6) Isvesti sarasa atvirkstine tvarka" << endl;
	cout << "---------------------------\n";

}
void suvestipradiniusduomenis(node* pradzia)
{
	int n;
	cout << "iveskite duomenu kieki: ";
	cin >> n;
	node* nod = NULL;
	node* ipraeita = pradzia;
	for (int i = 0; i < n; i++)
	{
		nod = new node;
		cin >> nod->data;
		nod->next = NULL;
		if (ipraeita != NULL)ipraeita->next = nod;
		ipraeita = nod;
	}

}
void nuskaitytipradiniusduomenis(node* pradzia)
{
	int n;
	ifstream fin("input.txt");
	fin >> n;
	node* nod = NULL;
	node* ipraeita = pradzia;
	for (int i = 0; i < n; i++)
	{
		nod = new node;
		fin >> nod->data;
		nod->next = NULL;
		if (ipraeita != NULL)ipraeita->next = nod;
		ipraeita = nod;
	}

	//delete ipraeita, nod;
}
bool artuscias(node pradzia)
{
	if (pradzia.next == NULL) return true;
	else return false;
}
void pasalintipirmaelementa(node* pradzia)
{
	node* e = new node;
	e->next = pradzia->next->next;
	pradzia->next = e->next;
	delete e;

}
void pasalintipaskutinielementa(node* pradzia)
{

	node* ptr = pradzia;
	while (ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	node* del = ptr->next->next;
	ptr->next = NULL;
	delete del;

}
void pasalintielementa(node* pradzia, int kelintas)
{
	if (kelintas == 1) pasalintipirmaelementa(pradzia);
	else if (kelintas == elementuskaicius(pradzia))
		pasalintipaskutinielementa(pradzia);
	else
	{
		node* ptr = pradzia;
		int i = 0;
		while (ptr != NULL)
		{
			i++;
			if (kelintas + 1 == i) break;
			ptr = ptr->next;
		}
		node* e;
		e = ptr->next;
		ptr->data = e->data;
		ptr->next = e->next;
		delete e;
	}

}
int elementuskaicius(node* pradzia)
{
	int counter = 0;
	node* ptr = pradzia;

	while (ptr != NULL)
	{
		ptr = ptr->next;
		counter++;
	}

	return counter;
}
///////////////////////////////////////////
void findNode(node* liststart, int t, bool failan) {
	node* n;
	n = liststart;
	while (n != NULL && n->data != t) {
		n = n->next;
	}
	if (n != NULL) {
		node* next = n->next;
		if (failan)
			fout << "Reiksme " << t << " rasta: " << n->data << ", pointina i " << n->next << " " << next->data << endl;
		else
			cout << "Reiksme " << t << " rasta: " << n->data << ", pointina i " << n->next << " " << next->data << endl;
	}
	else {
		if (failan)
			fout << "Reiksme " << t << " nerasta" << endl;
		else
			cout << "Reiksme " << t << " nerasta" << endl;

	}
}
void pushFront(node* listStart, int data) {
	node* naujas;
	if (listStart->next != NULL) {
		node* n;
		n = listStart->next;
		naujas = new node;
		naujas->data = data;
		naujas->next = n;
		listStart->next = naujas;
	}
	else {
		naujas = new node;
		naujas->data = data;
		naujas->next = NULL;
		listStart->next = naujas;
	}
}
void pushBack(node* listStart, int data) {
	node* n;
	node* naujas;
	naujas = new node;
	n = listStart;
	naujas->data = data;
	naujas->next = NULL;
	if (n != NULL) {
		while (n->next != NULL)
		{
			n = n->next;
		}
	}
	n->next = naujas;
}
void pushByIndex(node* listStart, int index, int data) {
	node* ptr = listStart;
	node* naujas;
	node* sekantis;
	naujas = new node;
	naujas->data = data;
	naujas->next = NULL;
	int i = 0;
	while (ptr != NULL) {
		if (i == index - 1) {
			sekantis = ptr->next;
			ptr->next = naujas;
			naujas->next = sekantis;
			break;
		}
		else {
			i++;
			ptr = ptr->next;
		}
	}
}
//////////////////////
void rasyti(node* pradzia, bool failan)
{
	node* nod = pradzia->next;
	while (nod != NULL)
	{
		if (failan)
		{
			fout << nod->data << " ";
		}
		else
		{
			cout << nod->data << " ";
		}

		nod = nod->next;
	}
	if (failan) fout << endl;
	else cout << endl;

}
void rasytiatvirksciai(node* pradzia, bool failan)
{
	if (pradzia == NULL)
		return;

	rasytiatvirksciai(pradzia->next, failan);

	if (failan) fout << pradzia->data << " ";
	else cout << pradzia->data << " ";
}