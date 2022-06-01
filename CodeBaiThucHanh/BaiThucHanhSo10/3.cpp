#include <bits/stdc++.h>
using namespace std;
/*Tao cau truc sinh vien*/
struct SinhVien{
	char soBD[20], hoTen[30];
	float diemThi;
};
/*Tao cau truc danh sach lien ket don*/
struct Node {
	SinhVien *data;
	Node *pNext;
};
struct LinkerList {
	Node *pHead;
	Node *pTail;
};
/*Khoi tao danh sach lien ket don*/
void Init(LinkerList *&list) {
	list = new LinkerList;
	list->pHead = list->pTail = NULL;
}
/*Nhap thong tin sinh vien*/
SinhVien *nhapSinhVien(void) {
	SinhVien *sv = new SinhVien;
	cout << "Nhap so bao danh: ";
	fflush(stdin);
	gets(sv->soBD);
	cout << "Nhap ho va ten: ";
	fflush(stdin);
	gets(sv->hoTen);
	cout << "Nhap tong diem thi: ";
	cin >> sv->diemThi;
	return sv;
}
//Tao node sinh vien
Node *CreateNode(SinhVien *sv) {
	Node *pNode = new Node;
	if(pNode!=NULL) {
		pNode->data = sv;
		pNode->pNext = NULL;
	} else {
		cout<<"cap phat bo nho that bai!!!";
	}
	return pNode;
}
//Them node vao dau sanh sach
void InsertFirst(LinkerList *&list, SinhVien *sv) {
	Node *pNode = CreateNode(sv);
	if(list->pHead == NULL) {
		list->pHead = list->pTail = pNode;
	} else {
		pNode->pNext = list->pHead;
		list->pHead = pNode;
	}
}
//Them node vao cuoi danh sach
void InsertLast(LinkerList *&list, SinhVien *sv) {
	Node *pNode = CreateNode(sv);
	if(list->pHead == NULL) {
		list->pHead = pNode;
	} else {
		Node *pTmp = list->pHead;

		while(pTmp->pNext != NULL) {
			pTmp = pTmp->pNext;
		}
		pTmp->pNext = pNode;
	}
}
//Hien thi danh sach
void PrintList(LinkerList *list) {
	Node *pTmp = list->pHead;
	if(pTmp == NULL) {
		cout << "Danh sach rong";
		return;
	}
	cout << setw(20) << "So bao danh" << setw(30) << "Ho va ten" << setw(20) << "Tong diem thi" << endl;
	while(pTmp != NULL) {
		SinhVien *sv = pTmp->data;
		cout << setw(20) << sv->soBD << setw(30) << sv->hoTen << setw(20) << sv->diemThi << endl;
		pTmp = pTmp->pNext;
	}
}
/* Ðem so phan tu trong danh sach*/
int SizeOfList(LinkerList *list) {
	Node *pTmp = list->pHead;
	int nSize = 0;
	while(pTmp != NULL) {
		pTmp = pTmp->pNext;
		nSize++;
	}
	return nSize;
}
/*Chen vao giua danh sach*/
void InsertMid(LinkerList *&list, int pos, SinhVien *sv) {
	if(pos < 0 || pos >= SizeOfList(list)) {
		cout<<"Khong chen duoc!!!";
		return;
	}
	if(pos == 0) {
		InsertFirst(list, sv);
	} else if(pos == SizeOfList(list)-1) {
		InsertLast(list, sv);
	} else {
		Node *pNode = CreateNode(sv);
		Node *pIns = list->pHead;
		Node *pPre = NULL;
		int i = 0;
		while(pIns != NULL) {
			if(i == pos)
				break;
			pPre = pIns;
			pIns = pIns ->pNext;
			i++;
		}
		pPre ->pNext = pNode;
		pNode->pNext = pIns;
	}
	cout << "\nThong tin sinh vien sau khi chen:" << endl;
	PrintList(list);
}
int main() {
	LinkerList *list;
	Init(list);
	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
		SinhVien *a = nhapSinhVien();
		InsertLast(list, a);
	}
	cout << "Thong tin sinh vien vua nhap:" << endl;
	PrintList(list);
	cout << "\nNhap thong tin sinh vien chen vao vi tri thu 3: " << endl;
	SinhVien *sv = nhapSinhVien();
	InsertMid(list, 2, sv);
	return 0;
}

