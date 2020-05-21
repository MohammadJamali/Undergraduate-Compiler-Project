#define ADD 1 // + 
#define AND 2 // &&
#define SUB 3 // -
#define MUL 4 // *
#define DIV 5 // /
#define OR 6 // ||
#define EQ 7 // =
#define NEQ 8 // !=
#define GR 9 // >
#define LES 10 // <
#define GRE 11 // >=
#define LSE 12 // <=
#define NOT 13 // !

#define CODEMAX 500

typedef struct threeAddr
{
	int operand;
	int result;
	int op1;
	int op2;
}threeAddrEntry;

threeAddrEntry codeTable[CODEMAX];

int  lastIndex = 0;

int generate(int operand, int result, int op1, int op2)
{
	int i = lastIndex;
	codeTable[i].operand = operand;
	codeTable[i].result = result;
	codeTable[i].op1 = op1;
	codeTable[i].op2 = op2;
	lastIndex++;
	return i;
	
}
