#include<stdio.h>


struct student
{
 char name[30];
 int reg;
 int marks;
};

int main()
{

 struct student s[20], temp;
 int i,j,n,s1,s2,s3,sum,ct=1;
 
 printf("Enter n:\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter name, registration no and marks of student in 3 subjects:\n");
  scanf("%s%d%d%d%d",s[i].name, &s[i].reg, &s1, &s2, &s3);
  sum=s1+s2+s3;
  s[i].marks = sum;
 }
 for(i=0;i< n-1;i++)
 {
  for(j=i+1;j< n;j++)
  {
   if(s[i].marks<s[j].marks)
   {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
   }
  }
 }
 printf("Ranklist:\n");
 for(i=0;i<n;i++)
 {
  printf("Rank: %d\n", ct);  
  printf("Name: %s\n", s[i].name);
  printf("Registration no: %d\n", s[i].reg);
  printf("Marks: %d\n\n", s[i].marks);
  ct++;
 }
 return 0;
}