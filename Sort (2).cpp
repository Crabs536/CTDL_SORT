#include "structSinhVien.h"
#include "mang.h"
#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "insertionSort.h"
#include "selectionSort.cpp"
#include <time.h>

void themVaoCuoiDon(LIST_DON &list, pNODE_DON p)
{
	if (list.pHead_Don == NULL)
	{
		list.pHead_Don = p;
	}
	else
	{
		pNODE_DON temp = list.pHead_Don;
		while (temp->pNext_Don != NULL)
		{
			temp = temp->pNext_Don;
		}
		temp->pNext_Don = p;
	}
}

void themVaoCuoiVong(LIST_VONG &list, pNODE_VONG p)
{
	// Danh sach rong
	if (list.pTail_Vong == NULL)
	{
		list.pTail_Vong = p;
		p->pNext_Vong = p; // Khi danh sách rỗng, pNext của phần tử đầu tiên trỏ lại chính nó
	}
	else
	{
		p->pNext_Vong = list.pTail_Vong->pNext_Vong; // Liên kết phần tử mới với phần tử đầu tiên
		list.pTail_Vong->pNext_Vong = p;			 // Liên kết phần tử cuối cùng với phần tử mới
		list.pTail_Vong = p;						 // Cập nhật pTail để trỏ đến phần tử mới
	}
}

// Ham them vao cuoi danh sach lien ket kep
void themVaoCuoiKep(LIST_KEP &list, pNODE_KEP p)
{
	// Danh sach rong
	if (list.pHead_Kep == NULL)
	{
		list.pHead_Kep = list.pTail_Kep = p;
	}
	else
	{
		list.pTail_Kep->pNext_Kep = p;
		p->pPrev_Kep = list.pTail_Kep;
		list.pTail_Kep = p;
	}
}

int n = 0;

SV nhapThongTin()
{
	n++;
	SV sv;
	cin.ignore();
	cout << "\nMa sv?";
	getline(cin, sv.maSV);
	cout << "\nTen?";
	getline(cin, sv.ten);
	cout << "\nDiem?";
	cin >> sv.diem;

	return sv;
}

void nhapMang()
{
	cout << "\nso luong?";
	cin >> soLuong;

	for (int i = 0; i < soLuong; i++)
	{
		LIST_MANG[i] = nhapThongTin();
	}
}

void nhapDslk(int kieuDL)
{
	cout << "\nso luong?";
	cin >> soLuong;

	for (int i = 0; i < soLuong; i++)
	{
		SV sv = nhapThongTin();
		if (kieuDL == 2)
			themVaoCuoiDon(listDon, khoiTaoNodeDon(sv));
		if (kieuDL == 3)
			themVaoCuoiVong(listVong, khoiTaoNodeVong(sv));
		if (kieuDL == 4)
			themVaoCuoiKep(listKep, khoiTaoNodeKep(sv));
	}
}

void writeToScreen(int kieuDL)
{
	if (kieuDL == 1)
	{
		for (int i = 0; i < n; i++)
			cout << LIST_MANG[i].maSV << "," << LIST_MANG[i].ten << "," << LIST_MANG[i].diem << "\n";
	}
	if (kieuDL == 2)
	{
		for (pNODE_DON i = listDon.pHead_Don; i != NULL; i = i->pNext_Don)
			cout << i->data.maSV << "," << i->data.ten << "," << i->data.diem << "\n";
	}
	if (kieuDL == 3)
	{
		pNODE_VONG i = listVong.pTail_Vong->pNext_Vong;
		while (i != listVong.pTail_Vong)
		{
			cout << i->data.maSV << "," << i->data.ten << "," << i->data.diem << "\n";
			i = i->pNext_Vong;
		}
		cout << i->data.maSV << "," << i->data.ten << "," << i->data.diem << "\n";
	}
	if (kieuDL == 4)
	{
		for (pNODE_KEP i = listKep.pHead_Kep; i != NULL; i = i->pNext_Kep)
			cout << i->data.maSV << "," << i->data.ten << "," << i->data.diem << "\n";
	}
}

int cmpStr(string s1, string s2)
{
	return strcmp(s1.c_str(), s2.c_str());
}

int kieuDL = 0;

// Lua chon kieu sap xep
int selectArrangeType(string s)
{
	regex pattern("[1-6]");
	while (!regex_match(s, pattern))
	{
		cout << "Vui long nhap lai (lua chon kieu sap xep tu 1->6)\n";
		getline(cin, s);
	}
	return stoi(s);
}

// Lua chon tieu chi sap xep
int selectCriterion(string s)
{
	regex pattern("[1-3]");
	while (!regex_match(s, pattern))
	{
		cout << "Vui long nhap lai (lua chon tieu chi sap xep tu 1->3)\n";
		getline(cin, s);
	}
	return stoi(s);
}

int tieuChi = 0;

int main()
{
	int O; // option
	while (1)
	{
		system("cls");
		cout << "[1].Nhap danh sach sinh vien\n";
		cout << "[2].Sap xep danh sach sinh vien\n";
		cout << "[3].In danh sach sinh vien\n";
		cin >> O;
		if (O == 1)
		{
			// 1-Mang 2-DSLKD 3-DSLK Vong 4-DSLK kep
			cout << "\nKieu luu?";
			cin >> kieuDL;
			if (kieuDL == 1)
			{
				nhapMang();
			}
			if (kieuDL == 2 || kieuDL == 3 || kieuDL == 4)
			{
				nhapDslk(kieuDL);
			}
		}
		if (O == 2)
		{
			system("cls");
			int arrangeType, tieuChi;
			string s;
			cout << "Chon cach sap xep: ";
			cout << "\n[1].BubbleSort";
			cout << "\n[2].QuickSort";
			cout << "\n[3].HeapSort";
			cout << "\n[4].MergeSort";
			cout << "\n[5].InsertionSort";
			cout << "\n[6].SelectionSort\n";
			getline(cin, s);
			arrangeType = selectArrangeType(s);

			system("cls");
			cout << "Chon tieu chi sap xep:\n";
			cout << "[1].Sap xep theo ma\n";
			cout << "[2].Sap xep theo ten\n";
			cout << "[3].Sap xep theo diem\n";
			getline(cin, s);
			tieuChi = selectCriterion(s);

			if (arrangeType == 1)
			{
				if (kieuDL == 1)
				{
					clock_t start = clock();
					bubbleSortArray(LIST_MANG, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 2)
				{
					clock_t start = clock();
					bubbleSortSinglyLinkedList(listDon, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 3)
				{
					clock_t start = clock();
					bubbleSortCircularLinkedList(listVong, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 4)
				{
					clock_t start = clock();
					bubbleSortDoublyLinkedList(listKep, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
			}
			if (arrangeType == 2)
			{
				if (kieuDL == 1)
				{
					clock_t start = clock();
					quickSortArray(LIST_MANG, 0, n - 1, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 2 || kieuDL == 3 || kieuDL == 4)
				{
					clock_t start = clock();
					quickSortLinkedList(listVong, listDon, listKep, kieuDL, tieuChi, n);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
			}
			if (arrangeType == 3)
			{
				if (kieuDL == 1)
				{
					clock_t start = clock();
					heapSortArray(LIST_MANG, n, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				else
				{
					clock_t start = clock();
					heapSortLinkedList(listVong, listDon, listKep, LIST_MANG, kieuDL, tieuChi, n);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
			}
			if (arrangeType == 4)
			{
				if (kieuDL == 1)
				{
					clock_t start = clock();
					mergeSortArray(LIST_MANG, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 2 || kieuDL == 3 || kieuDL == 4)
				{
					clock_t start = clock();
					mergeSortLinkedList(listVong, listDon, listKep, kieuDL, tieuChi, n);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
			}
			if (arrangeType == 5)
			{
				if (kieuDL == 1)
				{
					clock_t start = clock();
					inertionSortMang(LIST_MANG, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 2)
				{
					clock_t start = clock();
					insertionSortSinglyLinkedList(listDon, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 3)
				{
					clock_t start = clock();
					insertionSortDoubleLinkedList(listKep, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 4)
				{
					clock_t start = clock();
					insertionSortCircularLinkedList(listVong, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
			}
			if (arrangeType == 6)
			{
				if (kieuDL == 1)
				{
					clock_t start = clock();
					selectionSortMang(LIST_MANG, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 2)
				{
					clock_t start = clock();
					selectionSortSinglyLinked(listDon, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 3)
				{
					clock_t start = clock();
					selectionSortDoubleLinked(listKep, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
				if (kieuDL == 4)
				{
					clock_t start = clock();
					selectionSortCircalLinked(listVong, tieuChi);
					clock_t end = clock();
					cout << "Time run: " << (float)(end - start) / CLOCKS_PER_SEC << " s" << endl;
				}
			}
			writeToScreen(kieuDL);
			system("pause");
		}

		if (O == 3)
		{
			system("cls");
			writeToScreen(kieuDL);
			system("pause");
		}
	}
	return 0;
}
