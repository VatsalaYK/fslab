//============================================================================
// Name        : b3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
class Student{
	string USN,name,branch;
		int sem;
public:
		string buffer;
	void readstudentfromconsole()
	{
		cin.clear();
		cin.ignore(255,'\n');
		cout<<"Enter the name: "<<endl;
		getline(cin,name);
		//cin.clear();
		//cin.ignore(255,'\n');
		cout<<"Enter the USN: "<<endl;
		cin>>USN;
		cin.clear();
		cout<<"Enter the branch: "<<endl;
		cin>>branch;
		cout<<"Enter the sem: "<<endl;
		cin>>sem;
	}
	void showstudent()
	{
		cout<<"USN: "<<USN<<endl<<"Name: "<<name<<endl<<"Branch: "<<branch<<endl<<"Sem: "<<sem<<endl;
	}
	void pack()
	{
		int j;
		string temp,sem1;
		stringstream out;
		out<<sem;
		sem1=out.str();
		temp.erase();
		temp=USN+'|'+name+'|'+branch+'|'+sem1;
		for(j=temp.size();j<100;j++)
		{
			temp=temp+'$';
		}
		buffer+=temp;
		cout<<buffer<<endl;
	}
	void write()
	{
		fstream f1;
		f1.open("data1.txt",ios::out|ios::app);
		f1<<buffer;
		f1.close();
	}
};

int main() {
	Student s;
	int choice;
	while(1)
		{
		cout<<"1.INSERT"<<endl<<"2.SEARCH"<<endl<<"3.DELETE"<<endl<<"4.MODIFY"<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		switch(choice)
			{
			case 1: s.readstudentfromconsole();
					s.showstudent();
					s.pack();
					s.write();
					break;
			default : return 0;
			}
		}
		return 0;
}
