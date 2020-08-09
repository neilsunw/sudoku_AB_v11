/* Neil Pierson - June 11, 2016
 *
 * puzzles.h
 *
 * BSD 3-Clause License
 * 
 * Copyright (c) 2020, Neil Pierson
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * Solve Sudoku Puzzles
 *  http://www.sudoku.com/
 *
 * Complete a 9x9 grid so that every row, column and 3x3 box contains
 * the numbers 1 through 9 (no repeats).
 *
 * Input puzzle can be defined by 9 long (32bit) integers (36 bytes, best compact form, more efficient than 9 nibbles)
 * Each integer should be 9 numbers long. Use 0's for empty/unknown numbers.
 * (drop leading 0s to avoid octal interpretation)
 *
 * Example:  12345060,         0, 450600037,   8030400,   7090500,   5010600, 590002041,         0,  30459780
 *
 * defines input puzzle:
 *
 *          +-----+-----+-----+
 *          |  1 2|3 4 5|  6  |
 *          |     |     |     |
 *          |4 5  |6    |  3 7|
 *          +-----+-----+-----+
 *          |    8|  3  |4    |
 *          |    7|  9  |5    |
 *          |    5|  1  |6    |
 *          +-----+-----+-----+
 *          |5 9  |    2|  4 1|
 *          |     |     |     |
 *          |  3  |4 5 9|7 8  |
 *          |-----+-----+-----+
 *
 * Puzzles from "The Big Book of Su Doku #1" by Mark Huckvale (2005)
 * Published by Newmarket Press, ISBN 1-55704-703-0
 * https://us.nicebooks.com/book/17516304
 */

#define PUZZLES    45 // total number of puzzles
#define PZ_MEDIUM  15 // first Medium puzzle (index)
#define PZ_HARD    25 // first   Hard puzzle (index)
#define PZ_CUSTOM 255 // custom puzzle, loaded from Serial input

const long puzzle_input[] PROGMEM = { // 36 bytes per puzzle, decimal constants (drop leading 0s)
  // Easy
  480000701,  25000000, 930540000, 704000000, 350409080,       400,   1706308, 860200510,     15049, // pg.21
  739462010,  80700300,   2300000,  15090080, 900010000,   4006079,  73000090, 100673250, 400028000, // pg.22
       7038,     50002,   3900040, 100400009, 630009800, 840000567,  25390400,   8010000,   1024000, // pg.23
      40000,   4005003,  90108000,   9020580, 500400060, 617803209, 140060090,    704030,  82091400, // pg.24
    5900800, 470008000,    673540, 800000000, 213085060,      7000, 508130600,  90020080,  20000910, // pg.25
  800000000, 740800000,   2064097,  86010032, 200580746,  90300508,        60,  30050000,    630089, // pg.26
  300000000, 608473025, 502006100, 900050842, 400090700, 237108000,   3720094, 790000000,        50, // pg.27
    6089000, 752341000,        23,    420300, 100000870,   5910000,  73100008,   1090004,   8005090, // pg.28
  517968000, 900703000,    210000,   3000000, 480000900,  90076003,  20000890, 800000700, 306805120, // pg.29
   10020008,   9000000, 702300549,  50630000,  90004100,  63008000,   1006000, 600972013,       400, // pg.30
  // Moderate
      80001,   7009024,    601000,  51000800,     27400, 400095003, 710000005, 865000032,  24000000, // pg.31
         20,         6,  74000310,        59, 480195000, 209304070, 806403200,     82001,   5700000, // pg.32
  805000000,   7000028,  19200700,  42000003, 908000000,      9270,  90510060,    960450, 600402807, // pg.33
        701, 602000380, 310002005,   5741009,  60009800,  30058100,   4930000,   3010500,    800000, // pg.34
          0, 500214009, 269000000,     80000,  18060700,   5070628,    620000, 180040300,  90508007, // pg.35
  // Tricky (medium)
    7000000, 300070085, 129000000, 400219057,  80400900, 200007461,         8,  40680093, 900000004, // pg.71
   98007300, 100083026,   6000900, 607305004,  12804000,   3760000,    500703, 369000040,  51000000, // pg.72
    9016500,   5900000, 700300860, 500602090,   6000020,   4195000, 620501907, 100000002,    703010, // pg.73
    5400000,   2600709, 300000000,       500,    900041, 647050082, 206070300,     90010,  94800000, // pg.74
  900006020,   5020080,     35009,   8560000,      4050,  76908000,     53010,   7400900,  30000200, // pg.75
  // Difficult
        600,  10045000,  53907800,  90001000,  65280701, 180470006,   8100300, 500700060, 200034000, // pg.111
     100060,  90700100,    896300,        46, 607580002,         0,   8971200, 210608000, 409000000, // pg.112
        700,         0,  30016289, 860329045,  20400800, 401000000,   6003000,  58692000, 902048300, // pg.113
    1924350, 300017009, 269830400,  90000100,         0,  50200000,      8003,         0, 800341020, // pg.114
        570, 708900306,   5170080, 300000194,   4039028,  90000600, 809040050, 500067000,       800, // pg.115
  // Challenging (hard)
      51400, 519000000,         0, 607003800,  83700006,         0, 208670910,  40008503,   5200600, // pg.151
  800001009,  10246000,  30090000, 706000000,   8000904, 100000270,    530800, 900060400, 473000001, // pg.152
  206090004,      5760, 500000003, 640000000,   1030098,  92100000,     80072,    900456, 960004000, // pg.153
   20080003,  40029006,   1006000, 100542090, 200000008,  39100002,    900000, 700014620,     30709, // pg.154
      90000, 653000000,         3,  30180670, 100005304, 700039125, 581703006,  40910750,   2000000, // pg.183
   80750016,  20000040,      6302, 900300005, 632000000,  10060000,         9,  53020000, 100003800, // pg.184
    8075000, 300000849, 900040060, 250000000,   6700000,     60000,     91007,  13058294, 680020300, // pg.185
  963000040, 547000000,        75, 100709000,     10000, 320800090,  92080360,  50600000,  36107054, // pg.186
     503600,    860700,   8074000,  80049030, 400008026,   5200008, 500102307,   4000000,    407009, // pg.187
   60320070, 470000032,    900146, 240800000,   8000201, 100002000,   2476800, 689000054,     80000, // pg.188
     824160, 417390502, 620000003,   5200010,  40000750,  60015000,  50002600, 100000000,     30008, // pg.189
  100300007, 428000000, 300000000, 500600080,  84537006,     40500,    482060,   5000070, 612090030, // pg.190
      20001,  10008309,   6000040, 709003000,  30000010,    700508,  40000700, 203900060, 100070000, //  6 prunes
    1020000, 300456000, 726000000, 405010000, 803000906,     80407,       368,    269004,     30100, // 25 prunes
   12345060,         0, 450600037,   8030400,   7090500,   5010600, 590002041,         0,  30459780, // 40 prunes
  // http://puzzling.stackexchange.com/questions/12/are-there-sudoku-puzzles-published-that-do-require-guessing
  671000523, 493000187, 285371900,   6800710, 907050608,  48007200,   2749800, 859000471, 764000392, //  2 guesses (1 dead-end)
      64203,  40008906,   6050407, 603800745, 450603821,    540639, 201430508, 704105362,         0, //  1 guess
  140900730, 763014800,   2030461,  37001600,  50000140,   1000250, 810040900, 329100504,  74009310, //  2 guesses (1 dead-end)
    2500098, 490020005, 305900200, 864312759, 153798020, 927654831, 201005903,     30582, 530200100, //  2 guesses (1 dead-end)
  // http://www.sudokudragon.com/sudokuguess.htm
          3,    800140, 560090200, 941005300,     40000,   3100459,   7030018,  38006000, 400000000  //  2 guesses (1 dead-end)
   
};

