#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Class for Book
// Abstract parent class
class Book
{
private:
   int code;
   string title;
   int available;
   int rented;
public:
   // Constructor
   Book() : code(0), title(""), available(0), rented(0) {}
   Book(int Code, string Title, int Available, int Rented) : code(Code), title(Title), available(Available), rented(Rented) {}
   // Setter
   void setCode(int Code) {code = Code;}
   void setTitle(string Title) {title = Title;}
   void setAvailable(int Available){available = Available;}
   void setRented(int Rented){rented = Rented;}
   // Getter
   int getCode() {return code;}
   string getTitle() {return title;}
   int getAvailable() {return available;}
   int getRented() {return rented;}
   // Pure virtual function
   virtual int getAge() = 0;
   virtual string getPublisher() = 0;
   virtual int getPublish_date() = 0;
};
// Child class
class ChildrenBook : public Book
{
private:
   int age;
public:
   // Constructor
   ChildrenBook() : Book(), age(0) {}
   ChildrenBook(int Code, string Title, int Age, int Available, int Rented) : Book(Code, Title, Available, Rented), age(Age) {}
   // Setter
   void setAge(int Age){age = Age;}
   // Getter
   int getAge() {return age;}
   string getPublisher() {return " ";}
   int getPublish_date() {return 0;}
};
class ComputerBook : public Book
{
private:
   string publisher;
public:
   // Constructor
   ComputerBook() : Book(), publisher(""){}
   ComputerBook(int Code, string Title, string Publisher, int Available, int Rented) : Book(Code, Title, Available, Rented), publisher(Publisher){}
   // Setter
   void setPublisher(string Publisher){publisher = Publisher;}
   // Getter
   string getPublisher() {return publisher;}
   int getAge() {return 0;}
   int getPublish_date() {return 0;}
};
class Novel: public Book
{
private:
   int publish_date;
public:
   // Constructor
   Novel() : Book(), publish_date(0){}
   Novel(int Code, string Title, int Publish_date, int Available, int Rented) : Book(Code, Title, Available, Rented), publish_date(Publish_date){}
   // Setter
   void setPublish_date(int Publish_date){publish_date = Publish_date;}
   // Getter
   int getPublish_date() {return publish_date;}
   int getAge() {return 0;}
   string getPublisher() {return " ";}
};
// BookNode class for linked list
class BookNode{
private:
   Book* data;
   BookNode* link;
public:
   // Constructor
   BookNode() : data(NULL), link(NULL) {}
   BookNode(Book* Data, BookNode* Link) : data(Data), link(Link) {}
   // Setter
   void setData(Book* Data) {data = Data;}
   void setLink(BookNode* Link) {link = Link;}
   // Getter
   Book* getData() const {return data;}
   BookNode* getLink() const {return link;}
};

// Class for person
// Abstract parent class
class Person
{
private:
   int id;
   string name;
   int count;
public:
   // Constructor
   Person() : id(0), name(""), count(0) {}
   Person(int Id, string Name, int Count) : id(Id), name(Name), count(Count) {}
   // Setter
   void setId(int Id){id = Id;}
   void setName(string Name){name = Name;}
   void setCount(int Count){count = Count;}
   // Getter
   int getId(){return id;}
   string getName(){return name;}
   int getCount(){return count;}
   // Virtual pure function
   virtual int getStudentCode1() = 0;
   virtual int getStudentCode2() = 0;
   virtual int getTeacherCode1() = 0;
   virtual int getTeacherCode2() = 0;
   virtual int getTeacherCode3() = 0;
};
// Child class
class Student: public Person
{
private:
   int code[2];
public:
   // Constructor
   Student() : Person() {code[0] = 0; code[1] = 0;}
   Student(int Id, string Name, int Count, int Code[2]): Person(Id, Name, Count) {code[0] = Code[0]; code[1] = Code[1];}
   // Setter
   void setStudentCode(int Code[2]){code[0] = Code[0]; code[1] = Code[1];}
   void setStudentCode1(int Code){code[0] = Code;}
   void setStudentCode2(int Code){code[1] = Code;}
   // Getter
   int getStudentCode1(){return code[0];}
   int getStudentCode2(){return code[1];}
   int getTeacherCode1(){return 0;}
   int getTeacherCode2(){return 0;}
   int getTeacherCode3(){return 0;}
};
class Teacher: public Person
{
private:
   int code[3];
public:
   // Constructor
   Teacher() : Person() {code[0] = 0; code[1] = 0; code[2] = 0;}
   Teacher(int Id, string Name, int Count, int Code[3]) : Person(Id, Name, Count) {code[0] = Code[0]; code[1] = Code[1]; code[2] = Code[2];}
   // Setter
   void setTeacherCode(int Code[3]){code[0] = Code[0]; code[1]= Code[1]; code[2] = Code[2];}
   void setTeacherCode1(int Code){code[0] = Code;}
   void setTeacherCode2(int Code){code[1] = Code;}
   void setTeacherCode3(int Code){code[2] = Code;}
   // Getter
   int getTeacherCode1(){return code[0];}
   int getTeacherCode2(){return code[1];}
   int getTeacherCode3(){return code[2];}
   int getStudentCode1(){return 0;}
   int getStudentCode2(){return 0;}
};
// PersonNode class for linked list
class PersonNode{
private:
   Person* data;
   PersonNode* link;
public:
   // Constructor
   PersonNode() : data(NULL), link(NULL) {}
   PersonNode(Person* Data, PersonNode* Link) : data(Data), link(Link) {}
   // Setter
   void setData(Person* Data) {data = Data;}
   void setLink(PersonNode* Link) {link = Link;}
   // Getter
   Person* getData() const {return data;}
   PersonNode* getLink() const {return link;}
};

void readBookFile(string, BookNode*[]);
void readPersonFile(string, PersonNode*[]);
void menu1(BookNode*[]);
void menu2(BookNode*[], PersonNode*[]);
void menu3(BookNode*[], PersonNode*[]);
void menu4(BookNode*[], PersonNode*[]);
void menu5(BookNode*[]);
void menu6(BookNode*[], PersonNode*[]);

int main() {

   // Read file and save data to library
   BookNode* library[3] = {NULL, NULL, NULL};
   readBookFile("book.txt", library);

   // Read file and save data to person
    PersonNode* person[2] = {NULL, NULL};
    readPersonFile("person.txt", person);

   // Show the Menu
   int select;
   do{
       cout << "-----------------------------" << endl;
       cout << "            Menu             " << endl;
       cout << "-----------------------------" << endl;
       cout << " 1.  Search a book" << endl;
       cout << " 2.  Rent a book" << endl;
       cout << " 3.  Return a book" << endl;
       cout << " 4.  Show my information" << endl;
       cout << " 5.  Show all books" << endl;
       cout << " 6.  Exit\n" << endl;
       cout << "Select (1~6) : ";
       cin >> select;
       if(select == 1)
           menu1(library);
       else if(select == 2)
           menu2(library, person);
       else if(select == 3)
           menu3(library, person);
       else if(select == 4)
           menu4(library, person);
       else if(select == 5)
           menu5(library);
   }while(select != 6);

   menu6(library, person);
   cout << "Exit..." << endl;

   return 0;
}

void readBookFile(string filename, BookNode* library[3]){
   ifstream infile;
   infile.open(filename);
   if(infile.fail()){
       cout << "Input file opening failed." << std::endl;
       exit(1);
   }

   // Create three head to save different type book
   BookNode* head1 = NULL;
   BookNode* head2 = NULL;
   BookNode* head3 = NULL;

   // Read file
   int tempCode, tempAge, tempAvailable, tempRent, tempPublishDate;
   string tempTitle, tempPublisher;
   while(!infile.eof()){
       infile >> tempCode;
       // Children book
       if(tempCode >= 1001 && tempCode <= 2000){
           infile >> tempTitle >> tempAge >> tempAvailable >> tempRent;
           ChildrenBook* tempKidBook = new ChildrenBook(tempCode, tempTitle, tempAge, tempAvailable, tempRent);
           BookNode* newKid = new BookNode(tempKidBook, NULL);
           // sort data by the code
           // For the first location
           if(head1 == NULL || newKid->getData()->getCode() < head1->getData()->getCode()){
               newKid->setLink(head1);
               head1 = newKid;
           }
           // For other location
           else {
               // Find the previous ptr location
               BookNode* ptr1  = head1;
               while (ptr1->getLink() != NULL && ptr1->getLink()->getData()->getCode() < newKid->getData()->getCode()) {
                   ptr1 = ptr1->getLink();
               }
               // Insert the number
               newKid->setLink(ptr1->getLink());
               ptr1->setLink(newKid);
           }
       }

       // Computer book
       else if(tempCode >= 2001 && tempCode <= 3000){
           infile >> tempTitle >> tempPublisher >> tempAvailable >> tempRent;
           ComputerBook* tempComBook = new ComputerBook(tempCode, tempTitle, tempPublisher, tempAvailable, tempRent);
           BookNode* newCom = new BookNode(tempComBook,NULL);
           // sort data by the code
           // For the first location
           if(head2 == NULL || newCom->getData()->getCode() < head2->getData()->getCode()){
               newCom->setLink(head2);
               head2 = newCom;
           }
           // For other location
           else {
               // Find the previous ptr location
               BookNode* ptr2 = head2;
               while (ptr2->getLink() != NULL && ptr2->getLink()->getData()->getCode() < newCom->getData()->getCode()) {
                   ptr2 = ptr2->getLink();
               }
               // Insert the number
               newCom->setLink(ptr2->getLink());
               ptr2->setLink(newCom);
           }
       }

       // Novel
       else{
           infile >> tempTitle >> tempPublishDate >> tempAvailable >> tempRent;
           Novel* tempNBook = new Novel(tempCode, tempTitle, tempPublishDate, tempAvailable, tempRent);
           BookNode* newNov = new BookNode(tempNBook, NULL);
           // sort data by the code
           // For the first location
           if(head3 == NULL || newNov->getData()->getCode() < head3->getData()->getCode()){
               newNov->setLink(head3);
               head3 = newNov;
           }
           // For other location
           else {
               // Find the previous ptr location
               BookNode* ptr3 = head3;
               while (ptr3->getLink() != NULL && ptr3->getLink()->getData()->getCode() < newNov->getData()->getCode()) {
                   ptr3 = ptr3->getLink();
               }
               // Insert the number
               newNov->setLink(ptr3->getLink());
               ptr3->setLink(newNov);
           }
       }
   }

   // ChildrenBook list for library[0]
   library[0] = head1;
   // ComputerBook list for library[1]
   library[1] = head2;
   // Novel list for library[2]
   library[2] = head3;

   infile.close();
}

void readPersonFile(string filename, PersonNode* person[2]){
   ifstream infile;
   infile.open(filename);
   if(infile.fail()){
       cout << "Input file opening failed." << std::endl;
       exit(1);
   }

   // Create two head to save teacher and student
   PersonNode* head1 = NULL;
   PersonNode* head2 = NULL;

   int tempId, tempCount;
   int tempTeacherCode[3] = {0}, tempStudentCode[2] = {0};
   string tempName;
   while(!infile.eof()){
       infile >> tempId;
       // Teacher
       if(tempId >= 1 && tempId <= 100){
           infile >> tempName >> tempCount;
           // Saving each code to code array
           int size = tempCount;
           for(int i = 0; i < size; i++)
               infile >> tempTeacherCode[i];
           Teacher* tempTeacher = new Teacher(tempId, tempName, tempCount, tempTeacherCode);
           PersonNode* newTeacher = new PersonNode(tempTeacher, NULL);
           // sort data by the code
           // For the first location
           if(head1 == NULL || newTeacher->getData()->getId() < head1->getData()->getId()){
               newTeacher->setLink(head1);
               head1 = newTeacher;
           }
           // For other location
           else {
               // Find the previous ptr location
               PersonNode* ptr1 = head1;
               while (ptr1->getLink() != NULL && ptr1->getLink()->getData()->getId() < newTeacher->getData()->getId()) {
                   ptr1 = ptr1->getLink();
               }
               // Insert the number
               newTeacher->setLink(ptr1->getLink());
               ptr1->setLink(newTeacher);
           }
       }
       // Student
       else{
           infile >> tempName >> tempCount;
           // Saving code
           int size = tempCount;
           for(int i = 0; i < size; i++)
               infile >> tempStudentCode[i];
           Student* tempStudent = new Student(tempId, tempName, tempCount, tempStudentCode);
           PersonNode* newStudent = new PersonNode(tempStudent, NULL);
           // sort data by the code
           // For the first location
           if(head2 == NULL || newStudent->getData()->getId() < head2->getData()->getId()){
               newStudent->setLink(head2);
               head2 = newStudent;
           }
           // For other location
           else {
               // Find the previous ptr location
               PersonNode* ptr2 = head2;
               while (ptr2->getLink() != NULL && ptr2->getLink()->getData()->getId() < newStudent->getData()->getId()) {
                   ptr2 = ptr2->getLink();
               }
               // Insert the number
               newStudent->setLink(ptr2->getLink());
               ptr2->setLink(newStudent);
           }
       }
   }
   // Teacher list for person[0]
   person[0] = head1;
   // Student list for person[1]
   person[1] = head2;

   infile.close();

}

// Check the book if exits by entering code and title
void menu1(BookNode* library[3]){
   int code;
   string title;
   cout << "Enter code  : ";
   cin >> code;
   cout << "Enter title : ";
   cin >> title;
   cout << endl;

   // Check, if not exits, catch the exception
   try{
       bool found = false;
       for(int i = 0; i < 3; i++) {
           // For ChildrenBook
           if (i == 0) {
               BookNode* ptr1;
               for (ptr1 = library[i]; ptr1; ptr1 = ptr1->getLink()) {
                   if (ptr1->getData()->getCode() == code && ptr1->getData()->getTitle() == title) {
                       cout << title << "(" << code << ") exists." << endl;
                       cout << "Category : Children" << endl;
                       cout << "Age : " << ptr1->getData()->getAge() << endl;
                       cout << ptr1->getData()->getAvailable() << " available, " << ptr1->getData()->getRented() << " rented" << endl;
                       found = true;
                       break;
                   }
               }
           }
               // For ComputerBook
           else if (i == 1) {
               BookNode* ptr2;
               for (ptr2 = library[i]; ptr2; ptr2 = ptr2->getLink()) {
                   if (ptr2->getData()->getCode() == code && ptr2->getData()->getTitle() == title) {
                       cout << title << "(" << code << ") exists." << endl;
                       cout << "Category : Computer" << endl;
                       cout << "Publisher : " << ptr2->getData()->getPublisher() << endl;
                       cout << ptr2->getData()->getAvailable() << " available, " << ptr2->getData()->getRented() << " rented" << endl;
                       found = true;
                       break;
                   }
               }
           }
               // For Novel
           else {
               BookNode* ptr3;
               for (ptr3 = library[i]; ptr3; ptr3 = ptr3->getLink()) {
                   if (ptr3->getData()->getCode() == code && ptr3->getData()->getTitle() == title) {
                       cout << title << "(" << code << ") exists." << endl;
                       cout << "Category : Novel" << endl;
                       cout << "Published date : " << ptr3->getData()->getPublish_date() << endl;
                       cout << ptr3->getData()->getAvailable() << " available, " << ptr3->getData()->getRented() << " rented" << endl;
                       found = true;
                       break;
                   }
               }
           }
       }
       if(found == false)
           throw "- No match (code and title do not match)";
   }
   catch(const char* message){
       cout << message << endl;
   }
   cout << endl;
}

// For rent book, ask user input id and book title, then update the rented book situation
void menu2(BookNode* library[], PersonNode* person[]){
    int id;
    string bookTitle;
    cout << "Enter your id    :";
    cin >> id;
    cout << "Enter book title :";
    cin >> bookTitle;
    cout << endl;

    // Show user's information
    PersonNode* ptr1;
    BookNode* ptr2;
    int rentNumber;
    string name;
    for(int i = 0; i < 2; i++) {
        for (ptr1 = person[i]; ptr1; ptr1 = ptr1->getLink()) {
            if (ptr1->getData()->getId() == id) {
                rentNumber = ptr1->getData()->getCount();
                name = ptr1->getData()->getName();
                cout << "You are " << name << ". You rented " << rentNumber << " book." << endl;
            }
        }
    }

    // Update the rented book situation
    char answer;
    cout << "Do you want to rent '" << bookTitle << "' (y/n) ?";
    cin >> answer;
    int count, bookCode;
    int teacherCode[3] = {0}, studentCode[2] = {0};
    if(tolower(answer) == 'y'){
        try {
            // Assure user has not rented 2(or 3) books
            for (int i = 0; i < 2; i++) {
                for (ptr1 = person[i]; ptr1; ptr1 = ptr1->getLink()) {
                    if (ptr1->getData()->getId() == id) {
                        // For teacher, they can rent 3 books
                        if (id >= 1 && id <= 100) {
                            if (ptr1->getData()->getCount() == 3){
                                throw "You already rented 3 books.";
                                break;
                            }
                            // If they can rent book, update the count number and the book code
                            else{
                                // Save the original count and code array
                                count = ptr1->getData()->getCount();
                                for(int k = 0; k < count; k++){
                                    if(k == 0)
                                        teacherCode[k] = ptr1->getData()->getTeacherCode1();
                                    else
                                        teacherCode[k] = ptr1->getData()->getTeacherCode2();
                                }
                                // Find the book code
                                for(int j = 0; j < 3; j++){
                                    for (ptr2 = library[j]; ptr2; ptr2 = ptr2->getLink()){
                                        if(ptr2->getData()->getTitle() == bookTitle){
                                            // Assure this book is available
                                            if(ptr2->getData()->getAvailable() == 0){
                                                throw "The book is not available (all rented out).";
                                                break;
                                            }
                                            // If this book is available, get the book code and update its available number & rented number
                                            else{
                                                bookCode = ptr2->getData()->getCode();
                                                // Set the available number - 1 and the rented number + 1
                                                int available, rent;
                                                string title;
                                                // For children book
                                                if(bookCode >= 1001 && bookCode <= 2000){
                                                    int age;
                                                    available = ptr2->getData()->getAvailable();
                                                    rent = ptr2->getData()->getRented();
                                                    age = ptr2->getData()->getAge();
                                                    title = ptr2->getData()->getTitle();
                                                    available -= 1;
                                                    rent += 1;
                                                    ChildrenBook* children = new ChildrenBook(bookCode, title, age, available, rent);
                                                    ptr2->setData(children);
                                                }
                                                // For computer book
                                                else if(bookCode >= 2001 && bookCode <= 3000){
                                                    string publisher;
                                                    available = ptr2->getData()->getAvailable();
                                                    rent = ptr2->getData()->getRented();
                                                    publisher = ptr2->getData()->getPublisher();
                                                    title = ptr2->getData()->getTitle();
                                                    available -= 1;
                                                    rent += 1;
                                                    ComputerBook* computer = new ComputerBook(bookCode, title, publisher, available, rent);
                                                    ptr2->setData(computer);
                                                }
                                                // For novel
                                                else{
                                                    int publish_date;
                                                    available = ptr2->getData()->getAvailable();
                                                    rent = ptr2->getData()->getRented();
                                                    publish_date = ptr2->getData()->getPublish_date();
                                                    title = ptr2->getData()->getTitle();
                                                    available -= 1;
                                                    rent += 1;
                                                    Novel* novel = new Novel(bookCode, title, publish_date, available, rent);
                                                    ptr2->setData(novel);
                                                }
                                            }
                                        }
                                    }
                                }
                                // After finding the book code, set count + 1 and set the new book code for the person
                                teacherCode[count] = bookCode;
                                count += 1;
                                Teacher* teacher = new Teacher(id, name, count, teacherCode);
                                ptr1->setData(teacher);
                            }
                        }
                        // For student, they can rent 2 books
                        else{
                            if (ptr1->getData()->getCount() == 2){
                                throw "You already rented 2 books.";
                                break;
                            }
                            // If they can rent book, update the count number and the book code
                            else{
                                // Save the original count and code array
                                count = ptr1->getData()->getCount();
                                for(int k = 0; k < count; k++){
                                    studentCode[k] = ptr1->getData()->getStudentCode1();
                                }
                                // Find the book code
                                for(int j = 0; j < 3; j++){
                                    for (ptr2 = library[j]; ptr2; ptr2 = ptr2->getLink()){
                                        if(ptr2->getData()->getTitle() == bookTitle){
                                            // Assure this book is available
                                            if(ptr2->getData()->getAvailable() == 0){
                                                throw "The book is not available (all rented out).";
                                                break;
                                            }
                                            // If this book is available, get the book code and update its available number & rented number
                                            else{
                                                bookCode = ptr2->getData()->getCode();
                                                // Set the available number - 1 and the rented number + 1
                                                int available, rent;
                                                string title;
                                                // For children book
                                                if(bookCode >= 1001 && bookCode <= 2000){
                                                    int age;
                                                    available = ptr2->getData()->getAvailable();
                                                    rent = ptr2->getData()->getRented();
                                                    age = ptr2->getData()->getAge();
                                                    title = ptr2->getData()->getTitle();
                                                    available -= 1;
                                                    rent += 1;
                                                    ChildrenBook* children = new ChildrenBook(bookCode, title, age, available, rent);
                                                    ptr2->setData(children);
                                                }
                                                    // For computer book
                                                else if(bookCode >= 2001 && bookCode <= 3000){
                                                    string publisher;
                                                    available = ptr2->getData()->getAvailable();
                                                    rent = ptr2->getData()->getRented();
                                                    publisher = ptr2->getData()->getPublisher();
                                                    title = ptr2->getData()->getTitle();
                                                    available -= 1;
                                                    rent += 1;
                                                    ComputerBook* computer = new ComputerBook(bookCode, title, publisher, available, rent);
                                                    ptr2->setData(computer);
                                                }
                                                    // For novel
                                                else{
                                                    int publish_date;
                                                    available = ptr2->getData()->getAvailable();
                                                    rent = ptr2->getData()->getRented();
                                                    publish_date = ptr2->getData()->getPublish_date();
                                                    title = ptr2->getData()->getTitle();
                                                    available -= 1;
                                                    rent += 1;
                                                    Novel* novel = new Novel(bookCode, title, publish_date, available, rent);
                                                    ptr2->setData(novel);
                                                }
                                            }
                                        }
                                    }
                                }
                                // After finding the book code, set count + 1 and set the new book code for the person
                                studentCode[count] = bookCode;
                                count += 1;
                                Student* student = new Student(id, name, count, studentCode);
                                ptr1->setData(student);
                            }
                        }
                    }
                }
            }
            cout << "***** Rent succeed! Check your info! *****" << endl;
        }
        catch(const char* message){
            cout << message << endl;
        }
    }
    cout << endl;
}

//  For return book, ask user input id and book title, then update the rented book situation
void menu3(BookNode* library[3], PersonNode* person[2]){
    int id, bookCode;
    cout << "Enter your id :";
    cin >> id;
    cout << "Enter the book code to return  :";
    cin >> bookCode;
    cout << endl;

    // Find the book title by the book code
    string bookTitle;
    BookNode* ptr1;
    for(int i = 0; i < 3; i++) {
        for (ptr1 = library[i]; ptr1; ptr1 = ptr1->getLink()) {
            if (ptr1->getData()->getCode() == bookCode)
                bookTitle = ptr1->getData()->getTitle();
        }
    }

    // Update the rented book situation
    char answer;
    cout << "Do you want to return '" << bookTitle << "' (y/n) ? ";
    cin >> answer;
    if(tolower(answer) == 'y'){
        PersonNode* ptr2;
        int teacherCode[3] = {0}, studentCode[2] = {0};
        bool found = false;
        try{
            // Find the id's book code information
            for(int i = 0; i < 2; i++){
                for(ptr2 = person[i]; ptr2; ptr2 = ptr2->getLink()){
                    if(ptr2->getData()->getId() == id){
                        int count = ptr2->getData()->getCount();
                        string name = ptr2->getData()->getName();
                        // For teacher
                        if(id >= 1 && id <= 100){
                            // Save the teacher's book code to an array
                            teacherCode[0] = ptr2->getData()->getTeacherCode1();
                            teacherCode[1] = ptr2->getData()->getTeacherCode2();
                            teacherCode[2] = ptr2->getData()->getTeacherCode3();
                            // Check if the teacher rented this book
                            for(int j = 0; j < 3; j++){
                                // If the teacher rented this book, update the book's situation and the teacher's information
                                if(teacherCode[j] == bookCode){
                                    // set teacher's count - 1, and change the book code to 0
                                    count -= 1;
                                    teacherCode[j] = 0;
                                    Teacher* teacher = new Teacher(id, name, count, teacherCode);
                                    ptr2->setData(teacher);
                                    // set the book's available number + 1 & rented number - 1
                                    for(int k = 0; k < 3; k++) {
                                        for (ptr1 = library[k]; ptr1; ptr1 = ptr1->getLink()) {
                                            if (ptr1->getData()->getCode() == bookCode){
                                                int available = ptr1->getData()->getAvailable();
                                                int rented = ptr1->getData()->getRented();
                                                available += 1;
                                                rented -= 1;
                                                // For children book
                                                if(bookCode >= 1001 && bookCode <= 2000){
                                                    int age = ptr1->getData()->getAge();
                                                    ChildrenBook* children = new ChildrenBook(bookCode, bookTitle, age, available, rented);
                                                    ptr1->setData(children);
                                                }
                                                // For computer book
                                                else if(bookCode >= 2001 && bookCode <= 3000){
                                                    string publisher;
                                                    publisher = ptr1->getData()->getPublisher();
                                                    ComputerBook* computer = new ComputerBook(bookCode, bookTitle, publisher, available, rented);
                                                    ptr1->setData(computer);
                                                }
                                                // For novel
                                                else{
                                                    int publish_date;
                                                    publish_date = ptr1->getData()->getPublish_date();
                                                    Novel* novel = new Novel(bookCode, bookTitle, publish_date, available, rented);
                                                    ptr1->setData(novel);
                                                }
                                            }
                                        }
                                    }
                                    found = true;
                                    break;
                                }
                            }
                        }
                        // For student
                        else{
                            // Save the student's book code to an array
                            studentCode[0] = ptr2->getData()->getStudentCode1();
                            studentCode[1] = ptr2->getData()->getStudentCode2();
                            // Check if the student rented this book
                            for(int j = 0; j < 2; j++){
                                // If the student rented this book, update the book's situation and the student's information
                                if(studentCode[j] == bookCode){
                                    // set student's count - 1, and change the book code to 0
                                    count -= 1;
                                    studentCode[j] = 0;
                                    Student* student = new Student(id, name, count, studentCode);
                                    ptr2->setData(student);
                                    // set the book's available number + 1 & rented number - 1
                                    for(int k = 0; k < 3; k++) {
                                        for (ptr1 = library[k]; ptr1; ptr1 = ptr1->getLink()) {
                                            if (ptr1->getData()->getCode() == bookCode){
                                                int available = ptr1->getData()->getAvailable();
                                                int rented = ptr1->getData()->getRented();
                                                available += 1;
                                                rented -= 1;
                                                // For children book
                                                if(bookCode >= 1001 && bookCode <= 2000){
                                                    int age = ptr1->getData()->getAge();
                                                    ChildrenBook* children = new ChildrenBook(bookCode, bookTitle, age, available, rented);
                                                    ptr1->setData(children);
                                                }
                                                // For computer book
                                                else if(bookCode >= 2001 && bookCode <= 3000){
                                                    string publisher;
                                                    publisher = ptr1->getData()->getPublisher();
                                                    ComputerBook* computer = new ComputerBook(bookCode, bookTitle, publisher, available, rented);
                                                    ptr1->setData(computer);
                                                }
                                                // For novel
                                                else{
                                                    int publish_date;
                                                    publish_date = ptr1->getData()->getPublish_date();
                                                    Novel* novel = new Novel(bookCode, bookTitle, publish_date, available, rented);
                                                    ptr1->setData(novel);
                                                }
                                            }
                                        }
                                    }
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if (!found) {
                throw "The 'id' did not rent the book.";
            }
            cout << "***** Return succeed! Check your info! *****" << endl;
        }
        catch(const char* message){
            cout << message << endl;
        }
    }
    cout << endl;
}

// Ask user input id and name, then print out their rented book information
void menu4(BookNode* library[3], PersonNode* person[2]){
   int id;
   string name;
   cout << "Enter your id   : ";
   cin >> id;
   cout << "Enter your name : ";
   cin >> name;
   cout << endl;
   // Search user's information and find the rented book code
   PersonNode* ptr1;
   int rentNumber, count;
   int teacherCode[3] = {0}, studentCode[2] = {0};
   for(int i = 0; i < 2; i++){
       for(ptr1 = person[i]; ptr1; ptr1 = ptr1->getLink()) {
           if (ptr1->getData()->getId() == id && ptr1->getData()->getName() == name) {
               rentNumber = ptr1->getData()->getCount();
               cout << "You rented " << rentNumber << " books." << endl;
               count = ptr1->getData()->getCount();
               if(rentNumber == 0)
                   break;
               else{
                   // save teacher's codes
                   if(id >= 1 && id <= 100){
                       teacherCode[0] = ptr1->getData()->getTeacherCode1();
                       teacherCode[1] = ptr1->getData()->getTeacherCode2();
                       teacherCode[2] = ptr1->getData()->getTeacherCode3();
                   }
                   else{ // save student's code
                       studentCode[0] = ptr1->getData()->getStudentCode1();
                       studentCode[1] = ptr1->getData()->getStudentCode2();
                   }
               }
           }
       }
   }
   // Print the book that they rented
   BookNode* ptr2;
   if(rentNumber != 0){
       for(int i = 0; i < 3; i++){
           for(ptr2 = library[i]; ptr2; ptr2 = ptr2->getLink()){
               // for teacher's code
               if(id >= 1 && id <= 100){
                   for(int j = 0; j < count; j++){
                       if(ptr2->getData()->getCode() == teacherCode[j]){
                           cout << "* " << ptr2->getData()->getTitle() << "(" << teacherCode[j] << ") - ";
                           // for children book, print the age
                           if(teacherCode[j] >= 1001 && teacherCode[j] <= 2000)
                               cout << "age " << ptr2->getData()->getAge() << endl;
                           // for computer book, print the publisher
                           else if(teacherCode[j] >= 2001 && teacherCode[j] <= 3000)
                               cout << "publisher " << ptr2->getData()->getPublisher() << endl;
                           // for novel, print the published date
                           else cout << "published data " << ptr2->getData()->getPublish_date() << endl;
                       }
                   }
               }
               // for student's code
               else {
                   for (int j = 0; j < count; j++) {
                       if (ptr2->getData()->getCode() == studentCode[j]) {
                           cout << "* " << ptr2->getData()->getTitle() << "(" << studentCode[j] << ") - ";
                           // for children book, print the age
                           if(studentCode[j] >= 1001 && studentCode[j] <= 2000)
                               cout << "age " << ptr2->getData()->getAge() << endl;
                               // for computer book, print the publisher
                           else if(studentCode[j] >= 2001 && studentCode[j] <= 3000)
                               cout << "publisher " << ptr2->getData()->getPublisher() << endl;
                               // for novel, print the published date
                           else cout << "published data " << ptr2->getData()->getPublish_date() << endl;
                       }
                   }
               }
           }
       }
   }
   cout << endl;
}

// Print out all books information by different kind
void menu5(BookNode* library[3]){
   // For Children book
   cout << "================================================================" << endl;
   cout << "                       Children   Books                         " << endl;
   cout << "================================================================" << endl;
   cout << " code               title               age   available  rented " << endl;
   cout << "----------------------------------------------------------------" << endl;
   BookNode* ptr1;
   for (ptr1 = library[0]; ptr1; ptr1 = ptr1->getLink()) {
       cout << setw(5) << ptr1->getData()->getCode() << "   ";
       // Resave title without '_'
       string title = ptr1->getData()->getTitle();
       string newTitle;
       for(int i = 0; i < title.length(); i++) {
           if (title[i] == '_')
               newTitle.append(" ");
           else
               newTitle.append(1,title[i]);
       }
       cout << setw(25) << right << newTitle << setw(9) << ptr1->getData()->getAge() << setw(9) << ptr1->getData()->getAvailable() << setw(9) << ptr1->getData()->getRented() << endl;
   }
   cout << endl;
   // For Computer book
   cout << "========================================================================" << endl;
   cout << "                            Computer   Books                            " << endl;
   cout << "========================================================================" << endl;
   cout << " code                title              publisher       available rented" << endl;
   cout << "------------------------------------------------------------------------" << endl;
   BookNode* ptr2;
   for (ptr2 = library[1]; ptr2; ptr2 = ptr2->getLink()) {
       cout << setw(5) << ptr2->getData()->getCode() << "   ";
       // Resave title without '_'
       string title = ptr2->getData()->getTitle();
       string newTitle;
       for(int i = 0; i < title.length(); i++) {
           if (title[i] == '_')
               newTitle.append(" ");
           else
               newTitle.append(1,title[i]);
       }
       cout << setw(23) << right << newTitle << setw(20) << ptr2->getData()->getPublisher() << setw(9) << ptr2->getData()->getAvailable() << setw(9) << ptr2->getData()->getRented() << endl;
   }
   cout << endl;
   // For Novel
   cout << "================================================================" << endl;
   cout << "                              Novel                             " << endl;
   cout << "================================================================" << endl;
   cout << " code           title            published-date available rented" << endl;
   cout << "----------------------------------------------------------------" << endl;
   BookNode* ptr3;
   for (ptr3 = library[2]; ptr3; ptr3 = ptr3->getLink()) {
       cout << setw(5) << ptr3->getData()->getCode() << "   ";
       // Resave title without '_'
       string title = ptr3->getData()->getTitle();
       string newTitle;
       for(int i = 0; i < title.length(); i++) {
           if (title[i] == '_')
               newTitle.append(" ");
           else
               newTitle.append(1,title[i]);
       }
       cout << setw(21) << right << newTitle << setw(15) << ptr3->getData()->getPublish_date() << setw(10) << ptr3->getData()->getAvailable() << setw(7) << ptr3->getData()->getRented() << endl;
   }
   cout << endl;
}

// Delete the linked lists
void menu6(BookNode* library[3], PersonNode* person[2]){
    // Delete the library linked list
    for(int i = 0; i < 3; i++){
        while (library[i] != NULL) {
            BookNode* temp = library[i];
            library[i] = library[i]->getLink();
            delete temp;
        }
    }
    // Delete the person linked list
    for(int i = 0; i < 2; i++){
        while (person[i] != NULL) {
            PersonNode* temp = person[i];
            person[i] = person[i]->getLink();
            delete temp;
        }
    }
}