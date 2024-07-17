# Advanced Programming in the UNIX Environment: Week 01 - Unix Basics

## Notes
### 1.0 Unix Basics
#### 1.1 - System calls vs Library functions
- System calls
A system call is a request for the operating system to do something on behalf of the user's program.

- Library functions
A library function is a function that is part of a library of functions that can be used by multiple programs.

#### 1.2 File descriptors
They are a small non-negative integer that refers to an open file.

- A directory is a file that contains a list of files.
- `stdin`, `stdout`, and `stderr` are file descriptors.

#### 1.3 Unix pipes
A pipe is a form of redirection that is used in UNIX to send the stdout of one command to the stdin of another command.

#### 1.4 Time
The time `time_t` is a data type that is used to store the time in seconds since the Unix epoch.

Initially defined as a 32-bit signed integer, it has been extended to 64 bits in most modern systems (otherwise we would overflow in 2038).

### 2.0 Program design
- Small is beautiful.
- Make each program do one thing well.
- Build a prototype as soon as possible.
- Choose portability over efficiency.
- Store data in flat text files.
- Use software leverage to your advantage.
- Use shell scripts to increase leverage and portability.
- Avoid captive user interfaces.
- Make every program a filter.

### Homework
- [ ] Bookmar pubs.opengroup.org
- [ ] Get a good understanding of the programs described in the lecture.
