#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <string>
#include <any>
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;

struct Student{
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

auto get_name(const json& j) -> std::string;

auto get_debt(const json& j) -> std::any;

auto get_avg(const json& j) -> std::any;

auto get_group(const json& j) -> std::any;

void from_json(const json& j, Student& s);

void print(const Student& student, std::ostream& os, unsigned max_name, unsigned max_group, unsigned max_avg, unsigned max_debt);

void print(const std::vector<Student>& students, std::ostream& os);

#endif // INCLUDE_HEADER_HPP_
