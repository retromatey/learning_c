# `logfind` Specification

I want a tool called `logfind` that lets me search through log files for text.
This tool is a specialized version of another tool called `grep`, but designed
only for log files on a system.  The idea is that I can type: 

```
logfind stuff
```

And, it will search all the common places that log files are stored, and print
out every file that has the word "stuff" in it.

The `logfind` tool should have these basic features:

1. This tool takes any sequence of words and assumes I mean "and" for them.  So
   `logfind stuff things blah` will find all files that have `stuff` _and_
   `things` _and_ `blah` in them.
1. It takes an optional argument of `-o` if the parameters are meant to be `or`
   logic.
1. It loads the list of allowed log files from `~/.logfind`.
1. The list of names can be anything that the `glob` function allows.  Refer to
   `man 3 glob` to see how this works.  Start out with a list of exact files,
   and then add the `glob` functionality.
1. You should output the matching lines as you scan, and try to match them as
   fast a possible.
