# Command for solve a puzzle
solver.exe \<solutions\> \<puzzle\>
 - solutions
    use a positive number to specify how many solutions you want,
    use a *n* or *N* if you do not sure about it and want as many as possiable
 - puzzle
    a string with 1-9 for filled cell, and any other for character for empty cell.

Command example:
 - for a puzzle like:

        1 2 3 | 4 5 6 | 0 0 0
        0 0 0 | 0 0 0 | 0 0 0
        0 0 0 | 0 0 0 | 0 0 0
        ---------------------
        0 0 0 | 0 0 0 | 0 0 0
        0 0 0 | 0 0 0 | 0 0 0
        0 0 0 | 0 0 0 | 0 0 0
        ---------------------
        0 0 0 | 0 0 0 | 0 0 0
        0 0 0 | 0 0 0 | 0 0 0
        0 0 0 | 0 0 0 | 0 0 0
    
 - you could use below command for two solutions:
    > solver.exe 2 123456000000000000000000000000000000000000000000000000000000000000000000000000000



