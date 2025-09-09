# Library Rental System

## Project Description
This is a **C++ library book rental and return system** that supports:
- Three categories of books: **Children books, Computer books, Novels**
- Two groups of people: **Teachers (up to 3 books), Students (up to 2 books)**
- Operations:
  - Search for a book
  - Rent a book
  - Return a book
  - Show my information
  - Show all books

## Features
- Implemented with **inheritance and polymorphism**
- Uses **linked lists** to store book and person data
- Includes **exception handling** for invalid operations
- File input for `book.txt` and `person.txt`

## Project Structure
```text
library-rental-system/
 ├── src/
 │   └── library_rental.cpp  
 ├── data/
 │   ├── book.txt       
 │   └── person.txt      
 ├── README.md     
 ├── .gitignore
 └── LICENSE
```

## Compile and Run
**In the terminal**:
```bash
g++ src/library_rental.cpp -o library
./library
```
**After running, the program shows the menu**:
```text
-----------------------------
            Menu             
-----------------------------
 1.  Search a book
 2.  Rent a book
 3.  Return a book
 4.  Show my information
 5.  Show all books
 6.  Exit
```
**Example Behavior**:
- Search a book → Shows details (category, availability, etc.)
- Rent a book → Updates availability and person’s rented list
- Return a book → Increases availability and removes from person’s rented list
- Show my information → Lists books rented by a teacher or student
- Show all books → Displays all books by category (Children, Computer, Novel)