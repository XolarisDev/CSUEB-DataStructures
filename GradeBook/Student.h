#pragma once
#include <string>
class Student {
  private:
  std::string first; // Student's first name
  std::string last; // Student's last name
  int id; // Student id number range 1...9999
  Student* next; // Pointer to next student in gradebook
  int numPrograms; // range 0...6
  int numTests; // range 0...4
  int numFinals; // range 0...1
  int programIter; // Index of next program grade to return
  int testIter; // Index of next test grade to return
  // The total of weights is 1.0
  double weightPrograms; // Weight of average program grade on final grade (0.0
                         // to 1.0)
  double
      weightTests; // Weight of average test grade on final grade (0.0 to 1.0)
  double weightFinal; // Weight of final exam grade on final grade (0.0 to 1.0)
  double*
      programGrades; // Array containing program assignment grades as 0.0...1.0
  double* testGrades; // Array containing test grades as 0.0...1.0
  double finalGrade; // Final exam grade as 0.0...1.0
  public:
  Student(std::string f, std::string l, int i, int numP, int numT, int numF,
      double weightP, double weightT, double weightF, double* gradesP,
      double* gradesT, double gradesF);
  // Student(Student& other);
  ~Student();
  std::string getName() const; // Returns student name as last, first
  int getId() const; // Returns id
  double getProgramGradeAverage() const; // Returns average program grade
  double getProgramGrade(); // Returns program assignment grade and increments
                            // programIter
  void resetProgramGrade(); // Reset programIter to 0
  double getTestGradeAverage() const; // Returns average test grade
  double getTestGrade(); // Returns test grade and increments testIter
  void resetTestGrade(); // Reset testIter to 0
  double getFinalGrade() const; // Returns final exam grade
  double getGrade() const; // Returns final grade
  void setNext(Student* N);
  Student* getNext() const;
  void testPrinter() const; // For testing
};
