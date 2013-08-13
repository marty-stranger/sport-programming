       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 S      PIC X(10) VALUE ZEROES.
       01 A        PIC 9(10).
       01 B        PIC 9(10).
       01 C        PIC 9(10).
       01 D        PIC 9(10).
       01 WS-COUNTER    PIC 9(9)  VALUE ZEROES.
       01 res pic X(64).

       PROCEDURE DIVISION.
         ACCEPT S
         MOVE S TO A

         MOVE 1048576 TO B

         MOVE A TO C
         PERFORM UNTIL B <= A
           DIVIDE B BY 2 GIVING B REMAINDER D
         END-PERFORM
         PERFORM UNTIL B = 0
           DIVIDE A BY B GIVING C REMAINDER A
           if C = 0
             display "0" with no advancing
           else
             display "1" with no advancing
           end-if
           DIVIDE B BY 2 GIVING B REMAINDER D
         END-PERFORM
         STOP RUN.


