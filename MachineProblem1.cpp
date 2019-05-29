// classroom management software
// electronic class record

#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()

{
	string sName[50]; 
	// student name
	double aveInd[50], aveGrp[50], FG[50], Grade; 
	// average individual report, average group report, final grade, transmuted grade
	int Q1[50], Q2[50], PE[50], FE[50], I[50][10], G[50][10], pPrac[50], fPrac[50], sInd=0, sGrp=0, i, j;
	// quiz 1, quiz 2, practical exam, final exam, individual report, group report, preliminary practical, final practical
	// sum of individual report, sum of group report, counter i, counter j
	
	cout << "Enter 50 student names: \n";
	// includes all 50 students in the class
	
	for (i=0; i<50; i++)
	{
	
	getline(cin,sName[i]); // getline reads in a single line of text from standard input and puts it into s as a C-style string
	cin.ignore(); // ignore function is used to skip (discard/throw away) characters in the input stream
}
	cout << "Enter their quiz scores (2): \n"; // includes the 2 quizzes 
	for (i=0; i<50; i++)
		cin >> Q1[i] >> Q2[i];
		
	cout << "Enter their major exam scores (2): \n"; // includes the preliminary and final written examinations
	for (i=0; i<50; i++)
		cin	>> PE[i] >> FE[i];
				
	cout << "Enter their practical exam scores (2): \n"; // includes the preliminary and final practical examinations
	for (i=0; i<50; i++)
		cin >> pPrac[i] >> fPrac[i];
		
	cout<< "Enter their individual report scores (10): \n"; // includes the 10 individual reports
		for (i=0; i<50; i++)
		{
				for (j=0; j<10; j++)
		   {
			cin >> I[i][j];
			sInd += I[i][j]; // total of individual report scores
		   }
		   aveInd[i] = sInd/10.0; // average of individual report scores
	    }
		
	cout << "Enter their group report scores (10): \n"; // includes the 10 group reports
		for (i=0; i<50; i++)
		{
				for (j=0; j<10; j++)
			{
			cin>> G[i][j];
			sGrp += G[i][j]; // total of group report scores
			}
			aveGrp[i] = sGrp/10.0; // average of group report scores
		} 
	
	// final grade transmutation
	for (i=0; i<50; i++)
	{
		FG[i] = (aveInd[i]*0.15)+(aveGrp[i]*0.25)+(((Q1[i]+Q2[i])/2.0)*0.2)+((PE[i]*0.3+pPrac[i]*0.7)*0.2)+(( FE[i]*0.3+fPrac[i]*0.7)*0.2);
		// final grade consists of 15% individual reports, 25% group report, 20% quizzes, and 40% major examinations
		// total equivalent percentage is 100%
		
		if (FG[i] >= 95.57 && FG[i] <= 100)
			Grade=1.00;
		else if (FG[i] >= 91.12 && FG[i] <= 95.56)
			Grade=1.25;
		else if (FG[i] >= 86.68 && FG[i] <= 91.11)
			Grade=1.50;
		else if (FG[i] >= 82.23 && FG[i] <= 86.67)
			Grade=1.75;
		else if (FG[i] >= 77.79 && FG[i] <= 82.22)
			Grade=2.00;
		else if (FG[i] >= 73.34 && FG[i] <= 77.78)
			Grade=2.25;
		else if (FG[i] >= 68.90 && FG[i] <= 73.33)
			Grade=2.50;
		else if (FG[i] >= 64.45 && FG[i] <= 68.89)
			Grade=2.75;
		else if (FG[i] >= 60.00 && FG[i] <= 64.44)
			Grade=3.00;
		else
			Grade=5.00;
		
		// students who get a grade higher than 60.00 will pass, otherwise will fail
		if (FG[i] < 60.00) 
	    	cout << "You Failed! \n";
	     cout << "Student " << i << "'s grade is "<< FG[i] <<" and its eqivalent is " << Grade << endl << endl;
    }  
	
	// sorting 
	bool sorted = false; 
	// bools have a default of false in a class or struct
	// with bools, the default Sort method will put false before true
		while(!sorted)
		{
			sorted = true;
			for(int i=0; i<50; i++)
			{
				if(FG[i] < FG[i+1])
				{
					int tmp = FG[i]; // final grade
					string tmp2 = sName[i]; // student name
					// sorting of final grade component
					FG[i] = FG[i+1];
					FG[i+1] = tmp;
					// sorting of student name component
					sName[i] = sName[i+1];
					sName[i+1] = tmp2;
			sorted = false;
				}
			}
		}	
	
	// ranking of the top performing students in class
	cout << "Top 10 Performing Students:\n\n";
		for (i=0; i<=10; i++) // only chooses the top 10 students in class
	cout << "\t" << i+1 << ". " << sName[i] << endl;
	
	_getch();
	return 0;
}

