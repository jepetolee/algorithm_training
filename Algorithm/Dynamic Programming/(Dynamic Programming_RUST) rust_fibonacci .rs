use std::io;

fn main() {
    println!("<Fibonacci_RUST>");
    println!("Dynamic fibonacci- find the 'N'th fibonacci sequence.:");
    let mut num = String::new();

    io::stdin().read_line(&mut num).unwrap();

    let num: usize = num.trim().parse().unwrap();
    if num <= 20 {
        println!(
            "1. {}th sequence is : {}",
            num,
            dynamic_fibonacci_basic(num)
        );
    } else {
        println!(
            "2. {}th sequence is : {}",
            num,
            dynamic_fibonacci_bigger(num)
        );
    }
}

fn dynamic_fibonacci_basic(number: usize) -> usize {
    fn solve(n: usize, cache: &mut [Option<usize>]) -> usize {
        cache[n].unwrap_or_else(|| {
            let result = {
                if n > 1 {
                    solve(n - 1, cache) + solve(n - 2, cache)
                } else {
                    1
                }
            };
            cache[n] = Some(result);
            result
        })
    }

    solve(number, &mut vec![None; number + 1])
}

fn dynamic_fibonacci_bigger(mut number: usize) -> u128 {
    let mut cache: Vec<u128> = vec![1; number + 1];

    let mut count: usize = 2;
    while number - 1 != 0 {
        cache[count] = cache[count - 1] + cache[count - 2];
        count = count + 1;
        number = number - 1;
    }
    cache[count - 1]
}
//dirty code
