#!/usr/bin/py
from datetime import datetime
 
def convertToEuTime(us_time):
    return datetime.strptime(us_time, '%I:%M:%S%p').strftime('%H:%M:%S')
 
if __name__ == '__main__':
    us_time = raw_input()
    print convertToEuTime(us_time)
    use std::io;
 
fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).ok().expect("Failed to read line");
     
    let a: String = line.chars().skip(0).take(2).collect();
    let b: String  = line.chars().skip(3).take(2).collect();
    let c: String  = line.chars().skip(6).take(2).collect();
    let d: String  = line.chars().skip(8).take(2).collect();
     
    let a = a.trim().parse::<u32>().unwrap();
    let b = b.trim().parse::<u32>().unwrap();
    let c = c.trim().parse::<u32>().unwrap();
     
    let a = (a % 12) + match d.as_ref()  {
        "AM"    => 0,
        "PM"    => 12,
        _       => panic!("Unknown date type"),
    };
     
    println!("{:02}:{:02}:{:02}", a, b, c);
}
