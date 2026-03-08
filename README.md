*This project has been created as part of the 42 curriculum by aalkiz.*

## Description

In this project, you will sort data in a stack using a limited set of instructions, aiming to achieve the lowest possible number of actions. You have at your disposal a set of integer values, 2 stacks named `a` and `b`, and a set of specific instructions to manipulate them. The goal is to calculate and display the shortest sequence of instructions needed to sort the given integers in stack `a` in ascending order.

To achieve maximum efficiency with a minimal number of operations, this project implements the **Turk Algorithm**. This algorithm works by calculating the "cheapest" node to push from stack `a` to stack `b` (sorting them in descending order), and then accurately pushing them back to stack `a` in the correct ascending order.

## Rules & Mechanics

* **Initialization:** Stack `a` contains a random number of unique negative and/or positive integers, while stack `b` is initially empty.
* **Operations:** The sorting is strictly limited to specific operations: pushing (`pa`, `pb`), swapping (`sa`, `sb`, `ss`), rotating (`ra`, `rb`, `rr`), and reverse rotating (`rra`, `rrb`, `rrr`).
* **Error Handling:** In case of errors (e.g., arguments are not integers, exceed integer limits, or contain duplicates), the program cleanly displays "Error" followed by a `\n` on the standard error.

## Instructions

Run `make` at the root of the repository to compile the source files.

Launch the sorting program by passing a list of integers as arguments. The first argument becomes the top of the stack:
`./push_swap 2 1 3 6 5 8`

The program will output the shortest sequence of instructions, separated by a `\n` and nothing else.

## Resources

* **Documentation:** 42 Subject guidelines, algorithm visualizers, and articles detailing the mechanics of the Turk Algorithm.
* **AI Usage:** AI tools were utilized during the development process to brainstorm debugging approaches for complex edge cases and to review code structure for Norminette compliance.
