#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void animation(){
int i;//for fake working signal
struct timespec onePause;
onePause.tv_sec=0;
onePause.tv_nsec=90000000;
printf("Working .");
fflush(stdout);
for(i=0;i<20;i++){
	nanosleep(&onePause,NULL);//pause for nano seconds. Linux altenative for delay
	printf(".");
	fflush(stdout);
   }
	printf("\n");
}
void removeme(char* str,int pos){	//to remove char from selected position and compress the character array
int i,len;
len = strlen(str);
for(i=pos;i<len;i++)
	str[i]=str[i+1];
}
void makelower(char* str){
int i;
for(i=0;i<strlen(str);i++)
	str[i] = tolower(str[i]);
str[i] = '\0';
}
int lovemeter(char* nam1,char* nam2) {
char name1[20],name2[20];
char sent[50],ch;
int i,j,k,len,temp,nums[50];

strcpy(name1,nam1);
strcpy(name2,nam2);
makelower(name1);
makelower(name2);

sent[0]='\0';   //clearing it out.-- It eats my 2 hour time.
strcat(sent, name1);
strcat(sent,"loves");
strcat(sent,name2);

int count_match;	//as they used to count the number of occurance
k=0;
for(;;)
{
 ch = sent[0];
 if(ch == '\0') //until string is come to end
 	break;
 count_match=0;
 for(j=0; ;j++)
  {
  if(sent[j]=='\0')
    break;
  if(ch == sent[j]){
     count_match++;		//if char matched increate the counter remove the char
     removeme(sent,j);
     j--;
     }
  }
  nums[k++]= count_match;	//save it for further processing
}

return computeLove(nums,k);
}
void analysis(int loveper,char* nam1,char* nam2) {
	
printf("  \'%s\' LOVES \'%s\'  = %d%%\n",nam1,nam2,loveper);
switch(loveper/10){
case 10:
	printf("  WOW !!!  What a perfect Relationship.\n");
	printf("  Contratulation %s and %s.\n",nam1,nam2);
	break;
case 9:
case 8:
case 7:
	printf("  Congratualtion for being loved Mr/s. %s.\n",nam2);
	break;
case 6:
case 5:
	printf("  Balanced Relationship. Good.\n");
	break;
case 4:
case 3:
	printf("  Not bad, try to win %s's heart %s.\n",nam1,nam2);
	break;
case 2:
case 1:
	("  Sorry %s. Better improving your relation with %s\n",nam2,nam1);
	break;
case 0:
	printf("  It is better to THINK the other way %s.\n",nam2);
}

}
int computeLove(int* nums,int len){
int sum,k,i,j,rem,tnums[50];
len = len-1;
for(;;){
if(len<=1)
  return(nums[0]*10+nums[1]);
else if ((len==2)&&(nums[0]*100+nums[1]+nums[2] == 100))
  return(100);
else{
	j=0;
	for(i=0; ;)
	{
	if(i>(len-i))
		break;
	else if(i==(len-i)) //if odd no 
		sum=nums[i];
	else
	    sum = nums[i] + nums[len-i];
	    	    
	if((sum/10) != 0){ //if two digit
		tnums[j++]=sum/10;
		tnums[j++]=sum%10;
	     }
	else
		tnums[j++]=sum;
	i++;
	} //end i for looop
	for(k=0;k<j;k++){
		nums[k] = tnums[k];
		}
	len = k-1;
    }//end else
  }//end infinite for loop
}//end fucntion reduce

int main(int argc, char* argv[])
{
if(argc!=3){ 	//error when both name are not given.
printf("Usage: %s <lover1> <lover2>\n",argv[0]);
exit(0);
}
printf("__________________________________________\n");
printf("     %s -> %s\n",argv[1],argv[2]);
printf("==========================================\n");
animation(); // show fake busy animation
int per1 = lovemeter(argv[1],argv[2]);
//printf("%s LOVES %s %d%%\n",argv[1],argv[2],per1);
analysis(per1,argv[1],argv[2]);
printf("__________________________________________\n");
printf("\n\n");
printf("__________________________________________\n");
printf("     %s -> %s\n",argv[2],argv[1]);
printf("==========================================\n");
animation(); // show fake busy animation
int per2 = lovemeter(argv[2],argv[1]);
//printf("%s LOVES %s %d%%\n",argv[2],argv[1],per2);
analysis(per2,argv[2],argv[1]);
printf("__________________________________________\n");
return 0;
}
