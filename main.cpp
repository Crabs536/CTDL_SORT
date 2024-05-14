#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>

using namespace std::chrono;

using namespace std;

int n = 0; // so luong sinh vien

typedef struct sinhVien
{
    int stt;
    string maSV;
    string ho;
    string ten;
    string lop;
    float diem;
};

typedef sinhVien SV;

typedef struct node
{
    SV data;
    node *pNext;
    node *pPrev;
} NODE;
typedef NODE *pNODE;

typedef struct list
{
    pNODE pHead;
    pNODE pTail;
} LIST;

LIST ds;

void khoiTao(LIST &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

pNODE khoiTaoNodeDon(SV sv)
{
    pNODE p = new NODE;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;
    return p;
}

pNODE khoiTaoNodeKep(SV sv)
{
    pNODE p = new NODE;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

void themVaoCuoiDon(LIST &list, pNODE p)
{
    if (list.pHead == NULL)
    {
        list.pHead = p;
    }
    else
    {
        pNODE temp = list.pHead;
        while (temp->pNext != NULL)
        {
            temp = temp->pNext;
        }
        temp->pNext = p;
    }
}

void themVaoCuoiVong(LIST &list, pNODE p)
{
    // Danh sach rong
    if (list.pTail == NULL)
    {
        list.pTail = p;
        p->pNext = p; // Khi danh sách rỗng, pNext của phần tử đầu tiên trỏ lại chính nó
    }
    else
    {
        p->pNext = list.pTail->pNext; // Liên kết phần tử mới với phần tử đầu tiên
        list.pTail->pNext = p;        // Liên kết phần tử cuối cùng với phần tử mới
        list.pTail = p;               // Cập nhật pTail để trỏ đến phần tử mới
    }
}

// Ham them vao cuoi danh sach lien ket kep
void themVaoCuoiKep(LIST &list, pNODE p)
{
    // Danh sach rong
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = p;
    }
    else
    {
        list.pTail->pNext = p;
        p->pPrev = list.pTail;
        list.pTail = p;
    }
}

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

#define max 10000

SV LIST_MANG[max];

int soLuong = 0;

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
            themVaoCuoiDon(ds, khoiTaoNodeDon(sv));
        if (kieuDL == 3)
            themVaoCuoiVong(ds, khoiTaoNodeDon(sv));
        if (kieuDL == 4)
            themVaoCuoiKep(ds, khoiTaoNodeKep(sv));
    }
}

void writeToScreen(int kieuDL)
{
    if (kieuDL == 1)
    {
        for (int i = 0; i < n; i++)
            cout << LIST_MANG[i].maSV << "," << LIST_MANG[i].ten << "," << LIST_MANG[i].diem << "\n";
    }
    if (kieuDL == 2 || kieuDL == 4)
    {
        for (pNODE i = ds.pHead; i != NULL; i = i->pNext)
            cout << i->data.maSV << "," << i->data.ten << "," << i->data.diem << "\n";
    }
    if (kieuDL == 3)
    {
        pNODE i = ds.pTail->pNext;
        while (i != ds.pTail)
        {
            cout << i->data.maSV << "," << i->data.ten << "," << i->data.diem << "\n";
            i = i->pNext;
        }
        cout << i->data.maSV << "," << i->data.ten << "," << i->data.diem << "\n";
    }
}

int smpStr(string s1, string s2)
{
    return strcmp(s1.c_str(), s2.c_str());
}
void insertionSort(SV LIST_MANG[], LIST &list, int tieuchi, int kieuDL)
{
    if (kieuDL == 1)
    {
        if (tieuchi == 1)
        {
            string x;
            int i, j;
            for (i = 1; i < n; i++)
            {
                x = LIST_MANG[i].maSV;
                for (j = i - 1; j >= 0 && smpStr(x, LIST_MANG[j].maSV) < 0; j--)
                    LIST_MANG[j + 1].maSV = LIST_MANG[j].maSV;
                LIST_MANG[j + 1].maSV = x;
            }
        }
        if (tieuchi == 2)
        {
            string x;
            int i, j;
            for (i = 1; i < n; i++)
            {
                x = LIST_MANG[i].ten;
                for (j = i - 1; j >= 0 && smpStr(x, LIST_MANG[j].maSV) < 0; j--)
                    LIST_MANG[j + 1].ten = LIST_MANG[j].ten;
                LIST_MANG[j + 1].ten = x;
            }
        }
        if (tieuchi == 3)
        {
            int x;
            int i, j;
            for (i = 1; i < n; i++)
            {
                x = LIST_MANG[i].diem;
                for (j = i - 1; j >= 0 && x < LIST_MANG[j].diem; j--)
                    LIST_MANG[j + 1].diem = LIST_MANG[j].diem;
                LIST_MANG[j + 1].diem = x;
            }
        }
    }
    if (kieuDL == 2 || kieuDL == 3 || kieuDL == 4)
    {
        if (tieuchi == 1)
        {
            if (list.pHead == NULL || list.pHead->pNext == NULL)
                return;

            pNODE pSorted = NULL;
            pNODE pCurrent = list.pHead; // Lưu node đầu

            while (pCurrent != NULL)
            {
                pNODE pNEXT = pCurrent->pNext; // Lưu con trỏ pNEXT tới node kế tiếp

                if (pSorted == NULL || pCurrent->data.maSV < pSorted->data.maSV)
                {
                    pCurrent->pNext = pSorted;
                    pSorted = pCurrent;
                }
                else
                {
                    // Tìm vị trí để chèn node hiện tại vào danh sách sắp xếp
                    pNODE pTemp = pSorted;
                    while (pTemp->pNext != NULL && pCurrent->data.maSV > pTemp->pNext->data.maSV)
                        pTemp = pTemp->pNext;

                    pCurrent->pNext = pTemp->pNext; // Chèn node hiện tại vào sau node Temp
                    pTemp->pNext = pCurrent;
                }
                pCurrent = pNEXT; // Di chuyển đến node kế tiếp
            }

            list.pHead = pSorted; // Cập nhật con trỏ đầu danh sách
        }
        if (tieuchi == 2)
        {
            if (list.pHead == NULL || list.pHead->pNext == NULL)
                return;

            pNODE pSorted = NULL;
            pNODE pCurrent = list.pHead; // Lưu node đầu

            while (pCurrent != NULL)
            {
                pNODE pNEXT = pCurrent->pNext; // Lưu con trỏ pNEXT tới node kế tiếp

                if (pSorted == NULL || pCurrent->data.ten < pSorted->data.ten)
                {
                    pCurrent->pNext = pSorted;
                    pSorted = pCurrent;
                }
                else
                {
                    // Tìm vị trí để chèn node hiện tại vào danh sách sắp xếp
                    pNODE pTemp = pSorted;
                    while (pTemp->pNext != NULL && pCurrent->data.ten > pTemp->pNext->data.ten)
                        pTemp = pTemp->pNext;

                    pCurrent->pNext = pTemp->pNext; // Chèn node hiện tại vào sau node Temp
                    pTemp->pNext = pCurrent;
                }
                pCurrent = pNEXT; // Di chuyển đến node kế tiếp
            }

            list.pHead = pSorted; // Cập nhật con trỏ đầu danh sách
        }
        if (tieuchi == 3)
        {
            if (list.pHead == NULL || list.pHead->pNext == NULL)
                return;

            pNODE pSorted = NULL;
            pNODE pCurrent = list.pHead; // Lưu node đầu

            while (pCurrent != NULL)
            {
                pNODE pNEXT = pCurrent->pNext; // Lưu con trỏ pNEXT tới node kế tiếp

                if (pSorted == NULL || pCurrent->data.diem < pSorted->data.diem)
                {
                    pCurrent->pNext = pSorted;
                    pSorted = pCurrent;
                }
                else
                {
                    // Tìm vị trí để chèn node hiện tại vào danh sách sắp xếp
                    pNODE pTemp = pSorted;
                    while (pTemp->pNext != NULL && pCurrent->data.diem > pTemp->pNext->data.diem)
                        pTemp = pTemp->pNext;

                    pCurrent->pNext = pTemp->pNext; // Chèn node hiện tại vào sau node Temp
                    pTemp->pNext = pCurrent;
                }
                pCurrent = pNEXT; // Di chuyển đến node kế tiếp
            }

            list.pHead = pSorted; // Cập nhật con trỏ đầu danh sách
        }
    }
}
void selectionSort(SV LIST_MANG[], LIST &list, int tieuchi, int kieuDL)
{
    if (kieuDL == 1)
    {
        if (tieuchi == 1)
        {
            string min;
            int vitrimin;
            int i, j;
            for (i = 0; i < n - 1; i++)
            {
                min = LIST_MANG[i].maSV;
                vitrimin = i;
                for (j = i + 1; j < n; j++)
                    if (smpStr(LIST_MANG[j].maSV, min) < 0)
                    {
                        min = LIST_MANG[j].maSV;
                        vitrimin = j;
                    }
                // Doi cho 2 phan tu A[i] va A[vitrimin]
                min = LIST_MANG[vitrimin].maSV;
                LIST_MANG[vitrimin].maSV = LIST_MANG[i].maSV;
                LIST_MANG[i].maSV = min;
            }
        }
        if (tieuchi == 2)
        {
            string min;
            int vitrimin;
            int i, j;
            for (i = 0; i < n - 1; i++)
            {
                min = LIST_MANG[i].ten;
                vitrimin = i;
                for (j = i + 1; j < n; j++)
                    if (smpStr(LIST_MANG[j].ten, min) < 0)
                    {
                        min = LIST_MANG[j].ten;
                        vitrimin = j;
                    }
                // Doi cho 2 phan tu A[i] va A[vitrimin]
                min = LIST_MANG[vitrimin].ten;
                LIST_MANG[vitrimin].ten = LIST_MANG[i].ten;
                LIST_MANG[i].ten = min;
            }
        }
        if (tieuchi == 3)
        {
            int min, vitrimin;
            int i, j;
            for (i = 0; i < n - 1; i++)
            {
                min = LIST_MANG[i].diem;
                vitrimin = i;
                for (j = i + 1; j < n; j++)
                    if (LIST_MANG[j].diem < min)
                    {
                        min = LIST_MANG[j].diem;
                        vitrimin = j;
                    }
                // Doi cho 2 phan tu A[i] va A[vitrimin]
                min = LIST_MANG[vitrimin].diem;
                LIST_MANG[vitrimin].diem = LIST_MANG[i].diem;
                LIST_MANG[i].diem = min;
            }
        }
    }
    if (kieuDL == 2 || kieuDL == 3 || kieuDL == 4)
    {
        if (tieuchi == 1)
        {
            pNODE pMin;

            for (node *i = ds.pHead; i != ds.pTail; i = i->pNext)

            {

                pMin = i;

                for (node *j = i->pNext; j != NULL; j = j->pNext)

                    if (j->data.maSV < pMin->data.maSV)

                        pMin = j;

                swap(i->data, pMin->data);
            }
        }
        if (tieuchi == 2)
        {
            pNODE pMin;

            for (node *i = ds.pHead; i != ds.pTail; i = i->pNext)

            {

                pMin = i;

                for (node *j = i->pNext; j != NULL; j = j->pNext)

                    if (j->data.ten < pMin->data.ten)

                        pMin = j;

                swap(i->data, pMin->data);
            }
        }
        if (tieuchi == 3)
        {
            pNODE pMin;

            for (node *i = ds.pHead; i != ds.pTail; i = i->pNext)

            {

                pMin = i;

                for (node *j = i->pNext; j != NULL; j = j->pNext)

                    if (j->data.diem < pMin->data.diem)

                        pMin = j;

                swap(i->data, pMin->data);
            }
        }
    }
}
pNODE merge(pNODE left, pNODE right)
{
    pNODE result = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data.maSV <= right->data.maSV)
    {
        result = left;
        result->pNext = merge(left->pNext, right);
    }
    else
    {
        result = right;
        result->pNext = merge(left, right->pNext);
    }

    return result;
}

pNODE mergeSort(pNODE head)
{
    if (head == NULL || head->pNext == NULL)
        return head;

    pNODE middle = head;
    pNODE fast = head->pNext;

    while (fast != NULL)
    {
        fast = fast->pNext;
        if (fast != NULL)
        {
            middle = middle->pNext;
            fast = fast->pNext;
        }
    }

    pNODE left = head;
    pNODE right = middle->pNext;
    middle->pNext = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void mergeSortList(LIST &list)
{
    if (list.pHead == NULL || list.pHead->pNext == NULL)
        return;

    list.pHead = mergeSort(list.pHead);
}
void merge_Sort(SV LIST_MANG[], LIST &list, int tieuchi, int kieuDL)
{
    if (kieuDL == 1)
    {
        if (tieuchi == 1)
        {
            int i, j, k, low1, up1, low2, up2, size;
            string dstam[1000];
            size = 1;
            while (size < n)
            {
                low1 = 0;
                k = 0;
                while (low1 + size < n)
                {
                    up1 = low1 + size - 1;
                    low2 = up1 + 1;
                    up2 = (low2 + size - 1 < n) ? low2 + size - 1 : n - 1;
                    for (i = low1, j = low2; i <= up1 && j <= up2; k++)
                        if (LIST_MANG[i].maSV <= LIST_MANG[j].maSV)
                            dstam[k] = LIST_MANG[i++].maSV;
                        else
                            dstam[k] = LIST_MANG[j++].maSV;
                    for (; i <= up1; k++)
                        dstam[k] = LIST_MANG[i++].maSV;
                    for (; j <= up2; k++)
                        dstam[k] = LIST_MANG[j++].maSV;
                    low1 = up2 + 1;
                }
                for (i = low1; k < n; i++)
                    dstam[k++] = LIST_MANG[i].maSV;
                for (i = 0; i < n; i++) // gan nguoc tra lai cho A
                    LIST_MANG[i].maSV = dstam[i];
                size *= 2;
            }
        }
        if (tieuchi == 2)
        {
            int i, j, k, low1, up1, low2, up2, size;
            string dstam[10000];
            size = 1;
            while (size < n)
            {
                low1 = 0;
                k = 0;
                while (low1 + size < n)
                {
                    up1 = low1 + size - 1;
                    low2 = up1 + 1;
                    up2 = (low2 + size - 1 < n) ? low2 + size - 1 : n - 1;
                    for (i = low1, j = low2; i <= up1 && j <= up2; k++)
                        if (LIST_MANG[i].ten <= LIST_MANG[j].ten)
                            dstam[k] = LIST_MANG[i++].ten;
                        else
                            dstam[k] = LIST_MANG[j++].ten;
                    for (; i <= up1; k++)
                        dstam[k] = LIST_MANG[i++].ten;
                    for (; j <= up2; k++)
                        dstam[k] = LIST_MANG[j++].ten;
                    low1 = up2 + 1;
                }
                for (i = low1; k < n; i++)
                    dstam[k++] = LIST_MANG[i].ten;
                for (i = 0; i < n; i++) // gan nguoc tra lai cho A
                    LIST_MANG[i].ten = dstam[i];
                size *= 2;
            }
        }
        if (tieuchi == 3)
        {
            int i, j, k, low1, up1, low2, up2, size;
            int dstam[max];
            size = 1;
            while (size < n)
            {
                low1 = 0;
                k = 0;
                while (low1 + size < n)
                {
                    up1 = low1 + size - 1;
                    low2 = up1 + 1;
                    up2 = (low2 + size - 1 < n) ? low2 + size - 1 : n - 1;
                    for (i = low1, j = low2; i <= up1 && j <= up2; k++)
                        if (LIST_MANG[i].diem <= LIST_MANG[j].diem)
                            dstam[k] = LIST_MANG[i++].diem;
                        else
                            dstam[k] = LIST_MANG[j++].diem;
                    for (; i <= up1; k++)
                        dstam[k] = LIST_MANG[i++].diem;
                    for (; j <= up2; k++)
                        dstam[k] = LIST_MANG[j++].diem;
                    low1 = up2 + 1;
                }
                for (i = low1; k < n; i++)
                    dstam[k++] = LIST_MANG[i].diem;
                for (i = 0; i < n; i++) // gan nguoc tra lai cho A
                    LIST_MANG[i].diem = dstam[i];
                size *= 2;
            }
        }
    }
    if (kieuDL == 2 || kieuDL == 3 || kieuDL == 4)
    {
        mergeSortList(list);
    }
}
int kieuDL = 0;
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
            cout << "\nLua chon?";
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
            cout << "\n[1].Insertionsort";
            cout << "\n[2].SelectionSort";
            cout << "\n[3].HeapSort\n";
            cin >> arrangeType;

            system("cls");
            cout << "Chon tieu chi sap xep:\n";
            cout << "[1].Sap xep theo ma\n";
            cout << "[2].Sap xep theo ten\n";
            cout << "[3].Sap xep theo diem\n";
            cin >> tieuChi;
            if (arrangeType == 1)
            {
                insertionSort(LIST_MANG, ds, tieuChi, kieuDL);
            }
            if (arrangeType == 2)
            {
                selectionSort(LIST_MANG, ds, tieuChi, kieuDL);
            }
        }
        if (O == 3)
        {
            writeToScreen(kieuDL);
        }
    }
}