int cmpStr(string s1, string s2)
{
    return strcmp(s1.c_str(), s2.c_str());
}
void inertionSortMang(SV LIST_MANG[], int tieuchi)
{
    if (tieuchi == 1)
    {
        string x;
        int i, j;
        for (i = 1; i < n; i++)
        {
            x = LIST_MANG[i].maSV;
            for (j = i - 1; j >= 0 && cmpStr(x, LIST_MANG[j].maSV) < 0; j--)
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
            for (j = i - 1; j >= 0 && cmpStr(x, LIST_MANG[j].maSV) < 0; j--)
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
void insertionSortSinglyLinkedList(LIST_DON &ds, int tieuchi)
{
    if (ds.pHead_Don == NULL || ds.pHead_Don->pNext_Don == NULL)
    {
        return;
    }
    pNODE_DON pSorted = NULL;
    pNODE_DON pCurrent = ds.pHead_Don;
    while (pCurrent != NULL)
    {
        if (tieuchi == 1)
        {
            pNODE_DON pNEXT = pCurrent->pNext_Don;
            if (pSorted == NULL || cmpStr(pCurrent->data.maSV, pSorted->data.maSV) > 0)
            {
                pCurrent->pNext_Don = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                pNODE_DON pTemp = pSorted;
                while (pTemp->pNext_Don != NULL && cmpStr(pCurrent->data.maSV, pTemp->data.maSV) > 0)
                {
                    pTemp = pTemp->pNext_Don;
                }
                pCurrent->pNext_Don = pTemp->pNext_Don;
                pTemp->pNext_Don = pCurrent;
            }
            pCurrent = pNEXT;
        }
        if (tieuchi == 2)
        {
            pNODE_DON pNEXT = pCurrent->pNext_Don;
            if (pSorted == NULL || cmpStr(pCurrent->data.ten, pSorted->data.ten) > 0)
            {
                pCurrent->pNext_Don = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                pNODE_DON pTemp = pSorted;
                while (pTemp->pNext_Don != NULL && cmpStr(pCurrent->data.ten, pTemp->data.ten) > 0)
                {
                    pTemp = pTemp->pNext_Don;
                }
                pCurrent->pNext_Don = pTemp->pNext_Don;
                pTemp->pNext_Don = pCurrent;
            }
            pCurrent = pNEXT;
        }
        if (tieuchi == 3)
        {
            if (ds.pHead_Don == NULL || ds.pHead_Don->pNext_Don == NULL)
                return;

            pNODE_DON pSorted = NULL;
            pNODE_DON pCurrent = ds.pHead_Don; // Lưu node đầu

            while (pCurrent != NULL)
            {
                pNODE_DON pNEXT = pCurrent->pNext_Don; // Lưu con trỏ pNEXT tới node kế tiếp

                if (pSorted == NULL || pCurrent->data.diem < pSorted->data.diem)
                {
                    pCurrent->pNext_Don = pSorted;
                    pSorted = pCurrent;
                }
                else
                {
                    // Tìm vị trí để chèn node hiện tại vào danh sách sắp xếp
                    pNODE_DON pTemp = pSorted;
                    while (pTemp->pNext_Don != NULL && pCurrent->data.diem > pTemp->pNext_Don->data.diem)
                        pTemp = pTemp->pNext_Don;

                    pCurrent->pNext_Don = pTemp->pNext_Don; // Chèn node hiện tại vào sau node Temp
                    pTemp->pNext_Don = pCurrent;
                }
                pCurrent = pNEXT; // Di chuyển đến node kế tiếp
            }
        }
        ds.pHead_Don = pSorted;
    }
}

void insertionSortDoubleLinkedList(LIST_KEP &ds, int tieuchi)
{
    if (ds.pHead_Kep == NULL || ds.pHead_Kep->pNext_Kep == NULL)
    {
        return;
    }
    pNODE_KEP pSorted = NULL;
    pNODE_KEP pCurrent = ds.pHead_Kep;
    while (pCurrent != NULL)
    {
        if (tieuchi == 1)
        {
            pNODE_KEP pNEXT = pCurrent->pNext_Kep;
            if (pSorted == NULL || cmpStr(pCurrent->data.maSV, pSorted->data.maSV) > 0)
            {
                pCurrent->pNext_Kep = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                pNODE_KEP pTemp = pSorted;
                while (pTemp->pNext_Kep != NULL && cmpStr(pCurrent->data.maSV, pTemp->data.maSV) > 0)
                {
                    pTemp = pTemp->pNext_Kep;
                }
                pCurrent->pNext_Kep = pTemp->pNext_Kep;
                pTemp->pNext_Kep = pCurrent;
            }
            pCurrent = pNEXT;
        }
        if (tieuchi == 2)
        {
            pNODE_KEP pNEXT = pCurrent->pNext_Kep;
            if (pSorted == NULL || cmpStr(pCurrent->data.ten, pSorted->data.ten) > 0)
            {
                pCurrent->pNext_Kep = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                pNODE_KEP pTemp = pSorted;
                while (pTemp->pNext_Kep != NULL && cmpStr(pCurrent->data.ten, pTemp->data.ten) > 0)
                {
                    pTemp = pTemp->pNext_Kep;
                }
                pCurrent->pNext_Kep = pTemp->pNext_Kep;
                pTemp->pNext_Kep = pCurrent;
            }
            pCurrent = pNEXT;
        }
        if (tieuchi == 3)
        {
            pNODE_KEP pNEXT = pCurrent->pNext_Kep; // Lưu con trỏ pNEXT tới node kế tiếp

            if (pSorted == NULL || pCurrent->data.diem < pSorted->data.diem)
            {
                pCurrent->pNext_Kep = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                // Tìm vị trí để chèn node hiện tại vào danh sách sắp xếp
                pNODE_KEP pTemp = pSorted;
                while (pTemp->pNext_Kep != NULL && pCurrent->data.diem > pTemp->pNext_Kep->data.diem)
                    pTemp = pTemp->pNext_Kep;

                pCurrent->pNext_Kep = pTemp->pNext_Kep; // Chèn node hiện tại vào sau node Temp
                pTemp->pNext_Kep = pCurrent;
            }
            pCurrent = pNEXT; // Di chuyển đến node kế tiếp
        }
        ds.pHead_Kep = pSorted;
    }
}
void insertionSortCircularLinkedList(LIST_VONG &ds, int tieuchi)
{
    pNODE_VONG pSorted = ds.pTail_Vong->pNext_Vong;
    pNODE_VONG pCurrent = ds.pTail_Vong->pNext_Vong;
    while (pCurrent != NULL)
    {
        if (tieuchi == 1)
        {
            pNODE_VONG pNEXT = pCurrent->pNext_Vong;
            if (pSorted == NULL || cmpStr(pCurrent->data.maSV, pSorted->data.maSV) > 0)
            {
                pCurrent->pNext_Vong = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                pNODE_VONG pTemp = pSorted;
                while (pTemp->pNext_Vong != NULL && cmpStr(pCurrent->data.maSV, pTemp->data.maSV) > 0)
                {
                    pTemp = pTemp->pNext_Vong;
                }
                pCurrent->pNext_Vong = pTemp->pNext_Vong;
                pTemp->pNext_Vong = pCurrent;
            }
            pCurrent = pNEXT;
        }
        if (tieuchi == 2)
        {
            pNODE_VONG pNEXT = pCurrent->pNext_Vong;
            if (pSorted == NULL || cmpStr(pCurrent->data.ten, pSorted->data.ten) > 0)
            {
                pCurrent->pNext_Vong = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                pNODE_VONG pTemp = pSorted;
                while (pTemp->pNext_Vong != NULL && cmpStr(pCurrent->data.ten, pTemp->data.ten) > 0)
                {
                    pTemp = pTemp->pNext_Vong;
                }
                pCurrent->pNext_Vong = pTemp->pNext_Vong;
                pTemp->pNext_Vong = pCurrent;
            }
            pCurrent = pNEXT;
        }
        if (tieuchi == 3)
        {
            pNODE_VONG pNEXT = pCurrent->pNext_Vong; // Lưu con trỏ pNEXT tới node kế tiếp

            if (pSorted == NULL || pCurrent->data.diem < pSorted->data.diem)
            {
                pCurrent->pNext_Vong = pSorted;
                pSorted = pCurrent;
            }
            else
            {
                // Tìm vị trí để chèn node hiện tại vào danh sách sắp xếp
                pNODE_VONG pTemp = pSorted;
                while (pTemp->pNext_Vong != NULL && pCurrent->data.diem > pTemp->pNext_Vong->data.diem)
                    pTemp = pTemp->pNext_Vong;

                pCurrent->pNext_Vong = pTemp->pNext_Vong; // Chèn node hiện tại vào sau node Temp
                pTemp->pNext_Vong = pCurrent;
            }
            pCurrent = pNEXT; // Di chuyển đến node kế tiếp
        }
        ds.pTail_Vong = pSorted;
    }
}
