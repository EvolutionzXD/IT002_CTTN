#include <bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string HoTen;
    string NgaySinh;
    double LuongCoBan;
public:
    NhanVien(string _HoTen = "", string _NgaySinh = "", double _LCB = 0) {
        HoTen = _HoTen;
        NgaySinh = _NgaySinh;
        LuongCoBan = _LCB;
    }

    virtual ~NhanVien() {}

    virtual void nhap(istream &inp) {
        inp >> ws;
        getline(inp, HoTen);
        getline(inp, NgaySinh);
        inp >> LuongCoBan;
    }

    virtual void xuat(ostream &out) const {
        out << "Ho ten: " << HoTen << " | Ngay sinh: " << NgaySinh
            << " | LCB: " << fixed << setprecision(0) << LuongCoBan
            << " | Luong thuc nhan: " << fixed << setprecision(0) << TinhLuong();
    }

    virtual double TinhLuong() const = 0; // Thuan ao (Pure virtual)

    string getHoTen() const {
        return HoTen;
    }

    friend istream& operator >> (istream &inp, NhanVien &nv) {
        nv.nhap(inp);
        return inp;
    }

    friend ostream& operator << (ostream &out, const NhanVien &nv) {
        nv.xuat(out);
        return out;
    }
};

class NhanVienVanPhong : public NhanVien {
private:
    int SoNgayLamViec;
    double TroCap;
public:
    NhanVienVanPhong(string _HoTen = "", string _NgaySinh = "", double _LCB = 0, int _Ngay = 0, double _TC = 0)
        : NhanVien(_HoTen, _NgaySinh, _LCB) {
        SoNgayLamViec = _Ngay;
        TroCap = _TC;
    }

    void nhap(istream &inp) override {
        NhanVien::nhap(inp);
        inp >> SoNgayLamViec >> TroCap;
    }

    void xuat(ostream &out) const override {
        out << "[Van Phong] ";
        NhanVien::xuat(out);
        out << " | Ngay lam: " << SoNgayLamViec << " | Tro cap: " << fixed << setprecision(0) << TroCap;
    }

    double TinhLuong() const override {
        return LuongCoBan + SoNgayLamViec * 200000.0 + TroCap;
    }
};

class NhanVienSanXuat : public NhanVien {
private:
    int SoSanPham;
public:
    NhanVienSanXuat(string _HoTen = "", string _NgaySinh = "", double _LCB = 0, int _SP = 0)
        : NhanVien(_HoTen, _NgaySinh, _LCB) {
        SoSanPham = _SP;
    }

    void nhap(istream &inp) override {
        NhanVien::nhap(inp);
        inp >> SoSanPham;
    }

    void xuat(ostream &out) const override {
        out << "[San Xuat]  ";
        NhanVien::xuat(out);
        out << " | So san pham: " << SoSanPham;
    }

    double TinhLuong() const override {
        return LuongCoBan + SoSanPham * 2000.0;
    }
};

class NhanVienQuanLy : public NhanVien {
private:
    double HeSoChucVu;
    double Thuong;
public:
    NhanVienQuanLy(string _HoTen = "", string _NgaySinh = "", double _LCB = 0, double _HSCV = 1.0, double _Thuong = 0)
        : NhanVien(_HoTen, _NgaySinh, _LCB) {
        HeSoChucVu = _HSCV;
        Thuong = _Thuong;
    }

    void nhap(istream &inp) override {
        NhanVien::nhap(inp);
        inp >> HeSoChucVu >> Thuong;
    }

    void xuat(ostream &out) const override {
        out << "[Quan Ly]   ";
        NhanVien::xuat(out);
        out << " | He so CV: " << HeSoChucVu << " | Thuong: " << fixed << setprecision(0) << Thuong;
    }

    double TinhLuong() const override {
        return LuongCoBan * HeSoChucVu + Thuong;
    }
};

class CongTyABC {
private:
    int n;
    NhanVien **arr;
public:
    CongTyABC(int _n = 0) {
        n = _n;
        arr = (n > 0) ? new NhanVien*[n] : nullptr;
    }

    ~CongTyABC() {
        if (arr != nullptr) {
            for (int i = 0; i < n; i++) delete arr[i];
            delete[] arr;
        }
    }

    void nhap(istream &inp) {
        inp >> n;
        if (arr != nullptr) {
            for (int i = 0; i < n; i++) delete arr[i];
            delete[] arr;
        }
        arr = new NhanVien*[n];
        for (int i = 0; i < n; i++) {
            int loai;
            inp >> loai; // 1: Van phong, 2: San xuat, 3: Quan ly
            if (loai == 1) arr[i] = new NhanVienVanPhong();
            else if (loai == 2) arr[i] = new NhanVienSanXuat();
            else arr[i] = new NhanVienQuanLy();
            inp >> *arr[i];
        }
    }

    void xuat(ostream &out) const {
        for (int i = 0; i < n; i++) {
            out << *arr[i] << "\n";
        }
    }

    double TinhTongLuong() const {
        double tong = 0;
        for (int i = 0; i < n; i++) {
            tong += arr[i]->TinhLuong();
        }
        return tong;
    }

    void TimKiemTheoTen(const string &ten, ostream &out) const {
        bool thay = false;
        for (int i = 0; i < n; i++) {
            if (arr[i]->getHoTen() == ten || arr[i]->getHoTen().find(ten) != string::npos) {
                out << *arr[i] << "\n";
                thay = true;
            }
        }
        if (!thay) out << "Khong tim thay nhan vien nao co ten: " << ten << "\n";
    }

    friend istream& operator >> (istream &inp, CongTyABC &cty) {
        cty.nhap(inp);
        return inp;
    }

    friend ostream& operator << (ostream &out, const CongTyABC &cty) {
        cty.xuat(out);
        return out;
    }
};
