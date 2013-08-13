       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 X-REC.
          03 PNTS OCCURS 60 TIMES.
             05 X PIC S9(10).
       01 Y-REC.
          03 Y-PNTS OCCURS 60 TIMES.
             05 Y PIC S9(10).
       01 N PIC 9(10).
       01 I PIC 9(10).
       01 J PIC 9(10).
       01 A PIC S9(10).
       01 B PIC S9(10).
       01 M PIC 9(10).
       01 Z PIC 9(10)V999999.
       01 S      PIC X(10) VALUE ZEROES.

       PROCEDURE DIVISION.
         ACCEPT S
         MOVE S TO N 

         MOVE 1 TO I

         add 1 to N

         perform until I = n
           accept S
           move S to X(I)
           accept S
           move S to Y(I)
           add 1 to I giving I
         end-perform

         move 1 to I
         move 0 to M
         perform until I = n
           move 1 to J
           perform until J = n
                   move X(I) to A
                   subtract X(J) from A
                   multiply A by A giving A
                   move Y(I) to B 
                   subtract Y(J) from B
                   multiply B by B giving B
                   add B to A giving A

                   if A > M
                           move A to M
                   end-if

                   add 1 to J giving J 
           end-perform
           add 1 to I giving I
         end-perform
         compute Z = (M ** .5)
         display Z
         stop run.


