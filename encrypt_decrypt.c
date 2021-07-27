#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Vigenere();
void Caesar();
int Input;
void main()
{
    printf("Select: 1 for Vigenere Cipher\n");
    printf("Select: 2 for Caesar Ciper\n");
    printf("Select your Cipher method: ");
    scanf("%d" ,&Input);
    switch (Input)
    {
    case 1:
        Vigenere();
        break;
    case 2: 
        Caesar();
        break;
    default:
        printf("Wrong Choice... Exiting Program!");
        exit(0);
        break;
    }
}
void Vigenere()
{
    char MessageV[50], KeyV[50];
    printf("Enter your Text: ");
    scanf("%s" ,MessageV);
    printf("Enter yoyr Key: ");
    scanf("%s" ,KeyV);
    int MessageLen, KeyLen, i, j;
    MessageLen = strlen(MessageV);
    KeyLen = strlen(KeyV);
    int InputV;
    char nKey[MessageLen], EncrpytMsg[MessageLen], DecryptMsg[MessageLen];
    printf("Do you want to Encrypt or Decrypt your text? [1---> Encrypt|| 2---> Decrypt]: ");
    scanf("%d" ,&InputV);
    for(i = 0, j = 0; i < MessageLen; ++i, ++j){
        if(j == KeyLen)
            j = 0;
 
        nKey[i] = KeyV[j];
    }
     nKey[i] = '\0';
    switch (InputV)
    {
    case 1:
         for(i = 0; i < MessageLen; ++i)
         EncrpytMsg[i] = ((MessageV[i] + nKey[i])%26 ) + 'A'; 
         EncrpytMsg[i] = '\0';      
         printf("Your Encrypted Message is: %s" ,EncrpytMsg);
        break;
    case 2:
        for(i = 0; i < MessageLen; ++i)
        DecryptMsg[i] = (((EncrpytMsg[i] - nKey[i]) + 26) % 26) + 'A'; 
        DecryptMsg[i] = '\0';
        printf("Your Decrypt Message is: %s" ,DecryptMsg);
    }

}
void Caesar()
{
    int i, InputC ,cKey;
    char MessageC[100], ch;
    printf("Enter Your Message: ");
    scanf("%s" ,MessageC);
    printf("Enter Your Key: ");
    scanf("%d" ,&cKey);
    printf("Do you want to Encrypt or Decrypt your text? [1---> Encrypt|| 2---> Decrypt]: ");
    scanf("%d" ,&InputC);
    switch (InputC)
    {
    case 1:
    for(i = 0; MessageC[i] != '\0'; ++i){
ch = MessageC[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch + cKey;
if(ch > 'z'){
ch = ch - 'z' + 'a' - 1;
}
MessageC[i] = ch;
}
else if(ch >= 'A' && ch <= 'Z'){
ch = ch + cKey;
if(ch > 'Z'){
ch = ch - 'Z' + 'A' - 1;
}
MessageC[i] = ch;
}
    }
    printf("You Encrypted Message is: %s\n" ,MessageC);

case 2:
for(i = 0; MessageC[i] != '\0'; ++i)
{
ch = MessageC[i];
if(ch >= 'a' && ch <= 'z'){
ch = ch - cKey;
if(ch < 'a'){
ch = ch + 'z' - 'a' + 1;
}
MessageC[i] = ch;
}
else if(ch >= 'A' && ch <= 'Z')
{
ch = ch - cKey;
if(ch < 'A')\
{
ch = ch + 'Z' - 'A' + 1;
}
MessageC[i] = ch;
}
}
printf("You Decrypted Message is: %s\n" ,MessageC);
break;
}
}