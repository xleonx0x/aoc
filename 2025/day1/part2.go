package main

import (
	"fmt"
	"os"
	"strings"
    "strconv"
)

func part2() {
    filePath := "input"

    content, _ := os.ReadFile(filePath)

    contentStr := string(content)
    ans := 0
    currDeg := 50

    for str := range strings.SplitSeq(contentStr, "\n") {
        dir, numStr := str[0:1], str[1:]
        num, _ := strconv.Atoi(numStr)
        wholeHundreds := num / 100
        remainder := num - 100 * wholeHundreds
        switch dir {
        case "L":
            if currDeg - remainder <= 0 && currDeg != 0 {
                ans += 1
            }
            currDeg = ((currDeg - num) % 100 + 100) % 100
        case "R":
            if currDeg + remainder >= 100 {
                ans += 1
            }
            currDeg = ((currDeg + num) % 100 + 100) % 100
        }

        ans += wholeHundreds
    }

    fmt.Println(ans)
}
