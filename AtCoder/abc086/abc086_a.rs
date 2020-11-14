use proconio::input;

fn main() {
    input! {
        a: i64,
        b: i64,
    }

    let answer = if a % 2 == 0 || b % 2 == 0 { "Even" } else { "Odd" };
    println!("{}", answer)
}

