#include <stdio.h>
#include <stdlib.h>

int main(){
    int score, td, tdc, tdfg, fg, s;
    printf("Enter 0 or 1 to stop.\n");
    while (1){
        printf("\nPlease enter the NFL Score:  ");
        scanf("%d", &score);
        if (score <=1){
            break;
        }
        printf("Here are the possible combinations of scoring plays:\n");

        for (tdc = 0; tdc<=score/8;tdc++){
            for (tdfg = 0;tdfg<=score/7;tdfg++){
                for (td = 0; td<=score/6;td++){
                    for (fg = 0; fg<= score/3;fg++){
                        for (s = 0; s<=score/2;s++){
                            if((tdc*8 + tdfg*7 + td*6 + fg*3 + s*2) == score){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tdc, tdfg, td, fg, s);
                            }
                        }
                    }
                }
            }
        }
    }
    
}