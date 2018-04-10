//
// Created by okasz on 10.04.2018.
//

#include "StudentRepository.h"

namespace student_repository{
    StudyYear::StudyYear(int year){
        year_ = year;
    }

    StudyYear& StudyYear::operator++() {
        year_ = year_ + 1;
        return *this;
    }

    StudyYear& StudyYear::operator--() {
        year_ = year_ - 1;
        return *this;
    }


}