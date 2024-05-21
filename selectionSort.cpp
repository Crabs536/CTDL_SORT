void selectionSortMang(SV LIST_MANG[], int tieuChi)
{
    int vitrimin;
    int i, j;
    if (tieuChi == 1)
    {
        string min;
        for (i = 0; i < n - 1; i++)
        {
            min = LIST_MANG[i].maSV;
            vitrimin = i;
            for (j = i + 1; j < n; j++)
                if (cmpStr(LIST_MANG[j].maSV, min) < 0)
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
    if (tieuChi == 2)
    {
        string min;
        for (i = 0; i < n - 1; i++)
        {
            min = LIST_MANG[i].ten;
            vitrimin = i;
            for (j = i + 1; j < n; j++)
                if (cmpStr(LIST_MANG[j].ten, min) < 0)
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
    if (tieuChi == 3)
    {
        int min;
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
void selectionSortSinglyLinked(LIST_DON &ds, int tieuChi)
{
    pNODE_DON p, q, pMin;
    if (tieuChi == 1)
    {
        string min;
        for (p = ds.pHead_Don; p->pNext_Don != NULL; p = p->pNext_Don)
        {
            min = p->data.maSV;
            pMin = p;
            for (q = p->pNext_Don; q != NULL; q = q->pNext_Don)
            {
                if (cmpStr(q->data.maSV, min) < 0)
                {
                    min = q->data.maSV;
                    pMin = q;
                }
                pMin->data.maSV = q->data.maSV;
                p->data.maSV = min;
            }
        }
        ds.pHead_Don = pMin;
    }
    if (tieuChi == 2)
    {
        string min;
        for (p = ds.pHead_Don; p->pNext_Don != NULL; p = p->pNext_Don)
        {
            min = p->data.ten;
            pMin = p;
            for (q = p->pNext_Don; q != NULL; q = q->pNext_Don)
            {
                if (cmpStr(q->data.ten, min) < 0)
                {
                    min = q->data.ten;
                    pMin = q;
                }
                pMin->data.ten = q->data.ten;
                p->data.ten = min;
            }
        }
        ds.pHead_Don = pMin;
    }
    if (tieuChi == 3)
    {
        int min;
        for (p = ds.pHead_Don; p->pNext_Don != NULL; p = p->pNext_Don)
        {
            min = p->data.diem;
            pMin = p;
            for (q = p->pNext_Don; q != NULL; q = q->pNext_Don)
            {
                if (q->data.diem < min)
                {
                    min = q->data.diem;
                    pMin = q;
                }
                pMin->data.diem = p->data.diem;
                p->data.diem = min;
            }
        }
        ds.pHead_Don = pMin;
    }
}
void selectionSortDoubleLinked(LIST_KEP &ds, int tieuChi)
{
    pNODE_KEP p, q, pMin;
    if (tieuChi == 1)
    {
        string min;
        for (p = ds.pHead_Kep; p->pNext_Kep != NULL; p = p->pNext_Kep)
        {
            min = p->data.maSV;
            pMin = p;
            for (q = p->pNext_Kep; q != NULL; q = q->pNext_Kep)
            {
                if (cmpStr(q->data.maSV, min) < 0)
                {
                    min = q->data.maSV;
                    pMin = q;
                }
                pMin->data.maSV = q->data.maSV;
                p->data.maSV = min;
            }
        }
        ds.pHead_Kep = pMin;
    }
    if (tieuChi == 2)
    {
        string min;
        for (p = ds.pHead_Kep; p->pNext_Kep != NULL; p = p->pNext_Kep)
        {
            min = p->data.ten;
            pMin = p;
            for (q = p->pNext_Kep; q != NULL; q = q->pNext_Kep)
            {
                if (cmpStr(q->data.ten, min) < 0)
                {
                    min = q->data.ten;
                    pMin = q;
                }
                pMin->data.ten = q->data.ten;
                p->data.ten = min;
            }
        }
        ds.pHead_Kep = pMin;
    }
    if (tieuChi == 3)
    {
        int min;
        for (p = ds.pHead_Kep; p->pNext_Kep != NULL; p = p->pNext_Kep)
        {
            min = p->data.diem;
            pMin = p;
            for (q = p->pNext_Kep; q != NULL; q = q->pNext_Kep)
            {
                if (q->data.diem < min)
                {
                    min = q->data.diem;
                    pMin = q;
                }
                pMin->data.diem = p->data.diem;
                p->data.diem = min;
            }
        }
        ds.pHead_Kep = pMin;
    }
}
void selectionSortCircalLinked(LIST_VONG &ds, int tieuChi)
{
    pNODE_VONG q, p, pMin;
    pNODE_VONG Last = ds.pTail_Vong->pNext_Vong;
    if (tieuChi == 1)
    {
        string min;
        for (p = ds.pTail_Vong->pNext_Vong; p->pNext_Vong != ds.pTail_Vong->pNext_Vong; p = p->pNext_Vong)
        {
            min = p->data.maSV;
            pMin = p;
            for (q = p->pNext_Vong; q != Last->pNext_Vong; q = q->pNext_Vong)
            {
                if (cmpStr(q->data.maSV, min) < 0)
                {
                    min = q->data.maSV;
                    pMin = q;
                }
                pMin->data.maSV = p->data.maSV;
                p->data.maSV = min;
            }
        }
        ds.pTail_Vong = pMin;
    }
    if (tieuChi == 2)
    {
        string min;
        for (p = ds.pTail_Vong->pNext_Vong; p->pNext_Vong != ds.pTail_Vong->pNext_Vong; p = p->pNext_Vong)
        {
            min = p->data.ten;
            pMin = p;
            for (q = p->pNext_Vong; q != Last->pNext_Vong; q = q->pNext_Vong)
            {
                if (cmpStr(q->data.ten, min) < 0)
                {
                    min = q->data.ten;
                    pMin = q;
                }
                pMin->data.ten = p->data.ten;
                p->data.ten = min;
            }
        }
        ds.pTail_Vong = pMin;
    }
    if (tieuChi == 1)
    {
        int min;
        for (p = ds.pTail_Vong->pNext_Vong; p->pNext_Vong != ds.pTail_Vong->pNext_Vong; p = p->pNext_Vong)
        {
            min = p->data.diem;
            pMin = p;
            for (q = p->pNext_Vong; q != Last->pNext_Vong; q = q->pNext_Vong)
            {
                if (min > q->data.diem)
                {
                    min = q->data.diem;
                    pMin = q;
                }
                pMin->data.diem = p->data.diem;
                p->data.diem = min;
            }
        }
        ds.pTail_Vong = pMin;
    }
}
