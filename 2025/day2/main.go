package main

import (
	"fmt"
	"os"
	"strings"
	"strconv"
)

func main() {
	part2()
}

func part1() {
	filePath := "input"
    content, _ := os.ReadFile(filePath)
    contentStr := string(content)
	contentStr = strings.ReplaceAll(contentStr, "\n", "")

	ans := 0

	for str := range strings.SplitSeq(contentStr, ",") {
		left, right, _ := strings.Cut(str, "-")
		half1, _ := strconv.Atoi(left)
		half2, _ := strconv.Atoi(right)
		
		i := half1

		for i <= half2 {
			length := len(strconv.Itoa(i))
			i_str := strconv.Itoa(i)
			if length % 2 == 0 {
				half1_, _ := strconv.Atoi(i_str[0:length/2])
				half2_, _ := strconv.Atoi(i_str[length/2:])
				if half1_ == half2_ {
					fmt.Println(i)
					ans += i
				}
			}
			i += 1
		}
	}
	
	fmt.Println(ans)
}

func part2() {
	filePath := "input"
    content, _ := os.ReadFile(filePath)
    contentStr := string(content)
	contentStr = strings.ReplaceAll(contentStr, "\n", "")

	ans := 0

	for str := range strings.SplitSeq(contentStr, ",") {
		left, right, _ := strings.Cut(str, "-")
		half1, _ := strconv.Atoi(left)
		half2, _ := strconv.Atoi(right)
		
		i := half1

		for i <= half2 {
			i_str := strconv.Itoa(i)
			length := len(i_str)
			j := 1
			for j < length {
				if length % j != 0 {
					j += 1
					continue
				}
				
				k := j
				
				flag := true
				starting := i_str[0:j]
				for k < length {
					if i_str[k:k+j] != starting {
						flag = false
						break
					}
					k += j
				}

				if flag {
					ans += i
					break
				}
				
				j += 1
			}
			
			i += 1
		}
	}
	
	fmt.Println(ans)
}
