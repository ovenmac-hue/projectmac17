#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber operator+(double p,const ComplexNumber &c){
	return ComplexNumber(p+c.real,c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);  
}

ComplexNumber operator-(double q,const ComplexNumber &c){
    return ComplexNumber(q - c.real, -c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(imag*c.real));
}

ComplexNumber operator*(double p,const ComplexNumber &c){
	return ComplexNumber(p*c.real,p*c.imag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/((c.real*c.real)+(c.imag*c.imag)),
							((imag*c.real)-(real*c.imag))/((c.real*c.real)+(c.imag*c.imag)));
}

ComplexNumber operator/(double p,const ComplexNumber &c){
	return ComplexNumber(
		(p * c.real) / ((c.real*c.real) + (c.imag*c.imag)),
		(-p * c.imag) / ((c.real*c.real) + (c.imag*c.imag))
	);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	return (real == c.real) && (imag == c.imag);
}

bool operator==(double p,const ComplexNumber &c){
	return (p == c.real) && (0 == c.imag);
}

ostream& operator<<(ostream& os, const ComplexNumber& c) {
    
    if (c.real == 0 && c.imag == 0)
        return os << 0;

    if (c.real == 0) {
        if (c.imag == 1)
            return os << "i";
        else if (c.imag == -1)
            return os << "-i";
        else
            return os << c.imag << "i";
    }

    if (c.imag == 0)
        return os << c.real;

    os << c.real;
    if (c.imag > 0) {
        if (c.imag == 1)
            os << "+i";
        else
            os << "+" << c.imag << "i";
    } else {
        if (c.imag == -1)
            os << "-i";
        else
            os << c.imag << "i";
    }

    return os;
}

double ComplexNumber::abs(){
	return sqrt((real*real)+(imag*imag));
}

double ComplexNumber::angle() {
    return atan2(imag, real) * 180.0 / M_PI;
}


int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";

	return 0;
}





