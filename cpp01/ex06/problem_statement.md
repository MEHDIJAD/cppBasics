# Exercise 06: Harl filter - Problem Statement

## Objective

Implement a program that filters Harl's complaints based on a specified log level. The program should display messages for the given level and all levels considered "above" it in severity.

## Program Details

*   **Executable Name:** `harlFilter`
*   **Input:** The program must accept exactly one command-line argument, which is a string representing a log level. Valid levels are "DEBUG", "INFO", "WARNING", and "ERROR".
*   **Filtering Logic:**
    *   The log levels have a hierarchy: `DEBUG` < `INFO` < `WARNING` < `ERROR`.
    *   If the input level is, for example, "WARNING", the program should display the messages for "WARNING" and "ERROR".
    *   If the input level is "INFO", it should display "INFO", "WARNING", and "ERROR".
*   **Invalid Input Handling:** If the provided command-line argument does not match any of the valid log levels, the program should print a generic message: `[ Probably complaining about insignificant problems ]`.
*   **Mandatory Control Flow:** You **must** use a `switch` statement to implement the filtering logic. This implies using fall-through cases to achieve the "level and above" behavior.
*   **Reusing Harl Class:** You are expected to reuse the `Harl` class (with its `debug`, `info`, `warning`, `error` member functions) from `ex05`.
*   **Files to Turn In:** `Makefile`, `main.cpp`, `Harl.{h, hpp}`, `Harl.cpp`.

## Example Usage

```bash
$> ./harlFilter "WARNING"
[ WARNING]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.
[ERROR]
This is unacceptable! I want to speak to the manager now.

$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```
