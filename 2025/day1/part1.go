package main

import (
	"fmt"
	"os"
	"strings"
    "strconv"
)

func part1() {
    filePath := "input"

    content, _ := os.ReadFile(filePath)

    contentStr := string(content)
    ans := 0
    currDeg := 50

    for _, str := range strings.Split(contentStr, "\n") {
        dir, numStr := str[0:1], str[1:]
        num, _ := strconv.Atoi(numStr)
        switch dir {
        case "L":
            currDeg = (currDeg - num) % 100
        case "R":
            currDeg = (currDeg + num) % 100
        }

        if currDeg == 0 {
            ans++
        }
    }

    fmt.Println(ans)
}
