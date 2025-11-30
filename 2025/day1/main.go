package main

import (
    "flag"
    "fmt"
)

func main() {
    day := flag.Int("day", 1, "day to run")
    flag.Parse()

    switch *day {
    case 1:
        part1()
    case 2:
        part2()
    default:
        fmt.Println("Day not implemented")
    }
}