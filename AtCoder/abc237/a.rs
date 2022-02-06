use proconio::input;

fn main() {
    input!{
        n: i64
    }

    println!("{}",if -2_i64.pow(31) <= n && n < 2_i64.pow(31) {"Yes"} else {"No"});
}

