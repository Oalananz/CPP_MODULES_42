#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Test counters
TOTAL_TESTS=0
PASSED_TESTS=0

# Function to verify if output is sorted
verify_sorted() {
    local output="$1"
    local sorted_line=$(echo "$output" | grep "After:")
    if [ -z "$sorted_line" ]; then
        echo -e "${RED}✗ FAIL${NC} - No sorted output"
        return 1
    fi
    local sorted_nums=$(echo "$sorted_line" | sed 's/After: *//' | tr ' ' '\n' | grep -E '^[0-9]+$')
    local is_sorted=$(echo "$sorted_nums" | awk 'NR>1 && $1<prev{exit 1} {prev=$1}' && echo "YES" || echo "NO")
    if [ "$is_sorted" = "YES" ]; then
        echo -e "${GREEN}✓ PASS${NC} - Correctly sorted"
        return 0
    else
        echo -e "${RED}✗ FAIL${NC} - Not sorted"
        return 1
    fi
}

# Function to verify error output
verify_error() {
    local output="$1"
    if echo "$output" | grep -q "Error"; then
        echo -e "${GREEN}✓ PASS${NC} - Error detected"
        return 0
    else
        echo -e "${RED}✗ FAIL${NC} - No error"
        return 1
    fi
}

# Check if specific test number is provided
if [ $# -eq 1 ]; then
    TEST_NUM=$1
else
    TEST_NUM="all"
fi

if [ "$TEST_NUM" = "all" ]; then
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}   PmergeMe Test Suite${NC}"
    echo -e "${BLUE}========================================${NC}"
    echo ""
fi

# Test 1: Basic example from subject
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "1" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 1: Basic example (3 5 9 7 4)${NC}"
    echo "Input: 3 5 9 7 4"
    OUTPUT=$(./PmergeMe 3 5 9 7 4 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 2: Error - negative number
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "2" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 2: Error case - negative number${NC}"
    echo "Input: -1 2"
    OUTPUT=$(./PmergeMe "-1" "2" 2>&1)
    echo "$OUTPUT"
    verify_error "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 3: Error - no arguments
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "3" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 3: Error case - no arguments${NC}"
    echo "Input: (no arguments)"
    OUTPUT=$(./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_error "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 4: Error - non-numeric input
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "4" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 4: Error case - non-numeric input${NC}"
    echo "Input: abc"
    OUTPUT=$(./PmergeMe abc 2>&1)
    echo "$OUTPUT"
    verify_error "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 5: Error - invalid character in number
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "5" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 5: Error case - invalid character${NC}"
    echo "Input: 1 2 3+"
    OUTPUT=$(./PmergeMe 1 2 3+ 2>&1)
    echo "$OUTPUT"
    verify_error "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 6: Single element
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "6" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 6: Single element${NC}"
    echo "Input: 42"
    OUTPUT=$(./PmergeMe 42 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 7: Two elements
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "7" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 7: Two elements${NC}"
    echo "Input: 5 3"
    OUTPUT=$(./PmergeMe 5 3 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 8: Already sorted
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "8" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 8: Already sorted (1 2 3 4 5)${NC}"
    echo "Input: 1 2 3 4 5"
    OUTPUT=$(./PmergeMe 1 2 3 4 5 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 9: Reverse sorted
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "9" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 9: Reverse sorted (10 9 8 7 6 5 4 3 2 1)${NC}"
    echo "Input: 10 9 8 7 6 5 4 3 2 1"
    OUTPUT=$(./PmergeMe 10 9 8 7 6 5 4 3 2 1 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 10: Duplicates
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "10" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 10: With duplicates (5 3 5 1 3 9 5)${NC}"
    echo "Input: 5 3 5 1 3 9 5"
    OUTPUT=$(./PmergeMe 5 3 5 1 3 9 5 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 11: 15 elements (all displayed)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "11" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 11: 15 elements${NC}"
    echo "Input: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"
    OUTPUT=$(./PmergeMe 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 12: 100 random elements
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "12" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 12: 100 random elements${NC}"
    RAND_INPUT=$(seq 1 100 | shuf | tr '\n' ' ')
    echo "Input: $RAND_INPUT"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 13: 500 random elements
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "13" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 13: 500 random elements${NC}"
    RAND_INPUT=$(seq 1 500 | shuf | tr '\n' ' ')
    echo "Input: (500 random numbers from 1 to 500)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 14: 1000 random elements
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "14" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 14: 1000 random elements${NC}"
    RAND_INPUT=$(seq 1 1000 | shuf | tr '\n' ' ')
    echo "Input: (1000 random numbers from 1 to 1000)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 15: 3000 random elements (required by subject)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "15" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 15: 3000 random elements (required)${NC}"
    RAND_INPUT=$(seq 1 3000 | shuf | tr '\n' ' ')
    echo "Input: (3000 random numbers from 1 to 3000)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 16: 3000 random from large range (subject example with shuf)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "16" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 16: 3000 random from 1-100000 (subject example)${NC}"
    RAND_INPUT=$(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
    echo "Input: (3000 random numbers from 1 to 100000)"
    OUTPUT=$(./PmergeMe $RAND_INPUT 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 17: 5000 random elements (stress test)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "17" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 17: 5000 random elements (stress test)${NC}"
    RAND_INPUT=$(seq 1 5000 | shuf | tr '\n' ' ')
    echo "Input: (5000 random numbers from 1 to 5000)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 18: Random large numbers (up to 2147483647)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "18" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 18: Random large numbers${NC}"
    RAND_INPUT=$(shuf -i 1000000-2147483647 -n 50 | tr '\n' ' ')
    echo "Input: (50 random large numbers)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 19: Random small dataset (20 elements)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "19" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 19: 20 random elements${NC}"
    RAND_INPUT=$(seq 1 20 | shuf | tr '\n' ' ')
    echo "Input: $RAND_INPUT"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 20: Random medium dataset (250 elements)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "20" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 20: 250 random elements${NC}"
    RAND_INPUT=$(seq 1 250 | shuf | tr '\n' ' ')
    echo "Input: (250 random numbers from 1 to 250)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 21: Random sparse numbers (100 numbers from large range)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "21" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 21: Sparse random numbers${NC}"
    RAND_INPUT=$(shuf -i 1-100000 -n 100 | tr '\n' ' ')
    echo "Input: (100 random numbers from 1 to 100000)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 22: Random odd number count (101 elements)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "22" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 22: 101 random elements (odd count)${NC}"
    RAND_INPUT=$(seq 1 101 | shuf | tr '\n' ' ')
    echo "Input: (101 random numbers from 1 to 101)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 23: Random even number count (200 elements)
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "23" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 23: 200 random elements (even count)${NC}"
    RAND_INPUT=$(seq 1 200 | shuf | tr '\n' ' ')
    echo "Input: (200 random numbers from 1 to 200)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 24: Random with duplicates
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "24" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 24: Random with many duplicates${NC}"
    RAND_INPUT=$(shuf -i 1-20 -n 100 -r | tr '\n' ' ')
    echo "Input: (100 random numbers from 1 to 20 with duplicates)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 25: 2000 random elements
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "25" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 25: 2000 random elements${NC}"
    RAND_INPUT=$(seq 1 2000 | shuf | tr '\n' ' ')
    echo "Input: (2000 random numbers from 1 to 2000)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

# Test 26: 4000 random elements
if [ "$TEST_NUM" = "all" ] || [ "$TEST_NUM" = "26" ]; then
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "${YELLOW}Test 26: 4000 random elements${NC}"
    RAND_INPUT=$(seq 1 4000 | shuf | tr '\n' ' ')
    echo "Input: (4000 random numbers from 1 to 4000)"
    OUTPUT=$(echo $RAND_INPUT | xargs ./PmergeMe 2>&1)
    echo "$OUTPUT"
    verify_sorted "$OUTPUT" && PASSED_TESTS=$((PASSED_TESTS + 1))
    echo ""
fi

if [ "$TEST_NUM" = "all" ]; then
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}   Test Summary${NC}"
    echo -e "${BLUE}========================================${NC}"
    echo -e "Total Tests:  ${BLUE}$TOTAL_TESTS${NC}"
    echo -e "Passed Tests: ${GREEN}$PASSED_TESTS${NC}"
    echo -e "Failed Tests: ${RED}$((TOTAL_TESTS - PASSED_TESTS))${NC}"
    echo ""
    if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
        echo -e "${GREEN}ALL TESTS PASSED! ✓${NC}"
    else
        echo -e "${RED}SOME TESTS FAILED! ✗${NC}"
    fi
    echo -e "${BLUE}========================================${NC}"
fi
