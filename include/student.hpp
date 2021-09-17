#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <string>
#include <any>
#include <student.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct student_t{
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

#endif // INCLUDE_HEADER_HPP_
