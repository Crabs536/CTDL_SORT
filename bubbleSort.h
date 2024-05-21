int cmpStr(string s1, string s2)
{
    return strcmp(s1.c_str(), s2.c_str());
}

void bubbleSortArray(SV LIST_MANG[], int tieuChi)
{
    for (int i = 1; i < soLuong; i++)
        for (int j = soLuong - 1; j >= i; j--)
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
        if (i == 0)
            break;
        end = p;
    } while (i > 0);
}

void bubbleSortDoublyLinkedList(LIST_KEP &ds, int tieuChi)
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
        if (i == 0)
            break;
        end = p;
    } while (i > 0);
}

void bubbleSortCircularLinkedList(LIST_VONG &ds, int tieuChi)
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
        if (i == 0)
            break;
        end = p;
    } while (i > 0);
}
