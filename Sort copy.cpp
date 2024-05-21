#include "structSinhVien.h"
#include "mang.h"
#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"

void themVaoCuoiDon(LIST_DON& list, pNODE_DON p)
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

void themVaoCuoiVong(LIST_VONG& list, pNODE_VONG p)
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
		list.pTail_Vong->pNext_Vong = p; // Liên kết phần tử cuối cùng với phần tử mới
		list.pTail_Vong = p; // Cập nhật pTail để trỏ đến phần tử mới
	}
}

// Ham them vao cuoi danh sach lien ket kep
void themVaoCuoiKep(LIST_KEP& list, pNODE_KEP p)
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

void bubbleSortArray(SV LIST_MANG[], int tieuChi)
{
	for (int i = 1; i < n; i++)
		for (int j = n - 1; j >= i; j--)
		{
			if (tieuChi == 1)
				if (cmpStr(LIST_MANG[j - 1].maSV, LIST_MANG[j].maSV) > 0)
					swap(LIST_MANG[j - 1], LIST_MANG[j]);
			if (tieuChi == 2)
				if (cmpStr(LIST_MANG[j - 1].ten, LIST_MANG[j].ten) > 0)
					swap(LIST_MANG[j - 1], LIST_MANG[j]);
			if (tieuChi == 3)
			{
				if (LIST_MANG[j - 1].diem > LIST_MANG[j].diem)
					swap(LIST_MANG[j - 1], LIST_MANG[j]);
			}
		}
}

void bubbleSortSinglyLinkedList(LIST_DON &ds, int tieuChi)
{
	int i;
	pNODE_DON p, end = NULL, start = ds.pHead_Don;
	do
	{
		i = 0;
		p = start;
		while (p->pNext_Don != end)
		{
			if (tieuChi == 1)
				if (cmpStr(p->data.maSV, p->pNext_Don->data.maSV) > 0)
				{
					swap(p->data, p->pNext_Don->data);
					i++;
				}
			if (tieuChi == 2)
				if (cmpStr(p->data.ten, p->pNext_Don->data.ten) > 0)
				{
					swap(p->data, p->pNext_Don->data);
					i++;
				}
			if (tieuChi == 3)
				if (p->data.diem > p->pNext_Don->data.diem)
				{
					swap(p->data, p->pNext_Don->data);
					i++;
				}
			p = p->pNext_Don;
		}
		if (i == 0) break;
		end = p;
	} while (i > 0);
}

void bubbleSortDoublyLinkedList(LIST_KEP& ds, int tieuChi)
{
	int i;
	pNODE_KEP p, end = NULL, start = ds.pHead_Kep;
	do
	{
		i = 0;
		p = start;
		while (p->pNext_Kep != end)
		{
			if (tieuChi == 1)
				if (cmpStr(p->data.maSV, p->pNext_Kep->data.maSV) > 0)
				{
					swap(p->data, p->pNext_Kep->data);
					i++;
				}
			if (tieuChi == 2)
				if (cmpStr(p->data.ten, p->pNext_Kep->data.ten) > 0)
				{
					swap(p->data, p->pNext_Kep->data);
					i++;
				}
			if (tieuChi == 3)
				if (p->data.diem > p->pNext_Kep->data.diem)
				{
					swap(p->data, p->pNext_Kep->data);
					i++;
				}
			p = p->pNext_Kep;
		}
		if (i == 0) break;
		end = p;
	} while (i > 0);
}

void bubbleSortCircularLinkedList(LIST_VONG& ds, int tieuChi)
{
	int i;
	pNODE_VONG start = ds.pTail_Vong->pNext_Vong, p;
	pNODE_VONG end = ds.pTail_Vong->pNext_Vong;
	do
	{
		i = 0;
		p = start;
		while (p->pNext_Vong != end)
		{
			if (tieuChi == 1)
				if (cmpStr(p->data.maSV, p->pNext_Vong->data.maSV) > 0)
				{
					swap(p->data, p->pNext_Vong->data);
					i++;
				}
			if (tieuChi == 2)
				if (cmpStr(p->data.ten, p->pNext_Vong->data.ten) > 0)
				{
					swap(p->data, p->pNext_Vong->data);
					i++;
				}
			if (tieuChi == 3)
				if (p->data.diem > p->pNext_Vong->data.diem)
				{
					swap(p->data, p->pNext_Vong->data);
					i++;
				}
			p = p->pNext_Vong;
		}
		if (i == 0) break;
		end = p;
	} while (i > 0);
}

void quickSortArray(SV LIST_MANG[], int u, int v, int tieuChi)
{
	SV mid = LIST_MANG[(u + v) / 2];
	int i = u;
	int j = v;
	do {
		if (tieuChi == 1)
		{
			while (cmpStr(LIST_MANG[i].maSV, mid.maSV) < 0) i++;
			while (cmpStr(LIST_MANG[j].maSV, mid.maSV) > 0) j--;
		}
		if (tieuChi == 2)
		{
			while (cmpStr(LIST_MANG[i].ten, mid.ten) < 0) i++;
			while (cmpStr(LIST_MANG[j].ten, mid.ten) > 0) j--;
		}
		if (tieuChi == 3)
		{
			while (LIST_MANG[i].diem < mid.diem) i++;
			while (LIST_MANG[j].diem > mid.diem) j--;
		}
		if (i <= j)
		{
			swap(LIST_MANG[i], LIST_MANG[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (u < j) quickSortArray(LIST_MANG, u, j, tieuChi);
	if (i < v) quickSortArray(LIST_MANG, i, v, tieuChi);
}

//#QuickSort dslk đơn
pNODE_DON partitionSinglyLinkedList(pNODE_DON start, pNODE_DON end, int tieuChi)
{
	if (start == NULL || end == NULL || start == end)
		return start;
	SV pivot = end->data;
	pNODE_DON current = start;
	pNODE_DON prev = start;
	while (start != end)
	{
		if (tieuChi == 1)
		{
			if (cmpStr(start->data.maSV, pivot.maSV) < 0)
			{
				prev = current;
				swap(current->data, start->data);
				current = current->pNext_Don;
			}
		}
		else
			if (tieuChi == 2)
			{
				if (cmpStr(start->data.ten, pivot.ten) < 0)
				{
					prev = current;
					swap(current->data, start->data);
					current = current->pNext_Don;
				}
			}
			else
				if (tieuChi == 3)
				{
					if (start->data.diem < pivot.diem)
					{
						prev = current;
						swap(current->data, start->data);
						current = current->pNext_Don;
					}
				}
		start = start->pNext_Don;
	}
	SV tmp = current->data;
	current->data = pivot;
	end->data = tmp;
	return prev;
}

void quickSortSinglyLinkedList(pNODE_DON start, pNODE_DON end, int tieuChi)
{
	if (start == end)
		return;
	pNODE_DON prev = partitionSinglyLinkedList(start, end, tieuChi);
	quickSortSinglyLinkedList(start, prev, tieuChi);
	if (prev != NULL && prev == start)
		quickSortSinglyLinkedList(prev->pNext_Don, end, tieuChi);
	else
		if (prev != NULL && prev->pNext_Don != NULL)
			quickSortSinglyLinkedList(prev->pNext_Don->pNext_Don, end, tieuChi);
}

//#QuickSort dslk vòng
pNODE_VONG partitionCircularLinkedList(pNODE_VONG start, pNODE_VONG end, int tieuChi)
{
	if (start == NULL || end == NULL || start == end)
		return start;
	SV pivot = end->data;
	pNODE_VONG current = start;
	pNODE_VONG prev = start;
	while (start != end)
	{
		if (tieuChi == 1)
		{
			if (cmpStr(start->data.maSV, pivot.maSV) < 0)
			{
				prev = current;
				swap(current->data, start->data);
				current = current->pNext_Vong;
			}
		}
		else
			if (tieuChi == 2)
			{
				if (cmpStr(start->data.ten, pivot.ten) < 0)
				{
					prev = current;
					swap(current->data, start->data);
					current = current->pNext_Vong;
				}
			}
			else
				if (tieuChi == 3)
				{
					if (start->data.diem < pivot.diem)
					{
						prev = current;
						swap(current->data, start->data);
						current = current->pNext_Vong;
					}
				}
		start = start->pNext_Vong;
	}
	SV tmp = current->data;
	current->data = pivot;
	end->data = tmp;
	return prev;
}

void quickSortCircularLinkedList(pNODE_VONG start, pNODE_VONG end, int tieuChi)
{
	if (start == end)
		return;
	pNODE_VONG prev = partitionCircularLinkedList(start, end, tieuChi);
	quickSortCircularLinkedList(start, prev, tieuChi);
	if (prev != NULL && prev == start)
		quickSortCircularLinkedList(prev->pNext_Vong, end, tieuChi);
	else
		if (prev != NULL && prev->pNext_Vong != NULL)
			quickSortCircularLinkedList(prev->pNext_Vong->pNext_Vong, end, tieuChi);
}

//#QuickSort dslk kép
pNODE_KEP partitionDoublyLinkedList(pNODE_KEP start, pNODE_KEP end, int tieuChi)
{
	if (start == NULL || end == NULL || start == end)
		return start;
	SV pivot = end->data;
	pNODE_KEP current = start;
	pNODE_KEP prev = start;
	while (start != end)
	{
		if (tieuChi == 1)
		{
			if (cmpStr(start->data.maSV, pivot.maSV) < 0)
			{
				prev = current;
				swap(current->data, start->data);
				current = current->pNext_Kep;
			}
		}
		else
			if (tieuChi == 2)
			{
				if (cmpStr(start->data.ten, pivot.ten) < 0)
				{
					prev = current;
					swap(current->data, start->data);
					current = current->pNext_Kep;
				}
			}
			else
				if (tieuChi == 3)
				{
					if (start->data.diem < pivot.diem)
					{
						prev = current;
						swap(current->data, start->data);
						current = current->pNext_Kep;
					}
				}
		start = start->pNext_Kep;
	}
	SV tmp = current->data;
	current->data = pivot;
	end->data = tmp;
	return prev;
}

void quickSortDoublyLinkedList(pNODE_KEP start, pNODE_KEP end, int tieuChi)
{
	if (start == end)
		return;
	pNODE_KEP prev = partitionDoublyLinkedList(start, end, tieuChi);
	quickSortDoublyLinkedList(start, prev, tieuChi);
	if (prev != NULL && prev == start)
		quickSortDoublyLinkedList(prev->pNext_Kep, end, tieuChi);
	else
		if (prev != NULL && prev->pNext_Kep != NULL)
			quickSortDoublyLinkedList(prev->pNext_Kep->pNext_Kep, end, tieuChi);
}

//HeapSort
void initHeapTree(SV LIST_MANG[], int n, int i, int tieuChi)
{
	int L = 2 * i + 1, R = 2 * i, Max;
	if (tieuChi == 1)
	{
		if (L < n && cmpStr(LIST_MANG[L].maSV, LIST_MANG[i].maSV) > 0)
			Max = L;
		else
			Max = i;
		if (R < n && cmpStr(LIST_MANG[R].maSV, LIST_MANG[Max].maSV)>0)
			Max = R;
	}
	if (tieuChi == 2)
	{
		if (L < n && cmpStr(LIST_MANG[L].ten, LIST_MANG[i].ten) > 0)
			Max = L;
		else
			Max = i;
		if (R < n && cmpStr(LIST_MANG[R].ten, LIST_MANG[Max].ten)>0)
			Max = R;
	}
	if (tieuChi == 3)
	{
		if (L < n && LIST_MANG[L].diem > LIST_MANG[i].diem)
			Max = L;
		else
			Max = i;
		if (R < n && LIST_MANG[R].diem > LIST_MANG[Max].diem)
			Max = R;
	}
	if (i != Max)
	{
		swap(LIST_MANG[i], LIST_MANG[Max]);
		initHeapTree(LIST_MANG, n, Max, tieuChi);
	}
}

void heapSortArray(SV LIST_MANG[], int n, int tieuChi)
{
	//tạo lại cây heap
	for (int i = n / 2 - 1; i >= 0; i--)
		initHeapTree(LIST_MANG, n, i, tieuChi);
	//Đưa nút lớn nhất về gốc
	for (int i = n - 1; i >= 0; i--)
	{
		swap(LIST_MANG[0], LIST_MANG[i]);
		initHeapTree(LIST_MANG, i, 0, tieuChi);
	}
}

void clearSinglyLinkedList(pNODE_DON& First)
{
	pNODE_DON p;
	while (First != NULL)
	{
		p = First;
		First = p->pNext_Don;
		delete p;
	}
}

void clearCircularLinkedList(pNODE_VONG& Last)
{
	while (Last != NULL)
	{
		pNODE_VONG p = Last->pNext_Vong;
		if (p == Last)
			Last = NULL;
		else
			Last->pNext_Vong = p->pNext_Vong;
		delete p;
	}
}

void clearDoublyLinkedList(pNODE_KEP& First)
{
	pNODE_KEP p;
	while (First != NULL)
	{
		p = First;
		if (First->pNext_Kep == NULL)
			First = NULL;
		else
		{
			First = p->pNext_Kep;
			First->pPrev_Kep = NULL;
		}
		delete p;
	}
}

void heapSortLinkedList(LIST_VONG& dsVong, LIST_DON& dsDon, LIST_KEP& dsKep ,SV a[], int kieuDL, int tieuChi, int n)
{
	if (kieuDL == 2)
	{
		int k = 0;
		pNODE_DON i = dsDon.pHead_Don;
		while (i != NULL)
		{
			a[k] = i->data;
			k++;
			i = i->pNext_Don;
		}
		clearSinglyLinkedList(dsDon.pHead_Don);
	}
	if (kieuDL == 3)
	{
		int k = 0;
		pNODE_VONG p = dsVong.pTail_Vong->pNext_Vong;
		while (p != dsVong.pTail_Vong)
		{
			a[k] = p->data;
			k++;
			p = p->pNext_Vong;
		}
		a[n - 1] = p->data;
		clearCircularLinkedList(dsVong.pTail_Vong);
	}
	if (kieuDL == 4)
	{
		int k = 0;
		pNODE_KEP i = dsKep.pHead_Kep;
		while (i != NULL)
		{
			a[k] = i->data;
			k++;
			i = i->pNext_Kep;
		}
		clearDoublyLinkedList(dsKep.pHead_Kep);
	}
	heapSortArray(a, n, tieuChi);
	if (kieuDL == 2)
	{
		khoitaoDSLKDon(dsDon);
		for (int i = 0; i < n; i++)
			themVaoCuoiDon(dsDon, khoiTaoNodeDon(a[i]));
	}
	if (kieuDL == 3)
	{
		for (int i = 0; i < n; i++)
			themVaoCuoiVong(dsVong, khoiTaoNodeVong(a[i]));
	}
	if (kieuDL == 4)
	{
		for (int i = 0; i < n; i++)
			themVaoCuoiKep(dsKep, khoiTaoNodeKep(a[i]));
	}
}

void mergeSortArray()
{

}

int kieuDL = 0;

int main()
{
	int O; //option
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
			cout << "Chon cach sap xep: ";
			cout << "\n[1].BubbleSort";
			cout << "\n[2].QuickSort";
			cout << "\n[3].HeapSort\n";
			cin >> arrangeType;

			system("cls");
			cout << "Chon tieu chi sap xep:\n";
			cout << "[1].Sap xep theo ma\n";
			cout << "[2].Sap xep theo ten\n";
			cout << "[3].Sap xep theo diem\n";
			cin >> tieuChi;
			if (kieuDL == 1)
			{
				if (arrangeType == 1)
					bubbleSortArray(LIST_MANG, tieuChi);
				if (arrangeType == 2)
					quickSortArray(LIST_MANG, 0, n - 1, tieuChi);
				if (arrangeType == 3)
					heapSortArray(LIST_MANG, n, tieuChi);
			}
			if (arrangeType == 2)
			{
				if (kieuDL == 1)
					quickSortArray(LIST_MANG, 0, n - 1, tieuChi);
				if (kieuDL == 2)
				{
					pNODE_DON p;
					for (p = listDon.pHead_Don; p != NULL; p = p->pNext_Don);
					quickSortSinglyLinkedList(listDon.pHead_Don, p, tieuChi);
				}
				if (kieuDL == 3)
					quickSortCircularLinkedList(listVong.pTail_Vong->pNext_Vong, listVong.pTail_Vong, tieuChi);
				if (kieuDL == 4)
					quickSortDoublyLinkedList(listKep.pHead_Kep, listKep.pTail_Kep, tieuChi);
			}
			if (arrangeType == 3)
			{
				if (kieuDL == 1)
					heapSortArray(LIST_MANG, n, tieuChi);
				else
					heapSortLinkedList(listVong, listDon, listKep, LIST_MANG, kieuDL, tieuChi, n);
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
