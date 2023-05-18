#include <iostream>
using namespace std;

struct node {
	int noMhs;
	string name;
	node* next;
};

node* START = NULL;

void addNode() {
	int nim;
	string nama;
	node* nodeBaru = new node();
	cout << "masukan NIM";
	cin >> nim;
	cout << "masukan NAMA";
	cin >> nama;
	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}

	}
}