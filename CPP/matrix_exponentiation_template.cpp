template<typename T>
struct Matrix{
    int r, c;
    vector<vector<T>> data;
    Matrix(int r, int c) : r(r), c(c){
        data.assign(r, vector<T> (c));
    }
    explicit Matrix(const vector<vector<T>> &a) {
        data = a, r = data.size(), c = data[0].size();
    }
    Matrix operator + (const Matrix &other) {
        assert(r == other.data.size() && c == other.data[0].size());
        Matrix<T> ans(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                ans.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return ans;
    }
    Matrix operator - (const Matrix &other) {
        assert(r == other.data.size() && c == other.data[0].size());
        Matrix<T> ans(r, c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                ans.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return ans;
    }
    Matrix operator * (const Matrix &other) {
        assert(c == other.data.size());
        int m = other.data[0].size();
        Matrix<T> ans(r, m);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < c; ++k) {
                    ans.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return ans;
    }
    friend ostream& operator << (ostream &_out, const Matrix<T> &other) {
        for (auto &i: other.data) {
            for (auto &j: i) {
                _out << j << ' ';
            }
            _out << "\n";
        }
        return _out;
    }
    Matrix& operator += (const Matrix &other) {
        *this = (*this + other);
        return *this;
    }
    Matrix& operator -= (const Matrix &other) {
        *this = (*this - other);
        return *this;
    }
    Matrix& operator *= (const Matrix &other) {
        *this = (*this * other);
        return *this;
    }
    Matrix transpose() {
        Matrix<T> res(c, r);
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                res[i][j] = data[j][i];
            }
        }
        return res;
    }
    vector<T>& operator [] (int i) {
        assert(i < r && i >= 0);
        return data[i];
    }
    vector<T>& operator [] (int i) const {
        assert(i < r && i >= 0);
        return data[i];
    }
    Matrix getIdentityMatrix() {
        assert(r == c);
        Matrix<T> id(r, r);
        for (int i = 0; i < r; ++i) {
            id.data[i][i] = (T)1;
        }
        return id;
    }
    Matrix pow(long long n) {
        if (n == 0) return getIdentityMatrix();
        Matrix<T> res = pow(n / 2);
        if (n % 2) return res * res * (*this);
        return res * res;
    }
};
