func numberOfPairs(nums1 []int, nums2 []int, k int) int {
    
    cnt:= 0
    for _,num1 := range nums1{

        for _,num2 := range nums2{

            if (num1)%(num2*k) == 0{
                cnt ++
            }
        }
    }
    return cnt
}