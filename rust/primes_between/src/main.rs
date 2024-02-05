use std::env;
use std::process;

fn is_prime(num: i32) -> bool {
    if num <= 1 {
        return false;
    }
    for i in 2..=((num as f64).sqrt() as i32) {
        if num % i == 0 {
            return false;
        }
    }
    true
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 3 {
        eprintln!("Usage: {} <start> <end>", args[0]);
        process::exit(1);
    }

    let start: i32 = match args[1].parse() {
        Ok(num) => num,
        Err(_) => {
            eprintln!("Error: '{}' is not an integer.", args[1]);
            process::exit(1);
        }
    };

    let end: i32 = match args[2].parse() {
        Ok(num) => num,
        Err(_) => {
            eprintln!("Error: '{}' is not an integer.", args[2]);
            process::exit(1);
        }
    };

    if start > end {
        eprintln!("Error: start must not be greater than end.");
        process::exit(1);
    }

    for num in start..=end {
        if is_prime(num) {
            println!("{}", num);
        }
    }
}
