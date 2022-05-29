#include <bits/stdc++.h>
using namespace std;
typedef int KeyType;
typedef struct Node {
	KeyType Key;
	struct Node * Left;
	struct Node * Right;
} Node;
typedef Node * BST;
/*Tao cay tim kiem nhi phan rong*/
void makenullBST(BST *T) {
	*T = NULL;
}
/*Kiem tra xem cay rong hay khong*/
int emptyBST(BST T) {
	return T == NULL;
}
/*Duyet tien tu*/
void preOrder(BST T) {
	if (T != NULL) {
		cout << T->Key << "  ";
		preOrder(T->Left);
		preOrder(T->Right);
	}
}
/*Duyet trung tu*/
void inOrder(BST T) {
	if (T != NULL) {
		inOrder(T->Left);
		cout << T->Key << "  ";
		inOrder(T->Right);
	}
}
/*Duyet hau tu*/
void posOrder(BST T) {
	if (T != NULL) {
		posOrder(T->Left);
		posOrder(T->Right);
		cout << T->Key << "  ";
	}
}
/*Tim kiem khoa X trong cay T*/
BST search(KeyType X, BST T) {
	if (T == NULL) return NULL;
	if (T->Key == X) return T;
	if (T->Key > X) return search(X, T->Left);
	return search(X, T->Right);
}
/*Chen khoa X vao cay T*/
void insertNode(KeyType X, BST *T) {
	if (*T == NULL) {
		*T = (Node*)malloc(sizeof(Node));
		(*T)->Key = X;
		(*T)->Left = NULL;
		(*T)->Right = NULL;
	} else if ((*T)->Key > X) insertNode(X, &(*T)->Left);
	else if((*T)->Key < X) insertNode(X, &(*T)->Right);
}
/*Xoa khoa X khoi cay T*/
KeyType deleteMax(BST *T) {
	KeyType k;
	if ((*T)->Right == NULL) {
		k = (*T)->Key;
		(*T) = (*T)->Left;
		return k;
	} else return deleteMax(&(*T)->Right);
}
/*Xoa 1 node tren cay*/
void deleteNode(KeyType X, BST *T) {
	if (*T != NULL)
		if ((*T)->Key > X) deleteNode(X, &(*T)->Left);
		else if ((*T)->Key < X) deleteNode(X, &(*T)->Right);
		else if ((*T)->Left == NULL and (*T)->Right == NULL) *T = NULL;
		else if ((*T)->Left == NULL) *T = (*T)->Right;
		else if ((*T)->Right == NULL) *T = (*T)->Left;
		else (*T)->Key = deleteMax(&(*T)->Left);
}
int n, a[20];
void createBST(BST *T) {
	makenullBST(T);
	KeyType X;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap cac key:\n";
	for (int i = 1; i <= n; i++) {
		cin >> X;
		insertNode(X, T);
		a[i - 1] = X;
	}
}
/*Tim cha cua mot nut*/
BST getParent(KeyType X, BST T) {
	BST P = T, Parent = NULL;
	while(P != NULL) {
		if (P->Key == X) return Parent;
		Parent = P;
		if (P->Key > X) P = P->Left;
		else P = P->Right;
	}
	return NULL;
}
int main () {
	BST T, P;
	createBST(&T);
	cout << "\n\n----------------github: huyngo2002----------------\n";
	cout << "\nDanh sach duyet tien tu:\n";
	preOrder(T);
	cout << "\nDanh sach duyet trung tu:\n";
	inOrder(T);
	cout << "\nDanh sach duyet hau tu:\n";
	posOrder(T);
	cout << "\nDanh sach sau khi chen nut co khoa 35 vao cay:\n";
	insertNode(35, &T);
	inOrder(T);
	if (search(48, T) != NULL)
		cout << "\nTim thay nut co khoa 48 tren cay\n";
	else
		cout << "\nKhong tim thay nut co khoa 48 tren cay";
	if (getParent(58, T) != NULL)
		cout << "\nCha cua nut co khoa 58 la: " << getParent(58, T)->Key;
	else
		cout << "\nKhong tim thay cha cua nut co khoa 58 trong cay";
	cout << "\nDanh sach sau khi xoa nut co khoa 55 tren cay:\n";
	deleteNode(55, &T);
	inOrder(T);
	return 0;
}
/*
Input:
12
50 40 60 10 20 30 10 15 65 55 45 58
*/
