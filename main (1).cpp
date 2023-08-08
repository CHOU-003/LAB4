#include <iostream>
#include <cmath>
#include <string>

using namespace std;

typedef struct NhanVien {
    double MaNV;
    string Hoten;
    string DiaChi;
    int CBQL;
} nhanvien;

void Nhap(nhanvien &N){
    cin.ignore();
    cout << "Nhap thong tin nhan vien: " << endl;
    cout << "Nhap ma nhan vien: "; cin >> N.MaNV;
    cin.ignore();
    cout << "Nhap ho va ten: "; getline(cin, N.Hoten);
    cout << "Nhap Dia chi: "; getline(cin, N.DiaChi);
    cout << "Nhap chuc vu: "; cin >> N.CBQL;
}

void Xuat(nhanvien N){
    cout <<"\n Thong tin cac nhan vien la: \n";
    cout << N.MaNV << "\n" << N.Hoten << "\n" << N.DiaChi << "\n" << N.CBQL;
}

void XuatNV(nhanvien N[], int n){
    for(int i=0; i<n; i++){
        if(N[i].CBQL == 1){
            cout << "Can bo quan ly: "<< N[i].Hoten << endl;
        }
    }
}

int main()
{
    nhanvien nv[50];
    int n;
    cout << "Nhap so luong nhan vien: "; cin >> n;
      for(int i = 0; i < n; i++) {
        Nhap(nv[i]);
    }
    XuatNV(nv,n);

    return 0;
}
