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
2. Every configuration(include testcases) is stored in a single `config.json` file.

### Procedure to test a program

1. Compile every necessary file. (Only compile modified files).
2. Test the program in sample test case.
3. Generate more tests
4. Test on newly generated tests.

### Task Configuration

Here is an example: problem [A - Plus Minus](https://atcoder.jp/contests/arc104/tasks/arc104_a) has the configuration:

```
{
  "tests": [
    { "input": "2 -2\n", "output": "0 2\n", "index": 0, "active": true },
    { "input": "3 1\n", "output": "2 1\n", "index": 1, "active": true }
  ],
  "name": "A - Plus Minus",
  "group": "AtCoder - AtCoder Regular Contest 104",
  "isInteractive": false,
  "timeLimit": 2000,
  "truncateLongTest": false,
  "checkerParameters": "",
  "useGeneration": false,
  "printWrongAnswer": false,
  "useLocalChecker": false,
  "url": "https://atcoder.jp/contests/arc104/tasks/arc104_a",
  "numTest": 0,
  "genParameters": null,
  "knowGenAns": false
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

##### 6. `useLocalChecker` (boolean)

We have 2 type of checker, `global` and `local`.

`global` is a generic checker (a `token checker`). It determine the correctness of solution by first break 2 output files into tokens, and then, compares them one by one.

`local` is an user-defined checker. The output of `local` checker is based on how users compare output files.

##### 7. `checkerParameters` (string)

Sometimes we need compare 2 double value, and the global can't really help us with that (it will only compare 2 tokens for exact match: `1.0000000` and `1.00000` are 2 different value).

However, implement a custom checker for only this task would not be time efficient. To address this issue, the `checkerParameters` comes in handy. It's a argument for global checker to activate some functionality other than `token checker`. For now, the `global checker` only receive 1 additional argument: the error for double number (for example: `D9` for `1e-9`).

##### 8. `useGeneration` (boolean)

For most of problems, sample cases are not enough. This is a tool for generater more testcase.

##### 3. `isInteractive` (boolean)

For `interactive` problems. Not yet ready.

##### 9. `printWrongAnswer` (boolean)

If this option is set to true, the testing process will stop after encounter a `wrong answer` testcase.

Deprecated

### Archive Structure

The Archive folder is on the same level with `Script` folder. The `A - Plus Minus` above will be archive at:

`Archive` / `AtCoder - AtCoder Regular Contest 104` / `A - Plus Minus`

Please take a look at the `Archive` folder for more information.

### Supported Verdics

1. ok
2. wrong answer
3. time limited exceed
4. runtime error

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

## Credits

1. The project is heavily inspired by [Egor Kulikov](https://github.com/EgorKulikov)'s [CHelper](https://github.com/EgorKulikov/idea-chelper).

2. The precompiled header script is [dush1729](https://github.com/dush1729/Speed-Up-GCC-Compile-Time)'s.
