#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void revStr(char *a)
{
    int n = strlen(a);
    for (int i = 0; i < n / 2; i++)
{
   char b=a[i];
a[i]=a[n-i-1];
a[n-i-1]=b;
}
}

static char** createArray(int a)
{
    char **p=malloc(sizeof(char *)*a);
    return p;
}

static int is_same(const char *a,const char *b)
{
    if(strlen(a)!=strlen(b))
		return 0;
    int v=strlen(b);
    for(int i=0;i<v;i++)
	{
        if(a[i]!=b[i])
		{
            return 0;
        }
    }
    return 1;
}

static char *copy(const char *a)
{
    int b=strlen(a);
    char *p=malloc(sizeof(char)*(b+1));
    for(int i=0;i<=b;i++)
{
        p[i]=a[i];
    }
    return p;
}

int intal_compare(const char* intal1, const char* intal2){
	
	int intal1_len = strlen(intal1);
	int intal2_len = strlen(intal2);
	

	if(intal1_len>intal2_len){
		 
		return 1;
	}
	else if(intal1_len<intal2_len){
		
		return -1;
	}


	for(int i=0;i<intal1_len;i++){
			int int1 = intal1[i] - '0';
			int int2 = intal2[i] - '0';
			if(int1==int2)
				continue;
			else if(int1>int2){
				return 1;
			}
			else{
				 return -1;
			}
		}
		 
		return 0;
}
	

char* intal_add(const char* intal1, const char* intal2)
{
    char *intal1_temp=copy(intal1);
    char *intal2_temp=copy(intal2);
    int len1=strlen(intal1_temp);
    int len2=strlen(intal2_temp);
    
    int n=len1>len2?len1:len2;
    if(intal_compare(intal2_temp,intal1_temp)==1)
    {
        char *l=intal1_temp;
        intal1_temp=intal2_temp;
        intal2_temp=l;
    }
    int min = (n==len1)?len2:len1;
    char* result = (char*)malloc(sizeof(char)*(n+2));
    revStr(intal1_temp);
    revStr(intal2_temp);
    int carry=0;
    int m=0;
    int sum;
    for (int i=0; i<min; i++)
    {
        sum = (intal1_temp[i]-'0')+(intal2_temp[i]-'0')+carry;
        result[m++]=48+sum%10;
        carry = sum/10;
    }
 
    for (int i=min; i<n; i++)
    {
        sum = (intal1_temp[i]-'0')+carry;
        result[m++]=48+sum%10;
        carry = sum/10;  
    }
 
	if(carry)
	{
  		 result[m++]=48+carry;
	}
	result[m]='\0';
 
	revStr(result);
	free(intal1_temp);
	free(intal2_temp);
	return result;
}

char* intal_diff(const char* intal1, const char* intal2){
	int compare = intal_compare(intal1, intal2);
	
	char* result = (char*)malloc(1000*sizeof(char));
	int intal1_len = strlen(intal1);
	int intal2_len = strlen(intal2);
	
	char* intalbig = (char*)malloc(1000*sizeof(char));
	char* intalsmall = (char*)malloc(1000*sizeof(char));
	int intalbig_len;
	int intalsmall_len;

	int i,j;

	if(compare==0){
		result[0]='0';
		result[1]='\0';
		return result;
	}

	else if(compare==1){
		for(i = intal1_len-1,j=0;i>=0;i--,j++)
    		{
        		intalbig[j] = intal1[i];
    		}
    		intalbig[j] = '\0';

    	for(i = intal2_len-1,j=0;i>=0;i--,j++)
    		{
        		intalsmall[j] = intal2[i];
    		}
    		intalsmall[j] = '\0';

			intalbig_len = strlen(intalbig);
			intalsmall_len = strlen(intalsmall);
		
		}

	else{
		for(i = intal2_len-1,j=0;i>=0;i--,j++)
    	{
    	    intalbig[j] = intal2[i];
    	}
    	
    	intalbig[j] = '\0';

    	for(i = intal1_len-1,j=0;i>=0;i--,j++)
    	{
        	intalsmall[j] = intal1[i];
    	}
		
    	intalsmall[j] = '\0';
		intalbig_len = strlen(intalbig);
		intalsmall_len = strlen(intalsmall);
		
	    }
	   

	int borrow;
	int diff;
	int int1;
	int int2;
	for(i=0;i<intalsmall_len;i++){
		int1 = intalbig[i] - '0';
		int2 = intalsmall[i] - '0';
		if(int1>=int2){
			borrow = 0;
			diff = (int1+borrow) - int2;
			result[i] = diff + '0';

		}
		else{
			int j=i+1;
			while(intalbig[j]==0){
				j++;
			}
			intalbig[j]--;
			borrow=10;
			diff = (int1+borrow) - int2;
			result[i] = diff + '0';
		}
	}
	for(i=intalsmall_len;i<intalbig_len;i++){
		result[i] = intalbig[i];
	}
	
	int k=intalbig_len-1;
	for(; k>= 0;k--)
    {
        if(!(result[k]=='0'))
            break;
       	
    }
    if(k==-1){
    	result[++k] = '0';
    	k++;
    }
    result[k+1]='\0';
    free(intalbig);
    free(intalsmall);
	revStr(result);
return result;

}

char* intal_multiply(const char* intal1,const char* intal2){
	char* result = (char*)malloc(1001*sizeof(char));
	int* holder1 = (int*)malloc(1001*sizeof(int));
	int* holder2 = (int*)malloc(1001*sizeof(int));
    int* result_temp = (int*)malloc(1001*sizeof(int));
    for(int n=0;n<=1001;n++){
    	result_temp[n]=0;
    }
    int i,j,temp;
   
    int l1 = strlen(intal1);
    int l2 = strlen(intal2);
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        holder1[j] = intal1[i]-'0';
    }

    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        holder2[j] = intal2[i]-'0';
    }
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            result_temp[i+j] += holder2[i]*holder1[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        temp = result_temp[i]/10;
        result_temp[i] = result_temp[i]%10;
        result_temp[i+1] = result_temp[i+1] + temp;
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(result_temp[i] > 0)
            break;
    }
    if(i==-1){
    	result[++i] = '0';
    	result[++i] = '\0';

    }
    else{
    int k=0;
    for(;i>= 0;i--)
    {
        result[k] = result_temp[i]+'0';
        k++;
    }
    result[k]='\0';
}
	free(result_temp);
    free(holder1);
    free(holder2);
    return result;
}

char* intal_mod(const char* intal1, const char* intal2){
	int compare = intal_compare(intal1,intal2);
	if(compare == 0){
		char* result = (char*)malloc(2*sizeof(char));
		result[0] = '0';
		result[1] = '\0';
		return result;
	}

	char* diff = (char*)malloc(1001*sizeof(char));
	char* intal2_temp = (char*)malloc(1001*sizeof(char));
	char* temp1;

	strcpy(diff,intal1);
	strcpy(intal2_temp,intal2);
	
	while(intal_compare(diff,intal2_temp)==1){
		while(intal_compare(diff,intal2_temp)==1){
				strcat(intal2_temp,"0");
		}
		intal2_temp[strlen(intal2_temp)-1] = '\0';
		while(intal_compare(diff, intal2_temp)==1){
				temp1 = intal_diff(diff, intal2_temp);
				strcpy(diff,temp1);
				free(temp1);
		}
		
		strcpy(intal2_temp,intal2);
}
	
	free(intal2_temp);
	return diff;
}


char* intal_pow(const char* intal1, unsigned int n){
	char* result = (char*)malloc(1001*sizeof(char));
	char* intal1_temp = (char*)malloc(1001*sizeof(char));
	char* temp;
	strcpy(intal1_temp, intal1);
	result[0] = '1';
	result[1] = '\0'; //int res = 1; Initialize result 
  
    while (n > 0) { 
        // If y is odd, multiply x with result 
        if (n & 1){ 
        	temp = intal_multiply(result,intal1_temp);
            strcpy(result,temp);
            free(temp); //res = res * x; 
  		}
  		if(strlen(intal1_temp)<=500){
        	n = n >> 1;
        	temp = intal_multiply(intal1_temp,intal1_temp);
        	strcpy(intal1_temp,temp);
        	free(temp);
        }
        else{
        	n = n >> 1;  
        }	
       				 // Change x to x^2 
    } 
    free(intal1_temp);
    return result; 
}


char* intal_gcd(const char* intal1, const char* intal2){
	char* intal1_temp = (char*)malloc(1001*sizeof(char));
	char* intal2_temp = (char*)malloc(1001*sizeof(char));
	char* temp1;
	char* temp2 = (char*)malloc(1001*sizeof(char));
	strcpy(intal1_temp,intal1);
	strcpy(intal2_temp,intal2);
  	
    while(intal_compare(intal2_temp,"0")!=0) //while (b != 0)
     {
     	 strcpy(temp2,intal2_temp);			
         temp1 = intal_mod(intal1_temp, intal2_temp);
         strcpy(intal2_temp,temp1);
         strcpy(intal1_temp,temp2);
         free(temp1); 
         
     }
    free(intal2_temp);
    free(temp2);
    return intal1_temp;
}


char* intal_fibonacci(unsigned int n){
	char* result = (char*)malloc(1001*sizeof(char));
	char* fib0 = (char*)malloc(1001*sizeof(char));
	char* fib1 = (char*)malloc(1001*sizeof(char));
	char* temp;
	fib0[0]='0';
	fib0[1]='\0';
	fib1[0]='1';
	fib1[1]='\0';
	if(n==0){
		free(result);
		free(fib1);
		return fib0;
	}
	else if(n==1){
		free(result);
		free(fib0);
		return fib1;
	}
	while(n>1){
  	temp = intal_add(fib0,fib1);//f=f1+f2;
  	strcpy(result, temp); 
  	free(temp);
  	strcpy(fib0,fib1);//f1=f2;
  	strcpy(fib1,result);//f2=f;
  	n--;
  }
  free(fib0);
  free(fib1);
  return result;
}

char* intal_factorial(unsigned int n){
	char* result = (char*)malloc(1001*sizeof(char));
	result[0]='1';
	result[1]='\0';
	char* temp;
	int i;
	char* tempn = (char*)malloc(100*sizeof(char));;
	for(i=2;i<=n;i++){
		sprintf(tempn, "%d", i);
		temp = intal_multiply(result,tempn);
		strcpy(result, temp);
		free(temp);
	}
	free(tempn);
	return result;
}

char* intal_bincoeff(unsigned int n, unsigned int k){
	char* result = (char*)malloc(1001*sizeof(char));
	char* temp;
	char **nCr = (char**) malloc((k+1) * sizeof(char*));
	for(int i = 0; i < k+1; i++) {
		nCr[i] = (char*) malloc(1001 * sizeof(char));
	}
  	
    for (int l = 0; l < k + 1; l++)
        strcpy(nCr[l],"0");
    strcpy(nCr[0],"1");
    for (int p = 1; p <= n; p++)
    {
        for (int q=(p<k)?p:k; q > 0; q--){
            temp = intal_add(nCr[q], nCr[q - 1]);
        	strcpy(nCr[q],temp);
        	free(temp);
        }
            //nCr[q] = nCr[q] + nCr[q - 1];
    }
    
    strcpy(result,nCr[k]);
    for(int i = 0; i < k+1; i++) {
        free(nCr[i]);
    }
    free(nCr);
    return result;

}


int intal_max(char **arr, int n){
    char *result=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(intal_compare(arr[i],result)==1){
            index=i;
            result=arr[i];
        }
    }
    return index;
}
int intal_min(char **arr, int n){
    char *result=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(intal_compare(arr[i],result)==-1){
            index=i;
            result=arr[i];
        }
    }
    return index;
}

int intal_search(char **arr, int n, char* key){
    int answer=-1;
    for(int i=0;i<n;i++){
        if(is_same(arr[i],key)==1){
            answer=i;
            return answer;
        }
    }

    return answer;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    int left = 0;
    int right = n-1;
    char *key_copy = copy(key);
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(intal_compare(arr[mid],key_copy)==0)
        {
            free(key_copy);
            return mid;
        }
        else if(intal_compare(arr[mid],key_copy)<0)
            left = mid+1;
        else
            right = mid-1;      
    }
    return -1;
}

static void merge(char** arr, int l, int m, int r)
{
    int i;
    int j;
    int k;
    int a1 = m - l + 1;
    int a2 =  r - m;
 
    char** left=createArray(a1);
    char** right=createArray(a2);
    for (i = 0; i < a1; i++){
        left[i] = copy(arr[l + i]);}
    for (j = 0; j < a2; j++){
        right[j] = copy(arr[m + 1+ j]);}
 
    i = 0;  
    j = 0;
    k = l;  
    while (i < a1 && j < a2)
    {
        if (intal_compare(left[i],right[j])<=0)
        {
            arr[k] = copy(left[i]);
            i++;
        }
        else
        {
            arr[k] = copy(right[j]);
            j++;
        }
        k++;
    }
 
    while (i < a1)
    {
        arr[k] = copy(left[i]);
        i++;
        k++;
    }
 
    while (j < a2)
    {
        arr[k] = copy(right[j]);
        j++;
        k++;
    }
}


static void mergeSort(char** arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }

}

void intal_sort(char **a, int n){
    mergeSort(a,0,n-1);
}


char* coin_row_problem(char **arr, int n)
{
    char *previous=malloc(sizeof(char)*1001);
    strcpy(previous,"0");
    char *current=malloc(sizeof(char)*1001);
    strcpy(current,arr[0]);
    char *next=malloc(sizeof(char)*1001);
    char *sum=malloc(sizeof(char)*1001);
    strcpy(sum,"0");
    char *res=malloc(sizeof(char)*1001);
    if(n==0)
    {
        free(res);
        free(next);
        free(sum);
        free(current);
        return previous;
    }
    for(int i=2;i<=n;i++)
    {
        char *t1 = intal_add(previous,arr[i-1]);
        char *t2=sum;
        sum=t1;
        free(t2);
        int flag = intal_compare(sum,current);
        if((flag == 0) || (flag==1))
        {
            strcpy(next,sum);
        }   
        else
        {
            strcpy(next,current);
        }
        strcpy(previous,current);  
        strcpy(current,next);
    }
    free(sum);
    free(previous);
    free(next);
    strcpy(res,current);
    free(current);
    
    return res;
}