use proconio::input;

fn main() {
    input! {
        n: i64,
        s: String,
    }

    println!("{}",s.chars().last().unwrap());
}

