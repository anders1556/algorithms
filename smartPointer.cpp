#include <iostream>
#include <stddef.h> //size_t的定义
template <class T>
class smartPointer
{
private:
	T* m_ptr;
public:
	smartPointer(T* p):m_ptr(p){}
	T& operator* (){ return *m_ptr;}
	T* operator->(){ return m_ptr;}
	~smartPointer(){ delete m_ptr;}
};

class U_Ptr
{
	friend class HasPtr;
	int* ip;
	size_t use;

	U_Ptr(int* p):ip(p),use(1){std::cout << "U_ptr constructor called!" << std::endl;}
	~U_Ptr(){ delete ip; std::cout << "U_ptr distructor called !" << std::endl;}
};

class HasPtr
{
public:
	HasPtr(int* p,int value):ptr(new U_Ptr(p)),val(value)
	{
		std::cout << "HasPtr constructor called!" << "use = " << ptr->use << std::endl;
	}

	HasPtr(const HasPtr& old):ptr(old.ptr),val(old.val)
	{
		++ ptr->use;
		std::cout << "HasPtr copy constructor called!" << "use = " << ptr->use << std::endl;
	}

	HasPtr& operator=(const HasPtr& old);

	~HasPtr()
	{
		std::cout << "HasPtr discontructor called !" << "use = " << ptr->use << std::endl;
		if(-- ptr->use == 0)
			delete ptr;
	}

	int * getPtr()const { return ptr->ip; }
	int getVal()const {return val;}
	void setPtr( int* p)const {ptr->ip = p;}
	void setVal(const int value) {this->val = value;}
	int get_ptr_value()const { return *ptr->ip;}
	void set_ptr_value(const int value) {*this->ptr->ip = value;}

private:
	U_Ptr *ptr;
	int val;
};

HasPtr& HasPtr::operator =(const HasPtr& old)
{
	++ old.ptr->use;
	if(-- this->ptr->use == 0)
		delete ptr;
	this->ptr = old.ptr;
	this->val = old.val;
	return *this;
}

int main(void)
{
    int *pi = new int(42);
    HasPtr *hpa = new HasPtr(pi, 100);    // 构造函数
    HasPtr *hpb = new HasPtr(*hpa);     // 拷贝构造函数
    HasPtr *hpc = new HasPtr(*hpb);     // 拷贝构造函数
    HasPtr hpd = *hpa;     // 拷贝构造函数

    std::cout << hpa->get_ptr_value() << " " << hpb->get_ptr_value() << std::endl;
    hpc->set_ptr_value(10000);
    std::cout << hpa->get_ptr_value() << " " << hpb->get_ptr_value() << std::endl;
    hpd.set_ptr_value(10);
    std::cout << hpa->get_ptr_value() << " " << hpb->get_ptr_value() << std::endl;
    delete hpa;
    delete hpb;
    delete hpc;
    std::cout << hpd.get_ptr_value() << std::endl;
    return 0;
}
