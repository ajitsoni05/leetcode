import ("math")
func calculateTime(keyboard string, word string) int {
    mp := make(map[rune]int)

    for idx,ch:= range keyboard {
        mp[ch] = idx
    }

    ans := 0

    prev := mp[rune(word[0])]
    for idx,ch := range word{
        if idx !=0{
        ans+= int(math.Abs(float64(mp[ch])-float64(prev)))
        prev = mp[ch]
        }else{
            ans+= prev
        }
    }
    return ans
}