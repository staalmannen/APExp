struct B { virtual int f(); virtual ~B(); };
struct D : B { int f(); };
int B::f() { return 1; }  B::~B() {}  int D::f() { return 2; }
template<class T> T twice(T x) { return x + x; }
int main() { D d; B *p = &d; return p->f() + twice(3); }

