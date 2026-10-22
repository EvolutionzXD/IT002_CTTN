#include <bits/stdc++.h>
using namespace std;

class MATRIX {
private:
    float **M;
    int row, col;
public:
	
    MATRIX(int r = 0, int c = 0) {
        row = r;
        col = c;
        if (row > 0 && col > 0) {
            M = new float*[row];
            for (int i = 0; i < row; i++) {
                M[i] = new float[col]();
            }
        } else {
            M = nullptr;
            row = col = 0;
        }
    }

    MATRIX(const MATRIX &other) {
        row = other.row;
        col = other.col;
        if (row > 0 && col > 0) {
            M = new float*[row];
            for (int i = 0; i < row; i++) {
                M[i] = new float[col];
                for (int j = 0; j < col; j++) {
                    M[i][j] = other.M[i][j];
                }
            }
        } else {
            M = nullptr;
        }
    }

    ~MATRIX() {
        if (M != nullptr) {
            for (int i = 0; i < row; i++) {
                delete[] M[i];
            }
            delete[] M;
        }
    }

    MATRIX& operator = (const MATRIX &other) {
        if (this == &other) return *this;
        
        if (M != nullptr) {
            for (int i = 0; i < row; i++) delete[] M[i];
            delete[] M;
        }

        row = other.row;
        col = other.col;
        if (row > 0 && col > 0) {
            M = new float*[row];
            for (int i = 0; i < row; i++) {
                M[i] = new float[col];
                for (int j = 0; j < col; j++) {
                    M[i][j] = other.M[i][j];
                }
            }
        } else {
            M = nullptr;
        }
        return *this;
    }

    float& operator() (int i, int j) {
        return M[i][j];
    }

    const float& operator() (int i, int j) const {
        return M[i][j];
    }

    void TaoNgauNhien(int r, int c) {
        if (M != nullptr) {
            for (int i = 0; i < row; i++) delete[] M[i];
            delete[] M;
        }
        row = r;
        col = c;
        M = new float*[row];
        for (int i = 0; i < row; i++) {
            M[i] = new float[col];
            for (int j = 0; j < col; j++) {
                M[i][j] = (rand() % 90 + 10) / 10.0f;
            }
        }
    }

    friend istream& operator >> (istream &inp, MATRIX &mat) {
        int r, c;
        inp >> r >> c;
        if (mat.M != nullptr) {
            for (int i = 0; i < mat.row; i++) delete[] mat.M[i];
            delete[] mat.M;
        }
        mat.row = r;
        mat.col = c;
        mat.M = new float*[mat.row];
        for (int i = 0; i < mat.row; i++) {
            mat.M[i] = new float[mat.col];
            for (int j = 0; j < mat.col; j++) {
                inp >> mat.M[i][j];
            }
        }
        return inp;
    }

   
    friend ostream& operator << (ostream &out, const MATRIX &mat) {
        for (int i = 0; i < mat.row; i++) {
            for (int j = 0; j < mat.col; j++) {
                out << mat.M[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }

    MATRIX operator + (const MATRIX &other) const {
        if (row != other.row || col != other.col) {
            cout << "Hai ma tran khong cung kich thuoc\n";
            return MATRIX(0, 0);
        }
        MATRIX kq(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                kq.M[i][j] = M[i][j] + other.M[i][j];
            }
        }
        return kq;
    }

    MATRIX operator - (const MATRIX &other) const {
        if (row != other.row || col != other.col) {
            cout << "Hai ma tran khong cung kich thuoc\n";
            return MATRIX(0, 0);
        }
        MATRIX kq(row, col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                kq.M[i][j] = M[i][j] - other.M[i][j];
            }
        }
        return kq;
    }

    MATRIX operator * (const MATRIX &other) const {
        if (col != other.row) {
            cout << "So cot ma tran 1 phai bang so dong ma tran\n";
            return MATRIX(0, 0);
        }
        MATRIX kq(row, other.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < other.col; j++) {
                kq.M[i][j] = 0;
                for (int k = 0; k < col; k++) {
                    kq.M[i][j] += M[i][k] * other.M[k][j];
                }
            }
        }
        return kq;
    }
};

