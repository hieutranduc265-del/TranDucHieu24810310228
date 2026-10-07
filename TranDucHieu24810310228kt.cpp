#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct KhachHang {
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTienThanhToan;
};

void nhap1KhachHang(KhachHang &kh) {
    cout << "  Nhap ma khach hang: ";
    cin >> kh.maKH;
    cin.ignore();

    cout << "  Nhap ten khach hang: ";
    getline(cin, kh.tenKH);

    cout << "  Nhap so dien thoai: ";
    getline(cin, kh.soDienThoai);

    cout << "  Nhap tong tien thanh toan: ";
    cin >> kh.tongTienThanhToan;
}

void xuat1KhachHang(const KhachHang &kh) {
    cout << "Ma KH: " << kh.maKH 
         << " | Ten: " << kh.tenKH 
         << " | SDT: " << kh.soDienThoai 
         << " | Tong tien: " << kh.tongTienThanhToan << endl;
}

void nhapDanhSach(vector<KhachHang> &ds, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap khach hang thu " << i + 1 << " ---" << endl;
        KhachHang kh;
        nhap1KhachHang(kh);
        ds.push_back(kh);
    }
}

void xuatDanhSach(const vector<KhachHang> &ds) {
    if (ds.empty()) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    for (size_t i = 0; i < ds.size(); i++) {
        cout << i + 1 << ". ";
        xuat1KhachHang(ds[i]);
    }
}

void insertionSort(vector<KhachHang> &ds) {
    int n = ds.size();
    for (int i = 1; i < n; i++) {
        KhachHang key = ds[i];
        int j = i - 1;

        while (j >= 0 && ds[j].tongTienThanhToan > key.tongTienThanhToan) {
            ds[j + 1] = ds[j];
            j = j - 1;
        }
        ds[j + 1] = key;
    }
}

void timKiemNhiPhanTheoTongTien(const vector<KhachHang> &ds, double X) {
    int left = 0;
    int right = ds.size() - 1;
    int pos = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (ds[mid].tongTienThanhToan == X) {
            pos = mid;
            break;
        }
        if (ds[mid].tongTienThanhToan < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (pos == -1) {
        cout << "\nKhong co khach hang nao co tong tien thanh toan bang " << X << endl;
        return;
    }

    cout << "\n=== DANH SACH KHACH HANG CO TONG TIEN = " << X << " ===" << endl;

    int first = pos;
    while (first - 1 >= 0 && ds[first - 1].tongTienThanhToan == X) {
        first--;
    }

    int last = pos;
    while (last + 1 < (int)ds.size() && ds[last + 1].tongTienThanhToan == X) {
        last++;
    }

    for (int i = first; i <= last; i++) {
        xuat1KhachHang(ds[i]);
    }
}

int main() {
    int n;
    vector<KhachHang> ds;

    cout << "Nhap so luong khach hang n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong khach hang phai lon hon 0!" << endl;
        return 0;
    }

    nhapDanhSach(ds, n);
    cout << "\nDANH SACH KHACH HANG VUA NHAP" << endl;
    xuatDanhSach(ds);

    insertionSort(ds);
    cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO TONG TIEN" << endl;
    xuatDanhSach(ds);

    double X;
    cout << "\nNhap tong tien thanh toan X can tim: ";
    cin >> X;
    timKiemNhiPhanTheoTongTien(ds, X);

    return 0;
}
