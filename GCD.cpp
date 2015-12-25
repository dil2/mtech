#include <iostream>
#include <iomanip>
using namespace std;

void gcd(int, int);
void extended_gcd(int, int, int, int);

int main()
{
int m=0, n=0;

cout<<"Welcome to the Greatest Common Divisor Program\n\n";
cout<<"Enter the first number: ";
cin>>m;
cout<<endl;
cout<<"Enter the second number: ";
cin>>n;
cout<<endl;
cout<<"gcd("<<m<<", "<<n<<") = ";
gcd(m, n);
return 0;
}

void gcd(int m, int n)
{
int r, q, d;
while (n!=0)
{
r = m % n;
q = m / n;
r = m - n * q; // I was thinking on put it on the stack
//but I dont know how
m = n;
n = r;
}

d = m;
cout<<d<<endl;
//then pop the stack as d=r-q*n
}
