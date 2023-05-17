# Calculator
____
## Annotation
This application is the GUI of another console application.

Link to the console variation: `https://github.com/Kuznetsov-Artyom/Reverse-Polish-notation.git`
____
## :clipboard:Description:clipboard:
This repository presents an open source desktop application for working with arithmetic expressions.
____
## :wrench:Opportunities:wrench:
* Mathematical operations
    * Binary (`+`, `-`, `*`, `/`, `^`)
    * Unary (`-`)

* Operands
    * Variables
    * Constants

* Error Handling (below is a code snippet)
```cpp
// Enumeration with possible error codes
enum class CodeError
{
	DEFAULT = 0,
	EMPTY_EXPRESSION = -1,
	TYPE_UNDEFINED = -2,
	INVALID_PARENTHESES = -3,
	NO_OPERATOR = -4,
	NO_OPERAND = -5,
	EMPTY_PARENTHESES = -6,
	ZERO_DIVISION = -7,
};
```
____
## UI
![calculator](https://github.com/Kuznetsov-Artyom/Calculator/assets/110616662/4721cc67-ea50-4506-b738-d8a25829eb68)
____
## Link for cloning the repository:octocat:
`git clone https://github.com/Kuznetsov-Artyom/Calculator.git`






