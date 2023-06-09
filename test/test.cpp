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
		if (nim == current->noMhs)
		{
			cout << "Nim sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}

	bool serachNode(int nim, node * current, node * previous) {
		previous = START;
		current = START;
		while (current != NULL && nim > current->noMhs);
		{
			previous = current;
			current = current->next;
		}

		if (current == NULL)
		{
			return false;
		}
		else if (current->noMhs == nim)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool deletenode(int nim) {
		node* current = START;
		node* previous = START;
		if (serachNode(nim, previous, current) == false)
			return false;
		previous->next = current->next;
		if (current == START)
			START = current->next;
		return true;
}
	bool listEmpty() {
		if (START == NULL)
			return true;
		else
			return false;

	}

	void traverse() {
		if (listEmpty()) {
			cout << "list kosong" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			node* currentNode = START;
			while (currentNode != NULL) {
				cout << "Nim:" << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
				currentNode = currentNode->next;
			}
		}
	}

	void searchData() {
		if (listEmpty()) {
			cout << "list kosong" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			int nim;
			cout << "masukkan NIM: ";
			cin >> nim;
			node* currentNode = START;
			while (currentNode != NULL) {
				if (currentNode->noMhs == nim) {
					cout << "NIM:" << currentNode->noMhs << ",Nama: " << currentNode->name << endl;
					return;
				}
				currentNode = currentNode->next;
			}
			cout << "Data tidak ditemukan" << endl;
		}
	}

	int main() {
		int pilihan;
		do
		{
			try
			{
				cout << "1.tambah data" << endl;
				cout << "2.hapus data" << endl;
				cout << "3.tampilkan data" << endl;
				cout << "4.cari data" << endl;
				cout << "5.keluar" << endl;
				cin >> pilihan;
				switch (pilihan)
				{
				case 1:
					addNode();
					cout << "data berhasil ditambakan" << endl;
					system("pause");
					system("cls");
					break;
				case 2:
					if (listEmpty())
					{
						cout << "list kosong" << endl;
						system("pause");
						system("cls");
						break;
					}
					int nim;
					cout << "masukan nim: ";
					cin >> nim;
					if (deletenode(nim)) {
						cout << "nim: " << nim << "berhasil dihapus " << endl;
						system("pause");
						system("cls");
					}
					else
						cout << "data tidak ditemukan" << endl;
					break;
				case 3:
					traverse();
					break;
				case 4:
					searchData();
					break;
				case 5:
					break;
				default:
					cout << "pilihan tidak ada " << endl;
					break;
				}
			}
			catch (exception e) 
			{
				cout << "terjadi kesalahan" << endl;
			}
		} while (pilihan != 5);
	}


