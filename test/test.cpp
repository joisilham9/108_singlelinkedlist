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
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	node* previous = START;
	node* current = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs) {
			cout << "Nim sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}
	
	bool serachNode(int nim, node * current, node * previous);
	{
		previous = START;
		current = START;
		while (current != NULL && nim > current->noMhs);
		{
			previous = current;
			current = current->next;
		}

}
}