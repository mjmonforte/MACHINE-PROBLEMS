#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cmath>
#include<math.h>
#define PI 3.14159265
using namespace std;

int main()
{
    double a, b, c, s, A, B, C, AngleA, AngleB, AngleC, heron, area, perimeter, apothem, h, n, m, i;
    float A1=0, A2=0, B1, B2, C1, C2=0, BA1, BA2, BC1, BC2, slope1, slope2, perp1, perp2, x, y;
    bool userquit = false;
    char contin;

	do
	{//Storing of values to be used.
    cout << "Enter the measurements of the triangle" << endl;
    cout << "Side A: "; cin >> a;
    cout << "Side B: "; cin >> b;
    cout << "Side C: "; cin >> c;
        
    //Cosine law for interior angles
    A = (((b*b) + (c*c) - (a*a)) / (2*b*c));
    B = (((c*c) + (a*a) - (b*b)) / (2*c*a));
    C = (((a*a) + (b*b) - (c*c)) / (2*a*b));
    AngleA = acos(A)*(180/M_PI);
    AngleB = acos(B)*(180/M_PI);
    AngleC = acos(C)*(180/M_PI);
        
    cout << "\nINTERIOR ANGLES: " << endl;
    cout << abs(AngleA) << " degrees" << endl;
    cout << abs(AngleB) << " degrees" << endl;
    cout << abs(AngleC) << " degrees\n" << endl;
    
    // If else condition to determine what type of traingle.
        // If all sides are equal:
    if(a==b && b==c){
        cout << "TYPE OF TRIANGLE: Equilateral Triangle.\n";}
        // If two sides are equal:
    else if(a==b && b!=c){
        cout << "TYPE OF TRIANGLE: Isosceles Triangle.\n";}
    else if(b==c && c!=a){
        cout << "TYPE OF TRIANGLE: Isosceles Triangle.\n";}
    else if(c==a && a!=b){
        cout << "TYPE OF TRIANGLE: Isosceles Triangle.\n";}
        // If no sides are equal:
    else{
        cout << "TYPE OF TRIANGLE: Scalene Triangle.\n\n";}
    
    // Calculating area using Heron's formula.
    s = (a + b + c) / 2;
    heron = s * (s-a) * (s-b) * (s-c);
    area = sqrt(heron);
    // Adding of three sides for perimeter calculation.
    perimeter = a + b + c;
    
    cout << "AREA OF THE TRIANGLE: " << area << " m^2.\n" << endl;
    cout << "PERIMETER OF THE TRIANGLE: " << perimeter << " meters.\n" << endl;
    
    // Classification whether acute, right, obtuse.
    if(AngleA<90 && AngleB<90 && AngleC<90){
        cout << "CLASSIFICATION OF TRIANGLE: Acute Triangle.\n\n";}
    else if(AngleA>90 || AngleB>90 || AngleC>90){
        cout << "CLASSIFICATION OF TRIANGLE: Obtuse Triangle.\n\n";}
    else if(AngleA==90 || AngleB==90 || AngleC==90){
        cout << "CLASSIFICATION OF TRIANGLE: Right Triangle.\n\n";}
    
    // Calculation for Apothem:
    if(a == b && a == c){
    	apothem = (2 * area) / perimeter;
    	cout << "LENGTH OF APOTHEM: " << apothem << endl << endl;}
	else{
		cout << "LENGTH OF APOTHEM: NO APOTHEM" << endl << endl;}
    // Formation of coordinates using derived mathematical equations.
    	C1 = a;
    	m = cos(AngleB * PI / 180);
    	n = c * m;
		B1 = n;
		i = sin(AngleC * PI / 180);
		h = b * i;
		B2 = h;
    cout << "=====The x and y coordinates of the Triangle=====" << endl;
    cout << "(0,0)" << endl; // 1st vertex assigned to origin.
    cout << "(" << a << ",0)" << endl; // 2nd vertex using value of a placed on x axis.
    cout << "(" << B1 << "," << B2 << ")" << endl;
        
    // Calculation of circumcenter coordinates:
		BA1 = (B1 + A1)/2; // midpoint and slope formulas.
		BA2 = (B2 + A2)/2;
		slope1 = (B2 - A2)/(B1 - A1);
		perp1 = - 1 / slope1; // perpendicular bisector.
		BC1 = (B1 + C1)/2;
		BC2 = (B2 + C2)/2;
		slope2 = (B2 - C2)/(B1 - C1);
		perp2 = - 1 / slope2; // perpendicular bisector.
		x = ((BC1 * perp2) - (BA1 * perp1)) / (perp2 - perp1);
		y = BC2 + (perp2 * (x - BC1));
		
		cout << "\nCOORDINATES OF THE CIRCUMCENTER: (" << x << "," << y << ")";
		cout << "\n\nDo you want to continue? (Y/N): "; cin >> contin;
		cout << endl ;
    // If the user wish to continue or not:
		switch(contin){
        case 'y':
		case 'Y':{userquit = false;}
			break;
		case 'n':
		case 'N':{userquit = true;}
			break;
		default: {userquit = true;}}
	}while(!userquit);
    
	getch();
    return 0;
}
