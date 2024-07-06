#include "GradeBook.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
int main()
{
  char userOpt;
  // Holds user input
  std::string firstName, lastName;
  // For reading strings from Grades.dat
  int studentID, programNum, testNum, finalNum;
  // For reading ints from Grades.dat
  double programWeight, testWeight, finalWeight, finalGrade, temp;
  // For reading doubles from Grades.dat
  double* programGrades;
  double* testGrades;
  std::string line;
  GradeBook masterList;
  std::ifstream in("Grades.dat");
  int counter = 1;
  if (in.is_open()) {
    while (getline(in, line)) {
      std::cout << "reading line " << counter << std::endl;
      std::istringstream s(line);
      std::getline(s, firstName, ';');
      std::getline(s, lastName, ';');
      s >> studentID;
      s >> programWeight;
      s >> programNum;
      programGrades = new double[programNum];
      for (int i = 0; i < programNum; i++) {
        s >> temp;
        programGrades[i] = temp;
      }
      s >> testWeight;
      s >> testNum;
      testGrades = new double[testNum];
      for (int i = 0; i < testNum; i++) {
        s >> testGrades[i];
      }
      s >> finalWeight;
      s >> finalNum;
      finalGrade = 0.0;
      if (finalNum > 0)
        s >> finalGrade;
      Student nextStudent(firstName, lastName, studentID, programNum, testNum,
          finalNum, programWeight, testWeight, finalWeight, programGrades,
          testGrades, finalGrade);
      masterList.putStudent(nextStudent);
      delete[] programGrades;
      delete[] testGrades;
      counter++;
    }
    in.close();
  }
  /*
  for (int i = 0; i < masterList.getLength(); i++) {
  masterList.getNextStudent().testPrinter();
  std::cout << std::endl;
  }
  */
  masterList.~GradeBook();
  return 0;
}
