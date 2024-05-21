#include "structSinhVien.h"
#include "mang.h"
#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"
#include "checkMaSv.h"
#include "nhapXuat.h"
#include "xoa.h"
#include "lietKe_TinhDiem.h"
#include "bubbleSort.h"

void menuChoMang(SV listMang[], int &soLuongSinhVien)
{
    string luaChon;
    bool backToMainMenu = false;
    while (!backToMainMenu)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH QUAN LY SINH VIEN BANG DANH SACH MANG ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   9. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhap lua chon: ";
        getline(cin, luaChon);

        regex pattern("[0-9]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 9 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            cout << "\n\t   1. Xuất danh sách sinh viên \n\n";
            inTieuDe();
            xuatSinhVienMang(listMang, soLuongSinhVien);
        }

        if (luaChon == "2")
        {
            // cout << "\n\t   2. Tìm kiếm sinh viên\n\n";
            // timKiemSinhVienMang(listMang, soLuongSinhVien);
        }

        if (luaChon == "3")
        {
            cout << "\n\t   3. Thêm mới sinh viên\n\n";
            themSinhVienMang(listMang, soLuongSinhVien, soLuongSinhVien);
            cout << "\n\tTHEM THANH CONG !!!\n\n";
        }

        if (luaChon == "4")
        {
            // cin.ignore();
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVMang(LIST_MANG, soLuongSinhVien);
            cout << "\n\tXOA THANH CONG !!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatMang(LIST_MANG, soLuongSinhVien);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatMang(LIST_MANG, soLuongSinhVien);
        }

        if (luaChon == "7")
        {

            cout << "\n\t-- Diem Trung Binh cua cac sinh vien: " << diemTBMang(LIST_MANG, soLuongSinhVien) << endl;
        }

        if (luaChon == "9")
        {
            cin.ignore();
            break;
        }

        if (luaChon == "0")
        {
            cout << "\n\t == KET THUC CHUONG TRINH ==\n";
            cin.ignore();
            exit(0);
        }
        system("pause");
    }
}

void menuChoDSLKDon(LIST_DON listDon)
{
    string luaChon;
    bool backToMainMenu = false;
    while (!backToMainMenu)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH QUAN LY SINH VIEN BANG DANH SACH LIEN KET DON ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   10. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhap lua chon: ";
        getline(cin, luaChon);

        regex pattern("[0-10]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 10 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            inTieuDe();
            xuatDSLKDon(listDon);
        }

        if (luaChon == "2")
        {
            // timKiemSinhVienDanhSachLKDon(listDon);
        }

        if (luaChon == "3")
        {
            cout << "- Them sinh vien tiep theo: ";
            themSVVaoCuoiDSLKDon(listDon, nhapThongTinSinhVien());
            cout << "\n\tTHEM THANH CONG !!!\n\n";
        }

        if (luaChon == "4")
        {
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVDSLKDon(listDon);
            cout << "\n\tXOA THANH CONG !!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatDSLKDon(listDon);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatDSLKDon(listDon);
        }

        if (luaChon == "7")
        {
            cout << "\n\t-- Diem Trung Binh cua cac sinh vien: " << diemTBDSLKDon(listDon) << endl;
        }

        if (luaChon == "10")
        {
            cin.ignore();
            break;
        }
        if (luaChon == "0")
        {
            // giaiPhongBoNhoDSLKDon(listDon);
            cout << "\n\t == KET THUC CHUONG TRINH ==\n";
            exit(0);
        }
        system("pause");
    }
}

void menuChoDSLKVong(LIST_VONG listVong)
{
    string luaChon;
    bool backToMainMenu = false;
    while (!backToMainMenu)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH QUAN LY SINH VIEN BANG DANH SACH LIEN KET VONG ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   10. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhap lua chon: ";
        getline(cin, luaChon);

        regex pattern("[0-10]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 10 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            inTieuDe();
            xuatDSLKVong(listVong);
        }

        if (luaChon == "2")
        {
            // timKiemSinhVienDanhSachLKVong(listVong);
        }

        if (luaChon == "3")
        {
            cout << "- Them sinh vien tiep theo: ";
            themSVVaoCuoiDSLKVong(listVong, nhapThongTinSinhVien());
            cout << "\n\tTHEM THANH CONG !!!\n\n";
        }

        if (luaChon == "4")
        {
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVDSLKVong(listVong);
            cout << "\n\tXOA THANH CONG !!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatDSLKVong(listVong);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatDSLKVong(listVong);
        }

        if (luaChon == "7")
        {
            cout << "\n\t-- Diem Trung Binh cua cac sinh vien: " << diemTBDSLKVong(listVong) << endl;
        }

        if (luaChon == "10")
        {
            cin.ignore();
            break;
        }
        if (luaChon == "0")
        {
            // giaiPhongBoNhoDSLKVong(listVong);
            cout << "\n\t == KET THUC CHUONG TRINH ==\n";
            exit(0);
        }
        system("pause");
    }
}

void menuChoDSLKKep(LIST_KEP listKep)
{
    string luaChon;
    bool backToMainMenu = false;
    while (!backToMainMenu)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH QUAN LY SINH VIEN BANG DANH SACH LIEN KET KEP ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Xuất danh sách sinh viên";
        cout << "\n\t   2. Tìm kiếm sinh viên";
        cout << "\n\t   3. Thêm mới sinh viên";
        cout << "\n\t   4. Xóa sinh viên";
        cout << "\n\t   5. Liệt kê các sinh viên có điểm thấp nhất";
        cout << "\n\t   6. Liệt kê các sinh viên có điểm cao nhất";
        cout << "\n\t   7. Tính điểm trung bình của lớp";
        cout << "\n\t   8. Sắp xếp danh sách sinh viên";
        cout << "\n\t   10. Quay lai";
        cout << "\n\t   0. Thoát";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhap lua chon: ";
        getline(cin, luaChon);

        regex pattern("[0-10]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 0 -> 10 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            inTieuDe();
            xuatDSLKKep(listKep);
        }

        if (luaChon == "2")
        {
            // timKiemSinhVienDanhSachLKKep(listKep);
        }

        if (luaChon == "3")
        {
            cout << "- Them sinh vien tiep theo: ";
            themSVVaoCuoiDSLKKep(listKep, nhapThongTinSinhVien());
            cout << "\n\tTHEM THANH CONG !!!\n\n";
        }

        if (luaChon == "4")
        {
            cin.ignore();
            cout << "\n\t   4. Xóa sinh viên\n\n";
            xoaSVDSLKKep(listKep);
            cout << "\n\tXOA THANH CONG !!!\n\n";
        }

        if (luaChon == "5")
        {
            lietKeSVDiemCaoNhatDSLKKep(listKep);
        }

        if (luaChon == "6")
        {
            lietKeSVDiemThapNhatDSLKKep(listKep);
        }

        if (luaChon == "7")
        {
            cout << "\n\t-- Diem Trung Binh cua cac sinh vien: " << diemTBDSLKKep(listKep) << endl;
        }

        if (luaChon == "10")
        {
            cin.ignore();
            break;
        }
        if (luaChon == "0")
        {
            // giaiPhongBoNhoDSLKKep(listKep);
            cout << "\n\t == KET THUC CHUONG TRINH ==\n";
            exit(0);
        }
        system("pause");
    }
}

static void mainMenu()
{
    string luaChon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH QUAN LY SINH VIEN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t   1. Lưu trữ bằng danh sách mảng";
        cout << "\n\t   2. Lưu trữ bằng danh sách liên kết đơn";
        cout << "\n\t   3. Lưu trữ bằng danh sách liên kết vòng";
        cout << "\n\t   4. Lưu trữ bằng danh sách liên kết kép";
        cout << "\n\t======================= END =======================";
        cout << "\n\tVui lòng chọn cách thức lưu trữ(nhập số)";
        cout << "\n\n\t - Nhap lua chon: ";
        getline(cin, luaChon);

        regex pattern("[1-4]");
        while (!regex_match(luaChon, pattern))
        {
            cout << "\n Chỉ nhập các số từ 1 -> 4 để chọn: ";
            getline(cin, luaChon);
        }

        if (luaChon == "1")
        {
            nhapMang();
            menuChoMang(LIST_MANG, soLuong);
        }

        if (luaChon == "2")
        {

            LIST_DON listDon;
            khoitaoDSLKDon(listDon);

            nhapDon(listDon);
            menuChoDSLKDon(listDon);
        }

        if (luaChon == "3")
        {

            LIST_VONG listVong;
            khoiTaoDSLKVong(listVong);

            nhapVong(listVong);
            menuChoDSLKVong(listVong);
        }

        if (luaChon == "4")
        {

            LIST_KEP listKep;
            khoiTaoDSLKKep(listKep);

            nhapKep(listKep);
            menuChoDSLKKep(listKep);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    SetConsoleOutputCP(CP_UTF8);
    mainMenu();
}