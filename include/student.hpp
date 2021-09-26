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

auto get_group(const json& j) -> std::any;

auto get_avg(const json& j) -> std::any;

auto get_debt(const json& j) -> std::any;

void from_json(const json& j, Student& s);

std::string get_str_from_name(std::any name);

std::string get_str_from_group(std::any group);

std::string get_str_from_avg(std::any avg);

std::string get_str_from_debt(std::any debt);

void print(const Student& student, std::ostream& os, unsigned max_name, unsigned max_group, unsigned max_avg, unsigned max_debt);

void print(const std::vector<Student>& students, std::ostream& os);

#endif // INCLUDE_HEADER_HPP_
