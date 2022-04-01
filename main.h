#include <stdio.h>

/* init_game()
* −−−−−−−−−−−−−−−
* Starts the game with the given parametres.
*
* len: value of the '-len' flag if it is given
* 
* max: value of the '-max' flag if it is given
* −−−−−−−−−−−−−−−
*/
int init_game(int wordLen, int maxGuesses, FILE* wordList);

/* usage_error()
* −−−−−−−−−−−−−−−
* Prints incorrect usage error to 'stderr' and exits with code 1.
* −−−−−−−−−−−−−−−
*/
void usage_error(void);

/* game_end_error()
* −−−−−−−−−−−−−−−
* Prints the game over message and returns exits the program with a code of 3.
* 
* answer: The answer of the game to be printed in the message.
* −−−−−−−−−−−−−−−
*/
void game_end_error(char* answer);

/* to_lower_word()
* −−−−−−−−−−−−−−−
* Mutates a string pointer so that all letters are lowercase.
*
* guess: the string pointer to be mutated.
* −−−−−−−−−−−−−−−
*/
void to_lower_word(char* word);

/* remove_new_line()
* −−−−−−−−−−−−−−−
* Removes new line character from string and replaces it with a null byte.
* 
* word: The string to be mutated.
* −−−−−−−−−−−−−−−
*/
void remove_new_line(char* word);

/* is_alphabetical()
* −−−−−−−−−−−−−−−
* Returns 1 if the given string is alphabetical and 0 otherwise.
*
* string: the string to be checked.
* −−−−−−−−−−−−−−−
*/
int is_alphabetical(char string[]);

/* check_guess()
* −−−−−−−−−−−−−−−
* Checks the given word is in teh given dictionary, is the right length and 
* that it contains only alphabetical characters.
*
* guess: The string to be checked
* 
* length: The length of 'answer' and 'guess.'
* 
* dictionary: The dictionary to check
*
* dictLength: The length of the aforementioned dictionary.
* −−−−−−−−−−−−−−−
*/
int check_guess(char* guess, int length, char** dictionary, int dictLength);

/* check_numerical_flag()
* −−−−−−−−−−−−−−−
* Checks the validity of the 'max' and 'len' flags.
*
* argc: Number of command line arguments.
*
* argv: Command line arguments.
* 
* flag: The integer value of the flag.
*
* iterator: Iterator of the loop that checks command line arguments.
* −−−−−−−−−−−−−−−
*/
void check_numerical_flag(int argc, char* argv[], int* flag, int* iterator);

/* check_word_exists()
* −−−−−−−−−−−−−−−
* Iterates over the given 'directory' and looks for string 'word'.
*
* dictionary: The dictionary to perform the search on.
*
* numWords: The length of the dictionary.
* 
* words: The string to be looked for.
*
* returns: 1 if word found ans 0 otherwise.
* −−−−−−−−−−−−−−−
*/
int check_word_exists(char** dictionary, int numWords, char* word);

/* generate_dictionary()
* −−−−−−−−−−−−−−−
* Generates an array of strings from file 'file.' Will only store strings that
* aret the same length as 'answerLength.'
*
* file: The file to be read.
* 
* numWords: The number of string that are raed into the array.
* 
* answerLength: The length that words must match to be read into array.
* −−−−−−−−−−−−−−−
*/
char** generate_dictionary(FILE* file, int* numWords, int answerLength);

/* print_letter_matching()
* −−−−−−−−−−−−−−−
* Prints a string of letters that shows which guessed letters match the answer.
*
* answer: The answer string.
* 
* length: The length of 'answer' and 'guess.'
* 
* guess: The guess string.
* −−−−−−−−−−−−−−−
*/
void print_letter_matching(char* answer, int length, char* guess);

/* free_dictionary()
* −−−−−−−−−−−−−−−
* Frees a 2D array of strings.
*
* dictionary: The dictionary to be freed.
* 
* numWords: The number of strings stored in the dictionary.
* −−−−−−−−−−−−−−−
*/
void free_dictionary(char** dictionary, int numWords);
