 long long int maxSumWithK(long long int nums[], long long int n, long long int k) 
    {
        long long ans=0;
        long long last=0;
          long long i=0,j=0;
        long long sum=0;
        long long maxi=INT_MIN;
        while(i<n){
            sum+=nums[i];
            if(i-j+1==k) //if equal h toh max sum bss
                maxi=max(maxi,sum);
             if(i-j+1>k){ // if k se bda hogya  then starting index se minus hoga jb
             //           vo neg hogyaa tbhi it will make our sum min
                       //tc=[-4,-2,1,-3]  k=2  o/p=-1
                       // i-j+1=2 pe -4+-2=-6 but when i-j+1>2 then check li last+=nums[j]->
                       //last=-4 ab ye sum me add hoga ussko chhota krr dega issliye
                       //if -ve h then sum me se minus sum=-5-(-4)=-1;
                    last+=nums[j];
                    j++;
                    
                    if(last<0){
                        sum-=last;
                        last=0;
                    }
                    maxi=max(maxi,sum);
                }
                
            i++;
        }
        
      return maxi;
    }