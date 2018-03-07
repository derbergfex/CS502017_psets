Harvard's CS50 C Psets
======================

Contents
--------
* [pset1](#pset1)
  * [hello](#hello)
  * [mario](#mario)
  * [water](#water)
  * [greedy](#greedy)
  
* [pset2](#pset2)
  * [initials](#initials)
  * [caesar](#caesar)
  * [vigenere](#vigenere)
  
* [pset3](#pset3)
  * [find](#find)
  * [fifteen](#fifteen)
  
* [pset4](#pset4)
  * [whodunit](#whodunit)
  * [resize](#resize)
  * [recover](#recover)
  
* [pset5](#pset5)
  * [speller](#speller)

  
  
pset1
=====

  hello
  ------
  Implement a program that prints out a simple greeting to the user.
  
  mario
  ------
  Implement a program that prints out a half-pyramid of a specified height, per the below.
  ```
    $ ./mario
    Height: 5
        ##
       ###
      ####
     #####
    ######

   $ ./mario
    Height: 3
      ##
     ###
    ####
  ```
  
  water
  ------
  Implement a program that reports a user’s water usage, converting minutes spent in the shower to bottles of drinking water.
  
  greedy
  ------
  Implement a program that calculates the minimum number of coins required to give a user change.
   ```
   $ ./greedy
   O hai! How much change is owed?
   0.41
   4
   ```
  
pset2
=====

  initials
  ---------
  Implement a program that, given a person’s name, prints a person’s initials, per the below.
  ```
  $ ./initials
  Regulus Arcturus Black
  RAB
  ```
  
  caesar
  -------
  Implement a program that encrypts messages using Caesar’s cipher, per the below.
  ```
  $ ./caesar 13
  plaintext:  HELLO
  ciphertext: URYYB
  ```
  
  vigenere
  ---------
  Implement a program that encrypts messages using Vigenère’s cipher, per the below.
  ```
  $ ./vigenere ABC
  plaintext:  HELLO
  ciphertext: HFNLP
  ```
  
pset3
=====

  find
  ------
  Implement a program that finds a number among numbers, per the below.
  ```
  $ ./generate 1000 | ./find 42
  Didn't find needle in haystack.
  ```
  
  fifteen
  --------
  Implement the Game of Fifteen, per the below.
  ```
  $ ./fifteen 3
  WELCOME TO GAME OF FIFTEEN

  8  7  6

  5  4  3

  2  1  _

  Tile to move:
  
  ```
  
pset4
=====

  whodunit
  ---------
  Answer some questions and then implement a program that reveals a hidden message in a BMP, per the below.
  ```
  $ ./whodunit clue.bmp verdict.bmp
  ```
  ### Questions:
   In questions.txt, answer each of the following questions in a sentence or more.
 
     1. What’s stdint.h?

     2. What’s the point of using uint8_t, uint32_t, int32_t, and uint16_t in a program?

     3. How many bytes is a BYTE, a DWORD, a LONG, and a WORD, respectively?

     4. What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

     5. What’s the difference between bfSize and biSize?

     6. What does it mean if biHeight is negative?

     7. What field in BITMAPINFOHEADER specifies the BMP’s color depth (i.e., bits per pixel)?

     8. Why might fopen return NULL in lines 24 and 32 of copy.c?

     9. Why is the third argument to fread always 1 in our code?

     10. What value does line 65 of copy.c assign to padding if bi.biWidth is 3?

     11. What does fseek do?

     12. What is SEEK_CUR?
  
  
  resize
  -------
  Implement a program that resizes BMPs, per the below.
  ```
  $ ./resize 4 small.bmp large.bmp
  ```
  
  recover
  --------
  Implement a program that recovers JPEGs from a forensic image, per the below.
  ```
  $ ./recover card.raw
  ```
