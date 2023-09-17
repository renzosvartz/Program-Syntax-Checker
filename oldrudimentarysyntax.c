//#define MAXARRAYSIZE 1000
//#define ON 1
//#define OFF 0
//main()
//{
//	int c;
//	char array[MAXARRAYSIZE];
//	int i = 0;
//	int j = 0;
//	char output[MAXARRAYSIZE];
//	int DONE = NO;
//	int STAR = NO;
//	int COMMENTCHECKING = ON;
//
//	while ((c = getchar()) != EOF && i < MAXARRAYSIZE - 1)
//	{
//		array[i] = c;
//		i++;
//	}
//	array[i] = '\0';
//	i = 0;
//	while (array[i] != '\0')
//	{
//		while (COMMENTCHECKING == ON && array[i] != '\0')
//		{
//			output[j] = array[i];
//			if (array[i] == '/' && COMMENTCHECKING == YES)
//			{
//				if (array[i + 1] == '/')
//				{
//					i++;
//					while (array[i] != '\n')
//					{
//						i++;
//					}
//					output[j] = array[i];
//				}
//				else if (array[i + 1] == '*' && COMMENTCHECKING == YES)
//				{
//					i++;
//					while (DONE == NO)
//					{
//						if (array[i] == '*')
//						{
//							STAR = YES;
//							i++;
//						}
//						else if (array[i] == '/' && STAR == YES)
//						{
//							DONE = YES;
//							i++;
//						}
//						else
//						{
//							STAR = NO;
//							i++;
//						}
//						output[j] = array[i];
//					}
//				}
//			}
//			else if (array[i] == '"')
//			{
//				COMMENTCHECKING = OFF;
//			}
//			i++;
//			j++;
//		}
//		while (COMMENTCHECKING == OFF && array[i] != '\0')
//		{
//			output[j] = array[i];
//			i++;
//			j++;
//			if (array[i] == '"')
//			{
//				COMMENTCHECKING = ON;	
//			}
//		}
//	}
//	output[j] = array[i];
//	printf("%s\n", output);
//}
//#define MAXARRAYSIZE 10000
//#define ON 1
//#define OFF 0
//main()
//{ //test 
//	int c;
//	char array[MAXARRAYSIZE]; /*test*/
//	int i = 0;
//	int j = 0;
//	char output[MAXARRAYSIZE];
//	int COMMENT = NO;
//	int STAR = NO;
//	int SQCOMMENTCHECKING = ON;
//	int DQCOMMENTCHECKING = ON;
//	/*test
//	a
//	b
//	c*/
//	while ((c = getchar()) != EOF && i < MAXARRAYSIZE - 1)
//	{
//		array[i] = c;
//		i++;
//	}
//	array[i] = '\0';
//	i = 0; //test
//	while (array[i] != '\0')	/*test
//	a
//	b
//	c*/
//	{
//		while (SQCOMMENTCHECKING == ON && DQCOMMENTCHECKING == ON && array[i] != '\0')
//		{
//			output[j] = array[i];
//			if (array[i] == '/' && SQCOMMENTCHECKING == ON && DQCOMMENTCHECKING == ON)
//			{
//				if (array[i + 1] == '/')
//				{
//					i++;
//					while (array[i] != '\n')
//					{
//						i++;
//					}
//					output[j] = array[i];//test
//				}
//				else if (array[i + 1] == '*' && SQCOMMENTCHECKING == ON && DQCOMMENTCHECKING == ON)
//				{
//					i++;
//					i++;
//					COMMENT = YES;
//					while (COMMENT == YES)
//					{//test
//						if (array[i] == '*')
//						{
//							STAR = YES;
//							i++;//test
//						}	/*test
//	a
//	b
//	c*/
//						else if (array[i] == '/' && STAR == YES)
//						{
//							COMMENT = NO;
//							i++;
//						}
//						else
//						{
//							STAR = NO;//test
//							i++;
//						}
//					}
//					//output[j] = array[i];
//				}
//			}
//			/*else if (array[i] == '"' && array[i-1] != '\'')
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//				COMMENTCHECKING = OFF;
//			}*/
//			else if (array[i] == '\'' && array[i - 1] != '\\')
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//				SQCOMMENTCHECKING = OFF;
//			}
//			else if (array[i] == '"' && array[i - 1] != '\\')
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//				DQCOMMENTCHECKING = OFF;
//			}
//			else
//			{
//				i++;
//				j++;
//			}
//		}
//		while ((SQCOMMENTCHECKING == OFF || DQCOMMENTCHECKING == OFF) && array[i] != '\0')
//		{
//			if (array[i] == '\'' && array[i - 1] != '\\')
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//				SQCOMMENTCHECKING = ON;
//			}
//			else if (array[i] == '"' && array[i - 1] != '\\')
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//				DQCOMMENTCHECKING = ON;
//			}
//			else
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//			}
//	//		if (array[i] == '"')
//	//		{	/*test
//	//a
//	//b
//	//c*//*test*///
//	//			COMMENTCHECKING = ON;
//	//		}
//		}
//	}
//	output[j] = array[i];
//	printf("%s\n", output);
//}
#define MAXARRAYSIZE 10000

//main()
//{
//	int c;
//	char array[MAXARRAYSIZE];
//	int i = 0;
//	char output[MAXARRAYSIZE];
//	int j = 0;
//	int MAXLParenthesis = 0;
//	int MAXLBraces = 0;
//	int MAXLBrackets = 0;
//	int RParenthesis = 0;
//	int RBraces = 0;
//	int RBrackets = 0;
//	int COMMENT = NO;
//	int STAR = NO;
//	int COMMENTDONE = NO;
//	int COMMENTBEGANON = 0;
//	int COMMENTBEGANON_REGISTERED = NO;
//	int LINE = 0;
//	int UNEVENCOMMENT = NO;
//	int INACOMMENT = NO;
//	while ((c = getchar()) != EOF)
//	{
//		array[i] = c;
//		i++;
//	}
//	array[i] = '\0';
//	i = 0;
//	while (array[i] != '\0')
//	{
//		if (array[i] == '\n')
//		{
//			LINE++; //LINE COUNTER
//		} //THE NEWLINE IS SAVED IN THE NEXT EXPRESSION AND THEN IT DOES NOT FIT ANY OTHER CONDITIONAL STATEMENTS SO IT WILL BE INCREMENTED BY AN ELSE 1
//
//		output[j] = array[i]; //STORES EVERY CHARACTER FROM array
//
//		if (array[i] == ';') //THIS CHECKS FOR COMMENTS AFTER ;
//		{
//			i++;
//			j++;
//			output[j] = array[i]; //CHECKS EITHER // OR /* OR / OR WHITE SPACE OR NEWLINE . FIVE DIFFERENT CASES.
//			
//			while (array[i] != '\n') //WHILE THE CHARACTER WE JUST SAVED IS NOT THE NEW LINE \n CHECK THE SIX CASES
//			{
//				i++;
//				j++;
//				output[j] = array[i];
//				if (INACOMMENT == NO && array[i] != '/' && array[i] != '*' && array[i] != ' ' && array[i] != '\t')
//				{
//					while (array[i] != '\n')
//					{
//						i++;
//						j++;
//						output[j] = array[i]; // //CASE 6 TEXT NOT IN A COMMENT 
//					}
//					printf("Error: Syntax error. Text not in a comment on line %d.", LINE);
//				}
//
//				if (array[i] == '/') //CHECKS CASE 1 2 3 4 5
//				{
//					UNEVENCOMMENT = YES; //CASE 1 UNEVEN COMMENT 
//					INACOMMENT == YES;
//					COMMENTBEGANON = LINE;
//					if (array[i + 1] == '/')
//					{
//						UNEVENCOMMENT = NO;
//						INACOMMENT = YES;
//						while (array[i] != '\n')
//						{
//							i++;
//							j++;
//							output[j] = array[i]; //CASE 4 SINGLE LINE COMMENT // 
//						}
//					}
//
//					else if (array[i + 1] == '*') //CASE 5 MULTI LINE COMMENT /* 
//					{
//						UNEVENCOMMENT = NO;
//						INACOMMENT = YES;
//						while (INACOMMENT == YES && array[i] != '\0')
//						{
//							if (array[i] == '\n')
//							{
//								if (COMMENTBEGANON_REGISTERED == NO)
//								{
//									COMMENTBEGANON = LINE;
//									COMMENTBEGANON_REGISTERED == YES;
//								}
//								LINE++; //LINE COUNTER
//							}
//							if (array[i] == '*')
//							{
//								output[j] == array[i];
//								j++;
//								i++;
//								STAR = YES;
//							}
//							else if (array[i] == '/' && STAR == YES)
//							{
//								output[j] == array[i];
//								j++;
//								i++;
//								INACOMMENT = NO;
//								COMMENTBEGANON_REGISTERED == NO;
//							}
//							else
//							{
//								output[j] == array[i];
//								j++;
//								i++;
//								STAR = NO;
//							}
//						}
//						printf(" End of multi line comment. New line will be printed v \n");
//					}
//				}
//			}
//			if (UNEVENCOMMENT == YES)
//			{
//				printf("Error: Unbalanced comment on line. Missing / or *.");
//				output[j] = array[i];
//				i++;
//				j++;
//			}
//			else if (UNEVENCOMMENT == NO) //CASE 2 WHITESPACE  //CASE 3 NEWLINE 
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//			}
//		}
//		if (array[i] == '/')
//		{
//			if (array[i + 1] == '/')
//			{
//				output[j] == 'C';
//				j++;
//				output[j] == 'O';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'E';
//				j++;
//				output[j] == 'N';
//				j++;
//				output[j] == 'T';
//				j++;
//				output[j] == ':';
//				j++;
//				output[j] = array[i]; // /
//				i++;
//				j++;
//				output[j] = array[i]; // //
//				i++;
//				j++;
//				COMMENT = YES;
//				while (c != '\n')
//				{
//					output[j] = array[i];//comment text
//					i++;
//					j++;
//				}
//				//output[j] = array[i]; //\n
//				//i++;
//				//j++;
//			}
//			else if (array[i + 1] == '*')
//			{
//				output[j] == 'C';
//				j++;
//				output[j] == 'O';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'E';
//				j++;
//				output[j] == 'N';
//				j++;
//				output[j] == 'T';
//				j++;
//				output[j] == ':';
//				j++;
//				output[j] = array[i]; // /
//				i++;
//				j++;
//				output[j] = array[i]; // //
//				i++;
//				j++;
//				COMMENT = YES;
//				COMMENTBEGANON = LINE; //comment that began on Line 1 never terminated.
//				while (COMMENTDONE == NO && array[i] != '\0')
//				{
//					if (array[i] == '*')
//					{
//						output[j] == array[i];
//						j++;
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						output[j] == array[i];
//						j++;
//						i++;
//						COMMENTDONE = YES;
//					}
//					else
//					{
//						output[j] == array[i];
//						j++;
//						i++;
//						STAR = NO;
//					}
//				}
//				if (array[i] == '\0' && COMMENTDONE == NO)
//				{
//					printf("Error: Unbalanced cooment. The comment that started on Line %d never finished.", COMMENTBEGANON);
//				}
//				COMMENT = NO;
//			}
//			else
//				;
//		}
//		else
//		{
//			j++;
//			i++;
//		}
//
//	}
//	output[j] = '\0';
//	printf("%s\n", output);
//}

//#define MAXARRAYSIZE 10000
//
//
//main()
//{
//	int c;
//	char array[MAXARRAYSIZE];
//	int i = 0;
//	char output[MAXARRAYSIZE];
//	int j = 0;
//	int MAXLParenthesis = 0;
//	int MAXLBraces = 0;
//	int MAXLBrackets = 0;
//	int RParenthesis = 0;
//	int RBraces = 0;
//	int RBrackets = 0;
//	int COMMENT = NO;
//	int STAR = NO;
//	int COMMENTDONE = NO;
//	int COMMENTBEGANON = 0;
//	int COMMENTBEGANON_REGISTERED = NO;
//	int LINE = 0;
//	int UNEVENCOMMENT = NO;
//	int INACOMMENT = NO;
//	while ((c = getchar()) != EOF)
//	{
//		array[i] = c;
//		i++;
//	}
//	array[i] = '\0';
//	i = 0;
//	while (array[i] != '\0')
//	{
//		if (array[i] == '\n')
//		{
//			LINE++; //LINE COUNTER
//		}
//
//		output[j] = array[i]; //STORES EVERY CHARACTER FROM array to output
//
//		if (array[i] == ';') //THIS CHECKS FOR COMMENTS AND TEXT OUTSIDE OF COMMENTS AFTER ;
//		{
//			i++;
//			j++;
//
//			output[j] = array[i]; //CHECKS EITHER // OR /* OR / OR WHITE SPACE OR NEWLINE OR TEXT. SIX DIFFERENT CASES.
//
//			while (array[i] != '\n') //CHECK THE SIX CASES
//			{
//				i++;
//				j++;
//
//				output[j] = array[i]; //BEGIINNING OF TEXT THAT HAS TO BE ANALYZED. SAVED AND NOT NEXT.
//
//				if (INACOMMENT == NO && array[i] != '/' && array[i] != '*' && array[i] != ' ' && array[i] != '\t') //CASE 6
//				{
//					while (array[i] != '\n')
//					{
//						i++;
//						j++;
//
//						output[j] = array[i];
//					}
//					printf("Error: Syntax error. Text not in a comment on line %d.", LINE);
//				}
//
//				if (array[i] == '/') //CHECKS CASE 1 2 3 4 5
//				{
//					UNEVENCOMMENT = YES; //CASE 1 UNEVEN COMMENT 
//					INACOMMENT == YES;
//					COMMENTBEGANON = LINE;
//					if (array[i + 1] == '/')
//					{
//						UNEVENCOMMENT = NO;
//						INACOMMENT = YES;
//						while (array[i] != '\n')
//						{
//							i++;
//							j++;
//							output[j] = array[i]; //CASE 4 SINGLE LINE COMMENT // 
//						}
//					}
//
//					else if (array[i + 1] == '*') //CASE 5 MULTI LINE COMMENT /* 
//					{
//						UNEVENCOMMENT = NO;
//						INACOMMENT = YES;
//						while (INACOMMENT == YES && array[i] != '\0')
//						{
//							if (array[i] == '\n')
//							{
//								if (COMMENTBEGANON_REGISTERED == NO)
//								{
//									COMMENTBEGANON = LINE;
//									COMMENTBEGANON_REGISTERED == YES;
//								}
//								LINE++; //LINE COUNTER
//							}
//							if (array[i] == '*')
//							{
//								output[j] == array[i];
//								j++;
//								i++;
//								STAR = YES;
//							}
//							else if (array[i] == '/' && STAR == YES)
//							{
//								output[j] == array[i];
//								j++;
//								i++;
//								INACOMMENT = NO;
//								COMMENTBEGANON_REGISTERED == NO;
//							}
//							else
//							{
//								output[j] == array[i];
//								j++;
//								i++;
//								STAR = NO;
//							}
//						}
//						printf(" End of multi line comment. New line will be printed v \n");
//					}
//				}
//			}
//			if (UNEVENCOMMENT == YES)
//			{
//				printf("Error: Unbalanced comment on line. Missing / or *.");
//				output[j] = array[i];
//				i++;
//				j++;
//			}
//			else if (UNEVENCOMMENT == NO) //CASE 2 WHITESPACE  //CASE 3 NEWLINE 
//			{
//				output[j] = array[i];
//				i++;
//				j++;
//			}
//		}
//		if (array[i] == '/')
//		{
//			if (array[i + 1] == '/')
//			{
//				output[j] == 'C';
//				j++;
//				output[j] == 'O';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'E';
//				j++;
//				output[j] == 'N';
//				j++;
//				output[j] == 'T';
//				j++;
//				output[j] == ':';
//				j++;
//				output[j] = array[i]; // /
//				i++;
//				j++;
//				output[j] = array[i]; // //
//				i++;
//				j++;
//				COMMENT = YES;
//				while (c != '\n')
//				{
//					output[j] = array[i];//comment text
//					i++;
//					j++;
//				}
//				//output[j] = array[i]; //\n
//				//i++;
//				//j++;
//			}
//			else if (array[i + 1] == '*')
//			{
//				output[j] == 'C';
//				j++;
//				output[j] == 'O';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'M';
//				j++;
//				output[j] == 'E';
//				j++;
//				output[j] == 'N';
//				j++;
//				output[j] == 'T';
//				j++;
//				output[j] == ':';
//				j++;
//				output[j] = array[i]; // /
//				i++;
//				j++;
//				output[j] = array[i]; // //
//				i++;
//				j++;
//				COMMENT = YES;
//				COMMENTBEGANON = LINE; //comment that began on Line 1 never terminated.
//				while (COMMENTDONE == NO && array[i] != '\0')
//				{
//					if (array[i] == '*')
//					{
//						output[j] == array[i];
//						j++;
//						i++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						output[j] == array[i];
//						j++;
//						i++;
//						COMMENTDONE = YES;
//					}
//					else
//					{
//						output[j] == array[i];
//						j++;
//						i++;
//						STAR = NO;
//					}
//				}
//				if (array[i] == '\0' && COMMENTDONE == NO)
//				{
//					printf("Error: Unbalanced cooment. The comment that started on Line %d never finished.", COMMENTBEGANON);
//				}
//				COMMENT = NO;
//			}
//			else
//				;
//		}
//		else
//		{
//			j++;
//			i++;
//		}
//
//	}
//	output[j] = '\0';
//	printf("%s\n", output);
//}
//
//
//if (array[i] == '/')
//{
//	if (array[i + 1] == '/')
//	{
//		output[j] == 'C';
//		j++;
//		output[j] == 'O';
//		j++;
//		output[j] == 'M';
//		j++;
//		output[j] == 'M';
//		j++;
//		output[j] == 'E';
//		j++;
//		output[j] == 'N';
//		j++;
//		output[j] == 'T';
//		j++;
//		output[j] == ':';
//		j++;
//		output[j] = array[i]; // /
//		i++;
//		j++;
//		output[j] = array[i]; // //
//		i++;
//		j++;
//		COMMENT = YES;
//		while (c != '\n')
//		{
//			output[j] = array[i];//comment text
//			i++;
//			j++;
//		}
//		//output[j] = array[i]; //\n
//		//i++;
//		//j++;
//	}
//	else if (array[i + 1] == '*')
//	{
//		output[j] == 'C';
//		j++;
//		output[j] == 'O';
//		j++;
//		output[j] == 'M';
//		j++;
//		output[j] == 'M';
//		j++;
//		output[j] == 'E';
//		j++;
//		output[j] == 'N';
//		j++;
//		output[j] == 'T';
//		j++;
//		output[j] == ':';
//		j++;
//		output[j] = array[i]; // /
//		i++;
//		j++;
//		output[j] = array[i]; // //
//		i++;
//		j++;
//		COMMENT = YES;
//		COMMENTBEGANON = LINE; //comment that began on Line 1 never terminated.
//		while (COMMENTDONE == NO && array[i] != '\0')
//		{
//			if (array[i] == '*')
//			{
//				output[j] == array[i];
//				j++;
//				i++;
//				STAR = YES;
//			}
//			else if (array[i] == '/' && STAR == YES)
//			{
//				output[j] == array[i];
//				j++;
//				i++;
//				COMMENTDONE = YES;
//			}
//			else
//			{
//				output[j] == array[i];
//				j++;
//				i++;
//				STAR = NO;
//			}
//		}
//		if (array[i] == '\0' && COMMENTDONE == NO)
//		{
//			printf("Error: Unbalanced cooment. The comment that started on Line %d never finished.", COMMENTBEGANON);
//		}
//		COMMENT = NO;
//	}
//	else
//		;
//}
//else
//{
//	j++;
//	i++;
//}
//
//collects everything, line counts, all errors after ; prototype done, comment prototyp done, single quote and double quote prototype done, bracket prototype done, parenthesis prototype done, braces prototype, 

//#define MAXARRAYSIZE 10000
//main()
//{
//	int c;
//	char array[MAXARRAYSIZE];
//	int i = 0;
//	char output[MAXARRAYSIZE];
//	int j = 0;
//	char syntaxerror[MAXARRAYSIZE];
//	int k = 0;
//	int LeftBrackets = 0;
//	int RightBrackets = 0;
//	int EXTRABRACKETONLINE = 0;
//	int RightParenthesis = 0;
//	int LeftParanthesis = 0;
//	int EXTRAPARENTHESISONLINE = 0;
//	int RightBraces = 0;
//	int LeftBraces = 0;
//	int EXTRABRACESONLINE = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int COMMENTDONE = NO;
//	int COMMENTBEGANON = 0;
//	int COMMENTENDEDON = 0;
//	int LINE = 1;
//	int SYNTAXERROR = NO;
//	int SYNTAXERRORONLINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//	int SINGLEQUOTEBEGANON = 0;
//	int DOUBLEQUOTEBEGANON = 0;
//	while ((c = getchar()) != EOF)
//	{
//		array[i] = c;
//		i++;
//	}
//	array[i] = '\0';
//	i = 0;
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//
//		if (array[i] == '\n')
//		{
//			LINE++; //LINE COUNTER
//			if (LeftParanthesis > RightParenthesis)
//			{
//				printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d. \t", EXTRAPARENTHESISONLINE);
//			}
//			RightBrackets = 0;
//			LeftBrackets = 0;
//		}
//
//		output[j] = array[i]; //STORES EVERY CHARACTER FROM array
//
//		if (array[i] == ';') //THIS CHECKS FOR COMMENTS AFTER ;
//		{
//			i++;
//			j++;
//
//			output[j] = array[i]; //CHECKS EITHER // OR /* OR / OR WHITE SPACE OR NEWLINE . SIX DIFFERENT CASES.
//			if (LeftParanthesis > RightParenthesis)
//			{
//				printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d. \n", EXTRAPARENTHESISONLINE);
//			}
//			RightBrackets = 0;
//			LeftBrackets = 0;
//
//			while (array[i] != '\n' && array[i] != '\0') //WHILE THE CHARACTER WE JUST SAVED IS NOT THE NEW LINE \n CHECK THE SIX CASES
//			{
//				if (INACOMMENT == NO && array[i] != '/' && array[i] != '*' && array[i] != ' ' && array[i] != '\t') //CASE 6
//				{
//					while (array[i] != '/' && array[i] != '\n' && array[i] != '\0')
//					{
//						output[j] = array[i];
//						syntaxerror[k] = array[i];
//						SYNTAXERRORONLINE = LINE;
//						k++;
//						i++;
//						j++;
//					}
//					SYNTAXERROR = YES; //CASE 6 DONE
//				}
//
//				else if (array[i] == '/') //CASE 1 2 3 4 5
//				{
//					output[j] = array[i];
//
//					UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//					COMMENTBEGANON = LINE;
//
//					if (array[i + 1] == '/') //CASE 4
//					{
//						UNBALANCEDCOMMENT = NO;
//						INACOMMENT = YES;
//						while (array[i] != '\n')
//						{
//							i++;
//							j++;
//							output[j] = array[i]; //CASE 4 DONE
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
//						j++;
//						output[j] = array[i];
//						i++;
//						j++;
//						while (INACOMMENT == YES && array[i] != '\0')
//						{
//							if (array[i] == '\n')
//							{
//								LINE++; //LINE COUNTER
//							}
//							else if (array[i] == '*')
//							{
//								output[j] = array[i];
//								i++;
//								j++;
//								STAR = YES;
//							}
//							else if (array[i] == '/' && STAR == YES)
//							{
//								output[j] = array[i];
//								i++;
//								j++;
//								INACOMMENT = NO;
//								UNBALANCEDCOMMENT = NO;
//								COMMENTENDEDON = LINE;
//								STAR = NO;
//							}
//							else
//							{
//								output[j] = array[i];
//								i++;
//								j++;
//								STAR = NO;
//							}
//						}
//						if (INACOMMENT == NO && UNBALANCEDCOMMENT == NO)
//						{
//							printf("Multi-line comment that started on line %d and ended on %d. New line.\n", COMMENTBEGANON, COMMENTENDEDON); //CASE 5 DONE
//						}
//					}
//
//					else
//					{
//						while (array[i] != '\n')
//						{
//							syntaxerror[k] = array[i]; // / a b
//							i++;
//							j++;
//							k++;
//							if (array[i] != '\n')
//							{
//								output[j] = array[i]; // a b
//							}
//							SYNTAXERRORONLINE = LINE;
//						}
//						SYNTAXERROR = YES;
//					}
//				}
//				else
//				{
//					i++;
//					j++;
//				}
//			}
//
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				printf("Error: Unbalanced comment on line %d. Missing / or *.\n", COMMENTBEGANON);
//				output[j] = array[i];
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				j++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2 WHITESPACE DONE  //CASE 3 NEWLINE DONE //CASE 4 // DONE //CASE 5 /**/ DONE
//			{
//				output[j] = array[i]; //SAVES /n THEN NEXT -- EXITS CHECKING AFTER ;
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				j++;
//			}
//			if (SYNTAXERROR == YES) //CASE 6 DONE
//			{
//				syntaxerror[k] = '\0';
//				printf("Error: Syntax error. Text not in a comment on line %d. Code: %s\n", SYNTAXERRORONLINE, syntaxerror);
//				syntaxerror[0] = '\0';
//				k = 0;
//				output[j] = array[i];
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				j++;
//				SYNTAXERROR = NO;
//			}
//		} //; DONE
//
//
//		else if (array[i] == '/') //3 CASES
//		{
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			COMMENTBEGANON = LINE;
//
//			if (array[i + 1] == '/') //CASE 2
//			{
//				UNBALANCEDCOMMENT = NO;
//
//				INACOMMENT = YES;
//
//				while (array[i] != '\n')
//				{
//					i++;
//					j++;
//					output[j] = array[i];
//				}
//				INACOMMENT = NO; //CASE 2 DONE
//			}
//
//			else if (array[i + 1] == '*') //CASE 3
//			{
//				UNBALANCEDCOMMENT = YES;
//
//				INACOMMENT = YES;
//
//				COMMENTBEGANON = LINE;
//
//				while (INACOMMENT == YES && array[i] != '\0')
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//					}
//					if (array[i] == '*')
//					{
//						i++;
//						j++;
//						output[j] == array[i];
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						i++;
//						j++;
//						output[j] == array[i];
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//					}
//					else
//					{
//						i++;
//						j++;
//						output[j] == array[i];
//						STAR = NO;
//					}
//				}
//				if (INACOMMENT == NO && UNBALANCEDCOMMENT == NO && SYNTAXERROR == NO)
//				{
//					printf(" End of multi line comment that started on line %d. New line will be printed in case the next character is not a whitespace \n", COMMENTBEGANON); //CASE 3 DONE
//				}
//			}
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				printf("Error: Unbalanced comment on line %d. Missing / or *.\n", COMMENTBEGANON);
//				output[j] = array[i];
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				j++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				output[j] = array[i]; //SAVES /n THEN NEXT
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//				}
//
//				i++;
//				j++;
//			}
//		}
//
//		else if (array[i] == '\'' && array[i - 1] != '\\')
//		{
//			INASINGLEQUOTE = YES;
//			SINGLEQUOTEBEGANON = LINE;
//			i++;
//			j++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n') //could use one variable INAQUOTE
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\')
//				{
//					INASINGLEQUOTE = NO;
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//				else
//				{
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				printf("Error: Uneven single quote. The quote that started on line %d is missing a single quote \'.\n", SINGLEQUOTEBEGANON);
//				INASINGLEQUOTE = NO;
//			}
//
//		}
//
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			DOUBLEQUOTEBEGANON = LINE; //could use one variable QUOTEBEGANON
//			i++;
//			j++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n') //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//				else
//				{
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				printf("Error: Uneven double quote. The double quote that started on line %d is missing a single quote \".\n", DOUBLEQUOTEBEGANON);
//				INADOUBLEQUOTE = NO;
//			}
//		}
//
//		else if (array[i] == '[')
//		{
//			LeftBrackets++;
//			EXTRABRACKETONLINE = LINE;
//
//			i++;
//			j++;
//			if (LeftBrackets - RightBrackets > 1)
//			{
//				printf("Error: Uneven brackets. An extra [ was found on line %d.\n", EXTRABRACKETONLINE);
//			}
//		}
//		else if (array[i] == ']')
//		{
//			RightBrackets++;
//			EXTRABRACKETONLINE = LINE;
//
//			i++;
//			j++;
//			if (RightBrackets - LeftBrackets > 0)
//			{
//				printf("Error: Uneven brackets. An extra ] was found on line %d.\n", EXTRABRACKETONLINE);
//			}
//		}
//
//		else if (array[i] == '(')
//		{
//			LeftParanthesis++;
//			EXTRAPARENTHESISONLINE = LINE;
//
//			i++;
//			j++;
//		}
//		else if (array[i] == ')')
//		{
//			RightParenthesis++;
//			EXTRAPARENTHESISONLINE = LINE;
//
//			i++;
//			j++;
//			if (RightParenthesis > LeftParanthesis)
//			{
//				printf("Error: Uneven Right Parenthesis. An extra ) was found on line %d.\n", EXTRAPARENTHESISONLINE);
//			}
//		}
//
//		else if (array[i] == '{')
//		{
//			LeftBraces++;
//			EXTRABRACESONLINE = LINE;
//
//			i++;
//			j++;
//		}
//		else if (array[i] == '}')
//		{
//			RightBraces++;
//			EXTRABRACESONLINE = LINE;
//
//			i++;
//			j++;
//			if (RightBraces > LeftBraces)
//			{
//				printf("Error: Uneven Right Braces. An extra } was found on line %d.\n", EXTRABRACESONLINE);
//			}
//		}
//		else if (array[i] != '\0' && array[i] != EOF)
//		{
//			i++;
//			j++;
//		}
//		else
//			;
//	}
//
//	if (LeftBraces > RightBraces)
//	{
//		printf("Error: Uneven Left Braces. An extra { was found on line %d.\n", EXTRABRACESONLINE);
//	}
//
//	output[j] = '\0'; //DONE
//	printf("%s\n", output); //PRINT OUTPUT
//}
/*
error
error; error
error; / error
error; //noerror
error; /*noerror*/
//error;/*noerror
//*/
//error; /*error/
//error; /*error*8/
//error:
//*/
//#define MAXARRAYSIZE 20000
//main()
//{
//	int c;
//	char array[MAXARRAYSIZE];
//	int i = 0;
//	char output[MAXARRAYSIZE];
//	int j = 0;
//	char syntaxerror[MAXARRAYSIZE];
//	int k = 0;
//	int LeftBrackets = 0;
//	int RightBrackets = 0;
//	int EXTRABRACKETONLINE = 0;
//	int RightParenthesis = 0;
//	int LeftParanthesis = 0;
//	int EXTRAPARENTHESISONLINE = 0;
//	int RightBraces = 0;
//	int LeftBraces = 0;
//	int EXTRALEFTBRACEONLINE = 0;
//	int EXTRARIGHTBRACEONLINE = 0;
//	int STAR = NO;
//	int UNBALANCEDCOMMENT = NO;
//	int INACOMMENT = NO;
//	int COMMENTDONE = NO;
//	int COMMENTBEGANON = 0;
//	int COMMENTENDEDON = 0;
//	int LINE = 2362;
//	int SYNTAXERROR = NO;
//	int SYNTAXERRORONLINE = 0;
//	int INASINGLEQUOTE = NO;
//	int INADOUBLEQUOTE = NO;
//	int SINGLEQUOTEBEGANON = 0;
//	int DOUBLEQUOTEBEGANON = 0;
//	int HEXSYNTAXERROR = NO;
//	int HEXSYNTAXERRORBEGANON = 0;
//	//octal (come back)
//	while ((c = getchar()) != EOF)
//	{
//		array[i] = c;
//		i++;
//	}
//	array[i] = '\0';
//	i = 0;
//	printf("\n");//appears after data collection. if this was placed at the beginning of the program after the declarations the newline would be printed before the data collection (the terminal would appear initiate with a newline.
//	while (array[i] != '\0' && array[i] != EOF)
//	{
//
//		if (array[i] == '\n')
//		{
//			LINE++; //LINE COUNTER
//			if (LeftParanthesis > RightParenthesis)
//			{
//				printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//			}
//			RightBrackets = 0;
//			LeftBrackets = 0;
//			RightParenthesis = 0;
//			LeftParanthesis = 0;
//		}
//		output[j] = array[i]; //STORES EVERY CHARACTER FROM array
//
//		if (array[i] == ';') //THIS CHECKS FOR COMMENTS AFTER ;
//		{
//			i++;
//			j++;
//
//			output[j] = array[i]; //CHECKS EITHER // OR /* OR / OR WHITE SPACE OR NEWLINE . SIX DIFFERENT CASES.
//			if (LeftParanthesis > RightParenthesis)
//			{
//				printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d. \n", EXTRAPARENTHESISONLINE);
//			}
//			RightBrackets = 0;
//			LeftBrackets = 0;
//
//			while (array[i] != '\n' && array[i] != '\0' && array[i] != EOF) //WHILE THE CHARACTER WE JUST SAVED IS NOT THE NEW LINE \n CHECK THE SIX CASES
//			{
//				if (INACOMMENT == NO && array[i] != '/' && array[i] != '*' && array[i] != ' ' && array[i] != '\t') //CASE 6
//				{
//					while (array[i] != '/' && array[i] != '\n' && array[i] != '\0')
//					{
//						output[j] = array[i];
//						syntaxerror[k] = array[i];
//						SYNTAXERRORONLINE = LINE;
//						k++;
//						i++;
//						j++;
//					}
//					syntaxerror[k] = ' ';
//					k++;
//					SYNTAXERROR = YES; //CASE 6 DONE
//				}
//
//				else if (array[i] == '/') //CASE 1 2 3 4 5
//				{
//					output[j] = array[i];
//
//					UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//					COMMENTBEGANON = LINE;
//
//					if (array[i + 1] == '/') //CASE 4
//					{
//						UNBALANCEDCOMMENT = NO;
//						INACOMMENT = YES;
//						while (array[i] != '\n')
//						{
//							i++;
//							j++;
//							output[j] = array[i]; //CASE 4 DONE
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
//						j++;
//						output[j] = array[i];
//						i++;
//						j++;
//						while (INACOMMENT == YES && array[i] != '\0')
//						{
//							if (array[i] == '\n')
//							{
//								LINE++; //LINE COUNTER
//								output[j] = array[i];
//								i++;
//								j++;
//								if (LeftParanthesis > RightParenthesis)
//								{
//									printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//								}
//								RightBrackets = 0;
//								LeftBrackets = 0;
//								RightParenthesis = 0;
//								LeftParanthesis = 0;
//							}
//							else if (array[i] == '*')
//							{
//								output[j] = array[i];
//								i++;
//								j++;
//								STAR = YES;
//							}
//							else if (array[i] == '/' && STAR == YES)
//							{
//								output[j] = array[i];
//								i++;
//								j++;
//								INACOMMENT = NO;
//								UNBALANCEDCOMMENT = NO;
//								COMMENTENDEDON = LINE;
//								STAR = NO;
//							}
//							else
//							{
//								output[j] = array[i];
//								i++;
//								j++;
//								STAR = NO;
//							}
//						}
//						if (INACOMMENT == NO && UNBALANCEDCOMMENT == NO)
//						{
//							printf("Multi-line comment started on line %d and ended on %d.\n", COMMENTBEGANON, COMMENTENDEDON); //CASE 5 DONE
//						}
//					}
//
//					else
//					{
//						syntaxerror[k] = array[i];
//						output[j] = array[i];
//						i++;
//						j++;
//						k++;
//
//						while (array[i] != '\n' && array[i] != '/' && array[i] != '\0' && array[i] != EOF)
//						{
//							syntaxerror[k] = array[i]; // / a b
//							output[j] = array[i];
//							i++;
//							j++;
//							k++;
//							SYNTAXERRORONLINE = LINE;
//						}
//						SYNTAXERROR = YES;
//					}
//				}
//				else
//				{
//					; //NEXT CHARACTER HANDLED IN THE UNBALANCED COMMENT CODE BLOCK
//					/*i++;
//					j++;*/
//				}
//			}
//
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				printf("Error: Unbalanced comment on line %d. Missing / or *.\n", COMMENTBEGANON);
//				output[j] = array[i];
//
//				if (array[i] == '\0')
//				{
//					printf("\n%s\n", output);
//				}
//				if (array[i] == '\n')
//				{
//					LINE++;
//					if (LeftParanthesis > RightParenthesis)
//					{
//						printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//					}
//					RightBrackets = 0;
//					LeftBrackets = 0;
//					RightParenthesis = 0;
//					LeftParanthesis = 0;
//				}
//
//				i++;
//				j++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2 WHITESPACE DONE  //CASE 3 NEWLINE DONE //CASE 4 // DONE //CASE 5 /**/ DONE
//			{
//				output[j] = array[i]; //SAVES /n THEN NEXT -- EXITS CHECKING AFTER ;
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//					if (LeftParanthesis > RightParenthesis)
//					{
//						printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//					}
//					RightBrackets = 0;
//					LeftBrackets = 0;
//					RightParenthesis = 0;
//					LeftParanthesis = 0;
//				}
//
//				i++;
//				j++;
//			}
//			if (SYNTAXERROR == YES) //CASE 6 DONE
//			{
//				syntaxerror[k] = '\0';
//				printf("Error: Syntax error. Text not in a comment on line %d. Code: %s\n", SYNTAXERRORONLINE, syntaxerror);
//				syntaxerror[0] = '\0';
//				k = 0;
//				output[j] = array[i];
//
//				if (array[i] == '\n')
//				{
//					if (LeftParanthesis > RightParenthesis)
//					{
//						printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//					}
//					LINE++;
//					RightBrackets = 0;
//					LeftBrackets = 0;
//					RightParenthesis = 0;
//					LeftParanthesis = 0;
//				}
//
//				i++;
//				j++;
//				SYNTAXERROR = NO;
//			}
//		} //; DONE
//		else if (array[i] == '/') //3 CASES
//		{
//			output[j] = array[i];
//
//			UNBALANCEDCOMMENT = YES; //CASE 1 DONE
//
//			COMMENTBEGANON = LINE;
//
//			if (array[i + 1] == '/') //CASE 4
//			{
//				UNBALANCEDCOMMENT = NO;
//				INACOMMENT = YES;
//				while (array[i] != '\n')
//				{
//					i++;
//					j++;
//					output[j] = array[i]; //CASE 4 DONE
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
//				j++;
//				output[j] = array[i];
//				i++;
//				j++;
//				while (INACOMMENT == YES && array[i] != '\0')
//				{
//					if (array[i] == '\n')
//					{
//						LINE++; //LINE COUNTER
//						output[j] = array[i];
//						i++;
//						j++;
//						if (LeftParanthesis > RightParenthesis)
//						{
//							printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//						}
//						RightBrackets = 0;
//						LeftBrackets = 0;
//						RightParenthesis = 0;
//						LeftParanthesis = 0;
//					}
//					else if (array[i] == '*')
//					{
//						output[j] = array[i];
//						i++;
//						j++;
//						STAR = YES;
//					}
//					else if (array[i] == '/' && STAR == YES)
//					{
//						output[j] = array[i];
//						i++;
//						j++;
//						INACOMMENT = NO;
//						UNBALANCEDCOMMENT = NO;
//						COMMENTENDEDON = LINE;
//						STAR = NO;
//					}
//					else
//					{
//						output[j] = array[i];
//						i++;
//						j++;
//						STAR = NO;
//					}
//				}
//				if (INACOMMENT == NO && UNBALANCEDCOMMENT == NO)
//				{
//					printf("Multi-line comment started on line %d and ended on %d.\n", COMMENTBEGANON, COMMENTENDEDON);
//				}
//			}
//			else
//				; //NEXT CHARACTER HANDLED IN THE UNBALANCED CODE BLOCK
//			if (UNBALANCEDCOMMENT == YES) //CASE 1
//			{
//				printf("Error: Unbalanced comment on line %d. Missing / or *.\n", COMMENTBEGANON);
//				output[j] = array[i];
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//					if (LeftParanthesis > RightParenthesis)
//					{
//						printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//					}
//					RightBrackets = 0;
//					LeftBrackets = 0;
//					RightParenthesis = 0;
//					LeftParanthesis = 0;
//				}
//
//				i++;
//				j++;
//				UNBALANCEDCOMMENT = NO;
//			}
//
//			else if (UNBALANCEDCOMMENT == NO) //CASE 2
//			{
//				output[j] = array[i]; //SAVES /n THEN NEXT
//
//				if (array[i] == '\n')
//				{
//					LINE++;
//					if (LeftParanthesis > RightParenthesis)
//					{
//						printf("Error: Uneven Left Parenthesis. An extra ( was found on line %d.\n", EXTRAPARENTHESISONLINE);
//					}
//					RightBrackets = 0;
//					LeftBrackets = 0;
//					RightParenthesis = 0;
//					LeftParanthesis = 0;
//				}
//
//				i++;
//				j++;
//			}
//		}
//
//		else if (array[i] == '\'' && array[i - 1] != '\\') //wow '\\' is reading \' wow SO THE CODE READS ' and before that the last two characters are \\. cases like \"' work as expected before this fix. LATEST DEBUG 5:02 PM 11/20/2019
//		{
//			INASINGLEQUOTE = YES;
//			SINGLEQUOTEBEGANON = LINE;
//			i++;
//			j++;
//
//			while (INASINGLEQUOTE == YES && array[i] != '\n') //if hex number must be 0-9 A-F until a space is read.
//			{
//				if (array[i] == '\'' && array[i - 1] != '\\') // && array[i-2] == "\""
//				{
//					INASINGLEQUOTE = NO;
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//				else if (array[i] == '\'' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INASINGLEQUOTE = NO;
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//				else if (array[i] == 'x' && array[i - 1] == '\\' && array[i-2] != '\\')
//				{
//					output[j] = array[i];
//
//					i++;
//					j++;
//					while (array[i] != ' ' && array[i] != '\'' && array[i] != '\n')
//					{
//						if (array[i] != '0' && array[i] != '1' && array[i] != '2' && array[i] != '3' && array[i] != '4' && array[i] != '5' && array[i] != '6' && array[i] != '7' && array[i] != '8' && array[i] != '9' && array[i] != 'A' && array[i] != 'B' && array[i] != 'C' && array[i] != 'D' && array[i] != 'E' && array[i] != 'F')
//						{
//							HEXSYNTAXERROR = YES;
//							HEXSYNTAXERRORBEGANON = LINE;
//						}
//						output[j] = array[i];
//
//						i++;
//						j++;
//					}
//				}
//				else
//				{
//
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//			}
//			if (INASINGLEQUOTE == YES)
//			{
//				printf("Error: Uneven single quote. The single quote that started on line %d is missing a single quote \'.\n", SINGLEQUOTEBEGANON);
//				INASINGLEQUOTE = NO;
//			}
//			if (HEXSYNTAXERROR == YES)
//			{
//				printf("Error: Syntax error. The hexidecimal number on line %d is not acceptable.\n", HEXSYNTAXERRORBEGANON);
//				HEXSYNTAXERROR = NO;
//			}
//		}
//
//		else if (array[i] == '"' && array[i - 1] != '\\')
//		{
//			INADOUBLEQUOTE = YES;
//			DOUBLEQUOTEBEGANON = LINE; //could use one variable QUOTEBEGANON
//			i++;
//			j++;
//			while (INADOUBLEQUOTE == YES && array[i] != '\n') //could use one variable INAQUOTE
//			{
//				if (array[i] == '"' && array[i - 1] != '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//				else if (array[i] == '"' && array[i - 1] == '\\' && array[i - 2] == '\\')
//				{
//					INADOUBLEQUOTE = NO;
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//				else if (array[i] == 'x' && array[i - 1] == '\\' && array[i - 2] != '\\')
//				{
//					output[j] = array[i];
//
//					i++;
//					j++;
//					while (array[i] != ' ' && array[i] != '\'' && array[i] != '\n')
//					{
//						if (array[i] != '0' && array[i] != '1' && array[i] != '2' && array[i] != '3' && array[i] != '4' && array[i] != '5' && array[i] != '6' && array[i] != '7' && array[i] != '8' && array[i] != '9' && array[i] != 'A' && array[i] != 'B' && array[i] != 'C' && array[i] != 'D' && array[i] != 'E' && array[i] != 'F')
//						{
//							HEXSYNTAXERROR = YES;
//							HEXSYNTAXERRORBEGANON = LINE;
//						}
//						output[j] = array[i];
//
//						i++;
//						j++;
//					}
//				}
//				else
//				{
//					output[j] = array[i];
//
//					i++;
//					j++;
//				}
//			}
//			if (INADOUBLEQUOTE == YES)
//			{
//				printf("Error: Uneven double quote. The double quote that started on line %d is missing a double quote \".\n", DOUBLEQUOTEBEGANON);
//				INADOUBLEQUOTE = NO;
//			}
//			if (HEXSYNTAXERROR == YES)
//			{
//				printf("Error: Syntax error. The hexidecimal number on line %d is not acceptable.\n", HEXSYNTAXERRORBEGANON);
//				HEXSYNTAXERROR = NO;
//			}
//		}
//
//		else if (array[i] == '[')
//		{
//			LeftBrackets++;
//			EXTRABRACKETONLINE = LINE;
//
//			i++;
//			j++;
//			if (LeftBrackets - RightBrackets > 1)
//			{
//				printf("Error: Uneven brackets. An extra [ was found on line %d.\n", EXTRABRACKETONLINE);
//			}
//		}
//		else if (array[i] == ']')
//		{
//			RightBrackets++;
//			EXTRABRACKETONLINE = LINE;
//
//			i++;
//			j++;
//			if (RightBrackets - LeftBrackets > 0)
//			{
//				printf("Error: Uneven brackets. An extra ] was found on line %d.\n", EXTRABRACKETONLINE);
//			}
//		}
//
//		else if (array[i] == '(')
//		{
//			LeftParanthesis++;
//			EXTRAPARENTHESISONLINE = LINE;
//
//			i++;
//			j++;
//		}
//		else if (array[i] == ')')
//		{
//			RightParenthesis++;
//			EXTRAPARENTHESISONLINE = LINE;
//
//			i++;
//			j++;
//			if (RightParenthesis > LeftParanthesis)
//			{
//				printf("Error: Uneven Right Parenthesis. An extra ) was found on line %d.\n", EXTRAPARENTHESISONLINE);
//			}
//		}
//
//		else if (array[i] == '{')
//		{
//			LeftBraces++;
//			EXTRALEFTBRACEONLINE = LINE;
//
//			i++;
//			j++;
//		}
//		else if (array[i] == '}')
//		{
//			RightBraces++;
//			EXTRARIGHTBRACEONLINE = LINE;
//
//			i++;
//			j++;
//			if (RightBraces > LeftBraces)
//			{
//				printf("Error: Uneven Right Braces. An extra } was found on line %d.\n", EXTRARIGHTBRACEONLINE);
//			}
//		}
//		else if (array[i] != '\0' && array[i] != EOF)
//		{
//			i++;
//			j++;
//		}
//		else
//			;
//	}
//
//	if (LeftBraces > RightBraces)
//	{
//		printf("Error: Uneven Left Braces. An extra { was found on line %d.\n", EXTRALEFTBRACEONLINE);
//	}
//
//	output[j] = '\0'; //DONE
//	printf("\n%s\n", output); //PRINT OUTPUT
//}