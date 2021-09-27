#include "student.hpp"

int main() {
    std::string jsonPath=FILE_DIR"students.json";

    parse_json(jsonPath);
    return 0;
}


