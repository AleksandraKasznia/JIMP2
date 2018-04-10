//
// Created by okasz on 10.04.2018.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <iostream>
#include <string>

using ::std::string;

namespace student_repository{
    class StudyYear{
    public:
        StudyYear(int year);
        StudyYear& operator++();
        StudyYear& operator--();

    private:
        int year_;
    };

    class Student{
    public:

    private:
        string id_;
        string first_name_;
        string last_name_;
        string program_;
        StudyYear syear_;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
