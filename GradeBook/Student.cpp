#include "Student.h"
#include <iostream>
Student::Student(std::string f, std::string l, int i, int numP, int numT,
    int numF, double weightP, double weightT, double weightF, double* gradesP,
    double* gradesT, double gradesF)
{
  first = f;
  last = l;
  id = i;
  next = NULL;
  numPrograms = numP;
  numTests = numT;
  numFinals = numF;
  weightPrograms = weightP;
  weightTests = weightT;
  weightFinal = weightF;
  programIter = 0;
  testIter = 0;
  programGrades = new double[numPrograms];
  for (int i = 0; i < numPrograms; i++) {
    programGrades[i] = gradesP[i];
  }
  testGrades = new double[numTests];
  for (int i = 0; i < numTests; i++) {
    testGrades[i] = gradesT[i];
  }
  if (numF > 0)
    finalGrade = gradesF;
}
/*
Student::Student(Student& other) {
std::cout << "copy constructor run " << std::endl;
first = other.first;
last = other.last;
id = other.id;
next = NULL;
numPrograms = other.numPrograms;
numTests = other.numTests;
numFinals = other.numFinals;
weightPrograms = other.weightPrograms;
weightTests = other.weightTests;
weightFinal = other.weightFinal;
programIter = other.programIter;
testIter = other.testIter;
programGrades = other.programGrades;
testGrades = other.testGrades;
finalGrade = other.finalGrade;
}
*/
Student::~Student()
{
  delete[] programGrades;
  delete[] testGrades;
}
std::string Student::getName() const
{ // Returns student name as last, first
  return last + ", " + first;
}
int Student::getId() const
{ // Returns id
  return id;
}
double Student::getProgramGradeAverage() const
{ // Returns average program
  grade as 0.0...1.0 double total = 0;
  for (int i = 0; i < numPrograms; i++) {
    total += programGrades[i];
  }
  return total / numPrograms;
}
double Student::getProgramGrade()
{ // Returns program assignment grade and increments programIter
  return programGrades[programIter++];
}
void Student::resetProgramGrade()
{ // Reset programIter to 0
  programIter = 0;
}
double Student::getTestGradeAverage() const
{ // Returns average test grade as 0.0...1.0
  double total = 0;
  for (int i = 0; i < numTests; i++) {
    total += testGrades[i];
  }
  return total / numTests;
}
double Student::getTestGrade()
{ // Returns test grade and increments testIter
  return testGrades[testIter++];
}
void Student::resetTestGrade()
{ // Reset testIter to 0
  testIter = 0;
}
double Student::getFinalGrade() const
{ // Returns final exam grade as 0.0...1.0
  if (numFinals > 0)
    return finalGrade;
  return 0;
}
double Student::getGrade() const
{ // Returns final grade as 0.0...1.0
  double program = getProgramGradeAverage();
  double test = getTestGradeAverage();
  double final = getFinalGrade();
  return (program * weightPrograms) + (test * weightTests)
      + (final * weightFinal);
}
void Student::setNext(Student* N) { next = N; }
Student* Student::getNext() const { return next; }
void Student::testPrinter() const
{
  std::cout << getName() << std::endl;
  std::cout << id << std::endl;
  std::cout << weightPrograms << std::endl;
  std::cout << numPrograms << std::endl;
  for (int i = 0; i < numPrograms; i++) {
    std::cout << programGrades[i] << " ";
  }
  std::cout << std::endl;
  std::cout << weightTests << std::endl;
  std::cout << numTests << std::endl;
  for (int i = 0; i < numTests; i++) {
    std::cout << testGrades[i] << " ";
  }
  std::cout << std::endl;
  std::cout << weightFinal << std::endl;
  std::cout << numFinals << std::endl;
  if (numFinals > 0)
    std::cout << finalGrade << std::endl;
}
