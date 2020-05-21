#include<string.h>
#include<stdlib.h>
#define idToken 1
#define numToken 2
#define intType 1
#define realType 2
#define TOKENMAX 100

extern FILE *yyout;

typedef struct entryRec{
char *name;
int type;
int valueType;
float realVal;
int intVal;}symTableEntry;

symTableEntry symTable[TOKENMAX];

int numOfTokens=0;
int searchSymTable(char *n)
{
int found=0;
int i;
for (i=0;i<numOfTokens && !found;i++)
if (strcmp(n,symTable[i].name)==0)
	found=1;

if (found)
	return i-1;
else
	return -1;
}

void setIntVal(int i,int iv)
{symTable[i].intVal=iv;
return;
}

void setRealVal(int i,float rv)
{symTable[i].realVal=rv;
return;
}

int addToSymTable(char *n,int t)
{
int i=searchSymTable(n);

if(i==-1){
i=numOfTokens;
symTable[i].name=malloc(sizeof(char*));
strcpy(symTable[i].name,n);
symTable[i].type=t;
symTable[i].valueType=0;
symTable[i].realVal=0;
symTable[i].intVal=0;
numOfTokens++;}
return i;
}

void setValueType(int i,int vt)
{
symTable[i].valueType=vt;
return;
}

int getValueType(int i)
{
int k;
k=symTable[i].valueType;
	return k;
}


void printSymTable()
{
int i;
printf("\n\t******************************SymbolTable******************************\n");
printf("\tToken Name\tToken type\tValue Type\tValue\t\t\n");
for(i=0;i<numOfTokens;i++)
{printf("\t%s\t",symTable[i].name);
if(symTable[i].type ==idToken)
printf("\tidentifier\t");

else 
printf("\tnum\t");
if(symTable[i].valueType==intType)
printf("\tinteger\t\t%d\t",symTable[i].intVal);
 /*else*/ 
 else if(symTable[i].valueType==realType)
printf("\treal\t\t%f\t",symTable[i].realVal);
printf("\n");
}
return;
}

int newTemp(int t)
{
int i = numOfTokens - 1 ;
char *n1,*n2,*n3;
int lastTemp = 0;
int j;
n2 = malloc(sizeof(char*));
n3 = malloc(sizeof(char*));
strcpy(n3,"_T");
while(i>=0)
{
	n1 = symTable[i].name;
	if(n1[0] == '_' && n1[1] == 'T')
	{
		n1++;
		n1++;
		lastTemp = atoi(n1)+ 1;
		i = -1;
	}
	i--;
}
itoa(lastTemp,n2,10);
strcat(n3,n2);
j = addToSymTable(n3,idToken);
setValueType(j,t);
return j;
}
/*
void printIDs()
{
	int iflag, fflag, i;
	iflag = 0;
	fflag = 0;
	fprintf(yyout,"\n\n");
	i = 0;
	while ( i < numOfTokens && !iflag)
	{
		if (symTable[i].type == idToken && symTable[i].valueType == intType)
			iflag = 1;
		i++;
		
	}
	if( iflag == 1 ) 
		fprintf(yyout,"int %s",symTable[i-1].name);
		while(iflag == 1 && i < numOfTokens)
		{
			if(symTable[i].type == idToken && symTable[i].valueType == intType )
				fprintf(yyout,",%s",symTable[i].name);
				
			i++;
		}
	if( iflag == 1 ) 
		fprintf(yyout,";\n");
	for( i = 0; i < numOfTokens;i++)
		if(symTable[i].type == idToken && symTable[i].valueType == realType )
		{
		
			fflag = 1;
			break;
		}
	if( fflag == 1 ) fprintf(yyout,"real %s", symTable[i].name);
	i++;
	while(fflag == 1 && i < numOfTokens)
	{
		if(symTable[i].type == idToken && symTable[i].valueType == realType )
				fprintf(yyout,",%s",symTable[i].name);
				
			i++;
	}
	if(fflag == 1) fprintf(yyout,";\n");
	return;

}
*/
char *getSymbol(int i)
{
	char *s;
	if( i == -1 ) return NULL;
	s = malloc(sizeof(char *));
	strcpy(s,symTable[i].name);
	return s;
}
