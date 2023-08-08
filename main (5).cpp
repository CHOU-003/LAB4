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


void XoaNV(nhanvien N[], int &n){
    for(int i = 0; i < n; i++){
        if(N[i].CBQL == 0){
            for(int j = i; j < n-1; j++){
                N[j] = N[j+1];
            }
            N[n-1] = {};
            n--;
            i--;
        }
    }
    
    cout << "\nDanh sach nhan vien sau khi xoa cac nhan vien khong co chuc vu quan ly:" << endl;

}


void themnv(nhanvien n[], int &n_size, int k){
    nhanvien newNv;
    cout << "\nNhap thong tin nhan vien can them:" << endl;
    Nhap(newNv);

    if(k >= 0 && k <= n_size){
        for(int i = n_size; i > k; i--){
            n[i] = n[i-1];
        }
        n[k] = newNv;
        n_size++;
    }
    else{
        cout << "\nVi tri chen khong hop le!" << endl;
    }
}



int main()
{
    nhanvien nv[50];
    int n, chon;
    do {
        cout << "Nhap vao cau ban muon xem: ";
        cin >> chon;
        switch(chon){
            case 1:
                cout << "Nhap so luong nhan vien: "; cin >> n;
                for(int i = 0; i < n; i++) {
                    Nhap(nv[i]);
                }
                break;
            case 2:
                XuatNV(nv,n);
                break;
            case 3:
                XoaNV(nv, n);
                for(int i = 0; i < n; i++) {
                    Xuat(nv[i]);
                } 
                break;
            case 4:
                    int k;
                    cout << "\nNhap vi tri muon chen nhan vien (tu 0 den " << n << "): ";
                    cin >> k;
                    themnv(nv, n, k);
                    for(int i = 0; i < n; i++) {
                        Xuat(nv[i]);
                    } 
                    break;
        }
        
    }while(chon > 0);

    return 0;
}
