#include <iostream>
#include <string>
using namespace std;
class human
{
private:
    string Hu_name;
    int Hu_high;
    string Hu_sex;
public:
    human(string name="Mike",int high=160,string sex="man")
    {
        Hu_name=name;
        Hu_high=high;
        Hu_sex=sex;
    }
    virtual void show()
    {
        cout<<"name:"<<Hu_name<<endl
           <<"high:"<<Hu_high<<endl
          <<"sex:"<<Hu_sex<<endl;
    }
};
class worker:public human
{
private:
    int W_money;
    int W_wages;
public:
    worker(string name="Mike",int high=160,string sex="man"):human(name,high,sex)//构造函数
    {
        W_wages=3000;
        W_money=10000;
    }
    worker(string name,int high,string sex,int wages,int money):human(name,high,sex)
    {
        W_money=money;
        W_wages=wages;
    }

    worker(const worker &M)//拷贝构造函数
    {
        W_wages=M.W_wages;
    }
    void work(int month)
    {
        W_money+=W_wages*month;
    }

    virtual void show()
    {
        human::show();
        cout<<"deposit:"<<W_money<<endl;
    }
    void operator+(worker&t)//操作符重载
    {
        W_money=W_money+t.W_money;
    }

    static string boss;
};
string worker::boss="Sheldon";
void replay(human&m)
{
    m.show();
}
int main()
{
    worker m("Jane",155,"woman",5000,10000);
    replay(m);
    m.work(5);
    replay(m);
    cout<<m.boss;
    return 0;
}
