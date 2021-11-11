#include<cstring>
#include<iostream>
using namespace std;        

class Date
{
    private:
        int day, month, year;
    public:
        Date(int day=0, int month=0, int year=0);
        Date(const Date &);
        ~Date();
        void Show();
};
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
};
Date::Date(const Date &d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
};
Date::~Date()
{
};
void Date::Show()
{
    cout <<"Ngay/Thang/Nam: "<<this->day << "/" << this->month << "/" << this->year << endl;
};


// Phong khach san
class PhongKS
{
    private:
        string maPhong;
        int soNguoi;
        bool tinhTrang;
        Date ngayNhan;
        Date ngayTra;
        double gia;
        friend class List;
    public:
        PhongKS(string = "" ,int = 0, bool = true, int =0,int =0,int =0,int =0,int =0,int =0 , double = 100.0);
        
        PhongKS(const PhongKS &);
        ~PhongKS();
        void Show();
};
PhongKS::PhongKS(string maPhong, int soNguoi, bool tinhTrang,int day1,int month1, int year1 ,int day2,int month2,int year2, double gia): ngayNhan(day1,month1,year1),ngayTra(day2,month2,year2)
{
    this->maPhong = maPhong;
    this->soNguoi = soNguoi;
    this->tinhTrang = tinhTrang;
    this->gia = gia;
};
PhongKS::PhongKS(const PhongKS &room)
{
    this->maPhong = room.maPhong;
    this->soNguoi = room.soNguoi;
    this->tinhTrang = room.tinhTrang;
    this->ngayNhan = room.ngayNhan;
    this->ngayTra = room.ngayTra;
    this->gia = room.gia;
};
PhongKS::~PhongKS()
{
    
};
void PhongKS::Show()
{
    cout <<"Phong: "<< this->maPhong << " | " << this->soNguoi << " | " << this->tinhTrang << " | ";
    ngayNhan.Show(); cout<<"|"; ngayTra.Show(); cout<<"|"<< this->gia;//<< this->ngayNhan << " | " << this->ngayTra << " | " << this->gia << endl;
};



// List
class List 
{
    private:
        PhongKS *p;
        int n;
    public:
        List();
        List(const List &);
        ~List();
        void Show();
        void AddTop(PhongKS&);
        void AddEnd(PhongKS&);
        void AddBatKy(PhongKS&, int);
        void DeleteTop();
        void DeleteEnd();
        void DeleteBatKy(int);
        void Update(string);
        void BubbleSort(PhongKS *);
        void Search(int );
        void LinearSearch(double);
};

List::List()
{
    this->n=0;
    this->p=nullptr;
}
List::List(const List &x){
    this->n=x.n;
    p=new PhongKS[this->n];
    for(int i=0;i<this->n;i++){
        *(this->p+i)=*(x.p+i);
    }
}
List::~List() 
{
    delete[] this->p;
}
void List::Update(string x)
{
     double q;
     for(int i=0;i<this->n;i++)
     {
        if(p[i].maPhong == x)
        {
            cout << "Gia phong hien tai: " << p[i].gia << ", hay nhap gia tri moi: " << endl;
            cin>> q; p[i].gia = q;
        }
     }
     
}

void List::LinearSearch(double s)
{
    for(int i=0; i<this->n; i++)
    {
        if(p[i].gia == s )
        {
            cout<<"Tim thay"<<endl;
        }
        else
        {
            cout<<"Khong tim thay"<<endl;
        }
    }
}

 
void List::Show(){
    for(int i=0; i<this->n; i++){
        (this->p + i) ->Show();
    }
}
void List::AddTop(PhongKS &q){
    this->n=this->n+1;
    PhongKS *k;
    k=new PhongKS[n];
    k[0]=q;
    for(int i=1;i<this->n;i++){
        *(k + i)=*(this->p + i);
    }
    delete [] p;
    this->p=new PhongKS[n];
    for(int i=0;i<this->n;i++){
        *(this->p + i) = *(k + i);
    }
    delete [] k;
}
void List::AddEnd(PhongKS &q){
    this->n=this->n+1;
    PhongKS *k;
    k=new PhongKS[this->n];
    k[this->n-1]=q;
    for(int i=0;i<this->n-1;i++){
        *(k + i)=*(this->p + i);
    }
    delete [] p;
    this->p=new PhongKS[this->n];
    for(int i=0;i<this->n;i++){
        *(this->p + i) = *(k + i);
    }
    delete [] k;
}
void List::AddBatKy(PhongKS &q, int index){
    this->n=this->n+1;
    PhongKS *k;
    k=new PhongKS[this->n];
    k[this->n-1]=q;
    for(int i=0;i<this->n;i++){
        if(i<index)
        {
            k[i]=p[i];
        }
        if(i==index)
        {
            k[i]=q;
        }
        else
        {
            k[i]=p[i-1];
        }
        
    }
    delete[] p;
    p=new PhongKS[this->n];
    for(int i=0;i<this->n;i++)
    {
        *(this->p + i)=*(k+1);
    }
    delete[] k;
}
void List::DeleteTop(){
    PhongKS *k;
    k=new PhongKS[this->n-1];
    for(int i=1;i<this->n;i++){
        k[i-1]=p[i];
    }
    delete [] p;
    this->n=this->n-1;
    this->p=new PhongKS[this->n];
    for(int i=0;i<this->n;i++){
        *(this->p + i) = *(k + i);
    }
    delete [] k;
}
void List::DeleteEnd(){
    PhongKS *k;
    k=new PhongKS[this->n-1];
    for(int i=0;i<this->n-1;i++){
        *(k + i)=*(this->p + i);
    }
    delete [] p;
    this->n=this->n-1;
    this->p=new PhongKS[this->n];
    for(int i=0;i<this->n;i++){
        *(this->p + i) = *(k + i);
    }
    delete [] k;
}
void List::DeleteBatKy(int index){
    PhongKS *k;
    k=new PhongKS[this->n];
    for(int i=0;i<this->n;i++){
        if(i<index)
        {
            k[i]=p[i];
        }
        if(i==index)
        {
            this->n = this->n-1;
        }
        else
        {
            k[i-1]=p[i];
        }
    }
    delete [] p;
    this->p=new PhongKS[this->n];
    for(int i=0;i<this->n;i++){
        *(this->p + i) = *(k + i);
    }
    delete [] k;
}
void swap(PhongKS &a, PhongKS &b)
{
    PhongKS temp = a;
    a = b;
    b = temp;
}
void List::BubbleSort(PhongKS *p)
{
    for (int i = 0; i < this->n - 1; ++i)
        for (int j = 0; j < this->n - i - 1; ++j)
            if (p[j].gia < p[j + 1].gia )
                swap(p[j], p[j + 1]);
}

int main()
{
    List l;
    PhongKS p("12345" ,4,true, 01,01,2002,01,11,2002, 100.0);
    l.AddTop(p);
    l.Show();
    l.Update("12345");
    l.Show();
    return 0;
}