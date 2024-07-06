#include "GradeBook.h"
#include <iostream>
GradeBook::GradeBook()
{
  length = 0;
  studentList = NULL;
  iter = 0;
}
GradeBook::~GradeBook()
{
  Student* temp;
  while (studentList != NULL) {
    temp = studentList;
    studentList = studentList->getNext();
    delete temp;
  }
}
int GradeBook::getLength() const { return length; }
/ ****************************************************************************************Title
    : PutItem function from Sorted List ADT* Author : Nell Dale,
    Chip Weems,
    Tim Richards* Availability : < where it's located> C++ Data Structures, 6th Ed * Code segment was modified
*************************************************************************************** /
void GradeBook::putStudent(Student s)
{ // Inserts new student into gradebook by student last name
  Student* newNode; // pointer to node being inserted
  Student* predLoc; // trailing pointer
  Student* location; // traveling pointer
  bool moreToSearch;
  location = studentList;
  predLoc = NULL;
  moreToSearch = (location != NULL);
  // Find insertion point.
  while (moreToSearch) {
    if (s.getName() > location->getName()) {
      location = location->getNext();
      moreToSearch = (location != NULL);
    } else {
      moreToSearch = false;
    }
  }
  // Prepare node for insertion
  newNode = new Student(s);
  newNode->testPrinter();
  // Insert node into list
  if (predLoc == NULL && location == NULL) { // Empty list
    studentList = newNode;
    std::cout << "insert into empty" << std::endl;
    length++;
    return;
  } else if (predLoc == NULL) { // Inserting at beginning
    newNode->setNext(studentList);
    studentList = newNode;
    std::cout << "insert into beginning" << std::endl;
    length++;
    return;
  } // Inserting after beginning
  newNode->setNext(location);
  predLoc->setNext(newNode);
  std::cout << "insert after beginning" << std::endl;
  length++;
  return;
}
Student GradeBook::getNextStudent()
{
  if (iter == NULL)
    iter = studentList;
  Student s(*iter);
  iter = iter->getNext();
  return s;
}
void GradeBook::reset() { iter = studentList; }
