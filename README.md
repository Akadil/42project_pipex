# 42 project - pipex
> Status: finished. 125/125

The purpose of this project is the discovery in detail UNIX mechanism - `pipe`.

## Description
Program needs to handle multiple pipes
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Support `<<` and `>>`, when instead of `file1` is`here_doc`.
```bash
$> cmd1 << LIMITER | cmd2 >> file2

$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```

## Implementation

'''Bash
$> make
'''
