# COMPETITIVE PROGRAMMING SCRIPTS (C++)

## What is this?

This project provides a set of tools for testing the correctness of solutions in coding competitions. Because scripts are all command-line interface (CLI), the project is independent of text editors/ IDEs. [vscode](https://code.visualstudio.com/) is the recommended text editors.

This project is in the early stage of development, so there is a lot of room for improvement. Nevertheless, it is mature enough for any coding competition.

## Install

### Requirements:

1. java
2. [jq](https://www.archlinux.org/packages/community/x86_64/jq/)
3. [optional] [clang](https://www.archlinux.org/packages/extra/x86_64/clang/)
4. [optional] [astyle](https://www.archlinux.org/packages/community/x86_64/astyle/)
5. [optional] [dev] [nlohmann-json] (https://www.archlinux.org/packages/community/any/nlohmann-json/files/)

### Step by step installation (with vscode)

1. clone the repo
2. `cd` to the directory
3. `code .` to start vscode.
4. open workspace if prompted.
5. add keyboard shortcut (as below)
6. precompiled header (`cd Script/precompiled/ && ./gen.sh`)
7. create new task and start solving problems.

## Concept

1. Each problem has its own folder, which can contains files like: `solution.cpp`, `checker.cpp`, `gen.cpp`.
2. Every configuration (including testcases) is stored in a single `config.json` file.

### Procedure to test a program

1. Compile every necessary file. (Only compile modified files).
2. Test the program in sample test case.
3. Generate more tests
4. Test on newly generated tests.

### Task Configuration

Here is an example: problem [B. Jumps](https://codeforces.com/contest/1455/problem/B) has the following configuration:

```
{
  "numTest": 0,
  "genParameters": "",
  "isInteractive": false,
  "useGeneration": false,
  "checker": "token_checker",
  "knowGenAns": false,
  "url": "https://codeforces.com/contest/1455/problem/B",
  "timeLimit": 1000,
  "tests": [
    {
      "output": "1\n3\n2\n3\n4\n",
      "input": "5\n1\n2\n3\n4\n5\n",
      "index": 0,
      "active": true
    },
    { "output": "4", "input": "1\n5", "index": 1, "active": true },
    { "output": "4", "input": "1\n10", "index": 2, "active": true },
    { "output": null, "input": "1\n11", "index": 3, "active": true }
  ],
  "stopAtWrongAnswer": false,
  "name": "B. Jumps",
  "truncateLongTest": false,
  "useLocalChecker": false,
  "group": "Codeforces - Educational Codeforces Round 99 (Rated for Div. 2)"
}
```

There are 10 configurations:

##### 1. `timeLimit` (int)

Problem's time limit in millisecond: (1000ms = 1s)

##### 2. `tests` (array of test objects)

An array to store test cases, each of them is a json object. For each test, the input field is required, but the output field is optional.

##### 3. `name` (string)

The name of the problem, usually the task's name or id number.

##### 4. `group` (string)

The name of the contest, used for archive.

##### 5. `truncateLongTest` (boolean)

Test cases could be really long, so there is high chance that they will cause performance problem. This option is for truncation the test's content when printing. Truncated test will only print the first and the last 50 characters.

##### 6. `checker` (string)

Name of the checker (default is `token_checker`)

##### 8. `useGeneration` (boolean)

For most of problems, sample cases are not enough. This is a tool for generater more testcase.

##### 9. `isInteractive` (boolean)

For `interactive` problems. Not yet ready.

##### 10. `stopAtWrongAnswer` (boolean)

If this option is set to true, the testing process will stop after encounter a `wrong answer` testcase.

### Archive Structure

The Archive folder is on the same level with `Script` folder. For example, problem `A - Plus Minus` will be archive at:

`Archive` / `AtCoder - AtCoder Regular Contest 104` / `A - Plus Minus` /

Please take a look at the `Archive` folder for more information.

### Supported Verdics

1. `accepted`
2. `wrong answer`
3. `time limited exceed`
4. `runtime error`

### Sample key blind for vscode

1. Start [Competitive Companion](https://github.com/jmerle/competitive-companion) (port 8080): Crtl + Alt + C
2. New Task: Ctrl + Alt + N
3. Archive: Ctrl + Alt + A
4. Task Configuration: Ctrl + Alt + E
5. Test Dialog: Ctrl + Alt + T
6. Complie and Run: Ctrl + Alt + B
7. Complie with terminal: Ctrl + Alt + Shift + B
8. Format Code: Ctrl + Alt + L

```
[
  {
    "key": "ctrl+alt+l",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "astyle -n --add-braces -s2 \"${file}\" && clang-format -i -style=\"{ColumnLimit: 100, AllowShortBlocksOnASingleLine: false}\" \"${file}\" \u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+b",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${workspaceFolder}/../Script/run.sh \"${fileDirname}\"/ \u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+shift+b",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${workspaceFolder}/../Script/run_with_terminal.sh \"${fileDirname}\"/ \u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+n",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${workspaceFolder}/../Script/new.sh ${workspaceFolder}/../Task\u000D"
    }
  },
  {
    "key": "ctrl+alt+e",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${workspaceFolder}/../Script/config.sh \"${fileDirname}\"/ \u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+t",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${workspaceFolder}/../Script/test_dialog.sh \"${fileDirname}\"/ \u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+c",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "cd ${workspaceFolder}/../CC/ && npm start\u000D"
    }
  },
  {
    "key": "ctrl+alt+a",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${workspaceFolder}/../Script/archive.sh \"${fileDirname}\"/ \u000D"
    },
    "when": "resourceExtname == .cpp"
  }
]
```

## Todos:

1. Add option for only print tests' status. Something like:

```
Test #0: wrong answer
Test #1: accepted
```

2. precomiled problem
3. slow solution independent of use generation
## Credits

1. The project is heavily inspired by [Egor Kulikov](https://github.com/EgorKulikov)'s [CHelper](https://github.com/EgorKulikov/idea-chelper).

2. The precompiled header script is [dush1729](https://github.com/dush1729/Speed-Up-GCC-Compile-Time)'s.

3. Checker use `testlib.h`
