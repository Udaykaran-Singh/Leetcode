# [Check Redundant Brackets](https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1)
## Medium
Given a string of balanced expression s, check if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets.Note:&nbsp;Expression may contain + , - ,&nbsp;*, and / operators. Given expression is&nbsp;valid&nbsp;and there are&nbsp;no white&nbsp;spaces present.Examples:
Input: s = "((a+b))"
Output: true 
Explanation: ((a+b)) can reduced to (a+b).
Input: s = "(a+(b)/c)"
Output: true
Explanation: (a+(b)/c) can reduced to (a+b/c) because b is surrounded by () which is redundant.

Input: s = "(a+b+(c+d))"
Output: false
Explanation:(a+b+(c+d)) doesn't have any redundant or multiple brackets.
Constraints:1 ≤ |s| ≤105