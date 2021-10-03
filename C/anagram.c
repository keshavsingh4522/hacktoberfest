/* anagram or not */
#include<stdio.h>
#include<string.h>
int main(){
	char t,arr1[260],arr2[260];
	int i,j,n1,n2;
	gets(arr1);
	gets(arr2);
	n1=strlen(arr1);
	n2=strlen(arr2);
	if(n1!=n2){
		printf("Not anagram\n");
		return 0;
	}
	for(i=0;i<n1-1;i++){
		for(j=i+1;j<n1;j++){
			if(arr1[i]>arr1[j]){
				t=arr1[i];
				arr1[i]=arr1[j];
				arr1[j]=t;
			}
			if(arr2[i]>arr2[j]){
				t=arr2[i];
				arr2[i]=arr2[j];
				arr2[j]=t;
			}
		}
	}
	for(i=0;i<n1;i++){
		if(arr1[i] != arr2[i]){
			printf("Not anagram\n");
			return 0;
		}
	}
	printf("Anagram\n");
	return 0;
}
