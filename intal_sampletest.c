#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void reverseStr(char *a)
{
    int n = strlen(a);
    for (int i = 0; i < n / 2; i++)
{
   char b=a[i];
a[i]=a[n-i-1];
a[n-i-1]=b;
}
}

static char** create_array(int a)
{
    char **p=malloc(sizeof(char *)*a);
    return p;
}

static int same(const char *a,const char *b)
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
	int i,j;

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
char *intal11=copy(intal1);
char *intal22=copy(intal2);
int a=strlen(intal11);
int b=strlen(intal22);
char *res;
int n=a>b?a:b;
if(intal_compare(intal22,intal11)==1)
{
char *l=intal11;
intal11=intal22;
intal22=l;
}
int min=(n==a)?b:a;
res=(char *)malloc(sizeof(char)*(n+2));
reverseStr(intal11);
reverseStr(intal22);
int carry=0;
int m=0;
for (int i=0; i<min; i++)
{
   int sum = (intal11[i]-'0')+(intal22[i]-'0')+carry;
   res[m++]=48+sum%10;
   carry = sum/10;
}
 
for (int i=min; i<n; i++)
{
   int sum = (intal11[i]-'0')+carry;
   res[m++]=48+sum%10;
   carry = sum/10;  
}
 
	if (carry)
	{
  		 res[m++]=48+carry;
	}
	res[m]='\0';
 
	reverseStr(res);
	free(intal11);
	free(intal22);
	return res;
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
	for(int i=0;i<intalsmall_len;i++){
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
	reverseStr(result);
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
	char* temp2 = (char*)malloc(1000*sizeof(char));
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
    free(nCr);
    return result;

}


int intal_max(char **arr, int n){
    char *res=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(intal_compare(arr[i],res)==1){
            index=i;
            res=arr[i];
        }
    }
    return index;
}
int intal_min(char **arr, int n){
    char *res=arr[0];
    int index=0;
    for(int i=1;i<n;i++){
        if(intal_compare(arr[i],res)==-1){
            index=i;
            res=arr[i];
        }
    }
    return index;
}

int intal_search(char **arr, int n, char* key){
    int ans=-1;
    for(int i=0;i<n;i++){
        if(same(arr[i],key)==1){
            ans=i;
            return ans;
        }
    }

    return ans;
}

static int intal_binsearch1(char **arr, int l, int r, char *key)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
       
        if (intal_compare(arr[mid],key)==0){
            return mid; }
 
        if (intal_compare(arr[mid],key)==1){
            return intal_binsearch1(arr, l, mid - 1, key);}
 
        return intal_binsearch1(arr, mid + 1, r, key);
    }
 
    return -1;
}
int intal_binsearch(char **arr, int n, char* key){
    return intal_binsearch1(arr,0,n-1,key);
}

static void merge(char** arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    char** L=create_array(n1);
    char** R=create_array(n2);
    for (i = 0; i < n1; i++){
        L[i] = copy(arr[l + i]);}
    for (j = 0; j < n2; j++){
        R[j] = copy(arr[m + 1+ j]);}
 
    i = 0;  
    j = 0;
    k = l;  
    while (i < n1 && j < n2)
    {
        if (intal_compare(L[i],R[j])<=0)
        {
            arr[k] = copy(L[i]);
            i++;
        }
        else
        {
            arr[k] = copy(R[j]);
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = copy(L[i]);
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = copy(R[j]);
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

static char* max(const char *a,const char *b){
char *l=copy(a);
char *m=copy(b);
    if(intal_compare(l,m)==1){
        return l;
    }
    else{
        return m;
    }
}

static char* coin_row(char** arr,int index,int n)
{
    if (index==n)
        return "0";
    if (index==n-1)
        return arr[index];
    if (index==n-2)
        return max(arr[index],arr[index+1]);
    return max(intal_add(arr[index],coin_row(arr,index+2,n)),coin_row(arr,index+1,n));
}

char* coin_row_problem(char **arr, int n)
{
    return coin_row(arr,0,n);
}


int main(int argc, char const *argv[]) {
	int n = 12;
	char **a = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(a[0], "1234512345123451234512345");
	strcpy(a[1], "543215432154321543215432154321");
	strcpy(a[2], "0");
	strcpy(a[3], "1234512345123451234512345");
	strcpy(a[4], "1234512345123451234512344");
	strcpy(a[5], "12");
	strcpy(a[6], "265252859812191058636308480000000");
	strcpy(a[7], "265252859812191058636308480000000");
	strcpy(a[8], "5432154321543215432154321");
	strcpy(a[9], "3");
	strcpy(a[10], "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	strcpy(a[11], "1230231922161117176931558813276752514640713895736833715766118029160058800614672948775360067838593459582429649254051804908512884180898236823585082482065348331234959350355845017413023320111360666922624728239756880416434478315693675013413090757208690376793296658810662941824493488451726505303712916005346747908623702673480919353936813105736620402352744776903840477883651100322409301983488363802930540482487909763484098253940728685132044408863734754271212592471778643949486688511721051561970432780747454823776808464180697103083861812184348565522740195796682622205511845512080552010310050255801589349645928001133745474220715013683413907542779063759833876101354235184245096670042160720629411581502371248008430447184842098610320580417992206662247328722122088513643683907670360209162653670641130936997002170500675501374723998766005827579300723253474890612250135171889174899079911291512399773872178519018229989376");
	char *result1;
	int index1;

	result1 = intal_add(a[0], a[1]);
	if(!result1) {
		printf("Test intal_add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543216666666666666666666666666")) {
			printf("Test intal_add PASSED\n");
		} else {
			printf("Test intal_add FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543216666666666666666666666666");
		}
		free(result1);
	}

	index1 = intal_compare(a[3], "1000000000000000000000000");
	if(1 == index1) {
		printf("Test intal_compare PASSED\n");
	} else {
		printf("Test intal_compare FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, -1);
	}

	result1 = intal_diff(a[0], a[1]);
	if(!result1) {
		printf("Test intal_diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543214197641976419764197641976")) {
			printf("Test intal_diff PASSED\n");
		} else {
			printf("Test intal_diff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "543214197641976419764197641976");
		}
		free(result1);
	}

	result1 = intal_multiply(a[8], a[5]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "65185851858518585185851852")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Test intal_multiply FAILED.\n.Your answer: %s\nExpected answer: %s\n", result1, "65185851858518585185851852");
		}
		free(result1);
	}

	result1 = intal_mod(a[3],"2");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1");
		}
		free(result1);
	}


	result1 = intal_mod("978", "5");
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}

	result1 = intal_mod(a[0], a[5]);
	if(!result1) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result1, "9")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "9");
		}
		free(result1);
	}

	result1 = intal_pow(a[5], 3);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1728")) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1728");
		}
		free(result1);
	}

	result1 = intal_pow("10", 999);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[10])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[10]);
		}
		free(result1);
	}

	result1 = intal_pow("2", 3000);
	if(!result1) {
		printf("Test intal_pow FAILED.\n");
	} else {
		if(0 == strcmp(result1, a[11])) {
			printf("Test intal_pow PASSED\n");
		} else {
			printf("Test intal_pow FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[11]);
		}
		free(result1);
	}

	result1 = intal_gcd(a[0], a[5]);
	if(!result1) {
		printf("Test intal_gcd FAILED.\n");
	} else {
		if(0 == strcmp(result1, "3")) {
			printf("Test intal_gcd PASSED\n");
		} else {
			printf("Test intal_gcd FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "3");
		}
		free(result1);
	}

	result1 = intal_fibonacci(3);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "2")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "2");
		}
		free(result1);
	}

	result1 = intal_fibonacci(1000);
	if(!result1) {
		printf("Test intal_fibonacci FAILED.\n");
	} else {
		if(0 == strcmp(result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875")) {
			printf("Test intal_fibonacci PASSED\n");
		} else {
			printf("Test intal_fibonacci FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "43466557686937456435688527675040625802564660517371780402481729089536555417949051890403879840079255169295922593080322634775209689623239873322471161642996440906533187938298969649928516003704476137795166849228875");
		}
		free(result1);
	}

	result1 = intal_factorial(0);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, a[6]);
		}
		free(result1);
	}

	result1 = intal_factorial(100);
	if(!result1) {
		printf("Test intal_factorial FAILED.\n");
	} else {
		if(0 == strcmp(result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000")) {
			printf("Test intal_factorial PASSED\n");
		} else {
			printf("Test intal_factorial FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
		}
		free(result1);
	}

	result1 = intal_bincoeff(10, 8);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "45")) {
			printf("Test intal_bincoeff PASSED\n");
		} else {
			printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "45");
		}
		free(result1);
	}

	result1 = intal_bincoeff(1000, 900);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890")) {
			printf("Test intal_bincoeff PASSED\n");
		} else {
			printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "63850511926305130236698511142022274281262900693853331776286816221524376994750901948920974351797699894319420811933446197797592213357065053890");
		}
		free(result1);
	}

	index1 = intal_max(a, n);
	if(10 == index1) {
		printf("Test intal_max PASSED\n");
	} else {
		printf("Test intal_max FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}

	index1 = intal_min(a, n);
	if(2 == index1) {
		printf("Test intal_min PASSED\n");
	} else {
		printf("Test intal_min FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 2);
	}

	index1 = intal_search(a, n, a[7]);
	if(6 == index1) {
		printf("Test intal_search PASSED\n");
	} else {
		printf("Test intal_search FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 6);
	}

	result1 = coin_row_problem(a, n);
	if(!result1) {
		printf("Test coin_row_problem FAILED.\n");
	} else {
		if(0 == strcmp("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987", result1)) {
			printf("Test coin_row_problem PASSED\n");
		} else {
			printf("Test coin_row_problem FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000265796081911012046846190578820987");
		}
		free(result1);
	}

	intal_sort(a, n);
	printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", a[i]);
	}
	printf("\n");

	index1 = intal_binsearch(a, n, "3");
	if(1 == index1) {
		printf("Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 1);
	}

	// Don't forget to free all the memory that is dynamically allocated.
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}

	free(a);
	return 0;
}
