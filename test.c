//# Test 1: Basic command with input and output files
echo -e "Hello\nWorld\nHello World" > infile

./pipex infile "cat" "cat" outfile
cat outfile  # Expected output: Hello\nWorld\nHello World
< infile cat | cat > oufile_bash

//# Test 2: Basic command with wc -l:
echo -e "Hello\nWorld\nHello World" > infile

./pipex infile "cat" "wc -l" outfile
cat outfile  # Expected output: 3
< infile cat | wc -l > outfile_bash

//# Test 3: Basic command with grep:
echo -e "Hello\nWorld\nHello World" > infile

./pipex infile "cat" "grep Hello" outfile
cat outfile  # Expected output: Hello\nHello World
< infile cat | grep "Hello" > outfile_bash

//# Test 4: Non-existent command:
echo -e "Hello\nWorld\nHello World" > infile
./pipex infile "nonexistentcommand" "wc -l" outfile
# Expected output: error message about nonexistentcommand
< infile nonexistentcommand | wc -l > outfile_bash

//# Test 5: Permission denied on infile:
echo -e "Hello\nWorld\nHello World" > infile
chmod 000 infile
./pipex infile "cat" "wc -l" outfile
# Expected output: error message about permission denied
chmod 777 infile
chmod 000 infile
< infile cat | wc -l > outfile_bash
chmod 777 infile

//# Test 6: Permission denied on outfile:
echo -e "Hello\nWorld\nHello World" > infile
touch outfile
chmod 000 outfile
./pipex infile "cat" "wc -l" outfile
# Expected output: error message about permission denied
chmod 777 outfile
chmod 000 outfile
< infile cat | wc -l > outfile
chmod 000 outfile 

//# Test 7: Using ls -l and wc -l:
./pipex /dev/null "ls -l" "wc -l" outfile
cat outfile  # Expected output: number of lines in 'ls -l' output
< /dev/null ls -l | wc -l > outfile_bash

//# Test 8: Empty input file:
touch infile
./pipex infile "cat" "wc -l" outfile
cat outfile  # Expected output: 0
< infile cat | wc -l > outfile_bash
cat outfile_bash

//# Test 9: Long command with multiple arguments:
echo -e "Hello\nWorld\nHello World" > infile
./pipex infile "cat -e" "wc -l" outfile
cat outfile  # Expected output: 3
< infile cat -e | wc -l > outfile_bash

//# Test 10: Handling relative paths:
echo -e "Hello\nWorld\nHello World" > infile
./pipex infile "/bin/cat" "/usr/bin/wc -l" outfile
cat outfile  # Expected output: 3
< infile /bin/cat | /usr/bin/wc -l > outfile_bash

//# Test 11: Commands with no output (e.g., true):
echo -e "Hello\nWorld\nHello World" > infile
./pipex infile "true" "wc -l" outfile
cat outfile  # Expected output: 0 (since 'true' produces no output)
< infile true | wc -l > outfile_bash

//# Test 12: Piping a non-executable file:
echo "Hello World" > infile
touch not_executable_file
./pipex infile "./not_executable_file" "wc -l" outfile
# Expected output: error message about not executable
< infile ./not_executable_file | wc -l > outfile



rm -f infile outfile not_executable_file outfile_bash 

valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all ./pipex
valgrind  --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --leak-resolution=high --trace-children=yes ./pipex infile.txt "sort" "head -7" outfile.txt

