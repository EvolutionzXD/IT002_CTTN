#include <bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string MaNV;
    string HoTen;
    int Tuoi;
    string SDT;
    string Email;
    double LuongCoBan;
public:
    NhanVien(string _MaNV = "", string _HoTen = "", int _Tuoi = 0, string _SDT = "", string _Email = "", double _LCB = 0) {
        MaNV = _MaNV;
        HoTen = _HoTen;
        Tuoi = _Tuoi;
        SDT = _SDT;
        Email = _Email;
        LuongCoBan = _LCB;
    }

    virtual ~NhanVien() {}

    virtual void nhap(istream &inp) {
        inp >> ws;
        getline(inp, MaNV);
        getline(inp, HoTen);
        inp >> Tuoi;
        inp >> ws;
        getline(inp, SDT);
        getline(inp, Email);
        inp >> LuongCoBan;
    }

    virtual void xuat(ostream &out) const {
        out << "Ma NV: " << MaNV << " | Ten: " << HoTen << " | Tuoi: " << Tuoi
            << " | SDT: " << SDT << " | Email: " << Email 
            << " | LCB: " << fixed << setprecision(0) << LuongCoBan
            << " | Luong: " << fixed << setprecision(0) << TinhLuong();
    }

    virtual double TinhLuong() const = 0;

    friend istream& operator >> (istream &inp, NhanVien &nv) {
        nv.nhap(inp);
        return inp;
    }

    friend ostream& operator << (ostream &out, const NhanVien &nv) {
        nv.xuat(out);
        return out;
    }
};

class LapTrinhVien : public NhanVien {
private:
    double GioOvertime;
public:
    LapTrinhVien(string _MaNV = "", string _HoTen = "", int _Tuoi = 0, string _SDT = "", string _Email = "", double _LCB = 0, double _OT = 0)
        : NhanVien(_MaNV, _HoTen, _Tuoi, _SDT, _Email, _LCB) {
        GioOvertime = _OT;
    }

    void nhap(istream &inp) override {
        NhanVien::nhap(inp);
        inp >> GioOvertime;
    }

    void xuat(ostream &out) const override {
        out << "[LTV] ";
        NhanVien::xuat(out);
        out << " | Overtime: " << GioOvertime << "h";
    }

    double TinhLuong() const override {
        return LuongCoBan + GioOvertime * 200000.0;
    }
};

class KiemChungVien : public NhanVien {
private:
    int SoLoi;
public:
    KiemChungVien(string _MaNV = "", string _HoTen = "", int _Tuoi = 0, string _SDT = "", string _Email = "", double _LCB = 0, int _Loi = 0)
        : NhanVien(_MaNV, _HoTen, _Tuoi, _SDT, _Email, _LCB) {
        SoLoi = _Loi;
    }

    void nhap(istream &inp) override {
        NhanVien::nhap(inp);
        inp >> SoLoi;
    }

    void xuat(ostream &out) const override {
        out << "[KCV] ";
        NhanVien::xuat(out);
        out << " | So loi: " << SoLoi;
    }

    double TinhLuong() const override {
        return LuongCoBan + SoLoi * 50000.0;
    }
};

class CongTyHoanCau {
private:
    int n;
    NhanVien **arr;
public:
    CongTyHoanCau(int _n = 0) {
        n = _n;
        arr = (n > 0) ? new NhanVien*[n] : nullptr;
    }

    ~CongTyHoanCau() {
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
            int type;
            inp >> type; 
            if (type == 1) arr[i] = new LapTrinhVien();
            else arr[i] = new KiemChungVien();
            
            inp >> *arr[i];
        }
    }

    void xuat(ostream &out) const {
        for (int i = 0; i < n; i++) {
            out << *arr[i] << "\n";
        }
    }

    double LuongTrungBinh() const {
        if (n == 0) return 0;
        double tong = 0;
        for (int i = 0; i < n; i++) tong += arr[i]->TinhLuong();
        return tong / n;
    }

    void ThapHonTB(ostream &out) const {
        double tb = LuongTrungBinh();
        out << "Muc luong trung binh: " << fixed << setprecision(0) << tb << " VND\n";
        out << "Danh sach nhan vien luong duoi muc trung binh:\n";
        for (int i = 0; i < n; i++) {
            if (arr[i]->TinhLuong() < tb) {
                out << *arr[i] << "\n";
            }
        }
    }

    friend istream& operator >> (istream &inp, CongTyHoanCau &ct) {
        ct.nhap(inp);
        return inp;
    }

    friend ostream& operator << (ostream &out, const CongTyHoanCau &ct) {
        ct.xuat(out);
        return out;
    }
};
