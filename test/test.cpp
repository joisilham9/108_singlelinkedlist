#include <iostream>
using namespace std;

struct node {
	int noMhs;
	string name;
	node* next;
};

node* STRAT = NULL;

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
}