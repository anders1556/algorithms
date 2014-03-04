//define
class Singleton
{
publci:
	static Singleton* Instance();
protected:
	Singleton();
private:
	static Singleton* _instance;
}

//implement
Singleton *Singleton:: _instance = 0;

Singleton * Singleton::Instance()
{
	if(_instance == 0)
		_instance = new Singleton();
	
	return _instance;
}
