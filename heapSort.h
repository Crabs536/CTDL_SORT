// Clear linked list
void clearSinglyLinkedList(pNODE_DON &First)
{
    pNODE_DON p;
    while (First != NULL)
    {
        p = First;
        First = p->pNext_Don;
        delete p;
    }
}

void clearCircularLinkedList(pNODE_VONG &Last)
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

void clearDoublyLinkedList(pNODE_KEP &First)
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
        list.pTail_Vong->pNext_Vong = p;             // Liên kết phần tử cuối cùng với phần tử mới
        list.pTail_Vong = p;                         // Cập nhật pTail để trỏ đến phần tử mới
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

int cmpStr(string s1, string s2)
{
    return strcmp(s1.c_str(), s2.c_str());
}

// Convert to linked list
void convertToSinglyLinkedList(LIST_DON &dsDon, SV a[])
{
    khoitaoDSLKDon(dsDon);
    for (int i = 0; i < n; i++)
        themVaoCuoiDon(dsDon, khoiTaoNodeDon(a[i]));
}

void convertToDoublyLinkedList(LIST_KEP &dsKep, SV a[])
{
    for (int i = 0; i < n; i++)
        themVaoCuoiKep(dsKep, khoiTaoNodeKep(a[i]));
}

void convertToCircularLinkedList(LIST_VONG &dsVong, SV a[])
{
    for (int i = 0; i < n; i++)
        themVaoCuoiVong(dsVong, khoiTaoNodeVong(a[i]));
}

// HeapSort
void initHeapTree(SV LIST_MANG[], int n, int i, int tieuChi)
{
    int L = 2 * i + 1, R = 2 * i, Max;
    if (tieuChi == 1)
    {
        if (L < n && cmpStr(LIST_MANG[L].maSV, LIST_MANG[i].maSV) > 0)
            Max = L;
        else
            Max = i;
        if (R < n && cmpStr(LIST_MANG[R].maSV, LIST_MANG[Max].maSV) > 0)
            Max = R;
    }
    if (tieuChi == 2)
    {
        if (L < n && cmpStr(LIST_MANG[L].ten, LIST_MANG[i].ten) > 0)
            Max = L;
        else
            Max = i;
        if (R < n && cmpStr(LIST_MANG[R].ten, LIST_MANG[Max].ten) > 0)
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
    // tạo lại cây heap
    for (int i = n / 2 - 1; i >= 0; i--)
        initHeapTree(LIST_MANG, n, i, tieuChi);
    // Đưa nút lớn nhất về gốc
    for (int i = n - 1; i >= 0; i--)
    {
        swap(LIST_MANG[0], LIST_MANG[i]);
        initHeapTree(LIST_MANG, i, 0, tieuChi);
    }
}

void heapSortLinkedList(LIST_VONG &dsVong, LIST_DON &dsDon, LIST_KEP &dsKep, SV a[], int kieuDL, int tieuChi, int n)
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
        convertToSinglyLinkedList(dsDon, a);
    }
    if (kieuDL == 3)
    {
        convertToCircularLinkedList(dsVong, a);
    }
    if (kieuDL == 4)
    {
        convertToDoublyLinkedList(dsKep, a);
    }
}
