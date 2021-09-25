#include <nlohmann/json.hpp>
#include "student.hpp"
#include <fstream>
#include <iostream>

int main() {
    std::string jsonPath = "RES_DIR/students.json";


    std::ifstream file{jsonPath};
    if (!file) {
        throw std::runtime_error{"unable to open json: " + jsonPath};
    }

    json data;
    file >> data;

    std::vector<Student> students;
    for (auto const& item : data.at("items")) {
        Student student;
        from_json(item, student);
        students.push_back(student);
    }
    //нужно проверки сделатб
    print(students, std::cout);

}


