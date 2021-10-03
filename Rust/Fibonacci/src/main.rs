use std::io;

fn main() {
    println!("Enter number to find fibonaaci to it:");

    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Error: Cannot Readline.");
    let limit = input.trim().parse().expect("Error: NAN");

    let mut next: i32;
    let mut curr = 1;
    let mut last = 0;
    loop {
        if curr > limit {
            break;
        }
        print!("{} ", curr);
        next = curr + last;
        last = curr;
        curr = next;
    }
    println!();
}
