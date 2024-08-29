## Chapter 2
Algorithm Analysis

- example:
Fibonacchi
can be optimized by creating a **table
put the known numbers into it for next searching**

### Compare the algorithms

- **MaxSubsequenceSum**
Given (possible negative) integers $A_1,A_2,…,A_N$,
find the maximun value of $\sum_{k=i}^{j} A_k$
    1. 无脑遍历
        
        ```c
        for (int i=0;i<n;i++){
        		for(int j=i;j<n;j++){
        				for (int k=i;k<=j;k++)
        							sum(); //phony
        							compare(sum,max);
        		}
        }
        ```
        
        $O(N^3)$
        
    2. 利用上次计算结果
        
        ```c
        for (int i=0;i<n;i++){
        			ThisSum=0;
        			for (int j=i;j<n;j++){
        					ThisSum+=A[j];
        					compare(Thissum,max);
        		}
        }
        ```
        
        $O(N^3)$
        
    3. Divide and Conquer
        
        ```c
        int border(int l,int r,int a[]){
            int lsum=0,lmax=0,rsum=0,rmax=0;
            int mid=(l+r+1)/2;
            for (int i=mid-1;i>=l;i--){
                lsum+=a[i];
                if(lsum>lmax) lmax=lsum;
            }
            for (int i=mid;i<=r;i++){
                rsum+=a[i];
                if(rsum>rmax) rmax=rsum;
            }
            int bd=lmax+rmax;
            return bd;
        
        }
        
        int DC(int l,int r,int a[]){
            int maxl,maxr;
            if(l==r){
                if(a[l]>0) return a[l];
                else return 0;
            }
            int mid=(l+r+1)/2;
            maxl=DC(l,mid-1,a);
            maxr=DC(mid,r,a);
            int across=border(l,r,a);
            return max(maxl,maxr,across);
        }
        ```
        
        $O(NlogN)$
        
    4. On-line Algorithm
    
        
        ```c
        int online(int a[],int n){
            int Max=0,ThisSum=0;
            for (int i=0;i<n;i++){
                ThisSum+=a[i];
                if(ThisSum>Max) Max=ThisSum; 
                if(ThisSum<0) ThisSum=0;
            }
            return Max;
        }
        ```
        
- **Euclid’s Algorithm
search for gcd**
    
    ```c
    int gcd(int m,int n){
        if (n>m){
            int temp=n;
            n=m;
            m=temp;
        }
        int rem;
        while(n>0){
            rem=m%n;
            m=n;
            n=rem;
        }
        //结束时即整除 此时有（m,0)
        return m;
    }
    ```
    
    $O(logN)$
    
- **Exponentiation**
    
    ```c
    int pow (int x,int n){
    		if(n==0) return 1;
    		if(n==1) return x;
    		if(even(n)){
    			return pow(x*x,n/2);
    		}
    		else return (pow(x*x,n/2)*x);
    }
    ```
    
    $O(logN)$
    
