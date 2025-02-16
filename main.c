#include "ac3tp.h"
#include "MKL25Z4.h"
int main(){
    init();
    
}
while(1){
    /* */
    
    if(sensTemp() == 'V'){
        PTE->PTOR|=(1u<<20);
       for(i=700000;i=0;i--);
       PTE-> PTOR|=(1u<<20); 
    }else if(sensTemp()== 'A'){
        PTE->PTOR|=(1u<<21);
        for(i=700000;i=0;i--);
        PTE-> PTOR|=(1u<<21); 
    } else if(sensTemp()=='N'){
        PTE->PTOR|=(1u<<22);
        for(i=700000;i=0;i--);
        PTE-> PTOR|=(1u<<22); 
    } else if(sensTemp()=='R'){
        PTE->PTOR|=(1u<<23);
        for(i=700000;i=0;i--);
        PTE-> PTOR|=(1u<<23); 
    }else {
        return 0;
    }
    if(sensHum()== 'V'){
        PTE->PTOR|=(1u<<20);
       for(i=700000;i=0;i--);
       PTE-> PTOR|=(1u<<20); 
    }else if(sensTemp()== 'A'){
        PTE->PTOR|=(1u<<21);
        for(i=700000;i=0;i--);
        PTE-> PTOR|=(1u<<21); 
    } else if(sensTemp()=='N'){
        PTE->PTOR|=(1u<<22);
        for(i=700000;i=0;i--);
        PTE-> PTOR|=(1u<<22); 
    } else if(sensTemp()=='R'){
        PTE->PTOR|=(1u<<23);
        for(i=700000;i=0;i--);
        PTE-> PTOR|=(1u<<23); 
    }else {
        return 0;
    }
    

}

