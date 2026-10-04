class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int f= 0, next;
        int s= 1;
        for(int i=1; i<n;i++){
         next= f+s;
        f=s;
        s=next;
        }
        return s;
    }
};