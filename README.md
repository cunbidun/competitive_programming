# COMPETITIVE PROGRAMMING SCRIPTS


## Concept
1. Each problem has its own folder, which can contains files like: `solution.cpp`, `checker.cpp`, `gen.cpp`.
2. Every configuration(include testcases) is stored in a single `config.json` file.

### Procedure to test a program
1. Compile every necessary file. (Only compile modified files).
2. Test the program in sample test case.
3. Generate more tests
4. Test on newly generated tests.

### Task Configuration
Here is an example:
```
{
	"timeLimit": 100000,
	"tests": [],
	"isInteractive": false,
	"name": "",
	"group": "",
	"truncateLongTest": false,
	"useLocalChecker": false,
	"checkerParameters": "",
	"useGeneration": false,
	"printWrongAnswer": false,
	"url": null,
	"numTest": 0,
	"genParameters": "",
	"knowGenAns": false
}
```
There are 10 Configurations:

##### 1. `timeLimit`
Problem's time limit in millisecond: (1000ms = 1s)

##### 2. `tests`
An array to store test cases, each of them is a json object. For each test, the input field is required, but the output field is optional.

##### 3. `name` 
The name of the problem, usually the task's name or id number.

##### 4. `group`
The name of the contest, used for archive.

##### 5. `truncateLongTest`
Test cases could be really long, so there is high chance that they will cause performance problem. So this option is for truncation the test's content when printing. Truncated test will only print the first and the last 50 characters. 

##### 6. `useLocalChecker` 
We have 2 type of checker, `global` and `local`. 

`global` is a generic checker (a `token checker`), that first break 2 output files into tokens, and compares theme one by one.

`local` is an user-defined checker. The output of `local` checker is based on how user compares outputs fiels.

##### 7. `checkerParameters`
Sometimes we need compare 2 double value, and the global can't really help us with that (it only compare 2 tokens for exact match: `1.0000000` and `1.00000` are 2 different value.).

However, implement a custom checker for only this task would not be time efficient. To address this issue, the `checkerParameters` comes in handy. It's a argument for global checker to activate some functionality other than `token checker`. For now, the `global checker` only receive 1 additional argument: the error for double number (for example: `E-9` for `1e-9`).

##### 8. Use Generattion? 

##### 3. Is Interactive?
Not yet ready

##### 9 . Print only Wrong answer
Deprecated

### Archive Structure
`group/name/`

### Key blind 
1. Start CC: Crtl + Alt + C
2. New Task: Ctrl + Alt + N
3. Archive: Ctrl + Alt + A
4. Test Configuration: Ctrl + Alt + E
5. Test Dialog: Ctrl + Alt + T
6. Complie and Run: Ctrl + Alt + B
7. Complie with terminal: Ctrl + Alt + Shift + B
8. Format Code: Ctrl + Alt + L

#### Verdic
1. AC
2. WA
3. TLE
4. RTE
