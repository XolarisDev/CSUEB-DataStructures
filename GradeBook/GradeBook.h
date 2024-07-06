#pragma once
#include <string>

#include "Student.h"
class GradeBook {
 private:
  Student* studentList;  // Pointer to head of linked list
  int length;            // Number of students in list
  Student* iter = NULL;

 public:
  GradeBook();
  ~GradeBook();
  int getLength() const;
  void putStudent(Student s);  // Inserts new student into gradebook by student
  last name Student getNextStudent();
  void reset();
};
