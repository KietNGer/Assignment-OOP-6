#include<iostream>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

class Point
{
public:
    double HoanhDo;
    double TungDo;
public:
    Point();
    Point(double a, double b);
    ~Point();
    void Nhap();
    Point Tinh_tien(Point &P, int a, int b);
    int Lay_hoang_do();
    int Lay_tung_do();
    void Xuat(Point a);
    float KhoangCach(Point A, Point B);
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

void Point ::Nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> HoanhDo;
    cout << "Nhap tung do: ";
    cin >> TungDo;
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

Point Point ::Tinh_tien(Point &P, int a, int b)
{
    P.HoanhDo += a;
    P.TungDo += b;
    return P;
}

float Point ::KhoangCach(Point A, Point B)
{
    float s = 0;
    s = (B.HoanhDo - A.HoanhDo) * (B.HoanhDo - A.HoanhDo) + (B.TungDo - A.TungDo) * (B.TungDo - A.TungDo);
    s = sqrt(s);
    return s;
}

int main()
{
    int n;
    cin >> n;
    Point a[n];
    for(int i = 0; i < n; i++)
    {
        a[i].Nhap();
    }

    cout << "Cac diem vua nhap: \n";
    for(int i = 0; i < n; i++)
    {
        a[i].Xuat(a[i]);
    }

    float max = a[0].KhoangCach(a[0], a[1]);
    float min = a[0].KhoangCach(a[0], a[1]);

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(max < a[i].KhoangCach(a[i], a[j]))
                max = a[i].KhoangCach(a[i], a[j]);
        }
    }
    cout << "Khoang cach xa nhat cua hai diem: " << max;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(min > a[i].KhoangCach(a[i], a[j]))
                min = a[i].KhoangCach(a[i], a[j]);
        }
    }
    cout << "\nKhoang cach gan nhat cua hai diem: " << min;

    cout << "\nNhap toa do vecto de tinh tien: ";
    float c;
    float b;
    cin >> b >> c;
    for(int i = 0; i < n; i++)
    {
        a[i].Xuat(a[i].Tinh_tien(a[i], b, c));
    }
    return 0;
}
