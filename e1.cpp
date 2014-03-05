#include<iostream>
using namespace std;

class A
{
	virtual void g()
	{
	    cout<<"A::g"<<endl;
	}
	private:
	    virtual void f()
	    {
	        cout<<"A::f"<<endl;
	    }
};
class B:public A
{
    void g()
    {
	    cout<<"B::g"<<endl;
    }
    virtual void h()
    {
        cout<<"B::h"<<endl;
    }
};
typedef void (*fun)(void);
int main()
{
	B b;
	fun pfun;
	for(int i=0;i<3;i++)
	{
		pfun=(fun)*((int*)*(int*)(&b)+i);
		pfun();
	}
	return 0;
}
