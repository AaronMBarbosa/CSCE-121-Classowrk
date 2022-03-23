#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

#include "grade_calculator.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// TODO(student): implement these methods

double GradeCalculator::exam_average() const 
{
    double sum = 0;
    double average = 0;

    for (unsigned int i = 0; i < get_exam_grades().size(); ++i)
    {
        sum += get_exam_grades().at(i);
    }

    if (has_final_exam == true)
    {
        average = (get_final_exam() + sum) / (get_exam_grades().size() + 1);

        if (get_final_exam() > average)
            return get_final_exam();

        else
            return average;
    }
        

    else
        average = sum / (get_exam_grades().size() + 1);

    return average;
}

double GradeCalculator::zybook_average() const 
{
    double sum = 0;
    double average = 0;

    for (unsigned int i = 0; i < get_zybook_participation_grades().size(); ++i)
    {
        sum += get_zybook_participation_grades().at(i);
    }

    for (unsigned int k = 0; k < get_zybook_challenge_grades().size(); ++k)
    {
        sum += get_zybook_challenge_grades().at(k);
    }
    
    average = sum / (get_zybook_participation_grades().size() + get_zybook_challenge_grades().size()) + 15;

    if (average >= 85)
        return 100.00;

    return average;
}

double GradeCalculator::hw_average() const 
{
    double sum = 0;
    double average = 0;

    for (unsigned int i = 0; i < get_hw_grades().size(); ++i)
    {
        sum += get_hw_grades().at(i);
    }

    if (get_hw_redemption_grades().empty() == true)
    {
        average = sum / get_hw_grades().size();
        return average;
    }
        

    else
    {
        for (unsigned int k = 0; k < get_hw_redemption_grades().size(); ++k)
        {

            if (get_hw_redemption_grades().at(k) > 0)
            {
                if(get_hw_redemption_grades().at(k) > get_hw_grades().at(k))
                    sum += (get_hw_redemption_grades().at(k) - get_hw_grades().at(k)) / 2;
            }
                

            
        }

        average = sum / (get_hw_grades().size());
        return average;
    }
}

double GradeCalculator::lw_average() const 
{
    double sum = 0;
    double average = 0;

    for (unsigned int i = 0; i < get_lw_grades().size(); ++i)
    {
        sum += get_lw_grades().at(i);
    }

    average = (sum * 100) / get_lw_grades().size();

    return average;
}

// does not apply modifiers
double GradeCalculator::final_grade_numeric() const 
{
    //Exams: 50%
    //Zybooks: 7%
    //Homework: 35%
    //Labwork: 8%

    double CourseAverage = 0;

    CourseAverage += (exam_average() * 0.5) + (zybook_average() * 0.07) + (hw_average() * 0.35) + (lw_average() * 0.08);

    return CourseAverage;
}

// includes application of modifiers
char GradeCalculator::final_grade_letter() const 
{
    //Modifiers:
        //If you have less than  60% exam average, the highest grade you can receive is a D
        //If you failt to submit syllabus ackowledgement by January 21st you receive an F

    char LetterGrade = 'a';

    if (has_syllabus_ack == false)
    {
        LetterGrade = 'F';
    }

    else if (exam_average() < 60)
    {
        if (final_grade_numeric() > 60)
        {
            LetterGrade = 'D';
        }

        else
        {
            LetterGrade = 'F';
        }
    }

    else
    {
        if (final_grade_numeric() >= 90)
            LetterGrade = 'A';
        else if (final_grade_numeric() >= 80)
            LetterGrade = 'B';
        else if (final_grade_numeric() >= 70)
            LetterGrade = 'C';
        else if (final_grade_numeric() >= 60)
            LetterGrade = 'D';
        else
            LetterGrade = 'F';
    }

    return LetterGrade;
}

////////////////////////////////////////////////////////////////////////////////

void GradeCalculator::read_final_exam(std::ifstream& fin) {
    has_final_exam = true;
    fin >> final_exam;
    if (fin.fail()) {
        throw std::runtime_error("failed to read final exam grade");
    }
}

void GradeCalculator::read_exam_hw_redemption_zybook(std::ifstream& fin, const std::string& category) {
    unsigned number;
    fin >> number;
    if (fin.fail()) {
        throw std::runtime_error("failed to read " + category + " number");
    }

    std::vector<double>* vec;
    if (category == "exam") {
        vec = &exam_grades;
    }
    else if (category == "hw") {
        vec = &hw_grades;
    }
    else if (category == "hw-redemption") {
        vec = &hw_redemption_grades;
    }
    else if (category == "zybook") {
        char type;
        fin >> type;
        if (fin.fail()) {
            // HOW TO REACH THIS?
            throw std::runtime_error("failed to read " + category + " type");
        }
        switch (type) {
        case 'p': vec = &zybook_participation_grades; break;
        case 'c': vec = &zybook_challenge_grades; break;
        default: throw std::runtime_error("unrecognized zybook assignment type: " + type);
        }
    }
    else {
        throw std::runtime_error("unrecognized category: " + category);
    }

    double grade;
    fin >> grade;
    if (fin.fail()) {
        throw std::runtime_error("failed to read " + category + " grade");
    }

    while (number > vec->size()) {
        vec->push_back(0);
    }

    vec->at(number - 1) = grade;
}

void GradeCalculator::read_lw(std::ifstream& fin) {
    unsigned number;
    fin >> number;
    if (fin.fail()) {
        throw std::runtime_error("failed to read lw number");
    }

    std::string str;
    fin >> str;
    if (fin.fail()) {
        // HOW TO REACH THIS?
        throw std::runtime_error("failed to read lw grade");
    }

    while (number > lw_grades.size()) {
        lw_grades.push_back(false);
    }

    if (str == "0" || str == "false") {
        lw_grades.at(number - 1) = false;
    }
    else if (str == "1" || str == "true") {
        lw_grades.at(number - 1) = true;
    }
    else {
        throw std::runtime_error("invalid lw grade value: " + str);
    }
}

void GradeCalculator::read_syllabus_ack(std::ifstream& fin) {
    std::string str;
    fin >> str;
    if (fin.fail()) {
        // HOW TO REACH THIS?
        throw std::runtime_error("failed to read syllabus-ack type");
    }
    if (str == "0" || str == "false") {
        has_syllabus_ack = false;
    }
    else if (str == "1" || str == "true") {
        has_syllabus_ack = true;
    }
    else {
        throw std::runtime_error("invalid syllabus-ack grade value: " + str);
    }
}

void GradeCalculator::load_grades(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        throw std::runtime_error("could not open file");
    }
    while (!fin.eof()) {
        std::string category;
        fin >> category;
        if (fin.fail()) {
            if (fin.eof()) {
                continue;
            }
            // HOW TO REACH THIS?
            throw std::runtime_error("failed to read category");
        }
        if (category == "final-exam") {
            read_final_exam(fin);
        }
        else if (category == "exam" || category == "hw" || category == "hw-redemption" || category == "zybook") {
            read_exam_hw_redemption_zybook(fin, category);
        }
        else if (category == "lw") {
            read_lw(fin);
        }
        else if (category == "syllabus-ack") {
            read_syllabus_ack(fin);
        }
        else {
            throw std::runtime_error("invalid category: " + category);
        }
    }
}