#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Point
{
private:
    double HoanhDo;
    double TungDo;
public:
    Point();
    Point(double a, double b);
    ~Point();
    Point Nhap();
    Point Tinh_tien(Point &P, double a, double b);
    int Lay_hoang_do();
    int Lay_tung_do();
    void Xuat(Point a);
    double KhoangCach(Point A, Point B);
    friend class TamGiac;
};

class TamGiac
{
private:
    Point a;
    Point b;
    Point c;
public:
    TamGiac();
    TamGiac(Point a, Point b, Point c);
    ~TamGiac();
    TamGiac(const TamGiac &T);
    int Kiemtra(TamGiac T);
    TamGiac Nhap(TamGiac &T);
    TamGiac Tinh_tien(TamGiac &T, double a, double b);
    double ChuVi(TamGiac &T);
    double DienTich(TamGiac &T);
    void Xuat(TamGiac T);
};

Point ::Point()
{
    HoanhDo = 0;
    TungDo = 0;
}

Point ::Point(double a, double b)
{
    HoanhDo = a;
    TungDo = b;
}

Point ::~Point()
{
    HoanhDo = 0;
    TungDo = 0;
}

Point Point ::Nhap()
{
    Point a(0, 0);
    cout << "Nhap hoanh do: ";
    cin >> a.HoanhDo;
    cout << "Nhap tung do: ";
    cin >> a.TungDo;
    return a;
}

void Point ::Xuat(Point a)
{
    cout << "<" << a.HoanhDo << "," << a.TungDo << ">" << endl;
}

int Point ::Lay_hoang_do()
{
    return HoanhDo;
}

int Point ::Lay_tung_do()
{
    return TungDo;
}

Point Point ::Tinh_tien(Point &P, double a, double b)
{
    P.HoanhDo += a;
    P.TungDo += b;
    return P;
}

double Point ::KhoangCach(Point A, Point B)
{
    double s = 0;
    s = (B.HoanhDo - A.HoanhDo) * (B.HoanhDo - A.HoanhDo) + (B.TungDo - A.TungDo) * (B.TungDo - A.TungDo);
    s = sqrt(s);
    return s;
}

TamGiac ::TamGiac()
{
    a = b = c = Point(0, 0);
}

TamGiac ::TamGiac(const TamGiac &T)
{
    a.HoanhDo = T.a.HoanhDo;
    b.HoanhDo = T.b.HoanhDo;
    c.HoanhDo = T.c.HoanhDo;
    a.TungDo = T.a.TungDo;
    b.TungDo = T.b.TungDo;
    c.TungDo = T.c.TungDo;
}


TamGiac ::TamGiac(Point d, Point e, Point f)
{
    a = d;
    b = e;
    c = f;
}

TamGiac ::~TamGiac()
{
    a = b = c = Point(0, 0);
}

int TamGiac ::Kiemtra(TamGiac T)
{
    double ab = T.a.KhoangCach(T.a, T.b);
    double ac = T.a.KhoangCach(T.a, T.c);
    double bc = T.b.KhoangCach(T.b, T.c);
    if(ab + ac <= bc || bc + ac <= ab || bc + ab <= ac)
        return 0;
    else return 1;
}

TamGiac TamGiac ::Nhap(TamGiac &T)
{
    int check;
    do
    {
        T.a = T.a.Nhap();
        T.b = T.b.Nhap();
        T.c = T.c.Nhap();
        check = T.Kiemtra(T);
        if(check == 0)
        {
            cout << "diem nhap khong tao thanh tam giac, vui long nhap lai: \n";
        }
    }while(check == 0);
        return T;
}

void TamGiac ::Xuat(TamGiac T)
{
    cout << "Toa do tam giac lan luot la: \n";
    T.a.Xuat(T.a);
    T.b.Xuat(T.b);
    T.c.Xuat(T.c);
}

TamGiac TamGiac ::Tinh_tien(TamGiac &T, double d, double e)
{
    T.a = T.a.Tinh_tien(T.a, d, e);
    T.b = T.b.Tinh_tien(T.b, d, e);
    T.c = T.c.Tinh_tien(T.c, d, e);
    return T;
}

double TamGiac ::ChuVi(TamGiac &T)
{
    double ab = T.a.KhoangCach(T.a, T.b);
    double ac = T.a.KhoangCach(T.a, T.c);
    double bc = T.b.KhoangCach(T.b, T.c);
    return ab + ac + bc;
}

double TamGiac ::DienTich(TamGiac &T)
{
    double ab = T.a.KhoangCach(T.a, T.b);
    double ac = T.c.KhoangCach(T.a, T.c);
    double bc = T.b.KhoangCach(T.b, T.c);
    double P = 0.0;
    P = ab + ac + bc;
    P = P / 2;
    double s = 0.0;
    s = P * (P-ab) * (P-ac) * (P-bc);
    return sqrt(s);
}

int main()
{
    TamGiac T[100];
    int n;;
    cout << "Nhap so luong tam giac: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        T[i].Nhap(T[i]);
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        T[i].Xuat(T[i]);
    }

    double max_chuvi = T[0].ChuVi(T[0]);
    TamGiac X;
    for(int i = 0; i < n; i++)
    {
        if(T[i].ChuVi(T[i]) > max_chuvi)
        {
            max_chuvi = T[i].ChuVi(T[i]);
            X = T[i];
        }
    }
    cout << endl << max_chuvi << endl;
    X.Xuat(X);

    double max_dientich = T[0].DienTich(T[0]);
    TamGiac Y;
    for(int i = 0; i < n; i++)
    {
        if(T[i].DienTich(T[i]) > max_dientich)
        {
            max_dientich = T[i].DienTich(T[i]);
            Y = T[i];
        }
    }
    cout << endl << max_dientich << endl;
    Y.Xuat(Y);

    cout << "\nNhap toa do vecto de tinh tien: ";
    double c;
    double b;
    cin >> b >> c;
    for(int i = 0; i < n; i++)
    {
        T[i].Xuat(T[i].Tinh_tien(T[i], b, c));
    }
    return 0;
}
