#include<iostream>
#include<fstream>

#include<string>
#include<iomanip>
using namespace std;
class student
{
string student_name;
int admission_num;
int classs;
int books_issued;
public:
void addstudent()
{
ofstream outf("students.txt", ios::app);

if (!outf.is_open()) {
cerr << "Error opening students file.\n";
return;
}
cout<<"enter students details"<<endl;
cout<<"name:";
cin>>student_name;
cout<<"admission number:";
cin>>admission_num;
cout<<"class:";
cin>>classs;

cout<<" number of books issued:";
cin>>books_issued;
outf<< student_name << "|" << admission_num << "|" << classs << "|" << books_issued << endl;

cout << "Student Record added successfully.\n";

outf.close();
}
void modifystudent()
{

ifstream inFile("students.txt");
ofstream outFile("temp.txt");

if (!inFile.is_open() || !outFile.is_open()) {
cerr << "Error opening files.\n";
return;
}

cout << "Enter Admission Number of the student to modify: ";
int admissionNumber;
cin >> admissionNumber;
bool found = false;
string name;
string className;

string numBooksIssued;

while (inFile >> student_name >> admission_num >> classs >> books_issued) {
if (admissionNumber == admission_num) {
found = true;

cout << "Enter new Student Name: ";
getline(cin,name);
cout << "Enter new Class: ";
getline(cin , className);
cout << "Enter new Number of Books Issued: ";
getline(cin , numBooksIssued);

outFile << name << "|" << admissionNumber << "|" << className << "|" << numBooksIssued <<
endl;

cout << "Student Record modified successfully.\n";
}
else {
outFile << name << "|" << admissionNumber << "|" << className << "|" << numBooksIssued <<
endl;
}
}

if (!found) {
cout << "Student with Admission Number " << admissionNumber << " not found.\n";

}

inFile.close();
outFile.close();

// Remove the old file and rename the new file
remove("students.txt");
rename("temp.txt", "students.txt");

}
void deletestudent()
{
ifstream inFile("students.txt");
ofstream outFile("temp.txt");

if (!inFile.is_open() || !outFile.is_open()) {
cerr << "Error opening files.\n";
return;
}

int admissionNumber;
cout << "Enter Admission Number of the student to delete: ";
cin >> admissionNumber;

bool found = false;

while (inFile >>student_name>> admission_num >> classs >> books_issued) {
if (admissionNumber == admission_num) {
found = true;
cout << "Student Record deleted successfully.\n";
} else {
outFile <<student_name << "|" << admission_num << "|" << classs << "|" << books_issued <<
endl;
}
}

if (!found) {
cout << "Student with Admission Number " << admissionNumber << " not found.\n";
}

inFile.close();
outFile.close();

// Remove the old file and rename the new file
remove("students.txt");
rename("temp.txt", "students.txt");
}

void viewstudent()
{
ifstream inFile("students.txt");

if (!inFile.is_open()) {
cerr << "Error opening students file.\n";
return;
}
while(inFile>>student_name>> admission_num >> classs >> books_issued)
{
cout << student_name<< admission_num << classs<< books_issued<<endl;
}
}
};
class book
{
int book_num;
string author;
string title;
string domain;
int edition;
int copiesavailable;
public:
void addbook()
{
ofstream outf("books.txt", ios::app);

if (!outf.is_open()) {

cerr << "Error opening books file.\n";
return;
}
cout<<"enter books details"<<endl;
cout<<"book number:";
cin>>book_num;
cout<<"author:";
cin>>author;
cout<<"title:";
cin>>title;
cout<<" domain:";
cin>>domain;
cout<<"edition:";
cin>>edition;
cout<<" number of copies available:";
cin>>copiesavailable;

outf<< book_num << "|" << author << "|" << title << "|" << domain <<
"|"<<edition<<"|"<<copiesavailable<<endl;

cout << "book Record added successfully.\n";

outf.close();
}
void modifybook()
{

ifstream inFile("books.txt");
ofstream outFile("tempt.txt");

if (!inFile.is_open() || !outFile.is_open()) {
cerr << "Error opening files.\n";
return;
}

cout << "Enter Number of the book to modify: ";
int bookNumber;
cin >> bookNumber;
bool found = false;
string _author;
string _title;
string _domain;
int _edition;
int _copies;

while (inFile>>book_num>>author >>title >>domain>>edition>>copiesavailable ) {
if (bookNumber == book_num) {
found = true;

cout << "Enter new book Name: ";
cin>>bookNumber;

cout << "Enter title: ";
getline(cin,_title);
cout << "Enter author: ";
getline(cin , _author);
cout << "Enter Number of copies available: ";
cin >>_copies;
cout << "Enter edition: ";
cin>> _edition;
cout << "Enter domain: ";
getline(cin , _domain);

outFile<<
bookNumber<<"|"<<_author<<"|"<<_title<<"|"<<_domain<<"|"<<_edition<<"|"<<_copies<<
"|"<<endl;

cout << "book Record modified successfully.\n";
}
else {
outFile<<
book_num<<"|"<<author<<"|"<<title<<"|"<<domain<<"|"<<edition<<"|"<<copiesavailable<<
"|"<<endl;
}
}

if (!found)

{
cout << "book with Number " << bookNumber << " not found.\n";
}

inFile.close();
outFile.close();

// Remove the old file and rename the new file
remove("books.txt");
rename("tempt.txt", "books.txt");

}
void deletebook()
{
ifstream inFile("books.txt");
ofstream outFile("tempt.txt");

if (!inFile.is_open() || !outFile.is_open()) {
cerr << "Error opening files.\n";
return;
}

int bookNumber;
cout << "Enter Number of the book to delete: ";
cin >> bookNumber;

bool found = false;

while (inFile>>book_num>>author >>title >>domain>>edition>>copiesavailable) {
if (bookNumber == book_num) {
found = true;
cout << "book Record deleted successfully.\n";
} else {
outFile <<book_num << "|" << author << "|" <<title << "|" <<domain<<"|"<<edition<<"|"<<
copiesavailable << endl;
}
}

if (!found) {
cout << "book with Number " << bookNumber<< " not found.\n";
}

inFile.close();
outFile.close();

// Remove the old file and rename the new file
remove("books.txt");
rename("tempt.txt", "books.txt");
}

void viewbook()

{
ifstream inFile("books.txt");

if (!inFile.is_open()) {
cerr << "Error opening students file.\n";
return;
}
while(inFile>>book_num>>author >>title >>domain>>edition>>copiesavailable)
{
cout << book_num<<author<<title<<domain<<edition<<copiesavailable <<endl;
}
}

};
class bookissue : public student, public book
{
public:
void issue()
{
cout << "enter the book number" << endl;
int b;
cin >> b;
cout << "enter the admission no." << endl;
int a;
cin >> a;

cout << "enter the issue date" << endl;
int d;
cin >> d;
ofstream o;
o.open("booksissue.txt", ios::app);
o << setw(10) << left << b << setw(10) << left << a << setw(10) << right << d << endl;
o.close();
}
void retrieve()
{
ifstream read("booksissue.txt");
if (!read.is_open())
cout << "file not opened" << endl;
else
{
cout << setw(10) << left << "book_no" << setw(20) << right << "admission no" << setw(20) << right
<< "issue date" << endl;
string line;
while (getline(read, line))
{
cout << line;
}
}
}
}
;

class bookdeposit : public student, public book
{
public:
void deposit()
{
cout << "enter the book number" << endl;
int b;
cin >> b;
cout << "enter the admission no." << endl;
int a;
cin >> a;
ofstream o;
o.open("booksdeopsit.txt", ios::app);
o << setw(10) << left << b << setw(10) << left << a << endl;
o.close();
}
void retrieve()
{
ifstream read("booksdeposit.txt");
if (!read.is_open())
cout << "file not opened" << endl;
else
{
cout << setw(10) << left << "book_no" << setw(20) << right << "admission no" << endl;
string line;

while (getline(read, line))
{
cout << line;
}
}
}
};
int main()
{
int choice;
cout<<"1.Add student record"<<endl;
cout<<"2.Add book record "<<endl;
cout<<"3.modify book record"<<endl;
cout<<"4.modify student record"<<endl;
cout<<"5.delete book record"<<endl;
cout<<"6.delete student record"<<endl;
cout<<"7.view student record"<<endl;
cout<<"8.view book record"<<endl;
cout<<"9.issue book"<<endl;
cout<<"10.deposit book"<<endl;

cout<<"enter 0 for exit"<<endl;
do{
cout<<"enter your choice :"<<endl;
cin>>choice;

switch(choice)
{
case 1:
{

student s;
s.addstudent();
}
break;
case 2:
{

book s;
s.addbook();
}
break;
case 3:
{

book s;
s.modifybook();
}
break;
case 4:

{

student s;
s.modifystudent();
}
break;
case 5:
{

book s;
s.deletebook();
}
break;
case 6:
{

student s;
s.deletestudent();
}
break;
case 7:
{

book s;
s.viewbook();}

break;
case 8:
{

student s;
s.viewstudent();
}
break;
case 9:
{
cout << "1.update issue list" << endl;
cout << "2.view issue list" << endl;
int n;
cin >> n;
if (n == 1)
{
cout<<"enter the no. of books to issue"<<endl;
int n;
cin>>n;
if(n>=1&&n<=3)
{
bookissue b;
b.issue();
b.student::modifystudent();
b.book::modifybook();

}
else
cout<<"not issued"<<endl;
}
if (n == 2)
{
bookissue b;
b.retrieve();
}

}
break;
case 10:
{cout << "1.update issue list" << endl;
cout << "2.view issue list" << endl;
int n;
cin >> n;
if (n == 1)
{
cout<<"enter the no. of days student has kept the book"<<endl;
int d;
cin>>d;
if(d>15)
{
bookdeposit b;

b.deposit();
b.student::modifystudent();
b.book::modifybook();
}
else
{
cout<<"Fine is imposed"<<endl;
cout<<"per day fine is 5 rupees"<<endl;
cout<<"Fine is "<<5*d<<endl;
}
}
if (n == 2)
{
bookdeposit b;
b.deposit();
}

}
break;
case 0:
cout<<"exit";
}
}while(choice!=0);}