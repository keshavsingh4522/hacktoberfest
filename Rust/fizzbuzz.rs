fn _check(num: isize, n: isize) -> bool {
    if num % n == 0 {
        true
    } else {
        false
    }
}

fn main() {
    let mut start = 1;
    let max = 100;

    while start <= max {
        match (_check(start, 3), _check(start, 5)) {
            (true, true) => println!("FizzBuzz"),
            (true, false) => println!("Fizz"),
            (false, true) => println!("Buzz"),
            (false, false) => println!("{}", start),
        }

        start += 1;
    }
}
