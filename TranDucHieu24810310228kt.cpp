#include <iostream>
#include <string>

using namespace std;

struct KhachHang {
    int ma;
    string ten;
    string sdt;
    double tien;
};

void nhap1(KhachHang &kh) {
    cout << "  Nhap ma khach hang: ";
    cin >> kh.ma;
    cin.ignore();

    cout << "  Nhap ten khach hang: ";
    getline(cin, kh.ten);

    cout << "  Nhap so dien thoai: ";
    getline(cin, kh.sdt);

    cout << "  Nhap tong tien thanh toan: ";
    cin >> kh.tien;
}

void xuat1(KhachHang kh) {
    cout << "Ma KH: " << kh.ma 
         << " | Ten: " << kh.ten 
         << " | SDT: " << kh.sdt 
         << " | Tong tien: " << kh.tien << endl;
}

void nhapDS(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap khach hang thu " << i + 1 << " ---" << endl;
        nhap1(a[i]);
    }
}

void xuatDS(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        xuat1(a[i]);
    }
}

void sapXep(KhachHang a[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tien > x.tien) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
    }
}

void timKiem(KhachHang a[], int n, double x) {
    int l = 0;
    int r = n - 1;
    int pos = -1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m].tien == x) {
            pos = m;
            break;
        }
        if (a[m].tien < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (pos == -1) {
        cout << "\nKhong co khach hang nao co tong tien thanh toan bang " << x << endl;
        return;
    }

    cout << "\n=== DANH SACH KHACH HANG CO TONG TIEN = " << x << " ===" << endl;

    int dau = pos;
    while (dau - 1 >= 0 && a[dau - 1].tien == x) {
        dau--;
    }

    int cuoi = pos;
    while (cuoi + 1 < n && a[cuoi + 1].tien == x) {
        cuoi++;
    }

    for (int i = dau; i <= cuoi; i++) {
        xuat1(a[i]);
    }
}

int main() {
    int n;
    cout << "Nhap so luong khach hang n: ";
    cin >> n;

    if (n <= 0) {
        cout << "So luong khach hang phai lon hon 0!" << endl;
        return 0;
    }

    KhachHang a[100];

    nhapDS(a, n);
    cout << "\n DANH SACH KHACH HANG VUA NHAP" << endl;
    xuatDS(a, n);

    sapXep(a, n);
    cout << "\n DANH SACH SAU KHI SAP XEP TANG DAN THEO TONG TIEN " << endl;
    xuatDS(a, n);

    double x;
    cout << "\nNhap tong tien thanh toan X can tim: ";
    cin >> x;
    timKiem(a, n, x);

    return 0;
}
