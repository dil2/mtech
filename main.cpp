#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;

int flag[5];

class raid
{
	public: void raid0();
		void raid1();
		void raid3();
		void raid4();
		void raid5();
		void raid6();
};

class student
{
	char name[20],usn[11],age[5],sem[5],branch[5];
	public:
		void read();
		void write0();
		void write1();
		void disp0();
		void disp1();
		void output();
		void search();
		void modify();
};
class raid3456
{
	char n[5][5],parity[5],parityp[5],parityq[5];
	public:
		void write34();
		void write5();
		void write6();
		void disp3();
		void disp456();
};
void raid3456::write6()
{
	fstream file1,file2,file3,file4,file5,file6;
	char buffer[30];
	file1.open("num1.txt",ios::app|ios::out);
	file2.open("num2.txt",ios::app|ios::out);
	file3.open("num3.txt",ios::app|ios::out);
	file4.open("num4.txt",ios::app|ios::out);
	file5.open("num5.txt",ios::app|ios::out);
	file6.open("num6.txt",ios::app|ios::out);
	cout<<"Enter the information of the Numbers\n";
	cout<<"Enter the first number\n";
	cin>>n[0];
	cout<<"Enter the second number\n";
	cin>>n[1];
	cout<<"Enter the third number\n";
	cin>>n[2];
	cout<<"Enter the fourth number\n";
	cin>>n[3];
	int total1=0,total2=0;
	for(int i=0;i<4;i++)
		total1+=atoi(n[i]);

	total2=total1*2;
	int p=0,q=0;
	while(total1>0)
	{
		int rem=total1%10;
		parityp[p++]=rem+'0';
		total1=total1/10;
	}
	while(total2>0)
	{
		int rem=total2%10;
		parityq[q++]=rem+'0';
		total2=total2/10;
	}
	if(flag[5]==0)
	{
		for(int j=q-1;j>=0;j--)
		{
			file6<<parityq[j];
		}
		file6<<"\n";
		for(int j=p-1;j>=0;j--)
			file5<<parityp[j];
		file5<<"\n";
		flag[5]=1;
		file1<<n[0]<<"\n";
		file2<<n[1]<<"\n";
		file3<<n[2]<<"\n";
		file4<<n[3]<<"\n";

	}
	else if(flag[4]==0)
	{
		file6<<n[3]<<"\n";

                for(int j=q-1;j>=0;j--)
                {
                        file5<<parityq[j];
                }
		file5<<"\n";
		for(int j=p-1;j>=0;j--)
			file4<<parityp[j];
		file4<<"\n";
		file1<<n[0]<<"\n";
		file2<<n[1]<<"\n";
		file3<<n[2]<<"\n";
		flag[4]=1;

	}
	else if(flag[3]==0)
        {
                for(int j=q-1;j>=0;j--)
                {
                        file4<<parityq[j];
                }
                file4<<"\n";
		for(int j=p-1;j>=0;j--)
			file3<<parityp[j];
		file3<<"\n";
                flag[3]=1;
		file1<<n[0]<<"\n";
                file2<<n[1]<<"\n";
                file5<<n[2]<<"\n";
                file6<<n[3]<<"\n";


        }
        else if(flag[2]==0)
        {
                for(int j=q-1;j>=0;j--)
                {
                        file3<<parityq[j];
                }
                file3<<"\n";
		for(int j=p-1;j>=0;j--)
			file2<<parityp[j];
		file2<<"\n";
		flag[2]=1;
		file1<<n[0]<<"\n";
                file4<<n[1]<<"\n";
                file5<<n[2]<<"\n";
                file6<<n[3]<<"\n";

        }
        else if(flag[1]==0)
        {
                for(int j=q-1;j>=0;j--)
                {
                        file2<<parityq[j];
                }
                file2<<"\n";
		for(int j=p-1;j>=0;j--)
			file1<<parityp[j];
		file1<<"\n";
                flag[1]=1;
                file3<<n[0]<<"\n";
                file4<<n[1]<<"\n";
                file5<<n[2]<<"\n";
                file6<<n[3]<<"\n";

        }
        else if(flag[0]==0)
        {
                for(int j=q-1;j>=0;j--)
                {
                        file1<<parityq[j];
                }
                file1<<"\n";
		for(int j=p-1;j>=0;j--)
			file6<<parityp[j];
		file6<<"\n";
                flag[0]=1;
                file2<<n[0]<<"\n";
                file3<<n[1]<<"\n";
                file4<<n[2]<<"\n";
                file5<<n[3]<<"\n";

        }
        file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();
}
void raid3456::write5()
{
	fstream file1,file2,file3,file4,file5,file6;
	char buffer[30];
	raid3456 r;
	file1.open("num1.txt",ios::app|ios::out);
	file2.open("num2.txt",ios::app|ios::out);
	file3.open("num3.txt",ios::app|ios::out);
	file4.open("num4.txt",ios::app|ios::out);
	file5.open("num5.txt",ios::app|ios::out);
	file6.open("num6.txt",ios::app|ios::out);
	cout<<"Enter the information of the Numbers\n";
	cout<<"Enter the first number\n";
	cin>>n[0];
	cout<<"Enter the second number\n";
	cin>>n[1];
	cout<<"Enter the third number\n";
	cin>>n[2];
	cout<<"Enter the fourth number\n";
	cin>>n[3];
	cout<<"Enter the fifth number\n";
	cin>>n[4];
	int total=0;
	for(int i=0;i<5;i++)
	{
		total+=atoi(n[i]);
	}
	int m=0;
	while(total>0)
	{
		int rem=total%10;
		parity[m++]=rem+'0';
		total=total/10;
	}
	if(flag[5]==0)
	{
		flag[5]=1;
		for(int j=m-1;j>=0;j--)
		{
			file6<<parity[j];
		}
		file6<<"\n";
		file1<<n[0]<<"\n";
		file2<<n[1]<<"\n";
		file3<<n[2]<<"\n";
		file4<<n[3]<<"\n";
		file5<<n[4]<<"\n";

	}
	else if(flag[4]==0)
	{
		flag[4]=1;
                for(int j=m-1;j>=0;j--)
                {
                        file5<<parity[j];
                }
		file5<<"\n";
		file1<<n[0]<<"\n";
		file2<<n[1]<<"\n";
		file3<<n[2]<<"\n";
		file4<<n[3]<<"\n";
		file6<<n[4]<<"\n";

	}
	else if(flag[3]==0)
        {
		flag[3]=1;
                for(int j=m-1;j>=0;j--)
                {
                        file4<<parity[j];
                }
                file4<<"\n";
		file1<<n[0]<<"\n";
                file2<<n[1]<<"\n";
                file3<<n[2]<<"\n";
                file5<<n[3]<<"\n";
                file6<<n[4]<<"\n";


        }
        else if(flag[2]==0)
        {
		flag[2]=1;
                for(int j=m-1;j>=0;j--)
                {
                        file3<<parity[j];
                }
                file3<<"\n";
		file1<<n[0]<<"\n";
                file2<<n[1]<<"\n";
                file4<<n[2]<<"\n";
                file5<<n[3]<<"\n";
                file6<<n[4]<<"\n";

        }
        else if(flag[1]==0)
        {
		flag[1]=1;
                for(int j=m-1;j>=0;j--)
                {
                        file2<<parity[j];
                }
                file2<<"\n";
		file1<<n[0]<<"\n";
                file3<<n[1]<<"\n";
                file4<<n[2]<<"\n";
                file5<<n[3]<<"\n";
                file6<<n[4]<<"\n";

        }
        else if(flag[0]==0)
        {
		flag[0]=1;
                for(int j=m-1;j>=0;j--)
                {
                        file1<<parity[j];
                }
                file1<<"\n";
		file2<<n[0]<<"\n";
                file3<<n[1]<<"\n";
                file4<<n[2]<<"\n";
                file5<<n[3]<<"\n";
                file6<<n[4]<<"\n";

        }
        file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();
}
void raid3456::disp456()
{
	fstream file1,file2,file3,file4,file5,file6;
	cout<<"OUTPUT THE CONTENTS OF :-\n";
	cout<<"1. FILE 1\n2. FILE 2\n3. FILE 3\n4. FILE 4\n5. FILE 5\n6. PARITY\n7. ALL FILES\n0. STOP\n";
	int ch=1;
	cout<<"Enter your choice\n";
	cin>>ch;
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:file1.open("num1.txt",ios::in);
				cout<<"The contents of FILE 1 are :\n\n";
				cout<<"NUM 1\n";
				while(!file1.eof())
	                        {
        	                        file1.getline(n[1],5,'\n');
					if(file1.fail())
						break;
                	                cout<<n[1]<<"\n";
				}
				file1.close();
				break;
			case 2:
				file2.open("num2.txt",ios::in);
				cout<<"The contents of FILE 2 are :\n\n";
				cout<<"NUM 2\n";
				while(!file2.eof())
                                {
                                        file2.getline(n[1],5,'\n');
					if(file2.fail())
						break;
                                        cout<<n[1]<<"\n";
				}
				file2.close();
				break;
			case 3:file3.open("num3.txt",ios::in);
				cout<<"The contents of FILE 3 are :\n\n";
				cout<<"NUM 3\n";
				while(!file3.eof())
                                {
                                        file3.getline(n[1],5,'\n');
					if(file3.fail())
						break;
                                        cout<<n[1]<<"\n";
				}
				file3.close();
				break;
			case 4:file4.open("num4.txt",ios::in);
				cout<<"The contents of FILE 4 are :\n\n";
				cout<<"NUM 4\n";
				while(!file4.eof())
                                {
                                        file4.getline(n[1],5,'\n');
					if(file4.fail())
						break;
                                        cout<<n[1]<<"\n";
                                }
				file4.close();
                                break;
			case 5:file5.open("num5.txt",ios::in);
				cout<<"The contents of FILE 5 are :\n\n";
				cout<<"NUM 5\n";
				while(!file5.eof())
                                {
                                        file5.getline(n[1],5,'\n');
					if(file5.fail())
						break;
                                        cout<<n[1]<<"\n";
                                }
				file5.close();
                                break;
			case 6:file6.open("num6.txt",ios::in);
				cout<<"The contents of FILE 6 are :\n\n";
				cout<<"NUM 6\n";
				while(!file6.eof())
                                {
                                        file6.getline(n[1],5,'\n');
					if(file6.fail())
						break;
                                        cout<<n[1]<<"\n";
                                }
				file6.close();
                                break;


			case 7:	file1.open("num1.txt",ios::in);
				file2.open("num2.txt",ios::in);
        			file3.open("num3.txt",ios::in);
      				file4.open("num4.txt",ios::in);
        			file5.open("num5.txt",ios::in);
        			file6.open("num6.txt",ios::in);
				cout<<"Num1\t|\tNum2\t|\tNum3\t|\tNum4\t|\tNum5\t|\tnum6\t|\n";
				for(int k=0;k<90;k++)
					cout<<"-";
				cout<<"\n";
				while(!file1.eof())
				{
					file1.getline(n[0],5,'\n');
					if(file1.fail())
						break;
					cout<<n[0]<<"\t|\t";
					file2.getline(n[1],5,'\n');
					cout<<n[1]<<"\t|\t";
					file3.getline(n[2],5,'\n');
					cout<<n[2]<<"\t|\t";
					file4.getline(n[3],5,'\n');
					cout<<n[3]<<"\t|\t";
					file5.getline(n[4],5,'\n');
					cout<<n[4]<<"\t|\t";
					file6.getline(parity,5,'\n');
					cout<<parity<<"\t|\n";
				}
				file1.close();
				file2.close();
				file3.close();
				file4.close();
				file5.close();
				file6.close();
				break;
			default: cout<<"Invalid choice\n";
			}
			cout<<"1. FILE 1\n2. FILE 2\n3. FILE 3\n4. FILE 4\n5. FILE 5\n6. PARITY\n7. ALL FILES\n0. DONE\n";
			cout<<"Enter your choice\n";
			cin>>ch;
		}

}

void raid3456::write34()
{
	fstream file1,file2,file3,file4,file5,file6;
	char buffer[30];
	file1.open("num1.txt",ios::app|ios::out);
	file2.open("num2.txt",ios::app|ios::out);
	file3.open("num3.txt",ios::app|ios::out);
	file4.open("num4.txt",ios::app|ios::out);
	file5.open("num5.txt",ios::app|ios::out);
	file6.open("num6.txt",ios::app|ios::out);
	raid3456 r;
	cout<<"Enter the information of the Numbers\n";
	cout<<"Enter the first number\n";
	cin>>n[0];
	cout<<"Enter the second number\n";
	cin>>n[1];
	cout<<"Enter the third number\n";
	cin>>n[2];
	cout<<"Enter the fourth number\n";
	cin>>n[3];
	cout<<"Enter the fifth number\n";
	cin>>n[4];
	char ch;
	file1<<n[0]<<"\n";
	file2<<n[1]<<"\n";
	file3<<n[2]<<"\n";
	file4<<n[3]<<"\n";
	file5<<n[4]<<"\n";
	int total=0;
	for(int i=0;i<5;i++)
	{
		total+=atoi(n[i]);
	}
	int n=0;
	while(total>0)
	{
		int rem=total%10;
		parity[n++]=rem+'0';
		total=total/10;
	}
	for(int i=n-1;i>=0;i--)
	{
		file6<<parity[i];
	}
	file6<<"\n";
	file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();
}


void raid3456::disp3()
{
	fstream file1,file2,file3,file4,file5,file6;
	file1.open("num1.txt",ios::in);
	file2.open("num2.txt",ios::in);
	file3.open("num3.txt",ios::in);
	file4.open("num4.txt",ios::in);
	file5.open("num5.txt",ios::in);
	file6.open("num6.txt",ios::in);

	cout<<"Num1\t|\tNum2\t|\tNum3\t|\tNum4\t|\tNum5\t|\tNum6\t|\n";
	for(int k=0;k<90;k++)
		cout<<"-";
	cout<<"\n";
	int i=0;char ch[5];
	while(!file1.eof())
	{

		file1.getline(n[1],5,'\n');
		if(file1.fail())
			break;
		cout<<n[1]<<"\t|\t";
		file2.getline(n[1],5,'\n');
		cout<<n[1]<<"\t|\t";
		file3.getline(n[1],5,'\n');
		cout<<n[1]<<"\t|\t";
		file4.getline(n[1],5,'\n');
		cout<<n[1]<<"\t|\t";
		file5.getline(n[1],5,'\n');
		cout<<n[1]<<"\t|\t";
		file6.getline(parity,5,'\n');
		cout<<parity<<"\t|\n";
	}
	file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();

}

void student::read()
{

	cout<<"Enter the information of the student\n";
	cout<<"Enter the name of the student\n";
	cin>>name;
	cout<<"Enter the usn of the student\n";
	cin>>usn;
	cout<<"Enter the age of the student\n";
	cin>>age;
	cout<<"Enter the sem of the student\n";
	cin>>sem;
	cout<<"Enter the branch of the student\n";
	cin>>branch;

}

void student::write0()
{
	fstream file1,file2,file3,file4,file5;
	char buffer[70];
	file1.open("name.txt",ios::app|ios::out);
	file2.open("usn.txt",ios::app|ios::out);
	file3.open("branch.txt",ios::app|ios::out);
	file4.open("sem.txt",ios::app|ios::out);
	file5.open("age.txt",ios::app|ios::out);
	read();
	file1<<name<<"\n";
	file2<<usn<<"\n";
	file3<<branch<<"\n";
	file4<<sem<<"\n";
	file5<<age<<"\n";
	file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
}
void student::search()
{
	fstream file1,file2,file3,file4,file5;
	int count=0,find=0;char u[20];
	cout<<"Enter the usn of the record to be searched\n";
	cin>>u;
	file1.open("name.txt",ios::in);
	file2.open("usn.txt",ios::in);
	file3.open("branch.txt",ios::in);
	file4.open("sem.txt",ios::in);
	file5.open("age.txt",ios::in);
	while(!file2.eof())
	{
		file2.getline(usn,11,'\n');
		if(strcmp(u,usn)!=0)
		{
			count++;
			continue;
		}
		else
		{
			for(int i=0;i<=count;i++)
			{
				file1.getline(name,20,'\n');
				file3.getline(branch,5,'\n');
				file4.getline(sem,5,'\n');
				file5.getline(age,5,'\n');

			}
			find=1;
			 cout<<"Name= "<<name<<"\tUSN= "<<usn<<"\tBranch= "<<branch<<"\tSEM= "<<sem<<"\tAGE= "<<age<<"\n";

			break;
		}
	}
	if(!find)
		cout<<"Respective record can not be found\n";
	file1.close();
	file2.close();

}

void student::disp0()
{
	fstream file1,file2,file3,file4,file5;
	file1.open("name.txt",ios::in);
	file2.open("usn.txt",ios::in);
	file3.open("branch.txt",ios::in);
	file4.open("sem.txt",ios::in);
	file5.open("age.txt",ios::in);


	cout<<"NAME\t|\tUSN\t|\tSEM\t|\tBRANCH\t|\tAGE\t|\n";
	for(int k=0;k<73;k++)
		cout<<"-";
	cout<<"\n";
	while(!file1.eof())
	{
		file1.getline(name,20,'\n');
		if(file1.fail())
			break;
		file2.getline(usn,20,'\n');
		file5.getline(age,5,'\n');
		file4.getline(sem,5,'\n');
		file3.getline(branch,20,'\n');


		cout<<name<<"\t|\t"<<usn<<"\t|\t"<<sem<<"\t|\t"<<branch<<"\t|\t"<<age<<"\t|\n";
	}
	file1.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();

}



void student::write1()
{
	fstream file1,file2;
	char buffer[70];
	file1.open("student.txt",ios::app|ios::out);
	file2.open("mirror_student.txt",ios::app|ios::out);
	read();
	strcpy(buffer,name);	strcat(buffer,"|");
	strcat(buffer,usn);	strcat(buffer,"|");
	strcat(buffer,branch);	strcat(buffer,"|");
	strcat(buffer,sem);	strcat(buffer,"|");
	strcat(buffer,age);

	file1<<buffer<<"\n";
	file2<<buffer<<"\n";
	file1.close();
	file2.close();
}

void student::disp1()
{
	fstream file1;
	file1.open("student.txt",ios::in);
	cout<<"NAME\t|\tUSN\t|\tSEM\t|\tBRANCH\t|\tAGE\t|\n";
	for(int k=0;k<73;k++)
		cout<<"-";
	cout<<"\n";
	while(!file1.eof())
	{
		file1.getline(name,20,'|');
		if(file1.fail())
			break;
		file1.getline(usn,11,'|');
		file1.getline(branch,5,'|');
		file1.getline(sem,5,'|');
		file1.getline(age,5,'\n');

		cout<<name<<"\t|\t"<<usn<<"\t|\t"<<sem<<"\t|\t"<<branch<<"\t|\t"<<age<<"\t|\n";
	}
	file1.close();

}
void student::modify()
{
	fstream file1,file2;
	int i=0,find=0;char s[10][70],u[11];
	cout<<"Enter the usn of the record to be modified\n";
	cin>>u;
	file1.open("student.txt",ios::in);
	while(!file1.eof())
	{
		file1.getline(name,20,'|');
		if(file1.fail())
			break;
		file1.getline(usn,11,'|');
		file1.getline(branch,5,'|');
                file1.getline(sem,5,'|');
                file1.getline(age,5,'\n');
		if(strcmp(u,usn)==0)
		{
			int ch=1;
			int ch2=0;
			cout<<"Old values\n";
			cout<<"Name= "<<name<<"\tUSN= "<<usn<<"\tBranch= "<<branch<<"\tSEM= "<<sem<<"\tAGE= "<<age<<"\n";
			cout<<"\n1. More than one FIELD\n2. One FIELD only\n";
		cin>>ch2;
		while(ch!=0)
			{
				cout<<"0. Done Modification\n1. Name\n2. Branch\n3. Semester\n4. Age\n";
				cin>>ch;

				switch(ch)
				{
					case 0:
						cout<<"Thank You\nModification has been Done\n";
						break;
					case 1:
						cout<<"Enter the name\n";
						cin>>name;
						break;
					case 2:
						cout<<"Enter the branch\n";
						cin>>branch;
						break;
					case 3:
						cout<<"Enter the Semester\n";
						cin>>sem;
						break;
					case 4:
						cout<<"Enter the age\n";
						cin>>age;
						break;
					default: cout<<"Invalid Choice\n";
				}
				if(ch2==2)
					ch=0;
			}

			 find=1;

		}
		 strcpy(s[i],name);      strcat(s[i],"|");
                 strcat(s[i],usn);       strcat(s[i],"|");
                 strcat(s[i],branch);    strcat(s[i],"|");
                 strcat(s[i],sem);       strcat(s[i],"|");
                 strcat(s[i],age);
		 i++;
		}

	file1.close();
	if(find==1)
	{
		file1.open("student.txt",ios::trunc|ios::out);
		file2.open("mirror_student.txt",ios::trunc|ios::out);
		for(int j=0;j<i;j++)
		{
			file1<<s[j]<<"\n";
			file2<<s[j]<<"\n";
		}
		file1.close();
		file2.close();
	}
	if(!find)
		cout<<"Respective record can not be found\n";

}
void raid::raid0()
{
	student s0;
	int ch;
	while(1)
	{
		cout<<"1. Write Record\n2. Display\n3. Search\n4. Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: s0.write0();
				break;
			case 2: s0.disp0();
				break;
			case 3: s0.search();
				break;
			case 4: return;
			default: cout<<"Invalid choice\n";
				break;
		}
	}
}







void raid::raid1()
{
	student s1;
	int ch;
	while(1)
	{
		cout<<"1. Write Record\n2. Display\n3. Modify\n4. Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: s1.write1();
				break;
			case 2: s1.disp1();
				break;
			case 3: s1.modify();
				break;
			case 4: return;
			default: cout<<"Invalid choice\n";
				break;
		}
	}
}

void raid::raid3()
{
	raid3456 r3;
	int ch;
	while(1)
	{
		cout<<"1. Write Record\n2. Display\n3. Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: r3.write34();
				break;
			case 2: r3.disp3();
				break;
			case 3: return;
			default: cout<<"Invalid choice\n";
				break;
		}
	}
}

void raid::raid4()
{
	raid3456 r4;
	int ch;
	while(1)
	{
		cout<<"1. Write Record\n2. Display\n3. Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: r4.write34();
				break;
			case 2: r4.disp456();
				break;
			case 3: return;
			default: cout<<"Invalid choice\n";
				break;
		}
	}
}

void raid::raid5()
{
	raid3456 r5;
	int ch;
	while(1)
	{
		cout<<"1. Write Record\n2. Display\n3. Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: r5.write5();
				break;
			case 2: r5.disp456();
				break;
			case 3: return;
			default: cout<<"Invalid choice\n";
				break;
		}
	}
}
void raid::raid6()
{
	raid3456 r6;
	int ch;
	for(int i=0;i<=5;i++)
	{
		flag[i]=0;
	}
	while(1)
	{
		cout<<"1. Write Record\n2. Display\n3. Exit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: r6.write6();
				break;
			case 2: r6.disp456();
				break;
			case 3: return;
			default: cout<<"Invalid choice\n";
				break;
		}
	}
}


int main()
{
	raid r;
	int ch;
	for(int i=0;i<6;i++)
		flag[i]=0;
	while(1)
	{
		cout<<"1. RAID 0\n2. RAID 1\n3. RAID 3\n4. RAID 4\n5. RAID 5\n6. RAID 6\n7. EXIT\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:r.raid0();
				break;
			case 2:r.raid1();
				break;
			case 3:
				r.raid3();
				break;
			case 4: r.raid4();
				break;
			case 5:r.raid5();
				break;
			case 6:r.raid6();
				break;
			case 7: exit(0);
			default: cout<<"Inavlid Choice\n";
					break;
		}
	}
	return 0;
}
