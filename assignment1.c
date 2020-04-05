#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{false, true} bool;

typedef struct 
{
    char s[3000];
    int size;
    bool neg;

}bigint;


bigint add(bigint a1, bigint a2);
bigint subtract(bigint a1,bigint a2);

bigint add(bigint a1, bigint a2)
{
    int l1 = a1.size;
    int l2 = a2.size;

    int i = l1-1, j = l2-1;
    
    bigint sum;
    int l = sum.size =  ( l1>l2 ? l1 : l2 ) + 1 ;
    int a = 0;
    if(a1.neg==true ^ a2.neg==true)
    {
       if(a1.neg==true)
       {
           int t=0;
          while(t<l1)
        {
             a1.s[t]=a1.s[t+1];
             t++;
        }
        a1.size=l1-1;
        a1.s[l1-1]='\0';
        a1.neg=false;
        sum = subtract(a2 , a1);
       }
       else
       {
           int t=0;
          while(t<l2)
        {
             a2.s[t]=a2.s[t+1];
             t++;
        }
        a2.size=l2-1;
        a2.s[t]='\0';
        a2.neg=false;
        sum = subtract(a1,a2);
       }
    }
   else
   {
    if( a1.neg==true && a2.neg==true )
    {
        a = 1;
        sum.neg = true;

    }

   
    int k = l-1;
    sum.s[l] = '\0';
if(a==1)
{
    if(l1!=l2)
    {
        sum.s[k--] = '\0';

    }
    else
    {
        if(((int)(a1.s[1]+a2.s[1]-'0'-'0'))<10)
        {
            sum.s[k--] = '\0';
        }
    }
}
    int carry = 0;
    int x, y;

    while( i>=a && j>=a )
    {
        x = (int)(a1.s[i]-'0');
        y = (int)(a2.s[j]-'0');

        sum.s[k] = (x+y+carry)%10 + '0';
        carry = (x+y+carry)/10;


        i--;
        j--;
        k--;

    }
    
    while( i>=a )
    {
        x = (int)(a1.s[i]-'0');
        sum.s[k] = (x+carry)%10 + '0';
        carry = (x+carry)/10;
        i--;
        k--;

    }

    while( j>=a )
    {
        y = (int)(a2.s[j]-'0');
        sum.s[k] = (y+carry)%10 + '0';
        carry = (y+carry)/10;
        j--;
        k--;

    }

    if( carry==1 )
    {
        sum.s[k--] = carry + '0';
    }  

    if( carry==0 && a==0 )
    {
        for( i = a; i < l -1; i++ )
        {
            sum.s[i] = sum.s[i+1];
        }

        sum.s[l-1] = '\0';

        sum.size = l-1;
    
    } 

    if(a==1)
    {
        sum.s[0] =  '-'; 
    }
   }
   
    return sum;

}



bigint subtract(bigint a1,bigint a2)
{
    bigint res;
    res.neg=false;
    int l1=a1.size;
    int l2=a2.size;
    int i=l1-1,j=l2-1;
    int l=res.size=(l1>l2 ? l1 : l2)+1;
    int k=l-1;
    res.s[l]='\0';
    int a=0,b=-1,d=0;
   
   if (a1.neg==false && a2.neg==true)
   {
       int m=0;
       while(m<l2)
       {
           a2.s[m]=a2.s[m+1];
           m++;
       }
       a2.s[l2-1]='\0';
       a2.size=l2-1;
       a2.neg = false;
       res = add(a1,a2);
       
   }
   else if(a1.neg==true && a2.neg==false)
   {
       int m=l2+1;
       while(m>=1)
       {
           a2.s[m]=a2.s[m-1];
           m--;
       }
       a2.s[m]='-';
       a2.neg=true;
       a2.size=l2+1;
       a2.s[l2+1]='\0';
       res = add(a1,a2);
       
    }
   
   else
   {
    if(l1>l2)
    {
        b=0;
    }
    else if(l1==l2)
    {
        int c;
        c=strcmp(a1.s,a2.s);
        if(c>0)
        b=0;
        else if(c==0)
        {
            res.s[0]='0';
            res.s[1]='\0';
            res.size=1;
            res.neg=false;
            b=-1;
            
		}
        else 
        b=1;
    }
    else
    {
        b=1;
    }
    
    
    if(a1.neg==true && a2.neg==true)
    {
        a=1;
    }
    
    if(b==0)
    {
        int x,y;
        while(i>=a && j>=a)
        {
            x=(int)(a1.s[i]-'0');
            y=(int)(a2.s[j]-'0');
            d=x-y;
            if(d<0)
            {
                int n=i-1,m;
                while(a1.s[n]=='0' && n>=a)
                {
                    a1.s[n]='9';
                    n--;
                }
                m=(int)(a1.s[n]-'0');
                m=m-1;
                a1.s[n]=m+'0';
                d=d+10;
            }
            res.s[k]=d+'0';
            i--;
            j--;
            k--;
        }
        while(i>=a)
        {
            x=(int)(a1.s[i]-'0');
            res.s[k--]=a1.s[i--];
        }
        int g=a;
        while(g>=0)
        {
        res.s[g--]='0';
        }
        if(a==1)
        {
            res.s[0]='-';
            res.neg=true;
            int p=1,q=1;
            while(res.s[p]=='0')
            {
                p++;
            }
            while(res.s[p]!='\0')
            {
                res.s[q++]=res.s[p++];
            }
            if(q==1)
            {
                res.s[q++]='0';
            }
            res.s[q]='\0';
            if(res.s[1]=='0')
            {
			res.s[0]='0';
            res.s[1]='\0';
		    }
			res.size=strlen(res.s);
        }
        else
        {
            int p=0,q=0;
            while(res.s[p]=='0')
            {
                p++;
            }
            while(res.s[p]!='\0')
            {
                res.s[q++]=res.s[p++];
            }
            if(q==0)
            {
                res.s[q++]='0';
            }
            res.s[q]='\0';
            res.size=strlen(res.s);
        }
    }
    else if(b==1)
    {
        int x,y;
        while(i>=a && j>=a)
        {
            x=(int)(a2.s[j]-'0');
            y=(int)(a1.s[i]-'0');
            d=x-y;
            if(d<0)
            {
                int n=j-1,m;
                while(a2.s[n]=='0' && n>=a)
                {
                    a2.s[n]='9';
                    n--;
                }
                m=(int)(a2.s[n]-'0');
                m=m-1;
                a2.s[n]=m+'0';
                d=d+10;
            }
            res.s[k]=d+'0';
            i--;
            j--;
            k--;
        }
        while(j>=a)
        {
            x=(int)(a2.s[j]-'0');
            res.s[k--]=a2.s[j--];
        }
        int g=a;
        while(g>=0)
        {
        res.s[g--]='0';
        }
        if(a==0)
        {
            res.s[0]='-';
            res.neg=true;
            int p=1,q=1;
            while(res.s[p]=='0')
            {
                p++;
            }
            while(res.s[p]!='\0')
            {
                res.s[q++]=res.s[p++];
            }
            if(q==1)
            {
                res.s[q++]='0';
            }
            res.s[q]='\0';
            res.size=strlen(res.s);
        }
        else
        {
            int p=0,q=0;
            while(res.s[p]=='0')
            {
                p++;
            }
            while(res.s[p]!='\0')
            {
                res.s[q++]=res.s[p++];
            }
            if(q==0)
            {
                res.s[q++]='0';
            }
            res.s[q]='\0';
            res.size=strlen(res.s);
        }
    }
   }    
    return res;
    
}

 /* bigint mul(bigint a1, bigint a2)
{
    bigint zero;
    zero.s[0] = '0' ;
    zero.size= 1;
    zero.neg=false;

    bigint one;
    one.s[0] = '1';
    one.size= 1;
    one.neg=false;

    int l1 = a1.size;
    int l2 = a2.size;

    bigint i = zero;
    bigint prod = zero;
    
    bool s1 = a1.neg, s2 = a2.neg;
    
    if(a1.neg==true)
    {
        int t=0;
        while(t<l1)
        {
             a1.s[t]=a1.s[t+1];
             t++;
        }
        a1.size=l1-1;
        a1.s[l1-1]='\0';
        a1.neg=false;
    }
    if(a2.neg==true)
    {
        int t=0;
        while(t<l2)
        {
             a2.s[t]=a2.s[t+1];
             t++;
        }
        a2.size=l2-1;
        a2.s[l2-1]='\0';
        a2.neg=false;
    }
    
    while ( strcmp(i.s,a1.s)!=0 )
    {
        prod = add(prod,a2) ;
        i = add(i,one);

    }
    
    if((s1==true && s2==false) || (s1==false && s2==true))
    {
        int n=(prod.size)+1;
        while(n>=1)
       {
           prod.s[n]=prod.s[n-1];
           n--;
       }
       prod.s[0]='-';
       prod.neg=true;
       
        
    }

    return prod;
} */

bigint mul(bigint a1,bigint a2)
{
    bigint zero;
    zero.s[0] = '0' ;
    zero.size= 1;
    zero.neg=false;

    bigint one;
    one.s[0] = '1';
    one.size= 1;
    one.neg=false;

    int l1 = a1.size;
    int l2 = a2.size;

    int x,y,i,j;
    bigint m,n,prod;

    bool s1 = a1.neg, s2 = a2.neg; 
    
    if(a1.neg==true)  
    {
        int t=0;
        while(t<l1)
        {
             a1.s[t]=a1.s[t+1];
             t++;
        }
        a1.size=l1-1;
        a1.s[l1-1]='\0';
        a1.neg = false;

        

    }

    if(a2.neg==true)  
    {
        int t=0;
        while(t<l2)
        {
             a2.s[t]=a2.s[t+1];
             t++;
        }
        a2.size=l2-1;
        a2.s[l2-1]='\0';
        a2.neg = false;
    }

    if(l2==1 )
    {
        x = (int)(a2.s[0]-'0');

        prod = zero;

        for(i = 0; i < x ; i++ )
        {
            prod = add(prod,a1);
        }
        
    }

    else
    {
        i = l2-1;
        prod = zero;

        while( i>=0 )
        {
            m.s[0] = a2.s[i];
            m.s[1] = '\0';
            m.size = 1;
            m.neg = false;

            n = mul(a1,m);

            int shift = (l2-1)-i;
            j = 0;

            while(j<shift)
            {
                n.s[n.size+j] = '0';
                j++;
            }

            n.size = n.size+shift;
            n.s[n.size+shift] = '\0';

            prod = add(prod,n);

            i--;
        }
    }

    if( (s1==true && s2==false) || (s1==false && s2==true) )   // when multiplication is negative
    {
        int n=(prod.size);
        while(n>=1)
        {
            prod.s[n]=prod.s[n-1];
            n--;
        }
        prod.s[0]='-';
        prod.neg=true;
        
        
    }

    if(s2==true)
    {
        if(s1==false)
        {
            prod.s[prod.size] = '\0';
        }
        else
        {
            prod.s[prod.size-1] = '\0';
        }
    }

    return prod;
}



bigint read()
{
    bigint x;

    scanf("%s",x.s);

    x.size = strlen(x.s);

    x.neg = x.s[0]=='-' ? true : false ;

    return x;
}

void main()
{
    bigint x;
    bigint y;
    int c;
  printf("Enter the first no. \n");
    x = read();
 printf("Enter the second no. \n");
    y = read();
 printf("Press 1 for addition,2 for subtraction and 3 for multiplication");
   scanf("%d",&c);
  
 if(c==1)
 {
   printf("addition is %s\n",add(x,y).s);
 }
else if(c==3)
 {
   printf("multiplication is %s \n",mul(x,y).s);
 }
else if(c==2)
 {   
    printf("subtraction is %s",subtract(x,y).s);
 }
else
 {
 printf("Enter a valid choice");
 }
}
