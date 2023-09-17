//void checkCommentsAfterSemicolon(char array[]); //line 0
//void checkComments(char array[]);
//void checkSingleQuotes(char array[]);
//void checkDoubleQuotes(char array[]);
//void checkHexidecimalEscapeSequences(char array[]);
//void checkBrackets(char array[]);
//void checkParenthesis(char array[]);
//void checkBraces(char array[]);
//
//#define MAXARRAYSIZE 50000
//main()
//{
//	int c;
//	char array[MAXARRAYSIZE];
//	int i = 0;
//	//octal (come back)
//
//	while ((c = getchar()) != EOF)
//	{
//		array[i] = c;
//		i++;
//	}
//	array[i] = '\0';
//
//	printf("\n");
//	//line 0
//	checkCommentsAfterSemicolon(array);
//
//	checkComments(array);
//
//	checkSingleQuotes(array);
//
//	checkDoubleQuotes(array);
//
//	checkHexidecimalEscapeSequences(array); //line 34
//
//	checkBrackets(array);
//
//	checkParenthesis(array);
//
//	printf("\ndone\n");
//}
//
//void checkCommentsAfterSemicolon(char array[])
//{
//	int i = 0;
//	char syntaxerror[MAXARRAYSIZE];
//	int k = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int COMMENTBEGANON = 0;
//	int COMMENTENDEDON = 0;
//	int LINE = 0;
//	int SYNTAXERROR = NO;
//	int SYNTAXERRORONLINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == ';') //line 34
//		{
//			i++;
//			while (array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //WHILE THE CHARACTER WE JUST SAVED IS NOT THE NEW LINE \n CHECK THE SIX CASES
//			{
//				if (INACOMMENT == NO && array[i] != '/' && array[i] != ' ' && array[i] != '\t') //CASE 6
//				{
//					while (array[i] != '/' && array[i] != '\n' && array[i] != '\0' && array[i] != EOF)
//					{
//						syntaxerror[k] = array[i];
//						SYNTAXERRORONLINE = LINE;
//						k++;
//						i++;
//					}
//					syntaxerror[k] = ' ';
//					k++;
//					SYNTAXERROR = YES; //CASE 6 DONE
//				}
//
//				else if (array[i] == '/') //CASE 1 2 3 4 5
//				{
//					UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//					COMMENTBEGANON = LINE;
//
//					if (array[i + 1] == '/') //CASE 4
//					{
//						UNBALANCEDCOMMENT = NO;
//						INACOMMENT = YES;
//						while (array[i] != '\n' && array[i] != '\0' && array[i] != EOF)
//						{
//							i++;
//						}
//						INACOMMENT = NO;
//					}
//
//					else if (array[i + 1] == '*') //CASE 5
//					{
//						UNBALANCEDCOMMENT = YES;
//						INACOMMENT = YES;
//						COMMENTBEGANON = LINE;
//						i++;
//						i++;
//						while (INACOMMENT == YES && array[i] != '\0' && array[i] != EOF)
//						{
//							if (array[i] == '\n')
//							{
//								LINE++; //LINE COUNTER
//								i++;
//							}
//							else if (array[i] == '*')
//							{
//								i++;
//								STAR = YES;
//							}
//							else if (array[i] == '/' && STAR == YES)
//							{
//								i++;
//								INACOMMENT = NO;
//								UNBALANCEDCOMMENT = NO;
//								STAR = NO;
//							}
//							else
//							{
//								i++;
//								STAR = NO;
//							}
//						}
//						if (INACOMMENT == NO && UNBALANCEDCOMMENT == NO)
//						{
//							printf("Multi-line comment started on line %d and ended on %d.\n", COMMENTBEGANON, COMMENTENDEDON); //CASE 5 DONE
//							/*test
//							*/
//						}
//					}
//
//					else
//					{
//						printf("5\n");
//						syntaxerror[k] = array[i];
//						i++;
//						k++;
//
//						while (array[i] != '\n' && array[i] != '/' && array[i] != '\0' && array[i] != EOF)
//						{
//							syntaxerror[k] = array[i]; // / a b
//							i++;
//							k++;
//							SYNTAXERRORONLINE = LINE;
//						}
//						SYNTAXERROR = YES;
//					}
//				}
//				else
//					i++;
//			}
//
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				printf("Error: Unbalanced comment on line %d. Missing / or *.\n", COMMENTBEGANON);
//
//				if (array[i] == '\0')
//				{
//					//printf("\n%s\n", output);
//					printf("null\n");
//				}
//
//				if (array[i] == EOF)
//				{
//					printf("EOF\n");
//				}
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2 WHITESPACE DONE  //CASE 3 NEWLINE DONE //CASE 4 // DONE //CASE 5 /**/ DONE
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//			if (SYNTAXERROR == YES) //CASE 6 DONE
//			{
//				syntaxerror[k] = '\0';
//				printf("Error: Syntax error. Text not in a comment on line %d. Code: %s\n", SYNTAXERRORONLINE, syntaxerror);
//				syntaxerror[0] = '\0';
//				k = 0;
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				SYNTAXERROR = NO;
//			}
//		}
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			COMMENTBEGANON = LINE;
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n' && array[i] != '\0' && array[i] != EOF)
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//
//				INACOMMENT = YES;
//
//				COMMENTBEGANON = LINE;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0' && array[i] != EOF)
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						COMMENTENDEDON = LINE;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//				if (INACOMMENT == NO && UNBALANCEDCOMMENT == NO)
//				{
//					printf("Multi-line comment started on line %d and ended on %d.\n", COMMENTBEGANON, COMMENTENDEDON); //style
//				}
//			}
//			else
//				; //NEXT CHARACTER (' ') IS HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				printf("Error: Unbalanced comment on line %d. Missing / or *.\n", COMMENTBEGANON);
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				INASINGLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				INADOUBLEQUOTE = NO;
//			}
//		}
//		else
//		{ 
//			if (array[i] == '\n')
//			{
//				LINE++;
//			}
//			i++;
//		}
//	}
//}
//
//void checkComments(char array[])
//{
//	int i = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int COMMENTBEGANON = 0;
//	int COMMENTENDEDON = 0;
//	int LINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			COMMENTBEGANON = LINE;
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n' && array[i] != '\0' && array[i] != EOF)
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//
//				INACOMMENT = YES;
//
//				COMMENTBEGANON = LINE;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0' && array[i] != EOF)
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						COMMENTENDEDON = LINE;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//				if (INACOMMENT == NO && UNBALANCEDCOMMENT == NO)
//				{
//					printf("Multi-line comment started on line %d and ended on %d.\n", COMMENTBEGANON, COMMENTENDEDON); //style
//				}
//			}
//			else
//				; //NEXT CHARACTER (' ') IS HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				printf("Error: Unbalanced comment on line %d. Missing / or *.\n", COMMENTBEGANON);
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				INASINGLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				INADOUBLEQUOTE = NO;
//			}
//		}
//		else
//		{
//			if (array[i] == '\n')
//			{
//				LINE++;
//			}
//			i++;
//		}
//	}
//}
//
//void checkSingleQuotes(char array[])
//{
//	int i = 0;
//	char syntaxerror[MAXARRAYSIZE];
//	int k = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int LINE = 0;
//	int INASINGLEQUOTE = NO;
//	int SINGLEQUOTEBEGANON = 0;
//	int INADOUBLEQUOTE = NO;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == '\'' && array[i - 1] != '\\') /*wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019*/
//		{
//			INASINGLEQUOTE = YES;
//			SINGLEQUOTEBEGANON = LINE;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				printf("Error: Uneven single quote. The single quote that started on line %d is missing a single quote \'.\n", SINGLEQUOTEBEGANON);
//				INASINGLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				INADOUBLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n' && array[i] != '\0' && array[i] != EOF)
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//				INACOMMENT = YES;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0' && array[i] != EOF)
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//			}
//			else
//			{
//				;//NEXT CHARACTER IS HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//				/*i++;
//				j++;*/
//			}
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else
//		{
//			if (array[i] == '\n')
//			{
//				LINE++;
//			}
//			i++;
//		}
//	}
//}
//
//void checkDoubleQuotes(char array[])
//{
//	int i = 0;
//	char syntaxerror[MAXARRAYSIZE];
//	int k = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int LINE = 0;
//	int INADOUBLEQUOTE = NO;
//	int DOUBLEQUOTEBEGANON = 0;
//	int INASINGLEQUOTE = NO;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			DOUBLEQUOTEBEGANON = LINE; //could use one variable QUOTEBEGANON
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				printf("Error: Uneven double quote. The double quote that started on line %d is missing a double quote \".\n", DOUBLEQUOTEBEGANON);
//				INADOUBLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				INASINGLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n' && array[i] != '\0' && array[i] != EOF)
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//				INACOMMENT = YES;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0' && array[i] != EOF)
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//			}
//			else
//			{
//				;//NEXT CHARACTER HANDLED IN THE UNBALANCED COMMENT BLOCK
//				/*i++;
//				j++;*/
//			}
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else
//		{
//			if (array[i] == '\n')
//			{
//				LINE++;
//			}
//			i++;
//		}
//	}
//}
//
//void checkHexidecimalEscapeSequences(char array[])
//{
//	int i = 0;
//	char syntaxerror[MAXARRAYSIZE];
//	int k = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int LINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//	int HEXSYNTAXERROR = NO;
//	int HEXSYNTAXERRORBEGANON = 0;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n') //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == 'x' && array[i - 1] == '\\' && array[i - 2] != '\\')
//				{
//					i++;
//					while (array[i] != ' ' && array[i] != '\'' && array[i] != '\n')
//					{
//						if (array[i] != '0' && array[i] != '1' && array[i] != '2' && array[i] != '3' && array[i] != '4' && array[i] != '5' && array[i] != '6' && array[i] != '7' && array[i] != '8' && array[i] != '9' && array[i] != 'A' && array[i] != 'B' && array[i] != 'C' && array[i] != 'D' && array[i] != 'E' && array[i] != 'F')
//						{
//							HEXSYNTAXERROR = YES;
//							HEXSYNTAXERRORBEGANON = LINE;
//						}
//						i++;
//					}
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				INASINGLEQUOTE = NO;
//			}
//			if (HEXSYNTAXERROR == YES)
//			{
//				printf("Error: Syntax error. The hexidecimal number in the single quotes on line %d is not acceptable.\n", HEXSYNTAXERRORBEGANON);
//				HEXSYNTAXERROR = NO;
//			}
//		}
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n') //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == 'x' && array[i - 1] == '\\' && array[i - 2] != '\\')
//				{
//					i++;
//					while (array[i] != ' ' && array[i] != '\'' && array[i] != '\n')
//					{
//						if (array[i] != '0' && array[i] != '1' && array[i] != '2' && array[i] != '3' && array[i] != '4' && array[i] != '5' && array[i] != '6' && array[i] != '7' && array[i] != '8' && array[i] != '9' && array[i] != 'A' && array[i] != 'B' && array[i] != 'C' && array[i] != 'D' && array[i] != 'E' && array[i] != 'F')
//						{
//							HEXSYNTAXERROR = YES;
//							HEXSYNTAXERRORBEGANON = LINE;
//						}
//						i++;
//					}
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				INADOUBLEQUOTE = NO;
//			}
//			if (HEXSYNTAXERROR == YES)
//			{
//				printf("Error: Syntax error. The hexidecimal number in the double quotes on line %d is not acceptable.\n", HEXSYNTAXERRORBEGANON);
//				HEXSYNTAXERROR = NO;
//			}
//		}
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n')
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//				INACOMMENT = YES;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0')
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//			}
//			else
//			{
//				;//NEXT CHARACTER HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//				/*i++;
//				j++;*/
//			}
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else
//		{
//			if (array[i] == '\n')
//			{
//				LINE++;
//			}
//			i++;
//		}
//	}
//}
//
//void checkBrackets(char array[])
//{
//	int i = 0;
//	int LeftBrackets = 0;
//	int RightBrackets = 0;
//	int EXTRALEFTBRACKETONLINE = 0;
//	int EXTRARIGHTBRACKETONLINE = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int LINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == '[')
//		{
//			LeftBrackets++;
//			EXTRALEFTBRACKETONLINE = LINE;
//			i++;
//			if (LeftBrackets - RightBrackets > 1)
//			{
//				printf("Error: Uneven brackets. An extra [ was found on line %d.\n", EXTRALEFTBRACKETONLINE);
//			}
//		}
//		else if (array[i] == ']')
//		{
//			RightBrackets++;
//			EXTRARIGHTBRACKETONLINE = LINE;
//			i++;
//			if (RightBrackets - LeftBrackets > 0)
//			{
//				printf("Error: Uneven brackets. An extra ] was found on line %d.\n", EXTRARIGHTBRACKETONLINE);
//			}
//		}
//		else if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n') //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				INASINGLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n') //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				INADOUBLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n')
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//				INACOMMENT = YES;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0')
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//			}
//			else
//			{
//				; //NEXT CHARACTER HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//				/*i++;
//				j++;*/
//			}
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else
//		{
//			if (array[i] == '\n')
//			{
//				LINE++;
//				LeftBrackets = 0;
//				RightBrackets = 0;
//			}
//			i++;
//		}
//	}
//}
//
//void checkParenthesis(char array[])
//{
//	int i = 0;
//	int LeftParenthesis = 0;
//	int RightParenthesis = 0;
//	int EXTRALEFTPARENTHESISONLINE = 0;
//	int EXTRARIGHTPARENTHESISONLINE = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int LINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == '(')
//		{
//			LeftParenthesis++;
//			EXTRALEFTPARENTHESISONLINE = LINE;
//
//			i++;
//		}
//		else if (array[i] == ')')
//		{
//			RightParenthesis++;
//			EXTRARIGHTPARENTHESISONLINE = LINE;
//
//			i++;
//			if (RightParenthesis > LeftParenthesis)
//			{
//				printf("Error: Uneven Right Parenthesis ). An extra ) was found on line %d.\n", EXTRARIGHTPARENTHESISONLINE);
//			}
//		}
//		else if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n') //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				INASINGLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n') //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				INADOUBLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n')
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//				INACOMMENT = YES;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0')
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//			}
//			else
//			{
//				; //NEXT CHARACTER HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//				/*i++;
//				j++;*/
//			}
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else
//		{
//			if (array[i] == '\n')
//			{
//				LINE++;
//				if (LeftParenthesis > RightParenthesis)
//				{
//					printf("Error: Uneven Left Parenthesis (. An extra ( was found on line %d.\n", EXTRALEFTPARENTHESISONLINE);
//				}
//				LeftParenthesis = 0;
//				RightParenthesis = 0;
//			}
//			i++;
//		}
//	}
//}
//
//void checkBraces(char array[])
//{
//	int i = 0;
//	int LeftBraces = 0;
//	int RightBraces = 0;
//	int EXTRALEFTBRACEONLINE = 0;
//	int EXTRARIGHTBRACEONLINE = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int LINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//		if (array[i] == '{')
//		{
//			LeftBraces++;
//			EXTRALEFTBRACEONLINE = LINE;
//			i++;
//		}
//		else if (array[i] == '}')
//		{
//			RightBraces++;
//			EXTRARIGHTBRACEONLINE = LINE;
//			i++;
//			if (RightBraces - LeftBraces > 0)
//			{
//				printf("Error: Uneven Right Braces. An extra } was found on line %d.\n", EXTRARIGHTBRACEONLINE);
//			}
//		}
//		else if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			i++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n') //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				INASINGLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			i++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n') //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					i++;
//				}
//				else
//				{
//					i++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				INADOUBLEQUOTE = NO;
//			}
//		}
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n')
//				{
//					i++;
//				}
//				INACOMMENT = NO;
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//				INACOMMENT = YES;
//				i++;
//				i++;
//				while (INACOMMENT == YES && array[i] != '\0')
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						i++;
//					}
//					else if (array[i] == '*')
//					{
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						STAR = NO;
//					}
//					else
//					{
//						i++;
//						STAR = NO;
//					}
//				}
//			}
//			else
//			{
//				; //NEXT CHARACTER HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//				/*i++;
//				j++;*/
//			}
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//				UNBALANCEDCOMMENT = NO;
//			}
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//				i++;
//			}
//		}
//		else
//		{
//			if (array[i] == '\n')
//			{
//				LINE++;
//			}
//			i++;
//		}
//	}
//	if (LeftBraces > RightBraces)
//	{
//		printf("Error: Uneven amount of Left Braces {. An extra left brace ({) was found on line %d.\n", EXTRALEFTBRACEONLINE);
//		printf("Total number of extra left braces: %d\n", LeftBraces - RightBraces);
//	}
//}
