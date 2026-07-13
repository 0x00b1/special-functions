# CLAUDE.md

## Filesystem scope

Do not read, list, search, glob, edit, or otherwise access any file or directory outside this project's working directory (the directory containing this CLAUDE.md). This restriction applies to all tools, including shell commands (`cat`, `ls`, `find`, `grep`, etc.), file tools, and any subagents you spawn — pass this restriction along to them.

Specifically:

- Never use absolute paths that resolve outside the working directory (e.g., `~`, `/tmp`, `/usr`, `/etc`, other home-directory folders, or sibling repositories).
- Never traverse upward out of the working directory (e.g., `..` paths that escape it).
- Never follow symlinks to locations outside the working directory.
- If a task appears to require reading or writing a file outside the working directory, stop and ask the user instead of doing it.
