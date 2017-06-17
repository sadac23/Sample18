#include <memory>

struct Day {
	explicit Day(int d)
		//	Day(int d)
		:val(d) {}
	int val;
};

/*
struct Month {
explicit Month(int m)
//	Month(int m)
:val(m)	{}
int val;
};
*/

class Month {
public:
	//	explicit Month (int m):val(m) {};
	static Month Jan() { return Month(1); }
	static Month Feb() { return Month(2); }
	int val;
private:
	explicit Month(int m) :val(m) {};
};

struct Year {
	explicit Year(int y)
		//	Year(int y)
		:val(y) {}
	int val;
};

class Date {
public:
	Date(const Month& m, const	Day& d, const Year& y) {};
};

class Investment {
public:
	Investment();
	~Investment();
	static Investment* CreateInvestment();
	//static std::tr1::shared_ptr<Investment> CreateInvestment();
	static void GetRidOfInvestment(Investment* p);		//カスタムデリータ用
};

//スマートポインタデバッグ用
void f();
