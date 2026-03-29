#include<stdio.h>
#include<string.h>
typedef struct
{
	char data[20];
	char address[30];
	char name[30];
}student; 	 
void function(student *p)
{
    strcpy((*p).data,"3.24");
	strcpy((*p).address,"北京");
	strcpy((*p).name,"小王");	
}
int main()
{
	student a[2];
	function(&a[0]);
	strcpy(a[1].data,"3.25");
	strcpy(a[1].address,"广州");
	strcpy(a[1].name,"小唐");
	for(int i = 0;i < 2;i++)
	{
		printf("日期%s，地点%s，名字%s\n",a[i].data,a[i].address,a[i].name);
	}
	return 0;
}	 
	 
	 
