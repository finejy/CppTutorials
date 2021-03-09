#ifndef GUARD_calcGrade_grade
#define GUARD_calcGrade_grade

#include <vector>
#include "calcGrade_studentInfo.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const student_info&);

#endif
