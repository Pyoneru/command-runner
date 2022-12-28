Tool to running shell commands in easier way.
Define commands, name it and run.

To generate config file run:
```shell
cr init
```

Example of cr_config.json
```json
{
    "commands": [
        {
            "command": "cmake --build .",
            "name": "build",
            "shell": "powershell"
        },
        {
             "name": "ls",
             "command": "ls"
        }
    ],
    "default-shell": "powershell"
}

```

Run custom command
```shell
cr ls
```

Output
```shell
|INFO|  SHELL: powershell | COMMAND: ls


    Directory: C:\Users\piotr\Desktop\CommandRunner\cmake-build-debug


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----        28/12/2022     20:41                .cmake
d-----        28/12/2022     21:05                CMakeFiles
d-----        28/12/2022     20:42                Testing
d-----        28/12/2022     20:41                _deps
-a----        28/12/2022     20:41          23550 CMakeCache.txt
-a----        28/12/2022     20:41           2031 cmake_install.cmake
-a----        28/12/2022     21:05        8238080 cr.exe
-a----        28/12/2022     21:03            247 cr_filename.json
-a----        28/12/2022     20:42          13476 Makefile
```