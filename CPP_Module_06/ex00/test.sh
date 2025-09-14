#!/bin/bash

TESTS=(
    "a" "0" "42" "42.0f" "3.14" "123.0000000f"
    ".123" "123." "1e10" "1e10f" "nan" "nanf" "inf" "inff" "-inf" "-inff"
    "2147483647" "-2147483648" "2147483648" "-2147483649"
    "1.7976931348623157e+308" "3.4028235e+38f" "9999999999999999.0"
    "abc" "3.14abc" "--42" "+-42" "123f.456" "123e" "42 " " " ""
)

for test in "${TESTS[@]}"; do
    echo "===== TEST: \"$test\" ====="
    valgrind --leak-check=full --track-origins=yes ./ScalarConverter "$test"
    echo
done
