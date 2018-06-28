#include "CException.h"
#include "unity.h"
#include "Exception.h"

#define ERR_OUT_OF_BOUND 3
#define ERR_UNKNOWN_COMPANY 4
#define ERR_UNKNOWN_PEOPLE 5

void setUp(void)
{
}

void tearDown(void)
{
}

//name is array 3 of pointer to char
char *names[] = {
	"Ali",
	"David",
	"Ah Beng",
	"Sally"
};

char *namesInIntel[] = {
	"Getha",
	"Sammy",
	"Ah Cheng",
	"Molly"
};

char *namesInNXP[] = {
	"Gambor",
	"Muller",
	"Slokovac",
	"Bambi"
};

char *namesInMicron[] = {
	"Mumbo",
	"Jumbo",
	"Lambo",
	"Sambo"
};

char *namesInNestle[] = {
	"Layla",
	"Ah Shoong",
	"Ah Tan",
	"Samanda"
};

char *copanies[] = {
	"Intel",
	"NXP",
	"Micron",
	"Nestle"
};

void *getNameInTable(int index, char *name[], int maxSize)
{
	if(index >= maxSize || index < 0)
		Throw(ERR_OUT_OF_BOUND);
	return names[index];
}

char getName(int index)
{
	if(index >= 4 || index <0)
		Throw(ERR_OUT_OF_BOUND);
	return names[index];
}

char *getNameInCompany(int companyIdx, int nameIdx)
{
	CEXCEPTION_T e;
	char *name;
	switch(companyIdx)
	{
		case 0:
			Try{
			name = getNameInTable(nameIdx, namesInIntel, 4);
			} Catch(e){
				if(e == ERR_UNKNOWN_PEOPLE)
					printf("You are looking for unknown person at intel. The index number you gave was %d\n", nameIdx);
					Throw(e);   //Rethrow the exception
			}
			break;
		case 1:
			name = getNameInTable(nameIdx, namesInMicron, 4);
			break;
		case 2:
			name = getNameInTable(nameIdx, namesInNXP, 4);
			break;
		case 3:
			name = getNameInTable(nameIdx, namesInNestle, 4);
			break;
		default:
			Throw(ERR_UNKNOWN_COMPANY);
	}
}
void test_getNameInCompany_given_company11_and_people10_expect_ERR_UNKNOWN_COMPANY
{
	CEXCEPTION_T e;
	char *name;
	
	Try{
		name = getNameInCompany(1,2);
		TEST_ASSERT_EQUAL_STRING("Slokovac", name);
	}Catch(e)
		{
			//printf("error code: %d", e);
		}

}
void test_getName_given_1_expect_David(void)
{
	CEXCEPTION_T e;
    char *name;
	
	Try{
		name = getName(-1);
		TEST_ASSERT_EQUAL_STRING("David", name);
	}Catch(e){
		printf("error code:%d\n", e);
	}
}

void test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND(void)
{
	CEXCEPTION_T e;
    char *name;
	
	Try{
		name = getName(-1);
		TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none.");
	}Catch(e){
		//printf("error code:%d\n", e);
	}
	
//	TEST_ASSERT_EQUAL_STRING("David", name);
}

void test_getName_given_4_expect_ERR_OUT_OF_BOUND(void)
{
	CEXCEPTION_T e;
    char *name;
	
	Try{
		name = getName(4);
		TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND to be thrown, but none.");
	}Catch(e){
		//printf("error code:%d\n", e);
	}
	
//	TEST_ASSERT_EQUAL_STRING("David", name);
}
