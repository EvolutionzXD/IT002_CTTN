#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tuso, mauso;
public:
    PhanSo(int t = 0, int m = 1) {
        tuso = t;
        mauso = (m != 0) ? m : 1;
        if (mauso < 0) {
            tuso = -tuso;
            mauso = -mauso;
        }
    }

    friend istream& operator >> (istream &inp, PhanSo &p) {
        is >> p.tuso >> p.mauso;
        if (p.mauso == 0) p.mauso = 1;
        if (p.mauso < 0) {
            p.tuso = -p.tuso;
            p.mauso = -p.mauso;
        }
        return inp;
    }

    friend ostream& operator << (ostream &out, const PhanSo &p) {
        if (p.mauso == 1 || p.tuso == 0) {
            out << p.tuso;
        } else {
            out << p.tuso << "/" << p.mauso;
        }
        return out;
    }

    bool operator > (const PhanSo &p) const {
        return (long long)tuso * p.mauso > (long long)p.tuso * mauso;
    }

    PhanSo operator + (const PhanSo &p) const {
        return PhanSo(tuso * p.mauso + mauso * p.tuso, mauso * p.mauso);
    }
};

class DSPhanSo {
private:
    PhanSo *arr;
    int n;
public:
    DSPhanSo() {
        n = 0;
        arr = nullptr;
    }

    ~DSPhanSo() {
        delete[] arr;
    }

    friend istream& operator >> (istream &inp, DSPhanSo &ds) {
        inp >> ds.n;
        delete[] ds.arr; 
        ds.arr = new PhanSo[ds.n];
        for (int i = 0; i < ds.n; i++) {
            inp >> ds.arr[i];
        }
        return inp;
    }

    friend ostream& operator << (ostream &out, const DSPhanSo &ds) {
        for (int i = 0; i < ds.n; i++) {
            out << ds.arr[i] << " ";
        }
        return out;
    }

    PhanSo TimMax() const {
        if (n <= 0) return PhanSo(0, 1);
        PhanSo max_ps = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max_ps) {
                max_ps = arr[i];
            }
        }
        return max_ps;
    }

    PhanSo TinhTong() const {
        PhanSo tong(0, 1);
        for (int i = 0; i < n; i++) {
            tong = tong + arr[i];
        }
        return tong;
    }
};
