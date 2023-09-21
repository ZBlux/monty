#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct monty_instruction_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack and queue
 * Description: carries values through the program
 */
typedef struct monty_instruction_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  monty_instruction_t;
extern monty_instruction_t bus;


/*all functions*/

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void _push(stack_t **head, unsigned int number);
void _pall(stack_t **head, unsigned int number);
void _pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);
void _sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void _mul(stack_t **head, unsigned int counter);
void _mod(stack_t **head, unsigned int counter);
void _pchar(stack_t **head, unsigned int counter);
void _pstr(stack_t **head, unsigned int counter);
void _rotl(stack_t **head, unsigned int counter);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);
#endif
