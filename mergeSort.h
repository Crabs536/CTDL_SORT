int cmpStr(string s1, string s2)
{
    return strcmp(s1.c_str(), s2.c_str());
}

// Clear linked list
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
// #MergeSort dslk đơn
void mergeSinglyLinkedListPointer(vector<pNODE_DON> &linkedListPointer, int left, int mid, int right, int tieuChi)
{
    int u, v, i = 0, j = 0, k = 0;
    u = mid - left + 1;
    v = right - mid;
    SV leftArray[MAX], rightArray[MAX];

    // Tách thành 2 mảng trái/phải
    for (i = 0; i < u; i++)
        leftArray[i] = linkedListPointer[left + i]->data;
    for (j = 0; j < v; j++)
        rightArray[j] = linkedListPointer[mid + j + 1]->data;
    i = 0;
    j = 0;
    k = left; // bắt đầu từ vị trí lưu lần trước

    // gộp mảng 2 trái/phải vào a với điều kiện phần tử bên trái < phần tử bên phải
    while (i < u && j < v)
    {
        if (tieuChi == 1)
        {
            if (cmpStr(leftArray[i].maSV, rightArray[j].maSV) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 2)
        {
            if (cmpStr(leftArray[i].ten, rightArray[j].ten) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 3)
        {
            if (leftArray[i].diem <= rightArray[j].diem)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
    }
    // Thêm những ptu còn lại cảu 2 mảng trái/phải vào a
    while (i < u)
    {
        linkedListPointer[k++]->data = leftArray[i++];
    }
    while (j < v)
    {
        linkedListPointer[k++]->data = rightArray[j++];
    }
}

// #MergeSort dslk vong
void mergeCircularLinkedListPointer(vector<pNODE_VONG> &linkedListPointer, int left, int mid, int right, int tieuChi)
{
    int u, v, i = 0, j = 0, k = 0;
    u = mid - left + 1;
    v = right - mid;
    SV leftArray[MAX], rightArray[MAX];

    // Tách thành 2 mảng trái/phải
    for (i = 0; i < u; i++)
        leftArray[i] = linkedListPointer[left + i]->data;
    for (j = 0; j < v; j++)
        rightArray[j] = linkedListPointer[mid + j + 1]->data;
    i = 0;
    j = 0;
    k = left; // bắt đầu từ vị trí lưu lần trước

    // gộp mảng 2 trái/phải vào a với điều kiện phần tử bên trái < phần tử bên phải
    while (i < u && j < v)
    {
        if (tieuChi == 1)
        {
            if (cmpStr(leftArray[i].maSV, rightArray[j].maSV) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 2)
        {
            if (cmpStr(leftArray[i].ten, rightArray[j].ten) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 3)
        {
            if (leftArray[i].diem <= rightArray[j].diem)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
    }
    // Thêm những ptu còn lại cảu 2 mảng trái/phải vào a
    while (i < u)
    {
        linkedListPointer[k++]->data = leftArray[i++];
    }
    while (j < v)
    {
        linkedListPointer[k++]->data = rightArray[j++];
    }
}

void mergeSortCircularLinkedList(vector<pNODE_VONG> &linkedListPointer, int left, int right, int tieuChi)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // (left+right)/2
        // gọi đệ quy chia đôi mảng
        mergeSortCircularLinkedList(linkedListPointer, left, mid, tieuChi);
        mergeSortCircularLinkedList(linkedListPointer, mid + 1, right, tieuChi);

        mergeCircularLinkedListPointer(linkedListPointer, left, mid, right, tieuChi);
    }
    else
        return;
}

// #MergeSort dslk kep
void mergeDoublyLinkedListPointer(vector<pNODE_KEP> &linkedListPointer, int left, int mid, int right, int tieuChi)
{
    int u, v, i = 0, j = 0, k = 0;
    u = mid - left + 1;
    v = right - mid;
    SV leftArray[MAX], rightArray[MAX];

    // Tách thành 2 mảng trái/phải
    for (i = 0; i < u; i++)
        leftArray[i] = linkedListPointer[left + i]->data;
    for (j = 0; j < v; j++)
        rightArray[j] = linkedListPointer[mid + j + 1]->data;
    i = 0;
    j = 0;
    k = left; // bắt đầu từ vị trí lưu lần trước

    // gộp mảng 2 trái/phải vào a với điều kiện phần tử bên trái < phần tử bên phải
    while (i < u && j < v)
    {
        if (tieuChi == 1)
        {
            if (cmpStr(leftArray[i].maSV, rightArray[j].maSV) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 2)
        {
            if (cmpStr(leftArray[i].ten, rightArray[j].ten) <= 0)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
        if (tieuChi == 3)
        {
            if (leftArray[i].diem <= rightArray[j].diem)
            {
                linkedListPointer[k++]->data = leftArray[i++];
            }
            else
            {
                linkedListPointer[k++]->data = rightArray[j++];
            }
        }
    }
    // Thêm những ptu còn lại cảu 2 mảng trái/phải vào a
    while (i < u)
    {
        linkedListPointer[k++]->data = leftArray[i++];
    }
    while (j < v)
    {
        linkedListPointer[k++]->data = rightArray[j++];
    }
}

void mergeSortDoublyLinkedList(vector<pNODE_KEP> &linkedListPointer, int left, int right, int tieuChi)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // (left+right)/2
        // gọi đệ quy chia đôi mảng
        mergeSortDoublyLinkedList(linkedListPointer, left, mid, tieuChi);
        mergeSortDoublyLinkedList(linkedListPointer, mid + 1, right, tieuChi);

        mergeDoublyLinkedListPointer(linkedListPointer, left, mid, right, tieuChi);
    }
    else
        return;
}

// #MergeSort dslk
void mergeSortSinglyLinkedList(vector<pNODE_DON> &linkedListPointer, int left, int right, int tieuChi)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // (left+right)/2
        // gọi đệ quy chia đôi mảng
        mergeSortSinglyLinkedList(linkedListPointer, left, mid, tieuChi);
        mergeSortSinglyLinkedList(linkedListPointer, mid + 1, right, tieuChi);

        mergeSinglyLinkedListPointer(linkedListPointer, left, mid, right, tieuChi);
    }
    else
        return;
}

void mergeSortLinkedList(LIST_VONG &dsVong, LIST_DON &dsDon, LIST_KEP &dsKep, int kieuDL, int tieuChi, int n)
{
    if (kieuDL == 2)
    {
        vector<pNODE_DON> linkedListPointer;
        for (pNODE_DON p = dsDon.pHead_Don; p != NULL; p = p->pNext_Don)
            linkedListPointer.push_back(p);

        mergeSortSinglyLinkedList(linkedListPointer, 0, n - 1, tieuChi);

        khoitaoDSLKDon(dsDon);
        for (int i = 0; i < n; i++)
            themVaoCuoiDon(dsDon, khoiTaoNodeDon(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
    if (kieuDL == 3)
    {
        vector<pNODE_VONG> linkedListPointer;
        pNODE_VONG p = dsVong.pTail_Vong->pNext_Vong;
        while (p != dsVong.pTail_Vong)
        {
            linkedListPointer.push_back(p);
            p = p->pNext_Vong;
        }
        linkedListPointer.push_back(p);

        mergeSortCircularLinkedList(linkedListPointer, 0, n - 1, tieuChi);
        khoiTaoDSLKVong(listVong);
        for (int i = 0; i < n; i++)
            themVaoCuoiVong(listVong, khoiTaoNodeVong(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
    if (kieuDL == 4)
    {
        vector<pNODE_KEP> linkedListPointer;
        pNODE_KEP p = dsKep.pHead_Kep;
        while (p != NULL)
        {
            linkedListPointer.push_back(p);
            p = p->pNext_Kep;
        }

        quicksortDoublyLinkedList(linkedListPointer, 0, n - 1, tieuChi);

        khoiTaoDSLKKep(listKep);
        for (int i = 0; i < n; i++)
            themVaoCuoiKep(listKep, khoiTaoNodeKep(linkedListPointer[i]->data));

        linkedListPointer.clear();
        linkedListPointer.shrink_to_fit();
    }
}
void mergeSortArray(SV LIST_MANG[], int tieuChi)
{
    int i, j, k, low1, up1, low2, up2, size;
    size = 1;
    if (tieuChi == 1)
    {
        while (size < n)
        {
            string dstam[MAX];
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
    if (tieuChi == 2)
    {
        while (size < n)
        {
            string dstam[MAX];
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
    if (tieuChi == 3)
    {
        while (size < n)
        {
            int dstam[MAX];
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