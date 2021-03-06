# COMPETITIVE PROGRAMMING SCRIPTS (C++)

## What is this?

This project provides a set of tools for testing the correctness of solutions in coding competitions. Because scripts are all command-line interface (CLI), the project is independent of text editors/ IDEs. [vscode](https://code.visualstudio.com/) is the recommended text editors.

This project is in the early stage of development, so there is a lot of room for improvement. Nevertheless, it is mature enough for casual coding competition.

## Install

### Requirements:

0. `zsh`
1. `java`
2. [jq](https://www.archlinux.org/packages/community/x86_64/jq/)
3. [optional] [clang](https://www.archlinux.org/packages/extra/x86_64/clang/)
4. [optional] [dev] [nlohmann-json] (https://www.archlinux.org/packages/community/any/nlohmann-json/files/)

### Step by step installation (with vscode)

1. Clone the repo. Note that the `<clone path>` is path to your repo folders
2. Export the path to the directory contains `project_config` to `CPS_PATH`. This repo, for example, we can add `export CPS_PATH="<clone path>/competitive_programming/cps_scripts/` to `.zshrc` because `project_config` is in `cps_scripts`.
3. Open the repo in `vscode`. For example, `code <clone path>`. (open workspace if prompted)
4. Edit `cps_scripts/project_config/` file (folder paths, cpp compiler flags)
5. If you want to use precompiled header, run `gen.sh` in `cps_scripts/precompiled/`
6. Add keyboard shortcut (as below)
7. Create new task and start solving problems.

## Concept

1. Each problem has its **own** folder, which can contains files like: `solution.cpp`, `checker.cpp`, `gen.cpp`.
2. Every configuration (including test cases) is stored in a single `config.json` file.

### Procedure to test a program

1. Compile every necessary file. (Only compile modified files).
2. Test the program in sample test case.
3. Generate more tests
4. Test on newly generated tests.

### Project Configuration

Here is an example project configuration (for this repo, it's in `cps_scripts` folder). This file should named `project_config` and place directly
on the top level the `CPS_PATH` folder. Make sure that there `main.sh` in your `CPS_PATH`. Also all the path must be in absolute form.

Sample Configuration:

```
TASK_PATH=/home/cunbidun/competitive_programming/task/
CACHE_PATH=/home/cunbidun/competitive_programming/cache/
OUTPUT_PATH=/home/cunbidun/competitive_programming/output/
TEMPLATE_PATH=/home/cunbidun/competitive_programming/template/
ARCHIVE_PATH=/home/cunbidun/competitive_programming/archive/
SCRIPT_PATH=/home/cunbidun/competitive_programming/cps_scripts/
FRONTEND_PATH=/home/cunbidun/competitive_programming/cps_scripts/frontend/Test.jar
PRECOMPILED_HEADER_PATH=/home/cunbidun/competitive_programming/cps_scripts/precompiled/
USE_PRECOMPILED_HEADER=1

CPP_DEBUG_FLAG=(-DLOCAL -Wall -Wshadow -std=c++17 -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG)
CPP_COMPILE_FLAG=(-DLOCAL -static -O2 -std=c++17)

USE_CACHE=1
```

| Num | Attribute                 | Type     | Description                                                                                          | Default value                                                                                     |
| --- | ------------------------- | -------- | ---------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| 1   | `TASK_PATH`               | `string` | Directory for storing current task, make sure that the `libs` folder are also in `TASK_PATH`         | `""`                                                                                              |
| 2   | `CACHE_PATH`              | `string` | Cache directory for speeding up compile time (don't recompile file with the same content)            | `""`                                                                                              |
| 3   | `OUTPUT_PATH`             | `string` | Compiled solution will be copy to this directory (so you know where to look for file for submission) | `""`                                                                                              |
| 4   | `TEMPLATE_PATH`           | `string` | Directory for storing template (check the repo `template` folder for more info)                      | `""`                                                                                              |
| 5   | `ARCHIVE_PATH`            | `string` | Directory for archiving completed task (check the repo `archive` folder for more info)               | `""`                                                                                              |
| 6   | `SCRIPT_PATH`             | `string` | Directory for storing all the scripts for this plugin                                                | `""`                                                                                              |
| 7   | `FRONTEND_PATH`           | `string` | Executable frontend to edit task `config.json`                                                       | Ugly java UI                                                                                      |
| 8   | `PRECOMPILED_HEADER_PATH` | `string` | Where precompiled headers generated and stored                                                       |                                                                                                   |
| 9   | `CPP_DEBUG_FLAG`          | `list`   | Cpp debug flag                                                                                       | `(-DLOCAL -Wall -Wshadow -std=c++17 -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG)` |
| 10  | `CPP_COMPILE_FLAG`        | `list`   | Cpp normal complier flag                                                                             | `(-DLOCAL -static -O2 -std=c++17)`                                                                |
| 11  | `USE_CACHE`               | `int`    | Enable cache                                                                                         | `1`                                                                                               |

### Task Configuration

Here is an example: problem [E. Trees of Tranquillity](https://codeforces.com/contest/1529/problem/E) has the following configuration:

```
{
  "timeLimit": 3000,
  "tests": [
    {
      "output": "1",
      "input": "1",
      "index": 0,
      "active": true
    },
    {
      "output": "2",
      "input": "2",
      "index": 1,
      "active": true
    }
  ],
  "name": "E. Trees of Tranquillity",
  "group": "Codeforces - Codeforces Round #722 (Div. 2)"
  "truncateLongTest": false,
  "checker": "custom",

  "url": "https://codeforces.com/contest/1529/problem/E",

  "useGeneration": true,
  "numTest": 10,
  "knowGenAns": true,
  "genParameters": "",
  "generatorSeed": "",

  "interactive": false,
  "stopAtWrongAnswer": false,

  "compact": false,
  "hideAcceptedTest": false,
}
```

There are 16 attributes:

| Num  | Attribute           | Type                    | Description                                                                                                                                                                                                                             | Default value   |
| ---- | ------------------- | ----------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------- |
| 1    | `timeLimit`         | `int`                   | Problem's time limit in millisecond: (1000ms = 1s)                                                                                                                                                                                      | `10000`         |
| 2    | `tests`             | `array of test objects` | An array to store test cases, each of them is a json object. For each test, the input field is required, but the output field is optional.                                                                                              | `[]`            |
| 3    | `name`              | `string`                | The name of the problem, usually the task's name or id number.                                                                                                                                                                          | `""`            |
| 4    | `group`             | `string`                | The name of the contest, used for archive.                                                                                                                                                                                              | `""`            |
| 5    | `truncateLongTest`  | `boolean`               | Test cases could be really long, so there is high chance that they will cause performance problem. This option is for truncation the test's content when printing. Truncated test will only print the first and the last 50 characters. | `false`         |
| 6 \* | `checker`           | `string`                | Name of the checker                                                                                                                                                                                                                     | `token_checker` |
| 7    | `url`               | `string`                | The url of the problem. And be used for auto submit                                                                                                                                                                                     | `""`            |
| 8    | `useGeneration`     | `boolean`               | For most of problems, sample cases are not enough. This is a tool for generating more test cases.                                                                                                                                       | `false`         |
| 9    | `numTest`           | `number`                | Number of generated test cases.                                                                                                                                                                                                         | `0`             |
| 10   | `knowGenAns`        | `boolean`               | If we have `slow.cpp` for generating test cases output                                                                                                                                                                                  | `false`         |
| 11   | `genParameters`     | `string`                | Parameters for the generator. Currently unused.                                                                                                                                                                                         | `""`            |
| 12   | `generatorSeed`     | `string`                | Generator seed.                                                                                                                                                                                                                         | `""`            |
| 13   | `interactive`       | `boolean`               | For `interactive` problems.                                                                                                                                                                                                             | `false`         |
| 14   | `stopAtWrongAnswer` | `boolean`               | If this option is set to true, the testing process will stop after encounter a `wrong answer` test cases.                                                                                                                               | `false`         |
| 15   | `compact`           | `boolean`               | Only print the most important information (test results)                                                                                                                                                                                | `true`          |
| 16   | `hideAcceptedTest`  | `boolean`               | Hide accepted test cases information                                                                                                                                                                                                    | `true`          |

Others `checker` included:

1. `double_4`: checking up to 4 decimals digit
2. `double_6`: checking up to 6 decimals digit
3. `double_9`: checking up to 9 decimals digit
4. `custom`: user's custom checker

### Archive Structure

The `archive` folder is for storing completed codes. For example, problem `A - Plus Minus` will be archive at:

`archive` / `AtCoder - AtCoder Regular Contest 104` / `A - Plus Minus` /

Please take a look at the `archive` folder for more information.

### Supported Verdicts

1. `accepted`
2. `wrong answer`
3. `time limited exceed`
4. `runtime error`

### Sample key blind for vscode

1. Start [Competitive Companion](https://github.com/jmerle/competitive-companion) (port 8080): Crtl + Alt + C
2. New Task: Ctrl + Alt + N
3. Archive: Ctrl + Alt + A
4. Task Configuration: Ctrl + Alt + T
5. Compile and Run: Ctrl + Alt + B
6. Compile and Run with DEBUG flag: Ctrl + Alt + E
7. Compile with terminal: Ctrl + Alt + Shift + B

```
[
  {
    "key": "ctrl+alt+b",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${CPS_PATH}/main.sh \"${fileDirname}\"/ 0\u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+e",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${CPS_PATH}/main.sh \"${fileDirname}\"/ 1\u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+shift+b",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${CPS_PATH}/main.sh \"${fileDirname}\"/ 2\u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+t",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${CPS_PATH}/main.sh \"${fileDirname}\"/ 3\u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+a",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${CPS_PATH}/main.sh \"${fileDirname}\"/ 4\u000D"
    },
    "when": "resourceExtname == .cpp"
  },
  {
    "key": "ctrl+alt+n",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "${CPS_PATH}/main.sh \"${fileDirname}\"/ 5\u000D"
    }
  },
  {
    "key": "ctrl+alt+c",
    "command": "workbench.action.terminal.sendSequence",
    "args": {
      "text": "cd ${workspaceFolder}/../CC/ && npm start\u000D"
    }
  },
]
```

## Credits

1. The project is heavily inspired by [Egor Kulikov](https://github.com/EgorKulikov)'s [CHelper](https://github.com/EgorKulikov/idea-chelper).

2. The precompiled header script is [dush1729](https://github.com/dush1729/Speed-Up-GCC-Compile-Time)'s.

3. Checker use `testlib.h`
