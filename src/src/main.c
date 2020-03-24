#include "main.h"

//Global variable to check which button is pressed
int8_t messageIndex = -1;

char *test_strings[] = {
	"developing",
	"embeded",
	"lab",
	"with",
	"interruptions"
};

int main()
{
	InitializeDelay();
	InitializeButtons();
	InitializeInterruptions();
	
	InitializeLCD();
	
	while(1){
		if(messageIndex != -1){
			ClearDisplay();
			WriteString(test_strings[messageIndex]);
			messageIndex = -1;
		}				
	}
}
