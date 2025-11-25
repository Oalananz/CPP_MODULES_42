#!/bin/bash

# Configuration
RPN_PROGRAM="./RPN"
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color
TEST_COUNT=0
PASS_COUNT=0

# --- Function to run a standard test (Expected SUCCESS) ---
run_test() {
    TEST_COUNT=$((TEST_COUNT + 1))
    local expression="$1"
    local expected_output="$2"
    local test_name="$3"

    printf "Test %d: %-50s\n" "$TEST_COUNT" "$test_name"
    printf "       Input: '%s'\n" "$expression"

    # Run the program, capture stdout
    output=$($RPN_PROGRAM "$expression" 2>/dev/null)
    
    if [ "$output" == "$expected_output" ]; then
        echo -e "       [${GREEN}PASS${NC}] Expected: $expected_output | Got: $output"
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        echo -e "       [${RED}FAIL${NC}] Expected: $expected_output | Got: $output"
    fi
    echo ""
}

# --- Function to run an error test (ONLY checks for "Error" string) ---
run_error_test() {
    TEST_COUNT=$((TEST_COUNT + 1))
    local expression="$1"
    local test_name="$2"

    printf "Test %d: %-50s\n" "$TEST_COUNT" "$test_name"
    printf "       Input: '%s'\n" "$expression"

    # Run the program, capture ALL output (stdout and stderr)
    output=$($RPN_PROGRAM "$expression" 2>&1)
    
    # Check only for the presence of the word "Error" in the output
    if echo "$output" | grep -q "Error"; then
        echo -e "       [${GREEN}PASS${NC}] 'Error' string detected | Output: $output"
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        echo -e "       [${RED}FAIL${NC}] Expected 'Error' output, but got: '$output'"
    fi
    echo ""
}

# --- New Function for Too Many Arguments Error Test ---
run_too_many_args_test() {
    TEST_COUNT=$((TEST_COUNT + 1))
    local test_name="$1"

    printf "Test %d: %-50s\n" "$TEST_COUNT" "$test_name"
    printf "       Input: '%s' + '%s'\n" "1 2 +" "extra argument"

    # Run the program with MORE THAN ONE argument string
    output=$($RPN_PROGRAM "1 2 +" "extra argument" 2>&1)

    # Check only for the presence of the word "Error" in the output
    if echo "$output" | grep -q "Error"; then
        echo -e "       [${GREEN}PASS${NC}] 'Error' string detected | Output: $output"
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        echo -e "       [${RED}FAIL${NC}] Expected 'Error' output, but got: '$output'"
    fi
    echo ""
}

# ----------------------------------------------------------------------
#                             START TESTS
# ----------------------------------------------------------------------

echo "--- 🟢 Standard Usage Tests (Expected Output) ---------------------"

run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "Provided Example 1"
run_test "7 7 * 7 -" "42" "Provided Example 2"
run_test "1 2 * 2 / 2 * 2 4 - +" "0" "Provided Example 3 (Negative Intermediate)"
run_test "9 1 /" "9" "Simple Division"
run_test "2 3 + 4 *" "20" "Multiple operations"

echo -e "\n--- 🛑 Error Handling Tests (Expected 'Error' Output Only) ----------"

# 1. Command-Line Argument Errors
run_error_test "" "Missing argument"
# **FIXED TEST 7** - Using a dedicated function to pass two arguments
run_too_many_args_test "Too many arguments" 

# 2. Expression Format/Token Errors
run_error_test "(1 + 1)" "Forbidden character (parentheses)"
run_error_test "10 5 +" "Two-digit number (Constraint violation)"
run_error_test "A 5 +" "Invalid character token (A)"

# 3. Stack Logic Errors (During Execution)
run_error_test "+ 1 2" "Insufficient operands (Stack too small at start)"
run_error_test "5 *" "Insufficient operands (Only one operand)"
run_error_test "5 0 /" "Division by zero"

# 4. Final Result Errors
run_error_test "1 2 3 +" "Too many operands remaining (Stack size > 1)"
run_error_test "1 +" "Insufficient operands (Too many operators)"

# ----------------------------------------------------------------------
#                             SUMMARY
# ----------------------------------------------------------------------

echo -e "\n--- SUMMARY ----------------------------------------------------"
if [ "$PASS_COUNT" -eq "$TEST_COUNT" ]; then
    echo -e "${GREEN}ALL $PASS_COUNT/$TEST_COUNT TESTS PASSED!${NC}"
else
    echo -e "${RED}$PASS_COUNT/$TEST_COUNT TESTS PASSED. FIX REMAINING ERRORS.${NC}"
fi