// C code to demonstrate the working of 
// strpbrk 
#include <stdio.h> 
#include <string.h> 

// Driver function 
int main() 
{ 
	// Declaring three strings 
	char s1[] = "geeksforgeeks"; 
	char s2[] = "app"; 
	char s3[] = "kite"; 
	char* r, *t; 

	// Checks for matching character 
	// no match found 
	r = strpbrk(s1, s2); 
	if (r != 0) 
		printf("First matching character: %c\n", *r); 
	else
		printf("Character not found"); 

	// Checks for matching character 
	// first match found at "e" 
	t = strpbrk(s1, s3); 
	if (t != 0) 
		printf("\nFirst matching character: %c\n", *t); 
	else
		printf("Character not found"); 

	return (0); 
} 
