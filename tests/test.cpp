// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <student.hpp>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Exceptions, Unable_to_open_1){
    EXPECT_THROW(parse_json(FILE_DIR"test_file1.json"),std::runtime_error);
}

TEST(Exceptions, Unexpected_group_type){
    EXPECT_THROW(get_str_from_group(3.14),std::invalid_argument);
}

TEST(Exceptions, Unexpected_avg_type){
    EXPECT_THROW(get_str_from_avg("ABOBA"),std::invalid_argument);
}

TEST(Exceptions, Unexpected_debt_type){
    EXPECT_THROW(get_str_from_debt(3.14),std::invalid_argument);
}

TEST(Equality, EqualityTest1){
    std::ifstream file{FILE_DIR"test_file2.json"};
    json data;
    file>>data;

    std::vector<Student> students=get_vector_from_json(data);
    std::stringstream parsed;
    print(students,parsed);

    EXPECT_EQ(parsed,
              "|---------------|---------|--------|-------|"
              "|Name           |Group    |Avg     |Debt   |"
              "|---------------|---------|--------|-------|"
              "|Abobus Amogusov|1        |4.25    |3 items|"
              "|---------------|---------|--------|-------|"
              "|Valentin Dyadka|Antihype |5       |Kremlin|"
              "|---------------|---------|--------|-------|"
              "|Andrei Zamai   |President|5.000000|null   |"
              "|---------------|---------|--------|-------|"
              "|Dirty Monk     |Beast    |1.000000|2 items|"
              "|---------------|---------|--------|-------|");
}