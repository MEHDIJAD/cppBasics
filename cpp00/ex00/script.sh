#!/bin/bash

# Colors
GREEN="\033[0;32m"
BLUE="\033[0;34m"
NC="\033[0m"

# Variables
PROGRAM="./megaphone"
OUTPUT_FILE="file.txt"
EXPECTED_FILE="out.txt"

# Clean the output file before starting
rm -f $OUTPUT_FILE


# --- Test 1 ---
echo -e "\n${GREEN}Running Test 1: shhhhh... I think the students are asleep...${NC}"
echo -e "${BLUE}Expected: SHHHHH... I THINK THE STUDENTS ARE ASLEEP...${NC}"
$PROGRAM "shhhhh... I think the students are asleep..." >> $OUTPUT_FILE

# --- Test 2 ---
echo -e "${GREEN}Running Test 2: Subject's example${NC}"
echo -e "${BLUE}Expected: DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.${NC}"
$PROGRAM "Damnit" " ! " "Sorry students, I thought this thing was off." >> $OUTPUT_FILE

# --- Test 3 ---
# echo -e "\n${GREEN}Running Test 3: Simple test${NC}"
# echo -e "${BLUE}Expected: THISISATEST${NC}"
# $PROGRAM "this" "is" "a" "test" >> $OUTPUT_FILE

# --- No arguments ---
echo -e "${GREEN}Running Test 0: No arguments${NC}"
echo -e "${BLUE}Expected: * LOUD AND UNBEARABLE FEEDBACK NOISE *${NC}"
$PROGRAM >> $OUTPUT_FILE

echo -e "\n${GREEN}Tests finished. Results are in $OUTPUT_FILE${NC}"

diff $OUTPUT_FILE $EXPECTED_FILE
