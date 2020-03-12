#include <stdio.h>
int main(){
    int i;
    int sum;
    int nums1[] = {1,2,3,4,5};
    int nums2[] = {5,4,3,2,1};
    for (i = 0; i < 5; i++){


        printf("index nums1[%d] include %d, index nums2[%d] contains %d\n" ,i, nums1[i], i, nums2[i] );
    }
    for (i = 0; i < 5; i++){

    sum = nums1[i]+nums2[i];
    }
    printf("The addition result of nums1[%d] and nums2[%d] is %d\n", i, i, sum);

    return 0;

}